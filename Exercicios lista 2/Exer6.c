#include <stdio.h>
#include <stdlib.h>

int main(){
    double paisA;
    double paisB;
    int ano;
    paisA = 5000000.0;
    paisB = 7000000.0;


    while(paisA <= paisB){
        paisA = paisA+(paisA*0.03);
        paisB = paisB+(paisB*0.02);
        ano++;       
    }
    
    printf("A populacao do paisA vai ultrapassar o paisB em: %d anos\n", ano);

    system("pause");
    return 0;
}