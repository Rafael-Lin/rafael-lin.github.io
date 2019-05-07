#include <stdio.h>
#include <stdlib.h>
#include <string.h>
main()
{
    char * ptr = "1234";
    char str_array[] = "1234";
    printf( "ptr = %s, ptr length = %d\n", ptr, strlen( ptr ) ) ;
    //printf( " *ptr length = %d\n", strlen( *ptr ) ) ;
    //printf( "*ptr " , *ptr ) ; --> error;;:w
    //
    // error 
    printf( " str array length = %d\n", strlen( str_array ) ) ;
}
