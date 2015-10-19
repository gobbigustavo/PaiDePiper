#ifndef TREE_DECLARATIONS_H_
#define TREE_DECLARATIONS_H_

typedef struct tree Tree;
Tree *createTreeFromQueue();
Tree *createTree(PriorityQueue *pq);
void printTreePreOrder(Node* node);
Hashtable* treeSearch(Node* first);

#endif
