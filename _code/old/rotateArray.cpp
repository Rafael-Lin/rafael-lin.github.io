#include "stdafx.h"
#include "rotateArray.h"
#include "string"
#include"type.h"
#include<algorithm>
#include<vector>
#include<ctime>
#include<iostream>
#include<set>
#include<unordered_map>
#include<unordered_set>

//#include<numeric>
#define GUARD -10000

using namespace std;

Solution1::Solution1() {

}

void Solution1::rotate(int nums[], int n, int k) {

  /*Rotate an array of n elements to the right by k steps.
    For example, with n = 7 and k = 3, the array[1, 2, 3, 4, 5, 6, 7] is rotated to[5, 6, 7, 1, 2, 3, 4].
    Note:
    Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
    */
  /*
     1. Make an extra copy and then rotate.
     Time complexity : O(n).Space complexity : O(n).
     */
  if ((n == 0) || (k <= 0))
    return;

  // Make a copy of nums
  vector<int> numsCopy(n);
  for (int i = 0; i < n; i++)
    numsCopy[i] = nums[i];

  // Rotate the elements.
  for (int i = 0; i < n; i++){
    int index = (i + k) % n;
    nums[index] = numsCopy[i];
    //printf("num[%d] = %d\n", index, nums[index] );
    /*
       num[3] = 1
       num[4] = 2
       num[5] = 3
       num[6] = 4
       num[0] = 5
       num[1] = 6
       num[2] = 7
       */
  }
}

void Solution1::rotateNtimes(int nums[], int n, int k) {
  /*
     2. Start from one element and keep rotating until we have rotated n different elements.
     Time complexity : O(n).Space complexity : O(1).
     */
  if ((n == 0) || (k <= 0))
    return;

  int cntRotated = 0;
  int start = 0;
  int curr = 0;
  int numToBeRotated = nums[0];
  int tmp = 0;
  // Keep rotating the elements until we have rotated n
  // different elements.
  while (cntRotated < n)
  {
    do
    {
      tmp = nums[(curr + k) % n];
      nums[(curr + k) % n] = numToBeRotated;
      numToBeRotated = tmp;
      curr = (curr + k) % n;
      cntRotated++;
    } while (curr != start);
    // Stop rotating the elements when we finish one cycle,
    // i.e., we return to start.

    // Move to next element to start a new cycle.
    start++;
    curr = start;
    numToBeRotated = nums[curr];
  }
}

void Solution1::rotateReverse(int nums[], int n, int k) {
  /* 3. Reverse the first n - k elements, the last k elements, and then all the n elements. */
  /* Time complexity : O(n).Space complexity : O(1). */
  k = k%n;

  // Reverse the first n - k numbers.
  // Index i (0 <= i < n - k) becomes n - k - i.
  reverse(nums, nums + n - k);

  // Reverse tha last k numbers.
  // Index n - k + i (0 <= i < k) becomes n - i.
  reverse(nums + n - k, nums + n);

  // Reverse all the numbers.
  // Index i (0 <= i < n - k) becomes n - (n - k - i) = i + k.
  // Index n - k + i (0 <= i < k) becomes n - (n - i) = i.
  reverse(nums, nums + n);
}

void Solution1::rotateSwap(int nums[], int n, int k) {

  /* 4. Swap the last k elements with the first k elements. */
  /* Time complexity : O(n).Space complexity : O(1). */
  for (; k = k%n; n -= k, nums += k)
  {
    // Swap the last k elements with the first k elements.
    // The last k elements will be in the correct positions
    // but we need to rotate the remaining (n - k) elements
    // to the right by k steps.
    for (int i = 0; i < k; i++)
    {
      swap(nums[i], nums[n - k + i]);
    }
  }
}

int Solution1::removeElement(vector<int>& nums, int val) {
  /* Given an array and a value, remove all instances of that value in place and return the new length. */
  /* The order of elements can be changed. It doesn't matter what you leave beyond the new length. */
  int i = 0;
  int n = nums.size();
  while (i < n) {
    if (nums[i] == val) {
      nums[i] = nums[n - 1];
      n--;
    }
    else
      i++;
  }
  return n;
}

int Solution1::removeDuplicates(vector<int>& nums) {

  /* 26 */
  /* Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length. */

  /* Do not allocate extra space for another array, you must do this in place with constant memory. */

  /* For example, */
  /* Given input array nums = [1,1,2], */

  /* Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length. */
  int count = 0;
  int n = nums.size();
  for (int i = 1; i < n; i++){
    if (nums[i] == nums[i - 1]) count++;
    else nums[i - count] = nums[i];
  }
  return n - count;
}

vector<string> Solution1::summaryRanges(vector<int>& nums) {
  /* 228. Summary Ranges */
  /* Given a sorted integer array without duplicates, return the summary of its ranges. */
  /* For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"]. */

  vector<string> retVec;
  for (int i = 0; i < nums.size();){
    int start = i, end = i;
    for (end = i;;){
      if (end + 1 < nums.size() && nums[end] + 1 == nums[end + 1])
        end++;
      else
        break;
    }
    string target = "";
    if (start == end)
      target = to_string(nums[start]);
    else
      target = to_string(nums[start]) + "->" + to_string(nums[end]);

    retVec.push_back(target);
    i = end + 1;
  }
  return retVec;
}

vector<string> Solution1::summaryRangesAns(vector<int>& nums) {
  const int size_n = nums.size();
  vector<string> res;
  if (0 == size_n) return res;
  for (int i = 0; i < size_n;) {
    int start = i, end = i;
    while (end + 1 < size_n && nums[end + 1] == nums[end] + 1)
      end++;
    if (end > start)
      res.push_back(to_string(nums[start]) + "->" + to_string(nums[end]));
    else
      res.push_back(to_string(nums[start]));
    i = end + 1;
  }
  return res;
}

void Solution1::printVector(vector<int> nums, int watch) {
  printf("watch : %d ,", watch);
  for (int i = 0; i < nums.size(); i++)
    printf("%d ", nums[i]);
  printf("\n");

}

void Solution1::moveZeroesAns(vector<int>& nums) {
  /*
     283. Move Zeroes My Submissions Question
     Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

     For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].
     */
  int len = 0;
  // len means
  // 1) the valid length of non-zero int currently
  // 2) the target position for zero value
  for (int i = 0; i < nums.size(); ++i) {
    if (nums[i] != 0) {
      if (nums[len] != nums[i]) {
        swap(nums[len], nums[i]);
      }
      ++len;
    }
    //printVector( nums );
  }
}

void Solution1::merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

  /*
     88. Merge Sorted Array My Submissions Question
     Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
     Note:
     You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.
     */
  if (n == 0) return;
  int index1 = m - 1;
  int index2 = n - 1;
  for (int index = m + n - 1; index >= 0; index--){
    if (index1 < 0){
      nums1[index] = nums2[index2];
      index2--;
    }
    else if (index2 < 0){
      nums1[index] = nums1[index1];
      index1--;

    }
    else if (nums1[index1] > nums2[index2]){
      nums1[index] = nums1[index1];
      index1--;
    }
    else{
      nums1[index] = nums2[index2];
      index2--;
    }
  }

}

int Solution1::majorityElementHashTable(vector<int>& nums) {
  /*
     Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
     You may assume that the array is non-empty and the majority element always exist in the array.
     */
  //https://leetcode.com/discuss/42929/6-suggested-solutions-in-c-with-explanations
  unordered_map<int, int> counts;
  int n = nums.size();
  for (int i = 0; i < n; i++)
  if (++counts[nums[i]] > n / 2)
    return nums[i];
}

int Solution1::majorityElementSorting(vector<int>& nums) {
  //http://en.cppreference.com/w/cpp/algorithm/nth_element
  nth_element(nums.begin(), nums.begin() + nums.size() / 2, nums.end());
  return nums[nums.size() / 2];
}

int Solution1::majorityElementRandom(vector<int>& nums) {
  int n = nums.size();
  srand(unsigned(time(NULL)));
  while (true) {
    int idx = rand() % n;
    int candidate = nums[idx];
    int counts = 0;
    for (int i = 0; i < n; i++)
    if (nums[i] == candidate)
      counts++;
    if (counts > n / 2) return candidate;
  }
}

vector<int> Solution1::plusOne(vector<int>& digits) {
  int n = digits.size();
  int addOne = 1;
  int i;
  vector<int> result(n);
  //example : 123 + 1 = 124 ;

  for (i = n - 1; i >= 0; i--)
  {
    result[i] = addOne + digits[i];
    if (result[i] == 10)
    {
      result[i] = 0;
      addOne = 1;
    }
    else
      addOne = 0;
  }

  if (addOne == 1)
    result.insert(result.begin(), 1);

  return result;
}

bool Solution1::containsDuplicate(vector<int>& nums) {

  //Given an array of integers, find if the array contains any duplicates.
  //Your function should return true if any value appears at least twice in the array,
  //and it should return false if every element is distinct.

  /* Unordered maps are associative containers that store elements formed by the combination of a key value and a mapped value, and which allows for fast retrieval of individual elements based on their keys. */
  /* In an unordered_map, the key value is generally used to uniquely identify the element, while the mapped value is an object with the content associated to this key.Types of key and mapped value may differ. */
  /* Internally, the elements in the unordered_map are not sorted in any particular order with respect to either their key or mapped values, but organized into buckets depending on their hash values to allow for fast access to individual elements directly by their key values(with a constant average time complexity on average). */
  /* unordered_map containers are faster than map containers to access individual elements by their key, although they are generally less efficient for range iteration through a subset of their elements. */

  unordered_map<int, int> mymap;
  int n = nums.size();
  int i;
  if (n < 2) return false;

  mymap.insert({ nums[0], 0 });
  unordered_map<int, int>::iterator got;
  for (i = 1; i < n; i++)
  {
    got = mymap.find(nums[i]);
    if (got != mymap.end())
      return true;
    mymap.insert({ nums[i], i });
  }
  return false;
}

