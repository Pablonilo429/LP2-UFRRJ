#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

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
    int i;
    FILE *f;
    
    f = fopen("disciplina.txt", "a");

    if(f == NULL){
        puts("Não foi possivel abrir o arquivo!");
    }
    else{
    
        fflush(stdin);
        fputs("Informações da Disciplina:\n", f);
        printf("Entre com o nome da disciplina:\n");fgets(disc->nomedis,51,stdin);
        fprintf(f,"\nNome da discipllina: %s", disc->nomedis); 
        fflush(stdin);
        printf("Entre com o código da disciplina:\n");scanf("%d", &disc->codigo);
        fprintf(f,"Codigo da disciplina: %d\n", disc->codigo);

        fclose(f);
    }
    for(i = 0; i < 40; i++){    //Zerando as matriculas da turma
        disc->turma[i].discente.matricula = 0;
    }   
}

void incluiraluno(disciplina *disc){    //Inclui aluno na disciplina
    int i;
    int contador;
    FILE *g;

    g = fopen("alunos.txt", "a+");

    if(g == NULL){
        puts("Não foi possivel abrir o arquivo!");
    }
    else{
        for(i = 0; i < 40; i++){
            if(disc->turma[i].discente.matricula == 0){     //Percorrer turma e adiciona o aluno 
                fflush(stdin);      //Zera os buffers do teclado para a funcao fgets funcionar
                fputs("\nInformações do aluno:\n",g);
                printf("\nEntre com o nome do aluno: "); fgets(disc->turma[i].discente.nome,81,stdin);
                fprintf(g,"\nNome do aluno: %s", disc->turma[i].discente.nome);
                printf("\nEntre com a idade do aluno: "); scanf("%d", &disc->turma[i].discente.idade);
                fflush(stdin);
                fprintf(g,"Idade do aluno: %d\n", disc->turma[i].discente.idade);
                printf("\nEntre com o curso do aluno: \n"); fgets(disc->turma[i].discente.curso,51,stdin);
                fprintf(g,"Curso do aluno: %s\n", disc->turma[i].discente.curso);
                printf("\nEntre com o numero da matrícula: \n"); scanf("%d", &disc->turma[i].discente.matricula);
                fprintf(g,"Matrícula do aluno: %d\n", disc->turma[i].discente.matricula);
                printf("\nEntre com o CR do aluno(Digite com virgula!):"); scanf("%f", &disc->turma[i].discente.cr);
                fprintf(g,"CR do aluno: %.2f\n", disc->turma[i].discente.cr);
                fclose(g);
                break;
            }
            else{
                contador++;
            }
        }
        if(contador == 40){     //Se todos os campos da matricula estiverem preenchidos mostra um aviso
            puts("Não há vagas na disciplina");
        }
    }
}

void excluiraluno(disciplina *disc){    //Exclui aluno da disciplina
    int i;
    int matric;
    char confirm;
    fflush(stdin);
    printf("\nEntre com a matrícula: ");scanf("%d", &matric);
    puts("Entre com \"s\" para excluir a matrícula");
    fflush(stdin);
    scanf("%c", &confirm);
    if(confirm == 's'){
        for(i = 0; i<40; i++){      //Encontra a matricula e zera
            if(disc->turma[i].discente.matricula == matric){
                disc->turma[i].discente.matricula = 0;
                break;
            }
            if(i == 39){        //Caso não exista matrícula na turma

                puts("Matricula invalida");
            }
        }
        puts("Processo concluído!");
    }
    else{
        puts("Processo cancelado!");
    }
}

void listaraluno(disciplina *disc){
    int i;
    FILE *f;
    char c;

    f = fopen("alunos.txt", "r");

    if(f == NULL){
        puts("Não foi possivel abrir o arquivo");
    }
    else{
        c = fgetc(f);
        while(c != EOF){
            printf("%c",c);
            c = fgetc(f);
        }
    }

    fclose(f);
}

