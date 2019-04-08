#include "stdafx.h"
#include "DFS.h"
#include "type.h"
#include "string"
#include<algorithm>
#include<vector>
#include<random>
#include<queue>
#include<map>
#include<ctime>
#include<math.h>

#include<iostream>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<sstream>
#include<stack>

using namespace std;

int minDepth(TreeNode* root) {
	/*
	   111. Minimum Depth of Binary Tree My Submissions Question
	   Total Accepted: 90418 Total Submissions: 300958 Difficulty: Easy
	   Given a binary tree, find its minimum depth.

	   The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

	   Subscribe to see which companies asked this question

	   Show Tags
	   Show Similar Problems
	   Have you met this question in a real interview? Yes  No

	   Discuss
	   */

	if (!root) return 0;
	if (!root->left) return 1 + minDepth(root->right);
	if (!root->right) return 1 + minDepth(root->left);
	return 1 + min(minDepth(root->left), minDepth(root->right));
}

void binaryTreePathsHelper(TreeNode* root, vector<int> solution, vector<string>& result) {
	if (!root) return;

	solution.push_back(root->val);

	//meet the leaf node, shape a path into the result
	if (root->left == NULL && root->right == NULL){
		if (solution.size() > 0){
			stringstream ss;
			for (int i = 0; i < solution.size(); i++){
				ss << solution[i] << (i < solution.size() - 1 ? "->" : "");
			}
			result.push_back(ss.str());
		}
		return;
	}

	binaryTreePathsHelper(root->left, solution, result);
	binaryTreePathsHelper(root->right, solution, result);

}

vector<string> binaryTreePaths(TreeNode* root) {
	/***************************************************************************************
	 *
	 * Given a binary tree, return all root-to-leaf paths.
	 *
	 * For example, given the following binary tree:
	 *
	 *    1
	 *  /   \
	 * 2     3
	 *  \
	 *   5
	 *
	 * All root-to-leaf paths are:
	 * ["1->2->5", "1->3"]
	 *
	 * Credits:
	 * Special thanks to @jianchao.li.fighter for adding this problem and creating all test
	 * cases.
	 *
	 ***************************************************************************************/
	vector<string> result;
	vector<int> solution;
	binaryTreePathsHelper(root, solution, result);
	return result;
}

bool isBalancedUtil(TreeNode* root, int& height){
	if (root == NULL){
		height = 0;
		return true;
	}
	int lh = 0, rh = 0;
	bool isLeft = isBalancedUtil(root->left, lh);
	bool isRight = isBalancedUtil(root->right, rh);
	height = (lh > rh ? lh : rh) + 1;
	return (abs(lh - rh) <= 1 && isLeft && isRight);
}

bool isBalanced(TreeNode *root) {
	/**********************************************************************************
	 *
	 * Given a binary tree, determine if it is height-balanced.
	 *
	 * For this problem, a height-balanced binary tree is defined as a binary tree in which
	 * the depth of the two subtrees of every node never differ by more than 1.
	 *
	 *
	 **********************************************************************************/
	int height = 0;
	return isBalancedUtil(root, height);
}
bool isSameTree2(TreeNode *p, TreeNode *q) {

	queue<TreeNode*> q1, q2;
	q1.push(p);
	q2.push(q);
	while (q1.size() > 0 && q2.size() > 0){
		TreeNode* p1 = q1.front();
		q1.pop();
		TreeNode* p2 = q2.front();
		q2.pop();
		if (!p1 && !p2) continue;
		if (!p1 || !p2)  return false;

		if (p1->val != p2->val) {
			return false;
		}

		q1.push(p1->left);
		q2.push(p2->left);

		q1.push(p1->right);
		q2.push(p2->right);

	}
	return true;
}

bool isSameTree(TreeNode *p, TreeNode *q) {
	/**********************************************************************************
	 *
	 * Given two binary trees, write a function to check if they are equal or not.
	 *
	 * Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
	 *
	 *
	 **********************************************************************************/
	//return isSameTree1(p, q);
	return isSameTree2(p, q);
}

bool isSameTree1(TreeNode *p, TreeNode *q) {
	if (!p && !q) return true;
	if (!p || !q) return false;
	return (p->val == q->val) &&
		isSameTree(p->left, q->left) &&
		isSameTree(p->right, q->right);
}


