#include <stdio.h>
#include <stdlib.h>

int main(){
    int mat[3][5] = {{3,4,5,8,2},{2,4,1,7,9},{10,34,23,2,4}};
    int vet[3];
    int i = 0;
    int j = 0;
    int k = 0;

    for(i = 0; i < 3; i++){     //Soma as linhas da matriz e jogo pra dentro de um vetor
        for(j = 0; j < 5; j++){
            vet[k] = vet[k] + mat[i][j];
        }
        k++;
    }

    printf("A matriz: \n"); //Imprime a matriz

    for(i = 0; i < 3; i++){          
       for(j = 0; j < 5; j++){           
           printf("%d ", mat[i][j]);
        }
       printf("\n");
    }    

    printf("\nA soma das linhas da matriz:\n");

    for( i = 0; i < 3; i++){    //Imprime o vetor
        printf("%d ", vet[i]);
    }
    system("pause");
    return 0;
}

