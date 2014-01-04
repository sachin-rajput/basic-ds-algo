#ifndef _DLINKLIST_H_
#define _DLINKLIST_H_
/***
 * Author : Sachin Rajput
 * License : GNU GENERAL PUBLIC LICENSE
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG 1

typedef struct {
	float val;
} data;

typedef struct nodePtr {
	struct nodePtr *next;
	struct nodePtr *prev;
	data *dataPtr;
} node;

typedef struct {
	node *head;
	node *tail;
} dlinklist;

/***
 * Creates dlinklist, set initial variables, and return dlinklist
 */
dlinklist* createlinklist();

/***
 * Creates node, set variables and return
 */
node* createNode(data *d);

/***
 * Creates data struct,set variables and return
 */
data* createData(float val);

/***
 * create a new node, set the data pointer, and add to front of dlinklist
 */
void addFront(dlinklist *ll,data *d);

/***
 * create a new node, set the data pointer, and add to back of dlinklist
 */
void addBack(dlinklist *ll,data *d);

/**
 * Add at position i of the linkList
 */
void addatPosition(dlinklist *ll,int position,float value);

/**
 * print values in the data structures in the dlinklist
 */
void printList(dlinklist *ll);

/***
 * count the number of elements in the dlinklist and return the count
 */
int listSize(dlinklist *ll);

/**
 * Check if dlinkList exists / empty?
 * return 1 if not empty else 0
 */
int checkEmpty(dlinklist *ll);

/***
 * remove node from the front of the list and return the data element
 */
data *popFront(dlinklist *ll);

/***
 * remove node from the front of the list and return the data element
 */
data *popBack(dlinklist *ll);

/**
 * Remove from position i of the linkList
 */
data *popatPosition(dlinklist *ll,int position);

/**
 * Remove with value from the linkList
 * first occurence will be deleted
 * Modification possible: delete all occurences of value
 */
data *popwithValue(dlinklist *ll,float value);

/***
 * free all memory in the dlinklist
 */
void cleanList(dlinklist *ll);

/***
 * reverse the elements of the dlinklist
 */
void reverseList(dlinklist *ll);

/***
 * search for element in dlinklist, if found remove.
 */
void searchRemove(dlinklist *ll,float val);


#endif
