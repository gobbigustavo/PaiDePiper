#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10

struct stack{
    int currentSize;
    int items[MAX_SIZE];
};

typedef struct stack Stack;

Stack *createStack() {
    Stack *stack = (Stack*) malloc(sizeof(Stack));
    stack->currentSize = 0;
    return stack;
}

int isEmpity(Stack *stack) {
    return (stack->currentSize == 0);
}

void push(Stack *stack, int item) {
    if(stack->currentSize == MAX_SIZE) {
        printf("Stack overflow.\n");
    } else {
        stack->items[stack->currentSize++];
    }
}

int pop(Stack *stack) {
    if(stack->currentSize == 0) {
        printf("Empity stack.\n");
        return -100000;
    } else {
        return stack->items[--stack->currentSize];
    }
}

int peek(Stack *stack) {
    if(stack->currentSize == 0) {
        printf("Empity stack.\n");
        return -100000;
    } else {
        return stack->items[stack->currentSize - 1];
    }
}
