#include <stdio.h>
#include <stdlib.h>

int funpar(int usernum){
    int n = usernum;
    int div;
    int quantDiv = 0;
    div = n;

    for(div = n; div != 0; div--){
        if(n % div == 0){
            quantDiv++;
        }
    }
    return quantDiv;
}

int funimpmenor(int usernum){
    int n = usernum;
    if((n==1) || (n==0)){
        return 1;
    }
    else{
        return funimpmenor(n-1)*n;
    }    
}

int funimpmaior(int usernum){
    int contador;
    int result = 0;
    for(contador=0; contador != usernum; contador++){
        result = result + contador;
    }
    return result;
}


int main(){
    int num;
    int compara;

    while(num > 0){

        printf("Entre com um numero: \n");
        scanf("%d", &num);

        if(num % 2 == 0){
        compara = 1;
        }
        else if(num > 10){
        compara = 3;
        }
        else{
        compara = 2;
        }

        switch(compara)
        {
            case 1:
                printf("Numero de divisores possiveis para %d: %d\n", num, funpar(num));
            break;
            case 2:
                printf("A fatorial de %d = %d\n", num, funimpmenor(num));
            break;
            case 3:
                printf("Soma dos numeros entre 1 ate %d = %d\n", num, funimpmaior(num));              
            break;
            default:
                printf("Numero nao aceito \n");
            break;    
        }

    }
    system("pause");
    return 0;

}






