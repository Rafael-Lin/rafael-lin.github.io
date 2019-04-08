#include "stdafx.h"
#include "PT.h"
#include "string"
#include<algorithm>
#include<vector>
#include<ctime>
#include<iostream>
#include<set>
#include"type.h"
#include<unordered_map>
#include<unordered_set>

//#include<numeric>
#define GUARD -10000

using namespace std;

// C:\work\Algo\NewSession\ConsoleApplication1\Debug

/*
// don't understand
// 1. nullptr
// 2. find_if
// 3. test_items_.push_back(std::shared_ptr<TestItem>(new TestItem(value)));
// 4. map _map.at(xx);
ANS : Access element
Returns a reference to the mapped value of the element identified with key k.
If k does not match the key of any element in the container, the function throws an out_of_range exception.
*/

PT::PT() {

}

ListNode* PT::reverseList(ListNode* head) {

  /*
  206. Reverse Linked List My Submissions Question
  Total Accepted: 72657 Total Submissions: 196505 Difficulty: Easy
  Reverse a singly linked list.
  */
  ListNode *prev = NULL, *cur = head, *tmp;
  while (cur){
    tmp = cur->next;
    cur->next = prev;
    prev = cur;
    cur = tmp;
  }
  return prev;
}

ListNode* PT::reverseListRecurrsive(ListNode* head) {
  if (!head || !(head->next))  return head;
  auto res = reverseListRecurrsive(head->next);
  head->next->next = head;
  head->next = NULL;
  return res;
}

ListNode* PT::removeNthFromEnd(ListNode* head, int n) {

  /*
  19. Remove Nth Node From End of List My Submissions Question
  Total Accepted: 88527 Total Submissions: 314006 Difficulty: Easy
  Given a linked list, remove the nth node from the end of list and return its head.

  For example,

  Given linked list: 1->2->3->4->5, and n = 2.

  After removing the second node from the end, the linked list becomes 1->2->3->5.
  Note:
  Given n will always be valid.
  Try to do this in one pass.
  */
  ListNode *slow = head, *fast = head;
  while (n-- > 0) fast = fast->next;
  if (fast == NULL)return head->next;  // The head need to be removed, do it.
  fast = fast->next;

  while (fast != NULL){
    slow = slow->next;
    fast = fast->next;
  }
  slow->next = slow->next->next;   // the one after the slow need to be removed
  return head;
}

void PT::deleteNode(ListNode* node) {
  /*
  237. Delete Node in a Linked List My Submissions Question
  Total Accepted: 54020 Total Submissions: 123162 Difficulty: Easy
  Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.

  Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, the linked list should become 1 -> 2 -> 4 after calling your function.

  Subscribe to see which companies asked this question
  */
  ListNode *tmp = node;
  while (tmp->next != NULL){
    ListNode *n = tmp->next;
    tmp->val = n->val;
    if (tmp->next->next == NULL){
      tmp->next = NULL;
      break;
    }
    else
      tmp = n;
  }

}

ListNode* PT::mergeTwoLists(ListNode* l1, ListNode* l2) {
  /*
  21. Merge Two Sorted Lists My Submissions Question
  Total Accepted: 100668 Total Submissions: 295501 Difficulty: Easy
  Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

  Subscribe to see which companies asked this question
  */
  ListNode *ret = NULL;
  ListNode *retHead = NULL;
  while (l1 && l2){
    if (l1->val > l2->val){
      if (retHead == NULL){
        retHead = l2;
        l2 = l2->next;
        retHead->next = NULL;
        ret = retHead;
      }
      else{
        ret->next = l2;
        l2 = l2->next;
        ret = ret->next;
        ret->next = NULL;
      }
    }
    else{
      if (retHead == NULL){
        retHead = l1;
        l1 = l1->next;
        retHead->next = NULL;
        ret = retHead;
      }
      else{
        ret->next = l1;
        l1 = l1->next;
        ret = ret->next;
        ret->next = NULL;
      }

    }
  }
  while (l1){
    if (retHead == NULL){
      retHead = l1;
      l1 = l1->next;
      retHead->next = NULL;
      ret = retHead;
    }
    else{
      ret->next = l1;
      l1 = l1->next;
      ret = ret->next;
      ret->next = NULL;
    }
  }
  while (l2){
    if (retHead == NULL){
      retHead = l2;
      l2 = l2->next;
      retHead->next = NULL;
      ret = retHead;
    }
    else{
      ret->next = l2;
      l2 = l2->next;
      ret = ret->next;
      ret->next = NULL;
    }
  }
  return retHead;
}

