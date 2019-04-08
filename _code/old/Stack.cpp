#include "stdafx.h"
#include "Stack.h"
#include <string>
#include <iostream>
#include <sstream>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
#include<ctime>
#include<iostream>
#include<set>
#include<unordered_map>
#include<unordered_set>

//#include<numeric>
#define GUARD -10000

using namespace std;

// C:\work\Algo\NewSession\ConsoleApplication1\Debug

StackT::StackT() {


}


class Queue {

  /*
  232. Implement Queue using Stacks My Submissions Question
  Total Accepted: 30037 Total Submissions: 88622 Difficulty: Easy
  Implement the following operations of a queue using stacks.

  push(x) -- Push element x to the back of queue.
  pop() -- Removes the element from in front of queue.
  peek() -- Get the front element.
  empty() -- Return whether the queue is empty.
  Notes:
  You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
  Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
  You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).
  */

private:
  stack<int> m_stack_back;
  stack<int> m_stack_front;
public:
  // Push element x to the back of queue.
  void push(int x) {
    m_stack_back.push(x);
  }

  // Removes the element from in front of queue.
  void pop(void) {
    if (m_stack_front.empty())
      this->move_back_2_front();
    m_stack_front.pop();
  }

  // Get the front element.
  int peek(void) {
    if (m_stack_front.empty())
      this->move_back_2_front();

    return m_stack_front.top();
  }

  // Return whether the queue is empty.
  bool empty(void) {
    return m_stack_back.empty() && m_stack_front.empty();
  }

private:
  void move_back_2_front(){
    while (!m_stack_back.empty()){
      m_stack_front.push(m_stack_back.top());
      m_stack_back.pop();
    }
  }
};

class MinStack {
  /*
  155. Min Stack My Submissions Question
  Total Accepted: 58492 Total Submissions: 274737 Difficulty: Easy
  Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

  push(x) -- Push element x onto stack.
  pop() -- Removes the element on top of the stack.
  top() -- Get the top element.
  getMin() -- Retrieve the minimum element in the stack.
  Subscribe to see which companies asked this question

  Show Tags
  Show Similar Problems

  */
private:
  stack<int> s1;
  stack<int> s2;
public:
  void push(int x) {
    s1.push(x);
    if (s2.empty() || x <= getMin())  s2.push(x);
  }
  void pop() {
    if (s1.top() == getMin())  s2.pop();
    s1.pop();
  }
  int top() {
    return s1.top();
  }
  int getMin() {
    return s2.top();
  }
};

class Stack {
public:
  queue<int> que;
  // 1,2,3
  // 1 -> 1
  // 1 2 -> 2,1
  // 2,1,3 -> 3,2,1
  // note : we could only que->front , to get the value in the queue
  // Push element x onto stack.
  void push(int x) {
    que.push(x);
    for (int i = 0; i < que.size() - 1; ++i){
      que.push(que.front());
      que.pop();
    }
  }

  // Removes the element on top of the stack.
  void pop() {
    que.pop();
  }

  // Get the top element.
  int top() {
    return que.front();
  }

  // Return whether the stack is empty.
  bool empty() {
    return que.empty();
  }
};

bool isValid(string s) {
  /*
  20. Valid Parentheses My Submissions Question
  Total Accepted: 88835 Total Submissions: 314406 Difficulty: Easy
  Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

  The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

  Subscribe to see which companies asked this question
  */

  stack<char> paren;
  for (char& c : s) {
    switch (c) {
    case '(':
    case '{':
    case '[': paren.push(c); break;
    case ')': if (paren.empty() || paren.top() != '(') return false; else paren.pop(); break;
    case '}': if (paren.empty() || paren.top() != '{') return false; else paren.pop(); break;
    case ']': if (paren.empty() || paren.top() != '[') return false; else paren.pop(); break;
    default:; // pass
    }
  }
  return paren.empty();
}


