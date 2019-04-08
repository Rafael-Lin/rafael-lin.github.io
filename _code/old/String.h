#include<vector>
#include"stdafx.h"
#include<string>
#include"type.h"
using std::vector;
using std::string;

#ifndef ST_FILE
#define ST_FILE

static class ST
{
public:
  ST();

  static int check(char ch);
  static int check(char ch1, char ch2);
  static int numDecodings(string s) ;

  static int longestValidParentheses(string s);

};


#endif
