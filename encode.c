#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"List.c"

#define MAX_SIZE 8

// FUN��ES GENERICAS, DEPOIS SER�O USADAS A MESMA DA ARVORE Q CLARA VAI FAZER
/*
ESTRUTURAS NECESS�RIAS:
    - HASH
    - LIST
    - TREE

FUN��ES NECESS�RIAS:
    - HuffTree
    - CreateEmptyList
    - AddListNode
*/
///text_size armazenado em uma variavel global logo qd ler o arquivo
int text_size;

struct Node{
    char caracter;
    int char_code[MAX_SIZE];
    int char_code_size; ///quantidade de bits preenchidos no arquivo p�s �rvore
};
typedef struct Node Node;

struct Hash{
    Node text[text_size];
};
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
    int value;
    struct Tree *left;
    struct Tree *right;
};
typedef struct Tree Tree;

Tree *HuffTree(char caracter){
    int code_array;
    return code_array;
}

///o arquivo do texto tem q ser colocado numa string text com cada caractere em uma posi��o
encode(char text, Tree *HuffTree){  ///text -  texto completo descomprimido
		unsigned char bit_array[MAX_SIZE]; ///array correspondente a 1 byte
		int index = 0;
		int code_index = 0;
		int code_text_index = 0;
		int text_index = 0;
		int code_length = 0; ///quantidade totais de bits do arquivo comprimido
		int bit_length = 0; ///quantidade de bit preenchidos de 1 byte

		ListNode *first;
		first->item = NULL;

		Hash* code;
		memset(bit_array, 0, sizeof(char)*MAX_SIZE);

		ListNode *full_text = createList; ///lista composta de todos os array de bits p�s compress�o

		while(index < sizeof(text)){
        ///code recebe a hash p�s �rvore do 1 caractere do texto com 1 n� text contendo o caractere, o code comprimido e o tamanho do code
            code = HuffTree(text[text_index]); ///vai mudar dependendo da estrutura da clara

			while(code_text_index < code[code_index]->text[text_size]->char_code_size){ ///loop pra cada caractere de cada codigo de cada letra p�s arvore
                ///deslocar os bits pra preencher o array de 1 byte
				if(code->text[code_index]->char_code[code_index] == '1'){
					code_length++;
					bit_array[MAX_SIZE] = (bit_array[MAX_SIZE] << 1) | 1;
					bit_length ++;
				}
				else
					code_length++;
					bit_array[MAX_SIZE] = (bit_array[MAX_SIZE] << 1);
                    bit_length ++;
				if(bit_length == MAX_SIZE) ///se atingir 8 guarda na lista, zera e come�a outro byte, independente de ta no meio de uma letra
					full_text = insertNode(first, bit_array);
					bit_length = 0;
			code_text_index++;
			code_index++;
			}
		index++;
		}
    ///salvar lixo
		if((bit_length != 0) && (bit_length < MAX_SIZE)){
			bit_array[MAX_SIZE] = (bit_array[MAX_SIZE]) << (MAX_SIZE - bit_length);
			full_text = AddListNode(bit_array);
			int trash = MAX_SIZE - bit_length;
		}
}

