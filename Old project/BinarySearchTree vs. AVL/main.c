#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "BinarySearchTree.c"
#include "AVL.c"
#define SIZE 20

struct point {
    int x;
    int y;
};

typedef struct point Point;

void swap(Point *x, Point *y) {
    Point aux;
    aux = *x;
    *x = *y;
    *y = aux;
}

void display(Point array[], const int size) {
    int i;
    for(i = 0; i < size; i++) {
        printf("%d ", array[i].x);
    }
    printf("\n");
}

void bubleSort(Point array[], const int size) {
    int i, j;
    for(i = 0; i < (size - 1); i++) {
        for(j = 0; j < (size - (i + 1)); j++) {
                if(array[j].x > array[j + 1].x) {
                    swap(&array[j], &array[j + 1]);
                }
        }
    }
}

int main() {
    int i, option;
    Point arrayBinarySearchTree[SIZE];
    Point arrayAVLTree[SIZE];
    Tree* BinarySearchTree = createEmptyTree();
    TreeAVL* AVLTree = createEmptyAVLTree();
    printf("Count and plot data\nBinary Search Tree vs. AVL Tree\n\n");
    printf("To continue, type 1\nTo exit, type ant other key\n\n");
    printf("Your option: ");
    scanf("%d", &option);

    if(option == 1) {
        for(i = 0; i < 10000; i++) {
            BinarySearchTree = insertNode(BinarySearchTree, i);
            AVLTree = insertNodeAVL(AVLTree, i);
        }

        for(i = 0; i < SIZE; i++) {
            int random = rand() % 10000;
            arrayAVLTree[i].x = random;
            arrayAVLTree[i].y = binarySearchAVL(AVLTree, random, 0);
            arrayBinarySearchTree[i].x = random;
            arrayBinarySearchTree[i].y = binarySearch(BinarySearchTree, random, 0);
        }

        bubleSort(arrayAVLTree, SIZE);
        bubleSort(arrayBinarySearchTree, SIZE);

        printf("\nBinarySearchTree array - R Code:\n\n");
        printf("png(\"binarySearchTreePlot.png\")\n\n");
        printf("x = c(");
        for(i = 0; i < SIZE - 1; i++) {
            printf("%d, ", arrayBinarySearchTree[i].x);
        }
        printf("%d)\n", arrayBinarySearchTree[i].x);
        printf("y = c(");
        for(i = 0; i < SIZE - 1; i++) {
            printf("%d, ", arrayBinarySearchTree[i].y);
        }
        printf("%d)\n", arrayBinarySearchTree[i].y);
        printf("plot(x, y)\n\n");
        printf("dev.off()\n");

        printf("\nAVLTree array - R Code:\n\n");
        printf("png(\"AVLTreePlot.png\")\n\n");
        printf("x = c(");
        for(i = 0; i < SIZE - 1; i++) {
            printf("%d, ", arrayAVLTree[i].x);
        }
        printf("%d)\n", arrayAVLTree[i].x);
        printf("y = c(");
        for(i = 0; i < SIZE - 1; i++) {
            printf("%d, ", arrayAVLTree[i].y);
        }
        printf("%d)\n", arrayAVLTree[i].y);
        printf("plot(x, y)\n\n");
        printf("dev.off()");
    } else {
        printf("Thanks for using\n");
    }

    return 0;
}
