chapter 4 functions and program structure

declaration
definition

4.1 basics of functions

#include <stdio.h>
#define MAXLINE 1000
int getline( char line[], int max ) ;
int strindex( char source[], char searchfor[] );
char pattern[] = "ould";
main()
{
	char line[MAXLINE] ;
	int found = 0 ;
	while( getline( line, MAXLINE ) > 0 ){
		if( strindex( line, pattern ) >= 0 ){
			printf( "%s", line ) ;
			found ++ ;
		}
	}
	return found ;
}
int getline( char s[], int lim )
{
	int c, i ;
	i = 0 ;
	while( --lim > 0 && ( c = getchar()) != EOF && c != '\n' )
		s[i++] =  c ;
	if( c == '\n' )
		s[i++] = c ;
	s[i] = '\0' ;
	return i ;
}
int strindex( char s[], char t[] )
{
	int i, j, k ;
	for( i = 0 ; s[i] != '\0' ; i ++ ){
		for( j = i , k = 0 ; t[k] != '\0' && s[j] == t[k] ; j++, k ++ )
			;
		if( k>0 && t[k] == '\0' )
			return 1 ;
	}
	return -1;
}

cc main.c getline.c strindex.c
//generate a.out
4.2 functions returning non-integers

#include <ctype.h>

double atof( char s[] )
{
	double val, power ;
	int i, sign ;
	for( i = 0 ; isspace(s[i]) ; i ++ )
		;
	sign = ( s[i] == '-' ) -1 : 1 ;
	if( s[i] == '+' || s[i] == '-' )
		i++ ;
	for( val = 0.0 ; isdigit( s[i] ) ; i ++ )
		val = 10.0 * val + ( s[i] - '0' ) ;
	if (s[i] == '.' )
		i ++ ;
	for ( power = 1.0 ; isdigit( s[i] ) ; i ++ ) {
		val = 10.0 * val + ( s[i] - '0' ) ;
		power *= 10.0 ;
	}
	return sign * val / power ;

}
#include <stdio.h>
#define MAXLINE 1000
main()
{
	double sum, atof( char [] ) ;
	char line[MAXLINE] ;
	int getline( char line [], int max ) ;
	sum = 0 ;
	while( getline( line, MAXLINE ) > 0 ){
		printf( "\t%g\n", sum += atof( line ) ) ;
	}
	return 0 ;
}

postfix notation : RPN ; Reverse Polish Notation
( 1 - 2 ) * ( 4 + 5 )
1 2 - 4 5 + *

#include <stdio.h>
#include <math.h>

#define MAXOP 100
#define NUMBER '0'

int getop( char [] ) ;
void push ( double ) ;
double pop( void ) ;

main()
{
	int type;
	double op2 ;
	char s[MAXOP] ;

	while( ( type = getop(s) != EOF )){
		switch( type ){
			case NUMBER :
				push( atof(s) ) ;
				break;
			case '+' :
				push( pop() + pop() ) ;
				break;
			case '*' :
				push( pop() * pop() ) ;
				break;
			case '-' :
				op2 = pop() ;
				push( pop() - op2 ) ;
				break;
			case '/' :
				op2 = pop() ;
				if( op2 != 0.0 )
					push( pop() / op2 ) ;
				else
					printf("error: zero divisor\n") ;
				break;
			case '\n' :
				printf("\t%.8g\n", pop() ) ;
				break;
			default :
				printf("error" ) ;
				break ;
		}
	}
}

#define MAXVAL 100
int sp = 0 ;
double val[MAXVAL] ;

void push( double f)
{
	if( sp < MAXVAL )
		val[sp++] = f ;
	else
		printf("Error");
}
double pop( void )
{
	if (sp > 0 )
		return val[--sp] ;
	else{
		printf("error : stack empty\n" ) ;
		return 0.0 ;
	}
}

===
#include <stdio.h>
#include <ctype.h>
int getch( void ) ;
void ungetch( int ) ;
int getop( char s[] )
{

}

===
Chap 5 Pointers and arrays

Void * : 指向 void的 pointer
P = &C ; // p is the address of C

Int x = 1, y = 2, z[10] ;
Int * ip ;
ip = &x;
*ip = 0 ;
Ip = &z[0];

指向 void 的指標可用來存放任何型別的指標，但卻不能直接用來 dereferencing.

*ip = *ip + 10 ; // * 的 priority is higher than = and +
Y = *ip + 1 ;
*ip +=1 ;  ++ *ip ;
(*ip) ++ // 這個 () 是必要的，因為 ++ 會由右向左做運算，而且會先去做.

Int * iq ;
Iq = ip ; // ip 指到的地方和 iq 一樣。


5.2 pointers and function arguments.

Call by value
Swap( a,b) ;
Void swap( int x, int y ){
Int tmp ;
Tmp = x ;
X = y ;
Y = tmp ;
}

The good method is call by address
Swap( &a, &b) ;
Void swap( int *px, int*py)
{
	Int tmp ;
	Tmp = *px ;
	*px = *py ;
	*py = tmp ;
}

Getint() 

