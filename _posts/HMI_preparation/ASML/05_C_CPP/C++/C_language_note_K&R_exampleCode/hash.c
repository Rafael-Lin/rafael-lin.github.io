#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IN 1
//state = IN ;
//install(s,t) : 把名稱 s 和其對應的文字 t  記錄到表格中
//looks(s) : 在表格中找到名稱 s

stuct nlist{
	struct nlist *next ;
	char *name ;
	char *defn ;
};

#define HASHSIZE 101
static struct nlist *hasttab[HASHSIZE] ;
struct nlist *lookup( char * ) ;
char *strdup( char * ) ;

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
	//  先用 string 找到 hush number, 再去 hash array 裡找到第一個 entry, 然後一個一個找有沒有和 string 一樣的
	for ( np = hashtab[ hash( s )] ; np != NULL ; np = np -> next )
		if( strcmp( s, np -> name ) == 0 )
			return np ;
	return NULL ;
}

struct nlist *install( char *name, char *defn)
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
		//  新的定義蓋掉舊的定義

	if( (np->defn = strdup(defn) == NULL )
			return NULL ;
	return np ;
}
