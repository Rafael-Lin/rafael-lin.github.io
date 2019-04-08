// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "rotateArray.h"
#include "PT.h"
#include "MT.h"
#include "String.h"
#include "HT.h"
#include "Stack.h"
#include "DP.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int inStreamExample() {

  string stringvalues = "125 320 512 750 333";
  istringstream iss(stringvalues);

  for (int n = 0; n<5; n++)
  {
    int val;
    iss >> val;
    std::cout << val * 2 << '\n';
  }

  return 0;
}

void HTUnitTest()
{

  string pattern = "abba";
  string str = "dog cat cat dog";
  //int h = HT::countPrimes(5)

}

void ArrayUnitTest()
{
  int array[5] = { 0, 1, 0, 3, 12 };
  int array1[9] = { -1, 0, 0, 3, 3, 3, 0, 0, 0 };
  int array2[3] = { 1, 2, 2 };
  int array3[8] = { 2, 3, 1, 2, 4, 3, 1, 2 };
  int array4[1] = { 0 };
  int array5[6] = { 1, 1, 1, 2, 2, 3 };
  int array6[10] = { 0, 1, 3, 4, 5, 6, 7, 8, 9, 10 };
  int array7[4] = { 1, 2, 3, 4 };
  int array11[10] = { 1, 1, 1, 1, 1, 1, 2, 2, 2, 3 };
  vector<int> testV1(array1, array1 + sizeof(array1) / sizeof(array1[0]));
  vector<int> testV2(array2, array2 + sizeof(array2) / sizeof(array2[0]));
  vector<int> testV3(array3, array3 + sizeof(array3) / sizeof(array3[0]));
  vector<int> testV4(array4, array4 + 1);
  vector<int> testV5(array5, array5 + 6);
  vector<int> testV11(array11, array11 + 10);
  vector<int> test;
  vector<vector<int>> testV6;
  vector<int> testV7(array6, array6 + 10);
  vector<int> testV8(array7, array7 + 4);
  vector<int> testV9{ 1, 2 };

}

void StackUnitTest()
{
  string input = "cbacdcbc";
  string in = " 2-1 + 2 ";
  vector<int> vec{2, 1, 5, 6, 2, 3 };
  string output;
  output = StackT::removeDuplicateLetters(input);
  int r = StackT::calculate(in);
  int a = StackT::largestRectangleArea(vec);

}
void StringUnitTest()
{
  int t = ST::numDecodings("123");
    //printf(" t = %d\n", t);
  int s = ST::longestValidParentheses( "(()())" );

}
void DPUnitTest()
{
  vector<int> a = { 10, 9, 2, 5, 3, 7, 101, 18 };
  int r = DP::lengthOfLIS(a);

}
void PointerUnitTest()
{
  ListNode* node1 = new ListNode(1);
  ListNode* node2 = new ListNode(1);
  node1->next = node2;
  ListNode * ret = PT::partition(node1, 0);
}
void MathUnitTest()
{
  //vector<int> a = { 10, 9, 2, 5, 3, 7, 101, 18 };
  vector<int> a = { 3, 4, -1, 1 }; // 10, 9, 2, 5, 3, 7, 101, 18 };
  /*
  swap : 3, -1
  swap : 4, 1
  swap : 1, -1
  1 -1 3 4
  */
  int c = MT::firstMissingPositive(a);


}

int _tmain(int argc, _TCHAR* argv[])
{
  ArrayUnitTest();
  HTUnitTest();
  PointerUnitTest();
  StackUnitTest();
  StringUnitTest();
  DPUnitTest();
  MathUnitTest();
  getchar();

  return 0;
}

