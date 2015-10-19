#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "priorityqueue.c"
#include "tree_declarations.h"

struct tree{
  unsigned int size;
  Node *first;
};

Tree *createTreeFromQueue(){
  Tree *tree = (Tree*)malloc(sizeof(Tree));
  tree->first = NULL;
  tree->size = 0;
  return tree;
};

void printTreePreOrder(Node* node){
	if(node != NULL){
		printf("%c - %d\n", node->character, node->frequency);
		printTreePreOrder(node->leftNode);
		printTreePreOrder(node->rightNode);
	}
}

/*unsigned char* treeSearch(Node* first, unsigned char character, unsigned char huffChar[8]){
    Node* currentNode = first;
    ///Hashtable* hash = createHashtable();
    while(currentNode->leftNode != NULL && currentNode->rightNode != NULL){
        currentNode = currentNode->leftNode;
        strcat(huffChar, "0");
    }
    put(hash, currentNode->character);

}*/

Tree *createTree(PriorityQueue *pq){
  Node *firstNode, *secondNode;
  Tree *huffTree = createTreeFromQueue();
  int frequencySum;
  while(queueLength(pq)>1){
    firstNode = dequeue(pq);
    secondNode = dequeue(pq);
    frequencySum = firstNode->frequency + secondNode->frequency;
    pq = insertTreeNodeOnPQ(pq, '*', frequencySum, firstNode, secondNode);
  }
  huffTree->first = pq->first;
  return huffTree;
}

/*unsigned char* getHuffChar(Node* first, unsigned char character){
    unsigned char* huffChar;
    return treeSearch(first, character, huffChar);
}*/
