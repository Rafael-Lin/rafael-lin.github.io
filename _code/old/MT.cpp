
#include "stdafx.h"
#include "MT.h"
#include "string"
#include<algorithm>
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


MT::MT() {
}

int addDigits(int num) {
  /*
  258. Add Digits My Submissions Question
  Total Accepted: 59184 Total Submissions: 123616 Difficulty: Easy
  Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

  For example:

  Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.

  Follow up:
  Could you do it without any loop/recursion in O(1) runtime?

  Hint:

  A naive implementation of the above process is trivial. Could you come up with other methods?
  What are all the possible results?
  How do they occur, periodically or randomly?
  You may find this Wikipedia article useful.
  */
  int ret = 0;
  ret = num;
  while (ret > 9){
    int tmp = 0;
    tmp += ret % 10;
    tmp += ret / 10;
    ret = tmp;
  }
  return ret;
}


string addBinary(string a, string b) {
	/**********************************************************************************
	*
	* Given two binary strings, return their sum (also a binary string).
	*
	* For example,
	* a = "11"
	* b = "1"
	* Return "100".
	*
	*
	**********************************************************************************/
	int alen = a.size();
	int blen = b.size();
	bool carry = false;
	string result;
	while (alen>0 || blen>0) {
		int abit = alen <= 0 ? 0 : a[alen - 1] - '0';
		int bbit = blen <= 0 ? 0 : b[blen - 1] - '0';
		int cbit = carry ? 1 : 0;
		result.insert(result.begin(), '0' + ((abit + bbit + cbit) & 1));
		carry = (abit + bbit + cbit>1);
		alen--; blen--;
	}
	if (carry){
		result.insert(result.begin(), '1');
	}
	return result;
}

int myAtoi(string str) {
	/**********************************************************************************
	*
	* Implement atoi to convert a string to an integer.
	*
	* Hint: Carefully consider all possible input cases. If you want a challenge,
	*       please do not see below and ask yourself what are the possible input cases.
	*
	* Notes:
	*   It is intended for this problem to be specified vaguely (ie, no given input specs).
	*   You are responsible to gather all the input requirements up front.
	*
	*
	* Requirements for atoi:
	*
	* The function first discards as many whitespace characters as necessary until the first
	* non-whitespace character is found. Then, starting from this character, takes an optional
	* initial plus or minus sign followed by as many numerical digits as possible, and interprets
	* them as a numerical value.
	*
	* The string can contain additional characters after those that form the integral number,
	* which are ignored and have no effect on the behavior of this function.
	*
	* If the first sequence of non-whitespace characters in str is not a valid integral number,
	* or if no such sequence exists because either str is empty or it contains only whitespace
	* characters, no conversion is performed.
	*
	* If no valid conversion could be performed, a zero value is returned. If the correct value
	* is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648)
	* is returned.
	*
	**********************************************************************************/

	long result = 0;
	int indicator = 1;
	for (int i = 0; i<str.size();)
	{
		i = str.find_first_not_of(' ');
		if (str[i] == '-' || str[i] == '+')
			indicator = (str[i++] == '-') ? -1 : 1;
		while ('0' <= str[i] && str[i] <= '9')
		{
			result = result * 10 + (str[i++] - '0');
			if (result*indicator >= INT_MAX) return INT_MAX;
			if (result*indicator <= INT_MIN) return INT_MIN;
		}
		return result*indicator;
	}
}

string base26_int2str(long long n) {
	string ret;
	while (n>0){
		char ch = 'A' + (n - 1) % 26;
		ret.insert(ret.begin(), ch);
		n -= (n - 1) % 26;
		n /= 26;
	}
	return ret;
}

string convertToTitle(int n) {
	/**********************************************************************************
	*
	* Given a positive integer, return its corresponding column title as appear in an Excel sheet.
	*
	* For example:
	*
	*     1 -> A
	*     2 -> B
	*     3 -> C
	*     ...
	*     26 -> Z
	*     27 -> AA
	*     28 -> AB
	*
	* Credits:Special thanks to @ifanchu for adding this problem and creating all test cases.
	*
	**********************************************************************************/
	return base26_int2str(n);
}

long long base26_str2int(string& s){
	long long ret = 0;
	for (int i = 0; i<s.size(); i++){
		int n = s[i] - 'A' + 1;
		ret = ret * 26 + n;
	}
	return ret;
}

