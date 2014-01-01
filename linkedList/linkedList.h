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
	nodePtr *next;
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