#include < stdio.h>
#include < ctype.h>
Int getch(void);
Void ungetch(int);
// getint : get next integer from input into *pn
int getint( int*pn)
{
    int c, sign;
    While( isspace( c = getch() ))	; // skip the space
    If( !isdigit(c) && C!= EOF && C != ‘+’ && C != ‘-‘ ){
	Unget(c) ; // it’s not a number
	Return 0 ;
    }
    Sign = ( c==’-‘ ) ? -1 : 1 ;
    If( c ==’+’ || c ==’-‘) c = getch();

    For( *pn = 0 ; isdigit(c) ; c = getch() )
	    *pn = 10 * *pn + ( c – ‘0’);
    *pn *= sign ;
    If( c != EOF )
	    Ungetch(c) ;
    Return c ;
}

5.3 pointers and arrays

Int *pa ;
Pa = &a[0]; // pa = a ;
X = *pa // let a[0] ‘s content equal to X

*(pa+1) = a[1] ;
*(pa+2) = a[2];
*(pa+3) = a[3];
*(pa+i) = a[i];
+1  指向下一個元素, address + sizeof( typeof( pa) ) ;

Pointer is variable, 因此 pa = a or pa ++ 是對的.
但是 array is not like variable, so a = pa 或是 a++ 卻是錯的。
如果把 array name a 傳到 function, 事實上是傳 &a[0]

int strlen( char *s )
{
    int n ;
    for( n = 0 ; *s != ‘\0’ ; s ++ )
	n++ ;
    return n ;
}
// 因為  s is pointer, 所以可以對它 ++, 而且他是 local variable, 因此 ++ 後之後並無影響。
Ex : strlen(“honey, I love you”), strlen( array ); , strlen( ptr ) ;

Char s[] ;  char *s ; // 建議用後者
也可以把 array 的一部份傳給 function

F(a+2)  F(&a[2]) ; != F( a[2] ) ;
Function 宣告方式：

F( int arr[] ) {}
F(int *arr) {…} ;

5.4 address arithmetic

Alloc(n) ：傳回一個指票，指客一塊足夠容納 n 個連續字符的記憶區。
Afree(p) : 將會指標 p 的記憶區還回去以便下次使用。
First allocate, First free.

Static external : 有效範圍只在一個原始檔案中.

#define ALLOCSIZE 1000
Static char allocbuf[ ALLOCSIZE] ; // storage for alloc
Static char *allocp = allocbuf ; // next free position ;

char * alloc( int n ) // return position to n characters
{
	if ( allocbuf + ALLOCSIZE - allocp >= n ){
		allocp += n ;
		return allocp =n ;
	}else
		return 0 ;
}
void afree( char * p ) // free storage pointed to by p
{
	if( p > allocbuf && p < allocbuf + ALLOCSIZE )
		allocp = p ;
}







char * alloc( int n ) // return position to n characters
{
	if ( allocbuf + ALLOCSIZE - allocp >= n ){
		// it fits.
		allocp += n ;
		return allocp =n ;
	}else // space is not enough
		return 0 ; // 0 and NULL 是可以共用的。
}
void afree( char * p ) // free storage pointed to by p
{
	if( p > allocbuf && p < allocbuf + ALLOCSIZE )
		allocp = p ;
}
static char *allocp = allocbuf ; // allocp 為指向 char * 並給 initial value , 使它指向陣列 allocbuf 之開頭.
--> static char * allocp = &allocbuf[0] ;

1. p < q // pointer's equal relation, bigger or less or ...
2. p + n // p 加上 n * 元素大小
3. pointer substraction : 如果 p and q 指向同一個 array, 且 p < q , 則 p-q+1 便是 p 到 q 之間的元素個數。

int strlen( char * s) // return the length of the string
{
	char *p = s;
	while( *p != '\0')
		p ++ ;
	return p -s ;
}

* 指向同一個 array，各元素的指標可以相減或相比較
* 指向不同 array 可以做相等或不相等的比較
* 可以設定 0 給 pointer, pointer 對可以對 0 相比較.

5.5 chararcter pointers and functions

char * pmessage ;
char amessage[] = " now is the time " ;
char *pmessage = " now is the time " ;

void strcpy( char *s, char *t )
{
	int i ;
	while( (s[i] = t[i]) != '\0 ')
		i++ ;
}
* != 的 priority 比 = 還要高，所以需要括號

void strcpy( char *s, char *t )
{
	int i ;
	while( (*s= *t) != '\0 ')
		i++ ;
}

void strcpy( char *s, char *t )
{
	while( (*s++= *t++) != '\0 ')
		;
}
//*s++  --> 先取值，再加加
// 做 = operation, 回傳值就是 operand 的內容

void strcpy( char *s, char *t )
{
	while (*s++== *t++)
		;
	// 因為 '\0' 的內容值就是 0 , 所以可以精簡掉
}

int strcmp( char *s, char *t)
{
	// return <0, if s < t
	// return 0 if s == t
	// return > 0, if s > t
	int i ;
	for( i = 0 ; s[i] == t[i] ; i ++ )
		if( s[i] =='\0' )
			return ;
	return s[i] - t[i] ;
}
pointer version
int strcmp( char *s, char *t)
{
	for( ; s[i] == t[i] ; s++, t++)
		if( *s =='\0')
			return ;
	return *s -*t ;
}
* *--p --> pointer 先減一，(指到上一個element), 再把值取出來。

5.6 pointer arrays : pointers to pointers

