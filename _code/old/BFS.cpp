#include "stdafx.h"
#include "BFS.h"
#include "string"
#include<algorithm>
#include<vector>
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
int numSquares_dp(int n) {

	/*
	* Dynamic Programming
	* ===================
	*   dp[0] = 0
	*   dp[1] = dp[0]+1 = 1
	*   dp[2] = dp[1]+1 = 2
	*   dp[3] = dp[2]+1 = 3
	*   dp[4] = min{ dp[4-1*1]+1, dp[4-2*2]+1 }
	*         = min{ dp[3]+1, dp[0]+1 }
	*         = 1
	*   dp[5] = min{ dp[5-1*1]+1, dp[5-2*2]+1 }
	*         = min{ dp[4]+1, dp[1]+1 }
	*         = 2
	*   dp[6] = min{ dp[6-1*1]+1, dp[6-2*2]+1 }
	*         = min{ dp[5]+1, dp[2]+1 }
	*         = 3
	*   dp[7] = min{ dp[7-1*1]+1, dp[7-2*2]+1 }
	*         = min{ dp[6]+1, dp[3]+1 }
	*         = 4
	*   dp[8] = min{ dp[8-1*1]+1, dp[8-2*2]+1 }
	*         = min{ dp[7]+1, dp[4]+1 }
	*         = 2
	*   dp[9] = min{ dp[9-1*1]+1, dp[9-2*2]+1, dp[9-3*3]+1 }
	*         = min{ dp[8]+1, dp[5]+1, dp[0]+1 }
	*         = 1
	*   dp[10] = min{ dp[10-1*1]+1, dp[10-2*2]+1, dp[10-3*3]+1 }
	*          = min{ dp[9]+1, dp[6]+1, dp[1]+1 }
	*          = 2
	*                           ....
	*
	*   So, the dynamic programm formula is
	*
	*
	*/

	//dp[n] = min{ dp[n - i*i] + 1 },  n - i*i >=0 && i >= 1

	if (n <= 0) return 0;

	int *dp = new int[n + 1];
	dp[0] = 0;

	for (int i = 1; i <= n; i++) {
		int m = n;
		for (int j = 1; i - j*j >= 0; j++) {
			m = min(m, dp[i - j*j] + 1);
		}
		dp[i] = m;
	}

	return dp[n];
	delete[] dp;
}

int numSquares_dp_opt(int n) {
	//using cache to optimize the dp algorithm
	if (n <= 0) return 0;

	static vector<int> dp(1, 0);
	if (dp.size() >= (n + 1)) return dp[n];

	for (int i = dp.size(); i <= n; i++) {
		int m = n;
		for (int j = 1; i - j*j >= 0; j++) {
			m = min(m, dp[i - j*j] + 1);
		}
		dp.push_back(m);
	}

	return dp[n];
}

int numSquares(int n) {
	/***************************************************************************************
	*
	* Given a positive integer n, find the least number of perfect square numbers (for
	* example, 1, 4, 9, 16, ...) which sum to n.
	*
	* For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2
	* because 13 = 4 + 9.
	*
	* Credits:Special thanks to @jianchao.li.fighter for adding this problem and creating
	* all test cases.
	*
	***************************************************************************************/
	return numSquares_dp_opt(n); //12ms
	return numSquares_dp(n); //232ms
}

int mySqrt(int x) {
	/**********************************************************************************
	*
	* Implement int sqrt(int x).
	*
	* Compute and return the square root of x.
	*
	**********************************************************************************/

	if (x <= 0) return 0;

	//the sqrt is not greater than x/2+1
	int e = x / 2 + 1;
	int s = 0;
	// binary search
	while (s <= e) {
		int mid = s + (e - s) / 2;
		long long sq = (long long)mid*(long long)mid;
		if (sq == x) return mid;
		if (sq < x) {
			s = mid + 1;
		}
		else {
			e = mid - 1;
		}
	}
	return e;

}

TreeNode* invertTree_recursive(TreeNode* root) {
    if (root==NULL) return root;
    TreeNode* node = invertTree_recursive(root->left);
    root->left = invertTree_recursive(root->right);
    root->right = node;
    return root;
}

TreeNode* invertTree_non_recursive(TreeNode* root) {
    if (root==NULL) return root;
    vector<TreeNode*> stack;
    stack.push_back(root);
    while (!stack.empty()) {
        TreeNode* node = stack.back();
        stack.pop_back();
        swap(node->left, node->right);
        if (node->left) stack.push_back(node->left);
        if (node->right) stack.push_back(node->right);
    }
    return root;
}

