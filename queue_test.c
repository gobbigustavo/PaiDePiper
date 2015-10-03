#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "functions.c"

main()
{
    char string[] = "teste_big.txt";
    StringtoQueue2(ExtractFile(string));
}
