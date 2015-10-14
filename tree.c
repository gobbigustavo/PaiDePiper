#include<stdio.h>
#include<stdlib.h>
#include "priorityqueue.c"

struct tree{
  unsigned int size;
  Node *first;
};

Tree *createTreeFromQueue(){
  Tree *tree = (Tree*)malloc(sizeof(Tree));
  tree->first = NULL;
  tree->size = 0;
  return tree;
}

Tree *createTree(PriorityQueue *pq){
  Node *leftNode, *rightNode;
  Tree *huffTree = createTreeFromQueue();
  int frequencySum;
  while(queueLength(pq)>1){
    firstNode = dequeue(pq);
    secondNode = dequeue(pq);
    frequencySum = leftNode->frequency + rightNode->frequency;
    pq = insertTreeNodeOnPQ(pq, '*', frequencySum, firstNode, secondNode);
  }
  huffTree->first = pq->first;
  return huffTree;
}
