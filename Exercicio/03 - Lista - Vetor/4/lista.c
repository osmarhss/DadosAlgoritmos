#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

int main() {
    lista l;
    CriarLista(&l);

    //Inserir produtos
    for (int i = 0; i < 2; i++) {
        struct tipo_produto p;
        printf("Insira os dados do produto %d:\n", i + 1);
        printf("Nome: ");
        scanf(" %[^\n]s", p.nome);
        printf("Valor unitário: ");
        scanf("%f", &p.valor_unitario);
        printf("Quantidade em estoque: ");
        scanf("%d", &p.quantidade_estoque);
        InserirProduto(&l, p);
    }

    //Grava a lista em um arquivo
    GravarLista(&l, "produtos.bin");

    //Limpa a lista para simular a leitura
    CriarLista(&l);

    //Lê a lista de produtos do arquivo
    LerLista(&l, "produtos.bin");

    //Imprime a lista
    printf("\nImprimindo a lista de produtos:\n");
    ImprimirLista(&l);

    //Pesquisa por um produto
    char nomePesquisa[50];
    printf("Digite o nome do produto a ser pesquisado: ");
    scanf(" %[^\n]s", nomePesquisa);
    int pos = PesquisarProduto(&l, nomePesquisa);
    if (pos != -1) {
        printf("Produto encontrado:\n");
        printf("Nome: %s, Valor unitário: %.2f, Quantidade em estoque: %d\n", l.vet[pos].nome, l.vet[pos].valor_unitario, l.vet[pos].quantidade_estoque);
        char resposta;
        printf("Deseja excluir este produto? (s/n): ");
        scanf(" %c", &resposta);
        if (resposta == 's') {
            ExcluirProduto(&l, pos);
        }
    } else {
        printf("Produto não cadastrado!\n");
    }

    return 0;
}