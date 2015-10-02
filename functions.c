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
    char searched_chars[500];
    ///searched_chars = alloc_char_array(strlen(string));

    PriorityQueue* pq = createPriorityQueue();

    for(count = 0; count<strlen(string); count++){
        printf("letter: %c\n", string[count]);
        if (strchr(searched_chars, string[count]) == NULL){
            occours = strchr(string, string[count]);
            while(occours != NULL){
                frequency++;
                occours = strchr(occours+1, string[count]);
            }
            searched_chars[count] = string[count];
            printf("Frequency: %d\n", frequency);
            enqueue(pq, string[count], frequency);
            frequency = 0;
            printf("\n");
            }
    }
    ///free(searched_chars);
    printPriorityQueue(pq);
    freePriorityQueue(pq);
}

char *ExtractFile(char file_address[])
{
    FILE *file = fopen(file_address,"r");
    fseek(file, 0L, SEEK_END);
    int length = ftell(file);
    fseek(file, 0L, SEEK_SET);
    char *string = (char*) malloc(sizeof (char) * length + 1);
    int count;
    for(count = 0;count < length; count++){
        string[count] = fgetc(file);
    }
    string[length] = '\0';
    return string;
}

/* EXAMPLE OF USAGE
int main()
{
    char *string = ExtractFile("teste.txt");
    printf("%s",string);
}
*/
