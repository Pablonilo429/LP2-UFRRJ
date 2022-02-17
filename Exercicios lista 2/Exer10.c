#include <stdio.h>
#include <stdlib.h>

int main(){
    float saldo = 60.00;
    float valTrans;
    float tax = 2.00;
    int conta = 223;
    int trans;
    int quantTrans = 0;
    int parada = 1;
    
    while(parada != 0){
        printf("Valor minimo diario = R$ 30.00\nQuantidade de transacoes: %d\nTaxa de servico: %.2f\n", quantTrans, tax);
        printf("Conta: %d\n", conta);
        printf("Selecione: 1 - Deposito e 2 - Retirada\n");
        scanf("%d", &trans);
        if(trans == 1){
            printf("Entre com o valor do deposito: \n");
            scanf("%f", &valTrans);
            printf("Foi adicionado: +R$ %.2f\n", valTrans);
            saldo = saldo + valTrans;
        }
        if(trans == 2){
            printf("Entre com o valor da retirada: \n");
            scanf("%f", &valTrans);
            if(saldo < valTrans){
                printf("Fundos insuficientes para retirada! \n");
                continue;
            }
            printf("Foi subtraido: -R$ %.2f\n", valTrans);
            saldo = saldo - valTrans;
        }
        if(saldo < 30){
            printf("Taxa cobrada! Saldo abaixo de R$ 30.00\n");
            saldo = saldo - tax;
        }
        quantTrans++;
        printf("Deseja encerrar o dia? Digite 0 para encerrar\n");
        scanf("%d", &parada);

    }

    printf("Saldo no fim do dia: %.2f\n", saldo);
    if(saldo < 0){
        printf("Nao ha fundos\n");
        printf("Conta: %d", conta);
    }
    
    system("pause");
    return 0;
}