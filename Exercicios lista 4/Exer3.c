#include <stdio.h>
#include <stdlib.h>


int contadordado(int vet1[]){
    int maiorval = 0;
    int contador = 1;
    int num;
    
    for (contador = 1; contador < 7; contador++){
        if(vet1[contador] > maiorval){
            maiorval = vet1[contador];
            num = contador;
        }
    }
   return num; 
}


int main(){
    int valdado = 1;
    int armazenadado[7] = {0,0,0,0,0,0,0};
    int i = 1;
    int num;
 

    do{
        printf("Insira o valor do dado: \n");
        scanf("%d", &valdado);
        armazenadado[valdado] = armazenadado[valdado]+1;
        printf("Caso queira encerrar digite um numero negativo\n");

    }while(valdado > 0);

    for(i = 1; i < 7; i++){
        num = armazenadado[i];
        printf("O dado de valor %d apareceu: %d vezes \n", i,  num);
    }

    printf("O dado %d foi o que mais apareceu \n", contadordado(armazenadado));
    system("pause");
    return 0;
}

