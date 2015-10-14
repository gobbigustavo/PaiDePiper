#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions_declarations.h"

char *ExtractFile(char file_address[]){
    FILE *fileptr;
    unsigned char *buffer;
    long filelen;

    fileptr = fopen(file_address, "rb");  // Open the file in binary mode
    fseek(fileptr, 0, SEEK_END);          // Jump to the end of the file
    filelen = ftell(fileptr);             // Get the current byte offset in the file
    rewind(fileptr);                      // Jump back to the beginning of the file

    buffer = (unsigned char *)malloc((filelen+1)*sizeof(unsigned char)); // Enough memory for file + \0
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