int titleToNumber(string s) {
	/**********************************************************************************
	*
	* Related to question Excel Sheet Column Title
	* Given a column title as appear in an Excel sheet, return its corresponding column number.
	*
	* For example:
	*     A -> 1
	*     B -> 2
	*     C -> 3
	*     ...
	*     Z -> 26
	*     AA -> 27
	*     AB -> 28
	*
	* Credits:Special thanks to @ts for adding this problem and creating all test cases.
	*
	**********************************************************************************/
	return base26_str2int(s);
}

bool isUgly(int num) {
	/***************************************************************************************
	*
	* Write a program to check whether a given number is an ugly number.
	*
	* Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For
	* example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.
	*
	* Note that 1 is typically treated as an ugly number.
	*
	* Credits:Special thanks to @jianchao.li.fighter for adding this problem and creating
	* all test cases.
	*
	***************************************************************************************/
	if (num == 0) return false;
	if (num == 1) return true;
	//becasue the 2,3,5 are prime numbers, so, we just simply remove each factors 
	//by keeping dividing them one by one 
	while (num % 2 == 0) num /= 2;
	while (num % 3 == 0) num /= 3;
	while (num % 5 == 0) num /= 5;

	return num == 1;
}
int min(int a, int b, int c) {
	return min(min(a, b), c);
}


int nthUglyNumber01(int n) {

	int i = 0, j = 0, k = 0;
	vector<int> v(1, 1);

	while (v.size() < n){
		int next = min(v[i] * 2, v[j] * 3, v[k] * 5);
		if (next == v[i] * 2) i++;
		if (next == v[j] * 3) j++;
		if (next == v[k] * 5) k++;
		v.push_back(next);
	}
	return v.back();
}

int nthUglyNumber02(int n) {
	// This version just uses the static variable to cache 
	// the 3 indics and the ugly number list

	static int i = 0, j = 0, k = 0;
	static vector<int> v(1, 1);

	if (v.size() >= n) return v[n - 1];

	while (v.size() < n){
		int next = min(v[i] * 2, v[j] * 3, v[k] * 5);
		if (next == v[i] * 2) i++;
		if (next == v[j] * 3) j++;
		if (next == v[k] * 5) k++;
		v.push_back(next);
	}
	return v.back();
}

int nthUglyNumber(int n) {
	/***************************************************************************************
	*
	* Write a program to find the n-th ugly number.
	*
	* Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For
	* example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
	*
	* Note that 1 is typically treated as an ugly number.
	*
	*   The naive approach is to call isUgly for every number until you reach the nth one.
	* Most numbers are not ugly. Try to focus your effort on generating only the ugly ones.
	*
	*   An ugly number must be multiplied by either 2, 3, or 5 from a smaller ugly number.
	*
	*   The key is how to maintain the order of the ugly numbers. Try a similar approach
	* of merging from three sorted lists: L1, L2, and L3.
	*
	*   Assume you have Uk, the kth ugly number. Then Uk+1 must be Min(L1 * 2, L2 * 3, L3
	* * 5).
	*
	* Credits:Special thanks to @jianchao.li.fighter for adding this problem and creating
	* all test cases.
	*
	***************************************************************************************/

	/*
	The idea is we generate the ugly number instead of checking every number.

	To generate the next ugly number, we can use the existed ugly numbers to multipy 2,3,5,
	and get the minimal one.

	Let's start from the first ugly number - [1]

	[1]  next = min( 1*2=2, 1*3=3, 1*5=5) = 2

	Now we have [1,2], we can see, only the second one need be multipied by 2
	but both 3 and 5 still need be multipied by first one. So:

	[1,2]  next = min(2*2=4, 1*3=3, 1*5=5) = 3

	Now we have [1,2,3], we can see the second one need be mulityped by 2 and 3,
	but the 5 still needs be multipied by first one. So:

	[1,2,3]  next = min (2*2, 2*3, 1*5) = 4

	and so on...

	So, we can see we need to maintain three indics in ugly number list,
	each one represents the place need be mulipied by 2,3,5.

	And we increase the index who's multiplication is the minimal.
	*/
	return nthUglyNumber02(n); // 4ms-8ms
	return nthUglyNumber01(n); // 28ms
}

