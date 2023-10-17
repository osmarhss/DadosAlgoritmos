#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"


// Pesquisar funcionário por CPF.
void PesquisarPorCPF(lista *l, long long cpf) {
    if (ListaVazia(l)) {
        printf("A lista está vazia.\n");
    } else {
        int encontrado = 0;
        for (int i = l->inicio; i <= l->fim; i++) {
            if (l->vet[i].CPF == cpf) {
                printf("Funcionário encontrado:\n");
                printf("CPF: %lld, Nome: %s, Endereço: %s, Telefone: %lld, Celular: %lld, Data de Nascimento: %s, Data de Admissão: %s, Departamento: %s, Cargo: %s, Salário: %.2f\n",
                       l->vet[i].CPF, l->vet[i].nome, l->vet[i].endereco, l->vet[i].telefone, l->vet[i].celular, l->vet[i].data_nascimento, l->vet[i].data_admissao, l->vet[i].departamento, l->vet[i].cargo, l->vet[i].salario);
                encontrado = 1;
            }
        }
        if (!encontrado) {
            printf("Funcionário com CPF %lld não encontrado.\n", cpf);
        }
    }
}

int main() {
    lista l;
    CriarLista(&l);

    //Entrada de dados
    for (int i = 0; i < 10; i++) {
        struct tipo_funcionario f;
        printf("Insira os dados do funcionário %d:\n", i + 1);
        printf("CPF: ");
        scanf("%lld", &f.CPF);
        printf("Nome: ");
        scanf(" %[^\n]s", f.nome);
        printf("Endereço: ");
        scanf(" %[^\n]s", f.endereco);
        printf("Telefone: ");
        scanf("%lld", &f.telefone);
        printf("Celular: ");
        scanf("%lld", &f.celular);
        printf("Data de Nascimento (dd/mm/aaaa): ");
        scanf(" %s", f.data_nascimento);
        printf("Data de Admissão (dd/mm/aaaa): ");
        scanf(" %s", f.data_admissao);
        printf("Departamento: ");
        scanf(" %[^\n]s", f.departamento);
        printf("Cargo: ");
        scanf(" %[^\n]s", f.cargo);
        printf("Salário: ");
        scanf("%f", &f.salario);
        Alistar(&l, f);
    }

    //Grava a lista no arquivo
    printf("\nGravando a lista em um arquivo...\n");
    DesalistePArquivo(&l, "arquivo.dat");
    printf("Lista gravada no arquivo com sucesso.\n");

    //Limpa a lista
    CriarLista(&l);

    //Lê a lista de dados
    printf("\nLendo a lista do arquivo e enfileirando novamente...\n");
    ArquivoPLista(&l, "arquivo.dat");
    printf("Lista carregada do arquivo com sucesso.\n");

      // Pesquisar funcionário por CPF
    printf("\nDigite o CPF do funcionário que deseja pesquisar: ");
    long long cpfPesquisa;
    scanf("%lld", &cpfPesquisa);
    PesquisarPorCPF(&l, cpfPesquisa);

    //Imprimi a lista
    printf("\nImprimindo a lista:\n");
    ImprimirLista(&l);
    return 0;
}