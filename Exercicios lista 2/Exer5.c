#include <stdio.h>
#include <stdlib.h>

int main(){
    int num;
    float contador;
    float somaimpar;
    int contadorPar;
    float contadorMedia;
    float porcentagem;
    float mediaImpar;
    int menor;
    int maior;  
    
    printf("Entre com um numero: \n");
    scanf("%d", &num);

    maior = num;
    menor = num;

    while(num > 0 ){

        if(maior < num){
            maior = num;
        }
        if(menor > num){
            menor = num;
        }
        if(num % 2 == 0){
            contadorPar++;
        }
        if(num % 2 != 0){
            somaimpar = somaimpar + num;
            contadorMedia++;
        }

        contador++;
        printf("Entre com um numero: \n");
        scanf("%d", &num);

    }
    
    porcentagem = (contadorPar*100)/contador;
    mediaImpar = somaimpar/contadorMedia;

    printf("Numeros validos: %0.f\n", contador);
    printf("Percentual de numeros pares: %.1f %% \n", porcentagem);
    printf("A media dos numeros impares %.2f \n", mediaImpar);
    printf("Maior numero: %d\nMenor numero: %d \n", maior, menor);

    system("pause");
    return 0;
}