#include <stdio.h>
#include <stdlib.h>

int main(){
    int dividendo;
    int divisor;
    int quociente = 1;
    int resto;
    
    printf("Entre com o dividendo \n");
    scanf("%d", &dividendo);
    printf("Entre com o divisor \n");
    scanf("%d", &divisor);

    if(divisor == 0){
        printf("Nao e possivel dividir por 0 \n");
        system("pause");
        exit(1);
    }

    resto = dividendo - divisor;

    while(resto >= divisor){
        quociente++;
        resto = resto - divisor;        
    }   
    
    printf("Quociente: %d\n", quociente);
    printf("Resto: %d\n", resto);

    system("pause");
    return 0;
}