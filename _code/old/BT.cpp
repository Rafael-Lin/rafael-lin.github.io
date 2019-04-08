
#include "stdafx.h"
#include "BT.h"
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

vector<vector<int>> BT::combine(int n, int k) {

/*
77. Combinations My Submissions Question
Total Accepted: 64875 Total Submissions: 196958 Difficulty: Medium
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
[2,4],
[3,4],
[2,3],
[1,2],
[1,3],
[1,4],
]
*/

  vector<vector<int> >res;
  if (n<k)return res;
  vector<int> temp(0, k);
  combine(res, temp, 0, 0, n, k);
  return res;
}

void BT::combine(vector<vector<int> > &res, vector<int> &temp, int start, int num, int n, int k)
{
  if (num == k){
    res.push_back(temp);
    return;
  }
  for (int i = start; i<n; i++){
    temp.push_back(i + 1);
    combine(res, temp, i + 1, num + 1, n, k);
    temp.pop_back();
  }
}

vector<vector<int> > BT::permute(vector<int> &num) {
  /*
  46. Permutations My Submissions Question
  Total Accepted: 83940 Total Submissions: 244960 Difficulty: Medium
  Given a collection of distinct numbers, return all possible permutations.

  For example,
  [1,2,3] have the following permutations:
  [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].

  Subscribe to see which companies asked this question
  */
  vector<vector<int> > result;
  permuteRecursive(num, 0, result);
  return result;
}
void BT::permuteRecursive(vector<int> &num, int begin, vector<vector<int> > &result)    {
// permute num[begin..end]
// invariant: num[0..begin-1] have been fixed/permuted
  if (begin >= num.size()) {
    // one permutation instance
    result.push_back(num);
    return;
  }

  for (int i = begin; i < num.size(); i++) {
    swap(num[begin], num[i]);
    permuteRecursive(num, begin + 1, result);
    // reset
    swap(num[begin], num[i]);
  }
}


vector<vector<int> > permuteReOrder(vector<int> &num) {
  /*
  *    The algroithm - Take each element in array to the first place.
  *
  *    For example:
  *
  *         0) initalization
  *
  *             pos = 0
  *             [1, 2, 3]
  *
  *         1) take each element into the first place,
  *
  *             pos = 1
  *             [1, 2, 3]  ==>  [2, 1, 3] , [3, 1, 2]
  *
  *             then we have total 3 answers
  *             [1, 2, 3],  [2, 1, 3] , [3, 1, 2]
  *
  *         2) take each element into the "first place" -- pos
  *
  *             pos = 2
  *             [1, 2, 3]  ==>  [1, 3, 2]
  *             [2, 1, 3]  ==>  [2, 3, 1]
  *             [3, 1, 2]  ==>  [3, 2, 1]
  *
  *             then we have total 6 answers
  *             [1, 2, 3],  [2, 1, 3] , [3, 1, 2], [1, 3, 2], [2, 3, 1], [3, 2, 1]
  *
  *          3) pos = 3 which greater than length of array, return.
  *
  */

  /*
  { 1 2 3 }
  { 2 1 3 }
  { 3 2 1 }
  { 1 3 2 }
  { 2 3 1 }
  { 3 1 2 }
  */
  vector<vector<int> > vv;
  vv.push_back(num);

  if (num.size() <2){
    return vv;
  }
  int pos = 0;
  while (pos<num.size() - 1){
    int size = vv.size();
    for (int i = 0; i<size; i++){
      //take each number to the first place
      for (int j = pos + 1; j<vv[i].size(); j++) {
        vector<int> v = vv[i];
        swap(v[pos], v[j]);
        vv.push_back(v);
      }
    }
    pos++;
  }
  return vv;
}

vector<vector<int> > permuteInsert(vector<int> &num) {

/*
[1]
[2, 1], [1, 2]
[3, 2, 1], [2, 3, 1], [2, 1, 3], [3, 1, 2], [1, 3, 2], [1, 2, 3]
*/
  vector<vector<int>> allPer;
  if (num.empty()) return allPer;
  allPer.push_back(vector<int>(1, num[0]));

  for (int i = 1; i<num.size(); i++) {
    int n = allPer.size();
    for (int j = 0; j<n; j++) {
      for (int k = 0; k<allPer[j].size(); k++) {
        vector<int> per = allPer[j];
        per.insert(per.begin() + k, num[i]);
        allPer.push_back(per);
      }
      allPer[j].push_back(num[i]);
    }
  }
  return allPer;
}

void findPermutations(vector<int> &num, vector<bool> &used, vector<int> &per, vector<vector<int>> &allPer) {
  if (per.size() == num.size()) {
    allPer.push_back(per);
    return;
  }

  for (int i = 0; i<num.size(); i++) {
    if (used[i]) continue;
    used[i] = true;
    per.push_back(num[i]);
    findPermutations(num, used, per, allPer);
    used[i] = false;
    per.pop_back();
  }
}


