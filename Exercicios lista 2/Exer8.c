#include <stdio.h>
#include <stdlib.h>

int main(){
    int num;
    int multiplicador;
    int result;
    printf("Entre com um numero: \n");
    scanf("%d", &num);

    while(multiplicador < 10){
        multiplicador++;
        result = num * multiplicador;
        printf("%d X %d = %d \n", num, multiplicador, result);
    }

    system("pause");
    return 0;
}