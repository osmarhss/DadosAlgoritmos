/*2. O TAD Deque pode ser implementado com alocação dinâmica de memória (alocação
encadeada). Modifique a biblioteca lista.h (ou fila.h, ou lista.h) com alocação dinâmica de
memória, para implementar as operações comuns em um TAD Deque listadas acima. Crie
também uma operação que permita atualizar um elemento no Deque.*/


#ifndef DEQUE_H
#define DEQUE_H

typedef struct Nodo {
    int elemento;
    struct Nodo* anterior;
    struct Nodo* proximo;
} Nodo;

typedef struct Deque {
    Nodo* frente;
    Nodo* tras;
} Deque;

void criarDeque(Deque* deque);
int estaVazio(Deque* deque);
void inserirInicio(Deque* deque, int elemento);
void inserirFinal(Deque* deque, int elemento);
int removerInicio(Deque* deque);
int removerFinal(Deque* deque);
void atualizarElemento(Deque* deque, int posicao, int novoElemento);

#endif




#include "deque.h"
#include <stdio.h>
#include <stdlib.h>

void criarDeque(Deque* deque) {
    deque->frente = NULL;
    deque->tras = NULL;
}

int estaVazio(Deque* deque) {
    return (deque->frente == NULL);
}

void inserirInicio(Deque* deque, int elemento) {
    Nodo* novoNodo = (Nodo*)malloc(sizeof(Nodo));
    novoNodo->elemento = elemento;
    novoNodo->proximo = deque->frente;
    novoNodo->anterior = NULL;

    if (estaVazio(deque)) {
        deque->tras = novoNodo;
    } else {
        deque->frente->anterior = novoNodo;
    }

    deque->frente = novoNodo;
}

void inserirFinal(Deque* deque, int elemento) {
    Nodo* novoNodo = (Nodo*)malloc(sizeof(Nodo));
    novoNodo->elemento = elemento;
    novoNodo->proximo = NULL;
    novoNodo->anterior = deque->tras;

    if (estaVazio(deque)) {
        deque->frente = novoNodo;
    } else {
        deque->tras->proximo = novoNodo;
    }

    deque->tras = novoNodo;
}

int removerInicio(Deque* deque) {
    if (estaVazio(deque)) {
        printf("O deque está vazio. Não é possível remover.\n");
        return -1; // Valor de erro
    }

    Nodo* nodoRemovido = deque->frente;
    int elementoRemovido = nodoRemovido->elemento;

    deque->frente = nodoRemovido->proximo;
    if (deque->frente == NULL) {
        deque->tras = NULL;
    } else {
        deque->frente->anterior = NULL;
    }

    free(nodoRemovido);
    return elementoRemovido;
}

int removerFinal(Deque* deque) {
    if (estaVazio(deque)) {
        printf("O deque está vazio. Não é possível remover.\n");
        return -1; // Valor de erro
    }

    Nodo* nodoRemovido = deque->tras;
    int elementoRemovido = nodoRemovido->elemento;

    deque->tras = nodoRemovido->anterior;
    if (deque->tras == NULL) {
        deque->frente = NULL;
    } else {
        deque->tras->proximo = NULL;
    }

    free(nodoRemovido);
    return elementoRemovido;
}

void atualizarElemento(Deque* deque, int posicao, int novoElemento) {
    int i = 0;
    Nodo* nodoAtual = deque->frente;
    
    while (nodoAtual != NULL && i < posicao) {
        nodoAtual = nodoAtual->proximo;
        i++;
    }

    if (nodoAtual != NULL) {
        nodoAtual->elemento = novoElemento;
    } else {
        printf("Posição fora dos limites.\n");
    }
}
