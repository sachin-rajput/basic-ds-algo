#include "tree.h"

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
	if(a>=b) return 0;
	else return 1;
}

/**
 * Inserts a data supplied
 */
void insert(tree *bst, int value){
	data *newDataIn = createData(value);
	if(bst->root == NULL){
		node *newNode = createNode(newDataIn);
		bst->root = newNode;
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
bool delete(tree *bst, int valueIn){
	if(bst->root==NULL) return false;

	node * root = bst->root;
	node *currNode = root;
	node *parentNode = root;

	while(currNode){
		if(currNode->dataPtr->value == valueIn){
			break;
		} else{
			int cmp = compare_int(currNode->dataPtr->value,valueIn);
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
			if(parentNode->left == currNode)
				parentNode->left = NULL;
			else
				parentNode->right = NULL;
			freePtr(currNode);
		}
	}
	//Case 2: Delete the node with one child 
	else if( (currNode->left == NULL && currNode->right != NULL) ||
		 	(currNode->left != NULL && currNode->right == NULL) ) {
		if(currNode->right){
			if(currNode==root){
				root = currNode->right;
			} else {
				if(parentNode->left == currNode)
					parentNode->left = currNode->right;
				else
					parentNode->right = currNode->right;
			}
		} else {
			if(currNode==root){
				root = currNode->left;
			} else {
				if(parentNode->right == currNode)
					parentNode->right = currNode->left;
				else
					parentNode->left = currNode->left;
			}
		}
		freePtr(currNode);
	}
	//Case 3: Delete the node with two child
	else if(currNode->left != NULL && currNode->right != NULL){

		//save current node in temp 
		node *temp = currNode;
		//save left and right of current node 
		node *leftNode = currNode->left;
		node *rightNode = currNode->right;

		//if right node's left and right are null, then 
		//make the right node as root if currnode is root 
		//make currnode's left as currnode's right's left 
		if(rightNode->right==NULL && rightNode->left==NULL){
			currNode->dataPtr->value = rightNode->dataPtr->value;
			currNode->right = NULL;
			freePtr(rightNode);
		} else {

			node *left_of_rightNode = rightNode->left;
			node *parent_of_left_of_rightNode = rightNode;

			if(left_of_rightNode){
				while(left_of_rightNode){
					if(left_of_rightNode->left == NULL)
						break;
					parent_of_left_of_rightNode = left_of_rightNode;
					left_of_rightNode = left_of_rightNode->left;
				}

				/* Move pointer of tempparentleft */
	            /* ensure there are no dangling links */
	            if (left_of_rightNode->right)
	                parent_of_left_of_rightNode->left = left_of_rightNode->right;
	            else parent_of_left_of_rightNode->left = NULL;

				currNode->dataPtr->value = left_of_rightNode->dataPtr->value;
				freePtr(left_of_rightNode);
			} else {
				currNode->dataPtr->value = rightNode->dataPtr->value; 
				if(rightNode->right)
					currNode->right = rightNode->right;
				else
					currNode->right = NULL;
				freePtr(rightNode);
			}
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


/**
 * Clears the tree
 */
void clearTree(node *root){
	if(root == NULL) return;
	clearTree(root->left);
	clearTree(root->right);
	freePtr(root);
}


/**
 * Print In-order 
 */
 void inOrder(node *root){
 	if(root==NULL) return;
 	inOrder(root->left);
 	printf(" %d ",root->dataPtr->value);
 	inOrder(root->right);
 }

 /**
 * Print In-order 
 */
 void preOrder(node *root){
 	if(root==NULL) return;
 	printf(" %d ",root->dataPtr->value);
 	preOrder(root->left);
 	preOrder(root->right);
 }

 /**
 * Print In-order 
 */
 void postOrder(node *root){
 	if(root==NULL) return;
 	postOrder(root->left);
 	postOrder(root->right);
 	printf(" %d ",root->dataPtr->value);
 }

 /**
 * Search the tree with the value
 */
bool search(node *root, int valueIn){
	if(root == NULL) return false;
	if(root->dataPtr->value==valueIn) return true;
	int cmp = compare_int(root->dataPtr->value,valueIn);
	if(cmp<1)
		return search(root->left,valueIn);
	else
		return search(root->right,valueIn);
}

/**
 * Returns the height from the supplied node
 */
int height(node *nodeIn){
	if(nodeIn==NULL) return 0;
	int left = height(nodeIn->left);
	int right = height(nodeIn->right);
	if(left>right) return left+1;
	else return right + 1;
}

/**
 * Checks if the supplied tree is Binary Search Tree
 */
bool isBST(node *nodeIn, int minData, int maxData) {
    if(nodeIn == NULL) return true;
    if(nodeIn->dataPtr->value < minData || nodeIn->dataPtr->value > maxData) return false;
    
    return isBST(nodeIn->left, minData, nodeIn->dataPtr->value) && isBST(nodeIn->right, nodeIn->dataPtr->value, maxData);
}
