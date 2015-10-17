#ifndef TREE_DECLARATIONS_H_
#define TREE_DECLARATIONS_H_

typedef struct tree Tree;
Tree *createTreeFromQueue();
Tree *createTree(PriorityQueue *pq);
void printTreePreOrder(Node* node);
unsigned char* binarySearch(Node* first, unsigned char character, unsigned char* huffChar);
unsigned char* getHuffChar(Node* first, unsigned char character);

#endif
