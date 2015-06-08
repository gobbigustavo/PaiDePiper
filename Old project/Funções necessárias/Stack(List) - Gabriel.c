#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node {
    char number;
    struct node *nextNode;
};

typedef struct node Node;

struct stack {
    Node *top;
    int currentSize;
};

typedef struct stack Stack;

Stack *createStack() {
    Stack *stack = (Stack*) malloc(sizeof(Stack));
    stack->top = NULL;
    stack->currentSize = 0;
    return stack;
}

void push(Stack *stack, char number) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->number = number;
    newNode->nextNode = stack->top;
    stack->currentSize++;
    stack->top = newNode;
}

char pop(Stack *stack) {
    char aux;
    if(!isEmpty(stack)){
        Node *current = (Node*) malloc(sizeof(Node));
        aux = stack->top->number;
        stack->top = stack->top->nextNode;
        free(current);
        stack->currentSize--;
        return aux;
    } else {
        return NULL;
    }
}

char peek(Stack *stack) {
    return stack->top->number;
}

int isEmpty(Stack *stack){
    return (stack == NULL);
}


int main(){
    int number=0,digit=0,opc=0;
    char decimalNumber[1000];

    printf("1 para decimal para binario e 2 pra binario pra decimal\n");
    scanf("%d", &opc);

    if(opc==1){
        Stack *stack = createStack();
        scanf("%d", &number);

        while (number != 0) {
            digit = number % 2;
            push(stack, digit);
            number = number / 2;
        }

        while (!isEmpty(stack)) {
            printf("%d", pop(stack));
        }

    } else if(opc==2) {
        Stack *stack = createStack();
        char aaa[] = "2112";

        int i=0;

        while (aaa[i] != '\0') {
            int a = atoi(aaa[i]);
            push(stack, a);
            printf("add esse: %d\n",a);
            i++;
          }

        int aux1 = 0;
        while (!isEmpty(stack)) {
            int aux = 0;
            int aux2 = 0;

            aux2 = atoi(pop(stack));

            printf("nume é esse: %d\n", aux2-1);

            printf("current Size: %d\n\n", stack->currentSize);

            aux = (aux2-1)*pow(2, stack->currentSize-1);
            aux1+=aux;

        }
        printf("ax1 final: %d", aux1);
    }
}