bool PT::isPalindrome(ListNode* head) {
  /*
  234. Palindrome Linked List My Submissions Question
  Total Accepted: 33040 Total Submissions: 127358 Difficulty: Easy
  Given a singly linked list, determine if it is a palindrome.

  Follow up:
  Could you do it in O(n) time and O(1) space?

  Subscribe to see which companies asked this question
  */

  if (head == NULL || head->next == NULL)
    return true;
  ListNode* slow = head;
  ListNode* fast = head;
  while (fast->next != NULL&&fast->next->next != NULL){
    slow = slow->next;
    fast = fast->next->next;
  }
  slow->next = reverseList(slow->next);
  slow = slow->next;
  while (slow != NULL){
    if (head->val != slow->val)
      return false;
    head = head->next;
    slow = slow->next;
  }
  return true;
}

ListNode* deleteDuplicates(ListNode* head) {
  /*
  83. Remove Duplicates from Sorted List My Submissions Question
  Total Accepted: 94820 Total Submissions: 265285 Difficulty: Easy
  Given a sorted linked list, delete all duplicates such that each element appear only once.

  For example,
  Given 1->1->2, return 1->2.
  Given 1->1->2->3->3, return 1->2->3.

  Subscribe to see which companies asked this question
  */
  ListNode *tmp = head;
  if (head == NULL) return head;
  while (tmp->next != NULL){
    if (tmp->next->val == tmp->val && tmp->next->next != NULL){
      tmp->next = tmp->next->next;
      continue;
    }
    else if (tmp->next->val == tmp->val && tmp->next->next == NULL){
      tmp->next = NULL;
      break;
    }
    tmp = tmp->next;
  }
  return head;

}

ListNode* removeElements(ListNode* head, int val) {
  /*
  203. Remove Linked List Elements My Submissions Question
  Total Accepted: 46780 Total Submissions: 171173 Difficulty: Easy
  Remove all elements from a linked list of integers that have value val.

  Example
  Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
  Return: 1 --> 2 --> 3 --> 4 --> 5

  Credits:
  Special thanks to @mithmatt for adding this problem and creating all test cases.

  Subscribe to see which companies asked this question
  */
  ListNode *newhead = new ListNode(-1);
  newhead->next = head;
  ListNode *tmp = newhead->next;
  ListNode *pre = newhead;
  while (tmp != NULL){
    if (tmp->val == val){
      pre->next = tmp->next;
      tmp = tmp->next;
    }
    else{
      pre = tmp;
      tmp = tmp->next;
    }
  }
  return newhead->next;

}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

  /*
  160. Intersection of Two Linked Lists My Submissions Question
  Total Accepted: 57321 Total Submissions: 191630 Difficulty: Easy
  Write a program to find the node at which the intersection of two singly linked lists begins.


  For example, the following two linked lists:

  A:          a1 → a2
  ↘
  c1 → c2 → c3
  ↗
  B:     b1 → b2 → b3
  begin to intersect at node c1.


  Notes:

  If the two linked lists have no intersection at all, return null.
  The linked lists must retain their original structure after the function returns.
  You may assume there are no cycles anywhere in the entire linked structure.
  Your code should preferably run in O(n) time and use only O(1) memory.
  */

  if (!headA || !headB) return NULL;
  ListNode *tmp = headA;
  int TotalNodeNumA = 0;
  int TotalNodeNumB = 0;
  while (tmp != NULL){
    TotalNodeNumA++;
    tmp = tmp->next;
  }
  tmp = headB;
  while (tmp != NULL){
    TotalNodeNumB++;
    tmp = tmp->next;
  }
  ListNode *tmpb = headB;
  tmp = headA;
  if (TotalNodeNumA > TotalNodeNumB){
    int diff = TotalNodeNumA - TotalNodeNumB;
    for (int i = 0; i < diff; i++){
      tmp = tmp->next;
    }
  }
  else{
    int diff = TotalNodeNumB - TotalNodeNumA;
    for (int i = 0; i < diff; i++){
      tmpb = tmpb->next;
    }
  }
  while (tmp->val != tmpb->val){
    tmp = tmp->next;
    tmpb = tmpb->next;
    if (!tmp || !tmpb)
      return NULL;
  }
  return tmp;

}

