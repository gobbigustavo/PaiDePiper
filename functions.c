#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions_declarations.h"

unsigned char* alloc_char_array(int n){
    unsigned char* array = (unsigned char*)calloc(n, sizeof(unsigned char));
    if(array == NULL){
        puts("Erro aloc. vetor");
        exit(0);
    }
    return array;
}

FILE* createFileFromAddress(char file_address[]){
    FILE *file;
    file = fopen(file_address, "rb"); // Open the file in binary mode
    return file;
}

unsigned char *ExtractFile(FILE* fileptr){
    unsigned char *buffer;
    long filelen;

    fseek(fileptr, 0, SEEK_END);          // Jump to the end of the file
    filelen = ftell(fileptr);             // Get the current byte offset in the file
    rewind(fileptr);                      // Jump back to the beginning of the file

    buffer = (unsigned char *)malloc((filelen+1)*sizeof(unsigned char)); // Enough memory for file + \0
    fread(buffer, filelen, 1, fileptr); // Read in the entire file
    fclose(fileptr); // Close the file
    return buffer;
}

void copyString(unsigned char array[], unsigned char* tree, unsigned char* compressedArray, unsigned int treeSize){
    int i;
    int tree_array_size = 1 + treeSize;
    tree = alloc_char_array(tree_array_size);
    int compressed_array_size = (strlen(array)) - tree_array_size;
    compressedArray = alloc_char_array(compressed_array_size);

    for(i = 1; i<=treeSize; i++){
        tree[i-1] = array[i];
    }

    for(i = treeSize+1; i<=strlen(array); i++){
        compressedArray[i] = array[i];
    }

}
/* EXAMPLE OF USAGE
int main()
{

    char* file_address = "teste.txt";
    FILE* file = createFileFromAddress(file_address)
    char* string = ExtractFile(file);
    printf("%s",string);
}*/

