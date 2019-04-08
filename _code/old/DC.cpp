#include "stdafx.h"
#include "DC.h"
#include "string"
#include<algorithm>
#include<vector>
#include<map>
#include<ctime>
#include<iostream>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include <sstream>
#include<stack>

//#include<numeric>
#define GUARD -10000

using namespace std;


//a bit optimization for methed 2 - the run time is 300ms
bool searchMatrix021(vector<vector<int>>& matrix, int target) {

  /**********************************************************************************
  *
  * Write an efficient algorithm that searches for a value in an m x n matrix. This
  * matrix has the following properties:
  *
  * Integers in each row are sorted in ascending from left to right.
  * Integers in each column are sorted in ascending from top to bottom.
  *
  * For example,
  *
  * Consider the following matrix:
  *
  * [
  *   [1,   4,  7, 11, 15],
  *   [2,   5,  8, 12, 19],
  *   [3,   6,  9, 16, 22],
  *   [10, 13, 14, 17, 24],
  *   [18, 21, 23, 26, 30]
  * ]
  *
  * Given target = 5, return true.
  * Given target = 20, return false.
  *
  *
  *
  *
  **********************************************************************************/

  if (matrix.size() == 0 || matrix[0].size() == 0) return false;
  int row = 0, col = matrix[0].size() - 1;
  while (row < matrix.size() && col >= 0) {
    if (target == matrix[row][col]) return true;
    while (col >= 0 && target < matrix[row][col]) {
      col--;
    }
    while (row < matrix.size() && target > matrix[row][col]){
      row++;
    }

  }
  return false;
}

bool isOperator(char ch){
  return (ch == '+' || ch == '-' || ch == '*');
}

vector<int> diffWaysToCompute(string input) {
  /**********************************************************************************
  *
  * Given a string of numbers and operators, return all possible results from computing
  * all the different possible ways to group numbers and operators. The valid operators
  * are +, - and *.
  *
  * Example 1
  * Input: "2-1-1".
  * ((2-1)-1) = 0
  * (2-(1-1)) = 2
  * Output: [0, 2]
  *
  * Example 2
  * Input: "2*3-4*5"
  * (2*(3-(4*5))) = -34
  * ((2*3)-(4*5)) = -14
  * ((2*(3-4))*5) = -10
  * (2*((3-4)*5)) = -10
  * (((2*3)-4)*5) = 10
  * Output: [-34, -14, -10, -10, 10]
  *
  * Credits:Special thanks to @mithmatt for adding this problem and creating all test
  * cases.
  *
  **********************************************************************************/
  //if the result has been cacluated, then just get it from the cache and return
  static map< string, vector<int> > cache;
  if (cache.find(input) != cache.end()){
    return cache[input];
  }


  vector<int> result;
  for (int i = 0; i<input.size(); i++){
    char ch = input[i];
    if (isOperator(ch)){
      //split the input to two parts, left part and right part
      //And recursively invoke this function.
      string left = input.substr(0, i);
      string right = input.substr(i + 1);
      vector<int> lv = diffWaysToCompute(left);
      vector<int> rv = diffWaysToCompute(right);

      //merge two result to one
      for (int li = 0; li<lv.size(); li++) {
        for (int ri = 0; ri<rv.size(); ri++) {
          switch (ch){
          case '+': result.push_back(lv[li] + rv[ri]); break;
          case '-': result.push_back(lv[li] - rv[ri]); break;
          case '*': result.push_back(lv[li] * rv[ri]); break;
          }
        }
      }

    }
  }
  //if we cannot find the "operator" in input,
  //which means, it is a number, just put the number into the result.
  if (result.size() == 0) {
    result.push_back(atoi(input.c_str()));
  }

  //cache the result, key = input, value = result;
  cache[input] = result;

  return result;
}


//qsort partition
int partition(vector<int>& nums, int left, int right) {
  // before : [3, 2, 1, 5, 4, 6]
  // after : [5, 6, 4, 3, 1, 2]
  int pivot = nums[left];
  int l = left + 1, r = right;
  while (l <= r) {
    if (nums[l] < pivot && nums[r] > pivot){
      swap(nums[l], nums[r]);
      l++;
      r--;
    }
    if (nums[l] >= pivot) l++;
    if (nums[r] <= pivot) r--;
  }
  swap(nums[left], nums[r]);
  return r;
}

