/*Rotate an array of n elements to the right by k steps.

  For example, with n = 7 and k = 3, the array[1, 2, 3, 4, 5, 6, 7] is rotated to[5, 6, 7, 1, 2, 3, 4].

Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
*/
#include<vector>
#include"stdafx.h"
#include<string>
using std::vector;
using std::string;

static class Solution1
{
public:

  Solution1();
  static void rotate(int nums[], int n, int k);
  static void rotateNtimes(int nums[], int n, int k);
  static void rotateReverse(int nums[], int n, int k);
  static void rotateSwap(int nums[], int n, int k);
  static int removeElement(vector<int>& nums, int val);
  static int removeDuplicates(vector<int>& nums);
  static vector<string> summaryRanges(vector<int>& nums);
  static vector<string> summaryRangesAns(vector<int>& nums);
  static void printVector(vector<int> nums);
  static void moveZeroesAns(vector<int>& nums);
  static void merge(vector<int>& nums1, int m, vector<int>& nums2, int n);
  static int majorityElement(vector<int>& nums);
  static int majorityElementHashTable(vector<int>& nums);
  static int majorityElementSorting(vector<int>& nums);
  static int majorityElementRandom(vector<int>& nums);
  static bool containsDuplicate(vector<int>& nums);
  static vector<int> plusOne(vector<int>& digits);
  static vector<int> getRow(int rowIndex);
  static vector<vector<int>> generate(int numRows);

  static bool containsNearbyDuplicateUnorderSet(vector<int>& nums, int k);
  static bool containsNearbyDuplicate(vector<int>& nums, int k);

  static int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid);
  static int uniquePathsWithObstaclesAns(vector<vector<int> > &obstacleGrid);

  static int uniquePaths(int m, int n);
  static int SetExample();

  static int minSubArrayLen(int s, vector<int>& nums);
  static int minSubArrayLenAns2(int s, vector<int>& nums);

  static int searchInsert(vector<int>& nums, int target);
  static int searchInsertBinarySearch(vector<int>& nums, int target);

  static vector<int> searchRange(vector<int>& nums, int target);
  static vector<int> searchRangeAns1(vector<int>& nums, int target);
  static vector<int> searchRangeLib(vector<int>& nums, int target);
  static vector<vector<int>> threeSum(vector<int>& nums);

  static void setZeroes(vector<vector<int>>& matrix);
  static int maxProfit(vector<int>& prices);

  static bool searchMatrix(vector<vector<int>>& matrix, int target);

  static int minPathSum(vector<vector<int>>& grid);

  static int missingNumberXOR(vector<int>& nums);
  static int missingNumberSUM(vector<int>& nums);
  static int missingNumberBinarySearch(vector<int>& nums);

  static vector<vector<int>> combinationSum(vector<int>& candidates, int target);
  static void bt(vector<int> candidiate, vector<vector<int>> & retV, int index, vector<int> &candV, int target);

  static vector<vector<int>> combinationSum2(vector<int>& candidates, int target);
  static void bt2(vector<int> candidiate, vector<vector<int>> & retV, int index, vector<int> &candV, int target);

  static vector<vector<int>> combinationSum3(int k, int n);
  static void bt3(vector<int> candidiate, vector<vector<int>> & retV, int index, vector<int> &candV, int totalnum, int targetSum);
  static vector<int> productExceptSelf(vector<int>& nums);

  static bool ExistDFS(vector<vector<char>>& board, int row, int col, const string &word, int start, int M, int N, int sLen);
  static bool exist(vector<vector<char>>& board, string word);

  static bool canJump(vector<int>& nums);

  static int minimumTotal(vector<vector<int>>& triangle);

  static void nextPermutation(vector<int>& nums);

  static int threeSumClosest(vector<int>& nums, int target);

  static vector<vector<int>> fourSum(vector<int>& nums, int target);

  static int ptrExample();

  static vector<int> twoSum(vector<int>& nums, int target);

  static int maxSubArray(vector<int>& nums);

  static int maxProduct(vector<int>& nums);

  static vector<vector<int>> subsets(vector<int>& nums);

  static vector<vector<int>> subsetsBT(vector<int>& nums);

  static void genSubsetsBT(vector<int>& nums, int start, vector<int>& sub, vector<vector<int>>& subs);

  static vector<vector<int>> subsetsIterative(vector<int>& nums);

  static vector<vector<int>> subsetsWithDup(vector<int>& nums);

  static void subsetsWithDupBT(std::vector<std::vector<int> > &res, std::vector<int> &nums, std::vector<int> &vec, int begin);

  static vector<int> majorityElementTwo(vector<int>& nums);

  static int findPeakElement(vector<int>& nums);

  static int findMin(vector<int>& nums);

  static bool searchDup(vector<int>& nums, int target);

  static int removeDuplicatesTwo(vector<int>& nums);

  static void printVector(vector<int> nums, int watch);

  static int removeDuplicatesTwoSec(vector<int>& nums);

  static void sortColorsOnePass(vector<int>& nums);

  static void sortColorsTwoPass(vector<int>& nums);

  static void sortColorsBucket(vector<int>& nums);

  static void gameOfLife(vector<vector<int>>& board);

  static vector<int> spiralOrder(vector<vector<int>>& matrix);

  static vector<vector<int>> Solution1::generateMatrix(int n);

  static int maxProfitSec(vector<int>& prices);

  static int jump(vector<int>& nums);

  static int firstMissingPositive(vector<int>& nums);

  static int longestConsecutive(vector<int>& nums);



};
