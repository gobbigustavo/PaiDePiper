#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "functions.c"

main()
{
    char string[] = "teste2.txt";

    StringtoQueue(ExtractFile(string));
}
