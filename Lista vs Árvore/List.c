#include <stdio.h>
#include <stdlib.h>

// ADT LIST
// STRUCT NODE
// REPRESENTS A NODE IN A LINKED LIST
// HAS A FILE AS VALUE AND A PONTEIR TO THE NEXT NODE IN THE LIST
struct Node {
    int item;
    char symbol; // JUST FOR THE TREE FILL
    struct Node *nextNode;
};

typedef struct Node Node;

// FUNCTION CREATELIST
// INITIALIZE A LINKED LIST WITH NULL
Node *createList() {
    return NULL;
}

// FUNCTION ISEMPTY
// CHECKS IF THE FIRST ELEMENT OF THE LIST IS NULL
// IF TRUE, THE LIST IS EMPTY
int isEmptyList(Node *first) {
    return (first == NULL);
}

// FUCNTION INSERTNODE
// INSERTS A NODE AT THE BEGINNING OF THE LIST
Node *insertNodeList(Node *first, int item) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->item = item;
    newNode->nextNode = first;
    return newNode;
}

// FUCNTION INSERTNODEFILLTREE
// INSERTS A NODE AT THE BEGINNING OF THE LIST
Node *insertNodeFillTree(char symbol, Node *first) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->symbol = symbol;
    newNode->nextNode = first;
    return newNode;
}

int searchNodeList(Node *first, int item, int comparisons) {
    Node *p;
    for (p = first; p != NULL; p = p->nextNode) {
        comparisons++;
        if (p->item == item) {
            return comparisons;
            }
        }
 return -1;
}
