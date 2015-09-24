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

	printf("root is : %d\n",newTree->root->dataPtr->value);

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
		newTree->root = insert(newTree->root,value);
	}
	fclose(input_file);
#if DEBUG
	printf(">>==============Tree Created=================<<\n\n");
#endif
	return newTree;
}