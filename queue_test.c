#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "functions.c"

main()
{
    char string[] = "teste3.txt";

    StringtoQueue(ExtractFile(string));
}
