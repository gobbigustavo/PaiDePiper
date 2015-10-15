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
    printPriorityQueue(pq);
    Tree* t = createTree(pq);
    printTreePreOrder(t->first);
}
