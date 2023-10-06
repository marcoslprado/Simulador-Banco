#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

struct Conta {
    char nomeCliente[100];
    int numeroConta;
    float saldo;
    int ativo;
};
void Cadastro(struct Conta vetor[], int i) {
    printf("Qual o nome do cliente? ");
    scanf("%s", &vetor[i].nomeCliente);
    vetor[i].numeroConta = i+1;
    printf("Digite o saldo da conta para cadastro: ");
    scanf("%f", &vetor[i].saldo);
    vetor[i].ativo = 1;
    i++;
}

void Busca(struct Conta vetor[], int numContas, char nomeBusca[]) {
    int achei = 0;
    for (int i = 0; i < numContas; i++) {
        if (vetor[i].ativo == 1) {
           if (strcmp(vetor[i].nomeCliente, nomeBusca) == 0) {
            printf("|=====================================================|\n");
            printf("|----------------------CONTA %d------------------------|\n", vetor[i].numeroConta);
            printf("|=====================================================|\n");
            printf("               Nome do cliente: %s\n", vetor[i].nomeCliente);
            printf("               Saldo: %.2f\n", vetor[i].saldo);
            printf("|=====================================================|\n");
            achei = 1;
            }
        }
    }
    if (achei == 0) {
        printf("Nenhuma conta desse cliente foi encontrada.");
    }
}

void Exclusao(struct Conta vetor[], int numContas) {
    if (numContas == 0) {
        printf("Nao existem contas para excluir.");
        Sleep(3000);
    }
    float saldoMenor = 99999999999999999999;
    for (int i = 0; i < numContas; i++) {
        if (vetor[i].saldo < saldoMenor && vetor[i].ativo == 1) {
            saldoMenor = vetor[i].saldo;
        }
    }
    if (saldoMenor == 99999999999999999999) {
        printf("Nao existem contas para excluir.");
        Sleep(3000);
    }
    for (int i = 0; i < numContas; i++) {
        if (vetor[i].saldo == saldoMenor && vetor[i].ativo == 1) {
            vetor[i].ativo = 0;
            printf("A conta de saldo %.2f foi excluida com sucesso!", saldoMenor);
            Sleep(3000);
        }
    }

}

void main() {
    struct Conta vetor[15];
    int numContas = 0;
    int opcao;
    char nomeBusca[100];
    while (opcao != 4) {
        for (int i = 0; i < 2; i++) {
            printf("o------");
            Sleep(100);
            system("cls");
            printf("-o-----");
            Sleep(100);
            system("cls");
            printf("--o----");
            Sleep(100);
            system("cls");
            printf("---o---");
            Sleep(100);
            system("cls");
            printf("----o--");
            Sleep(100);
            system("cls");
            printf("-----o-");
            Sleep(100);
            system("cls");
            printf("-------o");
            Sleep(100);
            system("cls");
        }
        printf("|=====================================================|\n");
        printf("|------------------------BANCO------------------------|\n");
        printf("|=====================================================|\n");
        printf("|1. Cadastrar Conta                                   |\n");
        printf("|2. Visualizar todas as contas de determinado cliente |\n");
        printf("|3. Excluir a conta com menor saldo                   |\n");
        printf("|4. Sair                                              |\n");
        printf("|=====================================================|\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        switch (opcao) {
        case 1:
            if (numContas < 15) {
                Cadastro(vetor, numContas);
                numContas++;
                break;
            } else {
                printf("Limite de contas excedido");
                Sleep(4000);
                break;
            }
        case 2:
            printf("Digite o nome do cliente: ");
            scanf("%s", &nomeBusca);
            Busca(vetor, numContas, nomeBusca);
            Sleep(6000);
            break;
        case 3:
            Exclusao(vetor, numContas);
            break;
        case 4:
            break;
        default:
            printf("Numero invalido, tente novamente!");
            Sleep(4000);
            break;
        }
    }
}