bool isSymmetric1(TreeNode *p, TreeNode *q){
	if (p == NULL && q == NULL) return true;
	if (p == NULL || q == NULL) return false;

	return (p->val == q->val) &&
		isSymmetric1(p->left, q->right) &&
		isSymmetric1(p->right, q->left);
}

bool isSymmetric2(TreeNode *p, TreeNode *q){

	queue<TreeNode*> q1;
	queue<TreeNode*> q2;
	q1.push(p);
	q2.push(q);
	while (q1.size() > 0 && q2.size() > 0){
		TreeNode* p1 = q1.front();
		q1.pop();
		TreeNode* p2 = q2.front();
		q2.pop();
		if (p1 == NULL && p2 == NULL) continue;
		if (p1 == NULL || p2 == NULL) return false;

		if (p1->val != p2->val) return false;

		q1.push(p1->left);
		q2.push(p2->right);

		q1.push(p1->right);
		q2.push(p2->left);

	}
	return true;

}

bool isSymmetric(TreeNode *p, TreeNode *q){

	//return isSymmetric1(p, q);
	return isSymmetric2(p, q);
}


bool isSymmetric(TreeNode *root) {
	/**********************************************************************************
	 *
	 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
	 *
	 * For example, this binary tree is symmetric:
	 *
	 *     1
	 *    / \
	 *   2   2
	 *  / \ / \
	 * 3  4 4  3
	 *
	 * But the following is not:
	 *
	 *     1
	 *    / \
	 *   2   2
	 *    \   \
	 *    3    3
	 *
	 * Note:
	 * Bonus points if you could solve it both recursively and iteratively.
	 *
	 * confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
	 *
	 * OJ's Binary Tree Serialization:
	 *
	 * The serialization of a binary tree follows a level order traversal, where '#' signifies
	 * a path terminator where no node exists below.
	 *
	 * Here's an example:
	 *
	 *    1
	 *   / \
	 *  2   3
	 *     /
	 *    4
	 *     \
	 *      5
	 *
	 * The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}".
	 *
	 *
	 **********************************************************************************/
	if (root == NULL) return true;
	return isSymmetric(root->left, root->right);

}

bool hasPathSumRecur(TreeNode *root, int sum) {

	if (root == NULL) return false;

	if (root->left == NULL && root->right == NULL){
		return (root->val == sum);
	}

	if (root->left){
		root->left->val += root->val;
		if (hasPathSumRecur(root->left, sum)){
			return true;
		}
	}

	if (root->right){
		root->right->val += root->val;
		if (hasPathSumRecur(root->right, sum)){
			return true;
		}
	}

	return false;
}

bool hasPathSum1(TreeNode *root, int sum) {
	if (root == NULL) return false;
	vector<TreeNode*> v;
	v.push_back(root);
	while (v.size() > 0){
		TreeNode* node = v.back();
		v.pop_back();
		if (node->left == NULL && node->right == NULL){
			if (node->val == sum){
				return true;
			}
		}
		if (node->left){
			node->left->val += node->val;
			v.push_back(node->left);
		}
		if (node->right){
			node->right->val += node->val;
			v.push_back(node->right);
		}
	}
	return false;

}

bool hasPathSum(TreeNode *root, int sum) {
	/**********************************************************************************
	 *
	 * Given a binary tree and a sum, determine if the tree has a root-to-leaf path
	 * such that adding up all the values along the path equals the given sum.
	 *
	 * For example:
	 * Given the below binary tree and sum = 22,
	 *
	 *               5
	 *              / \
	 *             4   8
	 *            /   / \
	 *           11  13  4
	 *          /  \      \
	 *         7    2      1
	 *
	 * return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
	 *
	 **********************************************************************************/
	if (rand() % 2){
		return hasPathSum1(root, sum);
	}
	return hasPathSumRecur(root, sum);
}

int maxDepth(TreeNode *root) {
	/**********************************************************************************
	 *
	 * Given a binary tree, find its maximum depth.
	 *
	 * The maximum depth is the number of nodes along the longest path from the root node
	 * down to the farthest leaf node.
	 *
	 **********************************************************************************/
	if (root == NULL){
		return 0;
	}
	if (!root->left && !root->right){
		return 1;
	}
	int left = 1, right = 1;
	if (root->left){
		left += maxDepth(root->left);
	}
	if (root->right){
		right += maxDepth(root->right);
	}
	return left > right ? left : right;
}

