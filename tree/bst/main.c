#include "tree.h"

 
tree *readData(char *filename);

int main(int argc, char* argv[])
{

#if DEBUG
	printf("\n>>==============Debug Value Set=================<<\n");
#endif
	char* file = argv[1];
	tree *newTree = readData(file);

#if DEBUG
	printf("\n>>==============Printing tree in InOrder=================<<\n");
#endif
	inOrder(newTree->root);
	printf("\n");
#if DEBUG
	printf("\n>>==============Printing tree in PreOrder=================<<\n");
#endif
	preOrder(newTree->root);
	printf("\n");
#if DEBUG
	printf("\n>>==============Printing tree in PostOrder=================<<\n");
#endif
	postOrder(newTree->root);
	printf("\n");	



#if DEBUG
	printf("\n>>==============Deleting with case 1: =================<<\n");
#endif	
	delete(newTree,51);
	
#if DEBUG
	printf("\n>>==============Printing after deletion, in InOrder=================<<\n");
#endif

#if DEBUG
	printf("\n>>==============Deleting with case 2: =================<<\n");
#endif	
	delete(newTree,52);
#if DEBUG
	printf("\n>>==============Printing after deletion, in InOrder=================<<\n");
#endif

#if DEBUG
	printf("\n>>==============Deleting with case 3: =================<<\n");
#endif	
	delete(newTree,10);
#if DEBUG
	printf("\n>>==============Printing after deletion, in InOrder=================<<\n");
#endif

	inOrder(newTree->root);
	printf("\n");

#if DEBUG
	printf("\n>>==============Searching for a value =================<<\n");
#endif
	bool ans = search(newTree->root,57);
	if(ans == 1)
		printf("Value found!\n" );
	else
		printf("Value not found!\n" );

	ans = search(newTree->root,99);
	if(ans == 1)
		printf("Value found!\n" );
	else
		printf("Value not found!\n" );

#if DEBUG
	printf("\n>>==============Height of tree =================<<\n");
#endif
	int ht = height(newTree->root);
	printf("%d \n",ht);

#if DEBUG
	printf("\n>>==============Is given tree a BST? =================<<\n");
#endif
	int ansbst = isBST(newTree->root,4,58);
	printf("%d \n",ansbst);

	//printf("%d\n", newTree->root->left->left->right->left->left->dataPtr->value);

	clearTree(newTree->root);
	free(newTree);
}

tree *readData(char *filename)
{
	FILE* input_file = fopen(filename,"r");
	if(input_file == NULL) {
		printf("Error opening input file %s\n",filename);
		exit(1);
	}
	int i;
	int value = 0;
#if DEBUG
	printf(">>==============Creating Tree=================<<\n");
#endif
	tree *newTree = createTree();
	while(fscanf(input_file, "%d", &value) != EOF) {
		insert(newTree,value);
	}
	fclose(input_file);
#if DEBUG
	printf(">>==============Tree Created=================<<\n\n");
#endif
	return newTree;
}