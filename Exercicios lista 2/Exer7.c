#include <stdio.h>
#include <stdlib.h>

int main(){
    int principal;
    int bebida;
    int sobremesa;
    int cals;

    printf("Entre com o numero correspondente ao prato principal: \n");
    printf("1 - Vegetariano\n");
    printf("2 - Peixe\n");
    printf("3 - Frango\n");
    printf("4 - Carne\n");
    scanf("%d", &principal);

    if(principal == 0){
        printf("Voce nao entrou com o prato principal \n");
        cals = cals;
    }

    if(principal == 1){
        cals = cals + 180;
    }
    if(principal == 2){
        cals = cals + 230;  
    }
    if(principal == 3){
        cals = cals + 250;
    }
    if(principal == 4){
        cals = cals + 350;
    }

    printf("Entre com o numero correspondente a bebida: \n");
    printf("1 - Cha\n");
    printf("2 - Suco de laranja\n");
    printf("3 - Suco de melão\n");
    printf("4 - Refrigerante\n");
    scanf("%d", &bebida);

    if(bebida == 0){
        printf("Voce nao entrou com a bebida\n");
        cals = cals;
    }    

    if(bebida == 1){
       cals = cals + 80;
    }
    if(bebida == 2){
       cals = cals + 150;
    }
    if(bebida == 3){
       cals = cals + 70;
    }
    if(bebida == 4){
       cals = cals + 2;
    }

    printf("Entre com o numero correspondente a sobremesa: \n");
    printf("1 - Abacaxi\n");
    printf("2 - Sorvete diet\n");
    printf("3 - Mousse diet\n");
    printf("4 - Mousse chocolate\n");     
    scanf("%d", &sobremesa);

    if(sobremesa == 0){
        printf("Voce nao entrou com a sobremesa\n");
        cals = cals;
    }    

    if(sobremesa == 1){
        cals = cals + 75;
    }
    if(sobremesa == 2){
        cals = cals + 110;
    }
    if(sobremesa == 3){
        cals = cals + 60;
    }
    if(sobremesa == 4){
        cals = cals + 250;
    }

    printf("Total de calorias da refeicao: %d cals\n", cals);


    system("pause");
    return 0;
}