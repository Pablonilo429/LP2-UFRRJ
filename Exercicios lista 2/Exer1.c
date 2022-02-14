#include <stdio.h>
#include <stdlib.h>

int main(){
    int num;
    int div;
    int result;
    int mod;   

    do
    {
        printf("Entre com um numero: \n");
        scanf("%d", &num);
        div = num; 
        while(div > 0){          
            result = num/div;
            mod = num % div;     
            div--;
            if(mod == 0){
                printf("Os divisores sao: %d\n", result);
            }   
        }           
    } while (num >= 0);
    
    system("pause");
    return 0;    
}





