#ifndef FUNCTIONS_DECLARATIONS_H_
#define FUNCTIONS_DECLARATIONS_H_

unsigned char* alloc_char_array(int n);
unsigned char *ExtractFile(FILE* file);
void copyString(unsigned char array[], unsigned char* tree, unsigned char* compressedArray, unsigned int treeSize);


#endif
