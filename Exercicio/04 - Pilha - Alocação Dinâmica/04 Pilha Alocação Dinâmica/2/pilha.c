#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pilha.h"

int main() {
    int opcao;
    Livro livro;
    pilha p;

    CriarPilha(&p);

    do {
        printf("\nInforme o título do livro: ");
        scanf("%s", livro.titulo);
        if (strcmp(livro.titulo, "0") == 0) // Verifica se o título é '0' para encerrar o cadastro
            break;
        printf("Informe o autor do livro: ");
        scanf("%s", livro.autor);
        printf("Informe a edição do livro: ");
        scanf("%d", &livro.edicao);

        Empilhar(&p, livro);

        printf("\nDeseja empilhar outro livro? (não = 0 / sim = 1)\n");
        scanf("%d", &opcao);
    } while (opcao == 1);

    ImprimirPilha(p);

    // Chame a função para imprimir a pilha em um arquivo binário
    ImprimirPilhaArquivo(p, "livros.bin");

    // Chame a função para ler o conteúdo do arquivo binário de volta para a pilha
    CriarPilha(&p); // Limpa a pilha antes de ler do arquivo
    LerPilhaArquivo(&p, "livros.bin");

    // Chame a função para contar a quantidade de livros até um título específico
    char titulo_desejado[100];
    printf("\nInforme o título do livro que deseja encontrar: ");
    scanf("%s", titulo_desejado);
    int quantidade = QuantidadeLivrosAteTitulo(&p, titulo_desejado);
    if (quantidade == -1) {
        printf("Livro não encontrado na pilha.\n");
    } else {
        printf("Quantidade de livros até o título desejado: %d\n", quantidade);
    }

    printf("\n");
    system("pause");
    return 0;
}
