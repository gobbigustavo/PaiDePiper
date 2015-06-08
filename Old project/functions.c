#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "PriorityQueue-BinaryTree.c"
#include "Hash-Stack.c"
#include "Queue.c"

//converts a inverted array of '1' and '0' into a integer
int convertBtoD(char *array){
    int i, result = 0;
    Stack *stk = createStack();
    for(i = 0; array[i] != '\0'; i++){
        stk = push((int)array[i] - 48, stk);
    }
    while(!isEmptyStack(stk)){
        result += pop(stk) * pow((double)2, (double)stk->currentSize);
    }
    free(stk);
    return result;
}

void convertDtoB(int decimal, char *result){
    int b;
    Stack *stk = createStack();
    while(decimal != 0){
        b = decimal % 2;
        stk = push(b, stk);
        decimal = decimal / 2;
    }
    int i = 0;
    while(!isEmptyStack(stk)){
        result[i] = pop(stk) + 48;
        i++;
    }
    result[i] = '\0';
    free(stk);
}

void huffmanDecode(Tree* tree, char* fileString, int i) {
    if(tree != NULL) {
        if(tree->left == NULL && tree->right == NULL) {
            printf("%c", tree->symbol);
            //huffmanDecode(tree, fileString, i++);
        }
    }
    if(fileString[i] == '0') {
        huffmanDecode(tree->left, fileString, i++);
    } else if(fileString[i] == '1') {
        huffmanDecode(tree->right, fileString, i++);
    }
}

void writeHeader(Hash *hash, unsigned char* charactersArray) {
    int i, j, contador;
    FILE *header;
    header = fopen("header.cpdt","w");

    if(!header){
        printf( "CompacData can't open this file :(");
        main();
    }

    for(i = 0; i < strlen(charactersArray); i++) {
        fprintf(header, "%s,", specialGet(hash, charactersArray[i]));
    }

    fclose(header);
}

void writeCompressed(Hash* hash, unsigned char* fileString) {
    int i, j = 0;
    char* huffmanCode = (char*) malloc(sizeof(char) * 20);
    huffmanCode = "";
    for(i = 0; fileString[i] != '\0'; i++) {
        Node* pointer = get(hash, fileString[i]);
        Node* pointerAux;
        for(pointerAux = pointer; pointerAux != NULL; pointerAux = pointerAux->nextNode) {
            j++;
        }
        char huffmanCodeAux[j];
        j = 0;
        for(pointerAux = pointer; pointerAux != NULL; pointerAux = pointerAux->nextNode) {
            huffmanCodeAux[j] = pointerAux->symbol;
            j++;
        }
        huffmanCodeAux[j] = '\0';
        //sprintf(huffmanCode, "%s%s", huffmanCode, huffmanCodeAux);
        //strcat(huffmanCode, huffmanCodeAux);
    }
    printf("%s", huffmanCode);
}

void fillTree(Tree *tree, char symbol, int priority, Node* first, Hash* hash) {
    if(tree != NULL) {
        if(tree->left == NULL && tree->right == NULL && tree->symbol == symbol) {
            put(hash, symbol, priority, first);
            return;
        }
        fillTree(tree->left, symbol, priority, insertNodeFillTree('0', first), hash);
        fillTree(tree->right, symbol, priority, insertNodeFillTree('1', first), hash);
    }
}

Tree* buildTree(PriorityQueue* queue) {
    while(queue->currentSize > 1) {
        Tree* treeFirst = dequeue(queue);
        Tree* treeSecond = dequeue(queue);
        Tree* newTree = createInternalNode(treeFirst, treeSecond);
        queue = enqueueInternalNode(queue, newTree);
    }
    return queue->first;
}

// FUCNTION COMPRESS
// COMPRESS A FILE
int compress(Tree* tree, unsigned char* charactersArray, int* prioritiesArray, unsigned char* fileString) {
    Hash* hash = createHash();
    int i, j = 0;
    for(i = 0; i < strlen(charactersArray); i++) {
        fillTree(tree, charactersArray[i], prioritiesArray[i], NULL, hash);
    }
    writeHeader(hash, charactersArray);

    huffmanDecode(tree, "1000110101", 0);

    writeCompressed(hash, fileString);

    free(hash);
    free(fileString);
    free(tree);
    getchar();
    main();
}

