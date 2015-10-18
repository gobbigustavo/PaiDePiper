#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.c"

#define MAX_SIZE 8

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

typedef struct Node{
    char caracter;
    int code[MAX_SIZE];
    int code_size; ///quantidade de bits preenchidos no arquivo pós árvore
}Node;

typedef struct Hash{ //-------- colocar hash do marcão
    Node* text[text_size];
}Hash;

char getCode(char byte) {
    /// pegar o código do byte na hash
    return ' ';
}

int createQueue(){
return 0;
}

struct Queue{
};
typedef struct Queue Queue;

struct Tree{
    int visited;
    unsigned char item;
    struct Tree *leftNode;
    struct Tree *rightNode;
    struct Tree *parent;
};
typedef struct Tree Tree;

/*Tree *HuffTree(char caracter){
    int code_array;
    return code_array;
}*/


long int codeSize(FILE* uncompressedFile){
   FILE *file = fopen(uncompressedFile, "r");
   fseek(file, 0, SEEK_END);
   long int fileSize = ftell(file);
   return fileSize;
}


///--------------------------------------------------ENCODE----------------------------------------------------------------------//

///o arquivo do texto tem q ser colocado numa string text com cada caractere em uma posição
    int encode(FILE* uncompressedFile){
    	long int fileSize = codeSize(uncompressedFile);
        unsigned char uncompressed_text[fileSize];
        strcpy(uncompressed_text, ExtractFile(uncompressedFile));

        Hash* codeEntry;

        Queue *toCompressQueue = createQueue; ///fila composta de todos os bits pós compressão

        unsigned char compressed_byte = 0;
        int compressed_byte_length = 0;
        int compressed_text_length = 0;
        int uncompressed_text_index;
        int trash_size = 0;
        int code_index;

        for(uncompressed_text_index = 0; uncompressed_text_index < sizeof(uncompressed_text); uncompressed_text_index++) {
            unsigned char uncompressed_byte = uncompressed_text[uncompressed_text_index];
            Node* codeEntry = getCode(uncompressed_byte); //----------------------fazer função getCode q retorna o nó

            for(code_index = 0; code_index < codeEntry->code_size; code_index++) {
                if(codeEntry->code[code_index] == 1) {
                    compressed_byte = (compressed_byte << 1) | 1;
                }
                else{
                    compressed_byte = (compressed_byte << 1);
                }
                compressed_byte_length++;
                compressed_text_length++;
                if(compressed_byte_length == 8) {
                    addToQueue(toCompressQueue, compressed_byte);
                    compressed_byte_length = 0;
                }
            }
        }


        if(compressed_byte_length != 0) {
            trash_size = 8 - compressed_byte_length;
            compressed_byte = compressed_byte << trash_size;
            addToQueue(toCompressQueue, compressed_byte);
        }
    return 0;
    }

    void createHeader(int trash_size, unsigned int treeSizeEncode){
        unsigned char byte1, byte2, aux;
        byte1 = trash_size << 5;
        aux = treeSizeEncode >>8;
        byte1 = byte1 | aux;
        treeSizeEncode = treeSizeEncode & 255;
        byte2 = (unsigned char) treeSizeEncode;
        ///------------- sobrescrever --------------///
    }

///--------------------------------------------------ENCODE----------------------------------------------------------------------//



///--------------------------------------------------DECODE----------------------------------------------------------------------//

struct HeaderFiles{
    int trash;
    long int fileSize;
    //long int bitFileSize;
    unsigned char tree;
    unsigned int treeSize;
};
typedef struct HeaderFiles HeaderFiles;


	void addToQueue(Queue *toDecompressQueue, unsigned char item){

	}




     void getCodeSize(FILE* compressedFile, HeaderFiles* HeaderFiles){
        FILE *file = fopen(compressedFile, "r");
        fseek(file, 0, SEEK_END);
        long int fileSize = ftell(file);
        fileSize = (fileSize - HeaderFiles->treeSize) - 2; ///take the 2 header bytes and the tree size
        HeaderFiles->fileSize = fileSize;
    }

    /*void getCodeBitSize(HeaderFiles *HeaderFiles){
        long int bitFileSize = (HeaderFiles->fileSize - HeaderFiles->trash) * 8; ///quantidade de bits do arquivo sem o lixo
        HeaderFiles->bitFileSize = bitFileSize;
    }*/