void calcularcrm(disciplina *disc){
    int i;
    float crm = 0;
    int contador = 0;
    for(i = 0; i < 40; i++){
        if(disc->turma[i].discente.matricula != 0){     //Calcula o CR medio conforme o numero de alunos
            contador++;
            crm = crm + disc->turma[i].discente.cr;
        }
    }
    printf("\nCR médio dos alunos da disciplina: %.2f\n", crm/contador);
} 

void imprimirboletim(disciplina *disc){
   int i;
    int posi = 0;
    FILE *f;

    f = fopen("boletins.txt", "a+");

    if(f == NULL){
        puts("Não foi possivel abrir o arquivo!");
    }
    else{
        for(i = 0; i < 40; i++){
            if(disc->turma[i].discente.matricula != 0){ 
                posi++;
                printf("%d - Nome de aluno: %s | Curso: %s | Matrícula: %d | Faltas: %d | Nota: %.1f\n", posi, disc->turma[i].discente.nome, disc->turma[i].discente.curso, 
                disc->turma[i].discente.matricula, disc->turma[i].falta, disc->turma[i].nota);
                fprintf(f, "%d - Nome do Aluno: %s | Idade: %d | Curso: %s | Cr: %.2f | Matricula: %d | nota: %.2f | faltas : %d\n",posi, disc->turma[i].discente.nome, disc->turma[i].discente.idade,
                disc->turma[i].discente.curso, disc->turma[i].discente.curso, disc->turma[i].discente.cr, disc->turma[i].discente.matricula, disc->turma[i].nota, disc->turma[i].falta);

            }
        }
    }

    fclose(f);
}

void fechardisc(disciplina *disc){
    int i;
    char confirm;
    fflush(stdin);
    puts("Confirme com \"s\" para fechar a disciplina");
    scanf("%c", &confirm);
    if(confirm == 's'){
        disc->codigo = ' ';     //Limpa a variavel codigo
        strcpy(disc->nomedis," ");  //Limpa o array de char 
        for(i = 0; i < 40; i++){
            disc->turma[i].discente.matricula = 0;  //Zera a matricula dos alunos
        }
        puts("Disciplina fechada com êxito!");
    }
    else{
        puts("Processo cancelado!");
    }
}

int main(){
    setlocale(LC_ALL,"Portuguese");
    int opcao;
    disciplina disc;
    do
    {
        fflush(stdin);
        puts("Digite o número correspondente a cada opção para acessar");
        puts("1 - Criar Disciplina");
        puts("2 - Incluir Aluno");
        puts("3 - Excluir Aluno");
        puts("4 - Listar Alunos");
        puts("5 - Calcular CR Médio");
        puts("6 - Imprimir Boletim");
        puts("7 - Fechar Disciplina");
        puts("8 - Sair");

        scanf("%d", &opcao);
        system("cls || clear");

        switch (opcao)
        {
        case 1:
            puts("Opção \"Cria Disciplina\" selecionada!");
            criardisciplina(&disc);
            break;
        case 2:
            puts("Opção \"Incluir Aluno\" selecionada!");
            incluiraluno(&disc);
            break;
        case 3:
            puts("Opção \"Excluir Aluno\" selecionada!");
            excluiraluno(&disc);
            break;
        case 4:
            puts("Opção \"Listar Aluno\" selecionada!");
            listaraluno(&disc);
            break;
        case 5:
            puts("Opção \"Calcular CR Médio\" selecionada!");
            calcularcrm(&disc);
            break;
        case 6:
            puts("Opção \"Imprimir Boletim\" selecionada!");
            imprimirboletim(&disc);
            break;
        case 7:
            puts("Opção \"Fechar Disciplina\" selecionada!");
            fechardisc(&disc);
            break;
        case 8:
            break;
        default:
            puts("Opção Inválida");
            break;
        }

        system("pause");
    } while (opcao != 8);

    puts("Obrigado por ver o meu código ;)");
    puts("By Nilopolitana");
    system("pause");
    return 0;
}