TreeNode* invertTree(TreeNode* root) {
  /**********************************************************************************
   *
   * Invert a binary tree.
   *      4
   *    /   \
   *   2     7
   *  / \   / \
   * 1   3 6   9
   *
   * to
   *      4
   *    /   \
   *   7     2
   *  / \   / \
   * 9   6 3   1
   *
   * Trivia:
   * This problem was inspired by this original tweet by Max Howell:
   * (https://twitter.com/mxcl/status/608682016205344768)
   *
   *  | Google: 90% of our engineers use the software you wrote (Homebrew),
   *  | but you can’t invert a binary tree on a whiteboard so fuck off.
   *
   **********************************************************************************/
    if (rand()%2){
        return invertTree_non_recursive(root);
    }
    return invertTree_recursive(root);
}

    int ladderLength(string start, string end, unordered_set<string> &dict) {
/**********************************************************************************
*
* Given two words (start and end), and a dictionary, find the length of shortest
* transformation sequence from start to end, such that:
*
* Only one letter can be changed at a time
* Each intermediate word must exist in the dictionary
*
* For example,
*
* Given:
* start = "hit"
* end = "cog"
* dict = ["hot","dot","dog","lot","log"]
*
* As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
* return its length 5.
*
* Note:
*
* Return 0 if there is no such transformation sequence.
* All words have the same length.
* All words contain only lowercase alphabetic characters.
*
*
**********************************************************************************/

/*
 ---------------------------
  BFS non-recursive method
 ---------------------------

    Using BFS instead of DFS is becasue the solution need the shortest transformation path.

    So, we can change every char in the word one by one, until find all possible transformation.

    Keep this iteration, we will find the shorest path.

 For example:

     start = "hit"
     end = "cog"
     dict = ["hot","dot","dog","lot","log","dit","hig", "dig"]

                      +-----+
        +-------------+ hit +--------------+
        |             +--+--+              |
        |                |                 |
     +--v--+          +--v--+           +--v--+
     | dit |    +-----+ hot +---+       | hig |
     +--+--+    |     +-----+   |       +--+--+
        |       |               |          |
        |    +--v--+         +--v--+    +--v--+
        +----> dot |         | lot |    | dig |
             +--+--+         +--+--+    +--+--+
                |               |          |
             +--v--+         +--v--+       |
        +----> dog |         | log |       |
        |    +--+--+         +--+--+       |
        |       |               |          |
        |       |    +--v--+    |          |
        |       +--->| cog |<-- +          |
        |            +-----+               |
        |                                  |
        |                                  |
        +----------------------------------+

     1) queue <==  "hit"
     2) queue <==  "dit", "hot", "hig"
     3) queue <==  "dot", "lot", "dig"
     4) queue <==  "dog", "log"
     */

        // Using a map for two purposes:
        //   1) store the distince so far.
        //   2) remove the duplication
        map<string, int> dis;
        dis[start] = 1;

        queue<string> q;
        q.push(start);

        while(!q.empty()){

            string word = q.front();
            q.pop();

            if (word == end) {
                break;
            }

            for (int i=0; i<word.size(); i++){
                string temp = word;
                for(char c='a'; c<='z'; c++){
                    temp[i] = c;
                    if (dict.count(temp)>0 && dis.count(temp)==0){
                        dis[temp] = dis[word] + 1;
                        q.push(temp);
                    }
                }
            }
        }
        return (dis.count(end)==0) ? 0 : dis[end];

    }

map< string, unordered_set<string> >& buildTree(string& start, string& end, unordered_set<string> &dict) {

    static map< string, unordered_set<string> > parents;
    parents.clear();

    unordered_set<string> level[3];
    unordered_set<string> *previousLevel = &level[0];
    unordered_set<string> *currentLevel = &level[1];
    unordered_set<string> *newLevel = &level[2];
    unordered_set<string> *p =NULL;
    currentLevel->insert(start);

    bool reachEnd = false;

    while( !reachEnd ) {
        newLevel->clear();
        for(auto it=currentLevel->begin(); it!=currentLevel->end(); it++) {
            for (int i=0; i<it->size(); i++) {
                string newWord = *it;
                for(char c='a'; c<='z'; c++){
                    newWord[i] = c;
                    if (newWord == end){
                        reachEnd = true;
                        parents[*it].insert(end);
                        continue;
                    }
                    if ( dict.count(newWord)==0 || currentLevel->count(newWord)>0 || previousLevel->count(newWord)>0 ) {
                        continue;
                    }
                    newLevel->insert(newWord);
                    //parents[newWord].insert(*it);
                    parents[*it].insert(newWord);
                }
            }
        }
        if (newLevel->empty()) break;

        p = previousLevel;
        previousLevel = currentLevel;
        currentLevel = newLevel;
        newLevel = p;
    }


    if ( !reachEnd ) {
        parents.clear();
    }
    return parents;
}

