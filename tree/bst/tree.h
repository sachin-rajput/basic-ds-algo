#ifndef TREE_H
#define TREE_H
 

#define DEBUG 1
/***
 * Author : Sachin Rajput
 * License : GNU GENERAL PUBLIC LICENSE
 */

#include <stdio.h>
#include <stdlib.h>

typedef enum { false, true } bool;

/***
 * Data structure for the data to be stored in
 * the nodes of Tree
 */
typedef struct {
	int value;
} data;

/***
 * Node which will store left and right pointer,
 * along with a data pointer
 */
typedef struct nodePtr {
	struct nodePtr *left;
	struct nodePtr *right;
	data *dataPtr;
} node;


/***
 * Data structure to keep root the Tree
 */
typedef struct {
	node *root;
} tree;

/**
 * Creates a tree
 */
tree *createTree();

/**
 * Creates a node with the data supplied
 */
node *createNode(data *newDataIn);

/**
 * Creates a data with int value
 */
data *createData(int valueIn);

/**
 * Inserts a data supplied
 */
void insert(tree *bst, int value);

/**
 * Insert helper for inserting a node in tree 
 * This will be a recursive function
 */
void insert_helper(node *currNode, data *newDataIn);

/**
 * Compare dataPtr 
 */
int compare(data *currData, data *dataIn);

/**
 * Int comparator 
 */
int compare_int(int a,int b);


/**
 * Deletes the node with the int value supplied
 */
bool delete(tree *bst, int valueIn);

/**
 * Clears the tree
 */
void clearTree(node *root);

/**
 * Free the pointers 
 */
void freePtr(node *nodeToDelete);


/**
 * Search the tree with the value
 */
bool search(node *root, int valueIn);


/**
 * Returns the height from the supplied node
 */
int height(node *nodeIn);


/**
 * Checks if the supplied tree is Binary Search Tree
 */
bool isBST(node *nodeIn, int minData, int maxData);

/**
* Print In-order 
*/
void inOrder(node *root);

/**
* Print In-order 
*/
void preOrder(node *root);

/**
* Print In-order 
*/
void postOrder(node *root);


#endif