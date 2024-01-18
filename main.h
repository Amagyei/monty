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
} Stack;

Stack* declareStack(int capacity);
void freeStack(Stack* stack);
void push(Stack* stack, const char* arg, int line_number);
void pall(Stack* stack);

#endif /* MAIN_H */

