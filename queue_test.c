#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "functions.c"
#include "tree.c"
main()
{
    char file_address[] = "teste_big.txt";
    FILE* fileout = fopen("fileout.txt", "wb");
    PriorityQueue* pq = createPriorityQueue();
    fprintf(fileout, ExtractFile(file_address));
    pq = StringtoQueue(ExtractFile(file_address));
    printf("Priority Queue:\n\n");
    printPriorityQueue(pq);
    printf("\n");
    printf("Huffman Tree:\n\n");
    Tree* t = createTree(pq);
    printTreePreOrder(t->first);
    printf("\n");
    ///printf("New representation of 'A': %d", getHuffChar(t->first, 'A'));
}
