#include <stdio.h>
#include <stdlib.h>

struct tree {
    int item;
    struct tree *left;
    struct tree *right;
};

typedef struct tree Tree;

Tree *createEmpityTree() {
    return NULL;
}

Tree *createTree(int item, Tree *left, Tree *right) {
    Tree *tree = (Tree*) malloc(sizeof(Tree));
    tree->item = item;
    tree->left = left;
    tree->right = right;
}

int isEmpity(Tree *tree) {
    return (tree == NULL);
}

void printPreOrder(Tree *tree) {
    if(tree != NULL) {
        printf("%d", tree->item);
        printPreOrder(tree->left);
        printPreOrder(tree->right);
    }
}

void printInOrder(Tree *tree) {
    if(tree != NULL) {
        printInOrder(tree->left);
        printf("%d", tree->item);
        printInOrder(tree->right);
    }
}

void printPostOrder(Tree *tree) {
    if(tree != NULL) {
        printPostOrder(tree->left);
        printPostOrder(tree->right);
        printf("%d", tree->item);
    }
}