string StackT::removeDuplicateLetters(string s) {
  /*
  316. Remove Duplicate Letters My Submissions Question
  Total Accepted: 6199 Total Submissions: 27480 Difficulty: Medium
  Given a string which contains only lowercase letters, remove duplicate letters so that every letter appear once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

  Example:
  Given "bcabc"
  Return "abc"

  Given "cbacdcbc"
  Return "acdb"

  Credits:
  */
  /*
  Here is the explaination.

  the core idea is to keep the stack. and the stack is used to keep the current minimal char.
  if the next char is less than the top of stack ,then the top should be poped unless the top can not be poped.
  when can't we pop the top of stack ? the char is the last time to be seen in the raw string,
  cbadd -> we can't pop out c because it is the only one
  then we can't pop it.(that's the power of cnts which can be implemented in vector~ less time maybe.)
  */
  vector<int> cand(256, 0);
  vector<bool> visited(256, false);
  for (char c : s)
    cand[c]++;
  string result = "0";
  for (char c : s) {
    cand[c]--;
    if (visited[c]) continue;
    while (c < result.back() && cand[result.back()]) {
      // result.back() means the last element of the string 
      // if current char is smaller than the last char and cand[ last ] is more than one
      // remove the last element and set it as un-visited
      visited[result.back()] = false;
      result.pop_back();
    }
    result += c;
    visited[c] = true;
  }
  return result.substr(1);


}

int StackT::calculate(string s) {
  /*
  224. Basic Calculator My Submissions Question
  Total Accepted: 21158 Total Submissions: 103513 Difficulty: Medium
  Implement a basic calculator to evaluate a simple expression string.

  The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

  You may assume that the given expression is always valid.

  Some examples:
  "1 + 1" = 2
  " 2-1 + 2 " = 3
  "(1+(4+5+2)-3)+(6+8)" = 23
  Note: Do not use the eval built-in library function.

  Subscribe to see which companies asked this question
  */
  stack<int> nums;
  stack<int> ops;
  int num = 0;
  int rst = 0;
  int sign = 1;
  for (char c : s) {
    if (isdigit(c)) {
      num = num * 10 + c - '0';
    }
    else {
      rst += sign * num;
      num = 0;
      if (c == '+') sign = 1;
      if (c == '-') sign = -1;
      if (c == '(') {
        nums.push(rst);
        ops.push(sign);
        rst = 0;
        sign = 1;
      }
      if (c == ')' && ops.size()) {
        rst = ops.top() * rst + nums.top();
        ops.pop();
        nums.pop();
      }
    }
  }
  rst += sign * num;
  return rst;

}

int calculate(string s) {
  stack<char> ops;
  stack<int> nums;
  int curnum = 0;
  /*
  Yet another stack-based solution. Very similar to the solution given by @jiannan here with a few minor differences.

  The basic idea is to scan from left to right. Push every

  (, + and - to an 'operator' stack, and every number to an 'number' stack.

  In this process, whenever a RIGHT operand is added to the 'number' stack, we can do a computation using the top two numbers in the 'number' stack with the operation specified by the top of the operator stack.

  There are only two situations when a RIGHT operand appears in the number stack:
  1. A number that is the RIGHT operand, .e.g 4 as in 3 + 4, is pushed;
  2. A braced block that is the RIGHT operand, e.g. (4+5) as in 3 + (4 + 5), is terminated and its result is added to the number stack.

  How do we know if a number added is the RIGHT or LEFT operand? The idea is, whenever a RIGHT operand appears, there must be an unused '+' or '-' left in the 'operator' stack.
  */

  for (int i = 0; i < s.size(); ++i) {
    char c = s[i];
    if (c == ' ') continue;   // Skip spaces
    if (c == '(' || c == '+' || c == '-') { ops.push(c); continue; }  // Store these operators for later

    // Only do calculation when 1. a braced block is terminated, 2. When the second operand isn added
    if (c == ')') ops.pop();
    else if (isdigit(c)) {
      curnum = curnum * 10 + c - '0';
      if (i + 1 < s.size() && isdigit(s[i + 1])) continue;    //This number is not finished
      nums.push(curnum);      // Otherwise, this number is ready and must be pushed to stack
      curnum = 0;             // Reset cursum;
    }

    if (ops.empty() || ops.top() == '(') continue;    // If, however, there is no more computational operators in stack
    // then either we have just added the LEFT operand, or if the braced block just terminated is a LEFT operand.
    // Either way, we cannot do computation yet.
    // Otherwise, it is safe to do the computation, assuming the expression is always valid:

    int n2 = nums.top(); nums.pop();
    if (ops.top() == '+')
      nums.top() += n2;
    else if (ops.top() == '-')
      nums.top() -= n2;
    ops.pop();
  }
  return nums.top();
}

