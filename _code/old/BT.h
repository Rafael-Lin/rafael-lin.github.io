
#include<vector>
#include"stdafx.h"
#include<string>
#include"type.h"
using std::vector;
using std::string;

#ifndef BT_FILE
#define BT_FILE
static class BT
{
public:

  BT();

  static vector<vector<int>> combine(int n, int k);
  static void combine(vector<vector<int> > &res, vector<int> &temp, int start, int num, int n, int k);

  static vector<vector<int> > permute(vector<int> &num);

  static void permuteRecursive(vector<int> &num, int begin, vector<vector<int> > &result);

};

#endif
