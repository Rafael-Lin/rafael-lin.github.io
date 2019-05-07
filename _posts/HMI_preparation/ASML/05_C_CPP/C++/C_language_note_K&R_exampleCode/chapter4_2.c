
#include <stdio.h>
#include <math.h>

#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100
#define BUFSIZE 100
int sp = 0 ;
double val[MAXVAL] ;
char buf[ BUFSIZE ] ; 

/* int getop( char [] ) ; */
void push ( double ) ;
double pop( void ) ;
int getch( void ) ;
void ungetch( int ) ;

main()
{
	int type; 
	double op2 ;
	char s[MAXOP] ;

	while ( (type = getop(s)) != EOF ){
		//printf("input str = %s, return type = %d \n", s , type ) ;
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
				//printf("get type error, type = %d\n", type  ) ;
				break ;
		}
	}
}

int getop( char s[] ) 
{
    int i, c ;
    while(( s[0] = c = getch() ) == ' ' || c == '\t' )
    	; 
    s[1] = '\0' ;
    //printf("c = %c\n", c ) ;
    if( !isdigit(c) && c != '.' ){
	//printf("stage1") ;
    	return c ;
    }
    if( isdigit(c) )
    	while( isdigit( s[++i] = c = getch() )){
	    //printf("stage2, i = %d\n", i ) ;
    	    ;
	}
    if( c == '.' )
    	while( isdigit( s[++i] = c = getch() )){
    	    ;
	}
    s[i] = '\0' ;
    //printf("the str  = %s\n", s ) ;
    //if( c != EOF ) ungetch(c) ;
    return NUMBER ;

}

void push( double f)
{
	if( sp < MAXVAL ){
		val[sp++] = f ;
		printf("push %f\n", f ) ;
	}else 
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
