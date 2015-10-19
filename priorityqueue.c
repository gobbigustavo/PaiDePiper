#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "priorityqueue_declarations.h"

struct Node{
    unsigned char character;
    int frequency;
    Node *nextNode;
    Node *leftNode;
    Node *rightNode;
};

struct pqueue{

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
			printf("\\n | %d\n", current->frequency);
		} else {
			printf("%c | %d\n", current->character, current->frequency);
		}
		current = current->nextNode;
	}
}
PriorityQueue* enqueue(PriorityQueue *pq, unsigned char character, int frequency) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->character = character;
    newNode->frequency = frequency;
    if ((QueueisEmpty(pq)) || (frequency < pq->first->frequency)) {
        newNode->nextNode = pq->first;
        pq->first = newNode;
    }
    else {
        Node *current = pq->first;
        while ((current->nextNode != NULL) && (current->nextNode->frequency < frequency)) {
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

int queueLength(PriorityQueue *pq){
    Node *current = pq->first;
    int counter = 0;
    while(current != NULL){
      current = current->nextNode;
      counter++;
    }
    return counter;
}

PriorityQueue* StringtoQueue(unsigned char string[]){
    int count;
    char ascii[256] = {0};
    PriorityQueue* pq = createPriorityQueue();
    for(count = 0; count<strlen(string); count++){
        ascii[(int)string[count]] = ascii[(int)string[count]] + 1;
    }
    for(count = 0; count<256; count++){
        if(ascii[count]>=1){
            if(count == 42){
                enqueue(pq, '\*', ascii[count]);
            }
            if(count == 92){
                enqueue(pq, '\\', ascii[count]);
            }
            else{
                enqueue(pq, count, ascii[count]);
            }
        }
    }
    return pq;
}

Node* dequeue(PriorityQueue *pq) {
    if (!QueueisEmpty(pq)){
        Node *current = pq->first;
        Node *dequeued = (Node*) malloc(sizeof(Node));
        memcpy(dequeued, current, sizeof(Node));
        pq->first = pq->first->nextNode;
        free(current);
        return dequeued;
    }
    else {
    printf("Empty priority queue!");
    return NULL;
    }
}

PriorityQueue* insertTreeNodeOnPQ(PriorityQueue* pq, unsigned char character, int frequency, Node *leftNode, Node *rightNode){
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->character = character;
    newNode->frequency = frequency;
    newNode->leftNode = leftNode;
    newNode->rightNode = rightNode;
    if ((QueueisEmpty(pq)) || (frequency < pq->first->frequency)) {
        newNode->nextNode = pq->first;
        pq->first = newNode;
    }
    else {
        Node *current = pq->first;
        while ((current->nextNode != NULL) && (current->nextNode->frequency < frequency)) {
            current = current->nextNode;
        }
        newNode->nextNode = current->nextNode;
        current->nextNode = newNode;
    }
    return pq;
}
