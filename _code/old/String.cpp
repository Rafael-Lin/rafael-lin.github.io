
#include "stdafx.h"
#include "String.h"
#include "string"
#include<algorithm>
#include<stack>
#include<vector>
#include<ctime>
#include<iostream>
#include<set>
#include"type.h"
#include<unordered_map>
#include<unordered_set>

//#include<numeric>
#define GUARD -10000

using namespace std;

ST::ST() {

}

string longestCommonPrefix(vector<string> &strs) {
  /**********************************************************************************
   *
   * Write a function to find the longest common prefix string amongst an array of strings.
   *
   *
   **********************************************************************************/
  string word;
  if (strs.size() <= 0) return word;
  for (int i = 1; i <= strs[0].size(); i++){
    string w = strs[0].substr(0, i);
    bool match = true;
    int j = 1;
    for (j = 1; j<strs.size(); j++){
      if (i>strs[j].size() || w != strs[j].substr(0, i)) {
        match = false;
        break;
      }
    }
    if (!match) {
      return word;
    }
    word = w;
  }
  return word;
}

int compareVersion(string version1, string version2) {

  /**********************************************************************************
   *
   * Compare two version numbers version1 and version1.
   * If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.
   *
   * You may assume that the version strings are non-empty and contain only digits and the . character.
   * The . character does not represent a decimal point and is used to separate number sequences.
   * For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.
   *
   * Here is an example of version numbers ordering:
   * 0.1 < 1.1 < 1.2 < 13.37
   *
   * Credits:Special thanks to @ts for adding this problem and creating all test cases.
   *
   **********************************************************************************/
  int i = 0;
  int j = 0;
  int n1 = version1.size();
  int n2 = version2.size();

  int num1 = 0;
  int num2 = 0;
  while (i < n1 || j < n2)
  {
    while (i < n1 && version1[i] != '.'){
      num1 = num1 * 10 + (version1[i] - '0');
      i++;
    }

    while (j<n2 && version2[j] != '.'){
      num2 = num2 * 10 + (version2[j] - '0');;
      j++;
    }

    if (num1>num2) return 1;
    else if (num1 < num2) return -1;

    num1 = 0;
    num2 = 0;
    i++;
    j++;
  }

  return 0;
}

string vecToStr(vector<int> v) {
  /*
     stringstream ss;
     for (int i=0; i<v.size(); i++) {
     ss << v[i];
     }
     return ss.str();
     */
  return "Hello";
}

vector<int> getNext(vector<int>& v) {
  int cnt = 0;
  int val = 0;
  vector<int> ret;
  for (int i = 0; i < v.size(); i++){
    if (i == 0){
      val = v[i];
      cnt = 1;
      continue;
    }
    if (v[i] == val){
      cnt++;
    }
    else{
      ret.push_back(cnt);
      ret.push_back(val);
      val = v[i];
      cnt = 1;
    }
  }
  if (cnt > 0 && val > 0){
    ret.push_back(cnt);
    ret.push_back(val);
  }
  return ret;
}

string countAndSay(int n) {
  /**********************************************************************************
   *
   * The count-and-say sequence is the sequence of integers beginning as follows:
   * 1, 11, 21, 1211, 111221, ...
   *
   * 1 is read off as "one 1" or 11.
   * 11 is read off as "two 1s" or 21.
   * 21 is read off as "one 2, then one 1" or 1211.
   *
   * Given an integer n, generate the nth sequence.
   *
   * Note: The sequence of integers will be represented as a string.
   *
   *
   **********************************************************************************/
  if (n <= 0) return "";
  if (n == 1) return "1";

  string s;
  vector<int> v;
  v.push_back(1);
  for (int i = 2; i <= n; i++){
    v = getNext(v);
    //s = s + ", " +vecToStr(v);
  }
  s = vecToStr(v);
  return s;
}

