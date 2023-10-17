#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int elementos[MAX_SIZE];
    int tamanho;
} Conjunto;

void inicializarConjunto(Conjunto *conj) {
    conj->tamanho = 0;
}

bool estaVazio(const Conjunto *conj) {
    return conj->tamanho == 0;
}

bool contem(const Conjunto *conj, int elemento) {
    for (int i = 0; i < conj->tamanho; i++) {
        if (conj->elementos[i] == elemento) {
            return true;
        }
    }
    return false;
}

void adicionarElemento(Conjunto *conj, int elemento) {
    if (conj->tamanho < MAX_SIZE && !contem(conj, elemento)) {
        conj->elementos[conj->tamanho] = elemento;
        conj->tamanho++;
    }
}

void removerElemento(Conjunto *conj, int elemento) {
    for (int i = 0; i < conj->tamanho; i++) {
        if (conj->elementos[i] == elemento) {
            conj->elementos[i] = conj->elementos[conj->tamanho - 1];
            conj->tamanho--;
            break;
        }
    }
}

void atualizarElemento(Conjunto *conj, int elementoAntigo, int elementoNovo) {
    if (contem(conj, elementoAntigo)) {
        removerElemento(conj, elementoAntigo);
        adicionarElemento(conj, elementoNovo);
    }
}

void imprimirConjunto(const Conjunto *conj) {
    if (estaVazio(conj)) {
        printf("Conjunto vazio.\n");
        return;
    }

    printf("Conjunto: { ");
    for (int i = 0; i < conj->tamanho; i++) {
        printf("%d ", conj->elementos[i]);
    }
    printf("}\n");
}

int main() {
    Conjunto conjunto;
    inicializarConjunto(&conjunto);

    adicionarElemento(&conjunto, 1);
    adicionarElemento(&conjunto, 2);
    adicionarElemento(&conjunto, 3);

    imprimirConjunto(&conjunto);
    atualizarElemento(&conjunto, 2, 4);
    imprimirConjunto(&conjunto);
    removerElemento(&conjunto, 3);
    imprimirConjunto(&conjunto);

    return 0;
}
