#include <stdio.h>
#include <stdlib.h>
#include <math.h>


//valida os dados de entada
//o primeiro argumento é um char de qual variavel será verificada
//o segundo a variavel a ser validada
void validator(char n, int i){
    if ( n=='n' && i<=0)// 0 é numero natural
    {   
        printf("Falha no processamento dos dados.");
        exit(0);
        
    }else if (n=='i' && i!=-1 && i!=0 &&i!=1)
    {
        printf("Falha no processamento dos dados.");
        exit(0);
    }
}

//conta a frequencia de cada terreno 
short int baldio=0, parque=0, residencia=0;
void earthCounter(int i){
    switch (i)
    {
    case 1:
        parque++;
        break;

    case -1:
        baldio++;
        break;

    case 0:
        residencia++;
        break;
    
    default:
        break;
    }
}

//calcular a diferença
float calculate(int x, int y, int preX, int preY){
    //soma das distancias de contoro menos a distancia economizada com um pitagoras
    return abs(x-preX)+abs(y-preY)-sqrt(pow(abs(x-preX),2)+pow(abs(y-preY),2));
}


int main()
{
    int n=0, x=0, y=0, preX=0, preY=0, homeX=0, homeY=0, i=0, preI=0,  j=0;
    float diference=0;
    scanf(" %i", &n);
    validator('n', n);

    scanf(" %i %i %i", &homeX, &homeY, &i);
    preX=homeX;
    preY=homeY;
    preI=i;
    earthCounter(i);

    for ( j = 1; j < n; j++)
    {
        scanf(" %i %i %i", &x, &y, &i);
        validator('i', i);
        earthCounter(i);
        if (preI==1)
        {
            diference+=calculate(x, y, preX, preY);
        }
        preX=x;
        preY=y;
        preI=i;
    }
    if (preI==1)
    {   
        diference+=calculate(x, y, homeX, homeY);
    }

    printf("Ao todo, foi passado por %d terrenos baldios, %d terrenos residenciais e %d parques.\nA diferenca total de distancia percorrida foi de %.2f metros.", baldio, residencia, parque, diference);
    
    return 0;
}