ListNode* PT::insertionSortList(ListNode* head) {
  /*
  147. Insertion Sort List My Submissions Question
  Total Accepted: 61576 Total Submissions: 218398 Difficulty: Medium
  Sort a linked list using insertion sort.

  Subscribe to see which companies asked this question

  Show Tags
  Show Similar Problems
  */

  ListNode *fakeHead = new ListNode(INT_MIN);
  ListNode *tmp = head;
  while (tmp != NULL){
    ListNode *target = tmp;
    tmp = tmp->next;

    ListNode *traverse = fakeHead;
    if (traverse->next == NULL){
      traverse->next = target;
      target->next = NULL;
    }
    else{

      while (traverse->next != NULL){
        if (traverse->val <= target->val && traverse->next->val > target->val){
          target->next = traverse->next;
          traverse->next = target;
          break;
        }
        traverse = traverse->next;
      }
      if (traverse->next == NULL){
        traverse->next = target;
        target->next = NULL;
      }

    }
  }
  return fakeHead->next;
}

ListNode* deleteDuplicatesUnknown(ListNode* head) {
  if (!head) return NULL;
  ListNode* p = new ListNode(head->val - 1), *ptr = p, *pre = p;
  while (head) {
    if (pre->val != head->val
      && (!head->next || head->next->val != head->val)) {
      ptr->next = head;
      ptr = ptr->next;
    }
    pre = head;
    head = head->next;
  }
  ptr->next = NULL;
  return p->next;
}

/*
ListNode *detectCycle(ListNode *head) {
142. Linked List Cycle II My Submissions Question
Total Accepted: 64099 Total Submissions: 203683 Difficulty: Medium
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Note: Do not modify the linked list.

Follow up:
Can you solve it without using extra space?

Subscribe to see which companies asked this question
ListNode *n = new ListNode(100);
return n;

}
*/

ListNode* sortList(ListNode* head) {
  /*
  148. Sort List My Submissions Question
  Total Accepted: 61669 Total Submissions: 259682 Difficulty: Medium
  Sort a linked list in O(n log n) time using constant space complexity.

  Subscribe to see which companies asked this question
  */
  // space : O(logn)  space
  if (!head || !head->next) return head;
  ListNode* slow = head;
  ListNode* fast = head->next;
  while (fast && fast->next){         // to find middle node
    fast = fast->next->next;
    slow = slow->next;
  }
  ListNode* headb = slow->next;     // headb is start of 2nd half of list
  slow->next = NULL;
  return PT::merge(sortList(head), sortList(headb));
}

ListNode* PT::merge(ListNode* head1, ListNode * head2){
  ListNode* d = new ListNode(0);            // dummy node
  ListNode* e = d;
  while (head1 || head2){
    if (head1 && (!head2 || head1->val <= head2->val)){
      e = e->next = head1;
      head1 = head1->next;
    }
    if (head2 && (!head1 || head2->val < head1->val)){
      e = e->next = head2;
      head2 = head2->next;
    }
  }
  e->next = NULL;
  return d->next;
}

ListNode* swapPairs(ListNode* head) {
  /*
  24. Swap Nodes in Pairs My Submissions Question
  Total Accepted: 77298 Total Submissions: 227834 Difficulty: Medium
  Given a linked list, swap every two adjacent nodes and return its head.

  For example,
  Given 1->2->3->4, you should return the list as 2->1->4->3.

  Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
  */
  if (!head || head->next == NULL) return head;
  ListNode *dummy = new ListNode(0);
  ListNode *pre = head;
  ListNode *cur = head;
  dummy->next = head;
  pre = dummy;
  while (cur != NULL && cur->next != NULL){
    ListNode *tmp = cur->next->next;
    ListNode *pretmp = cur;
    pre->next = cur->next;
    cur->next = tmp;
    pre->next->next = cur;

    pre = pretmp;
    cur = tmp;
  }
  return dummy->next;

}

