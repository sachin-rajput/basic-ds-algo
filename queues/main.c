#include "queue.h"


/***
 * int addDirection :
 * 		1 - addFront
 * 		2 - addBack
 */
queue *readData(char *filename,int addDirection);

int main(int argc, char* argv[])
{

#if DEBUG
	printf("\n>>==============Debug Value Set=================<<\n");
#endif
	char* file = argv[1];
	queue *newqueue = readData(file,1);
	queuePrint(newqueue);
	queuePop(newqueue);
	queueClean(newqueue);
	return 0;
}

queue *readData(char *filename,int addDirection)
{
	FILE* input_file = fopen(filename,"r");
	if(input_file == NULL) {
		printf("Error opening input file %s\n",filename);
		exit(1);
	}
	float value = 0.0;
#if DEBUG
	printf(">>===============Creating queue=================<<\n");
#endif
	queue *newdqueue = createQueue();
	while(fscanf(input_file, "%f", &value) != EOF) {
		data *newData = createData(value);
		queuePush(newdqueue,newData);
	}
	fclose(input_file);
#if DEBUG
	printf(">>==============queue Created=================<<\n\n");
#endif
	return newdqueue;
}