vector<vector<int>> Solution1::generate(int numRows) {

  /*
     118. Pascal's Triangle My Submissions Question
     Given numRows, generate the first numRows of Pascal's triangle.

     For example, given numRows = 5,
     Return

     [
     [1],
     [1,1],
     [1,2,1],
     [1,3,3,1],
     [1,4,6,4,1]
     ]
     */

  vector<vector<int>> retVec;
  vector<int> PrevRow;
  if (numRows == 0) return retVec;
  PrevRow.push_back(1);
  retVec.push_back(PrevRow);
  for (int i = 0; i < numRows - 1; i++){
    vector<int> CurrRow;
    CurrRow.push_back(1);
    for (int j = 0; j + 1 < PrevRow.size(); j++){
      CurrRow.push_back(PrevRow[j] + PrevRow[j + 1]);
    }
    CurrRow.push_back(1);
    PrevRow = CurrRow;
    //printVector( CurrRow );
    retVec.push_back(CurrRow);
  }
  return retVec;
}

vector<int> Solution1::getRow(int rowIndex) {
  /*
     119. Pascal's Triangle II My Submissions Question
     Given an index k, return the kth row of the Pascal's triangle.

     For example, given k = 3,
     Return [1,3,3,1].

     Could you optimize your algorithm to use only O(k) extra space?

     [
     [1],
     [1,1],
     [1,2,1],
     [1,3,3,1],
     [1,4,6,4,1]
     ]
     1 0 0 0 0 0
     1 1 0 0 0 0
     1 2 1 0 0 0
     1 3 3 1 0 0
     1 4 6 4 1 0
     1 5 10 10 5 1
     */
  vector<int> vi(rowIndex + 1);
  vi[0] = 1;
  for (int i = 0; i <= rowIndex; ++i)
  {
    for (int j = i; j > 0; --j)
    {
      vi[j] = vi[j] + vi[j - 1];
    }
    //printVector(vi);
  }
  return vi;
}

bool Solution1::containsNearbyDuplicate(vector<int>& nums, int k) {
  /*
     219. Contains Duplicate II My Submissions Question
     Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the difference between i and j is at most k.

     */
  set<int> cand;
  for (int i = 0; i < nums.size(); i++) {
    if (i > k)
      cand.erase(nums[i - k - 1]);
    if (!cand.insert(nums[i]).second)
      return true;
  }
  return false;
}

int Solution1::SetExample() {
  std::set<int> myset;
  std::set<int>::iterator it;

  // insert some values:
  for (int i = 1; i < 10; i++) myset.insert(i * 10);  // 10 20 30 40 50 60 70 80 90

  it = myset.begin();
  ++it;                                         // "it" points now to 20

  myset.erase(it);

  myset.erase(40);

  it = myset.find(60);
  myset.erase(it, myset.end());

  std::cout << "myset contains:";
  for (it = myset.begin(); it != myset.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}

bool Solution1::containsNearbyDuplicateUnorderSet(vector<int>& nums, int k) {
  unordered_set<int> s;

  if (k <= 0) return false;
  if (k >= nums.size()) k = nums.size() - 1;

  for (int i = 0; i < nums.size(); i++)
  {
    if (i > k) s.erase(nums[i - k - 1]);
    if (s.find(nums[i]) != s.end()) return true;
    s.insert(nums[i]);
  }

  return false;
}

int Solution1::uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {


  /*
     63. Unique Paths II My Submissions Question

     Now consider if some obstacles are added to the grids.How many unique paths would there be ?

     An obstacle and empty space is marked as 1 and 0 respectively in the grid.

     For example,
     There is one obstacle in the middle of a 3x3 grid as illustrated below.
     [
     [0,0,0],
     [0,1,0],
     [0,0,0]
     ]
     The total number of unique paths is 2.
     */
  int m = obstacleGrid[0].size();
  int n = obstacleGrid.size();

  if (obstacleGrid[0][0] == 1) return 0;
  vector<int> test(m);
  for (int i = 0; i < m; i++){
    if (obstacleGrid[0][i] == 1)
      test[i] = 0;
    else
      test[i] = 1;
  }
  for (int j = 1; j < n; j++){
    for (int i = 1; i < m; i++){
      if (obstacleGrid[j][i] == 0)
        test[i] = test[i] + test[i - 1];
      else
        test[i] = 0;
    }
  }
  return test[m - 1];

}

int Solution1::uniquePathsWithObstaclesAns(vector<vector<int> > &obstacleGrid) {
  int m = obstacleGrid.size(), n = obstacleGrid[0].size();
  vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
  dp[0][1] = 1;
  for (int i = 1; i <= m; ++i)
  for (int j = 1; j <= n; ++j)
  if (!obstacleGrid[i - 1][j - 1])
    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
  return dp[m][n];
}

int Solution1::uniquePaths(int m, int n) {

  /*
     62. Unique Paths My Submissions Question

     Total Accepted : 72163 Total Submissions : 207649 Difficulty : Medium
     A robot is located at the top - left corner of a m x n grid(marked 'Start' in the diagram below).

     The robot can only move either down or right at any point in time.The robot is trying to reach the bottom - right corner of the grid(marked 'Finish' in the diagram below).

     How many possible unique paths are there ?
     */

  vector<int> test(m);
  for (int i = 0; i < m; i++)
    test[i] = 1;
  for (int j = 1; j < n; j++){
    for (int i = 1; i < m; i++)
      test[i] = test[i] + test[i - 1];
  }
  return test[m - 1];

}

int Solution1::minSubArrayLen(int s, vector<int>& nums) {

  /*
     209. Minimum Size Subarray Sum My Submissions Question
     Given an array of n positive integers and a positive integer s,
     find the minimal length of a subarray of which the sum ≥ s. If there isn't one, return 0 instead.

     For example, given the array [2,3,1,2,4,3] and s = 7,
     the subarray [4,3] has the minimal length under the problem constraint.

     click to show more practice.

     More practice:
     If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).
     */

  int n = nums.size();
  int result = n + 1;
  int left = 0;
  int right = 0;
  int sum = 0;
  while (right < n)
  {
    sum = sum + nums[right];
    right = right + 1;
    while (sum >= s)
    {
      printf("result : %d, left = %d, right = %d, sum = %d \n", result, left, right, sum);
      result = min(result, right - left);
      sum = sum - nums[left];
      left = left + 1;
    }
  }

  if (result == n + 1)
    return 0;
  else
    return result;
}

int Solution1::minSubArrayLenAns2(int s, vector<int>& nums) {
  int n = nums.size(), start = 0, sum = 0, minlen = INT_MAX;
  for (int i = 0; i < n; i++) {
    sum += nums[i];
    while (sum >= s) {
      minlen = min(minlen, i - start + 1);
      sum -= nums[start++];
    }
  }
  return minlen == INT_MAX ? 0 : minlen;
}

int Solution1::searchInsert(vector<int>& nums, int target) {
  /*
     35. Search Insert Position My Submissions Question
     Given a sorted array and a target value,
     return the index if the target is found. If not,
     return the index where it would be if it were inserted in order.

     You may assume no duplicates in the array.

     Here are few examples.
     [1,3,5,6], 5 → 2
     [1,3,5,6], 2 → 1
     [1,3,5,6], 7 → 4
     [1,3,5,6], 0 → 0

     */

  if (nums.size() > 0 && nums[0] > target) return 0;
  for (int i = 0; i < nums.size(); i++){
    if (nums[i] == target)
      return i;
    if (i + 1 < nums.size() && nums[i + 1] > target)
      return i + 1;
  }
  return nums.size();
}

int Solution1::searchInsertBinarySearch(vector<int> &nums, int target){
  // (1) At this point, low > high. That is, low >= high+1
  // (2) From the invariant, we know that the index is between [low, high+1],
  //	so low <= high+1. Follwing from (1), now we know low == high+1.
  // (3) Following from (2), the index is between [low, high+1] = [low, low],
  //  which means that low is the desired index
  // Therefore, we return low as the answer. You can also return high+1 as the result, since low == high+1
  int low = 0, high = nums.size() - 1;

  // Invariant: the desired index is between [low, high+1]
  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (nums[mid] < target)
      low = mid + 1;
    else
      high = mid - 1;
  }

  return low;
}

vector<int> Solution1::searchRange(vector<int>& nums, int target) {
  /*
     34. Search for a Range My Submissions Question
     Given a sorted array of integers, find the starting and ending position of a given target value.

     Your algorithm's runtime complexity must be in the order of O(log n).

     If the target is not found in the array, return [-1, -1].

     For example,
     Given [5, 7, 7, 8, 8, 10] and target value 8,
     return [3, 4].

     */
  vector<int> retV;
  int low = 0, high = nums.size() - 1;
  int targetIndex = 0, mid = 0;
  if (nums.size() == 1){
    if (find(nums.begin(), nums.end(), target) != nums.end()){
      retV.push_back(0);
      retV.push_back(0);
      return retV;
    }
    else{
      retV.push_back(-1);
      retV.push_back(-1);
      return retV;
    }
  }
  while (low < high){
    mid = low + (high - low) / 2;
    if (nums[mid] > target)
      high = mid - 1;
    else if (nums[mid] < target)
      low = mid + 1;
    else {
      targetIndex = mid;
      break;
    }
  }
  if (targetIndex == -1){
    retV.push_back(-1);
    retV.push_back(-1);
    return retV;
  }
  int llow = 0, lhigh = mid;
  int hlow = mid, hhigh = nums.size() - 1;
  while (llow < lhigh){
    mid = llow + (lhigh - llow) / 2;
    if (nums[mid] > target)
      lhigh = mid - 1;
    else if (nums[mid] < target)
      llow = mid + 1;
    else {
      targetIndex = mid;
      break;
    }
  }

  retV.push_back(targetIndex);
  while (hlow < hhigh){
    mid = hlow + (hhigh - hlow) / 2;
    if (nums[mid] > target)
      hhigh = mid - 1;
    else if (nums[mid] < target)
      hlow = mid + 1;
    else {
      targetIndex = mid;
      break;
    }
  }
  retV.push_back(targetIndex);
  return retV;
}

