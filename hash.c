#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_declarations.h"

const int hashSize = 256;

struct element{
    int key;
    int value;
};

struct hashtable{
    Element *table[256];
};

Hashtable* createHashtable(){
    Hashtable *ht = malloc(sizeof(Hashtable));
    int i;
    for (i = 0; i < hashSize; i++){
    ht->table[i] = NULL;
    }
    return ht;
}

void put(Hashtable *ht, int key, int value){
    int h = hashCode(key);
    while (ht->table[h] != NULL){
        if (ht->table[h]->key == key){
            ht->table[h]->value = value;
            break;
        }
        h = (h + 1) % hashSize;
    }
    if(ht->table[h] == NULL){
        Element *newElement = (Element*) malloc(sizeof(Element));
        newElement->key = key;
        newElement->value = value;
        ht->table[h] = newElement;
    }
}

int get(Hashtable *ht, int key){
    int h = hashCode(key);
    while(ht->table[h] != NULL){
        if (ht->table[h]->key == key){
            return ht->table[h]->value;
        }
        h = (h + 1) % hashSize;
    return -100;
    }
}

int hashCode(unsigned char *string) {
  int i;
  int hashCode = 0;
  int charCode;

  if (strlen(string) == 0)
    return 0;

  for (i = 0; i < strlen(string); i++) {
    charCode = string[i];
    hashCode = ((hashCode << 5) - hashCode) + charCode;
    hashCode = hashCode & hashCode;
  }
  return hashCode;
}

int main(int argc, char const *argv[]){
  unsigned char *string = "A";
  printf("%d\n", hashCode(string) % hashSize);

  return 0;
}

