#ifndef PRIORITYQUEU_DECLARATIONS_H_
#define PRIORITYQUEU_DECLARATIONS_H_

typedef struct Node Node;
typedef struct pqueue PriorityQueue;
PriorityQueue* createPriorityQueue();
PriorityQueue* enqueue(PriorityQueue *pq, unsigned char character, int frequency);
PriorityQueue* insertTreeNodeOnPQ(PriorityQueue *pq, unsigned char character, int frequency, Node *lefNode, Node *rightNode);
PriorityQueue* StringtoQueue(unsigned char string[]);
int queueLength(PriorityQueue *pq);
int QueueisEmpty(PriorityQueue *pq);
void printPriorityQueue(PriorityQueue *pq);
void freePriorityQueue(PriorityQueue *pq);
Node* dequeue(PriorityQueue *pq);
Node* createNode(unsigned char character, int frequency);


#endif
