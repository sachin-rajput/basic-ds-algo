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
 * Each data also has height, default height is -1
 */
typedef struct {
	int value;
	int height;
} data;

/***
 * Node which will store parent, left and right pointer,
 * along with a data pointer
 */
typedef struct nodePtr {
	struct nodePtr *parent;
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
 * Inserts a node in tree 
 * This will be a recursive function
 */
node *insert(node *currNode, int valueIn);

/**
 * 
 */
int getBalance(node *N);

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


int max(int a, int b);

/**
 * Rotation for right rotation
 */
node *rightRotate(node *y);

/**
 * Rotation for left rotation
 */
node *leftRotate(node *x);

/**
 * Checks if the supplied tree is balanced tree
 */
bool isBalanced(node *nodeIn);

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