void PT::reorderList(ListNode* head) {
  /*
  143. Reorder List My Submissions Question
  Total Accepted: 56744 Total Submissions: 258160 Difficulty: Medium
  Given a singly linked list L: L0→L1→…→Ln-1→Ln,
  reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

  You must do this in-place without altering the nodes' values.

  For example,
  Given {1,2,3,4}, reorder it to {1,4,2,3}
  */
  ListNode *slow = head;
  ListNode *fast = head;
  ListNode *secHalf = head;
  ListNode *firstHalf = head;
  ListNode *newHead = new ListNode(0);
  ListNode *tra = newHead;
  if (!head || head->next == NULL) return;
  while (fast != NULL && fast->next != NULL){
    slow = slow->next;
    fast = fast->next->next;
  }
  secHalf = slow->next;
  slow->next = NULL;
  secHalf = PT::reverseList(secHalf);
  while (secHalf || firstHalf){
    if (firstHalf){
      tra->next = firstHalf;
      firstHalf = firstHalf->next;
      tra = tra->next;
      tra->next = NULL;
    }
    if (secHalf){
      tra->next = secHalf;
      secHalf = secHalf->next;
      tra = tra->next;
      tra->next = NULL;
    }
  }
  head = newHead->next;

}

ListNode* rotateRight(ListNode* head, int k) {
  /*
  61. Rotate List My Submissions Question
  Total Accepted: 57928 Total Submissions: 259815 Difficulty: Medium
  Given a list, rotate the list to the right by k places, where k is non-negative.

  For example:
  Given 1->2->3->4->5->NULL and k = 2,
  return 4->5->1->2->3->NULL.

  Subscribe to see which companies asked this question
  */
  // Failed
  if (!head || k == 0) return head;

  int len = 0;
  ListNode *newHead = new ListNode(0);
  ListNode *fast = head;
  ListNode *slow = head;
  ListNode *pre;
  newHead->next = head;
  pre = newHead;
  while (slow != NULL){
    len++;
    slow = slow->next;
  }
  k = k % len;
  if (k == len || len == 1) return head;
  for (int i = 0; i < k; i++){
    fast = fast->next;
    if (!fast) break;
  }
  slow = head;
  while (fast != NULL){
    pre = pre->next;
    fast = fast->next;
    slow = slow->next;
  }
  pre->next = NULL;
  newHead->next = slow;
  ListNode *tra = newHead->next;
  while (tra->next != NULL)
    tra = tra->next;
  tra->next = head;
  return newHead->next;

}

ListNode* rotateRightAns(ListNode* head, int k) {
  if (!head) return head;

  int len = 1; // number of nodes
  ListNode *newH, *tail;
  newH = tail = head;

  while (tail->next)  // get the number of nodes in the list
  {
    tail = tail->next;
    len++;
  }
  tail->next = head; // circle the link

  if (k %= len)
  {
    for (auto i = 0; i < len - k; i++)
      tail = tail->next; // the tail node is the (len-k)-th node (1st node is head)
  }
  newH = tail->next;
  tail->next = NULL;
  return newH;
}

ListNode* reverseBetweenII(ListNode* head, int m, int n) {
  /*
  92. Reverse Linked List II My Submissions Question
  Total Accepted: 60667 Total Submissions: 225318 Difficulty: Medium
  Reverse a linked list from position m to n. Do it in-place and in one-pass.

  For example:
  Given 1->2->3->4->5->NULL, m = 2 and n = 4,

  return 1->4->3->2->5->NULL.

  Note:
  Given m, n satisfy the following condition:
  1 ≤ m ≤ n ≤ length of list.
  */
  int index = 1;
  ListNode *tra = head;
  ListNode *start, *end;
  while (tra != NULL){
    if (index == m)
      start = tra;
    else if (index == n + 1)
      end = tra;
    index++;
    tra = tra->next;
  }

  return tra;

}