int lengthOfLastWord(string s){
  /**********************************************************************************
   *
   * Given a string s consists of upper/lower-case alphabets and empty space characters ' ',
   * return the length of last word in the string.
   *
   * If the last word does not exist, return 0.
   *
   * Note: A word is defined as a character sequence consists of non-space characters only.
   *
   * For example,
   * Given s = "Hello World",
   * return 5.
   *
   *
   **********************************************************************************/
  int count = 0;
  for (int i = s.size() - 1; i >= 0; i--) {
    if (count && s[i] == ' ')  return count;
    if (s[i] != ' ') count++;
  }
  return count;
}

string convert(string s, int nRows) {
  /**********************************************************************************
   *
   * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
   * (you may want to display this pattern in a fixed font for better legibility)
   *
   * P   A   H   N
   * A P L S I I G
   * Y   I   R
   *
   * And then read line by line: "PAHNAPLSIIGYIR"
   *
   * Write the code that will take a string and make this conversion given a number of rows:
   *
   * string convert(string text, int nRows);
   *
   * convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
   *
   *
   **********************************************************************************/
  /*
     P.......A......H.......N
     ..A..P....L..S...I...I...G
     ...Y.......I.......R
     */
  //The cases no need to do anything
  if (nRows <= 1 || nRows >= s.size()) return s;

  vector<string> r(nRows);
  int row = 0;
  int step = 1;
  for (int i = 0; i < s.size(); i++) {
    if (row == nRows - 1)
      step = -1;
    if (row == 0)
      step = 1;
    //cout << row <<endl;
    r[row] += s[i];
    row += step;
  }

  string result;
  for (int i = 0; i < nRows; i++){
    result += r[i];
  }
  return result;
}

string removeNoise(string& s){
  string d;
  for (int i = 0; i < s.size(); i++){
    if (::isalpha(s[i]) || ::isdigit(s[i])){
      d.push_back(::tolower(s[i]));
    }
  }
  return d;
}

bool isPalindrome(string s) {
  /*
     125. Valid Palindrome My Submissions Question
     Total Accepted: 89459 Total Submissions: 384051 Difficulty: Easy
     Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

     For example,
     "A man, a plan, a canal: Panama" is a palindrome.
     "race a car" is not a palindrome.
     */
  s = removeNoise(s);
  for (int i = 0; i < s.size() / 2; i++){
    if (s[i] != s[s.size() - i - 1]){
      return false;
    }
  }
  return true;
}

int strStr(string haystack, string needle) {

  /**********************************************************************************
   *
   * Implement strStr().
   *
   * Returns a pointer to the first occurrence of needle in haystack, or null if needle is not part of haystack.
   *
   *
   **********************************************************************************/
  int m = haystack.length(), n = needle.length();
  if (!n) return 0;
  for (int i = 0; i < m - n + 1; i++) {
    int j = 0;
    for (; j < n; j++)
      if (haystack[i + j] != needle[j])
        break;
    if (j == n) return i;
  }
  return -1;
}
int romanCharToInt(char c) {
  switch (c) {
    case 'I':   return 1;
    case 'V':   return 5;
    case 'X':   return 10;
    case 'L':   return 50;
    case 'C':   return 100;
    case 'D':   return 500;
    case 'M':   return 1000;
    default:    return 0;
  }
}

int romanToInt(string s) {
  /**********************************************************************************
   *
   * Given a roman numeral, convert it to an integer.
   *
   * Input is guaranteed to be within the range from 1 to 3999.
   *
   **********************************************************************************/
  int num = 0;
  int size = s.size();

  for (int i = 0; i < size; i++) {
    if (i < (size - 1) && romanCharToInt(s[i]) < romanCharToInt(s[i + 1])) {
      num -= romanCharToInt(s[i]);
    }
    else {
      num += romanCharToInt(s[i]);
    }
  }
  return num;
}

