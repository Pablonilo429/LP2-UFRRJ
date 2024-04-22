#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

    int var1;
    float potvar;
    int contadorTerm = 1;
    int term = 1;
    int fatTerm = 1;
    float seno;
    float transport;
    double fat;

    printf("Entre com X: ");
    scanf("%d,", &var1);

    while (contadorTerm <= 20)
    {

        for (fat = 1; fatTerm > 1; fatTerm--) // Calcula a fatorial da formula
            fat = fat * fatTerm;

        potvar = pow(var1, term); // Calcula a potencia da formula

        transport = potvar / fat;
        // Seleciona subtracao e soma conforme a formula
        if (contadorTerm % 2 == 0)
        {
            seno = seno - transport;
        }
        if (contadorTerm % 2 != 0)
        {
            seno = transport + seno;
        }

        if (contadorTerm >= 10)
        { // Mostra os valores conforme os termos
            printf("Seno (%d) com termo %d e de: %lf \n ", var1, contadorTerm, seno);
        }

        contadorTerm++;
        term = term + 2;
        fatTerm = term;
    }

    system("pause");

    return 0;
}