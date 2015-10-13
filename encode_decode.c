#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"List.c"

#define MAX_SIZE 8

// FUNÇÕES GENERICAS, DEPOIS SERÃO USADAS A MESMA DA ARVORE Q CLARA VAI FAZER
/*
ESTRUTURAS NECESSÁRIAS:
    - HASH
    - LIST
    - TREE

FUNÇÕES NECESSÁRIAS:
    - HuffTree
    - CreateEmptyList
    - AddListNode
*/
///text_size armazenado em uma variavel global logo qd ler o arquivo
int text_size;

struct Node{
    char caracter;
    int char_code[MAX_SIZE];
    int char_code_size; ///quantidade de bits preenchidos no arquivo pós árvore
};
typedef struct Node Node;

struct Hash{
    Node text[text_size];
};

char getCode(char byte) {
    /// pegar o código do byte na hash
    return ' ';
}
typedef struct Hash Hash;

struct Queue{
};
typedef struct Queue Queue;

struct List{
    return 0;
};
typedef struct List List;

List *CreateEmptyList(){
    return;
}

struct Tree {
    int item;
    int visited = 0;
    struct Tree *leftNode;
    struct Tree *rightNode;
    struct Tree *parent;
};
typedef struct Tree Tree;

Tree *HuffTree(char caracter){
    int code_array;
    return code_array;
}

///--------------------------------------------------ENCODE----------------------------------------------------------------------//

///o arquivo do texto tem q ser colocado numa string text com cada caractere em uma posição
encode(char uncompressed_text){

    Hash* codeEntry;

	ListNode *full_text = createList; ///lista composta de todos os array de bits pós compressão

    char compressed_byte = 0;
    int compressed_byte_length = 0;
    int compressed_text_length = 0;
    int uncompressed_text_index;

    for(uncompressed_text_index = 0; uncompressed_text_index < sizeof(uncompressed_text); uncompressed_text_index++) {
        char uncompressed_byte = uncompressed_text[uncompressed_text_index];
        Code codeEntry = getCode(uncompressed_byte); ///fazer função getCode

        for(int code_index = 0; code_index < code_size; code_index++) {
            if(codeEntry->code[code_index] == 1) {
                compressed_byte = (compressed_byte << 1) | 1;
            } else {
                compressed_byte = (compressed_byte << 1);
            }
            compressed_byte_length++;
            compressed_text_length++;
            if(compressed_byte_length == 8) {
                addToList(compressed_byte);
                compressed_byte_length = 0;
            }
        }
    }

    int trash_size = 0;

    if(compressed_byte_length != 0) {
        trash_size = 8 - compressed_byte_length;
        compressed_byte = compressed_byte << trash_size;
        addToList(compressed_byte);
    }
}

    createHeader(int trash_size, unsigned int treeSize){
        unsigned char byte1, byte2, aux;
        byte1 = trash_size << 5;
        aux = treeSize >>8;
        byte1 = byte1 | aux;
        treeSize = treeSize & 255;
        byte2 = (unsigned char) treeSize;
        ///------------- sobrescrever --------------///
    }

///--------------------------------------------------ENCODE----------------------------------------------------------------------//



///--------------------------------------------------DECODE----------------------------------------------------------------------//


    int getCodeSize(File* compressedFile){
        File *file = fopen(compressedFile, "r");
        fseek(file, 0, SEEK_END);
        long int fileSize = ftell(file);
        return fileSize;
    }

    int getCodeBitSize(long int fileSize, int trash){
        long int bitFileSize = (fileSize - trash) * 8; ///quantidade de bits do arquivo sem o lixo
        return bitFileSize;
    }

decode(File *compressedFile){
    fopen(compressedFile); ///descobrir se precisa de alguma outra função pra ler o arquivo
    getCodeSize(File *compressedFile); ///fazer função pra pegar o tamanho
    File *file =


}





