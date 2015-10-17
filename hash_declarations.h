#ifndef HASH_DECLARATIONS_H_
#define HASH_DECLARATIONS_H_

typedef struct hashtable Hashtable;
typedef struct element Element;
Hashtable* createHashtable();
void put(Hashtable *ht, unsigned char* key, unsigned char character, unsigned int char_huff);
int get(Hashtable *ht, unsigned char* key);
void printHashtable(Hashtable *ht);

#endif // HASH_DECLARATIONS_H_
