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
    printf("Priority Queue:\n\n");
    printPriorityQueue(pq);
    printf("\n");
    printf("Huffman Tree:\n\n");
    Tree* t = createTree(pq);
    printTreePreOrder(t->first);
    printf("\n");
    printf("New representation of 'A': %d", getHuffChar(t->first, 'A'));
}
