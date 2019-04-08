
#include "stdafx.h"
#include "sort.h"
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
typedef int uint32_t;
int maximumGap(vector<int> &num) {
  /**********************************************************************************
  *
  * Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
  *
  * Try to solve it in linear time/space.
  *
  * Return 0 if the array contains less than 2 elements.
  *
  * You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
  *
  * Credits:Special thanks to @porker2008 for adding this problem and creating all test cases.
  *
  **********************************************************************************/

  if (num.size() < 2) return 0;

  //find the max & min element
  int min = num[0], max = num[0];
  for (int i = 1; i<num.size(); i++){
    min = min > num[i] ? num[i] : min;
    max = max < num[i] ? num[i] : max;
  }

  //Divide the interval [min, max] into n "buckets" of equal size = (max -min)/n
  //for example, max = 15 , min = 0, size = 5, bucket_size = 15/5 + 1 = 4 ;
  int bucket_size = (max - min) / num.size() + 1;

  //For each of the remaining n-2 numbers, determin in which bucket it falls .
  //The number num[i] belongs to the kth bucket B[k] if and only if (num[i]-min)/m = k-1

  vector< vector<int> > buckets((max - min) / bucket_size + 1);
  //For each bucket B[k], compute its max & min among the numbers which falls in B[k].
  //if the bucket is empty, remain it nothing.
  //if the bucket has one number, make this number as both max & min 
  for (int i = 0; i<num.size(); i++){
    int idx = (num[i] - min) / bucket_size;
    // for ex : 8 - 0 / 4 = 2 ;
    // for ex : sec times, 9 - 0 / 4 = 2.x
    if (buckets[idx].empty()){
      buckets[idx].push_back(num[i]);
      buckets[idx].push_back(num[i]);
    }
    else{
      buckets[idx][0] = buckets[idx][0] > num[i] ? num[i] : buckets[idx][0];
      buckets[idx][1] = buckets[idx][1] < num[i] ? num[i] : buckets[idx][1];
    }
  }

  //calculate the max gap
  int maxGap = 0;
  int prev = 0;
  for (int i = 1; i < buckets.size(); i++) {
    if (buckets[i].empty()) continue;
    int gap = buckets[i][0] - buckets[prev][1];
    // next bucket's max minus curr bucket's min = maxGap
    maxGap = maxGap > gap ? maxGap : gap;
    prev = i;
  }
  return maxGap;
}
bool compare(const Interval& lhs, const Interval& rhs){
  return (lhs.start == rhs.start) ? lhs.end < rhs.end : lhs.start < rhs.start;
}
vector<Interval> merge(vector<Interval> &intervals) {
  /**********************************************************************************
  *
  * Given a collection of intervals, merge all overlapping intervals.
  *
  * For example,
  * Given [1,3],[2,6],[8,10],[15,18],
  * return [1,6],[8,10],[15,18].
  *
  *
  **********************************************************************************/

  vector<Interval> result;

  if (intervals.size() <= 0) return result;
  //sort the inervals. Note: using the customized comparing function.
  sort(intervals.begin(), intervals.end(), compare);
  for (int i = 0; i<intervals.size(); i++) {
    int size = result.size();
    // if the current intervals[i] is overlapped with previous interval.
    // merge them together
    if (size>0 && result[size - 1].end >= intervals[i].start) {
      result[size - 1].end = max(result[size - 1].end, intervals[i].end);
    }
    else{
      result.push_back(intervals[i]);
    }
  }

  return result;
}


vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
  /**********************************************************************************
  *
  * Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
  *
  * You may assume that the intervals were initially sorted according to their start times.
  *
  * Example 1:
  * Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
  *
  * Example 2:
  * Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].
  *
  * This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
  *
  *
  **********************************************************************************/

  //just reuse the solution of "Merge Intervals", quite straight forward

  intervals.push_back(newInterval);

  return merge(intervals);
}

static bool comp(string& s1, string& s2) { return s1 + s2 > s2 + s1; }

string largestNumber(vector<int> &num) {
  /**********************************************************************************
  *
  * Given a list of non negative integers, arrange them such that they form the largest number.
  *
  * For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
  *
  * Note: The result may be very large, so you need to return a string instead of an integer.
  *
  * Credits:Special thanks to @ts for adding this problem and creating all test cases.
  *
  **********************************************************************************/

  //convert int to string
  vector<string> v;
  for (int i = 0; i<num.size(); i++)
    v.push_back(to_string(num[i]));

  //sort the string
  sort(v.begin(), v.end(), comp);

  //generate the result
  string result;
  for (int i = 0; i<v.size(); i++){
    result += v[i];
  }

  //special case: start with zero (e.g. [0, 0])
  if (result[0] == '0') return "0";

  return result;
}

bool isPowerOfTwo01(int n) {
  // count the number fo bits 1, if it only has one, then return true
  /**********************************************************************************
  *
  * Given an integer, write a function to determine if it is a power of two.
  *
  * Credits:Special thanks to @jianchao.li.fighter for adding this problem and creating
  * all test cases.
  *
  *
  *
  **********************************************************************************/
  int cnt = 0; //num of bits 1
  for (; n>0; n >>= 1){
    if (n & 1) {
      cnt++;
      if (cnt>1) return false;
    }
  }
  return cnt == 1;
}

//we notice: 2^n - 1 always be 1111111...
//so, (2^n) & (2^n-1) always be zero
bool isPowerOfTwo02(int n) {
  return n <= 0 ? false : (n & (n - 1)) == 0;
}

uint32_t reverseBits(uint32_t n) {
  /**********************************************************************************
  *
  * Reverse bits of a given 32 bits unsigned integer.
  *
  * For example, given input 43261596 (represented in binary as 00000010100101000001111010011100),
  * return 964176192 (represented in binary as 00111001011110000010100101000000).
  *
  * Follow up:
  * If this function is called many times, how would you optimize it?
  *
  * Related problem: Reverse Integer
  *
  * Credits:Special thanks to @ts for adding this problem and creating all test cases.
  *
  **********************************************************************************/
  uint32_t ret = 0;
  for (int i = 0; i<32; i++) {
    ret = (ret * 2) + (n & 0x1);
    n /= 2;
  }
  return ret;
}

int maxProduct(vector<string>& words) {
  /*
  318. Maximum Product of Word Lengths My Submissions Question
  Total Accepted: 9052 Total Submissions: 23338 Difficulty: Medium
  Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. You may assume that each word will contain only lower case letters. If no such two words exist, return 0.

  Example 1:
  Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
  Return 16
  The two words can be "abcw", "xtfn".

  Example 2:
  Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
  Return 4
  The two words can be "ab", "cd".

  Example 3:
  Given ["a", "aa", "aaa", "aaaa"]
  Return 0
  No such pair of words.
  */

  vector<int> mask(words.size());
  int result = 0;
  for (int i = 0; i<words.size(); ++i) {
    for (char c : words[i])
      mask[i] |= 1 << (c - 'a');
    for (int j = 0; j<i; ++j)
    if (!(mask[i] & mask[j]))
      result = max(result, int(words[i].size() * words[j].size()));
  }
  return result;
}






