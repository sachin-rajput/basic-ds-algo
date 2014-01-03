#include "stack.h"

/***
 * Creates a stack using structure containing a dlinklist
 */
stack* createStack()
{
	stack* new_stack = (stack*)malloc(sizeof(stack));
	new_stack->ll = createlinklist();
	return new_stack;
}

/***
 * Pushes the data in the stack from top
 */
void stackPush(stack *s,data *d)
{
	addBack(s->ll,d);
}

/***
 * Pop's data from the top
 */
void stackPop(stack *s)
{
	popBack(s->ll);
}

/***
 * Print the data from the stack
 */
void stackPrint(stack *s)
{
	printList(s->ll);
}

/***
 * Get the stack size
 */
int stackSize(stack *s)
{
	return listSize(s->ll);
}

/***
 * Cleans the stack
 */
void stackClean(stack *s)
{
	cleanList(s->ll);
	free(s);
}