bool hasCycle(ListNode *head) {
  /*
  141. Linked List Cycle My Submissions Question
  Total Accepted: 88920 Total Submissions: 242239 Difficulty: Medium
  Given a linked list, determine if it has a cycle in it.

  Follow up:
  Can you solve it without using extra space?

  Subscribe to see which companies asked this question
  */
  ListNode *slow = head;
  ListNode *fast = head;
  if (head == NULL) return false;
  while (fast->next != NULL && fast->next->next != NULL){
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast)
      return true;
  }
  return false;


}

ListNode *detectCycle(ListNode *head) {
  /*
  Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

  Note: Do not modify the linked list.

  Follow up:
  Can you solve it without using extra space?
  */
  if (head == NULL || head->next == NULL) return NULL;

  ListNode* firstp = head;
  ListNode* secondp = head;
  bool isCycle = false;

  while (firstp != NULL && secondp != NULL) {
    firstp = firstp->next;
    if (secondp->next == NULL) return NULL;
    secondp = secondp->next->next;
    if (firstp == secondp) { isCycle = true; break; }
  }

  if (!isCycle) return NULL;
  firstp = head;
  while (firstp != secondp) {
    firstp = firstp->next;
    secondp = secondp->next;
  }

  return firstp;
}

ListNode* deleteDuplicatesTwo(ListNode* head) {
  /*
  82. Remove Duplicates from Sorted List II My Submissions Question
  Total Accepted: 62235 Total Submissions: 238828 Difficulty: Medium
  Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

  For example,
  Given 1->2->3->3->4->4->5, return 1->2->5.
  Given 1->1->1->2->3, return 2->3.

  Subscribe to see which companies asked thi
  */

  if (!head) return NULL;
  ListNode* p = new ListNode(head->val - 1), *ptr = p, *pre = p;
  while (head) {
    if (pre->val != head->val && (!head->next || head->next->val != head->val)) {
      ptr->next = head;
      ptr = ptr->next;
    }
    pre = head;
    head = head->next;
  }
  ptr->next = NULL;
  return p->next;

}

ListNode* PT::partition(ListNode* head, int x) {
  /*
  86. Partition List My Submissions Question
  Total Accepted: 56400 Total Submissions: 197623 Difficulty: Medium
  Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

  You should preserve the original relative order of the nodes in each of the two partitions.

  For example,
  Given 1->4->3->2->5->2 and x = 3,
  return 1->2->2->4->3->5.
  */

  // 8ms
  ListNode *moreList = new ListNode(-1);
  ListNode *newhead = new ListNode(-1);
  ListNode *moreListTra  = NULL ;
  ListNode *tra = head;
  ListNode *pre ;

  if (!head || head->next == NULL) return head;
  newhead->next = head;
  //moreList->next = moreListTra;
  pre = newhead;

  for (; tra != NULL;){
    if (tra->val >= x) {
      if (moreList->next == NULL){
        pre->next = tra->next;
        moreListTra = tra;
        moreList -> next = moreListTra;
        moreListTra->next = NULL;
        tra = pre -> next ;
        continue;
      }
      pre->next = tra->next;
      moreListTra->next = tra;
      tra = tra->next;
      moreListTra = moreListTra->next;
      moreListTra->next = NULL;
    }else{
      pre = tra;
      tra = tra->next;
    }
  }
  if ( moreList != NULL )
    pre->next = moreList->next;
  return newhead->next;

}

ListNode* oddEvenList(ListNode* head) {
	/***************************************************************************************
	*
	* Given a singly linked list, group all odd nodes together followed by the even nodes.
	* Please note here we are talking about the node number and not the value in the nodes.
	*
	* You should try to do it in place. The program should run in O(1) space complexity
	* and O(nodes) time complexity.
	*
	* Example:
	* Given 1->2->3->4->5->NULL,
	* return 1->3->5->2->4->NULL.
	*
	* Note:
	* The relative order inside both the even and odd groups should remain as it was in
	* the input.
	* The first node is considered odd, the second node even and so on ...
	*
	* Credits:Special thanks to @aadarshjajodia for adding this problem and creating all
	* test cases.
	***************************************************************************************/
	if (!head) return head;
	ListNode* pOdd = head;
	ListNode* p = head->next;
	ListNode* pNext = NULL;
	while (p && (pNext = p->next)) {

		p->next = pNext->next; // 2->4
		pNext->next = pOdd->next; // 3->2
		pOdd->next = pNext; // 1-> 3

		p = p->next;
		pOdd = pOdd->next;

	}
	return head;
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    /**********************************************************************************
     *
     * You are given two linked lists representing two non-negative numbers.
     * The digits are stored in reverse order and each of their nodes contain a single digit.
     * Add the two numbers and return it as a linked list.
     *
     * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
     * Output: 7 -> 0 -> 8
     *
     **********************************************************************************/

    ListNode preHead(0), *p = &preHead;
    int extra = 0;
    while (l1 || l2 || extra) {
        int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + extra;
        extra = sum / 10;
        p->next = new ListNode(sum % 10);
        p = p->next;
        l1 = l1 ? l1->next : l1;
        l2 = l2 ? l2->next : l2;
    }
    return preHead.next;
}