bool isPowerOfThree(int n) {
	/***************************************************************************************
	*
	* Given an integer, write a function to determine if it is a power of three.
	*
	*     Follow up:
	*     Could you do it without using any loop / recursion?
	*
	* Credits:Special thanks to @dietpepsi for adding this problem and creating all test
	* cases.
	*
	***************************************************************************************/
	for (; n>0; n /= 3){
		if (n == 1 || n == 3) return true;
		if (n % 3 != 0) return false;
	}
	return false;
}

int trailingZeroes(int n) {
	/**********************************************************************************
	*
	* Given an integer n, return the number of trailing zeroes in n!.
	*
	* Note: Your solution should be in polynomial time complexity.
	*
	* Credits:Special thanks to @ts for adding this problem and creating all test cases.
	*
	**********************************************************************************/

	/*
	* The idea is:
	*
	*  1. The ZERO comes from 10.
	*  2. The 10 comes from 2 x 5
	*  3. And we need to account for all the products of 5 and 2. likes 4กั5 = 20 ...
	*  4. So, if we take all the numbers with 5 as a factor, we'll have way more than enough even numbers
	*     to pair with them to get factors of 10
	*
	* **Example One**
	*
	* How many multiples of 5 are between 1 and 23?
	* There is 5, 10, 15, and 20, for four multiples of 5. Paired with 2's from the even factors,
	* this makes for four factors of 10, so: **23! has 4 zeros**.
	*
	*
	* **Example Two**
	*
	* How many multiples of 5 are there in the numbers from 1 to 100?
	*
	* because   100 กา 5 = 20, so, there are twenty multiples of 5 between 1 and 100.
	*
	* but wait, actually 25 is 5กั5, so each multiple of 25 has an extra factor of 5,
	* ( e.g. 25 กั 4 = 100กAwhich introduces extra of zero )
	*
	* So, we need know how many multiples of 25 are between 1 and 100? Since 100 กา 25 = 4,
	* (there are four multiples of 25 between 1 and 100)
	*
	* Finally, we get 20 + 4 = 24 trailing zeroes in 100!
	*
	*
	* The above example tell us, we need care about 5, 5กั5, 5กั5กั5, 5กั5กั5กั5 ....
	*
	* **Example Three**
	*
	*
	* 5^1 :  4617 กา 5 = 923.4, so we get 923 factors of 5
	* 5^2 :  4617 กา 25 = 184.68, so we get 184 additional factors of 5
	* 5^3 :  4617 กา 125 = 36.936, so we get 36 additional factors of 5
	* 5^4 :  4617 กา 625 = 7.3872, so we get 7 additional factors of 5
	* 5^5 :  4617 กา 3125 = 1.47744, so we get 1 more factor of 5
	* 5^6 :  4617 กา 15625 = 0.295488, which is less than 1, so stop here.
	*
	* Then 4617! has 923 + 184 + 36 + 7 + 1 = 1151 trailing zeroes.
	*
	*/
	int result = 0;
	//To avoid the integer overflow ( e.g. 'n >=1808548329' )
	for (long long i = 5; n / i>0 && i <= INT_MAX; i *= 5){
		result += (n / i);
	}
	return result;
}
bool isPalindrome(int x) {
	/**********************************************************************************
	*
	* Determine whether an integer is a palindrome. Do this without extra space.
	*
	*
	* Some hints:
	*
	* Could negative integers be palindromes? (ie, -1)
	*
	* If you are thinking of converting the integer to string, note the restriction of using extra space.
	*
	* You could also try reversing an integer. However, if you have solved the problem "Reverse Integer",
	* you know that the reversed integer might overflow. How would you handle such case?
	*
	* There is a more generic way of solving this problem.
	*
	*
	**********************************************************************************/

	if (x<0) {
		return false;
	}

	int len = 1;
	for (len = 1; (x / len) >= 10; len *= 10);

	while (x != 0) {
		int left = x / len;
		int right = x % 10;

		if (left != right){
			return false;
		}

		x = (x%len) / 10;
		len /= 100;
	}
	return true;
}

int reversePalindrome(int x) {
	int y = 0;

	int n;
	while (x != 0){
		n = x % 10;
		y = y * 10 + n;
		x /= 10;
	}
	return y;
}

