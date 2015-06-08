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
    newInternalNode->frequency = tree1->frequency + tree2->frequency;
    newInternalNode->left = tree1;
    newInternalNode->right = tree2;
    return newInternalNode;
}

// FUNCTION DEPTHSEARCH
// SEARCH AN ELEMENT IN THE WHOLE TREE AND RETURNS HIS PATH
char* DepthSearch(Tree* tree, char symbol, Tree* previous, int n, int count) {
    char path[30];
    int i;
    path[30] = '\0';
    tree->visited = 1;

    if((tree->symbol == symbol) && ((tree->left == NULL) && (tree->right == NULL))) {
        return path;
    }
    else {
        if(((tree->left->visited == 1) && (tree->right->visited == 1)) || ((tree->left == NULL) && (tree->right == NULL))) {
            n++; //removendo da string
            count--;
            DepthSearch(tree->previous, symbol, tree->previous->previous, n, count);
        }

        else {
            if((tree->left == NULL) || (tree->left->visited == 1)) {
                if(tree->right->visited == 1) {
                    n++; //removendo da string
                    count--;
                    DepthSearch(tree->previous, symbol, tree->previous->previous, n, count);
                }
                else {
                    // add 1 na string
                    for(i = n - 1; i >= 0; i--) {
                        path[i] = 1;
                        n--;
                        count++;
                    }
                    DepthSearch(tree->right, symbol, tree, n, count);
                }
            }
            else if((tree->right == NULL) || (tree->right->visited == 1)) {
                n++;
                count--;
                DepthSearch(tree->previous, symbol, tree->previous->previous, n, count);
            }
            else {
                //add 0 na string
                for(i = n - 1; i >= 0; i--){
                    path[i] = 0;
                    n--;
                    count++;
                }
                DepthSearch(tree->left, symbol, tree, n, count);
           }
        }
    }

    for(i = n; i < n + count; i++) {
          printf("%c", path[i]);
    }
}

struct nodeQueue {
    Tree* leaf;
    struct nodeQueue *nextnodeQueue;
};

typedef struct nodeQueue nodeQueue;

struct priority_queue {
    int currentSize;
    nodeQueue *first;
};

typedef struct priority_queue PriorityQueue;

PriorityQueue* createPriorityQueue() {
    PriorityQueue* priorityQueue = (PriorityQueue*) malloc(sizeof(PriorityQueue));
    priorityQueue->first = NULL;
    return priorityQueue;
}

PriorityQueue* enqueue(PriorityQueue *priorityQueue, char item, int priority) {
    nodeQueue* newnodeQueue = (nodeQueue*) malloc(sizeof(nodeQueue));
    newnodeQueue->leaf->symbol = item;
    newnodeQueue->leaf->frequency = priority;
    newnodeQueue->leaf->visited = 0;
    newnodeQueue->leaf->left = NULL;
    newnodeQueue->leaf->right = NULL;
    if(priorityQueue->first == NULL || priority < priorityQueue->first->leaf->frequency) {
        newnodeQueue->nextnodeQueue = priorityQueue->first;
        priorityQueue->first = newnodeQueue;
    } else {
        nodeQueue *current = priorityQueue->first;
        while(current->nextnodeQueue != NULL && current->nextnodeQueue->leaf->frequency < priority) {
            current = current->nextnodeQueue;
        }
        newnodeQueue->nextnodeQueue = current->nextnodeQueue;
        current->nextnodeQueue = newnodeQueue;
    }
    priorityQueue->currentSize++;
    return priorityQueue;
}

nodeQueue* dequeue(PriorityQueue *priorityQueue) {
    if(priorityQueue->first == NULL) {
        printf("Priority Queue empty.\n");
        return NULL;
    } else {
        nodeQueue* current = priorityQueue->first;
        nodeQueue* returnCurrent = current;
        priorityQueue->first = priorityQueue->first->nextnodeQueue;
        free(current);
        return returnCurrent;
    }
}
