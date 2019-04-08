
#include "stdafx.h"
#include "HT.h"
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
using namespace std;

bool HT::wordPattern(string pattern, string str) {
  /*
  290. Word Pattern My Submissions Question
  Total Accepted: 21298 Total Submissions: 77627 Difficulty: Easy
  Given a pattern and a string str, find if str follows the same pattern.

  Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

  Examples:
  pattern = "abba", str = "dog cat cat dog" should return true.
  pattern = "abba", str = "dog cat cat fish" should return false.
  pattern = "aaaa", str = "dog cat cat dog" should return false.
  pattern = "abba", str = "dog dog dog dog" should return false.
  Notes:
  You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.
  */
  map<char, int> p2i;
  map<string, int> w2i;
  istringstream in(str);
  int i = 0, n = pattern.size();
  for (string word; in >> word; ++i) {
    if (i == n || p2i[pattern[i]] != w2i[word])
      return false;
    p2i[pattern[i]] = w2i[word] = i + 1;
  }
  return i == n;
  return true;
}

int tran(int n){
  int ans = 0;
  while (n){
    ans += pow(n % 10, 2);
    n /= 10;
  }
  return ans;
}

bool isHappy(int n) {
  /*
  202. Happy Number My Submissions Question
  Total Accepted: 49584 Total Submissions: 141605 Difficulty: Easy
  Write an algorithm to determine if a number is "happy".

  A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

  Example: 19 is a happy number

  12 + 92 = 82
  82 + 22 = 68
  62 + 82 = 100
  12 + 02 + 02 = 1
  Credits:
  Special thanks to @mithmatt and @ts for adding this problem and creating all test cases.

  Subscribe to see which companies asked this question
  */

  bool rep[1000];
  memset(rep, 0, sizeof(rep));
  n = tran(n);
  while (!rep[n]){
    rep[n] = true;
    if (n == 1)
      return true;
    n = tran(n);
  }
  return false;
}

string getHint(string secret, string guess) {
  /*
  299. Bulls and Cows My Submissions Question
  Total Accepted: 14657 Total Submissions: 53450 Difficulty: Easy
  You are playing the following Bulls and Cows game with your friend: You write down a number and ask your friend to guess what the number is.
  Each time your friend makes a guess, you provide a hint that indicates how many digits in said guess match your secret number exactly in both digit and position
  (called "bulls") and how many digits match the secret number but locate in the wrong position (called "cows").
  Your friend will use successive guesses and hints to eventually derive the secret number.

  For example:

  Secret number:  "1807"
  Friend's guess: "7810"
  Hint: 1 bull and 3 cows. (The bull is 8, the cows are 0, 1 and 7.)
  Write a function to return a hint according to the secret number and friend's guess, use A to indicate the bulls and B to indicate the cows.
  In the above example, your function should return "1A3B".

  Please note that both secret number and friend's guess may contain duplicate digits, for example:

  Secret number:  "1123"
  Friend's guess: "0111"
  In this case, the 1st 1 in friend's guess is a bull, the 2nd or 3rd 1 is a cow, and your function should return "1A1B".
  You may assume that the secret number and your friend's guess only contain digits, and their lengths are always equal.

  Credits:
  Special thanks to @jeantimex for adding this problem and creating all test cases.
  */
  int aCnt = 0;
  int bCnt = 0;
  vector<int> sVec(10, 0); // 0 ~ 9 for secret
  vector<int> gVec(10, 0); // 0 ~ 9 for guess
  if (secret.size() != guess.size() || secret.empty()) { return "0A0B"; }
  for (int i = 0; i < secret.size(); ++i) {
    char c1 = secret[i]; char c2 = guess[i];
    if (c1 == c2) {
      ++aCnt;
    }
    else {
      ++sVec[c1 - '0'];
      ++gVec[c2 - '0'];
    }
  }
  // count b
  for (int i = 0; i < sVec.size(); ++i) {
    bCnt += min(sVec[i], gVec[i]);
  }
  return to_string(aCnt) + 'A' + to_string(bCnt) + 'B';
}

