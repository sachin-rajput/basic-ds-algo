#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#define DEBUG 1
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
void addFront(linkList *ll,int value);

/**
* Add node to the linkedList from back
*/
void addBack(linkList *ll,int value);

/**
 * Add at position i of the linkList
 */
void addatPosition(linkList *ll,int position,int value);

/**
* Remove node from the linkedList from front
* (Used pop instead of remove)
*/
void popFront(linkList *ll);

/**
* Remove node from the linkedList from back
* (Used pop instead of remove)
*/
void popBack(linkList *ll);

/**
 * Remove from position i of the linkList
 */
void popatPosition(linkList *ll,int position);

/**
 * Remove with value from the linkList
 * first occurence will be deleted
 * Modification possible: delete all occurences of value
 */
void popwithValue(linkList *ll,int value);

/**
 * Print the values of the linkList
 */
void printlinkList(linkList *ll);

/**
 * Search value in linkList,
 * return 1 if found else 0
 */
int searchValue(linkList *ll,int value);

/**
 * Check if head exists?
 * return 1 if exist and 0 if not
 */
int checkHead(linkList *ll);

/**
 * Check if tail exists?
 * return 1 if exist and 0 if not
 */
int checkTail(linkList *ll);

/**
 * Check if linkList exists / empty?
 * return 1 if not empty else 0
 */
int checkEmpty(linkList *ll);

/**
 * Clean up the memory we used
 */
void cleanlinkList(linkList *ll);

#endif
