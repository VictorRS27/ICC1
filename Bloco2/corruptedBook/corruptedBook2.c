#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *read_line( char *line) {
    int i=0;
    do
    {
        line[i]= getchar();
        if (line[i]=='\n')
        {
            line[i]='\0';
        }else
        {
            line = realloc(line, (i+1) * sizeof(char));
        }
        i++;
    }while (line[i-1]!='\0');
    fflush(stdin);
    return line;
}

int main(int argc, char const *argv[])
{
    int lines=0, valids=0, i=0/*, j=0*/;

    scanf(" %i%*[\n]s", &lines);
    char **line = malloc(lines * sizeof(char *));
	for (i=0; i<lines; i++){
		line[i] = malloc(sizeof(char));
        line[i] = read_line(line[i]);
    }

    scanf(" %i", &valids);
    int valid[valids];
    for ( i = 0; i < valids; i++)
    {
        scanf(" %i", &valid[i]);
    }
    for ( i = 0; i < valids; i++)
    {
        printf("%s\n", line[valid[i]]);
        /*j=0;
        do
        {            
            printf("%c", *(line[valid[i]]+j));
            j++;
        } while (*(line[valid[i]]+j-1)!='\0');
        printf("\n");*/
    }
    
    


    for (i=0; i<lines; i++)
		free(line[i]);
	free(line);
    return 0;
}