//------ READHEADER ---------//
struct HeaderFiles{
    int trash;
    unsigned char tree;
    unsigned int treeSize;
};
typedef struct HeaderFiles HeaderFiles;


    void readHeader(File *compressedFile){
        File *file = fopen(compressedFile, "r")
        unsigned char byte1, byte2;
        unsigned int treeSize;
        fread(&byte1, 1, 1, compressedFile);
        fread(&byte2, 1, 1, compressedFile);

        int trash = getTrash(byte1)
        unsigned int treeSize = getTreeSize(byte1, byte2);

        unsigned char *tree = malloc(treeSize * (sizeof(unsigned char)));

        int tree_index;
        for (tree_index = 0; tree_index < treeSize; tree_index++){
            fread(&tree[tree_index], 1, 1, compressedFile);
        }
        HeaderFiles->tree = malloc(treeSize * (sizeof(unsigned char)));

        HeaderFiles->tree = tree;
        HeaderFiles->trash = trash;
        HeaderFiles->treeSize = treeSize;
    }


    int getTrash(unsigned char byte1){
        int trash;
        trash = (int) byte1 >> 5;
        return trash;
    }

    unsigned int getTreeSize(unsigned char byte1, unsigned char byte2){
        unsigned int treeSize = byte1  & 31; ///set the first 3 bits 0
        treeSize = treeSize << 8; ///coloca os bits já existentes 8 casas pra esquerda pois eles são o começo do tamanho e o fim é o byte 2
        treeSize = treeSize | (unsigned int) byte2; ///coloca o byte 2 no fim do treeSize, juntando assim os bits do tamanho completo da arvore
        return treeSize;
    }

//------END OF READHEADER ---------//



    void rebuildTree(HeaderFiles *treeSize, HeaderFiles *tree){
        int rt_index;

        Tree *rebuiltTree; ///criar nó vazio
        Tree *aux = NULL;

        for(rt_index = 0; rt_index < treeSize; rt_index++){

            if(tree[rt_index] == '*'){
                if(rebuiltTree->visited == 0){ ///Root case
                    rebuiltTree->item = tree[rt_index];
                    rebuiltTree->visited = 1;
                    rebuiltTree->parent = aux;
                    aux = rebuiltTree;
                }
                else{
                    if(rebuiltTree->leftNode == NULL){
                        aux = rebuiltTree;
                        rebuiltTree = rebuiltTree->leftNode;
                        rebuiltTree->item = tree[rt_index];
                        rebuiltTree->visited = 1;
                        rebuitTree->parent = aux;
                    }
                   else if((rebuildTree->leftNode != NULL)&&(rebuiltTree->rightNode == NULL)){
                       aux = rebuiltTree;
                       rebuiltTree = rebuiltTree->rightNode
                       rebuiltTree->item = tree[rt_index];
                       rebuiltTree->visited = 1;
                       rebuiltTree->parent = aux;
                   }
                   else if ((rebuiltTree->leftNode !=NULL) && (rebuiltTree->rightNode !=NULL)){
                        aux = rebuiltTree->parent->parent;
                        rebuiltTree = rebuiltTree->parent;
                        rebuiltTree->parent = aux;

                    }
                }
            }
            else{///leaf case
                aux = rebuiltTree; ///vai até a folha, preenche ela e voltra pra o nó do meio
                if(rebuiltTree->leftNode == NULL){
                    rebuiltTree = rebuiltTree->leftNode;
                    rebuiltTree->item = tree[rt_index];
                    rebuiltTree->visited = 1;
                    rebuitTree->parent = aux;
                }
                else if ((rebuildTree->leftNode != NULL)&&(rebuiltTree->rightNode == NULL)){
                    rebuitTree = rebuitTree->rightNode;
                    rebuiltTree->item = tree[rt_index];
                    rebuiltTree->visited = 1;
                    rebuitTree->parent = aux;
                }
                aux = rebuitTree->parent->parent;
                rebuiltTree = rebuiltTree->parent;
                rebuitTree->parent = aux;
                if((rebuildTree->leftNode != NULL)&&(rebuiltTree->rightNode != NULL)){
                    aux = rebuitTree->parent->parent;
                    rebuiltTree = rebuiltTree->parent;
                    rebuitTree->parent = aux;
                }
            }
        }
    }





///--------------------------------------------------DECODE----------------------------------------------------------------------///