// FUNCTION DECOMPRESS
// DECOMPRESS A FILE
void decompress(char* fileName){
    char *nameFile = (char*) malloc(sizeof(char));
    //sprintf(nameFile, "%s%s", fileName,".cpdt");

    FILE *file;
    FILE *header;
    FILE *output;

    //file = fopen(nameFile,"r");
    header = fopen("header.cpdt","r");
    output = fopen("output.txt","w");

    PriorityQueue* queue = createPriorityQueue();
    char priority[10];
    char caracter;
    char c;
    int aux = 0,i;
    char* a[10];

    while(c=fgetc(header) != EOF){
        if(c != ',' && aux < 1){
            aux = 1;
            caracter = c;
            printf("o caracter é: %c", caracter);
        } else {
            if(c != ','){
                priority[i] = c;
                i++;
            } else {
                memcpy(a, priority, '\0');
                //a[x] = '\0';
                int p = atoi(a);
                enqueue(queue,caracter,p);
                aux = 0;
                memset(a, 0, 10);
                i=0;
                caracter = '\0';
            }
        }
    }

    printf("passou");
    Tree* tree = buildTree(queue);

    fclose(file);
    fclose(header);
    fclose(output);
    free(nameFile);
    free(fileName);
    free(queue);
    free(tree);
}

int countCharCompress(unsigned char symbol, unsigned char* fileString) {
    int i, count = 0;
    for(i = 0; fileString[i] != '\0'; i++) {
        if(fileString[i] == symbol) {
            count++;
        }
    }
    return count;
}

void initCount(unsigned char* fileString) {
    PriorityQueue* queue = createPriorityQueue();
    unsigned char charactersArray[256];
    int prioritiesArray[256];
    int i, j = 0, num = 0;
    for(i = 0; i < 256; i++) {
        if(countCharCompress(i, fileString) > 0) {
            enqueue(queue, i, countCharCompress(i, fileString));
            prioritiesArray[j] = countCharCompress(i, fileString);
            charactersArray[j] = i;
            j++;
        }
    }
    charactersArray[j] = '\0';
    Tree* tree = buildTree(queue);
    free(queue);
    compress(tree, charactersArray, prioritiesArray, fileString);
}

void initFile(char* option, char* fileName, FILE* file) {
    if(file == NULL) {
        printf("CompacData can't open this file :(\n");
        main();
    } else {
        fseek(file, 0, SEEK_END);
        long fileSize = ftell(file);
        fseek(file, 0, SEEK_SET);
        char* fileString = malloc(fileSize + 1);
        fread(fileString, fileSize, 1, file);
        fclose(file);
        fileString[fileSize] = 0;

        if((strcmp (option, "1") == 0)){
            initCount(fileString);
        } else if ((strcmp (option, "2") == 0)){
            decompress(fileName);
        }
    }
}

void selectFile(char* option) {
    char *fileName = (char*) malloc(sizeof(char));
    printf("\nSelect a file: ");
    scanf("%[^\n]s", fileName);
    FILE *file = fopen(fileName, "r");
    initFile(option, fileName, file);
    free(fileName);
    free(file);
}

void yourOption(){
    char option[100];

    printf("\n\nYour option: ");
    scanf("%[^\n]s", option);
    getchar();

    if ((strcmp (option, "1") == 0) || (strcmp (option, "2") == 0) || (strcmp (option, "3") == 0)) {
        if((strcmp (option, "1") == 0)) {
            selectFile(option);
        } else if((strcmp (option, "2") == 0)) {
            selectFile(option);
        }
        if((strcmp (option, "3") == 0)){
            printf("Thanks for using CompacData!\n");
            exit(1);
        }
    }

    else {
        printf("\nInvalid option!\n");
        yourOption();
    }
}