bool isValidSudoku(vector<vector<char>>& board) {
  /*
  36. Valid Sudoku My Submissions Question
  Total Accepted: 60351 Total Submissions: 207145 Difficulty: Easy
  Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

  The Sudoku board could be partially filled, where empty cells are filled with the character '.'.


  A partially filled sudoku which is valid.

  Note:
  A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.

  Subscribe to see which companies asked this question

  Hide Tags

  */
  bool row[9][9] = { false }, col[9][9] = { false }, box[9][9] = { false };
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if (board[i][j] != '.') {
        int num = board[i][j] - '0' - 1;
        int k = i / 3 * 3 + j / 3;
        if (row[i][num] || col[j][num] || box[k][num]) return false;
        row[i][num] = col[j][num] = box[k][num] = true;
      }
    }
  }
  return true;

}

bool isAnagramUnorderMap(string s, string t) {
  /*
  Given two strings s and t, write a function to determine if t is an anagram of s.

  For example,
  s = "anagram", t = "nagaram", return true.
  s = "rat", t = "car", return false.

  Note:
  You may assume the string contains only lowercase alphabets.

  Follow up:
  What if the inputs contain unicode characters? How would you adapt your solution to such case?
  */
  if (s.length() != t.length()) return false;
  int n = s.length();
  unordered_map<char, int> counts;
  for (int i = 0; i < n; i++) {
    counts[s[i]]++;
    counts[t[i]]--;
  }
  for (auto count : counts)
  if (count.second) return false;
  return true;
}

bool isAnagramSelfMap(string s, string t) {
  if (s.length() != t.length()) return false;
  int n = s.length();
  int counts[26] = { 0 };
  for (int i = 0; i < n; i++) {
    counts[s[i] - 'a']++;
    counts[t[i] - 'a']--;
  }
  for (int i = 0; i < 26; i++)
  if (counts[i]) return false;
  return true;
}

bool isAnagramSort(string s, string t) {
  sort(s.begin(), s.end());
  sort(t.begin(), t.end());
  return s == t;
}

int HT::countPrimes(int n) {
  /*
  204. Count Primes My Submissions Question
  Total Accepted: 47300 Total Submissions: 207778 Difficulty: Easy
  Description:

  Count the number of prime numbers less than a non-negative number, n.

  Credits:
  Special thanks to @mithmatt for adding this problem and creating all test cases.

  Show Hint

  */
  vector <bool> NumVec(n, true);
  int PrimeCnt = 0;
  int size = sqrt(n);
  NumVec[0] = false;
  NumVec[1] = false;
  for (int i = 0; i < size + 1; i++){
    if (NumVec[i] == false) continue;
    for (int j = i*i; j < n; j = j + i){
      if (NumVec[j])
        NumVec[j] = false;
    }
  }
  return count(NumVec.begin(), NumVec.end(), true);
}

bool isIsomorphic(string s, string t) {
  /*
  205. Isomorphic Strings My Submissions Question
  Total Accepted: 41960 Total Submissions: 150426 Difficulty: Easy
  Given two strings s and t, determine if they are isomorphic.

  Two strings are isomorphic if the characters in s can be replaced to get t.

  All occurrences of a character must be replaced with another character while preserving the order of characters.
  No two characters may map to the same character but a character may map to itself.

  For example,
  Given "egg", "add", return true.

  Given "foo", "bar", return false.

  Given "paper", "title", return true.
  */
  char map_s[128] = { 0 };
  char map_t[128] = { 0 };
  int len = s.size();
  for (int i = 0; i < len; ++i)
  {
    if (map_s[s[i]] != map_t[t[i]]) return false;
    map_s[s[i]] = i + 1;
    map_t[t[i]] = i + 1;
  }
  return true;
}

int hIndexSort(vector<int>& citations) {
  /*
274. H-Index My Submissions Question
Given an array of citations (each citation is a non-negative integer) of a
researcher, write a function to compute the researcher's h-index.

According to the definition of h-index on Wikipedia: "A scientist has index h
if h of his/her N papers have at least h citations each, and the other N − h
papers have no more than h citations each."

For example, given citations = [3, 0, 6, 1, 5], which means the researcher has
5 papers in total and each of them had received 3, 0, 6, 1, 5 citations
respectively. Since the researcher has 3 papers with at least 3 citations each
and the remaining two with no more than 3 citations each, his h-index is 3.

Note: If there are several possible values for h, the maximum one is taken as
the h-index.
*/
    sort(citations.begin(), citations.end());
    int len = citations.size();
    for (int i = 0; i < len; i++){
        if (citations[i] >= len - i) return len - i;

    }
    return 0;

}