#include <stdio.h>
#include <string.h>
#define MAXLINES 5000
char *lineptr[ MAXLINES ] ;

int readline( char *lineptr[], int nlines ) ;
void writelines( char *lineptr[], int nlines ) ;
void qsort( char *lineptr[] , int left, int right) ;

main()
{
	int nlines ;
	if(( nlines = readlines( lineptr, MAXLINES )) >= 0 ){
		qsort( lineptr, 0, nlines - 1 ) ;
		writelines( lineptr, nlines ) ;
		return 0 ;
	}else{
		printf("error\n") ;
		return 1;
	}
}
#define MAXLEN 1000
int getline( char *, int ) ;
char *alloc(int);

int readlines( char *lineptr[], int maxlines )
{
	int len, nlines;
	char *p, line[MAXLEN];

	nlines = 0 ;
	while( ( len = getline(line, MAXLEN))> 0){
		if( nlines >=0 MAXLINES || ( p = alloc(len) == NULL ))
			return -1 ;
		else{
			line[len - 1 ] = '\0' ;
			strcpy( p, line) ;
			lineptr[nlines++] p ;
		}
	}
	return nlines ;
}
void writelines( char * lineptr[], int nlines )
{
	int i ;
	for( i = 0 ; i < nlines ; i++ )
		printf("%s\n", lineptr[i]) ;

}
void writelines( char * lineptr[], int nlines )
{
	while( nlines-- > 0)
		printf( "%s\n", *lineptr ++ ) ;
	// *lineptr ++ : 先取用 *lineptr, 再對 lineptr 做 ++
}

void qsort( char * v[], int left, int right )
{
	int i, last;
	void swap( char v[], int i, int j ) ;
	if( left >= right )
		return ;
	swap( v, left, (left + right ) / 2 ) ;
	last = left ;
	for( i = left + 1 ; i < = right ; i ++ )
		if( strcmp( v[i], v[left] ) < 0 )
			swap( v, ++last, i ) ;

	swap( v, left, last ) ; // v[last] is 己經到達定位
	qsort( v, left , last - 1 ) ;
	qsort( v, last+ 1 , right ) ;
}

void swap( char *v[], int i, int j )
{
	char *temp ;
	temp = v[i] ; v[i] = v[j] ; v[j] = temp ;
}

5.7 multi-dimensional arrays

static char daytab[2][13] = {
	{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, },
	{ 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, }
};

int day_of_year( int year, int month, int day)
{
	int i, leap ;
	leap = year%4 == 0 && year%100!=0 || year%400 == 0 ;
	for( i = 0 ; i< month ; i ++ )
		day += daytab[leap][i] ;
	return day ;
}
void month_day( int year, int yearday, int *pmonth, int *pday )
{
	int i, leap ;
	leap = year%4 == 0 && year%100!=0 || year%400 == 0 ;
	for( i = 1 ; yearday > day[tab][i] ; i ++ )
		yearday -= daytab[leap][i] ;
	*pmonth = i ;
	*pday = yearday ;
}

month_day( 1988, 60, &m, &d ) ; // 由第幾天算出是幾月幾號

*raw major : 最右邊的[] 變動的最快，如 c , pascal
*column major :  最左邊的 [] 變動最快, 如 fortran

*transfer into function
f( int daytab[2][13] )
{
	...
}
f( int daytab[][13] )
{
	...
}
f( int (*daytab)[13] )
{
	...
}
* () 是必要的，因為 [] 的優先權高於  *

int *daytab[13] : 有13個元素的 pointer array, 每個元素都是指向整數的 pointer

5.8 initialization of pointer arrays

char *month_name( int n )
{
	static char * name[] = {
		"January", "February", "March", "April", "May",
		"June", "July", "August", "September", "October",
		"November", "December"
	};
	return ( n < 1 || n > 12 ) ? name[0] : name[n] ;
}
5.9 pointers vs. multi-dimensional arrays

int a[10][20] ;
int *b[10] ;

b : 只配置了 10 個元素，每個元素均可存放一個指向整數的指標，而且不會自動設定初值，也就是沒有真正安排要存放整數的位置。
	假設，這10個指標各指向一個有20個元素的陣列，則總共安排了210個元素，包括了 200 個整數和 10 個位址.

char *name[] = { "Illegal month", "Jan", "Feb", "Mar" } ;
char aname[][] = { "Illegal month", "Jan", "Feb", "Mar" } ; // 每項都佔 15 bytes

5.10 command-line arguments

echo hello, world // argv[0] : echo, argv = 3
argc : 至少是1

echo function :
#include < stdio.h>
main( int argc, char *argv[] )
{
	int i ;
	for( i = 0 ; i < argc ; i ++ )
		printf( "%s%s", argv[i], ( i < argc - 1 ) ? " " : "" )  ;
	printf( "\n" ) ;
	return 0 ;
}
/* pointer version */
main( int argc, char *argv[] )
{
	while ( --argc > 0 )
		printf("%s%s", *++argv, ( argc > 1 ) ? " " : "" ) ;
	printf( "\n" ) ;
	return 0 ;
}
#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int getline( char *line, int max ) ;
// find : print lines that match pattern form 1st arg
main( int argc, char *argv[] )
{
	char line[MAXLINE] ;
	int found = 0 ;

	if( argc != 2 )
		printf( "Usage : %s pattern\n", argv[0] ) ;
	else{
		while ( getline(line, MAXLINE) > 0 )
			if( strstr( line, argv[1]) != NULL ){
				printf( "%s", line ) ;
				found ++ ;
			}
	}
	return found ;
}
find -x -n pattern  --> find -nx pattern
x : except
n : line number


