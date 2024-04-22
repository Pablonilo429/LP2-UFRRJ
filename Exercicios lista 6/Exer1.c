#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int dia;
    int mes;
    int ano;
}data;

void inicializa(data *dt, int dia, int mes, int ano){
    dt->dia = dia;
    dt->mes = mes;
    dt->ano = ano;
}

int valida(data dt){
    int verifica;   //1 para valor invalido e 0 para valor valido
    if(dt.ano < 1){
        verifica = 1;
    }
    else if(dt.dia > 31 || dt.dia < 1){  //Verifica se dia e valido    
        verifica = 1;
    }
    else if(dt.mes > 12 || dt.mes < 1){      //Verifica se o mes esta correto
        verifica = 1;
    }   
    else if(dt.dia == 29 && dt.mes == 2 && dt.ano % 4 == 0){    //Verifica se o ano e bissexto 
        verifica = 0;         
    }
    else if(dt.dia >= 29 && dt.mes == 2){   //Verifica se o mes de fevereiro tem mais de 28 dias
        verifica = 1;
    }  
    else if(dt.dia > 30 && (dt.mes == 4 || dt.mes == 6 || dt.mes == 9 || dt.mes == 11) ){  //Verifica os meses que possuem 30 dias
        verifica = 1;
    }
    else{
        verifica = 0;
    }  
    return verifica;
}

void imprime(data dt){
    printf("Data: %d/%d/%d", dt.dia, dt.mes, dt.ano);
}


int main(){
    data dt;
    int dia;
    int mes;
    int ano;
    int verifica;

    puts("Entre com o dia: ");
    scanf("%d", &dia);
    puts("Entre com o mes: ");
    scanf("%d", &mes);
    puts("Entre com o ano: ");
    scanf("%d", &ano);

    inicializa(&dt, dia, mes, ano);
    verifica = valida(dt);
    if(verifica == 1){
        puts("Data invalida");
    }
    else{
        imprime(dt);
    }

    system("pause");
    return 0;

}