bool isPalindrome2(int x) {
	return (x >= 0 && x == reversePalindrome(x));
}

namespace leetcode
{
	class Point {
	public:
		Point(int _x, int _y) :x(_x), y(_y) {}
		int x, y;
	};

	class Rectangle {
	public:
		Rectangle(int a, int b, int c, int d) :topLeft(a, d), bottomRight(c, b) { }
		int Area(){
			return (bottomRight.x - topLeft.x)*(topLeft.y - bottomRight.y);
		}

		int InclusiveArea(Rectangle &r){
			// I include it
			if (r.topLeft.x >= topLeft.x && r.bottomRight.x <= bottomRight.x &&
				r.topLeft.y <= topLeft.y && r.bottomRight.y >= bottomRight.y) {
				return this->Area();
			}
			// it includes me
			if (r.topLeft.x <= topLeft.x && r.bottomRight.x >= bottomRight.x &&
				r.topLeft.y >= topLeft.y && r.bottomRight.y <= bottomRight.y) {
				return r.Area();
			}
			// 0 - no inclusive
			return 0;
		}

		int OverlappedArea(Rectangle &r) {
			int overlap_x = max(0, min(r.bottomRight.x, bottomRight.x) - max(r.topLeft.x, topLeft.x));
			int overlap_y = max(0, min(r.topLeft.y, topLeft.y) - max(r.bottomRight.y, bottomRight.y));
			return overlap_x * overlap_y;
		}

		Point topLeft;
		Point bottomRight;
	};
};

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
	using namespace leetcode;
	Rectangle r1(A, B, C, D);
	Rectangle r2(E, F, G, H);
	int area = r1.InclusiveArea(r2);
	if (area > 0) return area;
	return r1.Area() + r2.Area() - r1.OverlappedArea(r2);
}

int reverse(int x) {

	/**********************************************************************************
	*
	* Reverse digits of an integer.
	*
	* Example1: x =  123, return  321
	* Example2: x = -123, return -321
	*
	*
	* Have you thought about this?
	*
	* Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!
	*
	* > If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.
	*
	* > Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer,
	*   then the reverse of 1000000003 overflows. How should you handle such cases?
	*
	* > Throw an exception? Good, but what if throwing an exception is not an option?
	*   You would then have to re-design the function (ie, add an extra parameter).
	*
	*
	**********************************************************************************/
	int y = 0;
	int n;
	while (x != 0){
		n = x % 10;
		//Checking the over/underflow.
		//Actually, it should be y>(INT_MAX-n)/10, but n/10 is 0, so omit it.
		if (y > INT_MAX / 10 || y < INT_MIN / 10){
			return 0;
		}
		y = y * 10 + n;
		x /= 10;
	}
	return y;
}

string multiply(string& num, char ch){
	int n = ch - '0';
	string s;
	int carry = 0;
	int x;
	for (int i = num.size() - 1; i >= 0; i--){
		x = (num[i] - '0') * n + carry;
		carry = x / 10;
		s.insert(s.begin(), x % 10 + '0');
	}
	if (carry>0) {
		s.insert(s.begin(), carry + '0');
	}
	return s;
}

string strPlus(string& num1, string& num2) {
	string s;
	int carry = 0;
	int x;
	int n1 = num1.size();
	int n2 = num2.size();

	int i, j;
	for (i = n1 - 1, j = n2 - 1; i >= 0 || j >= 0; i--, j--){
		int x1 = i >= 0 ? num1[i] - '0' : 0;
		int x2 = j >= 0 ? num2[j] - '0' : 0;
		x = x1 + x2 + carry;
		carry = x / 10;
		s.insert(s.begin(), x % 10 + '0');
	}
	if (carry>0) {
		s.insert(s.begin(), carry + '0');
	}
	return s;
}

string multiply(string num1, string num2) {
	/**********************************************************************************
	*
	* Given two numbers represented as strings, return multiplication of the numbers as a string.
	*
	* Note: The numbers can be arbitrarily large and are non-negative.
	*
	**********************************************************************************/

	if (num1.size() <= 0 || num2.size() <= 0) return "";

	int shift = 0;
	string result = "0";
	for (int i = num1.size() - 1; i >= 0; i--) {
		string s = multiply(num2, num1[i]);
		for (int j = 0; j<shift; j++){
			s.insert(s.end(), '0');
		}
		result = strPlus(result, s);
		shift++;
	}
	//check if it is zero
	if (result[0] == '0') return "0";
	return result;
}

