#include<vector>
#include"stdafx.h"
#include<string>
#include"type.h"
using std::vector;
using std::string;

#ifndef STACK_FILE 
#define STACK_FILE


static class StackT 
{
public:
  StackT();
  static string StackT::removeDuplicateLetters(string s);
  static int StackT::calculate(string s);

  static void build(TreeNode* n, vector<vector<int>>& R, int d);
  static int largestRectangleArea(vector<int>& height);

  static void preTraversal(TreeNode* root, vector<int>& v);
};

#endif
