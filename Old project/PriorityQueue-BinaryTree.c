#include <stdio.h>
#include <stdlib.h>

//ADT BINARY TREE
// STRUCT TREE
// REPRESENTS A BINARY TREE
// HAS A SYMBOL AND A FREQUENCY AS VALUES AND POINTERS TO LEFT, RIGHT AND PREVIOUS TREES
struct tree {
    char symbol;
    int frequency;
    int visited;
    struct tree *left;
    struct tree *right;
    struct tree *previous;
    struct tree *nextTree;
};

typedef struct tree Tree;

// FUNCTION CREATETREE
// CREATES A BINARY TREE SETING HER VALUES AND POINTERS
Tree *createTree(char symbol, int frequency, Tree *left, Tree *right) {
    Tree *binaryTree = (Tree*) malloc(sizeof(Tree));
    binaryTree->frequency = frequency;
    binaryTree->symbol = symbol;
    binaryTree->left = left;
    binaryTree->right = right;
    return binaryTree;
}

// FUNCTION CREATEINTERNALNODE
// CREATES AN INTERNAL NODE IN A BINARY TREE SETING HIS VALUES AND POINTERS
Tree *createInternalNode(Tree *tree1, Tree *tree2) {
    Tree *newInternalNode = (Tree*) malloc(sizeof(Tree));
    newInternalNode->symbol = '/';
    newInternalNode->frequency = tree1->frequency + tree2->frequency;
    newInternalNode->left = tree1;
    newInternalNode->right = tree2;
    return newInternalNode;
}

struct priority_queue {
    int currentSize;
    Tree* first;
};

typedef struct priority_queue PriorityQueue;

PriorityQueue* createPriorityQueue() {
    PriorityQueue* priorityQueue = (PriorityQueue*) malloc(sizeof(PriorityQueue));
    priorityQueue->currentSize = 0;
    priorityQueue->first = NULL;
    return priorityQueue;
}

PriorityQueue* enqueueInternalNode(PriorityQueue* priorityQueue, Tree* tree) {
    tree->visited = 0;
    if(priorityQueue->first == NULL || tree->frequency < priorityQueue->first->frequency) {
        tree->nextTree = priorityQueue->first;
        priorityQueue->first = tree;
    } else {
        Tree *current = priorityQueue->first;
        while(current->nextTree != NULL && current->nextTree->frequency < tree->frequency) {
            current = current->nextTree;
        }
        tree->nextTree = current->nextTree;
        current->nextTree = tree;
    }
    priorityQueue->currentSize++;
    return priorityQueue;
}

PriorityQueue* enqueue(PriorityQueue *priorityQueue, char item, int priority) {
    Tree* newTree = (Tree*) malloc(sizeof(Tree));
    newTree->symbol = item;
    newTree->frequency = priority;
    newTree->visited = 0;
    newTree->left = NULL;
    newTree->right = NULL;
    if(priorityQueue->first == NULL || priority < priorityQueue->first->frequency) {
        newTree->nextTree = priorityQueue->first;
        priorityQueue->first = newTree;
    } else {
        Tree *current = priorityQueue->first;
        while(current->nextTree != NULL && current->nextTree->frequency < priority) {
            current = current->nextTree;
        }
        newTree->nextTree = current->nextTree;
        current->nextTree = newTree;
    }
    priorityQueue->currentSize++;
    return priorityQueue;
}

Tree* dequeue(PriorityQueue *priorityQueue) {
    if(priorityQueue->first == NULL) {
        printf("Priority Queue empty.\n");
        exit(0);
        return NULL;
    } else {
        Tree* current = priorityQueue->first;
        Tree* returnCurrent = current;
        priorityQueue->first = priorityQueue->first->nextTree;
        //free(current);
        priorityQueue->currentSize--;
        return returnCurrent;
    }
}
