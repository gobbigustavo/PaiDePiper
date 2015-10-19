#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions_declarations.h"
#include "hash_declarations.h"
#include "queue_declarations.h"

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


long int codeSize(FILE* uncompressedFile){
   FILE *file = fopen("uncompressedFile", "r");
   fseek(file, 0, SEEK_END);
   long int fileSize = ftell(file);
   return fileSize;
}


///--------------------------------------------------ENCODE----------------------------------------------------------------------//

///o arquivo do texto tem q ser colocado numa string text com cada caractere em uma posição
    int encode(FILE* uncompressedFile){
    	long int fileSize = codeSize(uncompressedFile);
        unsigned char *uncompressed_text = malloc(fileSize * sizeof(unsigned char));
        uncompressed_text = ExtractFile(uncompressedFile);
        Hashtable* hash; //hash pós arvore
        Element* codeEntry = malloc(sizeof(Element));

        Queue *toCompressQueue = createQueue(); ///fila composta de todos os bits pós compressão

        unsigned char *uncompressed_byte;
        unsigned char compressed_byte = 0;
        int compressed_byte_length = 0;
        int compressed_text_length = 0;
        int uncompressed_text_index;
        int trash_size = 0;
        int code_index;

        for(uncompressed_text_index = 0; uncompressed_text_index < sizeof(uncompressed_text); uncompressed_text_index++) {
            uncompressed_byte = &uncompressed_text[uncompressed_text_index];
            codeEntry = getHashElement(hash, uncompressed_byte); //hash

            for(code_index = 0; code_index < codeEntry->char_huff_size; code_index++) {
                if(codeEntry->char_huff[code_index] == 1) {
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

