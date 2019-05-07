#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IN 1
//state = IN ;
//install(s,t) : ��W�� s �M���������r t  �O�����椤
//looks(s) : �b��椤���W�� s

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
	//  ���� string ��� hush number, �A�h hash array �̧��Ĥ@�� entry, �M��@�Ӥ@�ӧ䦳�S���M string �@�˪�
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
		//  �s���w�q�\���ª��w�q

	if( (np->defn = strdup(defn) == NULL )
			return NULL ;
	return np ;
}
