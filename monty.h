#ifndef MAIN_H
#define MAIN_H

#define MAX_STACK_SIZE 100
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int* array;
    int top;
    int capacity;
} stack_t;

typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

stack_t* declarestack_t(int capacity);
void freestack_t(stack_t** stack);
void push(stack_t **stack, unsigned int line_number, const char *arg);
void pall(stack_t **stack);

#endif /* MAIN_H */
