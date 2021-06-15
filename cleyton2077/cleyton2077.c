#include <stdio.h>
#include <stdlib.h>

#define size_fita 512
int main()
{
    int tape[size_fita] = {}, operacao = 0, i = 0, pointer = 0;

    //leitura da fita
    for (i = 0; i < size_fita; i++)
    {
        scanf(" %i", &tape[i]);
    }

    //começo da saída e processamento
    printf("Saida do programa:\n");

    do
    {
        operacao = tape[pointer];
        switch (operacao)
        {
        case 1:
            tape[tape[pointer + 3]] =tape[tape[pointer + 1]]+ tape[tape[pointer + 2]];
            pointer += 4;
            break;

        case 2:
            tape[tape[pointer + 3]] = tape[tape[pointer + 1]] * tape[tape[pointer + 2]];
            pointer += 4;
            break;

        case 3:
            tape[tape[pointer + 3]] = tape[tape[pointer + 1]] < tape[tape[pointer + 2]] ? 1 : 0;
            pointer += 4;
            break;

        case 4:
            tape[tape[pointer + 3]] = tape[tape[pointer + 1]] == tape[tape[pointer + 2]] ? 1 : 0;
            pointer += 4;
            break;

        case 5:
            pointer = tape[tape[pointer + 1]];
            break;

        case 6:
            if (tape[tape[pointer + 1]] != 0)
            {
                pointer = tape[tape[pointer + 2]];
            }
            else
            {
                pointer+=3;
            }
            break;

        case 7:
            tape[tape[pointer + 2]] = tape[tape[pointer + 1]];
            pointer += 3;
            break;

        case 8:
            printf("%c", tape[tape[pointer + 1]]);
            pointer += 2;
            break;

        case 9:
            printf("%i", tape[tape[pointer + 1]]);
            pointer += 2;
            break;

        default:
            break;
        }
    } while (operacao != 0);

    printf("\n");
    //saída da fita
    printf("Estado final da fita:");
    for (i = 0; i < size_fita; i++)
    {
        printf("\n%i", tape[i]);
    }

    return 0;
}
