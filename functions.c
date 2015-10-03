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

void StringtoQueue(char string[]){
    int count;
    int frequency = 0;
    char* occours;
    char searched_chars[256];
    ///searched_chars = alloc_char_array(strlen(string));

    PriorityQueue* pq = createPriorityQueue();

    for(count = 0; count<strlen(string); count++){
        ///printf("letter: %c\n", string[count]);
        if (strchr(searched_chars, string[count]) == NULL){
            searched_chars[count] = string[count];
            occours = strchr(string, string[count]);
            while(occours != NULL){
                frequency++;
                occours = strchr(occours+1, string[count]);
            }
            ///printf("Frequency: %d\n", frequency);
            enqueue(pq, string[count], frequency);
            frequency = 0;
            ///printf("\n");
            }
    }
    ///free(searched_chars);
    printPriorityQueue(pq);
    freePriorityQueue(pq);
}

void StringtoQueue2(char string[]){
    int count;
    int frequency = 0;
    char* occours;
    char ascii[256] = {0};
    ///searched_chars = alloc_char_array(strlen(string));

    PriorityQueue* pq = createPriorityQueue();

    for(count = 0; count<strlen(string); count++){
        ascii[(int)string[count]] = ascii[(int)string[count]] + 1;
    }

    for(count = 0; count<256; count++){
        if(ascii[count]>=1){
            printf("Char: %c, freq: %d\n", count, ascii[count]);
        }
    }
}

char *ExtractFile(char file_address[])
{
    FILE *file = fopen(file_address,"r");
    fseek(file, 0L, SEEK_END);
    int length = ftell(file);
    fseek(file, 0L, SEEK_SET);
    char *string = (char*) malloc(sizeof (char) * length + 1);
    int count;///Count = String size
    for(count = 0;count < length; count++){
        string[count] = fgetc(file);
    }
    string[length] = '\0';
    return string;
}

char *ExtractFile2(char file_address[]){
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
