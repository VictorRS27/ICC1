#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n=0, k=0, i=0, j=0;
    char c=0;
    
    scanf(" %i ", &n);    
    //fflush(stdin);
    scanf("%c", &c);

    if ((n<=0)||(n>25))
    {
        printf("Altura invalida\n");
        exit(0);
    }
    
    for (k = n-1; k >= 0; k--)
    {

        for (i = 0; i < k; i++)
        {
            printf(" ");
        }
        for (j = i*2+1; j < n*2; j++)
        {
            printf("%c", c);
        }
        printf("\n");
    }
    
}
