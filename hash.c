#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_declarations.h"

const int hashSize = 256;

struct element{
    int key;
    unsigned char character;
    unsigned char* char_huff;
    int char_huff_size;
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

void put(Hashtable *ht, unsigned char* key, unsigned char character, unsigned char* char_huff){
    int h = hashCode(key);
    while (ht->table[h] != NULL){
        if (ht->table[h]->key == h){
            ht->table[h]->character = character;
            ht->table[h]->char_huff = char_huff;
            break;
        }
        h = (h + 1) % hashSize;
    }
    if(ht->table[h] == NULL){
        Element *newElement = (Element*) malloc(sizeof(Element));
        newElement->key = h;
        newElement->character = character;
        newElement->char_huff = char_huff;
        ht->table[h] = newElement;
    }
}

Element* getHashElement(Hashtable *ht, unsigned char* key){
    int h = hashCode(key);
    while(ht->table[h] != NULL){
        if (ht->table[h]->key == h){
            return ht->table[h];
        }
        h = (h + 1) % hashSize;
    return NULL;
    }
}

int main(int argc, char const *argv[]){
  unsigned char *string = "A";
  Hashtable* hash = createHashtable();
  put(hash, "a", 'a', "1101");

  Element* node = getHashElement(hash, "a");

  puts(node->char_huff);

  return 0;
}

