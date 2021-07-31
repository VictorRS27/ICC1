#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
 * Victor Rodrigues da Silva
 * N°USP: 12566140
 * 
 * Atividade de detecao de palindromos conforme pdf contido na pasta desse arquivo
 * 
*/

char *read_line() {
    int i=0;
    char *line= malloc(sizeof(char));
    do
    {
        line[i]= getchar();
        if (line[i]=='\n' || line[i]=='\r')
        {
            line[i]='\0';
        }else
        {
            line = realloc(line, (i+2) * sizeof(char));
        }
        i++;
    }while (line[i-1]!='\0');
    return line;
}

char *frase;
int idi;

int detectaPalindromo(int direita, int esquerda) {

    int saida;
    if (!isalnum(frase[direita]))
    {
        if (frase[direita]=='/' || frase[direita]=='/')
        {
            return 2;
        }
        saida = detectaPalindromo(direita - 1, esquerda);
    }else if (!isalnum(frase[esquerda])
    {
        saida = detectaPalindromo(direita , esquerda + 1);
    }else
    {
        if (frase[direita]==frase[esquerda])
        {
            if (direita==esquerda || direita == esquerda+1)
            {
                return 1;
            }
            saida = detectaPalindromo(direita - 1, esquerda + 1);
        }
    }
    
    
    
    
    
}