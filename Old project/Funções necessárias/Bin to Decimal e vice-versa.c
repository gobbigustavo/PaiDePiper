#define MAX_SIZE 20
#include <stdlib.h>
#include <stdio.h>
struct stack {
    int currentSize;
    int itens[MAX_SIZE];
} typedef Stack;

Stack * createStack(){
    Stack* stk = (Stack*)malloc(sizeof(Stack));
    stk->currentSize = 0;
    return stk;
}

Stack * push(int item, Stack * stk){
    if(stk->currentSize >= MAX_SIZE){
        printf("Stack OverFlow!");
        return NULL;
    } else {
        stk->itens[stk->currentSize++] = item;
    }
    return stk;
}
int isEmpty(Stack* stk){
    return stk->currentSize == 0;
}

int peek(Stack* stk){
    if(!isEmpty(stk)){
        return stk->itens[stk->currentSize-1];
    } else {
        return -1;
    }
}

int pop(Stack* stk){
    if(!isEmpty(stk)){
        return stk->itens[--stk->currentSize];
    } else {
        return -1;
    }
}

int convertBtoD(char *array){
    int i, result = 0;
    Stack *stk = createStack();
    for(i=0; array[i] != '\0'; i++){
        stk = push((int)array[i]-48, stk);
    }

    while(!isEmpty(stk)){
        result += pop(stk)*pow((double)2, (double)stk->currentSize);
    }
    return result;
}

void convertDtoB(int decimal, char *result){
    int b;
    Stack *stk = createStack();
    while(decimal != 0){
        b = decimal%2;
        stk = push(b, stk);
        decimal = decimal/2;
    }
    int i=0;
    while(!isEmpty(stk)){
        result[i] = pop(stk)+48;
        i++;
    }
    result[i] = '\0';
    return result;

}

int main(){
    char array[] = "00001000111001";
    int r = convertBtoD(array);
    printf("%d\n", r);
    char result[20] = "";
    convertDtoB(r, result);
    printf("%s", result);

}
