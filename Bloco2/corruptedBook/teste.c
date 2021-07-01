#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char const *argv[])
{
    int lines=4, valids=0, i=0, j=0;
    
    char *line;
    line = malloc( sizeof(char));
    line = realloc(line, lines * sizeof(char));
    

    getchar();
    getchar();
    getchar();
    getchar();
    getchar();

    free(line);
    return 0;
}
