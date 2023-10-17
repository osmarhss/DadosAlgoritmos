#ifndef DEQUE_H
#define DEQUE_H

#define MAX_SIZE 100 // Tamanho máximo do deque

typedef struct Deque {
    int front, rear;
    int elementos[MAX_SIZE];
} Deque;

void criarDeque(Deque* deque);
int estaVazio(Deque* deque);
int estaCheio(Deque* deque);
void inserirInicio(Deque* deque, int elemento);
void inserirFinal(Deque* deque, int elemento);
int removerInicio(Deque* deque);
int removerFinal(Deque* deque);
void atualizarElemento(Deque* deque, int posicao, int novoElemento);

#endif