#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int getline( char *line, int max ) ;
// find : print lines that match pattern form 1st arg
main( int argc, char *argv[] )
{
	char line[MAXLINE] ;
	long lineno = 0 ;
	int c, except = 0, number = 0, found = 0 ;

	while( --argc > 0 && (*++argv)[0] == '-' )
		while ( c = *++argv[0] ){
			switch( c ) {
				case 'x' :
					except = 1 ;
					break ;
				case 'n' :
					number = 1 ;
					break ;
				default :
					printf( "find: illegal option %c\n", c ) ;
					argc = 0 ;
					found = -1 ;
					break ;
			}
		}
	if( argc != 1)
		printf( "Usage : find -x -n pattern\n" ) ;
	else{
		while ( getline(line, MAXLINE) > 0 )
			lineno++ ;
			if( ( strstr( line, argv[1]) != NULL ) ! = except ){
				if( number )
					printf( "%ld:", lineno ) ;
				printf( "%s", line ) ;
				found ++ ;
			}
	}
	return found ;
}
/*
 *  (*++argv)[0] : 第一個字符，用 () 把 (*argv) 包住是必要的，因為 [] 比 * and ++ 的 priority 還高
 *  */

 5.11 pointers to functions

#include <stdio.h>
#include <string.h>
#define MAXLINES 5000
char *lineptr[ MAXLINES ] ;

int readline( char *lineptr[], int nlines ) ;
void writelines( char *lineptr[], int nlines ) ;
void qsort( void *lineptr[] , int left, int right, int( *comp ) ( void*, void*)) ;
int numcmp( const char *, const char * ) ;

main( argc, char * argv[] )
{
	int nlines ;
	int numeric = 0 ;
	if( argc > 1 && strcmp ( argv[1], "-n" ) == 0 )
		numeric = 1 ;
	if(( nlines = readlines( lineptr, MAXLINES )) >= 0 ){
		qsort( (void **) lineptr, 0, nlines - 1 , ( int (*)( void*, void *))(numeric ? numcmp : strcmp)) ;
		writelines( lineptr, nlines ) ;
		return 0 ;
	}else{
		printf("input too big to sort\n") ;
		return 1;
	}
}
// 傳 numcpm  or strcmp 傳入 function 之中
// int(*)( void *, void * ) numcmp
// int(*)( void *, void * ) strcmp

void qsort( void *v[], int left, int right, int (*comp) ( void *, void *))
{
	int i , last ;
	void swap( void *v[], int, int ) ;
	if( left >= right ) return ;

	swap( v, left, ( left+right) / 2 );
	last = left ;
	for( i = left + 1 ; i <= right ; i ++ )
		if( (*comp)( v[i], v[left] ) < 0 )
			swap( v, ++last, i ) ;
	swap( v, left, last ) ;
	qsort(v, left, last-1, comp )  ;
	qsort(v, last+1 , right, comp )  ;
}
// ( *comp ) ( v[i], v[left] )  : 用 () 把 comp 包住是必要的
//  int * comp ( void *, void * ) : 表示回傳 ( int * )  的 function
int numcmp( char *s1, char *s2 )
{
	double v1, v2 ;
	v1 = atof( s1 ) ;
	v2 = atof( s2 ) ;
	if( v1 < v2 ) return -1 ;
	else if ( v1 > v2 ) return 1 ;
	else return 0 ;
}
void swap( void *[], int i, int j )
{
	void *temp ;
	temp = v[i] ;
	v[i] = v[j] ;
	v[j] = temp ;
}

5.12 complicated declarations

int *f() // f: function returning pointer to int
int (*pf)() ; // pf : pointer to function returning int
// * 的 priority 比  () 還低

char **argv
argv : pointer to pointer to char

int (*daytab)[13]
daytab : array[13] of pointer to int

int *daytab[13]
daytab : array[13] of pointer to int

void * comp()
comp : function returning pointer to void

void (*comp)()
comp : pointer to function returning void

char (*(*x())[]) ()
x : function returning pointer to array[] of pointer to function returning char

太難了

chapter 6 structures

6.1 basics of structures

struct point{
	int x;
	int y;
}
struct {...} x, y, z ;
--> int x, y , z;
struct point pt ;
struct point pt = {320, 200} ;

printf( "%d,%d", pt.x, pt.y ) ;

double dist, sqrt(double);
dist = sqrt( (double) pt.x * pt.x + (double) pt.y * pt.y ) ;

struct rect{
	struct point pt1 ;
	struct point pt2 ;
};
struct rect screen ;
screen.pt.x  = xxx ;

6.2 structures and functions

struct point makepoint( int x, int y )
{
	struct point temp ;
	temp.x = x ;
	temp.y = y ;
	return temp ;
}

struct rect screen ;
struct point middle ;
struct point makepoint( int, int );
screen.pt1 = makepoint(0,0 );
screen.pt2 = makepoint(XMAX, XMAX );

