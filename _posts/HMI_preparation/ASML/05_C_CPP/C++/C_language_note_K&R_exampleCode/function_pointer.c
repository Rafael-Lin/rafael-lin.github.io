#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int a_func( int, int ) ;
int b_func( int, int ) ;
int a_func( int a, int b )
{
    printf("this is function a: %d,%d\n", a, b ) ;
    return 0 ;
}
int b_func( int a, int b )
{
    printf("this is function b: %d,%d\n", a, b ) ;
    return 0;
}
int c_func( int a, int b )
{
    printf("this is function c: %d,%d\n", a, b ) ;
    return 0;
}
int (*func_array[])( int, int ) = { a_func, b_func, c_func } ;
/*
int (*func_array[])( int, int ) ; // = { a_func, b_func, c_func } ;
func_array[] = { a_func, b_func, c_func } ;
fail declare method
*/
typedef int Length ;
typedef int (*PFI)(char *, char * ) ;
typedef int (*FUNC_PTR_TYPE)( int, int ) ;
FUNC_PTR_TYPE funcP ;
//int (*funcP)( int, int ) ;

Length a ;
main()
{
    int tmp = 0 ;
    int i = 0 ;
    if( tmp == 0 )
    	funcP = a_func ;
    else
    	funcP = b_func ;
    //(*funcP)(10,11);
    funcP(10,11);
    for( i = 0 ; i < 3 ; i ++ )
    	func_array[i]( i, i ) ;
    return ;
}
