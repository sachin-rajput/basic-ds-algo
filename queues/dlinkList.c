#include "dlinkList.h"

/***
 * Creates dlinklist, set initial variables, and return dlinklist
 */
dlinklist* createlinklist()
{
	dlinklist* ll = (dlinklist*)malloc(sizeof(dlinklist));
	ll->head = NULL;
	ll->tail = NULL;
	return ll;
}

/***
 * Creates node, set variables and return
 */
node* createNode(data *d)
{
	node *n = (node*)malloc(sizeof(node));
	n->dataPtr = d;
	n->next = NULL;
	n->prev = NULL;
	return n;
}

/***
 * Creates data struct,set variables and return
 */
data* createData(float val)
{
	data *d = (data*)malloc(sizeof(data));
	d->val = val;
	return d;
}

/***
 * create a new node, set the data pointer, and add to front of dlinklist
 */
void addFront(dlinklist *ll,data *d)
{
	node *newnode = createNode(d);
	if(ll->head == NULL && ll->tail == NULL) {
		ll->head = newnode;
		ll->tail = newnode;
	} else {
		newnode->next = ll->head;
		ll->head->prev = newnode;
		ll->head = newnode;
	}
#if DEBUG
	printf("Node added at front of queue with value : %f\n",newnode->dataPtr->val);
#endif
}

/***
 * create a new node, set the data pointer, and add to back of dlinklist
 */
void addBack(dlinklist *ll,data *d)
{
	node *newnode = createNode(d);
	if(ll->head == NULL && ll->tail == NULL) {
		ll->head = newnode;
		ll->tail = newnode;
	} else {
		ll->tail->next = newnode;
		newnode->prev = ll->tail;
		ll->tail = newnode;
	}
#if DEBUG
	printf("Node added at back of queue with value : %f\n",newnode->dataPtr->val);
#endif
}

/**
 * Add at position i of the linkList
 * Note: index is not zero-based
 */
void addatPosition(dlinklist *ll,int position,float value)
{
	int length = listSize(ll);
	if(position > length + 1) {
		printf("You entered the position out of the bound!\n");
		return;
	}
	node *temp;
	int i = 1;
	data *newData = createData(value);

	if(position == 1) {
		//insert here - addFront and return;
		addFront(ll,newData);
	} else if(position == length + 1) {
		//insert here - addBack and return;
		addBack(ll,newData);
	}

	node *newNode = createNode(newData);
	for(temp= ll->head; temp != NULL; temp=temp->next) {
		if(i == position) {
			//insert here and return;
			temp->prev->next = newNode;
			newNode->next = temp;
			newNode->prev = temp->prev;
			temp->prev = newNode;
#if DEBUG
			printf(">>==============Node added at position %d with value : %f================<<\n",position,value);
#endif
			return;
		}
		i++;
	}
}

/***
 * print values in the data structures in the dlinklist
 */
void printList(dlinklist *ll)
{
	if(!checkEmpty(ll)) return;
	node *temp = ll->head;
#if DEBUG
	printf(">>==============Printing queue from bottom to top================<<\n");
#endif
	while(temp != NULL) {
		printf("%f\n",temp->dataPtr->val);
		temp = temp->next;
	}
#if DEBUG
	printf(">>==============Printing queue finished================<<\n");
#endif
}


/***
 * count the number of elements in the dlinklist and return the count
 */
int listSize(dlinklist *ll)
{
	if(!checkEmpty(ll)) return 0;
	node *temp = ll->head;
	int size = 0;
	while(temp != NULL) {
		size++;
		temp = temp->next;
	}
	return size;
}

/**
 * Check if dlinkList exists / empty?
 * return 1 if not empty else 0
 */
int checkEmpty(dlinklist *ll)
{
	if(ll->head && ll->tail) return 1;
	return 0;
}

/***
 * remove node from the front of the list and return the data element
 */
data *popFront(dlinklist *ll)
{
	if(!checkEmpty(ll)) return NULL;
	data *returndata;
	if(ll->head == ll->tail) {
		node *deltemp= ll->head;
		ll->head = NULL;
		ll->tail = NULL;
		returndata = createData(deltemp->dataPtr->val);
		free(deltemp->dataPtr);
		free(deltemp);
	} else {
		node* deltemp = ll->head;
		ll->head=ll->head->next;
		ll->head->prev = NULL;
		returndata = createData(deltemp->dataPtr->val);
		free(deltemp->dataPtr);
		free(deltemp);
	}
#if DEBUG
	printf(">>==============Node pop'd from front ================<<\n");
#endif
	return returndata;
}

