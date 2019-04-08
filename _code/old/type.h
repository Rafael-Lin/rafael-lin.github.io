#include<vector>
#include"stdafx.h"
#include<string>
//using std;
#ifndef TYPE_FILE 
#define TYPE_FILE
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) :val(x), next(NULL){}
};

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};
struct TreeLinkNode{
  int val;
  TreeLinkNode *left;
  TreeLinkNode *right;
  TreeLinkNode *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL),next(NULL) {}


};
struct RandomListNode {
  int label;
  RandomListNode *next, *random;
  RandomListNode(int x) : label(x), next(NULL), random(NULL) {}

};

class TrieNode {
public:
  bool isKey;
  TrieNode* children[26];
  TrieNode() : isKey(false) {
    memset(children, NULL, sizeof(TrieNode*)* 26);
  }
};
struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

#endif