vector<int> Solution1::searchRangeAns1(vector<int>& nums, int target) {
  int start = 0, end = nums.size(), mid, left, right;
  while (start < end) {
    mid = (start + end) / 2;
    if (nums[mid] >= target)
      end = mid;
    else
      start = mid + 1;
  }
  left = start;
  start = 0, end = nums.size();
  while (start < end) {
    mid = (start + end) / 2;
    if (nums[mid] > target)
      end = mid;
    else
      start = mid + 1;
  }
  right = start;
  return left == right ? vector<int> {-1, -1} : vector<int>{ left, right - 1 };
}

vector<int> Solution1::searchRangeLib(vector<int>& nums, int target) {
  /*
     int lo = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
     if (nums[lo] != target)
     return vector<int> {-1, -1};
     int hi = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
     return vector<int> {lo, hi}; 1
     */
  vector<int> r;
  return r;
}

vector<vector<int>> Solution1::threeSum(vector<int>& nums) {
  /*
     15. 3Sum My Submissions Question
     Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0?
     Find all unique triplets in the array which gives the sum of zero.

     Note:
     Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
     The solution set must not contain duplicate triplets.
     For example, given array S = {-1 0 1 2 -1 -4},

     A solution set is:
     (-1, 0, 1)
     (-1, -1, 2)
     */
  vector<vector<int>> RetV;
  sort(nums.begin(), nums.end());
  for (int i = 0; i < nums.size();){
    int a = nums[i];
    int low = i + 1;
    int high = nums.size() - 1;
    while (low < high){
      int sum = a + nums[low] + nums[high];
      if (sum == 0){
        vector<int> candidate;
        candidate.push_back(a);
        candidate.push_back(nums[low]);
        candidate.push_back(nums[high]);
        RetV.push_back(candidate);
        low++;
        high--;
        while (low < high && nums[low - 1] == nums[low])
          low++;
        while (low < high && nums[high + 1] == nums[high])
          high--;
      }
      else if (sum > 0){
        high--;
        while (low < high && nums[high + 1] == nums[high])
          high--;
      }
      else if (sum < 0){
        low++;
        while (low < high && nums[low - 1] == nums[low])
          low++;
      }
    }
    i++;
    while ((i < nums.size()) && nums[i] == nums[i - 1])
      i++;
  }
  return RetV;

}

void Solution1::setZeroes(vector<vector<int>>& matrix) {
  /*
     73. Set Matrix Zeroes My Submissions Question
     Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

     click to show follow up.

     Follow up :
     Did you use extra space ?
     A straight forward solution using O(mn) space is probably a bad idea.
     A simple improvement uses O(m + n) space, but still not the best solution.
     Could you devise a constant space solution ?
     */
  int i, j;
  int m = matrix.size();
  if (m == 0) return;

  int n = matrix[0].size();
  if (n == 0) return;


  for (i = 0; i < m; i++){
    for (j = 0; j < n; j++)
    {
      if (matrix[i][j] == 0){ matrix[i][j] = GUARD; }
    }
  }

  for (i = 0; i < m; i++)
  for (j = 0; j < n; j++)
  {
    if (matrix[i][j] == GUARD){
      int p;
      for (p = 0; p < m; p++) if (matrix[p][j] != GUARD) matrix[p][j] = 0;
      for (p = 0; p < n; p++) if (matrix[i][p] != GUARD) matrix[i][p] = 0;
      matrix[i][j] = 0;
    }
  }
}

int Solution1::maxProfit(vector<int>& prices) {
  /*
     121. Best Time to Buy and Sell Stock My Submissions Question

     Say you have an array for which the ith element is the price of a given stock on day i.

     If you were only permitted to complete at most one transaction
     (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
     */
  int maxPro = 0;
  int minPrice = INT_MAX;
  for (int i = 0; i < prices.size(); i++){
    minPrice = min(minPrice, prices[i]);
    maxPro = max(maxPro, prices[i] - minPrice);
  }
  return maxPro;
}

bool Solution1::searchMatrix(vector<vector<int>>& matrix, int target) {
  /*
     74. Search a 2D Matrix My Submissions Question
     Total Accepted: 65737 Total Submissions: 200300 Difficulty: Medium
     Write an efficient algorithm that searches for a value in an m x n matrix.
     This matrix has the following properties:

     Integers in each row are sorted from left to right.
     The first integer of each row is greater than the last integer of the previous row.
     For example,

     Consider the following matrix:

     [
     [1,   3,  5,  7],
     [10, 11, 16, 20],
     [23, 30, 34, 50]
     ]
     Given target = 3, return true.
     */
  if (matrix.empty() || matrix[0].empty())
    return false;
  int m = matrix.size();
  int n = matrix[0].size();
  int start = 0;
  int end = m * n - 1;
  while (start <= end){
    int mid = start + (end - start) / 2;
    int midElement = matrix[mid / n][mid % n];
    if (midElement == target)
      return true;
    else if (midElement < target)
      start = mid + 1;
    else
      end = mid - 1;
  }
  return false;
}

int Solution1::minPathSum(vector<vector<int>>& grid) {
  /*
     64. Minimum Path Sum My Submissions Question
     Total Accepted: 59066 Total Submissions: 175717 Difficulty: Medium
     Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

     Note: You can only move either down or right at any point in time.

     Subscribe to see which companies asked this question
     */
  int m = grid.size();
  int n = grid[0].size();
  for (int i = 1; i < n; i++)
    grid[0][i] = grid[0][i - 1] + grid[0][i];

  for (int i = 1; i < m; i++)
    grid[i][0] = grid[i][0] + grid[i - 1][0];

  for (int i = 1; i < m; i++){
    for (int j = 1; j < n; j++){
      grid[i][j] = min(grid[i][j] + grid[i][j - 1], grid[i][j] + grid[i - 1][j]);
    }
  }
  return grid[m - 1][n - 1];
}

int Solution1::missingNumberXOR(vector<int>& nums) {

  /*
     268. Missing Number My Submissions Question
     Total Accepted: 31964 Total Submissions: 84077 Difficulty: Medium
     Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

     For example,
     Given nums = [0, 1, 3] return 2.

     Note:
     Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?

     Credits:
     Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

     Subscribe to see which companies asked this question
     */

  int res = nums.size();
  for (int i = 0; i < nums.size(); i++){
    res ^= i;
    res ^= nums[i];
  }
  return res;
}

int Solution1::missingNumberSUM(vector<int>& nums){
  int len = nums.size();
  int sum = (0 + len)*(len + 1) / 2;
  for (int i = 0; i < len; i++)
    sum -= nums[i];
  return sum;
}

int Solution1::missingNumberBinarySearch(vector<int>& nums){
  sort(nums.begin(), nums.end());
  int left = 0, right = nums.size(), mid = (left + right) / 2;
  while (left<right){
    mid = (left + right) / 2;
    printf("mid = %d, num[mid] = %d, left = %d, right =%d\n", mid, nums[mid], left, right);
    /*
       int array6[10] = { 0,1,3,4,5,6,7,8,9,10};
       mid = 5, num[mid] = 6, left = 0, right = 10
       mid = 2, num[mid] = 3, left = 0, right = 5
       mid = 1, num[mid] = 1, left = 0, right = 2
       */
    if (nums[mid]>mid)
      right = mid;
    else
      left = mid + 1;
  }
  return left;
}

void Solution1::bt(vector<int> candidiate, vector<vector<int>> & retV, int index, vector<int> &candV, int target) {
  if (target == 0){
    retV.push_back(candV);
    return;
  }
  for (int i = index; i < candidiate.size() && target >= candidiate[i]; i++){
    candV.push_back(candidiate[i]);
    bt(candidiate, retV, i, candV, target - candidiate[i]);
    candV.pop_back();
  }
}

vector<vector<int>> Solution1::combinationSum(vector<int>& candidates, int target) {
  /*
     39. Combination Sum My Submissions Question
     Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

     The same repeated number may be chosen from C unlimited number of times.

     Note:
     All numbers (including target) will be positive integers.
     Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
     The solution set must not contain duplicate combinations.
     For example, given candidate set 2,3,6,7 and target 7,
     A solution set is:
     [7]
     [2, 2, 3]
     */

  sort(candidates.begin(), candidates.end());
  vector<vector<int>> retV;
  vector<int> candV;
  bt(candidates, retV, 0, candV, target);
  return retV;

}

void Solution1::bt2(vector<int> candidiate, vector<vector<int>> & retV, int index, vector<int> &candV, int target){
  if (target == 0){
    retV.push_back(candV);
    return;
  }
  for (int i = index; i < candidiate.size() && target >= candidiate[i]; i++){
    candV.push_back(candidiate[i]);
    bt2(candidiate, retV, i + 1, candV, target - candidiate[i]);
    candV.pop_back();
  }
}

vector<vector<int>> Solution1::combinationSum2(vector<int>& candidates, int target) {
  /*
     40. Combination Sum II My Submissions Question
     Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
     Each number in C may only be used once in the combination.

     Note:
     All numbers (including target) will be positive integers.
     Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
     The solution set must not contain duplicate combinations.
     For example, given candidate set 10,1,2,7,6,1,5 and target 8,
     A solution set is:
     [1, 7]
     [1, 2, 5]
     [2, 6]
     [1, 1, 6]
     */
  sort(candidates.begin(), candidates.end());
  vector<vector<int>> retV;
  vector<int> candV;
  bt2(candidates, retV, 0, candV, target);
  return retV;

}

void Solution1::bt3(vector<int> candidiate, vector<vector<int>> & retV, int index, vector<int> &candV, int totalnum, int targetSum){
  if (targetSum == 0 && candV.size() == totalnum){
    retV.push_back(candV);
    return;
  }
  for (int i = index; i < candidiate.size() && targetSum >= candidiate[i]; i++){
    candV.push_back(candidiate[i]);
    bt3(candidiate, retV, i + 1, candV, totalnum, targetSum - candidiate[i]);
    candV.pop_back();
  }
}

