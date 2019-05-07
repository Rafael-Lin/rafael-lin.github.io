
#include <ctype.h>
#include <stdio.h>
#define MAXLINE 1000
void printd( int n )
{
    if( n < 0 ){
    	putchar('-') ;
	n = -n ;
    }
    if( n / 10 )
    	printd( n / 10 ) ;
    putchar( n % 10 + '0');
}
main()
{
	printd( 100 );
	printf("\n") ;
	printd( -1100 );
	printf("\n") ;
	printf("tmp\n");
	int ccc = '\0';
	printf(" \0 = %d", ccc) ;
	return 0 ;
}
