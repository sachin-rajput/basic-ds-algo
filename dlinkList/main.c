#include "dlinkList.h"


/***
 * int addDirection :
 * 		1 - addFront
 * 		2 - addBack
 */
dlinklist *readData(char *filename,int addDirection);

int main(int argc, char* argv[])
{

#if DEBUG
	printf("\n>>==============Debug Value Set=================<<\n");
#endif
	char* file = argv[1];
	dlinklist *newdlinklist = readData(file,1);
	//linkList *newlinkList = readData(file,2); //adding from back
	addatPosition(newdlinklist,2,4.5);
	popFront(newdlinklist);
	popBack(newdlinklist);
	popatPosition(newdlinklist,7);
	popwithValue(newdlinklist,32.34);
	printList(newdlinklist);
	reverseList(newdlinklist);
	printList(newdlinklist);
	float value_f = 33.4;
	searchRemove(newdlinklist,value_f);
	cleanList(newdlinklist);
	return 0;
}

dlinklist *readData(char *filename,int addDirection)
{
	FILE* input_file = fopen(filename,"r");
	if(input_file == NULL) {
		printf("Error opening input file %s\n",filename);
		exit(1);
	}
	float value = 0.0;
#if DEBUG
	printf(">>===============Creating dLinklist=================<<\n");
#endif
	dlinklist *newdlinklist = createlinklist();
	while(fscanf(input_file, "%f", &value) != EOF) {
		data *newData = createData(value);
		addFront(newdlinklist,newData);
	}
	fclose(input_file);
#if DEBUG
	printf(">>==============dLinklist Created=================<<\n\n");
#endif
	return newdlinklist;
}
