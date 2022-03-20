#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printvet(int *vet){    //Funcao para imprimir vetores
    int i;
    printf("[ ");
    for(i = 0; i < 30; i++){
        printf("%d ", vet[i]);
    }
    printf("]");
}


void zeraPares(int *vet){   //Zera os pares de dentro de um vetor
    int i;
    
    for(i = 0; i < 30; i++){
        if(vet[i] % 2 == 0){
            vet[i] = 0;
        }
    }   

    printvet(vet); 
}

void dobra(int *vet){   //Dobra um vetor
    int i;

    for(i = 0; i < 30; i++){
        vet[i] = vet[i]*2;
    }
    printvet(vet);
}

void soma(int *vet1,int *vet2){     //Soma dois vetores
    int i;
    int aux;

    for(i = 0; i < 30; i++){
        aux = vet1[i];
        aux = aux + vet2[i];
        vet1[i] = aux;
    }
    printvet(vet1);
}


int main(){
    int vet[30];
    int vet1[30];
    int vet2[30];
    memset(vet, 0, 30);     //Zera um vetor
    int i;


    
    for(i = 0; i < 30; i++){    //Preenche os vetores com numeros de 1 ate 30
        vet[i] = i+1;
        vet1[i] = i+1;
        vet2[i] = i+1;
    }

    
    printf("Vetor usado: ");
    printvet(vet);
    printf("\nValor do vetor com numeros pares zerados: ");
    zeraPares(&vet);
    printf("\nValor do vetor dobrado: ");
    dobra(&vet);
    printf("\nSoma de dois vetores: ");
    soma(&vet1, &vet2);
    printf("\n");

    system("pause");
    return 0;
}