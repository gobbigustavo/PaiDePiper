#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    char item[8];
    struct node *nextNode;
};

typedef struct ListNode ListNode;

ListNode *createList() {
    return NULL;
}

int isEmpty(ListNode *first) {
    return (first == NULL);
}

ListNode *insertNode(ListNode *first, char item[8]) {
    ListNode *newNode = (ListNode*) malloc(sizeof(ListNode));
    strcpy(newNode->item, item);
    newNode->nextNode = first;
    first = newNode;
}
/*
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
*/