void generatePath( string start, string end,
        map< string, unordered_set<string> > &parents,
        vector<string> path,
        vector< vector<string> > &paths) {

    if (parents.find(start) == parents.end()){
        if (start == end){
            paths.push_back(path);
        }
        return;
    }

    for(auto it=parents[start].begin(); it!=parents[start].end(); it++){
        path.push_back(*it);
        generatePath(*it, end, parents, path, paths);
        path.pop_back();
    }

}

vector< vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {

/**********************************************************************************
*
* Given two words (start and end), and a dictionary, find all shortest transformation
* sequence(s) from start to end, such that:
*
* Only one letter can be changed at a time
* Each intermediate word must exist in the dictionary
*
* For example,
*
* Given:
* start = "hit"
* end = "cog"
* dict = ["hot","dot","dog","lot","log"]
*
* Return
*
*   [
*     ["hit","hot","dot","dog","cog"],
*     ["hit","hot","lot","log","cog"]
*   ]
*
* Note:
*
* All words have the same length.
* All words contain only lowercase alphabetic characters.
*
*
**********************************************************************************/

/*
 Solution

      1) Using BSF algorithm build a tree like below
      2) Using DSF to parse the tree to the transformation path.

 For example:

     start = "hit"
     end = "cog"
     dict = ["hot","dot","dog","lot","log","dit","hig", "dig"]

                      +-----+
        +-------------+ hit +--------------+
        |             +--+--+              |
        |                |                 |
     +--v--+          +--v--+           +--v--+
     | dit |    +-----+ hot +---+       | hig |
     +--+--+    |     +-----+   |       +--+--+
        |       |               |          |
        |    +--v--+         +--v--+    +--v--+
        +----> dot |         | lot |    | dig |
             +--+--+         +--+--+    +--+--+
                |               |          |
             +--v--+         +--v--+       |
        +----> dog |         | log |       |
        |    +--+--+         +--+--+       |
        |       |               |          |
        |       |    +--v--+    |          |
        |       +--->| cog |<-- +          |
        |            +-----+               |
        |                                  |
        |                                  |
        +----------------------------------+
  */


    vector< vector<string> > ladders;
    vector<string> ladder;
    ladder.push_back(start);
    if (start == end){
        ladder.push_back(end);
        ladders.push_back(ladder);
        return ladders;
    }

    map< string, unordered_set<string> >& parents = buildTree(start, end, dict);

    if  (parents.size()<=0) {
        return ladders;
    }

    generatePath(start, end, parents, ladder, ladders);

    return ladders;
}

#if 0


const int MAX_CHARS = 26;

class TrieNode {
    public:
        TrieNode(string s):isWord(false), word(s) {
            memset(children, 0, sizeof(children));
        }
        TrieNode* & operator [] (char ch) {
            return children[(ch - 'a') % MAX_CHARS];
        }
        TrieNode* & operator [] (int idx) {
            return children[idx % MAX_CHARS];
        }

    public:
        string word;
        bool isWord;
    private:
        TrieNode* children[MAX_CHARS];
};

class TrieTree {
    public:
        TrieTree():root(new TrieNode("")) { }
        ~TrieTree() { freeTree(root); }
        TrieNode* getRoot() {
            return root;
        }
        void addWord(string& s){
            TrieNode *node = root;
            string t;
            for (int i=0; i<s.size(); i++){
                t += s[i];
                if ( (*node)[s[i]] == NULL ){
                    (*node)[s[i]] = new TrieNode(t);
                }
                node = (*node)[s[i]];
            }
            node->isWord = true;
        }
    private:
        void freeTree(TrieNode* node){
            for(int i=0; i<MAX_CHARS; i++){
                if ((*node)[i]!=NULL){
                    freeTree((*node)[i]);
                }
            }
            delete node;
        }
        TrieNode *root;

};

