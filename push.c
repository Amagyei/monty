#include "monty.h"


/*
 * push - function to push items onto stack
 *
 * Description: function fr stack to recieve items
 *
 * @value: item to be recieved onto stack
 *
 * return: 0 for success
 */
void push(stack_t **stack, unsigned int line_number, const char *arg)
{
	int value = atoi(arg);

	if (arg == NULL || *arg == '\0')
	{
		printf("L%d: usage: push integer\n", line_number);
		freestack_t(stack);
		exit(EXIT_FAILURE);
	}


	if ((* stack)->top == (* stack)->capacity - 1)
	{
		printf("L%d: stack_t overflow\n", line_number);
		freestack_t(stack);
		exit(EXIT_FAILURE);
	}

	(* stack)->array[++(* stack)->top] = value;
}