middle_x = (screen.pt1.x + screen.pt2.x) / 2  ;
middle_y = (screen.pt1.y + screen.pt2.y) / 2  ;
middle = makepoint( middle_x, middle_y ) ;

struct point addpoint( struct point p1, struct point p2 )
{
	// call by value
	p1.x += p2.x ;
	p1.y += p2.y ;
	return p1 ;
}
int ptinrect( struct point p, struct rect r )
{
	return ... && ... && ... && ...
}

struct point *pp ;
(*pp).x and (*pp).y is its member

struct point origin, *pp ;
pp = &origin ;
(*pp).x 的 () 是必要的，因為 .  的優先權高於 *
*pp.x --> *(pp.x) 表示 x 是個 pointer

(*pp).x --> pp->x
(*pp).y --> pp->y

struct rect r, *rp = r ;
r.pt1.x
rp->pt1.x

struct {
	int len ;
	char * str ;
}*p ;

++p->len
	: 加len 的值，因為 -> 的權限高於 ++

6.3 arrays of structure

char * keyword[NKEYS]
int keycount[NKEYS]
-->
struct key{
	char *word ;
	int count ;
}keytab[NKEYS];
-->
struct key{
	char *word ;
	int count ;
};
struct key keytab[NKEYS] ;
-->
struct key{
	char *word ;
	int count ;
}keytab[] = {
	"auto", 0,
	"auto", 0,
	"auto", 0,
	"auto", 0,
	"auto", 0,
	...
	// 每一個項次可以再加個大{}

};


#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAXWORD 100
#define NKEYS ( sizeof keytab / sizeof( struct key ) )
#define NKEYS( sizeof keytab / sizeof keytab[0] )

int getword( char *, int ) ;
int binsearch( char *, struct key *, int ) ;

main()
{
	int n ;
	char word[ MAXWORD ] ;

	while ( getword( word, MAXWORD ) != EOF ){
		if ( isalpha( word[0] ))
			if (( n = binsearch( word, key, NKEYS)) >= 0 )
				keytab[n].count ++ ;
	}
	for( n = 0 ; n < NKEYS ; n ++ )
		if( keytab[n].count > 0 )
			printf( "%4d %s\n", keytab[n].count, keytab[n].word ) ;

	return 0 ;
}

int binsearch( char * word, struct key tab[], int n )
{
	int cond ;
	int low, high, mid ;

	low = 0 ;
	high = n-1 ;
	while( low <= high ){
		mid = ( low + high ) / 2 ;
		if( ( count = strcmp( word, tab[mid].word)) < 0 )
			high = mid - 1 ;
		else if ( cond > 0 )
			low = mid + 1 ;
		else
			return mid ;
	}
	return -1 ;
}

int getword( char * word, int lim)
{
	int c, getch(void);
	void ungetch(int);

	char *w = word ;
	while( isspace( c = getch() ))
		;
	if( c != EOF )
		*w ++ = '\0' ;
	if( !isalpha(c)){
		*w = '\0' ;
		return c ;
	}
	for( ; --lim > 0 ; w ++ )
		if( !isalnum( *w = get())){
			ungetch( *w ) ;
			break ;
		}
	*w = '\0' ;
	return word[0] ;
}

6.4 pointers to structures

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <ctype.h>

#define MAXWORD 100

int getword( char *, int ) ;
struct key *binsearch( char *, struct key *, int ) ;

main()
{
	char word[ MAXWORD ] ;
	struct key *p ;

	while ( getword( word, MAXWORD ) != EOF ){
		if ( isalpha( word[0] ))
			if (( p = binsearch( word, key, NKEYS)) != NULL )
				p->count ++ ;

	}
	for( p = keytab ; p < keytab + NKEYS ; p ++ )
		if( p->count > 0 )
			printf( "%4d %s\n", p->count, p->word) ;
	return 0 ;

}
struct key *binsearch( char * word, struct *key tab, int n )
{
	int cond ;
	struct key *low = &tab[0] ;
	struct key *high = &tab[n] ;
	// &tab[n] : pointer 計算時用到最後一個元素的下一個元素
	struct key *mid ;


	while( low < high ){
		mid = low + ( high - low ) / 2 ;
		// high - low : 元素個數
		if( ( cond = strcmp( word, tab[mid].word)) < 0 )
			high = mid ;
		else if ( cond > 0 )
			low = mid + 1 ;
		else
			return mid ;
	}

	return NULL ;
}

6.5 self referential structure

struct tnode{
	char *word;
	int count ;
	struct tnode *left ;
	struct tnode *right;
}
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAXWORD 100

struct tnode *addtree( struct tnode *, char * ) ;
void treeprint( struct tnode * ) ;
int getword( char * , int ) ;

main()
{
	struct tnode *root ;
	char word[MAXWORD] ;
	root = NULL ;
	while( getword( word, MAXWORD ) != EOF )
		if( isalpha( word[0] ))
			root = addtree ( root, word ) ;

	treeprint( root ) ;
	return 0 ;
}

struct tnode *talloc( void ) ;
char  *strup( char * ) ;

