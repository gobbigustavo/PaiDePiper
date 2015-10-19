#ifndef QUEUE_DECLARATIONS_H_
#define QUEUE_DECLARATIONS_H_

typedef struct queue Queue;
Queue* createQueue();
void addToQueue(Queue* queue, unsigned char item);

#endif