class Solution {
public:
    void findWords(vector<vector<char>>& board, TrieNode* root, int row, int col, vector<string>& result){
        if (row < 0 || col < 0 ||
                row >= board.size() ||
                col >= board[row].size() ||
                board[row][col] == '\0' ) {
            return;
        }

        char ch = board[row][col];
        root = (*root)[ch];

        if (root==NULL) return;

        if (root->isWord){
            result.push_back(root->word);
            root->isWord = false;
        }


        board[row][col] = '\0';

        findWords(board, root, row, col - 1, result);
        findWords(board, root, row, col + 1, result);
        findWords(board, root, row + 1, col, result);
        findWords(board, root, row - 1, col, result);

        board[row][col] = ch;

    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieTree t;
        for (int i = 0; i<words.size(); i++){
            t.addWord(words[i]);
        }

        vector<string> result;
        for (int i = 0; i<board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                findWords(board, t.getRoot(), i, j, result);
            }
        }
        return result;
    }

};

#endif

    bool isMatch(const char *s, const char *p) {
    /**********************************************************************************
     *
     * Implement regular expression matching with support for '.' and '*'.
     *
     * '.' Matches any single character.
     * '*' Matches zero or more of the preceding element.
     *
     * The matching should cover the entire input string (not partial).
     *
     * The function prototype should be:
     * bool isMatch(const char *s, const char *p)
     *
     * Some examples:
     * isMatch("aa","a") → false
     * isMatch("aa","aa") → true
     * isMatch("aaa","aa") → false
     * isMatch("aa", "a*") → true
     * isMatch("aa", ".*") → true
     * isMatch("ab", ".*") → true
     * isMatch("aab", "c*a*b") → true
     *
     *
     **********************************************************************************/
//http://xiaohuiliucuriosity.blogspot.tw/2014/12/regular-expression-matching.html
        if (!*p)    return (!*s);

        if ('*' == *(p + 1)) {
            // x* matches empty string or at least one character: x* -> xx*
            // *s is to ensure s is non-empty
            return (isMatch(s, p + 2) || *s && (*s == *p || '.' == *p) && isMatch(s + 1, p));
        } else {
            if (!*s)    return false;
            return (*s == *p || '.' == *p) ? isMatch(s + 1, p + 1) : false;
        }
    }
    bool isMatchDP(string s, string p) {
        /**
         * f[i][j]: if s[0..i-1] matches p[0..j-1]
         * if p[j - 1] != '*'
         *      f[i][j] = f[i - 1][j - 1] && s[i - 1] == p[j - 1]
         * if p[j - 1] == '*', denote p[j - 2] with x
         *      f[i][j] is true iff any of the following is true
         *      1) "x*" repeats 0 time and matches empty: f[i][j - 2]
         *      2) "x*" repeats >= 1 times and matches "x*x": s[i - 1] == x && f[i - 1][j]
         * '.' matches any single character
         */
        int m = s.size(), n = p.size();
        vector<vector<bool>> f(m + 1, vector<bool>(n + 1, false));

        f[0][0] = true;
        for (int i = 1; i <= m; i++)
            f[i][0] = false;
        // p[0.., j - 3, j - 2, j - 1] matches empty iff p[j - 1] is '*' and p[0..j - 3] matches empty
        for (int j = 1; j <= n; j++)
            f[0][j] = j > 1 && '*' == p[j - 1] && f[0][j - 2];

        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                if (p[j - 1] != '*')
                    f[i][j] = f[i - 1][j - 1] && (s[i - 1] == p[j - 1] || '.' == p[j - 1]);
                else
                    // p[0] cannot be '*' so no need to check "j > 1" here
                    f[i][j] = f[i][j - 2] || (s[i - 1] == p[j - 2] || '.' == p[j - 2]) && f[i - 1][j];

        return f[m][n];
    }
#if 0
class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode():isWord(false) {   }
    unordered_map<char, TrieNode*> children;
    bool isWord;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string s) {
        if (s.size()<=0) return;
        TrieNode * node = root;
        for (int i=0; i<s.size(); i++) {
            if (node->children.find(s[i]) == node->children.end()){
                node->children[s[i]] = new TrieNode();
            }
            node = node->children[s[i]];
        }
        node->isWord = true;
    }

    // Returns if the word is in the trie.
    bool search(string key) {
        return retrieve(key, true);
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
/**********************************************************************************
 *
 * Implement a trie with insert, search, and startsWith methods.
 *
 * Note:
 * You may assume that all inputs are consist of lowercase letters a-z.
 *
 *
 **********************************************************************************/
        return retrieve(prefix, false);
    }

private:

    inline bool retrieve(const string& key, bool isWord) {
        if (key.size() <= 0) return false;
        TrieNode * node = root;
        for (int i=0; i<key.length(); i++) {
            if (node->children.find(key[i]) == node->children.end()) {
                return false;
            }
            node = node->children[key[i]];
        }
        return isWord ? node->isWord : true;
    }

    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