int countDigitOne(int n) {
  /**********************************************************************************
  *
  * Given an integer n, count the total number of digit 1 appearing in all non-negative
  * integers less than or equal to n.
  *
  * For example:
  * Given n = 13,
  * Return 6, because digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.
  *
  *   Beware of overflow.
  *
  **********************************************************************************/
  
    /*
    for each number, assumed we set it as 1 and see how many possibility it could have.
    for example : 392
    if we assumed 2 as 1 -> then total possibility would be : 00~39 : 40
    if we assumed 9 as 1 -> then total possibility would be : 00~39 : 40, noted that it's not 32 since for the 2, it could be 0-9
    if we assumed 3 as 1 -> then total possibility would be : 00~99 : 100
    so, the total 1 would be 40 + 40 + 100 = 180;
    */

  int rearSize = 1;
  long mod = 1;
  int count = 0;
  while (mod <= n){
    long front = n / (mod * 10);
    long rear = n % mod;
    int curDigit = (int)(n % (mod * 10)) / rearSize;

    if (curDigit > 1){
      count += ((front + 1) * rearSize);
    }
    else if (curDigit == 1){
      count += (front * rearSize + rear + 1);
    }
    else{
      count += (front * rearSize);
    }

    mod *= 10;
    rearSize *= 10;
  }
  return count;
}

int MT::firstMissingPositive(vector<int>& nums) {

  /**********************************************************************************
  *
  * Given an unsorted integer array, find the first missing positive integer.
  *
  * For example,
  * Given [1,2,0] return 3,
  * and [3,4,-1,1] return 2.
  *
  * Your algorithm should run in O(n) time and uses constant space.
  *
  *
  **********************************************************************************/
  /*
  *  Idea:
  *
  *    We can move the num to the place whcih the index is the num.
  *
  *    for example,  (considering the array is zero-based.
  *       1 => A[0], 2 => A[1], 3=>A[2]
  *
  *    Then, we can go through the array check the i+1 == A[i], if not ,just return i+1;
  *
  *    This solution comes from StackOverflow.com
  *    http://stackoverflow.com/questions/1586858/find-the-smallest-integer-not-in-a-list

  When we find 5, then swap it with A[4].

  1. if A[i] < 1 || A[i] > n , it must not be the "First missing positive, next
  2. if A[i] == i+1, then it's at the correct position
  3. if A[i] != i + 1 and 0 < A[i] < n, then we should swap these two number

  */

  int n = nums.size();
  for (int i = 0; i < n; i++)
  while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]){
    //printf("swap : %d, %d\n", nums[i], nums[nums[i] - 1]);
    swap(nums[i], nums[nums[i] - 1]);
  }
  for (int i = 0; i < n; i++)
  if (nums[i] != i + 1)
    return i + 1;
  return n + 1;
}

int findDuplicate(vector<int>& nums)
{
  /***************************************************************************************
  *
  * Given an array nums containing n + 1 integers where each integer is between 1 and
  * n (inclusive), prove that at least one duplicate number must exist.
  * Assume that there is only one duplicate number, find the duplicate one.
  *
  * Note:
  * > You must not modify the array (assume the array is read only).
  * > You must use only constant, O(1) extra space.
  * > Your runtime complexity should be less than O(n2).
  * > There is only one duplicate number in the array, but it could be repeated more than
  *   once.
  *
  * Credits:
  * Special thanks to @jianchao.li.fighter for adding this problem and creating all test
  * cases.
  *
  ***************************************************************************************/
  /*
  // This problem can be transfromed to "Linked List Cycle" problem.
  // There are two pointers, one goes one step, another goes two steps.
  //
  // Refer to: https://en.wikipedia.org/wiki/Cycle_detection

  */

  if (nums.size() > 1)
  {
    int slow = nums[0];
    int fast = nums[nums[0]];
    while (slow != fast)
    {
      slow = nums[slow];
      fast = nums[nums[fast]];
    }

    fast = 0;
    while (fast != slow)
    {
      fast = nums[fast];
      slow = nums[slow];
    }
    return slow;
  }
  return -1;
}

