#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "functions.c"
#include "tree.c"
main()
{
    char string[] = "teste_big.txt";
    PriorityQueue* pq = createPriorityQueue();
    pq = StringtoQueue(ExtractFile(string));
    FILE* file = fopen("testeout.txt", "wb");
    fprintf(file, ExtractFile(string));
    printf("Priority Queue:\n\n");
    printPriorityQueue(pq);
    printf("\n");
    printf("Huffman Tree:\n\n");
    Tree* t = createTree(pq);
    printTreePreOrder(t->first);
    printf("\n");
    Hashtable* hash = treeSearch(t->first);
    ///Element* node = getHashElement(hash, 'A');
    ///printf("New representation of '%c': ", node->character);
    ///puts(node->char_huff);


/*
    char string[]="atirei o pau no gato";
    int treeSize = 6;
    unsigned char* tree;
    unsigned char* compressedArray;

    copyString(string, tree, compressedArray, treeSize);
    puts(string);
    puts(compressedArray);*/
}
