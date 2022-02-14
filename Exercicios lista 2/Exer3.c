#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int idade;
    int somaIdade;
    int contador = 0;
    int contadorMedia;

    printf("Entre com a sua idade: \n");
    scanf("%d", &idade);

    while(idade > 0){
        if(idade > 21){
            contador++;
        }
        if(idade > 60){
            contadorMedia++;
            somaIdade = somaIdade + idade;
        }
        printf("Entre com a sua idade: \n");
        scanf("%d", &idade);
        
    }    
    printf("Pessoas maiores de 21 anos: %d\n", contador);
    if(contadorMedia == 0){
        printf("Nao ha pessoas com mais de 60 anos \n");
    }
    printf("Media das pessoas com mais de 60 anos: %d\n", somaIdade/contadorMedia);

    system("pause");
    return 0;
}