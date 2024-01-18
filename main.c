#include "monty.h"
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

stack_t* declarestack_t(int capacity) {
    stack_t* stack = malloc(sizeof(stack_t));

	

	

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
void freestack_t(stack_t* stack) {
    free(stack->array);
    free(stack);
}
int main(int argc, char* argv[]) {
	FILE* file = fopen(argv[1], "r");
	stack_t* mystack_t = declarestack_t(MAX_STACK_SIZE);
	instruction_t instructions[] = {
        {"push", push},
        {"pall", pall},

        {NULL, NULL} // Terminate the array with NULL values
    };
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


	while (fscanf(file, "%s", opcode) != EOF) {
        line_number++;

        // Search for the opcode in the instructions array
        int i = 0;
        while (instructions[i].opcode != NULL) {
            if (strcmp(opcode, instructions[i].opcode) == 0) {
                // Execute the corresponding function
                instructions[i].f(&mystack_t, line_number);
                break;
            }
            i++;
        }

        if (instructions[i].opcode == NULL) {
            printf("L%d: Unknown opcode: %s\n", line_number, opcode);
            freeStack(mystack_t);
            fclose(file);
            exit(EXIT_FAILURE);
        }
    }

	fclose(file);
	freestack_t(mystack_t);

	return 0;
}