string simplifyPath(string path) {
  /*
  71. Simplify Path My Submissions Question
  Total Accepted: 44602 Total Submissions: 210435 Difficulty: Medium
  Given an absolute path for a file (Unix-style), simplify it.

  For example,
  path = "/home/", => "/home"
  path = "/a/./b/../../c/", => "/c"
  click to show corner cases.

  Corner Cases:
  Did you consider the case where path = "/../"?
  In this case, you should return "/".
  Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
  In this case, you should ignore redundant slashes and return "/home/foo".
  Subscribe to see which companies asked this question
  */
  string result = "", token;
  stringstream ss(path);
  vector<string> tokens;
  while (getline(ss, token, '/')){
    if (token == "." || token == "") continue;
    else if (token == ".."){
      if (tokens.size() != 0)  tokens.pop_back();
    }
    else tokens.push_back(token);
  }
  if (tokens.size() == 0) return "/";
  for (int i = 0; i < tokens.size(); ++i)
    result = result + '/' + tokens[i];
  return result;
}

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
  /*
  103. Binary Tree Zigzag Level Order Traversal My Submissions Question
  Total Accepted: 52093 Total Submissions: 188047 Difficulty: Medium
  Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

  For example:
  Given binary tree {3,9,20,#,#,15,7},
  3
  / \
  9  20
  /  \
  15   7
  return its zigzag level order traversal as:
  [
  [3],
  [20,9],
  [15,7]
  ]
  */
  if (root == NULL) {
    return vector<vector<int> >();
  }
  vector<vector<int> > result;

  queue<TreeNode*> nodesQueue;
  nodesQueue.push(root);
  bool leftToRight = true;

  while (!nodesQueue.empty()) {
    int size = nodesQueue.size();
    vector<int> row(size);
    for (int i = 0; i < size; i++) {
      TreeNode* node = nodesQueue.front();
      nodesQueue.pop();

      // find position to fill node's value
      int index = (leftToRight) ? i : (size - 1 - i);

      row[index] = node->val;
      if (node->left) {
        nodesQueue.push(node->left);
      }
      if (node->right) {
        nodesQueue.push(node->right);
      }
    }
    // after this level
    leftToRight = !leftToRight;
    result.push_back(row);
  }
  return result;

}

void StackT::build(TreeNode* n, vector<vector<int>>& R, int d) {
  if (!n) return;
  if (d == R.size()) R.push_back(vector<int>());
  R[d].push_back(n->val);
  StackT::build(n->left, R, d + 1);
  StackT::build(n->right, R, d + 1);
}

vector<vector<int>> zigzagLevelOrderRec(TreeNode* root) {
  vector<vector<int>> R;
  StackT::build(root, R, 0);
  for (int i = 1; i < R.size(); i += 2) reverse(R[i].begin(), R[i].end());
  return R;
}

class BSTIterator {
  /**
  * Your BSTIterator will be called like this:
  * BSTIterator i = BSTIterator(root);
  * while (i.hasNext()) cout << i.next();
  */
  /*
  173. Binary Search Tree Iterator My Submissions Question
  Total Accepted: 38208 Total Submissions: 116752 Difficulty: Medium
  Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

  Calling next() will return the next smallest number in the BST.

  Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.

  Credits:
  Special thanks to @ts for adding this problem and creating all test cases.

  Subscribe to see which companies asked this question
  */
private:
  stack<TreeNode*> st;
public:
  BSTIterator(TreeNode *root) {
    find_left(root);
  }

