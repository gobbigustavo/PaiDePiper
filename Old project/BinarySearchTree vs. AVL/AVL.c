#include <stdio.h>
#include <stdlib.h>

// BINARYSEARCHTREE ADT
// STRUCT TREEAVL
// REPRESENTS A "NODE" OF AN AVL TREE
struct treeAVL {
    int item;
    int height;
    struct treeAVL *left;
    struct treeAVL *right;
};

typedef struct treeAVL TreeAVL;

// FUNCTION MAX
// RETURNS THE MAXIMUM OF TWO GIVEN INTEGERS
int max(int number1, int number2) {
    return (number1 > number2) ? number1 : number2;
}

// FUNCTION CREATEEMPITYTREE
// CREATES A EMPTY TREE (NULL POINTER)
TreeAVL *createEmptyAVLTree() {
    return NULL;
}

// FUNCTION CREATEAVLNODE
// CREATES A AVL "NODE" AS A LEAF (NULL LEFT AND RIGHT POINTERS)
TreeAVL* createAVLNode(int item) {
    TreeAVL* node = (TreeAVL*) malloc(sizeof(TreeAVL));
    node->item = item;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return(node);
}

// FUNCTION HEIGHTTREE
// RETURNS THE HEIGHT OF A GIVEN TREE
int heightTree(TreeAVL *tree) {
    if (tree == NULL) {
        return 0;
    }
    return tree->height;
}

// FUNCTION RIGHTROTATE
// DOES THE RIGHT ROTATITION IN AN AVL TREE AND UPDATE THE HEIGHTS OF THE GIVEN AND NEW TREES
TreeAVL *rightRotate(TreeAVL *tree) {
    TreeAVL *newTree = tree->left;
    TreeAVL *treeAux = newTree->right;

    // ROTATES RIGHT
    newTree->right = tree;
    tree->left = treeAux;

    // UPDATE THE HEIGHTS
    tree->height = max(heightTree(tree->left), heightTree(tree->right)) + 1;
    newTree->height = max(heightTree(newTree->left), heightTree(newTree->right)) + 1;
    return newTree;
}

// FUNCTION LEFTROTATE
// DOES THE LEFT ROTATITION IN AN AVL TREE AND UPDATE THE HEIGHTS OF THE GIVEN AND NEW TREES
TreeAVL *leftRotate(TreeAVL *tree) {
    TreeAVL *newTree = tree->right;
    TreeAVL *treeAux = newTree->left;

    // ROTATES RIGHT
    newTree->left = tree;
    tree->right = treeAux;

    // UPDATE THE HEIGHTS
    tree->height = max(heightTree(tree->left), heightTree(tree->right)) + 1;
    newTree->height = max(heightTree(newTree->left), heightTree(newTree->right)) + 1;
    return newTree;
}

// FUNCTION GETBALANCE
// RETURNS THE BALANCE OF A GIVEN TREE
int getBalance(TreeAVL *tree) {
    if (tree == NULL) {
        return 0;
    }
    return heightTree(tree->left) - heightTree(tree->right);
}

// FUNCTION INSERTNODE
// INSERTS A NEW NODE IN THE TREE WITH THE AVL STYLE :)
TreeAVL* insertNodeAVL(TreeAVL* node, int item) {
    if (node == NULL) {
        return(createAVLNode(item));
    }

    if (item < node->item) {
        node->left  = insertNodeAVL(node->left, item);
    } else {
        node->right = insertNodeAVL(node->right, item);
    }

    // UPDATE THE HEIGHT AND BALANCE OF THE PREVIOUS NODE
    node->height = max(heightTree(node->left), heightTree(node->right)) + 1;
    int balance = getBalance(node);

    // LEFT LEFT CASE
    if (balance > 1 && item < node->left->item) {
        return rightRotate(node);
    }

    // RIGHT RIGHT CASE
    if (balance < -1 && item > node->right->item) {
        return leftRotate(node);
    }

    // LEFT RIGHT CASE
    if (balance > 1 && item > node->left->item) {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }

    // RIGHT LEFT CASE
    if (balance < -1 && item < node->right->item) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

// FUNCTION BINARYSEARCHAVL (RECURSIVE)
// SEARCHS FOR AN ITEM IN THE TREE AND RETURN THE NUMBER OF COMPARISONS NEEDED TO FIND THE GIVEN ITEM
int binarySearchAVL(TreeAVL *tree, int item, int comparisons) {
    if(tree == NULL || tree->item == item) {
        return comparisons;
    } else {
        if(tree->item > item) {
            comparisons++;
            binarySearchAVL(tree->left, item, comparisons);
        } else {
            comparisons++;
            binarySearchAVL(tree->right, item, comparisons);
        }
    }
}
