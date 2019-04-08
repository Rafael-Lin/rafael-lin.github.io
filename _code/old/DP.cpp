
#include "stdafx.h"
#include "DP.h"
#include "type.h"
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

using namespace std;
//Time too long
DP::DP(){

}
int climbStairs(int n) {
  /**********************************************************************************
   *
   * You are climbing a stair case. It takes n steps to reach to the top.
   *
   * Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
   *
   *
   **********************************************************************************/
  /*This problem is a Fibonacci problem. F(n)=F(n-1)+F(n-2); Solving this
   * problem by recursion ,we will do a lot of same recursion. Example:
   * F(10)=F(9)+F(8); F(9)=F(8)+F(7); we calculate F(8) twice,when n is
   * large,this will increase as a rate of n's exponent.

   So a more efficient way to solve this problem is from Bottom to Top. Calculate
   F(0) ,F(1); then F(2).........
   */

  int StepOne = 1;
  int StepTwo = 0;
  int ret = 0;
  for(int i=0;i<n;i++)
  {
    ret = StepOne + StepTwo;
    StepTwo = StepOne;
    StepOne = ret;
  }
  return ret;
}

int numTrees1(int n) {

  /**********************************************************************************
   *
   * Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
   *
   * For example,
   * Given n = 3, there are a total of 5 unique BST's.
   *
   *    1         3     3      2      1
   *     \       /     /      / \      \
   *      3     2     1      1   3      2
   *
   *
   **********************************************************************************/

  /* take n = 3 for example
   * root = 1 : left : null , right could be 2 or 3 => f(0) * f(2);
   * root = 2 : left : 1, right : 3 => f(1) * f(1)
   * root = 3 : left : 2 or 1, right : null => f(1) * f(1);
   * so conclude the formula
   * f(0) = 1
   * f(n) = f(0)*f(n-1) + f(1)*f(n-2) + ... + f(n-2)*f(1) + f(n-1)*f(0)
   */
  vector<int> numBST(n+1,0);
  numBST[0] = 1;

  for(int i=1; i<=n; i++) {
    for(int j=0; j<i; j++) {
      numBST[i] += numBST[j]*numBST[i-1-j];
    }
  }
  return numBST[n];
}

vector<TreeNode*> generateTrees(int low, int high){
  vector<TreeNode*> v;
  if (low > high || low<=0 || high<=0){
    v.push_back(NULL);
    return v;
  }
  if (low==high){
    TreeNode* node = new TreeNode(low);
    v.push_back(node);
    return v;
  }
  for (int i=low; i <= high; i++){
    vector<TreeNode*> vleft = generateTrees(low, i-1);
    vector<TreeNode*> vright = generateTrees(i+1, high);
    for (int l=0; l<vleft.size(); l++){
      for (int r=0; r<vright.size(); r++){
        TreeNode *root = new TreeNode(i);
        root->left = vleft[l];
        root->right = vright[r];
        v.push_back(root);
      }
    }
  }
  return v;
}

