#include <stdio.h>
#include <math.h>   
#include <stdlib.h>


float funmaior(float usernum){
    float increment;
    float result;
    while(increment < 100){
        increment++;
        result = result + ((usernum+increment)/increment);        
    }
    return result;
}

float funmenor(float usenum){
    int increment;
    float result;
    float divisorIncrement = 100;
    while(increment < 100){
      if(increment % 2 == 0){
        increment++;
        result = result + ((pow(usenum, 2)+increment)/divisorIncrement);
        divisorIncrement--;
      }
      if(increment % 2 == 1){
        increment++;
        result = result - ((pow(usenum, 2)+increment)/divisorIncrement);
        divisorIncrement--;
      }      
    }
    return result; 
}


int main(){
    float num;
    printf("Entre com um numero: \n");
    scanf("%f", &num);

    if(num > 0){
        printf("Resultado: %.2f\n", funmaior(num));
    }
    if(num <= 0){
        printf("Resultado: %.2f\n", funmenor(num));       
    }

    system("pause");
    return 0;
}



