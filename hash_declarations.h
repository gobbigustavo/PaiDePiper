#ifndef HASH_DECLARATIONS_H_
#define HASH_DECLARATIONS_H_



typedef  struct element{
    int key;
    unsigned char character;
    unsigned char* char_huff;
    int char_huff_size;
}Element;

typedef struct hashtable{
    Element *table[256];
}Hashtable;

int hashCode(unsigned char *string);
Hashtable* createHashtable();
void put(Hashtable *ht, unsigned char* key, unsigned char character, unsigned char* char_huff);
Element* getHashElement(Hashtable *ht, unsigned char* key);
void printHashtable(Hashtable *ht);

#endif // HASH_DECLARATIONS_H_
