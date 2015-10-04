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

int queueLength(Queue *pq){
    Node *current = pq->first;
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

Tree *createTree(Queue *pq){
  Node *leftNode, *rightNode, *newNode;
  Tree *huffTree = createTreeFromQueue();
  int frequencySum;
  while(queueLength(pq)>1){
    leftNode = dequeue(pq);
    rightNode = dequeue(pq);
    frequencySum = leftNode->frequency + rightNode->frequency;
  }
  huffTree->first = newNode;
  return huffTree;
}