  /** @return whether we have a next smallest number */
  bool hasNext() {
    if (st.empty())
      return false;
    return true;
  }

  /** @return the next smallest number */
  int next() {
    TreeNode* top = st.top();
    st.pop();
    if (top->right != NULL)
      find_left(top->right);

    return top->val;
  }

  /** put all the left child() of root */
  void find_left(TreeNode* root)
  {
    TreeNode* p = root;
    while (p != NULL)
    {
      st.push(p);
      p = p->left;
    }
  }
};

int eval_expression(vector<string>& tokens, int& pt)
{

  /*
  150. Evaluate Reverse Polish Notation My Submissions Question
  Total Accepted: 58118 Total Submissions: 255948 Difficulty: Medium
  Evaluate the value of an arithmetic expression in Reverse Polish Notation.

  Valid operators are +, -, *, /. Each operand may be an integer or another expression.

  Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
  */
  string s = tokens[pt];

  if (s == "+" || s == "-" || s == "*" || s == "/") // tokens[r] is an operator
  {
    pt--;
    int v2 = eval_expression(tokens, pt);
    pt--;
    int v1 = eval_expression(tokens, pt);
    if (s == "+")
      return v1 + v2;
    else if (s == "-")
      return v1 - v2;
    else if (s == "*")
      return v1 * v2;
    else
      return v1 / v2;
  }
  else // tokens[r] is a number
  {
    return atoi(s.c_str());
  }
}

int evalRPN(vector<string> &tokens) {
  int pt = tokens.size() - 1;
  return eval_expression(tokens, pt);
}

int evalRPNIter(vector<string> &tokens) {
  stack<int> st;
  int s1, s2;
  s1 = s2 = 0;
  int res = 0;
  for (vector<string>::iterator iter = tokens.begin(); iter != tokens.end(); iter++)
  {
    if (*iter == "+")
    {
      s1 = st.top();
      st.pop();
      s2 = st.top();
      st.pop();
      res = s1 + s2;
      st.push(res);
    }

    else if (*iter == "-")
    {
      s1 = st.top();
      st.pop();
      s2 = st.top();
      st.pop();
      res = s2 - s1;
      st.push(res);
    }
    else if (*iter == "*")
    {
      s1 = st.top();
      st.pop();
      s2 = st.top();
      st.pop();
      res = s1*s2;
      st.push(res);
    }
    else if (*iter == "/")
    {
      s1 = st.top();
      st.pop();
      s2 = st.top();
      st.pop();
      res = s2 / s1;
      st.push(res);
    }
    else
    {
      st.push(atoi((*iter).c_str()));
    }
  }
  return st.top();


}
vector<int> preorderTraversal(TreeNode *root) {
  if (root == NULL) {
    return vector<int>();
  }
  vector<int> result;
  stack<TreeNode *> treeStack;
  treeStack.push(root);
  while (!treeStack.empty()) {
    TreeNode *temp = treeStack.top();
    result.push_back(temp->val);
    treeStack.pop();
    if (temp->right != NULL) {
      treeStack.push(temp->right);
    }
    if (temp->left != NULL) {
      treeStack.push(temp->left);
    }
  }
  return result;
}
// recursive, but it's trivial...
vector<int> preorderTraversalRec(TreeNode* root) {
  vector<int> v;
  StackT::preTraversal(root, v);
  return v;
}
void StackT::preTraversal(TreeNode* root, vector<int>& v){
  if (!root) return;
  v.push_back(root->val);
  StackT::preTraversal(root->left, v);
  StackT::preTraversal(root->right, v);
}

