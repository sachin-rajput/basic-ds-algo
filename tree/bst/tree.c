#include "tree.c"

/**
 * Creates a tree
 */
tree *createTree(){
	tree *newtree = (tree*)malloc(sizeof(tree));
	newtree->root = NULL;
	return newtree;
}

/**
 * Creates a node with the data supplied
 */
node *createNode(data *newDataIn){
	node *newNode = (node*)malloc(sizeof(node));
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->dataPtr = newDataIn;
	return newNode;
}

/**
 * Creates a data with int value
 */
data *createData(int valueIn){
	data *newData = (data*)malloc(sizeof(data));
	newData->value = valueIn;
	return newData;
}

/**
 * Compare dataPtr 
 */
int compare(data *currData, data *dataIn){
	// we can call different comparator here ...
	return compare_int(currData->value,dataIn->value);
}

/**
 * Int comparator 
 */
int compare_int(int a,int b){
	if(a>=b) return 1;
	else return 0;
}

/**
 * Inserts a data supplied
 */
void insert(tree *bst, data *newDataIn){
	if(bst->root == NULL){
		node *newNode = createNode()
	} else
		insert_helper(bst->root,newDataIn);
}

/**
 * Insert helper for inserting a node in tree 
 * This will be a recursive function
 */
void insert_helper(node *currNode, data *newDataIn){
	int cmp = compare(currNode->dataPtr,newDataIn);
	if(cmp<1){
		if(currNode->left==NULL){
			currNode->left = createNode(newDataIn);
		} else 
			insert_helper(currNode->left,newDataIn);
	} else {
		if(currNode->right==NULL){
			currNode->right = createNode(newDataIn);
		} else 
			insert_helper(currNode->right,newDataIn);
	}
}

/**
 * Deletes the node with the data supplied
 */
bool delete(node *root, int valueIn){
	if(root==NULL) return false;

	node *currNode = root;
	node *parentNode = root;
	while(currNode){
		if(currNode->dataPtr->value == valueIn){
			break;
		} else{
			int cmp = compare_int(currNode->dataPtr->value,newDataIn->value);
			if(cmp<1){
				parentNode = currNode;
				currNode = currNode->left;
			}
			else{
				parentNode = currNode;
				currNode = currNode->right;
			}
		}
	}

	//return false if not found 
	if(currNode == NULL) return false;

	//three cases for delete 

	//Case 1: Delete the node with no child
	if(currNode->left == NULL && currNode->right == NULL){
		//if currNode was root 
		if(currNode == root){
			freePtr(currNode);
			return true;
		}
		else{
			freePtr(currNode);
			parentNode->left = NULL;
			parentNode->right = NULL;
		}
	}

	//Case 2: Delete the node with one child 
	else if((currNode->left == NULL && currNode->right != NULL) || (currNode->left != NULL && currNode->right == NULL)){
		if(currNode->left){
			if(currNode==root){
				root = currNode->left;
				freePtr(currNode);
			} else {
				parentNode->left = currNode->left;
				freePtr(currNode);
			}
		} else {
			if(currNode==root){
				root = currNode->right;
				freePtr(currNode);
			} else {
				parentNode->right = currNode->right;
				freePtr(currNode);
			}
		}
	}
	//Case 3: Delete the node with two child
	else if(currNode->left != NULL && currNode->right != NULL){
		node *leftNode = currNode->left;

		if(leftNode->left==NULL){
			currNode->dataPtr->value = leftNode->dataPtr->value;
			freePtr(leftNode);
			currNode->left = NULL;
		} else {
			node *templeft = leftNode;
			node *tempprevleft = leftNode;
			while(templeft){
				if(templeft->left == NULL)
					break;
				tempprevleft = templeft;
				templeft = templeft->left;
			}
			currNode->dataPtr->value = tempprevleft->dataPtr->value;
			freePtr(tempprevleft);
		}
	}
	return true;
}

/**
 * Free the pointers 
 */
void freePtr(node *nodeToDelete){
	free(nodeToDelete->dataPtr);
	free(nodeToDelete);
}
