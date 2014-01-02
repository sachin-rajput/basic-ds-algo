#include "linkedList.h"


/***
 * int addDirection :
 * 		1 - addFront
 * 		2 - addBack
 */
linkList *readData(char *filename,int addDirection);

int main(int argc, char* argv[])
{

#if DEBUG
	printf("\n>>==============Debug Value Set=================<<\n");
#endif
	char* file = argv[1];
	linkList *newlinkList = readData(file,1);
	//linkList *newlinkList = readData(file,2); //adding from back
	addatPosition(newlinkList,10,45);
	popFront(newlinkList);
	popBack(newlinkList);
	popatPosition(newlinkList,7);
	popwithValue(newlinkList,45);
	printlinkList(newlinkList);
	int value_f = 222;
	int i = searchValue(newlinkList,value_f);
#if DEBUG
	if(i == 1)
		printf(">>==============Search: Value %d found=================<<\n",value_f);
	else
		printf(">>==============Search: Value not found=================<<\n");
#endif

	cleanlinkList(newlinkList);
	return 0;
}

linkList *readData(char *filename,int addDirection)
{
	FILE* input_file = fopen(filename,"r");
	if(input_file == NULL) {
		printf("Error opening input file %s\n",filename);
		exit(1);
	}
	int i;
	int value = 0.0;
#if DEBUG
	printf(">>==============Creating Linklist=================<<\n");
#endif
	linkList *newlinkList = createlinkList();
	while(fscanf(input_file, "%d", &value) != EOF) {
		addFront(newlinkList,value);
	}
	fclose(input_file);
#if DEBUG
	printf(">>==============Linklist Created=================<<\n\n");
#endif
	return newlinkList;
}
