#include <stdio.h>
#include <string.h>

#define MAXLINES 5000
#define MAXLEN 1000


int readline( char *lineptr[], int nlines ) ;
void writelines( char *lineptr[], int nlines ) ;
void qsort( char *lineptr[] , int left, int right) ;
int getline( char *, int ) ;
char *lineptr[ 5000] ;
void swap( char *v[], int i, int j )
{
	char *temp ;
	temp = v[i] ; v[i] = v[j] ; v[j] = temp ;
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
int readlines( char *lineptr[], int maxlines )
{
	int len, nlines;
	char *p, line[MAXLEN]; 

	nlines = 0 ;
	while( ( len = getline(line, MAXLEN))> 0){
		if( nlines >= MAXLINES ){
			printf("error") ;
			return -1 ;
		}
		else{
			line[len - 1 ] = '\0' ;
			strcpy( p, line) ;
			lineptr[nlines++]  = p ;
		}
	}
	printf("read line return value :%d\n", nlines ) ;
	return nlines ;
}
void writelines( char * lineptr[], int nlines )
{
	int i ; 
	for( i = 0 ; i < nlines ; i++ )
		printf("%s\n", lineptr[i]) ;

}
/*
void writelines( char * lineptr[], int nlines )
{
	while( nlines-- > 0)
		printf( "%s\n", *lineptr ++ ) ;
	// *lineptr ++ : 先取用 *lineptr, 再對 lineptr 做 ++ 
}
*/

void qsort( char * v[], int left, int right )
{
	int i, last;
	if( left >= right )
		return ;
	swap( v, left, (left + right ) / 2 ) ;
	last = left ;
	for( i = left + 1 ; i <= right ; i ++ )
		if( strcmp( v[i], v[left] ) < 0 )
			swap( v, ++last, i ) ;

	swap( v, left, last ) ; // v[last] is 己經到達定位 
	qsort( v, left , last - 1 ) ;
	qsort( v, last+ 1 , right ) ;
}


main()
{
	int nlines ; 
	if(( nlines = readlines( lineptr, MAXLINES )) >= 0 ){
		qsort( lineptr, 0, nlines - 1 ) ;
		printf("main sorting\n") ;
		writelines( lineptr, nlines ) ;
		return 0 ;
	}else{
		printf("error\n") ;
		return 1; 
	}
}