ListNode *reverseBetween(ListNode *head, int m, int n) {
	/**********************************************************************************
	*
	* Reverse a linked list from position m to n. Do it in-place and in one-pass.
	*
	* For example:
	* Given 1->2->3->4->5->NULL, m = 2 and n = 4,
	*
	* return 1->4->3->2->5->NULL.
	*
	* Note:
	* Given m, n satisfy the following condition:
	* 1 ≤ m ≤ n ≤ length of list.
	*
	*
	**********************************************************************************/

	if (head == NULL || m >= n) return head;

	ListNode fake(0);
	fake.next = head;
	ListNode *pBegin = &fake, *pEnd = &fake;

	int distance = n - m;
	// get pEnd and pBegin in position
	while (pEnd && distance>0){
		pEnd = pEnd->next;
		distance--;
	}
	while (pBegin && pEnd && m - 1>0) {
		pBegin = pBegin->next;
		pEnd = pEnd->next;
		m--;
	}
	if (pBegin == NULL || pEnd == NULL || pEnd->next == NULL){
		return head;
	}

	ListNode *p = pBegin->next;
	ListNode *q = pEnd->next->next;

	ListNode *pHead = q;
	while (p != q){
		ListNode* node = p->next;
		p->next = pHead;
		pHead = p;
		p = node;
	}
	pBegin->next = pHead;

	return fake.next;

}

void TakeOutNode(ListNode*& head, ListNode*& tail, ListNode*& p){
    ListNode *pNext = p->next;
    if (head==NULL){
        head = tail = p;
    }else{
        tail->next = p;
        tail = p;
    }
    p->next = NULL;
    p = pNext;
}

ListNode *mergeTwoLists01(ListNode* head1, ListNode* head2){
    ListNode *p1 = head1,  *p2=head2;
    static ListNode dummy(0);

    dummy.next = p1;
    ListNode *prev = &dummy;

    while(p1 && p2){
        if(p1->val < p2->val){
            prev = p1;
            p1 = p1->next;
        }else{
            prev->next = p2;
            p2 = p2->next;
            prev = prev->next;
            prev->next = p1;
        }
    }
    if (p2){
        prev->next = p2;
    }

    return dummy.next;
}

ListNode *mergeTwoLists02(ListNode* head1, ListNode* head2) {
    ListNode *p1 = head1,  *p2=head2;

    ListNode *pHead = NULL, *pTail=NULL;
    while(p1 && p2){
        if(p1->val < p2->val){
            TakeOutNode(pHead, pTail, p1);
        }else{
            TakeOutNode(pHead, pTail, p2);
        }
    }

    ListNode *p=NULL;
    if (p1){
        p = p1;
    }else if (p2){
        p = p2;
    }
    if (pHead==NULL){
        return p;
    }
    pTail->next = p;
    return pHead;
}

ListNode *mergeTwoLists(ListNode* head1, ListNode* head2){
    return mergeTwoLists01(head1, head2);
    return mergeTwoLists02(head1, head2);
}

ListNode *mergeKLists(vector<ListNode *> &lists) {
    /**********************************************************************************
     *
     * Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
     *
     **********************************************************************************/

    ListNode *p, *p1, *p2;
    while(lists.size()>1){
        p1 = lists.back();
        lists.pop_back();
        p2 = lists.back();
        lists.pop_back();
        p = mergeTwoLists(p1, p2);
        lists.insert(lists.begin(), p);
    }
    return lists.size()==1 ? lists[0] : NULL;
}


