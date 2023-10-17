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