vector<vector<int> > permute(vector<int> &num) {
  //http://bangbingsyb.blogspot.tw/2014/11/leetcode-permutations-i-ii.html
  vector<vector<int>> allPer;
  if (num.empty()) return allPer;
  vector<bool> used(num.size(), false);
  vector<int> per;
  findPermutations(num, used, per, allPer);
  return allPer;
}

void findPerUniq(vector<int> &num, vector<bool> &used, vector<int> &per, vector<vector<int>> &allPer) {
  if (per.size() == num.size()) {
    allPer.push_back(per);
    return;
  }

  for (int i = 0; i<num.size(); i++) {
    if (used[i]) continue;
    if (i>0 && num[i] == num[i - 1] && !used[i - 1]) continue;
    used[i] = true;
    per.push_back(num[i]);
    findPerUniq(num, used, per, allPer);
    per.pop_back();
    used[i] = false;
  }
}


vector<vector<int> > permuteUnique(vector<int> &num) {
  vector<vector<int>> allPer;
  if (num.empty()) return allPer;
  sort(num.begin(), num.end());
  vector<int> per;
  vector<bool> used(num.size(), false);
  findPerUniq(num, used, per, allPer);
  return allPer;
}

vector<vector<int> > permuteUniqReorder(vector<int> &num) {
  // To deal with the duplication number, we need do those modifications:
  //    1) sort the array [pos..n].
  //    2) skip the same number.

  vector<vector<int> > vv;
  vv.push_back(num);

  if (num.size() <2){
    return vv;
  }
  int pos = 0;
  while (pos<num.size() - 1){
    int size = vv.size();
    for (int i = 0; i<size; i++){
      //sort the array, so that the same number will be together
      sort(vv[i].begin() + pos, vv[i].end());
      //take each number to the first
      for (int j = pos + 1; j<vv[i].size(); j++) {
        vector<int> v = vv[i];
        //skip the same number
        if (j>0 && v[j] == v[j - 1]){
          continue;
        }
        swap(v[j], v[pos]);
        vv.push_back(v);
      }
    }
    pos++;
  }
  return vv;
}

void addingpar(vector<string> &v, string str, int n, int m){
  if (n == 0 && m == 0) {
    v.push_back(str);
    return;
  }
  if (m > 0){ addingpar(v, str + ")", n, m - 1); }
  if (n > 0){ addingpar(v, str + "(", n - 1, m + 1); }
}


vector<string> generateParenthesis(int n) {
  /*
  22. Generate Parentheses My Submissions Question
  Total Accepted: 74511 Total Submissions: 211758 Difficulty: Medium
  Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

  For example, given n = 3, a solution set is:

  "((()))", "(()())", "(())()", "()(())", "()()()"
  */
  vector<string> res;
  addingpar(res, "", n, 0);
  return res;
}

vector<int> grayCode(int n) {
  /*
  89. Gray Code My Submissions Question
Total Accepted: 52017 Total Submissions: 148529 Difficulty: Medium
The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
Note:
For a given n, a gray code sequence is not uniquely defined.

For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.

Subscribe to see which companies asked this question
  */
  /*
  n = 0: 0
n = 1: 0, 1
n = 2: 00, 01, 11, 10  (0, 1, 3, 2)
n = 3: 000, 001, 011, 010, 110, 111, 101, 100 (0, 1, 3, 2, 6, 7, 5, 4)
the second half has the first 1 and the order is reverse compared with the first half
  */
  vector<int> greySeq;
  if (n<0) return greySeq;
  greySeq.push_back(0);
  int inc = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = greySeq.size() - 1; j >= 0; j--)
      greySeq.push_back(greySeq[j] + inc);
    inc <<= 1;
  }
  return greySeq;
}


class WordDictionary {
  /*
  211. Add and Search Word - Data structure design My Submissions Question
  Total Accepted: 18273 Total Submissions: 89748 Difficulty: Medium
  Design a data structure that supports the following two operations:

  void addWord(word)
  bool search(word)
  search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

  For example:

  addWord("bad")
  addWord("dad")
  addWord("mad")
  search("pad") -> false
  search("bad") -> true
  search(".ad") -> true
  search("b..") -> true
  */
public:
  WordDictionary() {
    root = new TrieNode();
  }

  // Adds a word into the data structure.
  void addWord(string word) {
    TrieNode* run = root;
    for (char c : word) {
      if (!(run->children[c - 'a']))
        run->children[c - 'a'] = new TrieNode();
      run = run->children[c - 'a'];
    }
    run->isKey = true;
  }

