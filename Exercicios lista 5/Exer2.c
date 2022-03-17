#include <stdio.h>
#include <stdlib.h>

void zeraPares(int *vet[]){
    int i;
    
    for(i = 0; i < 30; i++){
        if(vet[i] % 2 == 0){
            vet[i] = 0;
        }
    }
}

void dobra(int *vet[]){
    int i;

    for(i = 0; i < 30; i++){
        vet[i] = vet[i] * 2;
    }
}