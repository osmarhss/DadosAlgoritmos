#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

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
    DesalistePArquivo(&l, "arquivo.txt");
    printf("Lista gravada no arquivo com sucesso.\n");

    //Limpa a lista
    CriarLista(&l);

    //Lê a lista de dados
    printf("\nLendo a lista do arquivo e enfileirando novamente...\n");
    ArquivoPLista(&l, "arquivo.txt");
    printf("Lista carregada do arquivo com sucesso.\n");

    //Imprimi a lista
    printf("\nImprimindo a lista:\n");
    ImprimirLista(&l);

    return 0;
}