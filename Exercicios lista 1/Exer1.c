#include <stdio.h>
#include <stdlib.h>

int main(){

    float menor;
    float maior;
    int contador;
    float med;
    float num;
    printf("Entre com um numero:\n");
    scanf ("%f", &num);   
    maior = num;
    menor = num;

    while (num != 999) 
    {
        contador++;
        med = med + num;
        if (maior < num){
            maior = num;
        }
        if (menor > num){
            menor = num;
        }             
        printf("Entre com um numero:\n");
        scanf ("%f", &num);
        
    }   
    printf("Numeros lidos: %d\n", contador);
    printf("Media: %.2f\n", med/contador);
    printf("Maior numero: %.2f\n", maior);
    printf("Menor numero: %.2f\n", menor);

    system("pause");
    return 0;       

}