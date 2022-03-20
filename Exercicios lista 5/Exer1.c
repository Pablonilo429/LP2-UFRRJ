#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void maiuscula(char *str1){  //Transforma uma string em maiuscula
    int i;
    for(i = 0; i < 30; i++){
        if(str1[i] == '\0' && str1[i+1] == '\0'){
            break;
        }
        str1[i] = toupper(str1[i]);
    }
    printf("%s", str1);
}

void concatena(char *str1, char *str2){  //Concatena duas strings
    printf("%s",strncat(str1, str2, 60));   
}



int main(){
    char str1[30];
    char str2[30];
    
    gets(str1);
    gets(str2);
    
    maiuscula(&str1);
    concatena(&str1, &str2);

    


}