int maxDepthRecurr(TreeNode* root) {
	return root ? 1 + max(maxDepthRecurr(root->left), maxDepthRecurr(root->right)) : 0;
}

int sumNumbers(TreeNode *root) {
	/**********************************************************************************
	 *
	 * Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
	 * An example is the root-to-leaf path 1->2->3 which represents the number 123.
	 *
	 * Find the total sum of all root-to-leaf numbers.
	 *
	 * For example,
	 *
	 *     1
	 *    / \
	 *   2   3
	 *
	 * The root-to-leaf path 1->2 represents the number 12.
	 * The root-to-leaf path 1->3 represents the number 13.
	 *
	 * Return the sum = 12 + 13 = 25.
	 *
	 *
	 **********************************************************************************/

	if (!root) return 0;

	int sum = 0;
	vector<TreeNode*> v;
	v.push_back(root);
	while (v.size() > 0){
		TreeNode* node = v.back();
		v.pop_back();
		if (node->left){
			node->left->val += (10 * node->val);
			v.push_back(node->left);
		}
		if (node->right){
			node->right->val += (10 * node->val);
			v.push_back(node->right);
		}
		if (!node->right && !node->left){
			sum += node->val;
		}
	}

	return sum;
}

void generatePathSum(TreeNode *root, int sum, vector<int> v, vector<vector<int> >& result) {

	if (root == NULL) {
		return;
	}

	if (root->left == NULL && root->right == NULL) {
		if (root->val == sum){
			v.push_back(root->val);
			result.push_back(v);
		}
		return;
	}

	v.push_back(root->val);

	if (root->left) {
		generatePathSum(root->left, sum - root->val, v, result);
	}

	if (root->right) {
		generatePathSum(root->right, sum - root->val, v, result);
	}
}

vector<vector<int> > pathSum(TreeNode *root, int sum) {
	/**********************************************************************************
	 *
	 * Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
	 *
	 * For example:
	 * Given the below binary tree and sum = 22,
	 *
	 *               5
	 *              / \
	 *             4   8
	 *            /   / \
	 *           11  13  4
	 *          /  \    / \
	 *         7    2  5   1
	 *
	 * return
	 *
	 * [
	 *    [5,4,11,2],
	 *    [5,8,4,5]
	 * ]
	 *
	 *
	 **********************************************************************************/

	vector<vector<int> > result;
	vector<int> v;
	generatePathSum(root, sum, v, result);
	return result;
}

TreeNode *sortedArrayToBST(vector<int> &num) {
	/**********************************************************************************
	*
	* Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
	*
	**********************************************************************************/
	if (num.size() == 0){
		return NULL;
	}
	if (num.size() == 1){
		return new TreeNode(num[0]);
	}
	int mid = num.size() / 2;

	TreeNode *node = new TreeNode(num[mid]);

	vector<int>::const_iterator first;
	vector<int>::const_iterator last;

	first = num.begin();
	last = num.begin() + mid;
	vector<int> v(first, last);
	node->left = sortedArrayToBST(v);

	if (mid == num.size() - 1){
		node->right = NULL;
	}
	else{
		first = num.begin() + mid + 1;
		last = num.end();
		vector<int> v(first, last);
		node->right = sortedArrayToBST(v);
	}
	return node;
}

void connect(TreeLinkNode *root) {
	/**********************************************************************************
	*
	* Given a binary tree
	*
	* Populate each next pointer to point to its next right node.
	* If there is no next right node, the next pointer should be set to NULL.
	*
	* Initially, all next pointers are set to NULL.
	*
	* Note:
	*
	* You may only use constant extra space.
	* You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
	*
	* For example,
	* Given the following perfect binary tree,
	*
	*          1
	*        /  \
	*       2    3
	*      / \  / \
	*     4  5  6  7
	*
	* After calling your function, the tree should look like:
	*
	*          1 -> NULL
	*        /  \
	*       2 -> 3 -> NULL
	*      / \  / \
	*     4->5->6->7 -> NULL
	*
	*
	**********************************************************************************/

	if (root == NULL){
		return;
	}
	if (root->left && root->right){
		root->left->next = root->right;
	}
	if (root->next && root->right){
		root->right->next = root->next->left;
	}
	connect(root->left);
	connect(root->right);

}

