#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#pragma setlocale(LC_ALL,"Portuguese")

typedef struct{       
    char nome[81];
    int idade;
    char curso[51];
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
    char nomedis[51];
    alunomat turma[40];
}disciplina;

void criardisciplina(disciplina *disc){     //Funcao para criar a disciplina
    setlocale(LC_ALL, "Portuguese");
    int i;
    printf("Entre com o nome da disciplina: ");fgets(disc->nomedis,50,stdin); 
    printf("\nEntre com o código da disciplina: ");scanf("%d", &disc->codigo); 
    for(i = 0; i < 40; i++){    //Zerando as matriculas da turma
        disc->turma[i].discente.matricula = 0;
    }   
}

void incluiraluno(disciplina *disc){    //Inclui aluno na disciplina
    int i;
    int contador;  
    for(i = 0; i < 40; i++){
        if(disc->turma[i].discente.matricula == 0){     //Percorrer turma e adiciona o aluno 
            fflush(stdin);      //Zera os buffers do teclado para a funcao fgets funcionar
            printf("\nEntre com o nome do aluno: "); fgets(disc->turma[i].discente.nome,80,stdin);
            printf("\nEntre com a idade do aluno: "); scanf("%d", &disc->turma[i].discente.idade);
            fflush(stdin);
            printf("\nEntre com o curso do aluno: "); fgets(disc->turma[i].discente.curso,50,stdin);
            printf("\nEntre com o numero da matrícula: "); scanf("%d", &disc->turma[i].discente.matricula);
            printf("\nEntre com o CR do aluno: "); scanf("%f", &disc->turma[i].discente.cr);
        }
        else{
            contador++;
        }
    }
    if(contador == 40){     //Se todos os campos da matricula estiverem preenchidos mostra um aviso
        puts("Não há vagas na disciplina");
    }
}

void excluiraluno(disciplina *disc){    //Exclui aluno da disciplina
    int i;
    int matric;
    scanf("%d", &matric);
    for(i = 0; i<40; i++){      //Encontra a matricula e zera
        if(disc->turma[i].discente.matricula == matric){
            disc->turma[i].discente.matricula = 0;
        }
        else{
            puts("Matricula inexistente");      //Exibe quando nao acha a matricula
        }
    }
}

void listaraluno(disciplina *disc){
    int i;
    int posi;
    for(i = 0; i < 40; i++){
        if(disc->turma[i].discente.matricula != 0){
            posi++;
            printf("%d - Nome do Aluno: %s | Idade: %d | Curso: %s | Cr: %.2f | Matrícula: %d\n",posi, disc->turma[i].discente.nome, disc->turma[i].discente.idade,
            disc->turma[i].discente.curso, disc->turma[i].discente.cr, disc->turma[i].discente.matricula);
        }
    }
}

void calcularcrm(disciplina *disc){
    int i;
    float crm;
    int contador;
    for(i = 0; i < 40; i++){
        if(disc->turma[i].discente.matricula != 0){
            contador++;
            crm = crm + disc->turma[i].discente.cr;
        }
    }
    printf("\nCR médio dos alunos da disciplina: %.2f\n", crm/contador);

} 

void imprimirboletim(disciplina *disc){
    int i;
    int posi = 0;
    for(i = 0; i < 40; i++){
        if(disc->turma[i].discente.matricula != 0){
            posi++;
            printf("%d - Nome de aluno: %s | Curso: %s | Matrícula: %d | Faltas: %d | Nota: %.1f\n", posi, disc->turma[i].discente.nome, disc->turma[i].discente.curso, 
            disc->turma[i].discente.matricula, disc->turma->falta, disc->turma->nota);
        }
    }
}

void fechardisc(disciplina *disc){
    int i;
    disc->codigo = ' ';
    strcpy(disc->nomedis," ");
    for(i = 0; i < 40; i++){
        disc->turma[i].discente.matricula = 0;
    }
    puts("Disciplina fechada com êxito!");
}




int main(){
    setlocale(LC_ALL, "Portuguese_Brazil.ACP");
    puts("cachaça pímba");
}