  // Returns if the word is in the data structure. A word could
  // contain the dot character '.' to represent any one letter.
  bool search(string word) {
    return query(word.c_str(), root);
  }

private:
  TrieNode* root;

  bool query(const char* word, TrieNode* node) {
    TrieNode* run = node;
    for (int i = 0; word[i]; i++) {
      if (run && word[i] != '.')
        run = run->children[word[i] - 'a'];
      else if (run && word[i] == '.') {
        TrieNode* tmp = run;
        for (int j = 0; j < 26; j++) {
          run = tmp->children[j];
          if (query(word + i + 1, run))
            return true;
        }
      }
      else break;
    }
    return run && run->isKey;
  }
};
void restoreIpAddressesHelper(string& s, int start, int partNum, string ip, vector<string>& result) {
  /*
  * s : input string
  * start : current index
  * partNum : current part
  * ip : current string
  * result : result string vector
  */

  int len = s.size();
  if (len - start < 4 - partNum || len - start >(4 - partNum) * 3) {
    /*
    * len - start : total length - current index -> un-scan chars
    * 4 - partNum : left part( unused )
    * for example : len-start = 1, 4-partNum = 2, or len-start = 2, 4-partNum = 3
    */
    return;
  }

  if (partNum == 4 && start == len){
    ip.erase(ip.end() - 1, ip.end());
    result.push_back(ip);
    return;
  }

  int num = 0;
  for (int i = start; i<start + 3; i++){
    num = num * 10 + s[i] - '0';
    if (num<256){
      ip += s[i];
      restoreIpAddressesHelper(s, i + 1, partNum + 1, ip + '.', result);
    }
    //0.0.0.0 valid, but 0.1.010.01 is not
    if (num == 0) {
      break;
    }
  }

}

vector<string> restoreIpAddresses(string s) {
  /*
  93. Restore IP Addresses My Submissions Question
  Total Accepted: 49167 Total Submissions: 218412 Difficulty: Medium
  Given a string containing only digits, restore it by returning all possible valid IP address combinations.

  For example:
  Given "25525511135",

  return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)

  Subscribe to see which companies asked this question
  */
  vector<string> result;
  string ip;
  restoreIpAddressesHelper(s, 0, 0, ip, result);
  return result;
}

void backtracking(const vector<vector<char>>& table, vector<string>& res, string& local,
  int index, const string& digits) {
  if (index == digits.size())
    res.push_back(local);
  else
  for (int i = 0; i<table[digits[index] - '0'].size(); i++) {
    local.push_back(table[digits[index] - '0'][i]);
    backtracking(table, res, local, index + 1, digits);
    local.pop_back();
  }
}

vector<string> letterCombinations(string digits)
{
  /*
  17. Letter Combinations of a Phone Number My Submissions Question
  Total Accepted: 66855 Total Submissions: 243797 Difficulty: Medium
  Given a digit string, return all possible letter combinations that the number could represent.

  A mapping of digit to letters (just like on the telephone buttons) is given below.



  Input:Digit string "23"
  Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
  Note:
  Although the above answer is in lexicographical order, your answer could be in any order you want.
  */
  vector<string> res;
  if (digits.size() == 0) return res;
  string local;
  vector<vector<char>> table(2, vector<char>());
  table.push_back(vector<char>{'a', 'b', 'c'}); // index 2
  table.push_back(vector<char>{'d', 'e', 'f'}); // 3
  table.push_back(vector<char>{'g', 'h', 'i'});
  table.push_back(vector<char>{'j', 'k', 'l'}); // 5
  table.push_back(vector<char>{'m', 'n', 'o'});
  table.push_back(vector<char>{'p', 'q', 'r', 's'}); // 7
  table.push_back(vector<char>{'t', 'u', 'v'});
  table.push_back(vector<char>{'w', 'x', 'y', 'z'}); // 9

  backtracking(table, res, local, 0, digits);
  return res;
}

bool isValid(int attemptedColumn, int attemptedRow, vector<int> &queenInColumn) {
  //Attempting to put the Queen into [row, col], check it is valid or not
  //Notes:
  //  1) we just checking the Column not Row, because the row cannot be conflicted
  //  2) to check the diagonal, we just check |x'-x| == |y'-y|, (x',y') is a Queen will be placed
  /* for each row i1 and col[i1], and row i2 and col[i2], when ( abs (i1-i2) == abs ( col[i1] - col[i2])  )
  * they are at the same diagonal line
  * attemptedColumn : the current column
  * attemptedRow : the current row
  * queenInColumn : so far, the solution
  */


  for (int i = 0; i<attemptedRow; i++) {
    if (attemptedColumn == queenInColumn[i] ||
      abs(attemptedColumn - queenInColumn[i]) == abs(attemptedRow - i)) {
      return false;
    }
  }
  return true;
}

