#include <stdio.h>
#include <stdlib.h>
#include <math.h>


float maiorig(float usernum){
    float result;
    result = sqrt(usernum-10)/2;
    return result;
}

float menorig(float usernum){
    float result;
    result = sqrt(pow(usernum,2)+1)/2;
    return result;
}

float maiorMenorig(float usernum){
    float result;
    float val1;
    val1 = pow(usernum,2)-16;
    return result = pow(usernum,3)/val1;
} 

float func(float usernum){
    if(usernum >= 10){
        return maiorig(usernum);
    }
    if(usernum <= 4){
        return menorig(usernum);
    }
    if(usernum > 4 && usernum < 10){
       return maiorMenorig(usernum);
    }    
}

int main(){
    int num = 1;

    printf("Entre com um numero:\n");
    scanf("%d", &num);        

    while(num > 0){
    printf("Resultado: %.2f\n", func(num));
    printf("Entre com um numero:\n");
    scanf("%d", &num);
    }

    system("pause");
    return 0;

}





