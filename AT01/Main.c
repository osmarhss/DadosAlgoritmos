#include <stdio.h>
#include "ArvoreBinariaDePesquisa.h"

int main() {
    Registro x;
    TipoDicionario Dicionario;
    Inicia(&Dicionario);

    printf("Informe a chave (digite um número negativo para sair): ");
    scanf("%d", &x.Chave);

    while (x.Chave >= 0) {
        Insere(x, &Dicionario);
        printf("Informe a chave (digite um número negativo para sair): ");
        scanf("%d", &x.Chave);
    }

    // Exemplo de como usar Pesquisa e Central
    printf("Informe a chave para pesquisa: ");
    scanf("%d", &x.Chave);
    Pesquisa(&x, Dicionario);

    printf("Percurso Central:\n");
    Central(Dicionario);

    return 0;
}