string intToRoman(int num) {
  /**********************************************************************************
   *
   * Given an integer, convert it to a roman numeral.
   *
   * Input is guaranteed to be within the range from 1 to 3999.
   *
   **********************************************************************************/
  string symbol[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
  int value[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
  string result;

  for (int i = 0; num != 0; i++){
    while (num >= value[i]){
      num -= value[i];
      result += symbol[i];
    }
  }

  return result;
}

string intToRomanSimple(int num) {
  string M[] = { "", "M", "MM", "MMM" };
  string C[] = { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" };
  string X[] = { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" };
  string I[] = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };
  return M[num / 1000] + C[(num % 1000) / 100] + X[(num % 100) / 10] + I[num % 10];
}

string digits[20] = { "Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight",
  "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen",
  "Eighteen", "Nineteen" };

string tens[10] = { "Zero", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy",
  "Eighty", "Ninety" };

string int2string(int n) {
  if (n >= 1000000000) {
    return int2string(n / 1000000000) + " Billion" + int2string(n % 1000000000);
  }
  else if (n >= 1000000) {
    return int2string(n / 1000000) + " Million" + int2string(n % 1000000);
  }
  else if (n >= 1000) {
    return int2string(n / 1000) + " Thousand" + int2string(n % 1000);
  }
  else if (n >= 100) {
    return int2string(n / 100) + " Hundred" + int2string(n % 100);
  }
  else if (n >= 20) {
    return  " " + tens[n / 10] + int2string(n % 10);
  }
  else if (n >= 1) {
    return " " + digits[n];
  }
  else {
    return "";
  }
}

string numberToWords(int num) {
  /***************************************************************************************
   *
   * Convert a non-negative integer to its english words representation. Given input is
   * guaranteed to be less than 231 - 1.
   *
   * For example,
   *
   * 123 -> "One Hundred Twenty Three"
   * 12345 -> "Twelve Thousand Three Hundred Forty Five"
   * 1234567 -> "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
   *
   *   Did you see a pattern in dividing the number into chunk of words? For example, 123
   * and 123000.
   *
   *   Group the number by thousands (3 digits). You can write a helper function that
   * takes a number less than 1000 and convert just that chunk to words.
   *
   *   There are many edge cases. What are some good test cases? Does your code work with
   * input such as 0? Or 1000010? (middle chunk is zero and should not be printed out)
   *
   ***************************************************************************************/
  if (num == 0) {
    return "Zero";
  }
  else {
    string ret = int2string(num);
    return ret.substr(1, ret.length() - 1);
  }
}


//Quick & Dirty Solution
bool isOperator1(const char ch) {
  return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int Priority(const char c) {
  if (c == '*' || c == '/') {
    return 2;
  }
  else if (c == '+' || c == '-') {
    return 1;
  }
  else {
    return 0;
  }
}

long long calculate_exp(long long x, long long y, char op) {
  switch (op) {
    case '+': return x + y;
    case '-': return x - y;
    case '*': return x * y;
    case '/': return x / y;
  }
  return -1;
}

//Two Stacks solution
int calculate_two_stacks(string& s) {

  s += "+0";
  stack<long long> num_stack; //put the number
  stack<char> op_stack; //put the operations

#define CALCULATE_IT { \
  long long y = num_stack.top(); num_stack.pop(); \
  long long x = num_stack.top(); num_stack.pop(); \
  char op = op_stack.top(); op_stack.pop(); \
  num_stack.push(calculate_exp(x, y, op)); \
}

  for (int i = 0; i < s.size(); i++){
    char ch = s[i];
    if (isspace(ch)) continue;
    if (isdigit(ch)) {
      string num;
      num += s[i];
      while (isdigit(s[i + 1])){
        num += s[i + 1];
        i++;
      }
      num_stack.push(stoll(num));
      continue;
    }
    if (isOperator1(ch)) {
      while (!op_stack.empty() && Priority(op_stack.top()) >= Priority(ch)) {
        CALCULATE_IT;
      }

      op_stack.push(ch);
    }

  }

while (!op_stack.empty()){
  CALCULATE_IT;
}

return num_stack.top();
}

int calculate1(string s) {
  /**********************************************************************************
   *
   * Implement a basic calculator to evaluate a simple expression string.
   *
   * The expression string contains only non-negative integers, +, -, *, / operators and empty spaces  .
   * The integer division should truncate toward zero.
   *
   * You may assume that the given expression is always valid.
   *
   * Some examples:
   *
   * "3+2*2" = 7
   * " 3/2 " = 1
   * " 3+5 / 2 " = 5
   *
   * Note: Do not use the eval built-in library function.
   *
   * Credits:Special thanks to @ts for adding this problem and creating all test cases.
   **********************************************************************************/
  return calculate_two_stacks(s);
}

int ST::check(char ch){
  //check 0 or not
  return (!isdigit(ch) || ch == '0') ? 0 : 1;
}

int ST::check(char ch1, char ch2){
  //check it's between 10 and 26
  return (ch1 == '1' || (ch1 == '2' && ch2 <= '6')) ? 1 : 0;
}

int ST::numDecodings(string s) {
  /**********************************************************************************
   *
   * A message containing letters from A-Z is being encoded to numbers using the following mapping:
   *
   * 'A' -> 1
   * 'B' -> 2
   * ...
   * 'Z' -> 26
   *
   * Given an encoded message containing digits, determine the total number of ways to decode it.
   *
   * For example,
   * Given encoded message "12",
   * it could be decoded as "AB" (1 2) or "L" (12).
   *
   * The number of ways decoding "12" is 2.
   *
   *
   **********************************************************************************/
  //Count[i] = Count[i-1]              if S[i-1] is a valid char (not '0')
  // or      = Count[i-1]+ Count[i-2]  if S[i-1] and S[i-2] together is still a valid char (10 to 26).

  if (s.size() <= 0) return 0;
  if (s.size() == 1) return check(s[0]);

  int* dp = new int[s.size()];
  memset(dp, 0, s.size()*sizeof(int));

  dp[0] = check(s[0]);
  dp[1] = check(s[0]) *  check(s[1]) + check(s[0], s[1]);
  for (int i = 2; i < s.size(); i++) {
    if (!isdigit(s[i])) break;
    if (check(s[i])) {
      dp[i] = dp[i - 1];
    }
    if (check(s[i - 1], s[i])) {
      dp[i] += dp[i - 2];
    }

  }
  int result = dp[s.size() - 1];
  delete[] dp;
  return result;
}

int numDecodings1(string s) {
  /*
     if XY <= 26 -> h[x], h[y], h[xy]
     if XY > 26 -> h[x], h[y]

     dp[i+1] : the total method to decode the string s, whose length = i + 1
     dp[0] = 1
     dp[1] = 1
     v = s[i-1] * 10 + s[i]
     if v<= 26 -> dp[i+1] = dp[i] + dp[i-1];
     if v> 26 -> dp[i+1] = dp[i] ;

     corner case :
     XY could be decoded when 9 < XY<= 26
     Y could be decoded singlely when Y!= 0
     */
  if(s.empty() || s[0]<'1' || s[0]>'9') return 0;
  vector<int> dp(s.size()+1,0);
  dp[0] = dp[1] = 1;

  for(int i=1; i<s.size(); i++) {
    if(!isdigit(s[i])) return 0;
    int v = (s[i-1]-'0')*10 + (s[i]-'0');
    if(v<=26 && v>9) dp[i+1] += dp[i-1];
    if(s[i]!='0') dp[i+1] += dp[i];
    if(dp[i+1]==0) return 0;
  }
  return dp[s.size()];
}

string findPalindrome(string s, int left, int right){
  int n = s.size();
  int l = left;
  int r = right;
  while (left>=0 && right<=n-1 && s[left] == s[right]) {
    left--;
    right++;
  }
  return s.substr(left+1, right-left-1);
}

string longestPalindrome(string s) {

  /**********************************************************************************
   *
   * Given a string S, find the longest palindromic substring in S.
   * You may assume that the maximum length of S is 1000,
   * and there exists one unique longest palindromic substring.
   *
   **********************************************************************************/
  int n = s.size();
  if (n<=1) return s;

  string longest;

  string str;
  for (int i=0; i<n-1; i++) {
    str = findPalindrome(s, i, i);
    if (str.size() > longest.size()){
      longest = str;
    }
    str = findPalindrome(s, i, i+1);
    if (str.size() > longest.size()){
      longest = str;
    }
  }

  return longest;
}

void reverseWords(string &s) {

  /**********************************************************************************
   *
   * Given an input string, reverse the string word by word.
   *
   * For example,
   * Given s = "the sky is blue",
   * return "blue is sky the".
   *
   *
   * Clarification:
   *
   * What constitutes a word?
   * A sequence of non-space characters constitutes a word.
   * Could the input string contain leading or trailing spaces?
   * Yes. However, your reversed string should not contain leading or trailing spaces.
   * How about multiple spaces between two words?
   * Reduce them to a single space in the reversed string.
   *
   *
   **********************************************************************************/
  if(s.empty()) return;
  string ret, word;

  for(int i=s.size()-1; i>=0; i--) {
    if(isspace(s[i])) {
      if(i<s.size()-1 && !isspace(s[i+1])) {
        reverse(word.begin(),word.end());
        ret.append(word+" ");
        word.clear();
      }
    }
    else {
      word.push_back(s[i]);
    }
  }

  if(!isspace(s[0])) {
    reverse(word.begin(),word.end());
    ret.append(word);
  }
  else if(!ret.empty()) {
    ret.pop_back();
  }

  s = ret;
}

void reverseWordsOneScan(string &s) {
  string ret;
  int j = s.size();
  for(int i=s.size()-1; i>=0; i--) {
    if(s[i]==' ')
      j = i;
    else if(i==0 || s[i-1]==' ') {
      if(!ret.empty()) ret.append(" ");
      ret.append(s.substr(i, j-i));
    }
  }
  s = ret;
}

int minDistance2(string word1, string word2) {

  /*
     1. Initial state and final output result
     DP[i+1][j+1]：word1[0:i] -> word2[0:j]的edit distance。
     return DP[i+1][j+1]

     2. formula
     考虑word1[0:i] -> word2[0:j]的最后一次edit。无非题目中给出的三种方式：

     a) insert one char : word1[0:i] -> word2[0:j-1], then insert word2[j] at word1[i]
     DP[i+1][j+1] = DP[i+1][j]+1

     b) delete one char : word1[0:i-1] -> word2[0:j], then delete word1[i]
     DP[i+1][j+1] = DP[i][j+1]+1

     c) replace one char : word1[0:i-1] -> word2[0:j-1]
     when word1[i] != word2[j]，word1[i] -> word2[j]：DP[i+1][j+1] = DP[i][j] + 1
     when word1[i] == word2[j]：DP[i+1][j+1] = DP[i][j]

     here comes the formula :
     DP[i+1][j+1] = min(DP[i][j] + k, DP[i+1][j]+1, DP[i][j+1]+1)
     word1[i]==word2[j] -> k = 0, otherwise k = 1

     3. calculate direction :
     replace (i, j)      delete (i, j+1)
     insert (i+1, j)    (i+1, j+1)

*/
  int m = word1.size(), n = word2.size();
  vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
  for(int j=1; j<=n; j++)
    dp[0][j] = j;

  for(int i=1; i<=m; i++) {
    dp[i][0] = i;
    for(int j=1; j<=n; j++) {
      dp[i][j] = dp[i-1][j-1];
      if(word1[i-1]!=word2[j-1]) dp[i][j]++;
      dp[i][j] = min(min(dp[i-1][j]+1, dp[i][j-1]+1), dp[i][j]);
    }
  }

  return dp[m][n];
}

int minTrio(int x, int y, int z) {
  return std::min(x, std::min(y,z));
}

int minDistance(string word1, string word2) {
  /**********************************************************************************
   *
   * Given two words word1 and word2, find the minimum number of steps required to
   * convert word1 to word2. (each operation is counted as 1 step.)
   *
   * You have the following 3 operations permitted on a word:
   *
   * a) Insert a character
   * b) Delete a character
   * c) Replace a character
   *
   *
   **********************************************************************************/

  /*
   *  Dynamic Programming
   *
   *    Definitaion
   *
   *        m[i][j] is minimal distance from word1[0..i] to word2[0..j]
   *
   *    So,
   *
   *        1) if word1[i] == word2[j], then m[i][j] == m[i-1][j-1].
   *
   *        2) if word1[i] != word2[j], then we need to find which one below is minimal:
   *
   *             min( m[i-1][j-1], m[i-1][j],  m[i][j-1] )
   *
   *             and +1 - current char need be changed.
   *
   *        Let's take a look  m[1][2] :  "a" => "ab"
   *
   *               +---+  +---+
   *        ''=> a | 1 |  | 2 | '' => ab
   *               +---+  +---+
   *
   *               +---+  +---+
   *        a => a | 0 |  | 1 | a => ab
   *               +---+  +---+
   *
   *        To know the minimal distance `a => ab`, we can get it from one of the following cases:
   *
   *            1) delete the last char in word1,  minDistance( '' => ab ) + 1
   *            2) delete the last char in word2,  minDistance(  a => a ) + 1
   *            3) change the last char,           minDistance( '' => a ) + 1
   *
   *            1) insert the last char in word1,  minDistance( a => ab ) + 1
   *            2) delete the last char in word1,  minDistance( a => "" ) + 1
   *            3) change the last char in word1,  minDistance( a => b ) + 1
   *
   *
   *    For Example:
   *
   *        word1="abb", word2="abccb"
   *
   *        1) Initialize the DP matrix as below:
   *
   *               "" a b c c b
   *            "" 0  1 2 3 4 5
   *            a  1
   *            b  2
   *            b  3
   *
   *        2) Dynamic Programming
   *
   *               "" a b c c b
   *            ""  0 1 2 3 4 5
   *            a   1 0 1 2 3 4
   *            b   2 1 0 1 2 3
   *            b   3 2 1 1 1 2
   *
   */

  int n1 = word1.size();
  int n2 = word2.size();
  if (n1==0) return n2;
  if (n2==0) return n1;
  vector< vector<int> > m(n1+1, vector<int>(n2+1));
  for(int i=0; i<m.size(); i++){
    m[i][0] = i;
  }
  for (int i=0; i<m[0].size(); i++) {
    m[0][i]=i;
  }

  //Dynamic Programming
  int row, col;
  for (row=1; row<m.size(); row++) {
    for(col=1; col<m[row].size(); col++){
      if (word1[row-1] == word2[col-1] ){
        m[row][col] = m[row-1][col-1];
      }else{
        int minValue = minTrio(m[row-1][col-1], m[row-1][col],  m[row][col-1]);
        m[row][col] = minValue + 1;
      }
    }
  }

  return m[row-1][col-1];
}

int ST::longestValidParentheses(string s) {

  /**********************************************************************************
   *
   * Given a string containing just the characters '(' and ')',
   * find the length of the longest valid (well-formed) parentheses substring.
   *
   * For "(()", the longest valid parentheses substring is "()", which has length = 2.
   *
   * Another example is ")()())", where the longest valid parentheses substring is "()()",
   * which has length = 4.
   *
   *
   **********************************************************************************/
//http://bangbingsyb.blogspot.tw/2014/11/leetcode-longest-valid-parentheses.html

  stack<pair<int,int>> stk;   // first: index, second: 0:'(', 1:')'
  int maxLen = 0, curLen = 0;
  for(int i=0; i<s.size(); i++) {
    if(s[i]=='(')   // left parenthesis
      stk.push(make_pair(i,0));
    else {          // right parenthesis
      if(stk.empty() || stk.top().second==1)
        stk.push(make_pair(i,1));
      else {
        stk.pop();
        if(stk.empty())
          curLen = i+1;
        else
          curLen = i-stk.top().first;
        maxLen = max(maxLen, curLen);
      }
    }
  }
  return maxLen;
}
