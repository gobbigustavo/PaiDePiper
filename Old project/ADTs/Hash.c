#include <stdio.h>
#include <stdlib.h>
// 256 = QUANTIDADE MÁXIMA DE CARACTERES ASCII
#define MAX_SIZE 256

// HASH TABLE ADT FOR HUFFMAN CODING
// STRUCT ELEMENT
// REPRESENTS AN ELEMENT WITH A KEY(CHAR) AND A PRIORITY(INT) IN THE HASH TABLE
struct element {
    char keySymbol;
    int priority;
};

typedef struct element Element;

// STRUCT HASH
// REPRESENTS THE ENTIRE HASH TABLE WITH AN ARRAY OF ELEMENTS
struct hash {
    Element *table[MAX_SIZE];
};

typedef struct hash Hash;

// FUNCTION CREATEHASH
// CREATES A HASH TABLE SETING ALL THE POINTER TO NULL
// RETURNS THE INITIALIZED HASH TABLE
Hash *createHash() {
    Hash *hash = (Hash*) malloc(sizeof(Hash));
    int i;
    for(i = 0; i < MAX_SIZE; i++) {
        hash->table[i] = NULL;
    }
    return hash;
}

// FUNCTION HASHFUCNTION
// SET THE POSITION OF A ELEMENT IN THE HASH TABLE
// RETURNS THE POSITION, A INTEGER
int hashFunction(char keySymbol) {
    int keySymbolInt = keySymbol;
    return keySymbolInt % MAX_SIZE;
}

// FUNCTION PUT
// PUT A ELEMENT IN THE CORRECT AND UNIQUE POSITION IN THE HASH TABLE
void put(Hash *hash, char keySymbol, int priority) {
    int hashFunctionNumber = hashFunction(keySymbol);
    Element *newElement = (Element*) malloc(sizeof(Element));
    newElement->keySymbol = keySymbol;
    newElement->priority = priority;
    hash->table[hashFunctionNumber] = newElement;
}

// FUNCTION GET
// GET A ELEMENT IN THE CORRECT AND UNIQUE POSITION IN THE HASH TABLE
// RETURNS THE KEY(CHAR) OF THE ELEMENT
char get(Hash *hash, char keySymbol) {
    int hashFunctionNumber = hashFunction(keySymbol);
    if(hash->table[hashFunctionNumber]->keySymbol == keySymbol) {
        return hash->table[hashFunctionNumber]->keySymbol;
    } else {
       return '%';
    }
}

// FUNCTION PRINTHASH
// WALK ALL OVER THE HASH TABLE PRINTING THE NON-NULL ELEMENTS
void printHash(Hash *hash) {
    int i;
    for(i = 0; i < MAX_SIZE; i++) {
        if(hash->table[i] != NULL) {
            printf("%d - %c", hash->table[i]->priority, hash->table[i]->keySymbol);
        }
    }
}
