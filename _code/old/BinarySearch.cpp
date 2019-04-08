#include "stdafx.h"
#include "BinarySearch.h"
#include "string"
#include<algorithm>
#include<vector>
#include<stack>
#include<ctime>
#include<iostream>
#include<set>
#include"type.h"
#include<unordered_map>
#include<unordered_set>

//#include<numeric>
#define GUARD -10000

using namespace std;
int search1(vector<int> &nums, int key);

/*
270 : Closest Binary Search Tree Value          : 33.8% : Easy : non
278 : First Bad Version                         : 22.2% : Easy : ok
69  : Sqrt(x)                                   : 25.1% : Medium :ok
29  : Divide Two Integers                       : 15.6% : Medium :ok
34  : Search for a Range                        : 28.9% : Medium :ok
81  : Search in Rotated Sorted Array II         : 31.8% : Medium :ok
300 : Longest Increasing Subsequence            : 34.0% : Medium :ok
74  : Search a 2D Matrix                        : 33.5% : Medium :ok
240 : Search a 2D Matrix II                     : 34.0% : Medium :ok
50  : Pow(x, n)                                 : 27.9% : Medium :ok
209 : Minimum Size Subarray Sum                 : 26.5% : Medium :ok
35  : Search Insert Position                    : 37.1% : Medium :ok
153 : Find Minimum in Rotated Sorted Array      : 35.9% : Medium :ok
230 : Kth Smallest Element in a BST             : 36.9% : Medium :ok
275 : H-Index II                                : 32.4% : Medium :non
222 : Count Complete Tree Nodes                 : 24.7% : Medium :ok
167 : Two Sum II - Input array is sorted        : 47.6% : Medium :non
162 : Find Peak Element                         : 32.9% : Medium :ok
33  : Search in Rotated Sorted Array            : 30.1% : Hard :ok
174 : Dungeon Game                              : 20.6% : Hard :non
154 : Find Minimum in Rotated Sorted Array II   : 34.1% : Hard :non
287 : Find the Duplicate Number                 : 38.2% : Hard :ok
4   : Median of Two Sorted Arrays               : 18.4% : Hard :non
302 : Smallest Rectangle Enclosing Black Pixels : 38.7% : Hard :non
*/

bool isBadVersion(int version)
{
  return false;

}

int firstBadVersion(int n) {
  /***************************************************************************************
   *
   * You are a product manager and currently leading a team to develop a new product.
   * Unfortunately, the latest version of your product fails the quality check. Since
   * each version is developed based on the previous version, all the versions after a
   * bad version are also bad.
   *
   * Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad
   * one, which causes all the following ones to be bad.
   *
   * You are given an API bool isBadVersion(version) which will return whether version is
   * bad. Implement a function to find the first bad version. You should minimize the
   * number of calls to the API.
   *
   * Credits:Special thanks to @jianchao.li.fighter for adding this problem and creating
   * all test cases.
   *
   ***************************************************************************************/
  int low = 1, high = n;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (isBadVersion(mid) && !isBadVersion(mid - 1)){
      return mid;
    }
    if (isBadVersion(mid)) {
      high = mid - 1;
    }
    else{
      low = mid + 1;
    }
  }
  return -1;
}

int mySqrt(int x) {

  // 69  : Sqrt(x)                                   : 25.1% : Medium :Ok
  /**********************************************************************************
   *
   * Implement int sqrt(int x).
   *
   * Compute and return the square root of x.
   *
   **********************************************************************************/

  if (x <=0 ) return 0;

  //the sqrt is not greater than x/2+1
  int e = x/2+1;
  int s = 0;
  // binary search
  while ( s <= e ) {
    int mid = s + (e-s)/2;
    long long sq = (long long)mid*(long long)mid;
    if (sq == x ) return mid;
    if (sq < x) {
      s = mid + 1;
    }else {
      e = mid - 1;
    }
  }
  return e;

}

