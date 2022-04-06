#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>



typedef struct{
    char nome[80];
    int idade;
    char curso[30];
    float cr;
    int matricula;
}aluno;

typedef struct{
    aluno discente;
    float nota;
    int falta;
}alunomat;


typedef struct{
    int codigo;
    char nomedis[50];
    alunomat turma[40];
}disciplina;



void criardisciplina(disciplina *disc){
    setlocale(LC_ALL, "Portuguese");
    int i;
    printf("Entre com o nome da disciplina: ");gets(disc->nomedis);
    printf("Entre com o codigo da disciplina: ");scanf("%d", &disc->codigo); 
    for(i = 0; i < 40; i++){
        disc->turma[i].discente.matricula = 0;
    }
   
    

}



int main(){
    int i;
    disciplina disc;
    setlocale(LC_ALL, "Portuguese");
    criardisciplina(&disc);
    printf("%s\n", disc.nomedis);
    for(i = 0; i<40; i++){
        printf("%d", disc.turma[i].discente.matricula);
    }
}