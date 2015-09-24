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
	newNode->parent = NULL;
	newNode->dataPtr = newDataIn;
	return newNode;
}

/**
 * Creates a data with int value
 */
data *createData(int valueIn){
	data *newData = (data*)malloc(sizeof(data));
	newData->value = valueIn;
	newData->height = -1;
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
 * Inserts a node in tree 
 * This will be a recursive function
 */
node *insert(node *currNode, int valueIn){
	
	if(currNode==NULL) {
		data *newDataIn = createData(valueIn);
		return createNode(newDataIn);
	}

	int cmp = compare_int(currNode->dataPtr->value,valueIn);
	
	if(cmp<1)
		currNode->left = insert(currNode->left,valueIn);
	else 
		currNode->right = insert(currNode->right,valueIn);

	//Update ancestors
	currNode->dataPtr->height = max(height(currNode->left),height(currNode->right))+1;

	//check balance
	int balance = getBalance(currNode);

	int key = valueIn;

	// Left Left Case
    if (balance > 1 && key < currNode->left->dataPtr->value){
        //printf("left left case \n");
        return rightRotate(currNode);
    }
    
    // Right Right Case
    if (balance < -1 && key > currNode->right->dataPtr->value){
        //printf("right right case and current node is %d curr->right: %d \n",node->val,node->right->val);        
        return leftRotate(currNode);
    }
 
    // Left Right Case
    if (balance > 1 && key > currNode->left->dataPtr->value)
    {
        //printf("left right case \n");        
        currNode->left =  leftRotate(currNode->left);
        return rightRotate(currNode);
    }
 
    // Right Left Case
    if (balance < -1 && key < currNode->right->dataPtr->value)
    {
        //printf("right left case \n");        
        currNode->right = rightRotate(currNode->right);
        return leftRotate(currNode);
    }
 
    /* return the (unchanged) node pointer */
    return currNode;
}

// A utility function to right rotate subtree rooted with y
// See the diagram given above.
node *rightRotate(node *y)
{
    node *x = y->left;
    node *T2 = x->right;
 
    // Perform rotation
    x->right = y;
    y->left = T2;
 
    // Update heights
    y->dataPtr->height = max(height(y->left), height(y->right))+1;
    x->dataPtr->height = max(height(x->left), height(x->right))+1;
 
    // Return new root
    return x;
}
 
// A utility function to left rotate subtree rooted with x
// See the diagram given above.
node *leftRotate(node *x)
{
    node *y = x->right;
    node *T2 = y->left;
 
    // Perform rotation
    y->left = x;
    x->right = T2;
 
    //  Update heights
    x->dataPtr->height = max(height(x->left), height(x->right))+1;
    y->dataPtr->height = max(height(y->left), height(y->right))+1;

    // Return new root
    return y;
}

/**
 * Deletes the node with the data supplied
 */
bool delete(tree *bst, int valueIn){
	
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
	if(nodeIn==NULL) return -1;
	return nodeIn->dataPtr->height;
}

int max(int a, int b)
{
    return (a > b)? a : b;
}

int getBalance(node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

/**
 * Checks if the supplied tree is balanced tree
 */
bool isBalanced(node *nodeIn) {
    if(nodeIn == NULL) return true;
    if(nodeIn->dataPtr->value < minData || nodeIn->dataPtr->value > maxData) return false;
    
    return isBST(nodeIn->left, minData, nodeIn->dataPtr->value) && isBST(nodeIn->right, nodeIn->dataPtr->value, maxData);
}
