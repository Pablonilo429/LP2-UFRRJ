#include <stdio.h>
#include <stdlib.h>




int main(){
    float m[4][5] = {{5.5,4,7.5,6,2}, {10,5.8,3.3,7,9}, {4,7,10,6,8}, {4,2,3,11,4}};
    float dobro[4][5];
    float soma[4][5];
    int i = 0;
    int j = 0;
  
    for(i = 0; i < 4; i++){
        for(j = 0; j < 5; j++){
            dobro[i][j] = m[i][j]*2;                
        }
    }


    for(i = 0; i < 4; i++){
        for(j = 0; j < 5; j++){
            soma[i][j] = m[i][j]+dobro[i][j];
        }
    }

    printf("A matriz dobro: \n");

    for(i = 0; i < 4; i++){          
       for(j = 0; j < 5; j++){           
           printf("%.1f, ", dobro[i][j]);
        }
       printf("\n");
    }
   


    printf("\nA matriz soma: \n");

   for(i = 0; i < 4; i++){          
       for(j = 0; j < 5; j++){           
           printf("%.1f, ", soma[i][j]);
        }
       printf("\n");
    }
   system("pause");
   return 0;

}




