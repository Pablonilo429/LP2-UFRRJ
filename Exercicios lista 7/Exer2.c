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
    
    f = fopen("disciplina.dat", "wb");

    if(f == NULL){
        puts("Não foi possivel abrir o arquivo!");
    }
    else{
    
        fflush(stdin);
        printf("Entre com o nome da disciplina:\n");fgets(disc->nomedis,51,stdin); 
        fflush(stdin);
        printf("Entre com o código da disciplina:\n");scanf("%d", &disc->codigo);
        fwrite(&disc->nomedis, sizeof(disciplina), 1, f);
        fwrite(&disc->codigo, sizeof(disciplina),1, f);
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

    g = fopen("alunos.dat", "ab");

    if(g == NULL){
        puts("Não foi possivel abrir o arquivo!");
    }
    else{
        for(i = 0; i < 40; i++){
            if(disc->turma[i].discente.matricula == 0){     //Percorrer turma e adiciona o aluno 
                fflush(stdin);      //Zera os buffers do teclado para a funcao fgets funcionar
                printf("\nEntre com o nome do aluno: "); fgets(disc->turma[i].discente.nome,81,stdin);
                printf("\nEntre com a idade do aluno: "); scanf("%d", &disc->turma[i].discente.idade);
                fflush(stdin);
                printf("\nEntre com o curso do aluno: \n"); fgets(disc->turma[i].discente.curso,51,stdin);
                printf("\nEntre com o numero da matrícula: \n"); scanf("%d", &disc->turma[i].discente.matricula);
                printf("\nEntre com o CR do aluno(Digite com virgula!):"); scanf("%f", &disc->turma[i].discente.cr);
                fwrite(&disc->turma[i].discente, sizeof(aluno), 1,g);
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
    int i = 0;
    int j = 0;
    FILE *f;
    aluno imprime;


    f = fopen("alunos.dat", "rb");

    if(f == NULL){
        puts("Não foi possivel abrir o arquivo");
    }
    else{
        while(!feof(f)){
            j = fread(&imprime, sizeof(aluno),1,f);
            if(j){
                printf("Aluno: %s | ", imprime.nome);
                printf("Idade: %d anos | ", imprime.idade);
                printf("Curso: %s | ", imprime.curso);
                printf("Matricula: %d | ", imprime.matricula);
                printf("CR: %.2f ", imprime.cr);
                printf("\n");
            }                 
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

    f = fopen("boletins.dat", "wb");

    if(f == NULL){
        puts("Não foi possivel abrir o arquivo!");
    }
    else{
        for(i = 0; i < 40; i++){
            if(disc->turma[i].discente.matricula != 0){ 
                posi++;
                printf("%d - Nome de aluno: %s | Curso: %s | Matrícula: %d | Faltas: %d | Nota: %.1f\n", posi, disc->turma[i].discente.nome, disc->turma[i].discente.curso, 
                disc->turma[i].discente.matricula, disc->turma[i].falta, disc->turma[i].nota);
                fwrite(&disc->turma[i],sizeof(alunomat),1, f);

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