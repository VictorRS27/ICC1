#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size=0, i=0;
    char values[49];
    
    for ( i = 0; i < 49; i++)
    {
        //fflush(stdin);
        scanf(" %c", &values[i]);
    }

    
    //fflush(stdin);
    scanf(" %i", &size);
    
    int message[size];

    for ( i = 0; i < size; i++)
    {
        //fflush(stdin);
        scanf(" %i", &message[i]);
    }

    for ( i = 0; i < size; i++)
    {
        
        switch (values[message[i]])
        {
        case 'E':
            printf("\n");
            break;
        case '_':
            printf(" ");
            break;        
        default:
            printf("%c", values[message[i]]);
            break;
        }
		        
    }

    return 0;    
}