//------ READHEADER ---------//

    unsigned int getTrash(unsigned char byte1){
        unsigned int trash;
        trash = (int) byte1 >> 5;
        return trash;
    }

    unsigned int getTreeSize(unsigned char byte1, unsigned char byte2){
        unsigned int treeSize = byte1  & 31; ///set the first 3 bits 0
        treeSize = treeSize << 8; ///coloca os bits já existentes 8 casas pra esquerda pois eles são o começo do tamanho e o fim é o byte 2
        treeSize = treeSize | (unsigned int) byte2; ///coloca o byte 2 no fim do treeSize, juntando assim os bits do tamanho completo da arvore
        return treeSize;
    }


    void readHeader(FILE *compressedFile, HeaderFiles* HeaderFiles){
        FILE *file = fopen(compressedFile, "r");
        unsigned char byte1;
        unsigned char byte2;
        unsigned int treeSize;
        fread(&byte1, 1, 1, compressedFile);
        fread(&byte2, 1, 1, compressedFile);

        int trash = getTrash(byte1);
        treeSize = getTreeSize(byte1, byte2);

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


//------END OF READHEADER ---------//

    void rebuildTree(HeaderFiles* HeaderFiles, unsigned char tree[]){
        int rt_index;
        Tree* rebuiltTree = malloc(sizeof(Tree));
        Tree* aux;

        for(rt_index = 0; rt_index < HeaderFiles->treeSize; rt_index++){

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
                        rebuiltTree->parent = aux;
                    }
                   else if((rebuiltTree->leftNode != NULL)&&(rebuiltTree->rightNode == NULL)){
                       aux = rebuiltTree;
                       rebuiltTree = rebuiltTree->rightNode;
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
                    rebuiltTree->parent = aux;
                }
                else if ((rebuiltTree->leftNode != NULL)&&(rebuiltTree->rightNode == NULL)){
                    rebuiltTree = rebuiltTree->rightNode;
                    rebuiltTree->item = tree[rt_index];
                    rebuiltTree->visited = 1;
                    rebuiltTree->parent = aux;
                }
                aux = rebuiltTree->parent->parent;
                rebuiltTree = rebuiltTree->parent;
                rebuiltTree->parent = aux;
                if((rebuiltTree->leftNode != NULL)&&(rebuiltTree->rightNode != NULL)){
                    aux = rebuiltTree->parent->parent;
                    rebuiltTree = rebuiltTree->parent;
                    rebuiltTree->parent = aux;
                }

            }
        }
    }





    void putBitOnTree(Tree* rebuiltTree, unsigned char current_bit){
    	Queue *toDecompressQueue = createQueue;
    	Tree* root = rebuiltTree;
        if(current_bit == '0'){
            rebuiltTree = rebuiltTree->leftNode;
        }
        else if(current_bit == '1'){
            rebuiltTree = rebuiltTree->rightNode;
        }

        if((rebuiltTree->leftNode != NULL) && (rebuiltTree->rightNode != NULL)){ ///leaf case
        	addToQueue(toDecompressQueue, rebuiltTree->item);
            rebuiltTree = root;
        }
    }


   void bitThroughTree(Tree* rebuiltTree, FILE* compressedFile, HeaderFiles* HeaderFiles){
        int index, bit_index;
        unsigned char bytes [HeaderFiles->fileSize];
        unsigned char current_bit;

        for(index = 0; index < HeaderFiles->fileSize; index++){
            fread(&bytes[index], 1, 1, compressedFile); ///li 1 byte
            if(index != (HeaderFiles->fileSize - 1)){ ///se não é o último byte
                for(bit_index = 7; bit_index >= 0; bit_index --){
                    current_bit = bytes[index] >> bit_index;
                    current_bit = current_bit & 1;
                    putBitOnTree(rebuiltTree, current_bit);
                }
            }
            else{///se for o ultimo byte subtrai o lixo
                for(bit_index = 7; bit_index > (7 - HeaderFiles->trash); bit_index--){
                    current_bit = bytes[index] >> bit_index;
                    current_bit = current_bit & 1;
                    putBitOnTree(rebuiltTree, current_bit);

                }
            }
        }
    }


    void writeDecompressedFile(Queue* toDecompressQueue){
        FILE * dFile;
        dFile = fopen ("decompressed","w");
        if (dFile != NULL){
            printOnFile(toDecompressQueue, dFile);
            fclose (dFile);
        }
    }



int decode(FILE *compressedFile){
    fopen(compressedFile, "r"); ///descobrir se precisa de alguma outra função pra ler o arquivo
    void readHeader(FILE* compressedFile, HeaderFiles* HeaderFiles);
    void getCodeSize(FILE* compressedFile, HeaderFiles* HeaderFiles);
    void rebuildTree(HeaderFiles *HeaderFiles, unsigned char tree[]);
    void bitThroughTree(Tree* rebuiltTree, FILE* compressedFile, HeaderFiles* HeaderFiles);
    void writeDecompressedFile(Queue* decompressedQueue);

    return 0;
}





    ///-----------------------createEmptyHeader ---------------------------------------//




     ///            FILETREETOARRAY







/*      todos os bits
            11010101 >> 7      00000001   &1    00000001 -> 1
            11010101 >> 6      00000011   &1    00000001 -> 1
            11010101 >> 5      00000110   &1    00000000 -> 0
            11010101 >> 4      00001101   &1    00000001 -> 1
            11010101 >> 3      00011010   &1    00000000 -> 0
            11010101 >> 2      00110101   &1    00000001 -> 1
            11010101 >> 1      01101010   &1    00000000 -> 0
            11010101 >> 0      11010101   &1    00000001 -> 1
        ultimo bit

            00000011 >> 2 00000000  &1  00000000
            00000011 >> 1 00000001  &1  00000001
            00000011 >> 0 00000011  &1  00000001



*/


///--------------------------------------------------DECODE----------------------------------------------------------------------///

