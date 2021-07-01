#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

char *read_line( char *line) {
    int i=0;
    line = malloc( sizeof(char));
    do
    {
        printf("Passo1");
        i++;
        line = realloc(line, i * sizeof(char));
        printf("Passo2");
        line[i] = getchar();
        printf("%c", line[i]);
        printf("Passo3");
        if (line[i]=='\n')
        {
            printf("executei!!!!!");
            line[i]='\0';
        }
        
    } while (line[i]!='\0');
    return line;
}


int main(int argc, char const *argv[])
{
    int lines=0, valids=0, i=0, j=0;
    
    scanf(" %i", &lines);
    getchar();
    char *line;
    line = read_line(line);
    
    /*for ( i = 0; i < lines; i++)
    {
        line = read_line(line);
        printf("executei");
    }
    
    /*scanf(" %i", &valids);
    int valid[valids];
    for ( i = 0; i < valids; i++)
    {
        scanf(" %i", &valid[i]);
        printf("%i", valid[i]);
    }
    
    /*for ( i = 0; i < valids; i++)
    {
        j=0;
        do
        {
            j++;
            printf("%s", *(line[valid[i]]+j));
        } while (*(line[valid[i]]+j-1)!='\0');
    }*/
        do
        {
            j++;
            printf("%c", *(line));
        } while (*(line)!='\0');
        /*do
        {
            j++;
            printf("%c", *(line[1]+j));
        } while (*(line[1]+j-1)!='\0');
        do
        {
            j++;
            printf("%s", *(line[2]+j));
        } while (*(line[2]+j-1)!='\0');
        do
        {
            j++;
            printf("%s", *(line[3]+j));
        } while (*(line[3]+j-1)!='\0');*/


   /*for (i=0; i<lines; i++)
		free(line[i]);*/
	free(line);
    return 0;
}