int StackT::largestRectangleArea(vector<int>& height) {
  /*
  84. Largest Rectangle in Histogram My Submissions Question
  Total Accepted: 52865 Total Submissions: 224569 Difficulty: Hard
  Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.


  Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].


  The largest rectangle is shown in the shaded area, which has area = 10 unit.

  For example,
  Given heights = [2,1,5,6,2,3],
  return 10.
  */
  height.push_back(0);
  int n = height.size(), area = 0;
  stack<int> indice;
  for (int i = 0; i < n; i++) {
    while (!indice.empty() && height[indice.top()] > height[i]) {
      int h = height[indice.top()]; 
      indice.pop();
      int l = indice.empty() ? -1 : indice.top();
      area = max(area, h * (i - l - 1));
    }
    indice.push(i);
  }
  return area;
}

int largestRectangleArea(vector<int>& height) {
  /*
  1) Create an empty stack.

  2) Start from first bar, and do following for every bar ‘hist[i]’ where ‘i’ varies from 0 to n-1.
  a) If stack is empty or hist[i] is higher than the bar at top of stack, then push ‘i’ to stack.
  b) If this bar is smaller than the top of stack, then keep removing the top of stack while top of the stack is greater. 
  Let the removed bar be hist[tp]. Calculate area of rectangle with hist[tp] as smallest bar. 
  For hist[tp], the ‘left index’ is previous (previous to tp) item in stack and ‘right index’ is ‘i’ (current index).

  3) If the stack is not empty, then one by one remove all bars from stack and do step 2.b for every removed bar.
  */
  height.push_back(0);
  const int size_h = height.size();
  stack<int> stk;
  int i = 0, max_a = 0;
  while (i < size_h) {
    if (stk.empty() || height[i] >= height[stk.top()]) stk.push(i++);
    else {
      int h = stk.top();
      stk.pop();
      max_a = max(max_a, height[h] * (stk.empty() ? i : i - stk.top() - 1));
    }
  }
  return max_a;
}

// http://www.geeksforgeeks.org/largest-rectangle-under-histogram/

int getMaxArea(int hist[], int n){
  // Create an empty stack. The stack holds indexes of hist[] array
  // The bars stored in stack are always in increasing order of their
  // heights.
  stack<int> s;

  int max_area = 0; // Initalize max area
  int tp;  // To store top of stack
  int area_with_top; // To store area with top bar as the smallest bar

  // Run through all bars of given histogram
  int i = 0;
  while (i < n)
  {
    // If this bar is higher than the bar on top stack, push it to stack
    if (s.empty() || hist[s.top()] <= hist[i])
      s.push(i++);

    // If this bar is lower than top of stack, then calculate area of rectangle 
    // with stack top as the smallest (or minimum height) bar. 'i' is 
    // 'right index' for the top and element before top in stack is 'left index'
    else
    {
      tp = s.top();  // store the top index
      s.pop();  // pop the top

      // Calculate the area with hist[tp] stack as smallest bar
      area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);

      // update max area, if needed
      if (max_area < area_with_top)
        max_area = area_with_top;
    }
  }

  // Now pop the remaining bars from stack and calculate area with every
  // popped bar as the smallest bar
  while (s.empty() == false)
  {
    tp = s.top();
    s.pop();
    area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);

    if (max_area < area_with_top)
      max_area = area_with_top;
  }

  return max_area;
}

#if 0
int largestRectangleArea(vector<int> &height) {
    /*
       84. Largest Rectangle in Histogram My Submissions Question
       Total Accepted: 53400 Total Submissions: 226376 Difficulty: Hard
       Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.


       Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].


       The largest rectangle is shown in the shaded area, which has area = 10 unit.

       For example,
       Given heights = [2,1,5,6,2,3],
       return 10.

       Subscribe to see which companies asked this question*
       */

        int n=height.size();
        if(n==0) return 0;
        if(n==1) return height[0];

        height.push_back(0);
        n++;

        int ans=0;
        stack<int> s;

        int i=0,j=0,h=0;
        while(i<n){
            if(s.empty() || height[i]>height[s.top()]) s.push(i++);
            else{
                h=height[s.top()];
                s.pop();
                j= s.empty() ? -1:s.top();
                ans=max(ans,h*(i-j-1));
            }
        }
        return ans;
    }

#endif