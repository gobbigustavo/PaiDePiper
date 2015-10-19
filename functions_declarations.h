#ifndef FUNCTIONS_DECLARATIONS_H_
#define FUNCTIONS_DECLARATIONS_H_

FILE* createFileFromAddress(char file_address[]);
unsigned char* alloc_char_array(int n);
unsigned char *ExtractFile(FILE* fileptr);
void copyString(unsigned char array[], unsigned char* tree, unsigned char* compressedArray, unsigned int treeSize);


#endif
