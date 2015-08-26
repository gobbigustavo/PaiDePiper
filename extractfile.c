#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "extractfile.h"

char *ExtractFile(char file_address[])
{
    FILE *file = fopen(file_address,"r");
    fseek(file, 0L, SEEK_END);
    int length = ftell(file);
    fseek(file, 0L, SEEK_SET);
    char *string = (char*) malloc(sizeof (char) * length + 1);
    int count;
    for(count = 0;count < length; count++)
        string[count] = fgetc(file);
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