void connect1(TreeLinkNode *root) {

	if (root == NULL)
		return;

	vector<TreeLinkNode*> v;
	v.push_back(root);
	int i = 0;

	while (i < v.size()){
		if (v[i]->left){
			v.push_back(v[i]->left);
		}
		if (v[i]->right) {
			v.push_back(v[i]->right);
		}
		i++;
	}

	i = 1;
	while (i<v.size()){
		for (int j = i - 1; j<2 * (i - 1); j++){
			v[j]->next = v[j + 1];
		}
		i *= 2;
	}

}

void connect2(TreeLinkNode *root) {

	if (root == NULL)
		return;

	vector<TreeLinkNode*> v;

	v.push_back(root);

	while (v.size()>0){

		if (root->left && root->right && root->left->next == NULL) {
			root->left->next = root->right;

			if (root->next){
				root->right->next = root->next->left;
			}

			v.push_back(root->right);
			v.push_back(root->left);
		}
		root = v.back();
		v.pop_back();
	}
}

TreeNode* sortedListToBST(int low, int high, ListNode*& head) {
	if (low>high || head == NULL) return NULL;

	int mid = low + (high - low) / 2;

	TreeNode* leftNode = sortedListToBST(low, mid - 1, head);

	TreeNode* node = new TreeNode(head->val);
	node->left = leftNode;
	head = head->next;

	TreeNode* rightNode = sortedListToBST(mid + 1, high, head);
	node->right = rightNode;

	return node;
}

TreeNode *sortedListToBST(ListNode *head) {
	/**********************************************************************************
	*
	* Given a singly linked list where elements are sorted in ascending order,
	* convert it to a height balanced BST.
	*
	**********************************************************************************/
	int len = 0;

	for (ListNode* p = head; p != NULL; p = p->next){
		len++;
	}
	return sortedListToBST(0, len - 1, head);
}

void flatten(TreeNode *root) {
	/**********************************************************************************
	*
	* Given a binary tree, flatten it to a linked list in-place.
	*
	* For example,
	* Given
	*
	*          1
	*         / \
	*        2   5
	*       / \   \
	*      3   4   6
	*
	* The flattened tree should look like:
	*
	*    1
	*     \
	*      2
	*       \
	*        3
	*         \
	*          4
	*           \
	*            5
	*             \
	*              6
	*
	*
	* Hints:
	* If you notice carefully in the flattened tree, each node's right child points to
	* the next node of a pre-order traversal.
	*
	**********************************************************************************/

	vector<TreeNode*> v, stack;
	stack.push_back(root);
	while (stack.size()>0){
		TreeNode* node = stack.back();
		stack.pop_back();
		v.push_back(node);

		if (node && node->right){
			stack.push_back(node->right);
		}
		if (node && node->left){
			stack.push_back(node->left);
		}
	}

	v.push_back(NULL);
	for (int i = 0; i<v.size(); i++){
		if (v[i]){
			v[i]->left = NULL;
			v[i]->right = v[i + 1];
		}
	}

}
void mark(vector<vector<char> >& grid, int r, int c){
	if (r<0 || r >= grid.size() ||
		c<0 || c >= grid[0].size() ||
		grid[r][c] != '1') {
		return;
	}

	grid[r][c] = 'M';

	//left
	mark(grid, r, c + 1);
	//right
	mark(grid, r, c - 1);
	//up
	mark(grid, r - 1, c);
	//down
	mark(grid, r + 1, c);
}

int numIslands(vector<vector<char> >& grid) {
	/**********************************************************************************
	*
	* Given a 2d grid map of '1's (land) and '0's (water), count the number of islands.
	* An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
	* You may assume all four edges of the grid are all surrounded by water.
	*
	* Example 1:
	*   11110
	*   11010
	*   11000
	*   00000
	* Answer: 1
	*
	* Example 2:
	*   11000
	*   11000
	*   00100
	*   00011
	* Answer: 3
	*
	* Credits:Special thanks to @mithmatt for adding this problem and creating all test cases.
	*
	**********************************************************************************/

	int result = 0;
	for (int r = 0; r<grid.size(); r++) {
		for (int c = 0; c<grid[r].size(); c++) {
			if (grid[r][c] == '1') {
				result++;
				mark(grid, r, c);
			}
		}
	}
	return result;
}




