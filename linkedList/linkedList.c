#include "linkedList.h"

/**
 * Creates a linkList
 */
linkList *createlinkList()
{
	linkList *newlinkList = (linkList*)malloc(sizeof(linkList));
	newlinkList->head = NULL;
	newlinkList->tail = NULL;
	return newlinkList;
}

/**
 * Creates a node with the data supplied
 */
node *createNode(int value)
{
	node *newNode = (node*)malloc(sizeof(node));
	newNode->dataPtr = createData(value);
	newNode->next = NULL;
	return newNode;
}

/**
 * Creates a data with int value
 */
data *createData(int value)
{
	data *newData = (data*)malloc(sizeof(data));
	newData->value = value;
	return newData;
}

/**
 * Add node to the linkedList from front
 */
void addFront(linkList *ll,int value)
{
	node *newNode = createNode(value);
	if(!checkEmpty(ll)) {
		ll->head = newNode;
		ll->tail = newNode;
	} else {
		newNode->next = ll->head;
		ll->head = newNode;
	}
#if DEBUG
	printf("Node added at front of linkList with value : %d\n",value);
#endif
}

/**
* Add node to the linkedList from back
*/
void addBack(linkList *ll,int value)
{
	node *newNode = createNode(value);
	if(!checkEmpty(ll)) {
		ll->head = newNode;
		ll->tail = newNode;
	} else {
		ll->tail->next = newNode;
		ll->tail = newNode;
	}
#if DEBUG
	printf("Node added at back of linkList with value : %d\n",value);
#endif
}

/**
 * Add at position i of the linkList
 * Note: index is not zero-based
 */
void addatPosition(linkList *ll,int position,int value)
{
	int length = lengthlinkList(ll);
	if(position > length + 1) {
		printf("You entered the position out of the bound!\n");
		return;
	}
	node *temp,*prev;
	int i = 1;

	if(position == 1) {
		//insert here - addFront and return;
		addFront(ll,value);
	} else if(position == length + 1) {
		//insert here - addBack and return;
		addBack(ll,value);
	}

	node *newNode = createNode(value);
	prev = ll->head;
	for(temp= ll->head; temp != NULL; temp=temp->next) {
		if(i == position) {
			//insert here and return;
			prev->next = newNode;
			newNode->next = temp;
#if DEBUG
			printf(">>==============Node added at position %d with value : %d================<<\n",position,value);
#endif
			return;
		}
		prev = temp;
		i++;
	}
}

/**
* Remove node from the linkedList from front
* (Used pop instead of remove)
*/
void popFront(linkList *ll)
{
	if(!checkEmpty(ll)) return;
	node *temp = ll->head;
	ll->head = ll->head->next;
#if DEBUG
	printf(">>==============Node pop'd from front ================<<\n");
#endif
	free(temp->dataPtr);
	free(temp);
}

/**
* Remove node from the linkedList from back
* (Used pop instead of remove)
*/
void popBack(linkList *ll)
{
	if(!checkEmpty(ll)) return;
	node *temp = ll->head;
	node *prev = temp;
	while(temp != NULL) {
		if(temp->next == NULL) {
			node *temp = ll->tail;
			ll->tail = prev;
			prev->next = NULL;
#if DEBUG
			printf(">>==============Node pop'd from back ================<<\n");
#endif
			free(temp->dataPtr);
			free(temp);
			return;
		}
		prev = temp;
		temp = temp->next;
	}
}

/**
 * Remove from position i of the linkList
 * Note: index is not zero-based
 */
void popatPosition(linkList *ll,int position)
{
	int length = lengthlinkList(ll);
	if(position > length) {
		printf("You entered the position out of the bound!\n");
		return;
	}
	node *temp,*prev;
	int i = 1;

	if(position == 1) {
		//pop here - popFront and return;
		popFront(ll);
	} else if(position == length) {
		//pop here - popBack and return;
		popBack(ll);
	}

	prev = ll->head;
	for(temp= ll->head; temp != NULL; temp=temp->next) {
		if(i == position) {
			//pop here and return;
			prev->next = temp->next;
			temp->next = NULL;
#if DEBUG
			printf(">>==============Node pop'd at position %d ================<<\n",position);
#endif
			free(temp->dataPtr);
			free(temp);
			return;
		}
		prev = temp;
		i++;
	}
}

/**
 * Remove with value from the linkList
 * first occurence will be deleted
 * Modification possible: delete all occurences of value
 */
void popwithValue(linkList *ll,int value)
{
	node *temp,*prev;
	prev = ll->head;
	for(temp= ll->head; temp != NULL; temp=temp->next) {
		if(temp->dataPtr->value == value) {
			//pop here and return;
			prev->next = temp->next;
			temp->next = NULL;
#if DEBUG
			printf(">>==============Node pop'd with value : %d ================<<\n",value);
#endif
			free(temp->dataPtr);
			free(temp);
			// Modification : if delete all occurences then,
			// comment below return and update,
			// temp = prev->next
			return;
		}
		prev = temp;
	}
}

/**
 * Print the values of the linkList
 */
void printlinkList(linkList *ll)
{
	if(!checkEmpty(ll)) return;
	node *temp = ll->head;
#if DEBUG
	printf(">>==============Printing linkList from front================<<\n");
#endif
	while(temp != NULL) {
		printf("%d\n",temp->dataPtr->value);
		temp = temp->next;
	}
#if DEBUG
	printf(">>==============Printing linkList finished================<<\n");
#endif
}

/**
 * Search value in linkList,
 * return 1 if found else 0
 */
int searchValue(linkList *ll,int value)
{
	node *temp,*prev;
	prev = ll->head;
	for(temp= ll->head; temp != NULL; temp=temp->next) {
		if(temp->dataPtr->value == value) {
			return 1;
		}
		prev = temp;
	}
	return 0;
}

/**
 * Check if head exists?
 * return 1 if exist and 0 if not
 */
int checkHead(linkList *ll)
{
	if(ll->head) return 1;
	return 0;
}

/**
 * Check if tail exists?
 * return 1 if exist and 0 if not
 */
int checkTail(linkList *ll)
{
	if(ll->tail) return 1;
	return 0;
}

/**
 * Check if linkList exists / empty?
 * return 1 if not empty else 0
 */
int checkEmpty(linkList *ll)
{
	if(ll->head && ll->tail) return 1;
	return 0;
}

/**
 * Returns the length of the linkList
 */
int lengthlinkList(linkList *ll)
{
	if(!checkEmpty(ll)) return 0;
	node *temp = ll->head;
	int i= 0;
	while(temp != NULL) {
		i++;
		temp = temp->next;
	}
	return i;
}


/**
 * Clean up the memory we used
 */
void cleanlinkList(linkList *ll)
{
	if(!checkEmpty(ll)) return;
	node *temp = ll->head;
	node *curr = temp;
	while(temp !=NULL) {
		curr=temp->next;
		free(temp->dataPtr);
		free(temp);
		temp = curr;
	}
	free(ll);
#if DEBUG
	printf(">>==============Linklist memory cleaned ================<<\n");
#endif
}
