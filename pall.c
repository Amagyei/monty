#include "monty.h"


/*
 * pall - function fo rpall
 *
 * Description: function to pull and print all the items in the stack
 *
 * @stack: stack to be printed
 *
 * return: 0
 */


void pall(Stack* stack)
{
	int i;
	for (i = stack->top; i >= 0; i--)
	{
		printf("%d\n", stack->array[i]);
	}
}
