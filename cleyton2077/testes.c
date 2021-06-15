#include <stdio.h>
#include <stdlib.h>

#define size_fita 10
int main()
{
    int tape[size_fita] = {}, operacao = 0, i = 0, pointer = 0;

    //leitura da fita
    for (i = 0; i < size_fita; i++)
    {
        scanf(" %i", &tape[i]);
    }

    if (tape[tape[pointer + 1]] != 0)
            {
                pointer = tape[tape[pointer + 2]];
            }
            else
            {
                pointer+=3;
            }

    //começo da saída e processamento
    printf("Saida do programa: \n");
    for (i = 0; i < size_fita; i++)
    {
        printf(" %i\n", tape[i]);
    }
    printf(" bmcvhnc %i tshthfhtfh %i\n", pointer, tape[pointer]);
    return 0;
}