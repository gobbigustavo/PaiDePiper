#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "queue.h"
#include "linkedList.h"
#include "hash.h"
#include "stack.h"

#define UNSIGNED_EOF 255 //VALOR DE EOF QUANDO CONVERTIDO PARA UNSIGNED CHAR
#define MAX_SIZE_BINARY 20
#define MAX_SIZE_BINARY_ARRAY 21

void compress()
{
	Hashtable *ht = createHashtable();
	linkedList *charBits = newLinkedList();
    FILE *file = fopen("file.txt", "r");
    FILE *backp = fopen("backp.txt","w");
    FILE *backp2 = fopen("backp2.txt","w");
    PriorityQueue * queue = createPriorityQueue();
    int characters[256],i,count=0,j,count2=0;
    unsigned char currentChar;
    memset(characters,0,sizeof(characters));

    if (file == NULL)
    {
        printf ("ERROR 404: FILE NOT FOUND\n");
        exit(0);
    }
    else
    {
        do
        {
            currentChar = fgetc(file);
            if(currentChar == UNSIGNED_EOF)
            {
                break;
            }
            characters[currentChar]++;
            count2++;
        }
        while(currentChar != UNSIGNED_EOF);
    }
    for(i=0; i < UNSIGNED_EOF; i++)
    {
        if(characters[i]!=0)
        {
            count++;
            enqueue(queue,i,characters[i],NULL);
        }
    }
    for(j = count ; j>1 ; j--)
    {
        dequeue(queue);
    }
	generateBits(ht, charBits, returnBT(queue));
	freeBT(returnBT(queue));
	rewind(file);
	do
    {
        currentChar = fgetc(file);
        if(currentChar == UNSIGNED_EOF)
        {
            break;
        }
        fprintf(backp,"%s",get(ht,currentChar));
    }
    while(currentChar != UNSIGNED_EOF);

    fprintf(backp2,"%d\n",count); // SALVA QUANTAS LINHAS DE HASH TERÁ NO ARQUIVO

    for(i=0; i < UNSIGNED_EOF; i++)
    {
        if(characters[i]!=0)
        {
            fprintf(backp2,"%c %s\n",i,get(ht,i)); //SALVA QUAL CARACTERE E O SEU CODIGO ASCII REDUZIDO NA HASH
        }
    }
    fprintf(backp2,"%d\n",count2); // SALVA A QUANTIDADE DE CHARS QUE EXISTIRÃO
    fclose(backp);
    writeCompressedData(backp2);
	fclose(backp2);
    fclose(file);
    rename("backp2.txt","compressed.txt");
    remove("backp.txt");
}



void writeCompressedData(FILE* file)
{
    FILE *backp = fopen("backp.txt","r");

    unsigned char currentChar;
    unsigned char binaryText[9];
    unsigned char CharT;
    int Char=0,count=0,i,binary[8];
    while(fgets(binaryText,9,backp)!=NULL)
    {
        for(i=0;i<strlen(binaryText);++i) // CONVERTE A STRING PARA ARRAY DE INTEIROS
        {
            binary[i] = binaryText[i] - 48;
        }
        if(strlen(binaryText) < 8)//PREENCHE COM 0 CASO O BINARIO N TENHA TAMANHO 8
        {
            for(i= strlen(binaryText) ; i<8 ; ++i)
            {
                binary[i] = 0;
            }
        }
        CharT = binToInt(binary);
        fprintf(file,"%c",CharT);
    }
    fclose(backp);
}







void decompress()
{
    FILE * file = fopen("compressed.txt","r");
    if (file == NULL)
    {
        printf ("ERROR 404: FILE NOT FOUND\n");
        exit(0);
    }
    int htLines,i,nmbChar,j;
    unsigned char Char;
    char bits[MAX_SIZE_BINARY_ARRAY];
    Hashtable * ht = createHashtable();
    unsigned Char2;
    char binaryText[MAX_SIZE_BINARY_ARRAY];
    fscanf(file,"%d",&htLines);//QUANTAS LINHAS SERÃO INSERIDAS NA HASH
    fgetc(file);
    for(i=0;i<htLines;++i)
    {
        Char = fgetc(file);
        fgetc(file); // PULAR O ESPAÇO ENTRE O CARACTER E OS BITS
        fgets(bits,MAX_SIZE_BINARY,file);
        bits[strlen(bits) - 1] = '\0'; // REMOVENDO \N QUE O FGETS COLOCA.
        put(ht,Char,Char,bits,0);
    }
    fscanf(file,"%d",&nmbChar);//PEGA QUANTOS CARACTERES TEM NA COMPRESSÃO
    fgetc(file);
    FILE* decomp = fopen("decomp.txt","w");
    do
    {
        Char = fgetc(file);
        if(Char == UNSIGNED_EOF)
        {
            break;
        }
        char binaryText[MAX_SIZE_BINARY_ARRAY];
        int * binary;
        binary = intToBin(Char);
        for(i=0;i<8;i++)
        {
            binaryText[i] = binary[i] + 48;
        }
        binaryText[8] = '\0';
        fprintf(decomp,"%s",binaryText);

    }
    while(Char != UNSIGNED_EOF);
    fclose(decomp);
    decomp = fopen("decomp.txt","r");
    FILE * decompressed = fopen("decompressed.txt","w");
    for(i=0;i<nmbChar;)
    {
        for(j=0;j<MAX_SIZE_BINARY;j++)
        {
            binaryText[j] = fgetc(decomp);
            binaryText[j+1] = '\0';
            unsigned char charByBit = getByBits(ht,binaryText);
            if(charByBit != UNSIGNED_EOF)
            {
                i++;
                fprintf(decompressed,"%c",charByBit);
                break;
            }
        }

    }

    removeht(ht);
    fclose(decompressed);
    fclose(file);
    fclose(decomp);
    remove("decomp.txt");
}
