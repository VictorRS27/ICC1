#include <stdio.h>

int main(){
    
	float tempC, tempF;

    //printf("Digite a temperatura em fahrenheit para convers�o");
    scanf("%f", &tempF);

    tempC = (tempF-32)*5/9;
    printf("%.2f\n", tempC);
}