struct tnode *addtree( struct tnode *p, char * w )
{
	if( p == NULL ){
		p = talloc();
		p -> word = strdup(w) ;
		p -> count = 1 ;
		p -> left = p -> right = NULL ;
	}else if (( cond = strcmp( w, p->word)) == 0 ){
		p -> count ++ ;
	}else if ( cond < 0 )
		p -> left = addtree( p->left, w );
	else
		p -> right= addtree( p->right, w );
	return p ;
}

void treeprint( struct tnode *p )
{
	if( p!= NULL){
		treeprint( p->left) ;
		printf( "%4d %s\n", p->count, p->word) ;
		treeprint( p->right) ;
	}
}

struct tnode *talloc( void )
{
	return (struct tnode *) malloc( sizeof( struct tnode ) ) ;
	// use cast , 轉出改要的型別
}

char *strdup( char *s)
{
	p = ( char * ) malloc( strlen(s) + 1 ) ;
	if( p != NULL )
		strcpy( p,s) ;
	return p;
}

6.6 Table-lookup

#define IN 1
state = IN ;
install(s,t) : 把名稱 s 和其對應的文字 t  記錄到表格中
looks(s) : 在表格中找到名稱 s

stuct nlist{
	struct nlist *next ;
	char *name ;
	char *defn ;
};

#define HASHSIZE 101
static struct nlist *hasttab[HASHSIZE] ;

/* hash function */
unsigned hash( char *s)
{
	unsigned hashval ;

	for( hashval = 0 ; *s != '\0'; s ++)
		hashval = *s + 31 * hashval ;

	return hashval % HASHSIZE ;
}

struct nlist *lookup( char *s )
{
	struct nlist *np ;
	for ( np = hashtab[ hash( s )] ; np != NULL ; np = np -> next )
		if( strcmp( s, np -> name ) == 0 )
			return np ;
	return NULL ;
}

struct nlist *lookup( char * ) ;
char *strdup( char * ) ;
struct nlist *install( char *name, char *defn))
{
	struct nlist *np ;
	unsigned hashval ;

	if( (np = lookup(name) ) == NULL ){
		np = ( struct nlist *) malloc( sizeof( *np ));
		if( np == NULL || ( np->name = strdup(name)) == NULL )
			return NULL ;
		hashval = hash(name) ;
		np->next = hashtab[hashval];
		hashtabl[hashval] = np ;
	}else
		free( ( void *) np ->defn ) ;

	if( (np->defn = strdup(defn) == NULL )
			return NULL ;
	return np ;
}

6.7 typedef

typedef int Length ;
Length len, maxlen ;
Length *length [] ;

typedef char * String ;
String p, line ptr[MAXLINES], alloc( int ) ;
int strcmp( String, String ) ;
P = ( String ) malloc( 100 ) ;


typedef struct tnode *Treeptr ;
typedef struct tnode {
	char *word ;
	int count ;
	Treeptr left ;
	Treeptr right ;
} Treenode ;

Treeptr talloc( void )
{
	return ( Treeptr ) malloc( sizeof( Treenode)) ;
}

typedef int( *PFI ) ( char *, char * ) ;
PFI strcmp, numcmp ;

6.8 Unions

union u_tag{
	int ival ;
	float fval ;
	char *sval ;
} u ;
u 的 memory space 是三者當中佔用最多的那一項。

member access function : union_name.member, union_pointer->member

if( utype == INT )
	printf("%d\n", u.ival ) ;
else if( utype == FLOAT )
	printf("%d\n", u.fval ) ;
else if( utype == STRING )
	printf("%d\n", u.sval ) ;
else ...

struct{
	char *name;
	int flags;
	int utype;
	union {
		int ival ;
		float fval ;
		char *sval ;
	} u ;
}symtab[NSYM] ;

*symtab[i].u.sval
symtab[i].u.sval[0]
--> sval 的第一個 char

6.9 Bit-fields

#define KEYWORD 01
#define EXTERNAL 02
#define STATIC 04

enum { KEYWORD = 01, EXTERNAL = 02, STATIC = 04 } ;

flag |= EXTERNAL | STATIC ;
flag &= ~( EXTERNAL | STATIC ) ; // 把 static and external 重置為 0

if( ( flag & ( EXTERNAL | STATIC )) == 0 )
	// 在 static 和 external 冏為 0 時 ... 才成立


struct {
	unsigned int is_keyword : 1 ;
	unsigned int is_extern : 1 ;
	unsigned int is_static : 1 ;
}flags ;

由三個單一 bit 的元素所組成的 flags, 其 1 表示用掉幾個 bit

flags.is_extern = flags.is_static = 1 ;
flags.is_extern = flags.is_static = 0 ;

if( flags.is_extern == 0 && flags.is_static == 0 ) ...


Chapter 7 Input and Output

7.1 Standard Input and Output

int getchar( void ) // EOF = -1 ;

	I/O redirection : input from file instead of keyboard
	prog < infile
	otherprog | prog // ..
	prog > outfile

#include <stdio.h> // find files in the /usr/include/



#include <stdio.h>
#include <ctype.h>
	main()
{
	int c ;
	while ( ( c = getchar()) != EOF )
		putchar( tolower(c) ) ;
	return 0 ;
}

7.2 printf( formatted output printf )

	int printf( char *format, arg1, arg2, ...)

