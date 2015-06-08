#include <stdio.h>
#include <stdlib.h>

struct node {
    int item;
    struct node *nextNode;
};

typedef struct node Node;

Node *createList() {
    return NULL;
}

int isEmpty(Node *first) {
    return (first == NULL);
}

Node *insertNode(Node *first, int item) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->item = item;
    newNode->nextNode = first;
}

Node *searchNode(Node *first, int item) {
    Node *pointer;
    for(pointer = first; pointer != NULL; pointer = pointer->nextNode) {
        if(pointer->item == item) {
            return pointer;
        }
    }
    return NULL;
}

Node *removeNode(Node *first, int item) {
    Node *previous = NULL;
    Node *current = first;
    while(current != NULL && current->item != item) {
        previous = current;
        current = current->nextNode;
    }
    if(current == NULL) {
        return first;
    }
    if(previous == NULL) {
        first = current->nextNode;
    } else {
        previous->nextNode = current->nextNode;
    }
    free(current);
    return first;
}

void printList(Node *first) {
    Node *pointer;
    for(pointer = first; pointer != NULL; pointer = pointer->nextNode) {
        printf("%d", pointer->item);
    }
}
