#include <stdio.h>
#include <stdlib.h>

struct node {
    char character;
    char* binary;
    struct node *nextNode;
};

typedef struct node Node;

struct stack {
    Node *top;
};

typedef struct stack Stack;

Stack *createStack() {
    Stack *stack = (Stack*) malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

void push(Stack *stack, char character, char* binary) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->character = character;
    newNode->binary = binary;
    newNode->nextNode = stack->top;
    stack->top = newNode;
}

void pop(Stack *stack) {
    Node *current = (Node*) malloc(sizeof(Node));
    stack->top = stack->top->nextNode;
    printf("%c", current->character);
    free(current);
}

int peek(Stack *stack) {
    return stack->top->character;
}


int main(){
    Node *stack = createStack();
    push(stack, 'c', 00011);
    printf("%c",peek(stack));
}
