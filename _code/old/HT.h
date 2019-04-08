#include<vector>
#include"stdafx.h"
#include<string>
#include"type.h"
using std::vector;
using std::string;

#ifndef HT_FILE
#define HT_FILE
static class HT
{
public:

  HT();

  static bool wordPattern(string pattern, string str);
  static int HT::countPrimes(int n);

  static void inorder(TreeNode* root, vector<int>& nodes);
  static string HT::strSort(string& s);
  static vector<string> findRepeatedDnaSequences(string s);

  static RandomListNode *copyRandomList(RandomListNode *head);

  static bool solveSudokuSub(vector<vector<char>> &board, int i, int j);
};

#endif