#endif
#if WildCard
The reason that the iterative solution is much faster for this case is we only need to save (and
    deal with) the positions (iStar for s, jStar for p) of the last "" we met. We only need to do
traceback using iStar and jStar and all the previous "" can be ignored since the last "" will cover
all the traceback cases for the previous "". What we need to do are

if the current p character is '' (i.e. p[j]==''), then we update iStar and jStar with the cureent i
and j values. iStar/jStar will be used for traceback. Also we do --i to start the depth first search
with the case that '*' represents a null string. if p[j]!='', then we check if mismatch occurs (i.e.
    p[j]!=s[i] and p[j]!='?'), if so we check if we met a '' before (iStar>=0), if not, then we
return false since no match can achieve. Otherwise, we traceback to the positions at which the last
'*' happens and do the next possible dfs search (i.e. i = iStar++; j = jStar; remember to update
    iStar too to save the i position to try in the next traceback). The loop will quit when we reach
the end of s. At last, we need to skip all the '*' in p to see if we can reach the end of p. if so,
    match, otherwise mismatch
class Solution {
public:
    bool isMatch(string s, string p) {
        int  slen = s.size(), plen = p.size(), i, j, iStar=-1, jStar=-1;

        for(i=0,j=0 ; i<slen; ++i, ++j)
        {
            if(p[j]=='*')
            { //meet a new '*', update traceback i/j info
                iStar = i;
                jStar = j;
                --i;
            }
            else
            {
                if(p[j]!=s[i] && p[j]!='?')
                {  // mismatch happens
                    if(iStar >=0)
                    { // met a '*' before, then do traceback
                        i = iStar++;
                        j = jStar;
                    }
                    else return false; // otherwise fail
                }
            }
        }
        while(p[j]=='*') ++j;
        return j==plen;
    }
};
A DP solution is also given here. It has O(N^2) time complexity and O(N) space

class Solution {
public:
    bool isMatch(string s, string p) {
        int pLen = p.size(), sLen = s.size(), i, j, k, cur, prev;
        if(!pLen) return sLen == 0;
        bool matched[2][sLen+1];
        fill_n(&matched[0][0], 2*(sLen+1), false);

        matched[0][0] = true;
        for(i=1; i<=pLen; ++i)
        {
            cur = i%2, prev= 1-cur;
            matched[cur][0]= matched[prev][0] && p[i-1]=='*';
            if(p[i-1]=='*') for(j=1; j<=sLen; ++j) matched[cur][j] = matched[cur][j-1] || matched[prev][j];
            else for(j=1; j<=sLen; ++j)            matched[cur][j] =  matched[prev][j-1] && (p[i-1]=='?' || p[i-1]==s[j-1]) ;
        }
            return matched[cur][sLen];
    }
};
A recursion version. A typical recursion version will give us TLE due to too many unnecessary recursive calls. As we explained, all the traceback recursive calls at the '' we met (except the last '') are unneccessary and should be avoided. In the below version, we use recLevel to track the recursion level (i.e the total '' we met) and we also use curLevel to save the order of '' we currently process. If it is not the last '' we met (i.e if(recLevel>curLevel+1) ), then we will return false directly ( if(recLevel>curLevel+1) return false;) to skip all unneccessary recursion call at the '' before the last '*'.

class Solution {
private:
    bool helper(const string &s, const string &p, int si, int pi, int &recLevel)
    {
        int sSize = s.size(), pSize = p.size(), i, curLevel = recLevel;
        bool first=true;
        while(si<sSize && (p[pi]==s[si] || p[pi]=='?')) {++pi; ++si;} //match as many as possible
        if(pi == pSize) return si == sSize; // if p reaches the end, return
        if(p[pi]=='*')
        { // if a star is met
            while(p[++pi]=='*'); //skip all the following stars
            if(pi>=pSize) return true; // if the rest of p are all star, return true
            for(i=si; i<sSize; ++i)
            {   // then do recursion
                if(p[pi]!= '?' && p[pi]!=s[i]) continue;
                if(first) {++recLevel; first = false;}
                if(helper(s, p, i, pi, recLevel)) return true;
                if(recLevel>curLevel+1) return false; // if the currently processed star is not the last one, return
            }
        }
        return false;
    }
public:
    bool isMatch(string s, string p) {
        int recLevel = 0;
        return helper(s, p, 0, 0, recLevel);
    }
};
#endif
