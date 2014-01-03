#ifndef _STACK_H_
#define _STACK_H_
/***
 * Author : Sachin Rajput
 * License : GNU GENERAL PUBLIC LICENSE
 */

#include "dlinklist.h"

/***
 * We are using a dlinklist to implement the stack
 */
typedef struct
{
  dlinklist *ll;
}stack;

/***
 * Creates a stack using structure containing a dlinklist
 */
stack* createStack();

/***
 * Pushes the data in the stack from top 
 */
void stackPush(stack *s,data *d);

/***
 * Pop's data from the top
 */
void stackPop(stack *s);

/***
 * Print the data from the stack
 */
void stackPrint(stack *s);

/***
 * Get the stack size
 */
int stackSize(stack *s);

/***
 * Cleans the stack
 */
void stackClean(stack *s);

#endif