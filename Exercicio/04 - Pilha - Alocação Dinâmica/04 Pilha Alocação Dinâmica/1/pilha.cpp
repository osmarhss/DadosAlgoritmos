#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main() {
    int num, resto;
    pilha p;

    CriarPilha(&p);

    printf("\nInforme um numero inteiro: ");
    scanf("%d", &num);

    while (num != 0) {
        resto = num % 2;
        Empilhar(&p, resto);
        num /= 2;
    }

    printf("\nCorrespondente em binario: ");
    while (!PilhaVazia(&p)) {
        resto = Desempilhar(&p);
        printf("%d", resto);
    }
    printf("\n\n");

    return 0;
}
