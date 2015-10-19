#ifndef HASH_DECLARATIONS_H_
#define HASH_DECLARATIONS_H_

typedef struct hashtable Hashtable;
typedef struct element Element;
Hashtable* createHashtable();
int hashCode(unsigned char character);
void put(Hashtable *ht, unsigned char character, unsigned char* char_huff);
Element* getHashElement(Hashtable *ht, unsigned char character);
void printHashtable(Hashtable *ht);

#endif // HASH_DECLARATIONS_H_
