#include "main.h"
/**
 * main - Entry point for the Monty bytecode interpreter.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings representing the command-line arguments.
 *
 * Description:
 *   This function serves as the entry point for the Monty bytecode interpreter.
 *   It reads Monty bytecode instructions from a file specified as a command-line argument,
 *   interprets and executes the instructions, and handles errors.
 *
 * Return:
 *   Returns 0 upon successful execution, or EXIT_FAILURE if an error occurs.
 */

Stack* declareStack(int capacity) {
    Stack* stack = malloc(sizeof(Stack));

    if (stack == NULL) {
        printf("Memory allocation failed. Exiting.\n");
        exit(EXIT_FAILURE);
    }

    stack->array = (int*)malloc(capacity * sizeof(int));

    if (stack->array == NULL) {
        printf("Memory allocation failed. Exiting.\n");
        free(stack);
        exit(EXIT_FAILURE);
    }

    stack->top = -1;
    stack->capacity = capacity;

    return stack;
}
void freeStack(Stack* stack) {
    free(stack->array);
    free(stack);
}
int main(int argc, char* argv[]) {
	FILE* file = fopen(argv[1], "r");
	Stack* myStack = declareStack(MAX_STACK_SIZE);
	char opcode[50];
	char arg[50];
	int line_number = 0;

	if (argc != 2)
	{
		printf("Usage: %s <filename>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if (file == NULL) 
	{
		printf("Error: Could not open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}


	while (fscanf(file, "%s", opcode) != EOF)
	{
		line_number++;
		if (strcmp(opcode, "push") == 0)
		{
			if (fscanf(file, "%s", arg) != 1)
			{
				printf("L%d: usage: push integer\n", line_number);
				freeStack(myStack);
				fclose(file);
				exit(EXIT_FAILURE);
			}
			push(myStack, arg, line_number);
		}
		else if (strcmp(opcode, "pall") == 0)
		{
			pall(myStack);
		}
		else
		{
			printf("L%d: Unknown opcode: %s\n", line_number, opcode);
			freeStack(myStack);
			fclose(file);
			exit(EXIT_FAILURE);
		}
	}

	fclose(file);
	freeStack(myStack);

	return 0;
}
