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


void pall(stack_t **stack, unsigned int line_number)
{
    int i;
	line_number++;
	
    for (i = (*stack)->top; i >= 0; i--)
    {
        printf("%d\n", (*stack)->array[i]);
    }
}

