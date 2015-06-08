#include <stdio.h>

int countChar(unsigned char symbol, unsigned char* fileString) {
    int i, count = 0;
    int t = strlen(fileString);
    for(i = 0; fileString[i] != '\0'; i++) {
        if(fileString[i] == symbol) {
            count++;
        }
    }
    return count;
}

void initCount(unsigned char* fileString) {
    int i;
    for(i = 0; i < 256; i++) {
        printf("'%c' -> %d\n", i, countChar(i, fileString));
    }
}
