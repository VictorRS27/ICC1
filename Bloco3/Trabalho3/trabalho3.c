#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Victor Rodrigues da Silva
 * N°USP: 12566140
 * 
 * Atividade para preenchimento de espaço vazio em ascii arte
 * 
 * 
*/

//leitura de strings
char *read_line()
{
    int i = 0;
    char *line = malloc(sizeof(char));
    do
    {
        line[i] = getchar();
        if (line[i] == '\n' || line[i] == '\r')
        {
            line[i] = '\0';
        }
        else
        {
            line = realloc(line, (i + 2) * sizeof(char));
        }
        i++;
    } while (line[i - 1] != '\0');
    return line;
}

int totalLines = -1;
int eofReader;
char fundo, caracPreenche;
//leitura de linha char em arquivo
char *readFileLine(FILE *leitura)
{
    int i = 0;
    char *line = malloc(sizeof(char));
    do
    {
        eofReader = fgetc(leitura);
        line[i] = eofReader;
        line = realloc(line, (i + 2) * sizeof(char));
        //posiciona /0 para escrita da imagem com a mascara %s 
        if (line[i] == '\n' || eofReader == EOF)
        {
            line[i+1]='\0';
        }
        //para escrita e preciso que tenha \n
        if (eofReader == -1)
        {
            line[i] = '\n';
        }

        i++;
    } while (line[i - 1] != '\n' && line[i - 1] != '\r');
    return line;
}
//funcao recursiva que preenche dados
void preencher(char **matriz, int coluna, int linha)
{
    if (coluna - 1 >= 0)
    {
        if (matriz[linha][coluna - 1] == fundo)
        {
            matriz[linha][coluna - 1] = caracPreenche;
            preencher(matriz, coluna - 1, linha);
        }
    }
    if (coluna + 1 < strlen(matriz[linha]))
    {
        if (matriz[linha][coluna + 1] == fundo)
        {
            matriz[linha][coluna + 1] = caracPreenche;
            preencher(matriz, coluna + 1, linha);
        }
    }
    if (linha - 1 >= 0)
    {
        if (matriz[linha - 1][coluna] == fundo)
        {
            matriz[linha - 1][coluna] = caracPreenche;
            preencher(matriz, coluna, linha - 1);
        }
    }
    if (linha + 1 <= totalLines)
    {
        if (matriz[linha + 1][coluna] == fundo)
        {
            matriz[linha + 1][coluna] = caracPreenche;
            preencher(matriz, coluna, linha + 1);
        }
    }
}
//funcao pronta para enquadramento
void enquadra_arte(
    char *nome_do_arquivo_da_arte,
    int altura_do_quadro,
    int largura_do_quadro)
{
    FILE *f_arte_ptr = fopen(nome_do_arquivo_da_arte, "r");
    if (f_arte_ptr == NULL)
    {
        printf(
            "Erro na abertura do arquivo, "
            "Você esqueceu de fechar o arquivo antes? "
            "Ou deu free na string com o nome sem querer?\n");

        exit(EXIT_FAILURE);
    }

    int qtd_espc_comeco;
    const char *apoio;
    if (largura_do_quadro % 2 == 0)
    {
        qtd_espc_comeco = largura_do_quadro / 2;
        apoio = "/\\";
    }
    else
    {
        qtd_espc_comeco = largura_do_quadro / 2 + 1;
        apoio = "Ʌ";
    }

    for (int i = 0; i < qtd_espc_comeco; i++)
        printf(" ");
    printf("%s\n", apoio);

    printf("╭");
    for (int i = 0; i < largura_do_quadro; i++)
        printf("—");
    printf("╮\n");

    for (int i = 0; i < altura_do_quadro; i++)
    {
        printf("|");
        for (int j = 0; j < largura_do_quadro; j++)
        {
            char pixel_atual = fgetc(f_arte_ptr);
            printf("%c", pixel_atual);
        }
        printf("|");

        char quebra = fgetc(f_arte_ptr);
        if (quebra != EOF)
            printf("%c", quebra);
    };
    fclose(f_arte_ptr);

    printf("\n╰");
    for (int i = 0; i < largura_do_quadro; i++)
        printf("—");
    printf("╯\n");
}

int main(int argc, char const *argv[])
{
    int i, j, linha, coluna, preenchimentos;
    char *fileName = read_line();
    char **figura = malloc(sizeof(char *));
    FILE *leitura = fopen(fileName, "r");

    if (leitura == NULL)
    {
        printf("Erro, nao foi possivel abrir o arquivo\n");
    }
    else
    {
        do
        {
            totalLines++;
            figura = realloc(figura, (totalLines + 1) * sizeof(char *));
            figura[totalLines] = readFileLine(leitura);
        } while (eofReader != EOF);
    }
    fclose(leitura);

    scanf("%i", &preenchimentos);

    printf("Arte inicial:\n");
    for (i = 0; i <= totalLines; i++)
    {
        /*for ( j = 0; j < strlen(figura[i]); j++)
        {
            printf("%i ", figura[i][j]);
        }
        printf("\n");*/
        printf("%s", figura[i]);
    }

    for (i = 0; i < preenchimentos; i++)
    {
        scanf(" %c", &caracPreenche);
        scanf(" %i", &linha);
        scanf(" %i", &coluna);

        fundo = figura[linha][coluna];
        figura[linha][coluna] = caracPreenche;
        preencher(figura, coluna, linha);

        printf("\nArte apos a etapa %i:\n", i);
        for (j = 0; j <= totalLines; j++)
        {
            printf("%s", figura[j]);
        }
    }

    FILE *escrita = fopen(fileName, "w");

    for (j = 0; j < totalLines; j++)
    {
        fprintf(escrita, "%s", figura[j]);
    }
    for (j = 0; j < strlen(figura[totalLines]); j++)
    {
        //reposicao do EOF para gravacao
        if (figura[totalLines][j] == '\n')
        {
            figura[totalLines][j] = EOF;
        }

        fprintf(escrita, "%c", figura[totalLines][j]);
    }

    fclose(escrita);

    printf("\nArte enquadrada:\n");

    enquadra_arte(fileName, totalLines + 1, strlen(figura[0]) - 1);

    //liberacao das variaveis alocadas
    for (i = 0; i < totalLines; i++)
    {
        free(figura[i]);
    }

    free(figura);
    free(fileName);

    return 0;
}