vector<vector<int>> Solution1::combinationSum3(int k, int n) {
  /*
     216. Combination Sum III My Submissions Question
     Find all possible combinations of k numbers that add up to a number n,
     given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

     Ensure that numbers within the set are sorted in ascending order.

     Example 1:

     Input: k = 3, n = 7
     Output:
     [[1,2,4]]

     Example 2:
     Input: k = 3, n = 9
     Output:

     [[1,2,6], [1,3,5], [2,3,4]]
     */
  vector<int> candidates;
  for (int i = 1; i < 10; i++) candidates.push_back(i);

  vector<vector<int>> retV;
  vector<int> candV;
  bt3(candidates, retV, 0, candV, k, n);
  return retV;
}

vector<int> Solution1::productExceptSelf(vector<int>& nums) {
  /*
     238. Product of Array Except Self My Submissions Question
     Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

     Solve it without division and in O(n).

     For example, given [1,2,3,4], return [24,12,8,6].

     Follow up:
     Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)

     Subscribe to see which companies asked this question
     */

  /*
     Two passes. During the 1st pass (from left to right), res[i] records nums[0]xnums[1]x...xnums[i-1],
     the products of all elements till nums[i]. During the second pass (from right to left),
     res[i] is multiplied by nums[i+1]xnums[i+2]x...xnums[N-1], the products of all elements from i+1 till the end.
     */

  int n = nums.size();
  vector<int> fromBegin(n);
  fromBegin[0] = 1;
  vector<int> fromLast(n);
  fromLast[0] = 1;

  for (int i = 1; i < n; i++){
    fromBegin[i] = fromBegin[i - 1] * nums[i - 1];
    fromLast[i] = fromLast[i - 1] * nums[n - i];
  }
  /*
     printVector(nums);
     printVector(fromBegin);
     printVector(fromLast);
     printVector(res);
     */
  vector<int> res(n);
  for (int i = 0; i < n; i++){
    res[i] = fromBegin[i] * fromLast[n - 1 - i];
  }
  /*
     1 2 3 4
     1 1 2 6
     1 4 12 24
     24 12 8 6
     */
  return res;
}

bool Solution1::ExistDFS(vector<vector<char>>& board, int row, int col, const string &word, int start, int M, int N, int sLen) {
  char curC;
  bool res = false;
  if ((curC = board[row][col]) != word[start]) return false;
  if (start == sLen - 1) return true;
  board[row][col] = '*';
  if (row > 0)  // left
    res = ExistDFS(board, row - 1, col, word, start + 1, M, N, sLen);
  if (!res && row < M - 1)  //right
    res = ExistDFS(board, row + 1, col, word, start + 1, M, N, sLen);
  if (!res && col > 0) //up
    res = ExistDFS(board, row, col - 1, word, start + 1, M, N, sLen);
  if (!res && col < N - 1) //down
    res = ExistDFS(board, row, col + 1, word, start + 1, M, N, sLen);
  board[row][col] = curC;
  return res;
}

bool Solution1::exist(vector<vector<char>>& board, string word) {
  /*
     79. Word Search My Submissions Question
     Given a 2D board and a word, find if the word exists in the grid.

     The word can be constructed from letters of sequentially adjacent cell,
     where "adjacent" cells are those horizontally or vertically neighboring.
     The same letter cell may not be used more than once.

     For example,
     Given board =

     [
     ['A','B','C','E'],
     ['S','F','C','S'],
     ['A','D','E','E']
     ]
     word = "ABCCED", -> returns true,
     word = "SEE", -> returns true,
     word = "ABCB", -> returns false.
     */
  int M, N, i, j, sLen = word.size();
  if ((M = board.size()) && (N = board[0].size()) && sLen)
  {
    for (i = 0; i < M; ++i)
    for (j = 0; j < N; ++j)
    if (ExistDFS(board, i, j, word, 0, M, N, sLen)) return true;
  }
  return false;
}

bool Solution1::canJump(vector<int>& nums) {
  /*
     55. Jump Game My Submissions Question
     Total Accepted: 65757 Total Submissions: 238279 Difficulty: Medium
     Given an array of non-negative integers, you are initially positioned at the first index of the array.

     Each element in the array represents your maximum jump length at that position.

     Determine if you are able to reach the last index.

     For example:
     A = [2,3,1,1,4], return true.

     A = [3,2,1,0,4], return false.
     */
  int n = nums.size();
  if (n <= 0) return false;
  int maxNum = nums[0];
  for (int i = 0; i <= maxNum && i < n; i++){
    maxNum = max(maxNum, nums[i] + i);
  }
  if (maxNum < n - 1) return false;
  else return true;
}

int Solution1::minimumTotal(vector<vector<int>>& triangle) {

  /*
     120. Triangle My Submissions Question
     Given a triangle, find the minimum path sum from top to bottom.
     Each step you may move to adjacent numbers on the row below.

     For example, given the following triangle
     [
     [2],
     [3,4],
     [6,5,7],
     [4,1,8,3]
     ]
     The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

     Note:
     Bonus point if you are able to do this using only O(n) extra space,
     where n is the total number of rows in the triangle.
     */
  //solution
  /*
     This problem is quite well-formed in my opinion. The triangle has a tree-like structure,
     which would lead people to think about traversal algorithms such as DFS.
     However, if you look closely, you would notice that the adjacent nodes always share a 'branch'.
     In other word, there are overlapping subproblems. Also, suppose x and y are 'children' of k.
     Once minimum paths from x and y to the bottom are known,
     the minimum path starting from k can be decided in O(1),
     that is optimal substructure.
     Therefore, dynamic programming would be the best solution to this problem in terms of time complexity.

     What I like about this problem even more is that the difference between 'top-down' and 'bottom-up'
     DP can be 'literally' pictured in the input triangle. For 'top-down' DP,
     starting from the node on the very top, we recursively find the minimum path sum of each node.
     When a path sum is calculated, we store it in an array (memoization);
     the next time we need to calculate the path sum of the same node, just retrieve it from the array.
     However, you will need a cache that is at least the same size as the input triangle itself to store the pathsum,
     which takes O(N^2) space. With some clever thinking,
     it might be possible to release some of the memory that will never be used after a particular point,
     but the order of the nodes being processed is not straightforwardly seen in a recursive solution,
     so deciding which part of the cache to discard can be a hard job.

     'Bottom-up' DP, on the other hand, is very straightforward:
     we start from the nodes on the bottom row;
     the min pathsums for these nodes are the values of the nodes themselves.
     From there, the min pathsum at the ith node on the kth row would be the lesser of the pathsums
     of its two children plus the value of itself, i.e.:

     minpath[k][i] = min( minpath[k+1][i], minpath[k+1][i+1]) + triangle[k][i];
     Or even better, since the row minpath[k+1] would be useless after minpath[k] is computed, we can simply set minpath as a 1D array, and iteratively update itself:

     For the kth level:
     minpath[i] = min( minpath[i], minpath[i+1]) + triangle[k][i];
     */
  int n = triangle.size();
  vector<int> minlen(triangle.back());
  for (int layer = n - 2; layer >= 0; layer--) // For each layer
  {
    for (int i = 0; i <= layer; i++) // Check its every 'node'
    {
      // Find the lesser of its two children, and sum the current value in the triangle with it.
      minlen[i] = min(minlen[i], minlen[i + 1]) + triangle[layer][i];
    }
  }
  return minlen[0];
}

void Solution1::nextPermutation(vector<int>& nums){

  /*
     31. Next Permutation My Submissions Question
     Implement next permutation,
     which rearranges numbers into the lexicographically next greater permutation of numbers.

     If such arrangement is not possible, it must rearrange it as the lowest possible order
     (ie, sorted in ascending order).

     The replacement must be in-place, do not allocate extra memory.

     Here are some examples.
     Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
     1,2,3 → 1,3,2
     3,2,1 → 1,2,3
     1,1,5 → 1,5,1
     */
}

int Solution1::threeSumClosest(vector<int>& nums, int target) {
  if (nums.size() < 3) return 0;
  int closest = nums[0] + nums[1] + nums[2];
  sort(nums.begin(), nums.end());
  for (int first = 0; first < nums.size() - 2; ++first) {
    if (first > 0 && nums[first] == nums[first - 1]) continue;
    int second = first + 1;
    int third = nums.size() - 1;
    while (second < third) {
      int curSum = nums[first] + nums[second] + nums[third];
      if (curSum == target) return curSum;
      if (abs(target - curSum)<abs(target - closest)) {
        closest = curSum;
      }
      if (curSum > target) {
        --third;
      }
      else {
        ++second;
      }
    }
  }
  return closest;
}

vector<vector<int>> Solution1::fourSum(vector<int>& nums, int target) {
  /*
     18. 4Sum My Submissions Question
     Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target?
     Find all unique quadruplets in the array which gives the sum of target.

     Note:
     Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
     The solution set must not contain duplicate quadruplets.
     For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

     A solution set is:
     (-1,  0, 0, 1)
     (-2, -1, 1, 2)
     (-2,  0, 0, 2)
     */
  vector<vector<int>> total;
  int n = nums.size();
  if (n<4)  return total;
  sort(nums.begin(), nums.end());
  for (int i = 0; i<n - 3; i++)
  {
    if (i>0 && nums[i] == nums[i - 1]) continue;
    if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3]>target) break;
    if (nums[i] + nums[n - 3] + nums[n - 2] + nums[n - 1]<target) continue;
    for (int j = i + 1; j<n - 2; j++)
    {
      if (j>i + 1 && nums[j] == nums[j - 1]) continue;
      if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2]>target) break;
      if (nums[i] + nums[j] + nums[n - 2] + nums[n - 1] < target) continue;
      int left = j + 1, right = n - 1;
      while (left < right){
        int sum = nums[left] + nums[right] + nums[i] + nums[j];
        if (sum<target) left++;
        else if (sum>target) right--;
        else{
          total.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
          do{ left++; } while (nums[left] == nums[left - 1] && left < right);
          do{ right--; } while (nums[right] == nums[right + 1] && left < right);
        }
      }
    }
  }
}