	:%s
	:%10s
	:%15.10s:
	佔15 blank, 只取  10 char  出現  //右置
	:%-15.10s:
	--> 左置

	sprintf( char *string, char *format, arg1, arg2, arg3 ... ) ;
	把 ... 輸出到 string

7.3 variable-length argument list

int printf( char *fmt, ... )
	... : 表示不定長度... 個數和  type 不固定。

void minprintf( char *fmt, ... )
	va_list : 宣告一個指向引數的變數.
	va_start :
	va_arg :

void minprintf( char *fmt, ... )
{
	va_list ap ;
	char *p, *sval ;
	int ival ;
	double dval ;
	va_start( ap, fmt) ; // make ap point to 1st unnamed arg
	for( p = fmt ; *p ; p ++) {
		if( *p != '%' ){
			putchar( *p ) ;
			continue ;
		}
		switch( *++p ){
			case 'd' :
				ival = va_arg(ap, int ) ;
				printf( "%d",ival ) ;
				break;
			case 'f' :
				dval = va_arg(ap, double ) ;
				printf( "%f",dval ) ;
				break;
			case 's' :
				for( sval = va_arg( ap, char * ) ; *sval ; sval ++ )
					putchar( *sval ) ;
				break;
			default :
				putchar( *p ) ;
				break ;
			}
	}
	va_end(ap);
}
// should check again.

7.4 scanf( formatted input - scanf )

	int scanf( char *format, ... )
	int sscanf( char *string, chart *format, arg1, arg2, ... ) //read not from the standard input , but from a string
	需要傳 address 進去

#include <stdio.h>
main()
{
	double sum, v ;
	sum = 0 ;
	while( scanf( "%1f", &v ) == 1 )
		printf( "\t%,2f\n", sum += v ) ;
	return 0 ;
}

25 Dec 1988
int day, year;
char monthname[20];
scanf("%d %s %d", &day, monthname, &year ) ;

int day, month, year; // mm/dd/yy
scanf( "%d/%d/%d", &month, &day, &year ) ;

while ( getline( line, sizeof( line ) ) > 0 ){
	if( sscanf( line, "%d %s %d", &day, monthname, &year ) == 3 )
		printf( "valid : %s\n", line  );
	else if(( sscanf( line, "%d/%d/%d"), &month, &day, &year ) == 3 )
		printf( "valid : %s\n", line  );
	else
		printf("invalid : %s\n", line ) ;
}
the parameter should be pointer, not variable name ;

7.5 File Access


FILE *fp ;
FILE *fopen( char *name, char *mode );
fp = fopen( name, mode ) ;
	r : read
	w : write
	a : append
	t : text
	b : binary

int getc( FILE *fp)
int putc( int c, FILE *fp )
	stdin : standard input
	stdout : standard output
	stderr : standard error

#define getchar() getc(stdin)
#define putchar() putc( (c), stdout )

int fscanf( FILE *fp, char *format, ... )
int fprintf( FILE *fp, char *format, ... )

#include <stdio.h>

main( int argc, char *argv[] )
{
	FILE *fp ;
	void filecopy( FILE *, FILE * )
	if( argc == 1 )
		filecopy( stdin, stdout );
	else{
		while( --argc > 0 ){
			if( ( fp = fopen( *++argv, "r")) == NULL ){
				printf( "cat: can't open %s\n", *argv ) ;
				return 1 ;
			}else{
				filecopy( fp, stdout ) ;
				fclose(fp);
			}
		}
	}
	return 0 ;
}
void filecopy( FILE *ifp, FILE *ofp )
{
	int c ;

	while( (c = getc(ifp)) != EOF )
		putc( c, ofp ) ;
}

7.6 Error Handling - stderr and exit

#include < stdio.h>

main( int argc, char *argv[] )
{
	FILE *fp ;
	void filecopy( FILE *, FILE * )
	char *prog = argv[0] ;

	if( argc == 1 )
		filecopy( stdin, stdout );
	else{
		while( --argc > 0 ){
			if( ( fp = fopen( *++argv, "r")) == NULL ){
				fprintf( stderr,  "%s : can't open %s\n", prog, *argv ) ;
				exit( 1 ) ;
			}else{
				filecopy( fp, stdout ) ;
				fclose(fp);
			}
		}
	}
	if( ferror( stdout ) ){
		fprintf( stderr, "%s: error writing stdout\n", prog ) ;
		exit(2);
	}
	exit( 0 )  ;
}

7.7 Line Input and Output

char *fgets( char *line, int maxline, FILE *fp )
	// 最多讀 maxline - 1 個 char, 得到的 char 補上 '\0'

int fputs( char *line, FILE *fp)

char *fgets( char *s, int n , FILE *iop )
{
	register int c ;
	register char *cs ;

	cs = c ;
	while( --n > 0 && ( c = getc(iop)) != EOF )
		if( (*cs ++ = c ) == '\n' )
			break ;
	*cs = '\0' ;
	return ( c == EOF && cs == s ) ? NULL : s ;
}

// fputs : put string s on file iop
int fputs( char *s, FILE *iop )
{
	int c ;
	while( c = *s++ )
		putc( c, iop ) ;
	return ferror( iop ) ? EOF : 0 ;
}
// getline : read a line, return length
int getline( char *line, int max )
{
	if( fgets( line, max, stdin ) == NULL )
		return 0 ;
	else
		return strlen( line ) ;
}

7.8 Miscellaneous Functions

7.8.1 String Operations
strcat
strncat
strcmp
strncmp
strcpy
strncpy
strlen
strchr
strrchr

7.8.2 Characer class testing and conversion

isalpha
isupper
islower
isdigit
isalnum
isspace
toupper
tolower

7.8.3 ungetc( ungetc )
	ungetc : 可放回剛剛讀過的一個 char
	in ungetc( int c, FILE *fp )

7.8.4 command execution

system( char *s ) : 執行在 s 中的 command
ex : system( "date" ) ;

7.8.5 storage management
malloc : dynamically get memory blocks
calloc : dynamically get memory blocks

void *malloc( size_t n )
	// return NULL, if there is no memory block

void *calloc( size_t n , size_t size )
	// return a pointer which contains n-size memory array, return NULL if failed

int *ip ;
ip = ( int * ) calloc ( n, sizeof( int ) ) ;

free( p ) // 空出由 p 指向的空間, 這裡的 p 是經由叫用 malloc 或是 calloc 獲得的

for( p = head ; p != NULL ; p = p -> next )
 free(p) ; // error 因為空出之後再使用