vector<TreeNode*> generateTrees(int n) {

  /*****
    Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

    For example,
    Given n = 3, your program should return all 5 unique BST's shown below.

    1         3     3      2      1
    \       /     /      / \      \
    3     2     1      1   3      2
    /     /       \                 \
    2     1         2                 3
    confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.

    Subscribe to see which companies asked this question
    */

  vector<TreeNode*> v;
  if( n == 0 ) return v ;
  v = generateTrees(1, n);
  return v;
}
int maxProfit(vector<int>& prices) {
  /*
     309. Best Time to Buy and Sell Stock with Cooldown My Submissions Question
     Total Accepted: 8554 Total Submissions: 24069 Difficulty: Medium
     Say you have an array for which the ith element is the price of a given stock on day i.

     Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:

     You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
     After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
Example:

prices = [1, 2, 3, 0, 2]
maxProfit = 3
transactions = [buy, sell, cooldown, buy, sell]
Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.

Subscribe to see which companies asked this question
*/


  /*
     buy[i] : at day i, the last opeartion is buy, and the max profit at that time
     sell[i] : at day i, the last opeartion is sell, and the max profit at that time
     rest[i] : at day i, the last opeartion is rest, and the max profit at that time
formula :

buy[i] = max(rest[i- 1 ] - price, buy[i- 1 ])
sell[i] = max(buy[i- 1 ] + price, sell[i- 1 ])
rest[i] = max(sell[i- 1 ], buy[i- 1 ], rest[i- 1 ])

becase of cooldown : we could induce that rest[i] = sell[i-1] -> simplify the formula into

buy[i] = max(sell[i- 1 ] - price, buy[i- 1 ])
sell[i] = max(buy[i- 1 ] + price, sell[i- 1 ])
*/
  int buy = INT_MIN, pre_buy = 0, sell = 0, pre_sell = 0;
  for (int price : prices) {
    pre_buy = buy;
    buy = max(pre_sell - price, pre_buy);
    pre_sell = sell;
    sell = max(pre_buy + price, pre_sell);
  }
  return sell;

}

int rob1(vector<int> &money) {
  /*
   * Dynamic Programming
   *
   * We can easy find the recurive fomular:
   *
   *     dp[n] = max(
   *                    dp[n-1],   // the previous house has been robbed.
   *                    dp[n-2] + money[n]  // the previous house has NOT been robbed.
   *                )
   *
   * The initalization is obvious:
   *     dp[1] = money[1]
   *     dp[2] = max(money[1], money[2])
   *
   */

  int n = money.size();
  if (n==0) return 0;

  vector<int> dp(n, 0);
  if (n>=1) dp[0] = money[0];
  if (n>=2) dp[1] = max(money[0], money[1]);

  for (int i=2; i<n; i++){
    dp[i] = max(dp[i-1], dp[i-2] + money[i]);
  }
  return dp[n-1];
}

int rob2(vector<int> &money) {
  /*
   * Acutally, we no need to allocate an additional array for DP.
   * we can only use several variables to record previous steps
   */
  int n2=0; // dp[i-2];
  int n1=0; // dp[i-1];

  for (int i=0; i<money.size(); i++){
    int current = max(n1, n2 + money[i]);
    n2 = n1;
    n1 = current;
  }
  return n1;
}

int rob(vector<int> &num) {
  /**********************************************************************************
   *
   * You are a professional robber planning to rob houses along a street. Each house has
   * a certain amount of money stashed, the only constraint stopping you from robbing
   * each of them is that adjacent houses have security system connected and it will
   * automatically contact the police if two adjacent houses were broken into on the same night.
   *
   * Given a list of non-negative integers representing the amount of money of each house,
   * determine the maximum amount of money you can rob tonight without alerting the police.
   *
   *
   **********************************************************************************/
  if (rand()%2)
    return rob1(num);
  return rob2(num);
}

class NumArray {
  private:
    int size;
    vector <long long> sums;
  public:
    NumArray(vector<int> &nums): size(nums.size()), sums(size+1, 0) {
      for(int i=0; i<size; i++) {
        sums[i+1] = sums[i] + nums[i];
      }
    }
    int sumRange(int i, int j) {
      /***************************************************************************************
       *
       * Given an integer array nums, find the sum of the elements between indices i and j
       * (i ≤ j), inclusive.
       *
       * Example:
       * Given nums = [-2, 0, 3, -5, 2, -1]
       *
       * sumRange(0, 2) -> 1
       * sumRange(2, 5) -> -1
       * sumRange(0, 5) -> -3
       * Note:
       * You may assume that the array does not change.
       * There are many calls to sumRange function.
       *
       ***************************************************************************************/

      /*
       * Solution
       * =========
       *
       * The sum of all the elements starting from position 0 to position i is stored in
       * sums[i]. This way we can reconstruct the sum from position i to position j by
       * subtracting sums[i - 1] from sums[j], leaving us with the sum of the desired elements.
       *
       * Note: we can add a dummy sum at then beginning to simplify the code
       *
       */
      return sums[j+1] - sums[i];
    }
};

