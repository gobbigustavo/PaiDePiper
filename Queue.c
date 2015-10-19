#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct queue{
    int currentSize;
    int first;
    int items[];
};typedef struct queue Queue;

Queue* createQueue() {
    Queue *queue = (Queue*) malloc(sizeof(Queue));
    queue->currentSize = 0;
    queue->first = 0;
    return queue;
}

void addToQueue(Queue* queue, unsigned char item){

}