int hIndexNoSort(vector<int>& citations) {
  int n = citations.size(), h = 0;
  int* counts = new int[n + 1]();
  for (int c : citations)
    counts[min(c, n)]++;
  for (int i = n; i; i--) {
    h += counts[i];
    if (h >= i) return i;
  }
  return h;
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
  /*
  49. Group Anagrams My Submissions Question
  Total Accepted: 61093 Total Submissions: 235826 Difficulty: Medium
  Given an array of strings, group anagrams together.

  For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],
  Return:

  [
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
  ]
  */
  unordered_map<string, multiset<string>> mp;
  for (string s : strs) {
    string t = s;
    sort(t.begin(), t.end());
    mp[t].insert(s);
  }
  vector<vector<string>> anagrams;
  for (auto m : mp) {
    vector<string> anagram(m.second.begin(), m.second.end());
    anagrams.push_back(anagram);
  }
  return anagrams;
}

vector<vector<string>> groupAnagramsCountSort(vector<string>& strs) {
  unordered_map<string, multiset<string>> mp;
  for (string s : strs) {
    string t = HT::strSort(s);
    mp[t].insert(s);
  }
  vector<vector<string>> anagrams;
  for (auto m : mp) {
    vector<string> anagram(m.second.begin(), m.second.end());
    anagrams.push_back(anagram);
  }
  return anagrams;
}

string HT::strSort(string& s) {
    // ??
  int count[26] = { 0 }, n = s.length();
  for (int i = 0; i < n; i++)
    count[s[i] - 'a']++;
  int p = 0;
  string t(n, 'a');
  for (int j = 0; j < 26; j++)
  for (int i = 0; i < count[j]; i++)
    t[p++] += j;
  return t;
}

int lengthOfLongestSubstring(string s) {
  /*
  3. Longest Substring Without Repeating Characters
  Total Accepted: 118525 Total Submissions: 559839 Difficulty: Medium
  Given a string, find the length of the longest substring without repeating characters.
  For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3.
  For "bbbbb" the longest substring is "b", with the length of 1.

  Subscribe to see which companies asked this question
  */

  /*
  the basic idea is, keep a hashmap which stores the characters in string as keys and their positions as values,
  and keep two pointers which define the max substring. move the right pointer to scan through the string ,
  and meanwhile update the hashmap. If the character is already in the hashmap,
  then move the left pointer to the right of the same character last found. Note that the two pointers can only move forward.
  */
  map<char, int> charMap;
  int start = -1;
  int maxLen = 0;

  for (int i = 0; i < s.size(); i++) {
    if (charMap.count(s[i]) != 0) {
      start = max(start, charMap[s[i]]);
    }
    charMap[s[i]] = i;
    maxLen = max(maxLen, i - start);
  }
  /*
  i = 0 start = -1 s[i] = a i - start : 1 maxLen = 1
  i = 1 start = -1 s[i] = b i - start : 2 maxLen = 2
  i = 2 start = -1 s[i] = c i - start : 3 maxLen = 3
  i = 3 start = 0  s[i] = a i - start : 3 maxLen = 3
  i = 4 start = 0  s[i] = d i - start : 4 maxLen = 4
  i = 5 start = 3  s[i] = a i - start : 2 maxLen = 4
  i = 6 start = 3  s[i] = e i - start : 3 maxLen = 4


  */

  return maxLen;

}

