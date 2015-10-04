#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions_declarations.h"
#include "priorityqueue.c"

char* alloc_char_array(int n){
    char* array = (char*)calloc(n, sizeof(char));
    if(array == NULL){
        puts("Erro aloc. vetor");
        exit(0);
    }
    return array;
}

PriorityQueue* StringtoQueue(char string[]){
    int count;
    char ascii[256] = {0};
    PriorityQueue* pq = createPriorityQueue();

    for(count = 0; count<strlen(string); count++){
        ascii[(int)string[count]] = ascii[(int)string[count]] + 1;
    }

    for(count = 0; count<256; count++){
        if(ascii[count]>=1){
            enqueue(pq, count, ascii[count]);
        }
    }
    return pq;
}

char *ExtractFile(char file_address[]){
    FILE *fileptr;
    char *buffer;
    long filelen;

    fileptr = fopen(file_address, "rb");  // Open the file in binary mode
    fseek(fileptr, 0, SEEK_END);          // Jump to the end of the file
    filelen = ftell(fileptr);             // Get the current byte offset in the file
    rewind(fileptr);                      // Jump back to the beginning of the file

    buffer = (char *)malloc((filelen+1)*sizeof(char)); // Enough memory for file + \0
    fread(buffer, filelen, 1, fileptr); // Read in the entire file
    fclose(fileptr); // Close the file
    return buffer;
}

/* EXAMPLE OF USAGE
int main()
{
    char *string = ExtractFile("teste.txt");
    printf("%s",string);
}
*/
