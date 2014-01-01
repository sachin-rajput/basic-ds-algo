/***
 * Author : Sachin Rajput
 * License : GNU GENERAL PUBLIC LICENSE
 */
 
#include <stdio.h>
#include <stdlib.h>

/***
 * Data structure for the data to be stored in 
 * the nodes of LinkedList
 */
typedef struct {
	int value;
} data;

/***
 * Node which will store next pointer, 
 * along with a data pointer
 */
typedef struct nodePtr {
	struct nodePtr *next;
	data *dataPtr;
} node;


/***
 * Data structure to keep track of
 * head and tail of the linked list
 */
typedef struct {
	node *head;
	node *tail;
} linkList;


/**
 * Creates a linkList 
 */
 linkList *createlinkList();
 
 /**
  * Creates a node with the data supplied
  */
 node *createNode(int value);

 /**
  * Creates a data with int value
  */
 data *createData(int value);

 /**
  * Add node to the linkedList from front
  */
 void addFront(linkList *ll,node *n); 
 
  /**
  * Add node to the linkedList from back
  */
 void addBack(linkList *ll,node *n); 
 
 /**
  * Add at position i of the linkList
  */
 void addPosition(linkList *ll,int position); 
 
  /**
  * Remove node to the linkedList from front
  * (Used pop instead of remove)
  */
 void popFront(linkList *ll);
 
  /**
  * Remove node to the linkedList from back 
  * (Used pop instead of remove)
  */
 void popBack(linkList *ll); 
 
 /**
  * Remove from position i of the linkList
  */
 void popPosition(linkList *ll,int position); 
 
 
  