* swap :

void swap(char &a, char &b){
    a = a^b;
    b = a^b;
    a = a^b;
}

* freopen :


    freopen("1.7.in", "r", stdin);


* bit_xor :
*/ bit_xor example
#include <iostream>     // std::cout
#include <functional>   // std::bit_xor
#include <algorithm>    // std::accumulate
#include <iterator>     // std::end

int main () {
  int flags[] = {1,2,3,4,5,6,7,8,9,10};
  int acc = std::accumulate (flags, std::end(flags), 0, std::bit_xor<int>());
  std::cout << "xor: " << acc << '\n';
  return 0;
}

xor : 11

* minus :
// minus example
#include <iostream>     // std::cout
#include <functional>   // std::minus
#include <algorithm>    // std::transform

int main () {
  int numbers[]={10,20,30};
  int result;
  result = std::accumulate (numbers, numbers+3, 100, std::minus<int>());
  std::cout << "The result of 100-10-20-30 is " << result << ".\n";
  return 0;
}

// he result of 100-10-20-30 is 40.
* accumulate
// accumulate example
#include <iostream>     // std::cout
#include <functional>   // std::minus
#include <numeric>      // std::accumulate

int myfunction (int x, int y) {return x+2*y;}
struct myclass {
	int operator()(int x, int y) {return x+3*y;}
} myobject;

int main () {
  int init = 100;
  int numbers[] = {10,20,30};

  std::cout << "using default accumulate: ";
  std::cout << std::accumulate(numbers,numbers+3,init);
  std::cout << '\n';

  std::cout << "using functional's minus: ";
  std::cout << std::accumulate (numbers, numbers+3, init, std::minus<int>());
  std::cout << '\n';

  std::cout << "using custom function: ";
  std::cout << std::accumulate (numbers, numbers+3, init, myfunction);
  std::cout << '\n';

  std::cout << "using custom object: ";
  std::cout << std::accumulate (numbers, numbers+3, init, myobject);
  std::cout << '\n';

  return 0;
}

using default accumulate: 160
using functional's minus: 40
using custom function: 220
using custom object: 280

* iota

// iota example
#include <iostream>     // std::cout
#include <numeric>      // std::iota

int main () {
  int numbers[10];

  std::iota (numbers,numbers+10,100);

  std::cout << "numbers:";
  for (int& i:numbers) std::cout << ' ' << i;
  std::cout << '\n';

  return 0;
}
numbers: 100 101 102 103 104 105 106 107 108 109
* find_if

// find_if example
#include <iostream>     // std::cout
#include <algorithm>    // std::find_if
#include <vector>       // std::vector

bool IsOdd (int i) {
  return ((i%2)==1);
}

int main () {
  std::vector<int> myvector;

  myvector.push_back(10);
  myvector.push_back(25);
  myvector.push_back(40);
  myvector.push_back(55);

  std::vector<int>::iterator it = std::find_if (myvector.begin(), myvector.end(), IsOdd);
  std::cout << "The first odd value is " << *it << '\n';

  return 0;
}

Output:
The first odd value is 25
* swap_ranges

// swap_ranges example
#include <iostream>     // std::cout
#include <algorithm>    // std::swap_ranges
#include <vector>       // std::vector

int main () {
  std::vector<int> foo (5,10);        // foo: 10 10 10 10 10
  std::vector<int> bar (5,33);        // bar: 33 33 33 33 33

  std::swap_ranges(foo.begin()+1, foo.end()-1, bar.begin());

  // print out results of swap:
  std::cout << "foo contains:";
  for (std::vector<int>::iterator it=foo.begin(); it!=foo.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  std::cout << "bar contains:";
  for (std::vector<int>::iterator it=bar.begin(); it!=bar.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}

// out
//foo contains: 10 33 33 33 10
//bar contains: 10 10 10 33 33
//
* permuteUnique
// GFG

// Program to print all permutations of a string in sorted order.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Following function is needed for library function qsort(). */
int compare(const void *a, const void * b) {
  return ( *(char *)a - *(char *)b );
}

// A utility function two swap two characters a and b
void swap(char* a, char* b) {
  char t = *a;
  *a = *b;
  *b = t;
}

// This function finds the index of the smallest character
// which is greater than 'first' and is present in str[l..h]
int findCeil(char str[], char first, int l, int h) {
  // initialize index of ceiling element
  int ceilIndex = l;

  // Now iterate through rest of the elements and find
  // the smallest character greater than 'first'
  for (int i = l+1; i <= h; i++)
    if (str[i] > first && str[i] < str[ceilIndex])
      ceilIndex = i;

  return ceilIndex;
}

// Print all permutations of str in sorted order
void sortedPermutations(char str[]) {
  // Get size of string
  int size = strlen(str);

  // Sort the string in increasing order
  qsort(str, size, sizeof( str[0] ), compare);

  // Print permutations one by one
  bool isFinished = false;
  while (!isFinished) {
    // print this permutation
    static int x = 1;
    printf("%d  %s \n", x++, str);

    // Find the rightmost character which is smaller than its next
    // character. Let us call it 'first char'
    int i;
    for (i = size - 2; i >= 0; --i)
      if (str[i] < str[i+1])
        break;

    // If there is no such chracter, all are sorted in decreasing order,
    // means we just printed the last permutation and we are done.
    if (i == -1)
      isFinished = true;
    else {
      // Find the ceil of 'first char' in right of first character.
      // Ceil of a character is the smallest character greater than it
      int ceilIndex = findCeil(str, str[i], i + 1, size - 1);

      // Swap first and second characters
      swap(&str[i], &str[ceilIndex]);

      // Sort the string on right of 'first char'
      qsort(str + i + 1, size - i - 1, sizeof(str[0]), compare);
    }
  }
}

// Driver program to test above function
int main() {
  char str[] = "ACBC";
  sortedPermutations( str );
  return 0;
}

* stringstream :

string vecToStr(vector<int> v) {
  stringstream ss;
  for (int i=0; i<v.size(); i++) {
    ss << v[i];
  }
  return ss.str();
}
