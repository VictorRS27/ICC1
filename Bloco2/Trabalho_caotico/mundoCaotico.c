#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct boardSize
{
    int lines;
    int columns;
} BOARD_SIZE;

int neighborNeummanCheck(int currentLine, int currentColumn, BOARD_SIZE boardData, char **copy)
{
    int i, totalNeighbors = 0;
    //printf("neuman\n");
    for (i = -2; i < 3; i++)
    {
        if (i != 0)
        {
            if (currentLine + i < 0)
            {
                if (copy[currentLine + i + boardData.lines][currentColumn] == 'x')
                {
                    totalNeighbors++;//printf("extrapolou pra cima e achou 1\n");
                }
            }
            else if (currentLine + i >= boardData.lines)
            {
                if (copy[currentLine + i - boardData.lines][currentColumn] == 'x')
                {
                    totalNeighbors++;//printf("extrapolou pra baixo e achou 1\n");
                }
            }
            else
            {
                if (copy[currentLine + i][currentColumn] == 'x')
                {
                    totalNeighbors++;//printf("vertical aleatoria achou\n");
                }
            }

            if (currentColumn + i < 0)
            {
                if (copy[currentLine][currentColumn + i + boardData.columns] == 'x')
                {
                    totalNeighbors++;//printf("extrapolou pra esquerda e achou 1\n");
                }
            }
            else if (currentColumn + i >= boardData.columns)
            {
                if (copy[currentLine][currentColumn + i - boardData.columns] == 'x')
                {
                    totalNeighbors++;//printf("extrapolou pra direita e achou 1\n");
                }
            }
            else
            {
                if (copy[currentLine][currentColumn + i] == 'x')
                {
                    totalNeighbors++;//printf("horizontal aleatorio achou\n");
                }
            }
        }
        //printf("%i\n", i);
    }
    //printf("total de vizinhos: %i\n", totalNeighbors);
    return totalNeighbors;
}

int neighborMooreCheck(int currentLine, int currentColumn, BOARD_SIZE boardData, char **copy)
{
    int i, j, totalNeighbors = 0;
    //printf("moore\n");
    for (i = -1; i < 2; i++)
    {
        for (j = -1; j < 2; j++)
        {
            if (i != 0 || j != 0)
            {
                if (currentLine + i < 0)
                {
                    if (currentColumn + j < 0)
                    {
                        if (copy[i + boardData.lines][j + boardData.columns] == 'x')
                        {
                            totalNeighbors++;//printf("extrapolou esquerda e cima e achou\n");
                        }
                    }
                    else if (currentColumn + j >= boardData.columns)
                    {
                        if (copy[boardData.lines-1][0] == 'x')
                        {
                            totalNeighbors++;//printf("extrapolou direita e cima e achou\n");
                        }
                    }else
                    {
                        if (copy[i + boardData.lines][currentColumn + j] == 'x')
                        {
                            totalNeighbors++;//printf("extrapolou cima e achou\n");
                        }
                    }
                    
                }
                else if (currentLine + i >= boardData.lines)
                {
                    if (currentColumn + j < 0)
                    {
                        if (copy[currentLine + i - boardData.lines][j + boardData.columns] == 'x')
                        {
                            totalNeighbors++;//printf("extrapolou esquerda e baixo e achou\n");
                        }
                    }
                    else if (currentColumn + j >= boardData.columns)
                    {
                        if (copy[0][0] == 'x')
                        {
                            totalNeighbors++;//printf("extrapolou direita e baixo e achou\n");
                        }
                    }else
                    {
                        if (copy[currentLine + i - boardData.lines][currentColumn + j] == 'x')
                        {
                            totalNeighbors++;//printf("extrapolou baixo e achou\n");
                        }
                    }
                    
                }
                else if (currentColumn +j < 0)
                {
                    if (copy[currentLine + i][currentColumn + j + boardData.columns] == 'x')
                    {
                        totalNeighbors++;//printf("extrapolou esquerda e achou\n");
                    }
                }
                else if (currentColumn + j >= boardData.columns)
                {
                    if (copy[currentLine + i][currentColumn + j - boardData.columns] == 'x')
                    {
                        totalNeighbors++;//printf("extrapolou direita e achou\n");
                    }
                }
                else
                {
                    if (copy[currentLine + i][currentColumn + j] == 'x')
                    {
                        totalNeighbors++;//printf("nao extrapolou achou\n");
                    }
                }
            }
            //printf("%i %i\n", i, j);
        }
    }
    /*if (currentLine + 1 == boardData.lines && currentColumn + 1 == boardData.columns)
    {
        printf("total de vizinhos: %i\n", totalNeighbors);
    }*/
    
    //printf("total de vizinhos: %i\n", totalNeighbors);
    return totalNeighbors;
}

void changeGeneration(char **board, BOARD_SIZE boardData, char method)
{
    int i, j, totalNeighbors;
    char **copy = malloc(boardData.lines * sizeof(char *));
    for (i = 0; i < boardData.lines; i++)
    {
        copy[i] = malloc(boardData.columns * sizeof(char));
    }
    //printf("copy created\n");
    for (i = 0; i < boardData.lines; i++)
    {
        for (j = 0; j < boardData.columns; j++)
        {
            copy[i][j] = board[i][j];
        }
    }
    //printf("copied\n");
    for (i = 0; i < boardData.lines; i++)
    {
        for (j = 0; j < boardData.columns; j++)
        {
            if (method == 'N')
                {
                    totalNeighbors = neighborNeummanCheck(i, j, boardData, copy);
                }
                else
                {
                    totalNeighbors = neighborMooreCheck(i, j, boardData, copy);
                }
            if (copy[i][j] == 'x')
            {
                
                if (totalNeighbors < 2 || totalNeighbors > 3)
                {
                    board[i][j] = '.';
                }
            }else if (copy[i][j] == '.')
            {
                
                if (totalNeighbors == 3)
                {
                    board[i][j] = 'x';
                }
            }
            //printf("fim de uma verificacao de um %c\n", copy[i][j]);
        }
    }
    //printf("\nFim de uma Geracao\n\n");
    /*printf("\n\n");
    for (i = 0; i < boardData.lines; i++)
    {
        for (j = 0; j < boardData.columns; j++)
        {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }*/
    

    for (i = 0; i < boardData.lines; i++)
        free(copy[i]);
    free(copy);
    //printf("\nFim de uma Geracao pos free\n\n");
}

int main(int argc, char const *argv[])
{
    int i, j, generations;
    char neighborhood;

    BOARD_SIZE boardData;

    scanf("%d %d", &boardData.lines, &boardData.columns);

    char **board = malloc(boardData.lines * sizeof(char *));
    for (i = 0; i < boardData.lines; i++)
    {
        board[i] = malloc(boardData.columns * sizeof(char));
    }

    scanf(" %d %c", &generations, &neighborhood);

    if ((neighborhood != 'N' && neighborhood!='M') || generations < 0 || boardData.columns <= 0 || boardData.lines <= 0)
        {
            printf("Dados de entrada apresentam erro.\n");
            exit(0);
        }

    for (i = 0; i < boardData.lines; i++)
    {
        for (j = 0; j < boardData.columns; j++)
        {
            scanf(" %c", &board[i][j]);
        }
    }


    for (i = 0; i < generations; i++)
    {
        changeGeneration(board, boardData, neighborhood);
    }

    for (i = 0; i < boardData.lines; i++)
    {
        for (j = 0; j < boardData.columns; j++)
        {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < boardData.lines; i++)
        free(board[i]);
    free(board);
    return 0;
}