int divide(int dividend, int divisor) {

  // 29  : Divide Two Integers                       : 15.6% : Medium
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

vector<int> searchRange(vector<int>& nums, int target) {
  // 34  : Search for a Range                        : 28.9% : Medium
  /*
   * 34. Search for a Range My Submissions Question
   Total Accepted: 77832 Total Submissions: 269230 Difficulty: Medium
   Given a sorted array of integers, find the starting and ending position of a given target value.

   Your algorithm's runtime complexity must be in the order of O(log n).

   If the target is not found in the array, return [-1, -1].

   For example,
   Given [5, 7, 7, 8, 8, 10] and target value 8,
   return [3, 4].

   Subscribe to see which companies asked this question
   * */
  int lo = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
  if (nums[lo] != target)
    return vector<int> {-1, -1};
  int hi = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
  return vector<int> {lo, hi};
}

int Solution::search(vector<int>& nums, int target) {
  /*
     81. Search in Rotated Sorted Array II My Submissions Question
     Total Accepted: 59464 Total Submissions: 186781 Difficulty: Medium
     Follow up for "Search in Rotated Sorted Array":
     What if duplicates are allowed?

     Would this affect the run-time complexity? How and why?

     Write a function to determine if a given target is in the array.

     Subscribe to see which companies asked this question
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

vector <int> longest_LIS;
int lengthOfLIS(vector<int>& nums) {
  // 300 : Longest Increasing Subsequence            : 34.0% : Medium :ok
  /***************************************************************************************
   *
   * Given an unsorted array of integers, find the length of longest increasing
   * subsequence.
   *
   * For example,
   * Given [10, 9, 2, 5, 3, 7, 101, 18],
   * The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4.
   * Note that there may be more than one LIS combination, it is only necessary for yo
   * to return the length.
   *
   * Your algorithm should run in O(n2) complexity.
   *
   * Follow up: Could you improve it to O(n log n) time complexity?
   *
   * Credits:
   * Special thanks to @pbrother for adding this problem and creating all test cases.
   *
   ***************************************************************************************/

  /*
   * Solution 1 - O(N^2)
   * =========
   *
   * LIS - longest increasing subsequence
   *
   * We iterate through the elements to find the LIS that ends with the current element.
   * To do that we need to look at all of the previous elements and find one smaller than
   * the current one so that we can add the current one to the sequence terminated in the
   * smaller one. The length of the LIS ending in the current element is the length of the
   * LIS ending in the smaller one + 1. To find the maximum current LIS we need to use the
   * maximum previous LIS that satisfies the conditions.
   *
   */
  /*
     10, 9, 2, 5, 3, 7, 101, 18
     1 1
     1 1 1
     1 1 1 2
     1 1 1 2 2
     1 1 1 2 2 3
     1 1 1 2 2 3 4
     1 1 1 2 2 3 4 4
     */
  int answer = 0;
  if(nums.size())
  {
    longest_LIS.push_back(1);
    answer = 1;
    for(int i = 1; i < nums.size(); i++)
    {
      int maximum = 1;
      for (int j = 0; j < longest_LIS.size(); j++)
        if(nums[i] > nums[j])
          maximum = max(maximum, longest_LIS[j] + 1);
      longest_LIS.push_back(maximum);
      answer = max(maximum, answer);
    }
  }
  return answer;
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
  /*
     74. Search a 2D Matrix My Submissions Question
     Total Accepted: 74394 Total Submissions: 221886 Difficulty: Medium
     Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

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
      start = mid + 1 ;
    else
      end = mid - 1 ;
  }
  return false;

}

bool searchMatrixII(vector<vector<int>>& matrix, int target) {
  /*
   * 240. Search a 2D Matrix II My Submissions Question
   Total Accepted: 32289 Total Submissions: 94922 Difficulty: Medium
   Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

   Integers in each row are sorted in ascending from left to right.
   Integers in each column are sorted in ascending from top to bottom.
   For example,

   Consider the following matrix:

   [
   [1,   4,  7, 11, 15],
   [2,   5,  8, 12, 19],
   [3,   6,  9, 16, 22],
   [10, 13, 14, 17, 24],
   [18, 21, 23, 26, 30]
   ]
   Given target = 5, return true.

   Given target = 20, return false.*/
  if (matrix.size() == 0 || matrix[0].size()==0) return false;
  int row=0,  col = matrix[0].size() - 1;
  while (row < matrix.size() && col >=0 ) {
    if (target == matrix[row][col]) return true;
    while ( col>=0 && target < matrix[row][col]) {
      col--;
    }
    while(row < matrix.size() && target > matrix[row][col]){
      row++;
    }
  }
  return false;
}

double powI(double x, int n) {
  /**********************************************************************************
   *
   * Implement pow(x, n).
   *
   *
   **********************************************************************************/
  /*
   *   Basically, most people think this is very easy as below:
   *
   *      double result = 1.0;
   *      for (int i=0; i<n; i++){
   *           result *=x;
   *      }
   *
   *   However,
   *
   *     1) We need think about the `n` is negtive number.
   *
   *     2) We need more wisely deal with the following cases:
   *
   *         pow(1, MAX_INT);
   *         pow(-1,BIG_INT);
   *         pow(2, BIG_INT);
   *
   *        To deal with such kind case, we can use x = x*x to reduce the `n` more quickly
   *
   *        so, if `n` is an even number, we can `x = x*x`, and `n = n>>1;`
   *            if `n` is an odd number, we can just `result *= x;`
   *
   */

  bool sign = false;
  unsigned int exp = n;
  if (n<0){
    exp = -n;
    sign = true;
  }
  double result = 1.0;
  while (exp) {
    if (exp & 1){
      result *= x;
    }
    exp >>= 1;
    x *= x;
  }

  return sign ? 1 / result : result;

}

int minSubArrayLen(int s, vector<int>& nums) {
  /*
   * 209. Minimum Size Subarray Sum My Submissions Question
   Total Accepted: 34743 Total Submissions: 131209 Difficulty: Medium
   Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum ≥ s. If there isn't one, return 0 instead.

   For example, given the array [2,3,1,2,4,3] and s = 7,
   the subarray [4,3] has the minimal length under the problem constraint.

   click to show more practice.

Credits:
Special thanks to @Freezen for adding this problem and creating all test cases.

Subscribe to see which companies asked this question
*/
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

int searchInsert(vector<int>& nums, int target) {
  /*
   * 35. Search Insert Position My Submissions Question
   Total Accepted: 99200 Total Submissions: 267685 Difficulty: Medium
   Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

   You may assume no duplicates in the array.

   Here are few examples.
   [1,3,5,6], 5 → 2
   [1,3,5,6], 2 → 1
   [1,3,5,6], 7 → 4
   [1,3,5,6], 0 → 0
   * */
  int n = nums.size();
  int start = 0, end = n - 1;
  int mid;
  while(start <= end){
    mid = (start + end) / 2;
    if(target == nums[mid]){
      return mid;
    }
    else if(target < nums[mid]){
      end = mid - 1;
    }
    else{
      start = mid + 1;
    }
  }
  return start;

}

int findMin(vector<int>& nums) {
  /*
   * 153. Find Minimum in Rotated Sorted Array My Submissions Question
   Total Accepted: 85459 Total Submissions: 238344 Difficulty: Medium
   Suppose a sorted array is rotated at some pivot unknown to you beforehand.

   (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

   Find the minimum element.

   You may assume no duplicate exists in the array.

   Subscribe to see which companies asked this question*/
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

int kthSmallestHelper_recursive(TreeNode* root, int& k) {
  if (root==NULL) return 0; //this behavior is undefined!

  //in-order travel
  int result = kthSmallestHelper_recursive(root->left, k);
  if (k==0) return result;

  k--;
  if (k==0) return root->val;


  return kthSmallestHelper_recursive(root->right, k);
}

int kthSmallestHelper_nonRecursive(TreeNode* root, int k){
  // in-order travel - non-recursive way
  stack<TreeNode*> s;

  while(!s.empty() || root){

    while (root) {
      s.push(root);
      root = root->left;
    }

    k--;
    root = s.top()->right;

    if (k==0) return s.top()->val;

    s.pop();
  }
  return -1;
}

int kthSmallest(TreeNode* root, int k) {
  // 230 : Kth Smallest Element in a BST             : 36.9% : Medium :ok
  /**********************************************************************************
   *
   * Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
   *
   * Note:
   * Follow up:
   * What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently?
   * How would you optimize the kthSmallest routine?
   *
   *   Try to utilize the property of a BST.
   *   What if you could modify the BST node's structure?
   *   The optimal runtime complexity is O(height of BST).
   *
   * Credits:Special thanks to @ts for adding this problem and creating all test cases.
   **********************************************************************************/
  return kthSmallestHelper_nonRecursive(root, k);
  return kthSmallestHelper_recursive(root, k);
}

// 275 : H-Index II                                : 32.4% : Medium :non

int isCompleteTree(TreeNode* root) {
  if (!root) return 0;

  int cnt = 1;
  TreeNode *left = root, *right = root;
  for(; left && right; left=left->left, right=right->right) {
    cnt *= 2;
  }

  if (left!=NULL || right!=NULL) {
    return -1;
  }
  return cnt-1;
}

int countNodes(TreeNode* root) {

  // 222 : Count Complete Tree Nodes                 : 24.7% : Medium
  /**********************************************************************************
   *
   * Given a complete binary tree, count the number of nodes.
   *
   * Definition of a complete binary tree from Wikipedia:
   * http://en.wikipedia.org/wiki/Binary_tree#Types_of_binary_trees
   *
   * In a complete binary tree every level, except possibly the last, is completely filled,
   * and all nodes in the last level are as far left as possible.
   * It can have between 1 and 2^h nodes inclusive at the last level h.
   *
   **********************************************************************************/
  int cnt = isCompleteTree(root);
  if (cnt != -1) return cnt;
  int leftCnt = countNodes(root->left);
  int rightCnt = countNodes(root->right);
  return leftCnt + rightCnt + 1;
}

// 167 : Two Sum II - Input array is sorted        : 47.6% : Medium
int findPeakElement(vector<int>& nums) {
  // 162 : Find Peak Element                         : 32.9% : Medium
  /*162. Find Peak Element My Submissions Question
    Total Accepted: 60459 Total Submissions: 183691 Difficulty: Medium
    A peak element is an element that is greater than its neighbors.

    Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.

    The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

    You may imagine that num[-1] = num[n] = -∞.

    For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
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

int search1( vector<int> &nums,int key) {
  int n = nums.size();
  if (n<=0) return -1;

  if (n==1){
    return (nums[0]==key) ? 0 : -1;
  }
  int low=0, high=n-1;
  while( low<=high ){

    if (nums[low] <= nums[high] && ( key < nums[low] || key > nums[high]) ) {
      return -1;
    }

    int mid = low + (high-low)/2;
    if ( nums[mid] == key ) return mid;

    //the target in non-rotated array
    if (nums[low] < nums[mid] && key >= nums[low] && key< nums[mid]){
      high = mid - 1;
      continue;
    }
    //the target in non-rotated array
    if (nums[mid] < nums[high] && key > nums[mid] && key <= nums[high] ){
      low = mid + 1;
      continue;
    }
    //the target in rotated array
    if (nums[low] > nums[mid] ){
      high = mid - 1;
      continue;
    }
    //the target in rotated array
    if (nums[mid] > nums[high] ){
      low = mid + 1;
      continue;
    }
  }
  return -1;
}

int search(vector<int>& nums, int target) {
  // 33  : Search in Rotated Sorted Array            : 30.1% : Hard
  /**********************************************************************************
   *
   * Suppose a sorted array is rotated at some pivot unknown to you beforehand.
   *
   * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
   *
   * You are given a target value to search. If found in the array return its index, otherwise return -1.
   *
   * You may assume no duplicate exists in the array.
   *
   **********************************************************************************/

  /*
   *    Using binary search idea,
   *    1) Spliting the array to two part, one part should be non-rotated, another one is rotated.
   *    2) Checking the "key" whether is possible in non-rotated sorted part.
   *        2.1) if it is, then go to the classcial binary searh.
   *        2.2) if it not, then keep spliting the rorated part.
   *
   */
  return search1(nums, target);
}

// 174 : Dungeon Game                              : 20.6% : Hard :non
// 154 : Find Minimum in Rotated Sorted Array II   : 34.1% : Hard

int findDuplicate(vector<int>& nums) {
  // 287 : Find the Duplicate Number                 : 38.2% : Hard :ok
  /***************************************************************************************
   *
   * Given an array nums containing n + 1 integers where each integer is between 1 and
   * n (inclusive), prove that at least one duplicate number must exist.
   * Assume that there is only one duplicate number, find the duplicate one.
   *
   * Note:
   * > You must not modify the array (assume the array is read only).
   * > You must use only constant, O(1) extra space.
   * > Your runtime complexity should be less than O(n2).
   * > There is only one duplicate number in the array, but it could be repeated more than
   *   once.
   *
   * Credits:
   * Special thanks to @jianchao.li.fighter for adding this problem and creating all test
   * cases.
   *
   ***************************************************************************************/
  /*
  // This problem can be transfromed to "Linked List Cycle" problem.
  // There are two pointers, one goes one step, another goes two steps.
  //
  // Refer to: https://en.wikipedia.org/wiki/Cycle_detection

*/

  if (nums.size() > 1)
  {
    int slow = nums[0];
    int fast = nums[nums[0]];
    while (slow != fast)
    {
      slow = nums[slow];
      fast = nums[nums[fast]];
    }

    fast = 0;
    while (fast != slow)
    {
      fast = nums[fast];
      slow = nums[slow];
    }
    return slow;
  }
  return -1;
}
// 4   : Median of Two Sorted Arrays               : 18.4% : Hard
// 302 : Smallest Rectangle Enclosing Black Pixels : 38.7% : Hard

