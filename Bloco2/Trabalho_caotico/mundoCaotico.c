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
                if (copy[currentLine + i + boardData.lines][currentColumn] == 'X')
                {
                    totalNeighbors++;//printf("extrapolou pra cima e achou 1\n");
                }
            }
            else if (currentLine + i >= boardData.lines)
            {
                if (copy[currentLine + i - boardData.lines][currentColumn] == 'X')
                {
                    totalNeighbors++;//printf("extrapolou pra baixo e achou 1\n");
                }
            }
            else
            {
                if (copy[currentLine + i][currentColumn] == 'X')
                {
                    totalNeighbors++;//printf("vertical aleatoria achou\n");
                }
            }

            if (currentColumn + i < 0)
            {
                if (copy[currentLine][currentColumn + i + boardData.columns] == 'X')
                {
                    totalNeighbors++;//printf("extrapolou pra esquerda e achou 1\n");
                }
            }
            else if (currentColumn + i >= boardData.columns)
            {
                if (copy[currentLine][currentColumn + i - boardData.columns] == 'X')
                {
                    totalNeighbors++;//printf("extrapolou pra direita e achou 1\n");
                }
            }
            else
            {
                if (copy[currentLine][currentColumn + i] == 'X')
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
    for (i = -1; i < 2; i++)
    {
        for (j = -1; j < 2; j++)
        {
            if (i != 0 || j != 0)
            {
                if (currentLine == 0)
                {
                    if (currentColumn == 0)
                    {
                        if (copy[i + boardData.lines][j + boardData.columns] == 'X')
                        {
                            totalNeighbors++;
                        }
                    }
                    else if (currentColumn == boardData.columns)
                    {
                        if (copy[i + boardData.lines][currentLine + j - boardData.columns] == 'X')
                        {
                            totalNeighbors++;
                        }
                    }
                }
                else if (currentLine == boardData.lines)
                {
                    if (currentColumn == 0)
                    {
                        if (copy[currentLine + i - boardData.lines][j + boardData.columns] == 'X')
                        {
                            totalNeighbors++;
                        }
                    }
                    else if (currentColumn == boardData.columns)
                    {
                        if (copy[currentLine + i - boardData.lines][currentLine + j - boardData.columns] == 'X')
                        {
                            totalNeighbors++;
                        }
                    }
                }
                else if (currentColumn == 0)
                {
                    if (copy[currentLine + i][j + boardData.columns] == 'X')
                    {
                        totalNeighbors++;
                    }
                }
                else if (currentColumn == boardData.columns)
                {
                    if (copy[currentLine + i][currentColumn + j - boardData.columns] == 'X')
                    {
                        totalNeighbors++;
                    }
                }
                else if (currentLine == boardData.lines)
                {
                    if (copy[currentLine + i - boardData.lines][currentColumn + j] == 'X')
                    {
                        totalNeighbors++;
                    }
                }
                else if (currentLine == 0)
                {
                    if (copy[i + boardData.lines][currentColumn + j] == 'X')
                    {
                        totalNeighbors++;
                    }
                }
                else
                {
                    if (copy[currentLine + i][currentColumn + j] == 'X')
                    {
                        totalNeighbors++;
                    }
                }
            }
        }
    }
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
            if (copy[i][j] == 'X')
            {
                if (method == 'N')
                {
                    totalNeighbors = neighborNeummanCheck(i, j, boardData, copy);
                }
                else
                {
                    totalNeighbors = neighborMooreCheck(i, j, boardData, copy);
                }

                if (totalNeighbors < 2 || totalNeighbors > 3)
                {
                    board[i][j] = '.';
                }
            }
            if (copy[i][j] == '.')
            {
                if (method == 'N')
                {
                    totalNeighbors = neighborNeummanCheck(i, j, boardData, copy);
                }
                else
                {
                    totalNeighbors = neighborMooreCheck(i, j, boardData, copy);
                }
                if (totalNeighbors == 3)
                {
                    board[i][j] = 'X';
                }
            }
            //printf("fim de uma verificação de um %c\n", copy[i][j]);
        }
    }
    //printf("\n");

    for (i = 0; i < boardData.columns; i++)
        free(copy[i]);
    free(copy);
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

    for (i = 0; i < boardData.lines; i++)
    {
        for (j = 0; j < boardData.columns; j++)
        {
            scanf(" %c", &board[i][j]);
        }
    }

    /*for (i = 0; i < boardData.lines; i++)
    {
        for (j = 0; j < boardData.columns; j++)
        {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }*/

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

    for (i = 0; i < boardData.columns; i++)
        free(board[i]);
    free(board);
    return 0;
}
