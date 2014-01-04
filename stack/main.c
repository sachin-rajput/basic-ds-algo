#include "stack.h"


/***
 * int addDirection :
 * 		1 - addFront
 * 		2 - addBack
 */
stack *readData(char *filename,int addDirection);

int main(int argc, char* argv[])
{

#if DEBUG
	printf("\n>>==============Debug Value Set=================<<\n");
#endif
	char* file = argv[1];
	stack *newstack = readData(file,1);
	stackPrint(newstack);
	data *datapopd = stackPop(newstack);
	// do something with datapopd ...... after use free it
	free(datapopd);
	stackClean(newstack);
	return 0;
}

stack *readData(char *filename,int addDirection)
{
	FILE* input_file = fopen(filename,"r");
	if(input_file == NULL) {
		printf("Error opening input file %s\n",filename);
		exit(1);
	}
	float value = 0.0;
#if DEBUG
	printf(">>===============Creating stack=================<<\n");
#endif
	stack *newdstack = createStack();
	while(fscanf(input_file, "%f", &value) != EOF) {
		data *newData = createData(value);
		stackPush(newdstack,newData);
	}
	fclose(input_file);
#if DEBUG
	printf(">>==============stack Created=================<<\n\n");
#endif
	return newdstack;
}
