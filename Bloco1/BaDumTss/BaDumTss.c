#include <stdio.h>

int main()
{
    int num;
	int cont=0;

    scanf("%i", &num);

    num % 11 == 0 ? cont++ : cont;
    num % 19 == 0 ? cont++ : cont;
    num % 13 == 0 ? cont++ : cont;
    switch (cont)
    {
    case 1:
        num % 11 == 0 ? printf("BaBa") : cont;
        num % 13 == 0 ? printf("BaDum") : cont;
        num % 19 == 0 ? printf("BaTss") : cont;
        break;
    case 2:
        num % 11 == 0 && num % 13 == 0 ? printf("BaDumDum") : cont;
        num % 11 == 0 && num % 19 == 0 ? printf("BaDumTss") : cont;
        num % 13 == 0 && num % 19 == 0 ? printf("DumDumTss") : cont;
        break;
    case 3:
        printf("BaDumTssTss");
        break;
    default:
        printf("%i", num);
        break;
    }

    return 0;
}
