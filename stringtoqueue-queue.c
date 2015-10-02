#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct pqueue PriorityQueue;
PriorityQueue* createPriorityQueue();
PriorityQueue* enqueue(PriorityQueue *pq, int i, int p);
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

PriorityQueue* isEmpty(PriorityQueue *pq){
  return (pq->first==NULL);
}

PriorityQueue* enqueue(PriorityQueue *pq, int i, int p) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->i = i;
    newNode->p = p;
    if ((isEmpty(pq)) || (p > pq->first->p)) {
        newNode->nextNode = pq->first;
        pq->first = newNode;
    }
    else {
        Node *current = pq->first;
        while ((current->nextNode != NULL) && (current->nextNode->p > p)) {
            current = current->nextNode;
        }
        newNode->nextNode = current->nextNode;
        current->nextNode = newNode;
    }
    return pq;
}

PriorityQueue* dequeue(PriorityQueue *pq){
  if(!isEmpty(pq)){
    Node *current = pq->first;
    pq->first = pq->first->nextNode;
    current->nextNode = NULL;
    return current;
  }
  return NULL;
}
