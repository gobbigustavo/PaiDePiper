#include <stdio.h>
#include <stdlib.h>

 struct q_node {
    char caracter;
    struct q_node *nextNode;
}typedef qNode;

struct queue{
    qNode* first;
    qNode* last;
    int currentSize;
} typedef Queue;

Queue * createQueue(){
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->currentSize = 0;
    q->first = NULL;
    q->last = NULL;
    return q;
}

Queue * simpleEnqueue(char c, Queue * q){
    qNode * newChar = (qNode*)malloc(sizeof(qNode));
    newChar->caracter = c;
    newChar->nextNode = NULL;
    if(isEmptyQueue(q)){
        q->first = newChar;
        q->last = newChar;
    } else {
        q->last->nextNode = newChar;
        q->last = newChar;
    }
    q->currentSize++;
    return q;
}

int isEmptyQueue(Queue* q){
    return !(q->currentSize);
}

char simpleDequeue(Queue* q){
    if(isEmptyQueue(q)){
        printf("is empty\n");
        return -1;
    } else {
        qNode * aux = q->first;
        q->first = q->first->nextNode;
        q->currentSize--;
        return (aux->caracter);
    }
}

void printQueue(Queue * q){
    qNode * atual = q->first;
    while(atual != NULL){
        printf("%c", atual->caracter);
        atual = atual->nextNode;
    }
    printf("\n");
}
