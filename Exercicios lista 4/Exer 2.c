#include <stdio.h>

int main(){
    int vet1[10] = {0,1,2,3,4,5,6,7,8,9};
    int vet2[10] = {10,11,12,13,14,15,16,17,18,19};
    int vet3[20];
    int i = 0, j = 0;
    int k = 19;

   for(i = 0; i < 20 && j < 10 & j < 10; i = i + 2){
       vet3[i] = vet1[j];
       vet3[i+1] = vet2[j];
       j++;
    }
    
    printf("O vetor: ");
    for(k = 19; k > -1; k--){
        printf("%d ", vet3[k]);
    }

    return 0;
}