#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tree.c"

int main(){
    int action_choice;
    char file_address[20];
    FILE* file;
    PriorityQueue* pq;
    Tree* t;
    Hashtable* hash;
    Element* node;

    printf("##################################\n");
    printf("#          PaiDePiper(TM)        #\n");
    printf("#                                #\n");
    printf("#    Insert the file address:    #\n");
    printf("##################################\n");

    gets(file_address);
    file = fopen(file_address, "rb");

    printf("\n#  Press 1 for COMPRESSION or 2 for DECOMPRESSION  #\n");
    scanf("%d", &action_choice);

    switch(action_choice){
    case 1:
        pq = createPriorityQueue();
        pq = StringtoQueue(ExtractFile(file));
        printf("Priority Queue:\n\n");
        printPriorityQueue(pq);
        printf("\n");
        printf("Huffman Tree:\n\n");
        t = createTree(pq);
        printTreePreOrder(t->first);
        hash = treeSearch(t->first);
        node = getHashElement(hash, 'A');
        ///printf("New representation of '%c': ", node->character);
        ///puts(node->char_huff);
        freePriorityQueue(pq);
        t->first = NULL;
        printf("\n");
        break;
        ///encode(file);
    case 2:
        break;
        ///decode(file);
    }

return 0;
}
