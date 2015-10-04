#include<stdio.h>
#include<stdlib.h>

typedef struct node{
  char byte;
  int frequency;
  struct node *leftNode;
  struct node *rightNode;
  struct node *nextNode;
}Node;

typedef struct queue{
    Node *first;
}Queue;

typedef struct tree{
  int size;
  Node *first;
}Tree;

int queueisEmpty(Queue *queue){
    return(queue->first == NULL);
}

Queue *dequeue(Queue *queue){
  if(!queueisEmpty){
    Node *current = queue->first;
    queue->first = queue->first->leftNode;
    current->nextNode = NULL;
    return current;
  }
  return NULL;
}

int queueLength(Queue *queue){
    Node *current = queue->first;
    int counter = 0;
    while(current != NULL){
      current = current->nextNode;
      counter++;
    }
    return counter;
}

Tree *createTreeFromQueue(){
  Tree *tree = (Tree*)malloc(sizeof(Tree));
  tree->first = NULL;
  tree->size = 0;
  return tree;
}

Tree *createTree(Queue *queue){
  Node *leftNode, *rightNode, *newNode;
  Tree *huffTree = createTreeFromQueue();
  int frequencySum;
  while(queueLength(queue)>1){
    leftNode = dequeue(queue);
    rightNode = dequeue(queue);
    frequencySum = leftNode->frequency + rightNode->frequency;
  }
  huffTree->first = newNode;
  return huffTree;
}