int Solution1::ptrExample(){
  /*
     Shared pointer
     Manages the storage of a pointer, providing a limited garbage-collection facility, possibly sharing that management with other objects.

     Objects of shared_ptr types have the ability of taking ownership of a pointer and share that ownership: once they take ownership,
     the group of owners of a pointer become responsible for its deletion when the last one of them releases that ownership.

     shared_ptr objects release ownership on the object they co-own as soon as they themselves are destroyed, or as soon as their value changes either by an assignment operation or by an explicit call to shared_ptr::reset. Once all shared_ptr objects that share ownership over a pointer have released this ownership, the managed object is deleted (normally by calling ::delete, but a different deleter may be specified on construction).

     shared_ptr objects can only share ownership by copying their value: If two shared_ptr are constructed (or made) from the same (non-shared_ptr) pointer, they will both be owning the pointer without sharing it, causing potential access problems when one of them releases it (deleting its managed object) and leaving the other pointing to an invalid location.

     Additionally, shared_ptr objects can share ownership over a pointer while at the same time pointing to another object. This ability is known as aliasing (see constructors), and is commonly used to point to member objects while owning the object they belong to. Because of this, a shared_ptr may relate to two pointers:

     A stored pointer, which is the pointer it is said to point to, and the one it dereferences with operator*.
     An owned pointer (possibly shared), which is the pointer the ownership group is in charge of deleting at some point, and for which it counts as a use.

     Generally, the stored pointer and the owned pointer refer to the same object, but alias shared_ptr objects (those constructed with the alias constructor and their copies) may refer to different objects.

     A shared_ptr that does not own any pointer is called an empty shared_ptr. A shared_ptr that points to no object is called a null shared_ptr and shall not be dereferenced. Notice though that an empty shared_ptr is not necessarily a null shared_ptr, and a null shared_ptr is not necessarily an empty shared_ptr.

     shared_ptr objects replicate a limited pointer functionality by providing access to the object they point to through operators * and ->. For safety reasons, they do not support pointer arithmetics.*

     https://msdn.microsoft.com/en-us/library/hh279669.aspx
     */
  /*
     shared_ptr<int> p1;
     std::shared_ptr<int> p2 (nullptr);
     std::shared_ptr<int> p3 (new int);
     std::shared_ptr<int> p4 (new int, std::default_delete<int>());
     std::shared_ptr<int> p5 (new int, [](int* p){delete p;}, std::allocator<int>());
     std::shared_ptr<int> p6 (p5);
     std::shared_ptr<int> p7 (std::move(p6));
     std::shared_ptr<int> p8 (std::unique_ptr<int>(new int));
     std::shared_ptr<C> obj (new C);
     std::shared_ptr<int> p9 (obj, obj->data);

     std::cout << "use_count:\n";
     std::cout << "p1: " << p1.use_count() << '\n';
     std::cout << "p2: " << p2.use_count() << '\n';
     std::cout << "p3: " << p3.use_count() << '\n';
     std::cout << "p4: " << p4.use_count() << '\n';
     std::cout << "p5: " << p5.use_count() << '\n';
     std::cout << "p6: " << p6.use_count() << '\n';
     std::cout << "p7: " << p7.use_count() << '\n';
     std::cout << "p8: " << p8.use_count() << '\n';
     std::cout << "p9: " << p9.use_count() << '\n';
     */
  return 0;
}

vector<int> Solution1::twoSum(vector<int>& nums, int target) {


  /*
     1. Two Sum My Submissions Question
     Total Accepted: 172395 Total Submissions: 852502 Difficulty: Medium
     Given an array of integers, find two numbers such that they add up to a specific target number.

     The function twoSum should return indices of the two numbers such that they add up to the target,
     where index1 must be less than index2.
     Please note that your returned answers (both index1 and index2) are not zero-based.

     You may assume that each input would have exactly one solution.

     Input: numbers={2, 7, 11, 15}, target=9
     Output: index1=1, index2=2
     */

  //Key is the number and value is its index in the vector.
  unordered_map<int, int> hash;
  vector<int> result;
  for (int i = 0; i < nums.size(); i++) {
    int numberToFind = target - nums[i];

    //if numberToFind is found in map, return them
    if (hash.find(numberToFind) != hash.end()) {
      //+1 because indices are NOT zero based
      result.push_back(hash[numberToFind] + 1);
      result.push_back(i + 1);
      return result;
    }

    //number was not found. Put it in the map.
    hash[nums[i]] = i;
  }
  return result;


}

int Solution1::maxSubArray(vector<int>& nums) {

  /*
     53. Maximum Subarray My Submissions Question
     Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

     For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
     the contiguous subarray [4,−1,2,1] has the largest sum = 6.

     click to show more practice.

     Subscribe to see which companies asked this question
     */
  /*
     Analysis of this problem: Apparently, this is a optimization problem, which can be usually solved by DP.
     So when it comes to DP, the first thing for us to figure out is the format of the sub problem(or the state of each sub problem).
     The format of the sub problem can be helpful when we are trying to come up with the recursive relation.

     At first, I think the sub problem should look like: maxSubArray(int A[], int i, int j), which means the maxSubArray for A[i: j].
     In this way, our goal is to figure out what maxSubArray(A, 0, A.length - 1) is. However, if we define the format of the sub problem in this way,
     it's hard to find the connection from the sub problem to the original problem(at least for me). In other words,
     I can't find a way to divided the original problem into the sub problems and use the solutions of the sub problems to somehow create the solution of the original one.

     So I change the format of the sub problem into something like: maxSubArray(int A[], int i),
     which means the maxSubArray for A[0:i ] which must has A[i] as the end element.
     Note that now the sub problem's format is less flexible and less powerful than the previous one because there's a limitation
     that A[i] should be contained in that sequence and we have to keep track of each solution of the sub problem to update the global optimal value.
     However, now the connect between the sub problem & the original one becomes clearer:

     maxSubArray(A, i) = maxSubArray(A, i - 1) > 0 ? maxSubArray(A, i - 1) : 0 + A[i];
     */

  int n = nums.size();
  vector<int> dp(n); //dp[i] means the maximum subarray ending with nums[i];
  dp[0] = nums[0];
  int maxNum = dp[0];

  for (int i = 1; i < n; i++){
    dp[i] = nums[i] + (dp[i - 1] > 0 ? dp[i - 1] : 0);
    maxNum = max(maxNum, dp[i]);
  }

  return maxNum;

}

int Solution1::maxProduct(vector<int>& nums) {
  /*
     152. Maximum Product Subarray My Submissions Question
     Total Accepted: 48724 Total Submissions: 231077 Difficulty: Medium
     Find the contiguous subarray within an array (containing at least one number) which has the largest product.

     For example, given the array [2,3,-2,4],
     the contiguous subarray [2,3] has the largest product = 6.

     Subscribe to see which companies asked this question
     */
  if (nums.size() == 0) {
    return 0;
  }

  int maxherepre = nums[0];
  int minherepre = nums[0];
  int maxsofar = nums[0];
  int maxhere, minhere;

  for (int i = 1; i < nums.size(); i++) {
    maxhere = max(max(maxherepre * nums[i], minherepre * nums[i]), nums[i]);
    minhere = min(min(maxherepre * nums[i], minherepre * nums[i]), nums[i]);
    maxsofar = max(maxhere, maxsofar);
    maxherepre = maxhere;
    minherepre = minhere;
  }
  return maxsofar;
}

vector<vector<int>> Solution1::subsets(vector<int>& nums) {
  /*
     78. Subsets My Submissions Question
     Total Accepted: 78118 Total Submissions: 261517 Difficulty: Medium
     Given a set of distinct integers, nums, return all possible subsets.

     Note:
     Elements in a subset must be in non-descending order.
     The solution set must not contain duplicate subsets.
     For example,
     If nums = [1,2,3], a solution is:

     [
     [3],
     [1],
     [2],
     [1,2,3],
     [1,3],
     [2,3],
     [1,2],
     []
     ]
     */
  int n = nums.size();
  int length = pow(2, n);
  vector<vector<int>> retV;
  sort(nums.begin(), nums.end());
  for (int i = 0; i < length; i++){
    vector<int> localV;
    int offset = 0;
    for (int setN = i; setN > 0; setN = setN >> 1){
      int x = setN % 2;
      if (x == 1) localV.push_back(nums[offset]);
      offset++;
    }
    retV.push_back(localV);
  }
  return retV;

}

vector<vector<int>> Solution1::subsetsBT(vector<int>& nums) {
  sort(nums.begin(), nums.end());
  vector<vector<int>> subs;
  vector<int> sub;
  genSubsetsBT(nums, 0, sub, subs);
  return subs;
}

void Solution1::genSubsetsBT(vector<int>& nums, int start, vector<int>& sub, vector<vector<int>>& subs) {
  subs.push_back(sub);
  for (int i = start; i < nums.size(); i++) {
    sub.push_back(nums[i]);
    genSubsetsBT(nums, i + 1, sub, subs);
    sub.pop_back();
  }
}

vector<vector<int>> Solution1::subsetsIterative(vector<int>& nums) {
  /*
     Iterative

     This problem can also be solved iteratively. Take [1, 2, 3] in the problem statement as an example. The process of generating all the subsets is like:

     Initially: [[]]
     Adding the first number to all the existed subsets: [[], [1]];
     Adding the second number to all the existed subsets: [[], [1], [2], [1, 2]];
     Adding the third number to all the existed subsets: [[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]].
     */
  sort(nums.begin(), nums.end());
  vector<vector<int>> subs(1, vector<int>());
  //TODO: awesome
  for (int i = 0; i < nums.size(); i++) {
    int n = subs.size();
    for (int j = 0; j < n; j++) {
      subs.push_back(subs[j]);
      subs.back().push_back(nums[i]);
    }
  }
  return subs;
}

