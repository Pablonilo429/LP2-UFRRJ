#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void maiuscula(char *str1){  //Transforma uma string em maiuscula
    int i;
    int taman = strlen(str1);
    for(i = 0; i < taman; i++){
        str1[i] = toupper(str1[i]);
    }
    printf("%s", str1);
}

void concatena(char *str1, char *str2){  //Concatena duas strings
    printf("%s",strncat(str1, str2, 60));   
}

int capitaliza(char *str){      //Contador de string e troca por maiusculo
    int i;
    int contador = 0;
    int taman = strlen(str);    
    for(i = 0; i < taman; i++){
        if(i == 0){
            str[i] = toupper(str[i]);
        }
        if(str[i] == ' '){
            str[i+1] = toupper(str[i+1]);
            contador++;
        }
    }
    taman = taman - contador;
    return taman;
}

int compara(char *str1, char *str2){
    int comp = strcmp(str1, str2);
    return comp;
}


int main(){
    char str1[30];
    char str2[30];
       
    printf("Entre com duas strings:\n");
    gets(str1);
    gets(str2);
    
    maiuscula(&str1);
    printf("\n");
    concatena(&str1, &str2); 
    printf("\nNumero de caracteres: %d\n", capitaliza(&str2));
    printf("%s\n", str2);

    memset(str1, 0, 30);
    memset(str2, 0, 30);

    printf("Entre novamente com duas strings:\n");
    gets(str1);
    gets(str2);

    switch(compara(&str2, &str1))
    {
        case -1: 
            printf("A primeira string e menor que a segunda string\n");
        break;
        case 0: 
            printf("A primeira string e igual a segunda string\n");
        break;
        case 1: 
            printf("A primeira string e maior que a segunda string\n");
        break; 
    }
    
    system("pause");
    return 0;
}
