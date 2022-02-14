#include <stdio.h>
#include <stdlib.h>

int main(){
    int num;
    int multi = 100;
    int result;
    printf("Entre com um numero menor que 10 \n");
    scanf("%d", &num);
    if (num >= 10)
    {
        printf("Erro: numero maior ou igual a 10 \n");
        multi = -1;  
    }
       
    while(multi >= 0){                      
        result = num * multi;
        multi--;
        if(result <= 100){
            printf("%d\n", result);
        }
    }
    system("pause");
    return 0;    
}
