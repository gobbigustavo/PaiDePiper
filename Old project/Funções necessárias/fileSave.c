#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 256

/** -------------------------------------------------------  **/
/**                      STACK  ADTS                         **/
/** -------------------------------------------------------  **/

struct stack {
    int currentSize;
    int itens[MAX_SIZE];
} typedef Stack;

Stack * createStack(){
    Stack* stk = (Stack*)malloc(sizeof(Stack));
    stk->currentSize = 0;
    return stk;
}

Stack * push(int item, Stack * stk){
    if(stk->currentSize >= MAX_SIZE){
        printf("Stack OverFlow!");
        return NULL;
    } else {
        stk->itens[stk->currentSize++] = item;
    }
    return stk;
}

int isEmpty(Stack* stk){
    return stk->currentSize == 0;
}

int peek(Stack* stk){
    if(!isEmpty(stk)){
        return stk->itens[stk->currentSize-1];
    } else {
        return -1;
    }
}

int pop(Stack* stk){
    if(!isEmpty(stk)){
        return stk->itens[--stk->currentSize];
    } else {
        return -1;
    }
}

/** -------------------------------------------------------  **/
/** HASH ADTS **/
/** ------------------------------------------------------- **/


struct element {
    char keyCharacter;
    int value;
    int priority;
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

void put(Hash *hash, char keyCharacter, int value) {
    int hashFunctionNumber = hashFunction(keyCharacter);
    Element *newElement = (Element*) malloc(sizeof(Element));
    newElement->keyCharacter = keyCharacter;
    newElement->value = value;
    newElement->priority = priority;
    hash->table[hashFunctionNumber] = newElement;
}

char* get(Hash *hash, char keyCharacter) {
    char *retorno = (char*) malloc(sizeof(char));
    int h = hashFunction(keyCharacter);
    if(hash->table[h]->keyCharacter == keyCharacter) {
        sprintf(retorno, "%d%c%d", hash->table[h]->priority,hash->table[h]->keyCharacter,hash->table[h]->value);
        return retorno;
    } else {
       return NULL;
    }
}

/** ------------------------------------------------------- **/
/** FUNCTIONS MOTHERFUCKERS**/
/** ------------------------------------------------------- **/

int convertBtoD(char *array){
    int i, result = 0;
    Stack *stk = createStack();
    for(i=0; array[i] != '\0'; i++){
        stk = push((int)array[i]-48, stk);
    }

    while(!isEmpty(stk)){
        result += pop(stk)*pow((double)2, (double)stk->currentSize);
    }
    return result;
}

char convertDtoB(int decimal, char *result){
    int b;
    Stack *stk = createStack();
    while(decimal != 0){
        b = decimal%2;
        stk = push(b, stk);
        decimal = decimal/2;
    }
    int i=0;
    while(!isEmpty(stk)){
        result[i] = pop(stk)+48;
        i++;
    }
    result[i] = '\0';
    return result;
}

void descompress(){

    Hash* hash = createHash();
    FILE *fp;

    fp = fopen("output.dfdfkndkf","r");

    char *conteudo = (char*) malloc(sizeof(char));
    char caracter;
    char priority;
    char binaryHuffman[30];
    int i, j;

    while((fgets(conteudo, 30, fp))!= NULL ){
        for(i = 0; conteudo[i] != '\0'; i++){
            priority = conteudo[1];
            caracter = conteudo[2];
            if(conteudo[i] != '\0' && i >=3){
                binaryHuffman[i-3] = conteudo[i];
            }
        }
        int value = atoi(binaryHuffman);
        int priorityInteger = atoi(binaryHuffman);
        put(hash, caracter, value, priorityInteger);

    }
    //  printf("caralho: %s\n", m(hash,'a'));
      //printf("caralho: %s\n", get(hash,'b'));
    //  printf("caralho: %s\n", get(hash,'c'));

}

void writeFile(Hash *hash, char* code){

    char *output = (char*) malloc(sizeof(char));
    int i;

    FILE *fp;

    fp = fopen("output.dfdfkndkf","w");

    if(!fp){
        printf( "Erro na abertura do arquivo");
        exit(0);
    }

    fprintf(fp, "'%s\n",  get(hash,'a'));

    fprintf(fp, "%s", (char*) code);

    fclose(fp);

}


/** ------------------------------------------------------- **/

int main(){
    Hash* hash = createHash();
    put(hash,'p',10,1);
    put(hash,'a',11,2);
    put(hash,'v',12,1);
    put(hash,'o',13,1);

    writeFile(hash, "101010");

   // descompress();


}
