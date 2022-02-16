#include <stdio.h>
#include <stdlib.h>

int main(){
    float contador = 0;
    int contadoropin = 0;
    int contadorPercent;
    int media;
    int novo;
    int velho;
    float percent;
    int idade;
    int somadorIdade = 0;
    int grau;
    int opin;
    int saida = 1;   
        
    while(saida != 0){
        printf("Entre com a sua idade: \n");
        scanf("%d", &idade);
        printf("Entre com o grau de instrucao, em anos\n");
        scanf("%d", &grau);
        printf("Entre com a sua opiniao: \n1 - otimo \n2 - regular \n3 - pessimo\n");
        scanf("%d", &opin);

        if(opin == 1){
            somadorIdade = somadorIdade + idade;
            contadoropin++;
        }
        if(opin == 3 && grau > 10){
            contadorPercent++;    
        }
        if(velho < idade){
            velho = idade;
        }
        if(novo > idade){
            novo = idade;
        }

        contador++;
        printf("Se deseja sair para receber os dados, digite zero: \n");
        scanf("%d", &saida);
          
    }

    media = somadorIdade/contadoropin;
    percent = (contadorPercent*100)/contador;

    printf("Media das idades das pessoas que responderam otimo: %d\n", media);
    printf("A idade do espectador mais velho: %d e mais novo: %d\n", velho, novo);
    printf("O percentual de pessoas com mais de 10 anos de instrucao que responderam pessimo: %.1f %%\n", percent);

    system("pause");
    return 0;
}