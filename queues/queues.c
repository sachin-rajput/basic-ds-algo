#include "queue.h"

/***
 * Creates a queue using structure containing a dlinklist
 */
queue* createQueue(){
        queue* new_queue = (queue*)malloc(sizeof(queue)); 
        new_queue->ll = createlinklist();
        return new_queue;
}

/***
 * Pushes the data in the queue from top 
 */
void queuePush(queue *q,data *d){
        addFront(q->ll,d);
}

/***
 * Pop's data from the top
 */
void queuePop(queue *q){
        popBack(q->ll);
}

/***
 * Print the data from the queue
 */
void queuePrint(queue *q){
        printList(q->ll);
}

/***
 * Get the queue size
 */
int queueSize(queue *q){
        return listSize(q->ll);
}
 
/***
 * Cleans the queue
 */
void queueClean(queue *q){
        cleanList(q->ll);
        free(q);
}