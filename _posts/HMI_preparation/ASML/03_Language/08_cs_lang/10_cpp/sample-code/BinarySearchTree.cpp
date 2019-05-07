
BinarySearchTree.h
----------------------
#ifndef BINARY_SEARCH_TREE_H_
#define BINARY_SEARCH_TREE_H_
#include "dsexceptions.h"
#include // For NULL
// Binary node and forward declaration because g++ does
// not understand nested classes.
template
class BinarySearchTree;
template
class BinaryNode
{
  Comparable element;
  BinaryNode *left;
  BinaryNode *right;
  BinaryNode( const Comparable & theElement, BinaryNode *lt, BinaryNode *rt )
    : element( theElement ), left( lt ), right( rt ) { }
  friend class BinarySearchTree;
};
// BinarySearchTree class
//
// CONSTRUCTION: with ITEM_NOT_FOUND object used to signal failed finds
//
// ******************PUBLIC OPERATIONS*********************
// void insert( x ) --> Insert x
// void remove( x ) --> Remove x
// Comparable find( x ) --> Return item that matches x
// Comparable findMin( ) --> Return smallest item
// Comparable findMax( ) --> Return largest item
// boolean isEmpty( ) --> Return true if empty; else false
// void makeEmpty( ) --> Remove all items
// void printTree( ) --> Print tree in sorted order
template
class BinarySearchTree
{
  public:
    explicit BinarySearchTree( const Comparable & notFound );
    BinarySearchTree( const BinarySearchTree & rhs );
    ~BinarySearchTree( );
    const Comparable & findMin( ) const;
    const Comparable & findMax( ) const;
    const Comparable & find( const Comparable & x ) const;
    bool isEmpty( ) const;
    void printTree( ) const;
    void makeEmpty( );
    void insert( const Comparable & x );
    void remove( const Comparable & x );
    const BinarySearchTree & operator=( const BinarySearchTree & rhs );
  private:
    BinaryNode *root;
    const Comparable ITEM_NOT_FOUND;
    const Comparable & elementAt( BinaryNode *t ) const;
    void insert( const Comparable & x, BinaryNode * & t ) const;void remove( const Comparable & x, BinaryNode * & t ) const;
    BinaryNode * findMin( BinaryNode *t ) const;
    BinaryNode * findMax( BinaryNode *t ) const;
    BinaryNode * find( const Comparable & x, BinaryNode *t ) const;
    void makeEmpty( BinaryNode * & t ) const;
    void printTree( BinaryNode *t ) const;
    BinaryNode * clone( BinaryNode *t ) const;
};
#endif
BinarySearchTree.cpp
--------------------
#include "BinarySearchTree.h"
#include
/**
* Implements an unbalanced binary search tree.
* Note that all "matching" is based on the < method.
*/
/**
* Construct the tree.
*/
template
BinarySearchTree::BinarySearchTree( const Comparable & notFound ) :
root( NULL ), ITEM_NOT_FOUND( notFound )
{} /*
*
* Copy constructor.
*/
template
BinarySearchTree::
BinarySearchTree( const BinarySearchTree & rhs ) :
  root( NULL ), ITEM_NOT_FOUND( rhs.ITEM_NOT_FOUND )
{*
  this = rhs;
} /*
*
* Destructor for the tree.
*/
template
BinarySearchTree::~BinarySearchTree( )
{
  makeEmpty( );
} /*
*
* Insert x into the tree; duplicates are ignored.
*/
template
void BinarySearchTree::insert( const Comparable & x )
{
  insert( x, root );
} /*
*
* Remove x from the tree. Nothing is done if x is not found.
*/
template
void BinarySearchTree::remove( const Comparable & x )
{
  remove( x, root );
} /*
*
* Find the smallest item in the tree.
* Return smallest item or ITEM_NOT_FOUND if empty.
*/
template
const Comparable & BinarySearchTree::findMin( ) const
{
  return elementAt( findMin( root ) );
} /*
*
* Find the largest item in the tree.
* Return the largest item of ITEM_NOT_FOUND if empty.
*/
template
const Comparable & BinarySearchTree::findMax( ) const
{
  return elementAt( findMax( root ) );
} /*
*
* Find item x in the tree.
* Return the matching item or ITEM_NOT_FOUND if not found.
*/
template
const Comparable & BinarySearchTree::
find( const Comparable & x ) const
{
  return elementAt( find( x, root ) );
} /*
*
* Make the tree logically empty.
*/
template
void BinarySearchTree::makeEmpty( )
{
  makeEmpty( root );
} /*
*
* Test if the tree is logically empty.
* Return true if empty, false otherwise.
*/
template
bool BinarySearchTree::isEmpty( ) const
{
  return root == NULL;
} /*
*
* Print the tree contents in sorted order.
*/
template
void BinarySearchTree::printTree( ) const
{if(
isEmpty( ) )
cout << "Empty tree" << endl;
else
printTree( root );
} /*
*
* Deep copy.
*/
templateconst BinarySearchTree &
BinarySearchTree::
operator=( const BinarySearchTree & rhs )
{if(
this != &rhs )
{m
akeEmpty( );
root = clone( rhs.root );
}r
eturn *this;
} /*
*
* Internal method to get element field in node t.
* Return the element field or ITEM_NOT_FOUND if t is NULL.
*/
template
const Comparable & BinarySearchTree::
elementAt( BinaryNode *t ) const
{if(
t == NULL )
return ITEM_NOT_FOUND;
else
return t->element;
} /*
*
* Internal method to insert into a subtree.
* x is the item to insert.
* t is the node that roots the tree.
* Set the new root.
*/
template
void BinarySearchTree::
insert( const Comparable & x, BinaryNode * & t ) const
{if(
t == NULL )
t = new BinaryNode( x, NULL, NULL );
else if( x < t->element )
insert( x, t->left );
else if( t->element < x )
insert( x, t->right );
else
; // Duplicate; do nothing
} /*
*
* Internal method to remove from a subtree.
* x is the item to remove.
* t is the node that roots the tree.
* Set the new root.
*/
template
void BinarySearchTree::
remove( const Comparable & x, BinaryNode * & t ) const
{if(
t == NULL )
return; // Item not found; do nothing
if( x < t->element )
remove( x, t->left );
else if( t->element < x )
remove( x, t->right );
else if( t->left != NULL && t->right != NULL ) // Two children
{t-
>element = findMin( t->right )->element;
remove( t->element, t->right );
}e
lse
{B
inaryNode *oldNode = t;t = ( t->left != NULL ) ? t->left : t->right;
delete oldNode;
}} /*
*
* Internal method to find the smallest item in a subtree t.
* Return node containing the smallest item.
*/
template
BinaryNode *
BinarySearchTree::findMin( BinaryNode *t ) const
{if(
t == NULL )
return NULL;
if( t->left == NULL )
return t;
return findMin( t->left );
} /*
*
* Internal method to find the largest item in a subtree t.
* Return node containing the largest item.
*/
template
BinaryNode *
BinarySearchTree::findMax( BinaryNode *t ) const
{if(
t != NULL )
while( t->right != NULL )
t = t->right;
return t;
} /*
*
* Internal method to find an item in a subtree.
* x is item to search for.
* t is the node that roots the tree.
* Return node containing the matched item.
*/
template
BinaryNode *
BinarySearchTree::
find( const Comparable & x, BinaryNode *t ) const
{if(
t == NULL )
return NULL;
else if( x < t->element )
return find( x, t->left );
else if( t->element < x )
return find( x, t->right );
else
return t; // Match
}/*
***** NONRECURSIVE VERSION*************************
template
BinaryNode *
BinarySearchTree::
find( const Comparable & x, BinaryNode *t ) const
{wh
ile( t != NULL )
if( x < t->element )
t = t->left;
else if( t->element < x )
t = t->right;
else
return t; // Match
return NULL; // No match
}*****************************************************/
/**
* Internal method to make subtree empty.
*/
template
void BinarySearchTree::
makeEmpty( BinaryNode * & t ) const
{if(
t != NULL )
{m
akeEmpty( t->left );
makeEmpty( t->right );
delete t;
}t
= NULL;
} /*
*
* Internal method to print a subtree rooted at t in sorted order.
*/
template
void BinarySearchTree::printTree( BinaryNode *t ) const
{if(
t != NULL )
{p
rintTree( t->left );
cout << t->element << endl;
printTree( t->right );
}} /*
*
* Internal method to clone subtree.
*/
template
BinaryNode *
BinarySearchTree::clone( BinaryNode * t ) const
{if(
t == NULL )
return NULL;
else
return new BinaryNode( t->element, clone( t->left ), clone( t->right ) );
} T
estBinarySearchTree.cpp
------------------------
#include
#include "BinarySearchTree.h"
// Test program
int main( )
{c
onst int ITEM_NOT_FOUND = -9999;
BinarySearchTree t( ITEM_NOT_FOUND );
int NUMS = 4000;
const int GAP = 37;
int i;
cout << "Checking... (no more output means success)" << endl;
for( i = GAP; i != 0; i = ( i + GAP ) % NUMS )
t.insert( i );
for( i = 1; i < NUMS; i+= 2 )
t.remove( i );if( NUMS < 40 )
t.printTree( );
if( t.findMin( ) != 2 || t.findMax( ) != NUMS - 2 )
cout << "FindMin or FindMax error!" << endl;
for( i = 2; i < NUMS; i+=2 )
if( t.find( i ) != i )
cout << "Find error1!" << endl;
for( i = 1; i < NUMS; i+=2 )
{if(
t.find( i ) != ITEM_NOT_FOUND )
cout << "Find error2!" << endl;
} B
inarySearchTree t2( ITEM_NOT_FOUND );
t2 = t;
for( i = 2; i < NUMS; i+=2 )
if( t2.find( i ) != i )
cout << "Find error1!" << endl;
for( i = 1; i < NUMS; i+=2 )
{if(
t2.find( i ) != ITEM_NOT_FOUND )
cout << "Find error2!" << endl;
} r
eturn 0;
}#    