void solveNQueensRecursive(int n, int currentRow, vector<int>& solution, vector< vector<string> >& result) {
  //The following recursion is easy to understand. Nothing's tricky.
  //  1) recursively find all of possible columns row by row.
  //  2) solution[] array only stores the columns index. `solution[row] = col;`
  //if no more row need to do, shape the result
  if (currentRow == n){
    vector<string> s;
    for (int row = 0; row < n; row++) {
      string sRow;
      for (int col = 0; col < n; col++) {
        sRow = sRow + (solution[row] == col ? "Q" : ".");
      }
      s.push_back(sRow);
    }
    result.push_back(s);
    return;
  }

  //for each column
  for (int col = 0; col < n; col++) {
    //if the current column is valid
    if (isValid(col, currentRow, solution)) {
      //place the Queue
      solution[currentRow] = col;
      //recursively put the Queen in next row
      solveNQueensRecursive(n, currentRow + 1, solution, result);
    }
  }
}

vector< vector<string> > solveNQueens(int n) {

  /**********************************************************************************
  *
  * The n-queens puzzle is the problem of placing n queens on an n×n chessboard
  * such that no two queens attack each other.
  *
  * Given an integer n, return all distinct solutions to the n-queens puzzle.
  *
  * Each solution contains a distinct board configuration of the n-queens' placement,
  * where 'Q' and '.' both indicate a queen and an empty space respectively.
  *
  * For example,
  * There exist two distinct solutions to the 4-queens puzzle:
  *
  * [
  *  [".Q..",  // Solution 1
  *   "...Q",
  *   "Q...",
  *   "..Q."],
  *
  *  ["..Q.",  // Solution 2
  *   "Q...",
  *   "...Q",
  *   ".Q.."]
  * ]
  *
  *
  **********************************************************************************/
  vector< vector<string> > result;
  vector<int> solution(n);
  solveNQueensRecursive(n, 0, solution, result);

  return result;
}

void solveNQueensRecursiveTotal(int n, int currentRow, vector<int>& solution, int& result) {

  // the solution is same as the "N Queens" problem.
  for (int i = 0; i < n; i++) {
    if (isValid(i, currentRow, solution)) {
      if (currentRow + 1 == n){
        result++;
        continue;
      }
      solution[currentRow] = i;
      solveNQueensRecursiveTotal(n, currentRow + 1, solution, result);
    }
  }
}

int totalNQueens(int n) {
  /**********************************************************************************
  *
  * Follow up for N-Queens problem.
  *
  * Now, instead outputting board configurations, return the total number of distinct solutions.
  *
  *
  **********************************************************************************/
  int result = 0;
  vector<int> solution(n);

  solveNQueensRecursiveTotal(n, 0, solution, result);

  return result;
}

similar one, with long division by number of permutations

priv
  string result;

string getPermutation(int n, int k) {
  /**********************************************************************************
  *
  * The set [1,2,3,…,n] contains a total of n! unique permutations.
  *
  * By listing and labeling all of the permutations in order,
  * We get the following sequence (ie, for n = 3):
  *
  * "123"
  * "132"
  * "213"
  * "231"
  * "312"
  * "321"
  *
  * Given n and k, return the kth permutation sequence.
  *
  * Note: Given n will be between 1 and 9 inclusive.
  *
  **********************************************************************************/

  /*
  Attached please find my solution.

  Idea:

  For an n-element permutation, there are (n-1)! permutations started with '1',
  (n-1)! permutations started with '2', and so forth. Therefore we can
  determine the value of the first element.

  After determining the first element, there are (n-1) candidates left. Then
  there are (n-2)! permutations started with the minimum element within the
  remaining set, and so forth.

  Complexities:

  Time complexity: O(n^2)

  Space complexity: O(n)
  take n=3, k=5 as an example:

  initial temp="123"; length of string len=3; renew k into k-1=4;

  the first char of result comes from k/(len-1)! position of temp, that is temp[2];
  push "3" into result and erase it from temp, the remaining string goes to temp="12";
  renew k into k%(len-1)!, that is 0;
  len--;
  repeat the loop;

  */

  string result = "";
  string temp = "1";
  int len = 1;

  for (int t = 2; t <= n; t++){ temp = temp + to_string(t); len = len*t; }
  // len = 2 * 3 = 6

  k = (k - 1) % len;                           // need k-1 here instead for calculation
  int count = n;
  int position;

  for (; k > 0;){

    len = len / count;
    position = k / len;                    // use k/len to determine the char picked from the remaing string

    result.push_back(temp[position]);  // record the char
    temp.erase(position, 1);           // erase that from the remaing string

    k = k%len;
    count--;

  }

  result = result + temp;                    // when k=0, no further permutation for the rest

  return result;

}

