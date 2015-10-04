#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "priorityqueue_declarations.h"

struct Node {
char character;
int priority;
Node *nextNode;
};

struct pqueue {
Node *first;
};

void freePriorityQueue(PriorityQueue* pq){
	Node *current;
	while(pq->first != NULL){
		current = pq->first;
		pq->first = pq->first->nextNode;
		free(current);
	}
}
void printPriorityQueue(PriorityQueue* pq){
	Node *current = pq->first;
	while(current != NULL){
		if(current->character == '\n'){
			printf("\\n | %d\n", current->priority);
		} else {
			printf("%c | %d\n", current->character, current->priority);
		}
		current = current->nextNode;
	}
}
PriorityQueue* enqueue(PriorityQueue *pq, char character, int priority) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->character = character;
    newNode->priority = priority;
    if ((QueueisEmpty(pq)) || (priority > pq->first->priority)) {
        newNode->nextNode = pq->first;
        pq->first = newNode;
    }
    else {
        Node *current = pq->first;
        while ((current->nextNode != NULL) && (current->nextNode->priority > priority)) {
            current = current->nextNode;
        }
        newNode->nextNode = current->nextNode;
        current->nextNode = newNode;
    }
    return pq;
}

int QueueisEmpty(PriorityQueue *pq){
    return (pq->first == NULL);
}

PriorityQueue* createPriorityQueue(){
	PriorityQueue* pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    pq->first = NULL;
	return pq;
}
