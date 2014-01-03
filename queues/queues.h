#ifndef _QUEUE_H_
#define _QUEUE_H_
/***
 * Author : Sachin Rajput
 * License : GNU GENERAL PUBLIC LICENSE
 */

#include "dlinkList.h"

/***
 * We are using a dlinklist to implement the queue
 */
typedef struct
{
  dlinklist *ll;
}queue;

/***
 * Creates a queue using structure containing a dlinklist
 */
queue* createQueue();

/***
 * Pushes the data in the queue from top 
 */
void queuePush(queue *s,data *d);

/***
 * Pop's data from the top
 */
void queuePop(queue *s);

/***
 * Print the data from the queue
 */
void queuePrint(queue *s);

/***
 * Get the queue size
 */
int queueSize(queue *s);

/***
 * Cleans the queue
 */
void queueClean(queue *s);

#endif