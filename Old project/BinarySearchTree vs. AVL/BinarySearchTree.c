#include <stdio.h>
#include <stdlib.h>

// BINARYSEARCHTREE ADT
// STRUCT TREE
// REPRESENTS A "NODE" OF A BINARY SEARCH TREE
struct tree {
    int item;
    int comparisons;
    struct tree *left;
    struct tree *right;
};

typedef struct tree Tree;

// FUNCTION CREATEEMPITYTREE
// CREATES A EMPTY TREE (NULL POINTER)
Tree *createEmptyTree() {
    return NULL;
}

// FUNCTION CREATETREE
// CREATES A NON-NULL TREE, WITH HER ITEM AND POINTERS
Tree *createTree(int item, Tree *left, Tree *right) {
    Tree *tree = (Tree*) malloc(sizeof(Tree));
    tree->item = item;
    tree->left = left;
    tree->right = right;
}

// FUNCTION ISEMPTY
// VERIFIES IF THE TREE IS EMPTY (NULL POINTER)
int isEmpty(Tree *tree) {
    return (tree == NULL);
}

// FUNCTION BINARYSEARCH (RECURSIVE)
// SEARCHS FOR AN ITEM IN THE TREE AND RETURN THE NUMBER OF COMPARISONS NEEDED TO FIND THE GIVEN ITEM
int binarySearch(Tree *tree, int item, int comparisons) {
    if(tree == NULL) {
        printf("Element not found.\n");
        return -1;
    }
    if(item > tree->item) {
        comparisons++;
        return binarySearch(tree->right, item, comparisons);
    } else if(item < tree->item) {
        comparisons++;
        return binarySearch(tree->left, item, comparisons);
    } else {
        return comparisons;
    }
}

// FUNCTION INSERTNODE
// INSERTS A "NODE" IN THE TREE IN THE CORRECT POSITION
Tree *insertNode(Tree *tree, int item) {
    if (tree == NULL) {
        return(createTree(item, NULL, NULL));
    }
    if (item < tree->item) {
        tree->left  = insertNode(tree->left, item);
    } else {
        tree->right = insertNode(tree->right, item);
    }
    return tree;
}