/***
 * remove node from the front of the list and return the data element
 */
data *popBack(dlinklist *ll)
{
	if(!checkEmpty(ll)) return NULL;
	data *returndata;
	if(ll->head == ll->tail) {
		node *deltemp =ll->head;
		ll->head = NULL;
		ll->tail = NULL;
		returndata = createData(deltemp->dataPtr->val);
		free(deltemp->dataPtr);
		free(deltemp);
	} else {
		node *deltemp = ll->tail;
		ll->tail = ll->tail->prev;
		ll->tail->next = NULL;
		returndata = createData(deltemp->dataPtr->val);
		free(deltemp->dataPtr);
		free(deltemp);
	}
#if DEBUG
	printf(">>==============Node pop'd from back ================<<\n");
#endif
	return returndata;
}

/**
 * Remove from position i of the linkList
 */
data *popatPosition(dlinklist *ll,int position)
{
	if(!checkEmpty(ll)) return NULL;
	int length = listSize(ll);
	if(position > length) {
		printf("You entered the position out of the bound!\n");
		return NULL;
	}
	node *temp;
	int i = 1;

	if(position == 1) {
		//pop here - popFront and return;
		popFront(ll);
	} else if(position == length) {
		//pop here - popBack and return;
		popBack(ll);
	}

	for(temp= ll->head; temp != NULL; temp=temp->next) {
		if(i == position) {
			//pop here and return;
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
#if DEBUG
			printf(">>==============Node pop'd at position %d ================<<\n",position);
#endif
			data *returndata = createData(temp->dataPtr->val);
			free(temp->dataPtr);
			free(temp);
			return returndata;
		}
		i++;
	}
	return NULL;
}

/**
 * Remove with value from the linkList
 * first occurence will be deleted
 * Modification possible: delete all occurences of value
 */
data *popwithValue(dlinklist *ll,float value)
{
	if(!checkEmpty(ll)) return NULL;
	node *temp;
	for(temp= ll->head; temp != NULL; temp=temp->next) {
		if(temp->dataPtr->val == value) {
			//pop here and return;
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
#if DEBUG
			printf(">>==============Node pop'd with value : %f ================<<\n",value);
#endif
			data *returndata = createData(temp->dataPtr->val);
			free(temp->dataPtr);
			free(temp);
			// Modification : if delete all occurences then,
			// comment below return and update,
			// temp = prev->next
			// also change the return type to void
			return returndata;
		}
	}
	return NULL;
}

/***
 * free all memory in the dlinklist
 */
void cleanList(dlinklist *ll)
{
	if(!checkEmpty(ll)) return;
	node *temp = ll->head;
	while(temp != NULL) {
		free(temp->dataPtr);
		node *tempnext = temp->next;
		free(temp);
		temp = tempnext;
	}
	free(ll);
#if DEBUG
	printf(">>==============queue memory cleaned ================<<\n");
#endif
}

/***
 * reverse the elements of the dlinklist
 */
void reverseList(dlinklist *ll)
{
	if(!checkEmpty(ll)) return;
	node *next;
	node *temphead = ll->head;

	while (temphead != NULL) {
		next = temphead->next;
		if(temphead->prev == NULL) ll->tail = temphead;
		if(next == NULL) ll->head = temphead;
		temphead->next = temphead->prev;
		temphead->prev = next;
		temphead = next;
	}
#if DEBUG
	printf(">>==============queue reversed ================<<\n");
#endif
}

/***
 * search for element in dlinklist, if found remove.
 */
void searchRemove(dlinklist *ll,float val)
{
	node *temp = ll->head;
	data *tempdata;
	while(temp != NULL) {
		if(temp->dataPtr->val == val) {
			//element found!
			if(temp == ll->head) {
				popFront(ll);
			} else if(temp == ll->tail) {
				popBack(ll);
			} else {
				temp->prev->next = temp->next;
				temp->next = NULL;
				tempdata = temp->dataPtr;
				free(tempdata);
				free(temp);
			}
#if DEBUG
			printf(">>==============Node with value: %f pop'd ================<<\n",val);
#endif
			return;
		} else {
			temp = temp->next;
		}
	}
}
