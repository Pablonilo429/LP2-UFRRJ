#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int fat (n){    //Calcula fatorial
    if((n==1) || (n==0)){
        return 1;
    }
    else{
        return fat(n-1)*n;
    }    
}

int pot(int base, int expoente){    //Calcula potenciacao
    int valor;
    if(expoente == 0){
        valor = 1;
    }
    else{
        valor = base * pot(base, expoente-1);
    }
    return valor;
}

int multi(int num1, int num2){  //Calcula multiplicacao por somas sucessivas
    int valor;
    if((num1 == 0)||(num2 ==0)){
        valor = 0;
    }
    else{
        valor = num1 + multi(num1,num2-1);
    }
    return valor;
}

int mod(int num1, int num2){    //Calcula mod
    int valor;
    if(num1 == 0 || num2 == 1){
        valor = 0;
    }
    else if(num1 < num2){
        valor = num1;
    }
    else{
        valor = mod(num1-num2, num2);
    }
    return valor;
}

int fib(int num){   //Calcula fibonacci
    int valor;
    if(num == 1 || num == 2){
        return 1;
    }
    else{  
    valor = fib(num - 1) + fib(num - 2);  
    return valor;
    }
}




int main(){
    char option[4] = "fim";
    char optionUser[4];
    int result = 1;
    int numfat;
    int base;
    int expoente;
    int fator_1;
    int fator_2;
    int dividendo;
    int divisor;
    int termsfib;
    int i;

    while(result != 0){   
        printf("Entre com um numero para calcular fatorial: \n");
        scanf("%d", &numfat);
        printf("Fatorial de %d = %d\n", numfat, fat(numfat));
        printf("Entre com dois numero para calcular a potenciacao: \nBase: \n");
        scanf("%d", &base);
        printf("Expoente: \n");
        scanf("%d", &expoente);
        printf("%d elevado a %d = %d\n", base, expoente, pot(base, expoente));
        printf("Entre com dois numeros para calcular a multiplicacao: \nFator_1: \n");
        scanf("%d", &fator_1);
        printf("Fator_2: \n");
        scanf("%d", &fator_2);
        printf("Resultado de: %d X %d = %d\n",fator_1, fator_2, multi(fator_1,fator_2));
        printf("Entre com dois numeros para calcula o mod: \nDividendo: \n");
        scanf("%d", &dividendo);
        printf("Divisor: \n");
        scanf("%d", &divisor);
        printf("Resultado de: %d mod %d = %d",dividendo, divisor, mod(dividendo, divisor));
        printf("Entre com a quantidade de termos da sequencia de fibonacci: \n");
        scanf("%d", &termsfib);
        printf("Resultado da sequencia: \n");
        for(i=0; i < termsfib; i++){
            printf("%d ", fib(i+1));
        }
        printf("Se deseja encerrar o programa digite \"fim\", caso queira continuar entre com qualquer caracter \n");
        scanf("%s", optionUser);
        result = strcmp(option, optionUser);
    }
    system("pause");
    return 0;
}
    