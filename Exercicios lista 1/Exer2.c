#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main()
{
    char option[4] = "fim";
    char optionUser[4];
    int optionMath;
    int result = 1;
    float var1, var2;

    while (result != 0)
    {
        printf("Entre com 1 para Soma, 2 para Subtracao, 3 para multiplicacao, 4 para divisao, 5 para potenciacao, 6 para logaritmo e 7 para raiz quadrada\n");
        scanf("%d", &optionMath);
        if (optionMath > 7 || optionMath <= 0)
        {
            printf("Entre com um valor dento da escala!\n");
        }

        if (optionMath == 1)
        { /* Soma */
            printf("Entre com os numeros para somar: \n");
            scanf("%f", &var1);
            scanf("%f", &var2);
            printf("Resultado da soma: %.1f\n", var1 + var2);
        }

        if (optionMath == 2)
        { /*Subtracao*/
            printf("Entre com os numeros para subtrair: \n");
            scanf("%f", &var1);
            scanf("%f", &var2);
            printf("Resultado da subtracao: %.1f\n", var1 - var2);
        }

        if (optionMath == 3)
        { /*Mulitplicacao*/
            printf("Ente com os numeros para multiplicacao: \n");
            scanf("%f", &var1);
            scanf("%f", &var2);
            printf("Resultado da multiplicacao: %.1f\n", var1 * var2);
        }

        if (optionMath == 4)
        { /*Divisao*/
            printf("Entre primeiro com o dividendo e depois o divisor: \n");
            scanf("%f", &var1);
            scanf("%f", &var2);
            if (var2 == 0)
            {
                printf("Nao e possivel dividir por zero!\n");
            }
            else
            {
                printf("Resultado da divisao: %.1f\n", var1 / var2);
            }
        }

        if (optionMath == 5)
        { /*Potenciacao*/
            printf("Entre primeiro com a base e depois o expoente: \n");
            scanf("%f", &var1);
            scanf("%f", &var2);
            printf("Resultado da exponenciacao: %.1f\n", pow(var1, var2));
        }

        if (optionMath == 6)
        { /*Logaritmo*/
            printf("Entre com o logaritmando: \n");
            scanf("%f", &var1);
            if (var1 == 0)
            {
                printf("Logaritmo de zero e indefinido!\n");
            }
            else
            {
                printf("Resultado do log: %.1f\n", log10(var1));
            }
        }

        if (optionMath == 7)
        { /*Raiz quadrada*/
            printf("Entre com o radicando: \n");
            scanf("%f", &var1);
            printf("Resultado da Radiciacao %.1f\n", sqrt(var1));
        }

        printf("Se deseja encerrar o programa digite \"fim\", caso queira continuar entre com qualquer caracter \n");
        scanf("%s", optionUser);
        result = strcmp(option, optionUser);
        optionMath = 0;
    }
    system("pause");
    return 0;
}