vector<vector<int>> Solution1::subsetsWithDup(vector<int>& nums) {
  /*
     90. Subsets II My Submissions Question
     Total Accepted: 56756 Total Submissions: 194260 Difficulty: Medium
     Given a collection of integers that might contain duplicates, nums, return all possible subsets.

     Note:
     Elements in a subset must be in non-descending order.
     The solution set must not contain duplicate subsets.
     For example,
     If nums = [1,2,2], a solution is:

     [
     [2],
     [1],
     [1,2,2],
     [2,2],
     [1,2],
     []
     ]
     */
  // TODO : not fully understand
  //https://leetcode.com/discuss/14902/c-solution-and-explanation
  std::sort(nums.begin(), nums.end());
  std::vector<std::vector<int> > res;
  std::vector<int> vec;
  subsetsWithDupBT(res, nums, vec, 0);
  return res;
}

void Solution1::subsetsWithDupBT(std::vector<std::vector<int> > &res, std::vector<int> &nums, std::vector<int> &vec, int begin) {
  res.push_back(vec);
  for (int i = begin; i != nums.size(); ++i)
  if (i == begin || nums[i] != nums[i - 1]) {
    vec.push_back(nums[i]);
    subsetsWithDupBT(res, nums, vec, i + 1);
    vec.pop_back();
  }
}

vector<int> Solution1::majorityElementTwo(vector<int>& nums) {
  /*
     229. Majority Element II My Submissions Question
     Total Accepted: 19876 Total Submissions: 80472 Difficulty: Medium
     Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times. The algorithm should run in linear time and in O(1) space.

     Hint:

     How many majority elements could it possibly have?Show More Hint
     Subscribe to see which companies asked this question
     */

  /*
     We can apply the same idea as easy version of majority element.
     If we remove three elements with different value at the same time,
     finally we should filter out the majority elements. So in the first pass, we search for possible majority elements
     (the number of majority element <3), and then for each candidate, we scan the array again to confirm wether it's majority or not.

     Updated Some guys are confused by the first branch, i.e.

     if(nums[i] == candidate1) count1 ++;
     Here we don't need to verify the value of count1. Why? Because if count1 is 0, and nums[i] = candidate1, we can still just add one to count1. It's logically safe.:
     */
  int candidate1 = 0, candidate2 = 0, count1 = 0, count2 = 0;
  for (int num : nums) {
    if (num == candidate1) count1++;
    else if (num == candidate2) count2++;
    else {
      if (!count1) {
        candidate1 = num;
        count1++;
      }
      else if (!count2) {
        candidate2 = num;
        count2++;
      }
      else {
        count1--;
        count2--;
      }
    }
    printf("num = %d, count1 = %d, count2 = %d, candidate1 = %d, candidiate2 = %d\n", num, count1, count2, candidate1, candidate2);
  }
  count1 = count2 = 0;
  for (int num : nums) {
    if (num == candidate1) count1++;
    else if (num == candidate2) count2++;
  }
  int n = nums.size();
  vector<int> majority;
  if (count1 > n / 3) majority.push_back(candidate1);
  if (count2 > n / 3) majority.push_back(candidate2);
  /*
     num = 2, count1 = 1, count2 = 0, candidate1 = 2, candidiate2 = 0
     num = 0, count1 = 1, count2 = 1, candidate1 = 2, candidiate2 = 0
     num = 1, count1 = 0, count2 = 0, candidate1 = 2, candidiate2 = 0
     num = 1, count1 = 1, count2 = 0, candidate1 = 1, candidiate2 = 0
     num = 2, count1 = 1, count2 = 1, candidate1 = 1, candidiate2 = 2
     */

  return majority;
}

int Solution1::findPeakElement(vector<int>& nums) {
  /*
     162. Find Peak Element My Submissions Question
     Total Accepted: 52099 Total Submissions: 159556 Difficulty: Medium
     A peak element is an element that is greater than its neighbors.

     Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.

     The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

     You may imagine that num[-1] = num[n] = -∞.

     For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.

     click to show spoilers.

     Note:
     Your solution should be in logarithmic complexity.
     https://leetcode.com/discuss/17793/find-the-maximum-by-binary-search-recursion-and-iteration:
     */
  int low = 0;
  int high = nums.size() - 1;

  while (low < high)
  {
    int mid1 = (low + high) / 2;
    int mid2 = mid1 + 1;
    if (nums[mid1] < nums[mid2])
      low = mid2;
    else
      high = mid1;
  }
  return low;
}

int Solution1::findMin(vector<int>& nums) {
  /*
     153. Find Minimum in Rotated Sorted Array My Submissions Question
     Total Accepted: 74811 Total Submissions: 213938 Difficulty: Medium
     Suppose a sorted array is rotated at some pivot unknown to you beforehand.

     (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

     Find the minimum element.

     You may assume no duplicate exists in the array.

     Subscribe to see which companies asked this question
     */
  /*
     In this problem, we have only three cases.

     Case 1. The leftmost value is less than the rightmost value in the list: This means that the list is not rotated. e.g> [1 2 3 4 5 6 7 ]

     Case 2. The value in the middle of the list is greater than the leftmost and rightmost values in the list. e.g> [ 4 5 6 7 0 1 2 3 ]

     Case 3. The value in the middle of the list is less than the leftmost and rightmost values in the list. e.g> [ 5 6 7 0 1 2 3 4 ]

     As you see in the examples above, if we have case 1, we just return the leftmost value in the list.
     If we have case 2, we just move to the right side of the list. If we have case 3 we need to move to the left side of the list.
     */

  int left = 0, right = nums.size() - 1;
  while (left < right) {
    if (nums[left] < nums[right])
      return nums[left];

    int mid = (left + right) / 2;
    if (nums[mid] > nums[right])
      left = mid + 1;
    else
      right = mid;
  }

  return nums[left];

}

bool Solution1::searchDup(vector<int>& nums, int target) {
  /*
     81. Search in Rotated Sorted Array II My Submissions Question
     Total Accepted: 53551 Total Submissions: 170087 Difficulty: Medium
     Follow up for "Search in Rotated Sorted Array":
     What if duplicates are allowed?

     Would this affect the run-time complexity? How and why?

     Write a function to determine if a given target is in the array.

     Subscribe to see which companies asked this question
     */
  /*
     The idea is the same as the previous one without duplicates

     1) everytime check if targe == nums[mid], if so, we find it.
     2) otherwise, we check if the first half is in order (i.e. nums[left]<=nums[mid])
     and if so, go to step 3), otherwise, the second half is in order,   go to step 4)
     3) check if target in the range of [left, mid-1]
     (i.e. nums[left]<=target < nums[mid]), if so, do search in the first half, i.e. right = mid-1; otherwise, search in the second half left = mid+1;
     4)  check if target in the range of [mid+1, right]
     (i.e. nums[mid]<target <= nums[right]), if so, do search in the second half, i.e. left = mid+1; otherwise search in the first half right = mid-1;

     The only difference is that due to the existence of duplicates, we can have nums[left] == nums[mid] and in that case, the first half could be out of order
     (i.e. NOT in the ascending order, e.g. [3 1 2 3 3 3 3]) and we have to deal this case separately.
     In that case, it is guaranteed that nums[right] also equals to nums[mid],
     so what we can do is to check if nums[mid]== nums[left] == nums[right] before the original logic,
     and if so, we can move left and right both towards the middle by 1. and repeat.
     */
  int left = 0, right = nums.size() - 1, mid;

  while (left <= right)
  {
    mid = (left + right) >> 1;
    if (nums[mid] == target) return true;

    // the only difference from the first one, trickly case, just updat left and right
    if ((nums[left] == nums[mid]) && (nums[right] == nums[mid])) { ++left; --right; }

    else if (nums[left] <= nums[mid])
    {
      if ((nums[left] <= target) && (nums[mid] > target)) right = mid - 1;
      else left = mid + 1;
    }
    else
    {
      if ((nums[mid] < target) && (nums[right] >= target)) left = mid + 1;
      else right = mid - 1;
    }
  }
  return false;
}

int Solution1::removeDuplicatesTwo(vector<int>& nums) {
  /*
     80. Remove Duplicates from Sorted Array II My Submissions Question
     Total Accepted: 62523 Total Submissions: 197562 Difficulty: Medium
     Follow up for "Remove Duplicates":
     What if duplicates are allowed at most twice?

     For example,
     Given sorted array nums = [1,1,1,2,2,3],
     watch : 1 ,1 1 1 2 2 3
     watch : 1 ,1 1 2 2 2 3
     watch : 1 ,1 1 2 2 2 3
     watch : 1 ,1 1 2 2 3 3


     nums = [1,1,1,1,1,1,2,2,2,3],

     watch : 1 ,1 1 1 1 1 1 2 2 2 3
     watch : 2 ,1 1 1 1 1 1 2 2 2 3
     watch : 3 ,1 1 1 1 1 1 2 2 2 3
     watch : 4 ,1 1 1 1 1 1 2 2 2 3
     watch : 4 ,1 1 2 1 1 1 2 2 2 3
     watch : 4 ,1 1 2 2 1 1 2 2 2 3
     watch : 5 ,1 1 2 2 1 1 2 2 2 3
     watch : 5 ,1 1 2 2 3 1 2 2 2 3

     Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.

     Subscribe to see which companies asked this question
     */
  int count = 0;
  int n = nums.size();
  if (n == 1) return 1;
  for (int i = 2; i < nums.size(); i++){
    if (nums[i] == nums[i - 2 - count])
      count++;
    else{
      nums[i - count] = nums[i];
      //count = 0;
    }
    printVector(nums, count);
  }
  return n - count;

}

int Solution1::removeDuplicatesTwoSec(vector<int>& nums) {
  int len = nums.size(), i, K = 2, last = K;
  if (len <= K) return len;
  for (i = K; i < len; ++i)
  {
    if (nums[i] != nums[last - K]) nums[last++] = nums[i]; // note it is last-K
    printf("%d ", i);
    printVector(nums, last);
  }
  return last;
}

void Solution1::sortColorsOnePass(vector<int>& nums) {
  /*
     75. Sort Colors My Submissions Question
     Total Accepted: 82009 Total Submissions: 242939 Difficulty: Medium
     Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

     Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

     Note:
     You are not suppose to use the library's sort function for this problem.

     click to show follow up.

     Subscribe to see which companies asked this question
     */
  int n = nums.size();
  int second = n - 1, zero = 0;
  for (int i = 0; i <= second; i++) {
    while (nums[i] == 2 && i<second) swap(nums[i], nums[second--]);
    while (nums[i] == 0 && i>zero) swap(nums[i], nums[zero++]);
  }
}

