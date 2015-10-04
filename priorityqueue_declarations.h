#ifndef PRIORITYQUEU_DECLARATIONS_H_
#define PRIORITYQUEU_DECLARATIONS_H_

typedef struct pqueue PriorityQueue;
PriorityQueue* createPriorityQueue();
PriorityQueue* enqueue(PriorityQueue *pq, char character, int priority);
PriorityQueue* StringtoQueue(char string[]);
int dequeue(PriorityQueue *pq);
int maximum(PriorityQueue *pq);
int QueueisEmpty(PriorityQueue *pq);
void printPriorityQueue(PriorityQueue *pq);
void freePriorityQueue(PriorityQueue* pq);
typedef struct Node Node;

#endif
