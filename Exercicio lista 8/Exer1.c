#include <stdio.h>
#include <stdlib.h>
typedef struct 
{
    int x;
    int y;
    int z;
}tpPonto;

typedef struct{
    tpPonto ponto;
    char rotulo;
}tpFigura;

void preenche(tpFigura *var){
    FILE *f;
    int i = 0;
    

    f = fopen("desenho.dat", "wb");
    if (f == NULL)
        printf("\nErro, nao foi possivel abrir o arquivo!");
    else {
        for(i = 0;i < 10 ;i++){
            fflush(stdin);
            puts("Entre com o rotulo: ");
            scanf("%c", &var[i].rotulo);
            puts("Entre com o ponto X: ");
            scanf("%d", &var[i].ponto.x);
            puts("Entre com o ponto Y: ");
            scanf("%d", &var[i].ponto.y);
            puts("Entre com o ponto Z: ");
            scanf("%d", &var[i].ponto.z);
            fwrite(&var[i],sizeof(tpFigura),1,f);
            
        }
    }
    fclose(f);

}

void imprime(){
    FILE *g;
    tpFigura aux[10];
    int i = 0;
 

    g = fopen("desenho.dat", "rb");
    if (g == NULL){
        printf("\nErro, nao foi possivel abrir o arquivo!");
    }
    else{
        
        for(i = 0; i < 10; i++){
            fseek(g,0, SEEK_SET);
            fread(&aux[i], sizeof(tpFigura), 1, g);
            

            printf("Ponto %c: x = %d, y = %d, z = %d ", aux[i].rotulo, aux[i].ponto.x, aux[i].ponto.y, aux[i].ponto.z); 
        }
    }
    
    fclose(g);
    
}
void apaga(tpFigura *var, char letra){
    FILE *h;
    int i;
    tpFigura aux;
    
 

    h = fopen("desenho.dat", "rb+");
    if (h == NULL){
        printf("\nErro, nao foi possivel abrir o arquivo!");
    }
    else{
        for(i = 0; i < 10; i++){
            if(var[i].rotulo == letra){
               
                var[i].rotulo = '#';
                fseek (h, i*sizeof(tpFigura), SEEK_SET);
                fwrite (&var[i].rotulo, sizeof(tpFigura),1,h);
                break;
                
            }
        }
        
        
    }   
    fclose(h);
}


int main(){
    tpFigura espacoR3[10];
    char letra;
    
    
    preenche(&espacoR3);
    imprime();
    puts("Entre com o retulo a ser excluido: ");
    fflush(stdin);
    scanf("%c", &letra);
    apaga(&espacoR3, letra);
    puts("Obrigado por ver o meu codigo ;)");
    puts("By Nilopolitana - Pablo");

    system("pause");
    return 0;
}