void Solution1::sortColorsTwoPass(vector<int>& nums) {
  int num0 = 0, num1 = 0, num2 = 0;
  int n = nums.size();

  for (int i = 0; i < n; i++) {
    if (nums[i] == 0) ++num0;
    else if (nums[i] == 1) ++num1;
    else if (nums[i] == 2) ++num2;
  }

  for (int i = 0; i < num0; ++i) nums[i] = 0;
  for (int i = 0; i < num1; ++i) nums[num0 + i] = 1;
  for (int i = 0; i < num2; ++i) nums[num0 + num1 + i] = 2;
}


void Solution1::sortColorsBucket(vector<int>& nums) {
  vector<int> buckets(3);
  for (int num : nums) buckets[num]++;
  for (int p = 0, val = 0; val < 3; val++) {
    for (int count = 0; count < buckets[val]; count++) {
      nums[p++] = val;
    }
  }
}
void Solution1::gameOfLife(vector<vector<int>>& board) {
  /*
     289. Game of Life My Submissions Question
     Total Accepted: 10403 Total Submissions: 31686 Difficulty: Medium
     According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

     Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

     Any live cell with fewer than two live neighbors dies, as if caused by under-population.
     Any live cell with two or three live neighbors lives on to the next generation.
     Any live cell with more than three live neighbors dies, as if by over-population..
     Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
     Write a function to compute the next state (after one update) of the board given its current state.

     < 2 , die
     2 or 3 , live
     >3, die
     dead cell  , with 3 live neighbor, live

     Follow up:
     Could you solve it in-place? Remember that the board needs to be updated at the same time:
     You cannot update some cells first and then use their updated values to update other cells.
     In this question, we represent the board using a 2D array.
     In principle, the board is infinite, which would cause problems when the active area encroaches the border of the array. How would you address these problems?
     */
  int m = board.size(), n = m ? board[0].size() : 0;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      int count = 0;
      for (int I = max(i - 1, 0); I < min(i + 2, m); ++I)
      for (int J = max(j - 1, 0); J < min(j + 2, n); ++J)
        count += board[I][J] & 1;
      if (count == 3 || count - board[i][j] == 3)
        board[i][j] |= 2;
    }
  }
  for (int i = 0; i < m; ++i)
  for (int j = 0; j < n; ++j)
    board[i][j] >>= 1;
}

