
/*Rotate an array of n elements to the right by k steps.

  For example, with n = 7 and k = 3, the array[1, 2, 3, 4, 5, 6, 7] is rotated to[5, 6, 7, 1, 2, 3, 4].

Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
*/
#include<vector>
#include"stdafx.h"
#include<string>
#include"type.h"
using std::vector;
using std::string;

#ifndef PT_FILE 
#define PT_FILE

static class PT 
{
public:

  PT();
  static ListNode* reverseList(ListNode* head) ;
  static ListNode* reverseListRecurrsive(ListNode* head);

  static ListNode* removeNthFromEnd(ListNode* head, int n);

  static void deleteNode(ListNode* node);

  static ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);

  bool isPalindrome(ListNode* head);

  static ListNode* insertionSortList(ListNode* head);

  static void reorderList(ListNode* head);

  static ListNode* merge(ListNode* head1, ListNode * head2);

  static ListNode* PT::partition(ListNode* head, int x);
};


#endif
