#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.c"
#include "Queue.c"

#define MAX_SIZE 8


///--------------------------------------------------DECODE----------------------------------------------------------------------//
struct Tree{
    int visited;
    unsigned char item;
    struct Tree *leftNode;
    struct Tree *rightNode;
    struct Tree *parent;
};
typedef struct Tree Tree;


struct HeaderFiles{
    int trash;
    long int fileSize;
    //long int bitFileSize;
    unsigned char tree;
    unsigned int treeSize;
};
typedef struct HeaderFiles HeaderFiles;


//fazer

    void printOnFile(Queue* queue, FILE* newFile){

    }



     void getCodeSize(FILE* compressedFile, HeaderFiles* HeaderFiles){
        FILE *file = fopen("compressedFile", "r");
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
        FILE *file = fopen("compressedFile", "r");
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
    	Queue *toDecompressQueue = createQueue();
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
        unsigned char *bytes = malloc(HeaderFiles->fileSize * sizeof(unsigned char));
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
    fopen("compressedFile", "r"); ///descobrir se precisa de alguma outra função pra ler o arquivo
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

