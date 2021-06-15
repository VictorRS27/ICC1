#include <stdio.h>
#include <stdlib.h>

int main()
{
    int La = 0, Lb = 0, Ca = 0, Cb = 0, semente = 0, i = 0, j = 0, k = 0;

    scanf(" %i %i", &La, &Ca);
    scanf(" %i %i", &Lb, &Cb);

    scanf(" %i", &semente);
    srand(semente);

    if (Ca != Lb || semente == 0)
    {
        printf("Valores invalidos para a multiplicacao.\n");
        exit(0);
    }

    int vetA[La][Ca], vetB[Lb][Cb], vetC[La][Cb];

    //atribuição
    for (i = 0; i < La; i++)
    {
        for (j = 0; j < Ca; j++)
        {
            vetA[i][j] = rand() % 50 - 25;
        }
    }
    for (i = 0; i < Lb; i++)
    {
        for (j = 0; j < Cb; j++)
        {
            vetB[i][j] = rand() % 50 - 25;
        }
    }

    //calculo
    for (i = 0; i < La; i++)
    {
        for (j = 0; j < Cb; j++)
        {
            for (k = 0; k < Lb; k++)
            {
                if (k==0)
                {
                    vetC[i][j] = 0;
                }
                
                vetC[i][j] += vetA[i][k] * vetB[k][j];
            }
        }
    }

    //saida
    for (i = 0; i < La; i++)
    {
        printf("Linha %i:", i);
        for (j = 0; j < Cb; j++)
        {
            printf(" %i", vetC[i][j]);
        }
        printf("\n");
    }
    return 0;
}
