#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct pqueue PriorityQueue;
PriorityQueue* createPriorityQueue();
PriorityQueue* enqueue(PriorityQueue *pq, int character, int priority);
int dequeue(PriorityQueue *pq);
int maximum(PriorityQueue *pq);
int isEmpty(PriorityQueue *pq);
void printPriorityQueue(PriorityQueue *pq);
typedef struct Node Node;

struct Node {
char character;
int priority;
Node *nextNode;
};



struct pqueue {
Node *first;
};

PriorityQueue* enqueue(PriorityQueue *pq, int character, int priority) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->character = character;
    newNode->priority = priority;
    if ((isEmpty(pq)) || (priority > pq->first->priority)) {
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

QueueisEmpty(PriorityQueue *pq){
return (pq->first == NULL);
}
