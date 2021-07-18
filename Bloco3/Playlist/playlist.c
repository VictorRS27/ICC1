#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Victor Rodrigues da Silva
 * N°USP: 12566140
 * 
 * Atividade de gerenciamento de playlists conforme imagem contida na pasta
*/

//structs com os dados das tabelas
typedef struct musica{
    int nomeSize;
    char *nome;
    int artistSize;
    char *artista;
    unsigned int duracao;
    } Musica;

typedef struct playlist{
    int nomeSize;
	char *nome;
	int total;
	Musica *musicas;
} Playlist;
//função pré pronta para avaliar o arquivo criado
void binaryToNum(char *binFilename) {
    FILE *fp = fopen(binFilename, "rb");

    double binValue = 0;
    double accumulator = 0.01;
    char ch;
    while (fread(&ch, sizeof(char), 1, fp)) {
        binValue += (double) ch * accumulator;
        accumulator += 0.01;
    }

    fclose(fp);
    printf("%lf\n", binValue);
}
//função para leitura de strings dinamicamente
char *read_line( int *size) {
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
            //printf("%c", line[i]);
            line = realloc(line, (i+2) * sizeof(char));
        }
        i++;
    }while (line[i-1]!='\0');
    //fflush(stdin);
    *size = i;
    return line;
}

int main(int argc, char const *argv[])
{
    Playlist list;
    list.total=0;
    int operator=0, i=0, atual=0, tmp;
    char *fileName;

    list.nome=read_line(&list.nomeSize);
    
    list.musicas = calloc(1, sizeof(Musica));
    //repete a função até o valor de saída
    do
    {
        scanf(" %i", &operator);
        switch (operator)
        {
        case 1://adiciona nova música
            if (list.total<15)
            {
                getchar();
                list.musicas = realloc(list.musicas, (list.total+1) * sizeof(Musica));            
                list.musicas[list.total].nome=read_line(&list.musicas[list.total].nomeSize);
                list.musicas[list.total].artista=read_line(&list.musicas[list.total].artistSize);
                scanf(" %i", &list.musicas[list.total].duracao);
                printf("Musica %s de %s adicionada com sucesso.\n", list.musicas[list.total].nome, list.musicas[list.total].artista);
                list.total++;
            }else
            {
                printf("Playlist cheia!\n");
            }
            
            break;

        case 2://exibe a playlist
            printf("---- Playlist: %s ----\n", list.nome);
            printf("Total de musicas: %i\n\n", list.total);
            for ( i = 0; i < list.total; i++)
            {
                if (i==atual)
                {
                    printf("=== NOW PLAYING ===\n");
                }
                
                printf("(%i). '%s'\n", i+1, list.musicas[i].nome);
                printf("Artista: %s\n", list.musicas[i].artista);
                printf("Duracao: %i segundos\n\n", list.musicas[i].duracao);
            }                            
            break;

        case 3://passa a música
            atual++;
            break;
        case 4://volta uma música
            atual--;
            break;

        case 5://salva playlist em arquivo binário
            getchar();
            fileName = read_line(&tmp);
            FILE *escrita = fopen( fileName,"wb");
            fwrite(&list.nomeSize, sizeof(int), 1, escrita);
            /*if (list.nome[list.nomeSize-1]=='\0')
            {
                list.nome = realloc(list.nome, (list.nomeSize-1) * sizeof(char));
            }*/
            
            
            fwrite(list.nome, sizeof(char), strlen(list.nome), escrita);
            fwrite(&list.total, sizeof(int), 1, escrita);
            //list.musicas = realloc(list.musicas, (list.total) * sizeof(Musica));
            for ( i = 0; i < list.total; i++)
            {
            fwrite(&list.musicas[i].nomeSize, sizeof(int), 1, escrita); 
            /*if (list.musicas[i].nome[list.musicas[i].nomeSize-1]=='\0')
            {
                list.musicas[i].nome = realloc(list.musicas[i].nome, strlen(list.musicas[i].nome) * sizeof(char));
            }*/
            
            
            fwrite(list.musicas[i].nome, sizeof(char), strlen(list.musicas[i].nome), escrita); 
            fwrite(&list.musicas[i].artistSize, sizeof(int), 1, escrita); 
            /*if (list.musicas[i].artista[list.musicas[i].artistSize-1]=='\0')
            {
                list.musicas[i].artista = realloc(list.musicas[i].artista, (list.musicas[i].artistSize-1) * sizeof(char));
            }*/
            
            
            fwrite(list.musicas[i].artista, sizeof(char), strlen(list.musicas[i].artista), escrita);
            fwrite(&list.musicas[i].duracao, sizeof( unsigned int), 1, escrita);
            }
            fclose(escrita);
            printf("Playlist %s salva com sucesso.\n", fileName);
            binaryToNum(fileName);
            break;

        case 6://carrega playlist em arquivo binário
            getchar();
            fileName = read_line(&tmp);
            FILE *leitura = fopen( fileName,"rb");
            if (leitura == NULL)
            {
                printf("Arquivo %s nao existe.\n", fileName);
                exit(0);
            }else
            {
                fread(&list.nomeSize, sizeof(int), 1, leitura);
                list.nome = realloc(list.nome, (list.nomeSize+1) * sizeof(char));
                list.nome[list.nomeSize]='\0';
                fread(list.nome, sizeof(char), list.nomeSize, leitura);
                fread(&list.total, sizeof(int), 1, leitura);
                list.musicas = realloc(list.musicas, (list.total) * sizeof(Musica));    
                for ( i = 0; i < list.total; i++)
                {
                fread(&list.musicas[i].nomeSize, sizeof(int), 1, leitura); 
                list.musicas[i].nome = realloc(list.musicas[i].nome, (list.musicas[i].nomeSize+1) * sizeof(char));
                list.musicas[i].nome[list.musicas[i].nomeSize]='\0';                
                fread(list.musicas[i].nome, sizeof(char), list.musicas[i].nomeSize, leitura); 
                fread(&list.musicas[i].artistSize, sizeof(int), 1, leitura); 
                list.musicas[i].artista = realloc(list.musicas[i].artista, list.musicas[i].artistSize * sizeof(char));
                list.musicas[i].artista[list.musicas[i].artistSize]='\0';
                fread(list.musicas[i].artista, sizeof(char), list.musicas[i].artistSize, leitura);
                fread(&list.musicas[i].duracao, sizeof(int), 1, leitura);
                }
                fclose(leitura);
                atual=0;
                printf("Playlist %s carregada com sucesso.\n", fileName);
                binaryToNum(fileName);
            }
            
            
            
            break;
        default:
            break;
        }
    } while (operator < 7);

    for ( i = 0; i < list.total; i++)
    {
        free(list.musicas[i].nome);
        free(list.musicas[i].artista);
    }
    free(list.musicas);
    free(list.nome);
    //printf("fim");
    return 0;
}
