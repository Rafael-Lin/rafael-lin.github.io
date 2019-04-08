
#include<vector>
#include"stdafx.h"
#include<string>
#include"type.h"
using std::vector;
using std::string;

#ifndef DC_FILE
#define DC_FILE
static class DC
{
public:

  DC();

  static vector<vector<int>> combine(int n, int k);
  static void combine(vector<vector<int> > &res, vector<int> &temp, int start, int num, int n, int k);

  static vector<vector<int> > permute(vector<int> &num);

  static void permuteRecursive(vector<int> &num, int begin, vector<vector<int> > &result);

};

#endif