int findKthLargest_qsort(vector<int>& nums, int k) {
  //https://leetcode.com/discuss/38336/solutions-partition-priority_queue-multiset-respectively

  /**********************************************************************************
  *
  * Find the kth largest element in an unsorted array.
  * Note that it is the kth largest element in the sorted order, not the kth distinct element.
  *
  * For example,
  * Given [3,2,1,5,6,4] and k = 2, return 5.
  *
  *
  **********************************************************************************/
  /*
  Quicksort
  In quicksort, in each iteration, we need to select a pivot and then partition the array
  into three parts:

  Elements smaller than the pivot; Elements equal to the pivot; Elements larger than the
  pivot. Now, let's do an example with the array [3, 2, 1, 5, 4, 6] in the problem
  statement. Let's assume in each time we select the leftmost element to be the pivot, in
  this case, 3. We then use it to partition the array into the above 3 parts, which results
  in [1, 2, 3, 5, 4, 6]. Now 3 is in the third position and we know that it is the third
  smallest element. Now, do you recognize that this subroutine can be used to solve this
  problem?

  In fact, the above partition puts elements smaller than the pivot before the pivot and
  thus the pivot will then be the k-th smallest element if it is at the k-1-th position.
  Since the problem requires us to find the k-th largest element, we can simply modify the
  partition to put elements larger than the pivot before the pivot. That is, after
  partition, the array becomes [5, 6, 4, 3, 1, 2]. Now we know that 3 is the 4-th largest
  element. If we are asked to find the 2-th largest element, then we know it is left to 3.
  If we are asked to find the 5-th largest element, then we know it is right to 3. So, in
  the average sense, the problem is reduced to approximately half of its original size,
  giving the recursion T(n) = T(n/2) + O(n) in which O(n) is the time for partition. This
  recursion, once solved, gives T(n) = O(n) and thus we have a linear time solution. Note
  that since we only need to consider one half of the array, the time complexity is O(n).
  If we need to consider both the two halves of the array, like quicksort, then the
  recursion will be T(n) = 2T(n/2) + O(n) and the complexity will be O(nlogn).

  Of course, O(n) is the average time complexity. In the worst case, the recursion may
  become T(n) = T(n - 1) + O(n) and the complexity will be O(n^2).

  Now let's briefly write down the algorithm before writing our codes.

  Initialize left to be 0 and right to be nums.size() - 1; Partition the array, if the
  pivot is at the k-1-th position, return it (we are done); If the pivot is right to the
  k-1-th position, update right to be the left neighbor of the pivot; Else update left to
  be the right neighbor of the pivot. Repeat 2. Now let's turn it into code.
  */

  int left = 0, right = nums.size() - 1;
  while (true) {
    int pos = partition(nums, left, right);
    if (pos == k - 1){
      return nums[pos];
    }
    if (pos > k - 1) {
      // if we want to find 3-largest element, but pos is 5
      // it means we have to find the first-half and find the 3-largest
      right = pos - 1;
    }
    else{
      // if we want to find 5-largest element, but pos is 2
      // then, start from pos + 1, and do partition to the second-half
      left = pos + 1;
    }
  }
}


int maxCoins_DC(vector<int>& nums, vector<vector<int>>& matrix, int low, int high) {

  /*
  Divide and Conquer

  If we seprate the array to two part, left part and right part.

  Then, we will find in this problem the left and right become adjacent
  and have effects on the maxCoins in the future.

  So, if we think reversely, if the balloon i is the last balloon of all to burst,
  the left and right section now has well defined boundary and do not affect each other!
  Therefore we can do either recursive method with memoization
  */

  if (low + 1 == high) return 0;
  if (matrix[low][high] > 0) return matrix[low][high];
  int result = 0;
  for (int i = low + 1; i < high; ++i){
    result = max(result, nums[low] * nums[i] * nums[high]
      + maxCoins_DC(nums, matrix, low, i)
      + maxCoins_DC(nums, matrix, i, high));
  }
  matrix[low][high] = result;
  return result;
}

int maxCoins(vector<int>& nums) {
  /*
  312. Burst Balloons My Submissions Question
  */

  //remove all of zero item
  nums.erase(remove_if(nums.begin(), nums.end(), [](int n){return n == 0; }), nums.end());

  //add 1 for head and tail
  nums.insert(nums.begin(), 1);
  nums.push_back(1);

  int n = nums.size();
  vector< vector<int> > matrix(n, vector<int>(n, 0));

  return maxCoins_DC(nums, matrix, 0, n - 1);
}



