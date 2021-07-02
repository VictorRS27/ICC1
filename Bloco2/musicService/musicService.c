#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct musica{
        char *nome;
        char *artista;
        int duracao;
    } Musica;

typedef struct playlist{
	char *nome;
	int total;
	Musica *musicas;
} Playlist;

char *read_line( ) {
    int i=0;
    char *line= malloc(sizeof(char));
    do
    {
        line[i]= getchar();
        if (line[i]=='\n')
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
    return line;
}

int main(int argc, char const *argv[])
{
    Playlist list;
    list.total=0;
    int operator=0, i=0, atual=0, teste=0;

    list.nome=read_line();
    
    list.musicas = calloc(1, sizeof(Musica));

    do
    {
        //operator=gets_s(stdin, 1);
        scanf(" %i", &operator);
        switch (operator)
        {
        case 1:
            getchar();
            teste=list.total+1;
            list.musicas = realloc(list.musicas, (teste) * sizeof(Musica));
            //printf("ler nome:");
            //printf("%s", read_line());
            list.musicas[list.total].nome=read_line();
            //printf("ler artista");
            list.musicas[list.total].artista=read_line();
            //printf("ler numero");
            scanf(" %i", &list.musicas[list.total].duracao);
            //printf("pos");            
            printf("Musica %s de %s adicionada com sucesso.\n", list.musicas[list.total].nome, list.musicas[list.total].artista);
            list.total++;
            break;

        case 2:
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

        case 3:
            atual++;
            break;
        case 4:
            atual--;
            break;
        default:
            break;
        }
    } while (operator < 5);

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
