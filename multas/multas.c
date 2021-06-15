#include <stdio.h>

const int LIMITE = 80;
int main()
{

    float velo;

    //printf("Digite o valor da velocidade do transeunte:\n");
    scanf("%f", &velo);

    if (velo > LIMITE)
    {
        printf("Limite de velocidade excedido! Multado no valor de R$%.2f!\n", (velo - LIMITE) * 2);
    }
    else
    {
        printf("Velocidade dentro do limite permitido.");
    }

    return 0;
}