vector <int> longest_LIS;
int DP::lengthOfLIS(vector<int>& nums) {
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
      /* for( int i = 0 ; i < longest_LIS.size() ; i ++ ) */
      /*   printf( "%d ", longest_LIS[i] ) ; */
      /* printf( "\n" ) ; */
    }
  }
  return answer;
}

int orginal_rob(vector<int> &money, int start, int end) {
  int n2=0;
  int n1=0;

  for (int i=start; i<end; i++){
    int current = max(n1, n2 + money[i]);
    n2 = n1;
    n1 = current;
  }
  return n1;
}

int robCircle(vector<int>& nums) {
  /**********************************************************************************
   *
   * Note: This is an extension of House Robber.
   *
   * After robbing those houses on that street, the thief has found himself a new place
   * for his thievery so that he will not get too much attention. This time, all houses
   * at this place are arranged in a circle. That means the first house is the neighbor
   * of the last one. Meanwhile, the security system for these houses remain the same as
   * for those in the previous street.
   *
   * Given a list of non-negative integers representing the amount of money of each house,
   * determine the maximum amount of money you can rob tonight without alerting the police.
   *
   * Credits:Special thanks to @Freezen for adding this problem and creating all test cases.
   *
   **********************************************************************************/
  int n = nums.size();
  switch (n) {
    case 0:
      return 0;
    case 1:
      return nums[0];
    case 2:
      return max(nums[0], nums[1]);
    default:
      /*
       * the idea is we cannot rob[0] and rob[n-1] at same time
       * so, we rob [0 .. n-2] or [1 .. n-1], can return the maxinum one.
       */
      int m1 = orginal_rob(nums, 0, n-1);
      int m2 = orginal_rob(nums, 1, n);

      return max(m1, m2);
  }
}

int coinChange(vector<int>& coins, int amount) {

/***************************************************************************************
 *
 * You are given coins of different denominations and a total amount of money amount.
 * Write a function to compute the fewest number of coins that you need to make up that
 * amount. If that amount of money cannot be made up by any combination of the coins,
 * return -1.
 *
 * Example 1:
 * coins = [1, 2, 5], amount = 11
 * return 3 (11 = 5 + 5 + 1)
 *
 * Example 2:
 * coins = [2], amount = 3
 * return -1.
 *
 * Note:
 * You may assume that you have an infinite number of each kind of coin.
 *
 * Credits:
 * Special thanks to @jianchao.li.fighter for adding this problem and creating all test
 * cases.
 *
 ***************************************************************************************/

 /*
 * Solution 1 - O(N * amount)
 * =========
 *
 * This problem can be solved using dynamic programming, thus building the optimal
 * solution from previous smaller ones. For every coin of value t and every sum of money
 * i the sum can be traced back to a previous sum i - t that was already computed and uses
 * the smallest number of coins possible. This way we can construct every sum i as the
 * minimum of all these previous sums for every coin value. To be sure we'll find a minimum
 * we can populate the solution vector with an amount bigger than the maximum possible,
 * which is amount + 1(when the sum is made up of only coins of value 1). The only exception
 * is sol[0] which is 0 as we need 0 coins to have a sum of 0. In the end we need to look
 * if the program found a solution in sol[amount] or it remained the same, in which case we
 * can return -1.
 *
 */

  const int INF = 0x7ffffffe;
  vector<int> dp(amount + 1, INF);
  dp[0] = 0;
  for (int i = 0; i <= amount; i++) {
    for (int j = 0; j<coins.size(); j++) {
      if (i + coins[j] <= amount && dp[i + coins[j]] > dp[i] + 1)
        dp[i + coins[j]] =dp[i] + 1;
    }
  }
  return dp[amount] == INF ? -1 : dp[amount];
}
