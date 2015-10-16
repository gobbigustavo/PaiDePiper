#ifndef HASH_DECLARATIONS_H_
#define HASH_DECLARATIONS_H_

typedef struct hashtable Hashtable;
typedef struct element Element;
Hashtable* createHashtable();
void put(Hashtable *ht, int key, int value);
int get(Hashtable *ht, int key);
void printHashtable(Hashtable *ht);

#endif // HASH_DECLARATIONS_H_
