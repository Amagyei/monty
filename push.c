#include "main.h"


/*
 * push - function to push items onto stack
 *
 * Description: function fr stack to recieve items
 *
 * @value: item to be recieved onto stack
 *
 * return: 0 for success
 */
void push(Stack* stack, const char* arg, int line_number) {
	int value = atoi(arg);

	if (arg == NULL || *arg == '\0')
	{
		printf("L%d: usage: push integer\n", line_number);
		freeStack(stack);
		exit(EXIT_FAILURE);
	}


	if (stack->top == stack->capacity - 1)
	{
		printf("L%d: Stack overflow\n", line_number);
		freeStack(stack);
		exit(EXIT_FAILURE);
	}

	stack->array[++stack->top] = value;
}

