#ifndef HASH_DECLARATIONS_H_
#define HASH_DECLARATIONS_H_

typedef struct hashtable Hashtable;
typedef struct element Element;
int hashCode(unsigned char character);
Hashtable* createHashtable();
void put(Hashtable *ht, unsigned char character);
Element* getHashElement(Hashtable *ht, unsigned char character);
void printHashtable(Hashtable *ht);

#endif // HASH_DECLARATIONS_H_