vector<int> Solution1::spiralOrder(vector<vector<int>>& matrix) {
  /*
     When traversing the matrix in the spiral order, at any time we follow one out of the following four directions: RIGHT DOWN LEFT UP. Suppose we are working on a 5 x 3 matrix as such:

     0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15

     Imagine a cursor starts off at (0, -1), i.e. the position at '0', then we can achieve the spiral order by doing the following:

     Go right 5 times
     Go down 2 times
     Go left 4 times
     Go up 1 times.
     Go right 3 times
     Go down 0 times -> quit
     Notice that the directions we choose always follow the order 'right->down->left->up', and for horizontal movements, the number of shifts follows:{5, 4, 3}, and vertical movements follows {2, 1, 0}.

     Thus, we can make use of a direction matrix that records the offset for all directions, then an array of two elements that stores the number of shifts for horizontal and vertical movements, respectively. This way, we really just need one for loop instead of four.

     Another good thing about this implementation is that: If later we decided to do spiral traversal on a different direction (e.g. Counterclockwise), then we only need to change the Direction matrix; the main loop does not need to be touched.
     */

  /*
     When traversing the matrix in the spiral order, at any time we follow one out of the following four directions: RIGHT DOWN LEFT UP. Suppose we are working on a 5 x 3 matrix as such:

     0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15

     Imagine a cursor starts off at (0, -1), i.e. the position at '0', then we can achieve the spiral order by doing the following:

     Go right 5 times
     Go down 2 times
     Go left 4 times
     Go up 1 times.
     Go right 3 times
     Go down 0 times -> quit

     Notice that the directions we choose always follow the order 'right->down->left->up', and for horizontal movements,
     the number of shifts follows:{5, 4, 3}, and vertical movements follows {2, 1, 0}.

     Thus, we can make use of a direction matrix that records the offset for all directions,
     then an array of two elements that stores the number of shifts for horizontal and vertical movements, respectively.
     This way, we really just need one for loop instead of four.

     Another good thing about this implementation is that: If later we decided to do spiral traversal on a different direction
     (e.g. Counterclockwise), then we only need to change the Direction matrix; the main loop does not need to be touched.
     */
  vector<vector<int> > dirs{ { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
  vector<int> res;
  int nr = matrix.size();     if (nr == 0) return res;
  int nc = matrix[0].size();  if (nc == 0) return res;

  vector<int> nSteps{ nc, nr - 1 }; //init only 2 values , for 5x3, -> 4

  int iDir = 0;   // index of direction.
  int ir = 0, ic = -1;    // initial position
  while (nSteps[iDir % 2]) {
    for (int i = 0; i < nSteps[iDir % 2]; ++i) {
      ir += dirs[iDir][0];
      ic += dirs[iDir][1];
      res.push_back(matrix[ir][ic]);
    }
    nSteps[iDir % 2]--;
    iDir = (iDir + 1) % 4;
  }
  return res;
}

vector<vector<int>> Solution1::generateMatrix(int n) {
  /*
     59. Spiral Matrix II My Submissions Question
     Total Accepted: 44672 Total Submissions: 133167 Difficulty: Medium
     Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

     For example,
     Given n = 3,

     You should return the following matrix:
     [
     [ 1, 2, 3 ],
     [ 8, 9, 4 ],
     [ 7, 6, 5 ]
     ]
     */
  vector<vector<int> > ret(n, vector<int>(n));
  int k = 1, i = 0;
  while (k <= n * n)
  {
    int j = i;
    // four steps
    while (j < n - i)             // 1. horizonal, left to right
      ret[i][j++] = k++;
    j = i + 1;
    while (j < n - i)             // 2. vertical, top to bottom
      ret[j++][n - i - 1] = k++;
    j = n - i - 2;
    while (j > i)                  // 3. horizonal, right to left
      ret[n - i - 1][j--] = k++;
    j = n - i - 1;
    while (j > i)                  // 4. vertical, bottom to  top
      ret[j--][i] = k++;
    i++;      // next loop
  }
  return ret;
}

int Solution1::maxProfitSec(vector<int>& prices) {

  /*
     122. Best Time to Buy and Sell Stock II My Submissions Question
     Total Accepted: 72747 Total Submissions: 178608 Difficulty: Medium
     Say you have an array for which the ith element is the price of a given stock on day i.

     Design an algorithm to find the maximum profit.
     You may complete as many transactions as you like
     (ie, buy one and sell one share of the stock multiple times).
     However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

     Subscribe to see which companies asked this question
     */
  int ret = 0;
  for (size_t p = 1; p < prices.size(); ++p)
    ret += max(prices[p] - prices[p - 1], 0);
  return ret;

}

int Solution1::jump(vector<int>& nums) {
  /*
     45. Jump Game II My Submissions Question
     Total Accepted: 55707 Total Submissions: 225119 Difficulty: Hard
     Given an array of non-negative integers, you are initially positioned at the first index of the array.

     Each element in the array represents your maximum jump length at that position.

     Your goal is to reach the last index in the minimum number of jumps.

     For example:
     Given array A = [2,3,1,1,4]

     The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

     Note:
     You can assume that you can always reach the last index.

     Subscribe to see which companies asked this question
     */
  // 2 1 5 2 4 6
  int j = 0;
  int leastStep = 0;

  int localMax = nums[0];
  if (nums.size() == 1) return 0;
  if (localMax >= nums.size() - 1) return 1;
  leastStep = 1;
  while (localMax< nums.size() - 1)
  {
    localMax = 0;
    int candidateJ = 0;
    for (int i = j; i <= j + nums[j]; i++){
      if (i + nums[i] > localMax){
        localMax = max(localMax, i + nums[i]);
        candidateJ = i;
      }
    }
    leastStep++;
    j = candidateJ;
  }

  printf("%d\n", leastStep);
  return leastStep;

}

int Solution1::firstMissingPositive(vector<int>& nums) {
  /*
     41. First Missing Positive My Submissions Question
     Total Accepted: 55712 Total Submissions: 238989 Difficulty: Hard
     Given an unsorted integer array, find the first missing positive integer.

     For example,
     Given [1,2,0] return 3,
     and [3,4,-1,1] return 2.

     Your algorithm should run in O(n) time and uses constant space.

     Subscribe to see which companies asked this question
     */
  return 0;
}

int Solution1::longestConsecutive(vector<int>& nums)
{
  /*
     128. Longest Consecutive Sequence My Submissions Question
     Total Accepted: 56382 Total Submissions: 182176 Difficulty: Hard
     Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

     For example,
     Given [100, 4, 200, 1, 3, 2],
     The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

     Your algorithm should run in O(n) complexity.

     Subscribe to see which companies asked this question
     */

  /*
     I have seen a lot of discussion about this problem.In my opinion,it is not correct to use set(which is ordered),
     because very time we insert an element to a ordered set,it will cost O(n),so the total complexity is O(nlogn),
     which violates the request of the problem.So here we use an unordered_set,and one is enough.

     Besides,to think about this problem,one principle issue we should realize is that usually when we want to reduce the time complexity,
     we have to increase the space complexity.In this case,if we want to access an element within O(1),we have to use hash table.
     */
  unordered_set<int> record(nums.begin(), nums.end());
  int res = 1;
  for (int n : nums){
    if (record.find(n) == record.end()) continue;
    record.erase(n);
    int prev = n - 1, next = n + 1;
    while (record.find(prev) != record.end()) record.erase(prev--);
    while (record.find(next) != record.end()) record.erase(next++);
    res = max(res, next - prev - 1);
  }
  return res;
}

void rotate(vector<vector<int> > &matrix) {
  /**********************************************************************************
   *
   * You are given an n x n 2D matrix representing an image.
   * Rotate the image by 90 degrees (clockwise).
   * Follow up:
   * Could you do this in-place?
   *
   **********************************************************************************/

  /*
     [0,0] -> [3,0]
     [3,0] -> [3,3]
     [3,3] -> [0,3]
     [0,3] -> [0,0]

     [1,0] -> [3,1]
     [3,1] -> [2,3]
     [2,3] -> [0,2]
     [0,2] -> [1,0]

     [2,0] -> [3,2]
     [3,2] -> [1,3]
     [1,3] -> [0,1]
     [0,1] -> [2,0]
     */
  int n = matrix.size();
  for (int i = 0; i < n / 2; i++){
    int low = i, high = n - i - 1;
    for (int j = low; j < high; j++){
      int tmp;
      tmp = matrix[i][j];
      matrix[i][j] = matrix[n - j - 1][i];
      matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
      matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
      matrix[j][n - i - 1] = tmp;
    }
  }
}

void nextPermutation(vector<int>& nums) {
  /*
   *    1 2 3 4
   *    1 2 4 3
   *    1 3 2 4
   *    1 3 4 2
   *    1 4 2 3
   *    1 4 3 2
   *    2 1 3 4
   1) Find the largest index k such that nums[k] < nums[k + 1]. If no such index
   exists, the permutation is sorted in descending order, just reverse it to
   ascending order and we are done. For example, the next permutation of [3, 2, 1]
   is [1, 2, 3].

   2) Find the largest index l greater than k such that nums[k] < nums[l].

   3) Swap the value of nums[k] with that of nums[l].

   4) Reverse the sequence from nums[k + 1] up to and including the final element
   nums[nums.size() - 1].
   Quite simple, yeah? Now comes the following code, which is barely a translation.
   */

  int k = -1;
  for (int i = nums.size() - 2; i >= 0; i--) {
    if (nums[i] < nums[i + 1]) {
      k = i;
      break;
    }
  }
  if (k == -1) {
    reverse(nums.begin(), nums.end());
    return;
  }
  int l = -1;
  for (int i = nums.size() - 1; i > k; i--) {
    if (nums[i] > nums[k]) {
      l = i;
      break;
    }
  }
  swap(nums[k], nums[l]);
  reverse(nums.begin() + k + 1, nums.end());
}

TreeNode* buildTreeHelper(vector<int>& post, int is, int ie, int ps, int pe, unordered_map<int, int>& inorder_map) {

  // tree:     8 4 10 3 6 9 11
  // Inorder   [3 4 6] 8 [9 10 11]
  // postorder [3 6 4]   [9 11 10] 8

  if (is > ie || ps > pe) {
    return NULL;
  }
  int root_val = post[pe];
  TreeNode* root = new TreeNode(root_val);
  int i = inorder_map.find(root_val)->second;
  // number of nodes in left subtree
  int l = i - is;
  root->left = buildTreeHelper(post, is, is + l - 1, ps, ps + l - 1, inorder_map);
  root->right = buildTreeHelper(post, is + l + 1, ie, ps + l, pe - 1, inorder_map);

  return root;
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {

  /**********************************************************************************
   *
   * Given inorder and postorder traversal of a tree, construct the binary tree.
   *
   * Note:
   * You may assume that duplicates do not exist in the tree.
   *
   *
   **********************************************************************************/
  unordered_map<int, int> inorder_map;
  // we need a map to look up the position of root in inorder, so
  // that we can divide the tree into separate subtrees,
  // reduces the complexity from n^2 to n assuming good hashing by unodered_map
  for (int i = 0; i < inorder.size(); ++i) {
    inorder_map[inorder[i]] = i;
  }
  return buildTreeHelper(postorder, 0, inorder.size() - 1, 0, postorder.size() - 1, inorder_map);
}

TreeNode* helper(vector<int>& preorder, int preOrder_s, int preOrder_e, vector<int>& inorder, int inOrder_s, int inOrder_e)
{
  // tree        8 4 5 3 7 3
  // preorder    8 [4 3 3 7] [5]
  // inorder     [3 3 4 7] 8 [5]

  if (preOrder_s >= preOrder_e || inOrder_s >= preOrder_e)
    return NULL;

  int mid = preorder[preOrder_s];
  auto f = find(inorder.begin() + inOrder_s, inorder.begin() + inOrder_e, mid);

  int dis = f - inorder.begin() - inOrder_s;

  TreeNode* root = new TreeNode(mid);
  root->left = helper(preorder, preOrder_s + 1, preOrder_s + 1 + dis, inorder, inOrder_s, inOrder_s + dis);
  root->right = helper(preorder, preOrder_s + 1 + dis, preOrder_e, inorder, inOrder_s + dis + 1, inOrder_e);
  return root;
}

TreeNode* buildTreePreAndIn(vector<int>& preorder, vector<int>& inorder) {

  /**********************************************************************************
   *
   * Given preorder and inorder traversal of a tree, construct the binary tree.
   *
   * Note:
   * You may assume that duplicates do not exist in the tree.
   *
   *
   **********************************************************************************/
  return helper(preorder, 0, preorder.size(), inorder, 0, inorder.size());
}

int maxArea(vector<int> &height) {
  /**********************************************************************************
   *
   * Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai).
   * n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).
   *
   * Find two lines, which together with x-axis forms a container, such that the container contains the most water.
   *
   * Note: You may not slant the container.
   *
   *
   **********************************************************************************/

  int maxArea = 0;
  // two pointers scan from two sides to middle
  int left = 0;
  int right = height.size() - 1;

  int area;
  while (left < right){
    // calculate the area
    //area = (right - left) * ( height[left] < height[right] ? height[left] : height[right]);
    area = (right - left) * (min(height[left], height[right]));

    // tracking the maxium area
    maxArea = area > maxArea ? area : maxArea;
    // because the area is decided by the shorter edge
    // so we increase the area is to increase the shorter edge
    //
    //     height[left] < height[right] ? left++ : right-- ;
    //
    // However, the above code could cause the unnecessary `area` cacluation
    // We can do some improvement as below:
    if (height[left] < height[right]) {
      do {
        left++;
      } while (left < right && height[left - 1] >= height[left]);
    }
    else {
      do {
        right--;
      } while (right > left && height[right + 1] >= height[right]);
    }
  }

  return maxArea;
}


int computeAreaMT(int A, int B, int C, int D, int E, int F, int G, int H) {

  /**********************************************************************************
   *
   * Find the total area covered by two rectilinear rectangles in a 2D plane.
   * Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.
   *
   *                      Y
   *                      ^
   *                      |
   *                      |
   *                      |
   *                      |
   *                      |     (C,D):(3,4)
   *            +------------------+
   *            |         |        |
   *            |         |        |
   *            |         |        |               (G,H):(9,2)
   *            |         +----------------------------+
   *            |         |        |                   |
   *            |         |        |                   |
   *            |         |        |                   |
   *            +---------|--------+-------------------|---------> X
   *      (A,B):(-3,0)    |                            |
   *                      +----------------------------+
   *                  (E,F):(0,-1)
   *
   *
   *
   * Assume that the total area is never beyond the maximum possible value of int.
   *
   * Credits:Special thanks to @mithmatt for adding this problem, creating the above image and all test cases.
   *
   **********************************************************************************/
  int together;
  if (C <= E || A >= G || B >= H || D <= F) {
    together = 0;
  }
  else {
    int x = min(C, G) - max(A, E);
    int y = min(D, H) - max(B, F);
    together = x * y;
  }
  return (C - A) * (D - B) + (G - E) * (H - F) - together;
}

int divide(int dividend, int divisor) {
  /**********************************************************************************
   *
   * Divide two integers without using multiplication, division and mod operator.
   *
   * If it is overflow, return MAX_INT.
   *
   **********************************************************************************/
  if (!divisor || (dividend == INT_MIN && divisor == -1))
    return INT_MAX;
  int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
  long long dvd = labs(dividend);
  long long dvs = labs(divisor);
  int res = 0;
  while (dvd >= dvs) {
    long long temp = dvs, multiple = 1;
    while (dvd >= (temp << 1)) {
      temp <<= 1;
      multiple <<= 1;
    }
    dvd -= temp;
    res += multiple;
  }
  return sign == 1 ? res : -res;
}

int bulbSwitch(int n) {
  /***************************************************************************************
   *
   * There are n bulbs that are initially off. You first turn on all the bulbs. Then, you
   * turn off every second bulb. On the third round, you toggle every third bulb (turning
   * on if it's off or turning off if it's on). For the nth round, you only toggle the
   * last bulb. Find how many bulbs are on after n rounds.
   *
   * Example:
   *
   * Given n = 3.
   *
   * At first, the three bulbs are [off, off, off].
   * After first round, the three bulbs are [on, on, on].
   * After second round, the three bulbs are [on, off, on].
   * After third round, the three bulbs are [on, off, off].
   *
   * So you should return 1, because there is only one bulb is on.
   *
   ***************************************************************************************/
  /*
Ok, very verbose explanation, but clear enough for everyone to understand.

the initial state all bulbs are off.

if at last the bulb was toggled odd number of times, it is on. if toggled even number of times, it is off.

simple enough, and that number is determined by how many factors a number has. note that every number has 1 and itself as a factor. and if it has multiple times of a factor it only counted once.

1 --------- 1

2 --------- 1, 2

3 --------- 1, 3

4 --------- 1, 2, 4

5 --------- 1, 5

6 --------- 1, 2, 3, 6

7 --------- 1, 7

8 --------- 1, 2, 4, 8

9 --------- 1, 3, 9

see that only square numbers like 1, 4 and 9 has odd number of factors. bulbs at those numbers will left on after all the rounds of toggle.

so basically, we calculate how many square numbers are there within a given number. and we can get it simply by calculate the square root of that number. of course the decimal part is eliminated.
*/
  return (int)sqrt(n);
}