int lengthOfLongestSubstringNoMap(string s) {
        vector<int> dict(256, -1);
        int maxLen = 0, start = -1;
        for (int i = 0; i != s.length(); i++) {
            if (dict[s[i]] > start)
                start = dict[s[i]];
            dict[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }

int lengthOfLongestSubstringDP(string s) {
  /**
  * Solution (DP, O(n)):
  *
  * Assume L[i] = s[m...i], denotes the longest substring without repeating
  * characters that ends up at s[i], and we keep a hashmap for every
  * characters between m ... i, while storing <character, index> in the
  * hashmap.
  * We know that each character will appear only once.
  * Then to find s[i+1]:
  * 1) if s[i+1] does not appear in hashmap
  *    we can just add s[i+1] to hash map. and L[i+1] = s[m...i+1]
  * 2) if s[i+1] exists in hashmap, and the hashmap value (the index) is k
  *    let m = max(m, k), then L[i+1] = s[m...i+1], we also need to update
  *    entry in hashmap to mark the latest occurency of s[i+1].
  *
  * Since we scan the string for only once, and the 'm' will also move from
  * beginning to end for at most once. Overall complexity is O(n).
  *
  * If characters are all in ASCII, we could use array to mimic hashmap.
  */

  // for ASCII char sequence, use this as a hashmap
  vector<int> charIndex(256, -1);
  int longest = 0, m = 0;

  for (int i = 0; i < s.length(); i++) {
    m = max(charIndex[s[i]] + 1, m);    // automatically takes care of -1 case
    charIndex[s[i]] = i;
    longest = max(longest, i - m + 1);
  }

  return longest;
}

int singleNumber(vector<int>& nums) {
  /*
  136. Single Number My Submissions Question
  Total Accepted: 107946 Total Submissions: 225178 Difficulty: Medium
  Given an array of integers, every element appears twice except for one. Find that single one.

  Note:
  Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

  Subscribe to see which companies asked this question
  */
  /*
  Logic: XOR will return 1 only on two different bits. So if two numbers are the same, XOR will return 0. Finally only one number left. A ^ A = 0 and A ^ B ^ A = B.
  */
  int result = nums[0];
  int n = nums.size();
  for (int i = 1; i < n; i++)
  {
    result = result^nums[i];  /* Get the xor of all elements */
  }
  return result;
}

vector<int> inorderTraversal(TreeNode* root) {
  /*
  94. Binary Tree Inorder Traversal My Submissions Question
  Total Accepted: 103707 Total Submissions: 271442 Difficulty: Medium
  Given a binary tree, return the inorder traversal of its nodes' values.

  For example:
  Given binary tree {1,#,2,3},
  1
  \
  2
  /
  3
  return [1,3,2].

  Note: Recursive solution is trivial, could you do it iteratively?

  confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
  */
  vector<int> nodes;
  stack<TreeNode*> toVisit;
  TreeNode* curNode = root;
  while (curNode || !toVisit.empty()) {
    if (curNode) {
      toVisit.push(curNode);
      curNode = curNode->left;
    }
    else {
      curNode = toVisit.top();
      toVisit.pop();
      nodes.push_back(curNode->val);
      curNode = curNode->right;
    }
  }
  return nodes;
}

void HT::inorder(TreeNode* root, vector<int>& nodes) {
  if (!root) return;
  inorder(root->left, nodes);
  nodes.push_back(root->val);
  inorder(root->right, nodes);
}

vector<int> inorderTraversalRecurr(TreeNode* root) {
  vector<int> nodes;
  HT::inorder(root, nodes);
  return nodes;
}

RandomListNode *HT::copyRandomList(RandomListNode *head) {
  /*
  138. Copy List with Random Pointer My Submissions Question
  Total Accepted: 55932 Total Submissions: 216661 Difficulty: Hard
  A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

  Return a deep copy of the list.

  Subscribe to see which companies asked this question
  */

  RandomListNode *newhead = new RandomListNode(-1);
  RandomListNode *tra;
  newhead->next = head;
  for (tra = head; tra != NULL;){
    RandomListNode *newNode = new RandomListNode(tra->label);
    RandomListNode *newPos;
    if (tra->next == NULL) newPos = NULL;
    else newPos = tra->next->next;
    newNode->next = tra->next;
    tra->next = newNode;
    tra = newPos;
  }
  for (tra = head; tra != NULL; tra = tra->next->next){
    if (tra->random != NULL)
      tra->next->random = tra->random->next;
    else
      tra->next->random = NULL;
  }
  RandomListNode *retHead = new RandomListNode(-1);
  RandomListNode *retTra = retHead;
  for (tra = head; tra != NULL;){
    if (retHead->next = NULL){
      retTra = tra->next;
      tra->next = retTra->next;
      tra = tra->next;
      retHead->next = retTra;
      retTra->next = NULL;
    }
    else{
      retTra->next = tra->next;
      tra = tra->next->next;
      retTra->next->next = NULL;
      retTra = retTra->next;

    }
  }
  return retHead->next;
}

RandomListNode *copyRandomListMethod1(RandomListNode *head) {

  // Here's how the 1st algorithm goes.
  // Consider l1 as a node on the 1st list and l2 as the corresponding node on 2nd list.
  // Step 1:
  // Build the 2nd list by creating a new node for each node in 1st list.
  // While doing so, insert each new node after it's corresponding node in the 1st list.
  // Step 2:
  // The new head is the 2nd node as that was the first inserted node.
  // Step 3:
  // Fix the random pointers in the 2nd list: (Remember that l1->next is actually l2)
  // l2->random will be the node in 2nd list that corresponds l1->random,
  // which is next node of l1->random.
  // Step 4:
  // Separate the combined list into 2: Splice out nodes that are part of second list.
  // Return the new head that we saved in step 2.
  //
  RandomListNode *newHead, *l1, *l2;
  if (head == NULL) return NULL;
  for (l1 = head; l1 != NULL; l1 = l1->next->next) {
    l2 = new RandomListNode(l1->label);
    l2->next = l1->next;
    l1->next = l2;
  }

  newHead = head->next;
  for (l1 = head; l1 != NULL; l1 = l1->next->next) {
    if (l1->random != NULL) l1->next->random = l1->random->next;
  }

  for (l1 = head; l1 != NULL; l1 = l1->next) {
    l2 = l1->next;
    l1->next = l2->next;
    if (l2->next != NULL) l2->next = l2->next->next;
  }

  return newHead;
}

RandomListNode *copyRandomListMethod2(RandomListNode *head) {
  //
  // Here's how the 2nd algorithm goes.
  // Consider l1 as a node on the 1st list and l2 as the corresponding node on 2nd list.
  // Step 1:
  // Build the 2nd list by creating a new node for each node in 1st list.
  // While doing so, set the next pointer of the new node to the random pointer
  // of the corresponding node in the 1st list.  And set the random pointer of the
  // 1st list's node to the newly created node.
  // Step 2:
  // The new head is the node pointed to by the random pointer of the 1st list.
  // Step 3:
  // Fix the random pointers in the 2nd list: (Remember that l1->random is l2)
  // l2->random will be the node in 2nd list that corresponds to the node in the
  // 1st list that is pointed to by l2->next,
  // Step 4:
  // Restore the random pointers of the 1st list and fix the next pointers of the
  // 2nd list. random pointer of the node in 1st list is the next pointer of the
  // corresponding node in the 2nd list.  This is what we had done in the
  // 1st step and now we are reverting back. next pointer of the node in
  // 2nd list is the random pointer of the node in 1st list that is pointed to
  // by the next pointer of the corresponding node in the 1st list.
  // Return the new head that we saved in step 2.
  //
  RandomListNode *newHead, *l1, *l2;
  if (head == NULL) return NULL;

  for (l1 = head; l1 != NULL; l1 = l1->next) {
    l2 = new RandomListNode(l1->label);
    l2->next = l1->random;
    l1->random = l2;
  }

  newHead = head->random;
  for (l1 = head; l1 != NULL; l1 = l1->next) {
    l2 = l1->random;
    l2->random = l2->next ? l2->next->random : NULL;
  }

  for (l1 = head; l1 != NULL; l1 = l1->next) {
    l2 = l1->random;
    l1->random = l2->next;
    l2->next = l1->next ? l1->next->random : NULL;
  }

  return newHead;
}

int row[9][256], col[9][256], cube[3][3][256];

void solveSudoku(vector<vector<char>>& board) {
  /*
  37. Sudoku Solver My Submissions Question
  Total Accepted: 43640 Total Submissions: 183744 Difficulty: Hard
  Write a program to solve a Sudoku puzzle by filling the empty cells.

  Empty cells are indicated by the character '.'.

  You may assume that there will be only one unique solution.
  */

  memset(row, 0, sizeof(row));
  memset(col, 0, sizeof(col));
  memset(cube, 0, sizeof(col));

  // hash the already existing cell values
  for (int r = 0; r < 9; r++) {
    for (int c = 0; c < 9; c++) {
      if (board[r][c] != '.') {
        int d = board[r][c];
        row[r][d] = 1; col[c][d] = 1; cube[r / 3][c / 3][d] = 1;
      }
    }
  }

  HT::solveSudokuSub(board, 0, 0);
}

bool check(vector<vector<char>>& board, int r, int c, char val) {
  if (row[r][val] == 1) return false;
  if (col[c][val] == 1) return false;
  if (cube[r / 3][c / 3][val] == 1) return false;
  return true;
}

bool HT::solveSudokuSub(vector<vector<char>> &board, int i, int j) {
  if (i == 9) return true;
  if (j == 9) return HT::solveSudokuSub(board, i + 1, 0);
  if (board[i][j] != '.') return HT::solveSudokuSub(board, i, j + 1);

  for (char d = '1'; d <= '9'; d++)
  {
    if (check(board, i, j, d))
    {
      board[i][j] = d;
      row[i][d] = 1; col[j][d] = 1; cube[i / 3][j / 3][d] = 1;  // hash the digit 'd'
      if (HT::solveSudokuSub(board, i, j + 1)) return true;
      board[i][j] = '.';
      row[i][d] = 0; col[j][d] = 0; cube[i / 3][j / 3][d] = 0;  // unhash the digit 'd'
    }
  }

  return false;
}

string fractionToDecimal(int numerator, int denominator) {
    /**********************************************************************************
     *
     * Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
     *
     * If the fractional part is repeating, enclose the repeating part in parentheses.
     *
     * For example,
     *
     * Given numerator = 1, denominator = 2, return "0.5".
     * Given numerator = 2, denominator = 1, return "2".
     * Given numerator = 2, denominator = 3, return "0.(6)".
     *
     * Credits:Special thanks to @Shangrila for adding this problem and creating all test cases.
     *
     **********************************************************************************/

    string result;
    //deal with the `ZERO` cases
    if (denominator == 0){ return result; }
    if (numerator == 0) { return "0"; }

    //using long long type make sure there has no integer overflow
    long long n = numerator;
    long long d = denominator;

    //deal with negtive cases
    bool sign = ((float)numerator/denominator >= 0);
    if ( n < 0 ){ n = -n; }
    if ( d < 0 ){ d = -d; }
    if (sign == false){
        result.push_back('-');
    }

    long long remainder = n % d;
    long long division = n / d;
    ostringstream oss;
    oss << division;
    result += oss.str();
    if (remainder == 0) return result;

    //remainder has value, the result is a float
    result.push_back('.');

    /*
    using a map to record all of reminders and their position.
    if the reminder appeared before, which means the repeated loop begin,
    then, get the place from map to insert "(".
    (In C++11, it's better to use unordered_map )
    */

    map<long long, int> rec;

    // d is denominator
    for (int pos=result.size(); remainder!=0; pos++, remainder=(remainder*10)%d ) {
        if (rec.find(remainder) != rec.end()) {
            result.insert(result.begin()+rec[remainder], '(');
            result.push_back(')');
            return result;
        }
        rec[remainder] = pos;
        result.push_back((remainder*10)/d + '0');
    }

    return result;
}

vector<string> findRepeatedDnaSequences(string s) {

    /**********************************************************************************
     *
     * All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T,
     *
     * For example: "ACGAATTCCG".
     * When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.
     *
     * Write a function to find all the 10-letter-long sequences (substrings) that
     * occur more than once in a DNA molecule.
     *
     * For example,
     *
     * Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",
     *
     * Return:
     * ["AAAAACCCCC", "CCCCCAAAAA"].
     *
     *
     **********************************************************************************/

    unordered_map<size_t, int> stat;
    hash<string> hash_func;
    int MAX_LEN = 10;

    vector<string> result;

    for( int i=0; i+MAX_LEN<=s.size(); i++ ){
        string word = s.substr(i, MAX_LEN);
        size_t hash_code = hash_func(word);
        stat[hash_code]++;
        if (stat[hash_code]==2){
            result.push_back(word);
        }
    }
    return result;
}

int largestRectangleAreaMR(vector<int> &height) {

    if (height.size()<=0) return 0;

    height.push_back(0);
    vector<int> stack;
    int maxArea=0;

    for(int i=0; i<height.size(); ){
        if (stack.size()==0 || height[i] >= height[ stack.back() ] ){
            stack.push_back(i);
            i++;
        }else{
            int topIdx = stack.back();
            stack.pop_back();
            int area = height[topIdx] * ( stack.size()==0 ? i  : i - stack.back() - 1 );
            if (area > maxArea){
                maxArea = area;
            }
        }
    }
    return maxArea;
}

int maximalRectangle(vector<vector<char> > &matrix) {
    /**********************************************************************************
     *
     85. Maximal Rectangle
     * Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle
     * containing all ones and return its area.
     *
     **********************************************************************************/

    if (matrix.size()<=0 || matrix[0].size()<=0) return 0;
    int row = matrix.size();
    int col = matrix[0].size();
    vector< vector<int> > heights(row, vector<int>(col));

    int maxArea = 0;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++) {
            if (matrix[i][j]=='1'){
                heights[i][j] = (i==0 ? 1 : heights[i-1][j] + 1);
            }
        }
        int area = largestRectangleAreaMR(heights[i]);
        if (area > maxArea){
            maxArea = area;
        }
    }
    return maxArea;
}

