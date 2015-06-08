#include <stdio.h>
#include <stdlib.h>
#include "List.c"
#define MAX_SIZE 256

/** -------------------------------------------------------  **/
/**                      STACK  ADTS                         **/
/** -------------------------------------------------------  **/

struct stack {
    int currentSize;
    int itens[MAX_SIZE];
    char characters[MAX_SIZE];
} typedef Stack;

Stack * createStack(){
    Stack* stk = (Stack*)malloc(sizeof(Stack));
    stk->currentSize = 0;
    return stk;
}

Stack* push(int item, Stack* stk){
    if(stk->currentSize >= MAX_SIZE){
        printf("Stack OverFlow!");
        return NULL;
    } else {
        stk->itens[stk->currentSize++] = item;
    }
    return stk;
}

int isEmptyStack(Stack* stk){
    return stk->currentSize == 0;
}

int peek(Stack* stk){
    if(!isEmptyStack(stk)){
        return stk->itens[stk->currentSize-1];
    } else {
        return -1;
    }
}

int pop(Stack* stk){
    if(!isEmptyStack(stk)){
        return stk->itens[--stk->currentSize];
    } else {
        return -1;
    }
}

/** ------------------------------------------------------- **/
/**                    HASH ADTS                            **/
/** ------------------------------------------------------- **/


struct element {
    char character;
    int priority;
    Node* first;
};

typedef struct element Element;

struct hash {
    Element *table[MAX_SIZE];
};

typedef struct hash Hash;

Hash *createHash() {
    Hash *hash = (Hash*) malloc(sizeof(Hash));
    int i;
    for(i = 0; i < MAX_SIZE; i++) {
        hash->table[i] = NULL;
    }
    return hash;
}

int hashFunction(char keyCharacter) {
    int keySymbolInt = keyCharacter;
    return keySymbolInt % MAX_SIZE;
}

void put(Hash *hash, char keyCharacter, int priority, Node* first) {
    int hashFunctionNumber = hashFunction(keyCharacter);
    Element *newElement = (Element*) malloc(sizeof(Element));
    newElement->character = keyCharacter;
    newElement->priority = priority;
    newElement->first = first;
    hash->table[hashFunctionNumber] = newElement;
}

char* specialGet(Hash *hash, char keyCharacter) {
    char *retorno = (char*) malloc(sizeof(char));
    int h = hashFunction(keyCharacter);
    if(hash->table[h]->character == keyCharacter) {
        sprintf(retorno, "%c%d", hash->table[h]->character,hash->table[h]->priority);
        return retorno;
    } else {
       return NULL;
    }
}

Node* get(Hash *hash, char keyCharacter) {
    int h = hashFunction(keyCharacter);
    if(hash->table[h]->character == keyCharacter) {
        return hash->table[h]->first;
    } else {
       return NULL;
    }
}
