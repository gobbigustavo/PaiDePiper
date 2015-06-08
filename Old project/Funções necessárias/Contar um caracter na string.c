#include <stdio.h>
#include <string.h>
int conta(char letra, char *palavra)
{

    int num_vezes=0;
    int i=0;
    while(*palavra!='\0')
    {
        if(*palavra==letra)
        {
            num_vezes++;
        }
        palavra++;
    }
    return num_vezes;
}

main()
{
    char palavra[50];

    gets(palavra);
    int indice = 0;

    while(palavra[indice]!='\0')
    {
        if(palavra[indice] != palavra[indice-1]){
        printf("Letra %c ocorre: %d vezes\n",palavra[indice],conta(palavra[indice],palavra));
        }
          indice++;

    }
}