 正確的作法應該是：

 for( p - head ; p != NULL ; p = q ){
 	 q = p -> next ;
 	 free(p) ;
 }

7.8.6 Mathematical functions

sin(x)
cos(x)
atan2(y,x)
exp(x)
lg(x)
log10(x)
pow(x,y)
sqrt(x)
fabs(x)

7.8.7 random number generator

rand() : 產生一系列範圍由 0 到 RAND_MAX 之間的一個假亂數

#define frand() ( (double) rand() ) / (RAND_MAX + 1.0 )
	ex : 產生一個大於或等於 0 但小於 1 的浮點亂數

srand( unsigned ) : 用來選定 func rand 的種子

chapter 8 the unix system interface

8.1 File Descriptors

everything is a file, such as keyboard, screen

when open one file, it could generate/open/create the file, then return the file descriptor as a positive integer

command interpreter automatically open 3 files and its file descriptor is 0, 1 and 2, each represent as standard input, standard output and standard error


8.2 low level I/O - read and write

read and write as system call

int n_read = read( int fd, char *buf, int n ) ;
int n_written = write( int fd, char *buf, int n ) ;

#include "syscalls.h" // 不是標準的 header

main()
{
	char buf[BUFSIZ] ;
	int n ;
	// read : 傳回所得的 byte number
	// 每次呼叫，使用者可以要求讀或寫任意的位元組數.
	while( ( n = read( 0, buf, BUFSIZ )) > 0 )
		write( 1, buf, n ) ;
	return 0 ;

}

#include "syscall.h"

// unbufferred single character input
int getchar( void )
{
	char c ;
	return ( read( 0, &c, 1 ) == 1 ) ? ( unsigned char ) c : EOF ;
}

//simple buffered version
int getchar( void )
{
	static char buf[ BUFSIZ ] ;
	static char *bufp = buf ;

	static int n = 0 ;
	if( n == 0 ){
		n  = read( 0, buf, sizeof( buf ) ) ;
		bufp = buf ;
	}
	return ( --n > 0 ) ? ( unsigned char ) *bufp++ : EOF ;
}

如果 include <stdio.h> 則必須 #undef getchar

8.3 Open, Create, Close, Unlink

#include <fcntl.h>

int fd;
int open( char *name, int flags, int perms ) ;
fd = open( name, flags, perms ) ;
// name : filename
// flags : int : O_RDONLY, O_WRONLY, O_RDWR
ex : fd = open( name, O_RDONLY, 0 ) ;
// 使用 open 時，第三個參數則永遠都是  0
//
creat system call : new or re-write a file

int creat( char *name, int perms ) ;
fd = creat( name, perms ) ;
perms : permission, 9 bits, control 1. owner, 2. group, 3, others and read, write, and execute.
八進位數正適合用來看這一個  permission :
0755
7 : 0111 : owner
5 : 0101 : group
5 : 0101 : others

#include <stdio.h>
#include <fcntl.h>
#include "syscall.h"
#define PERMS 0666

void error( char *, ... ) ;

main( int argc, char *argv[] )
{
	int f1, f2, n ;
	char buf[ BUFSIZ ] ;

	if( argc != 3 )
		error( "Usage : cp from to " ) ;
	if(( f1 = open( argv[1], O_RDONLY, 0 )) == -1 )
		error( "cp : can't open %s", argv[1] ) ;
	if(( f1 = creat( argv[2], PERMS )) == -1 )
		error( "cp : can't create %s, mode %03o", argv[2], PERMS ) ;

	while( ( n = read( f1, buf, BUFSIZ )) > 0 )
		if( write( f2, buf, n ) != n )
			error( "cp: write error on file %s", argv[2]) ;
	return 0 ;
}

#include <stdio.h>
#include <stdarg.h>

void error( char *fmt, ...)
{
	va_list args;
	va_start( args, fmt ) ;
	fprintf( stderr, "error: ") ;
	vfprintf( stderr, fmt, args ) ;
	fprintf( stderr, "\n" );
	va_end( args ) ;
	exit(1);
}
