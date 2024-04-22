#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    int i;
    int j;
    int es;

    printf("Entre com um numero: \n");
    scanf("%d", &num);

    for (i = 0; i < num; i++)
    {
        for (es = 1; es <= (num - i) + 1; es++)
            printf(" ");
        for (j = 1; j <= (i * 2) + 1; j++)
            printf("*");
        printf("\n");
    }

    system("pause");
    return 0;
}