#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
    int vet[100];
    memset(&vet, 0, sizeof(vet));
    char useroption = ' ';
    int j = 0;
    int i = 0;
    int contador = 0;
    int num;
    int maiorvalor;
    int contadorvalor = 0;
 

    do{    
        printf("Entre com um numero: \n");
        scanf("%d", &num);
        vet[contador] = num;
        contador++;
        printf("Deseja sair? (S/N): \n");
        scanf("%c", &useroption);
    } while(useroption != 's' && useroption != 'S');
    
    maiorvalor = vet[0];
    for (i = 0; i < 100; i++){
       if (vet[i] > maiorvalor){
           maiorvalor = vet[i];
        }
    }

    for(j = 0; j < 100; j++){
        if(maiorvalor == vet[j]){
            contadorvalor++;
        }

    }


    printf("Maior valor = %d \n", maiorvalor);
    printf("Esse valor apareceu %d vezes \n", contadorvalor);

    system("pause");
    return 0;


}

