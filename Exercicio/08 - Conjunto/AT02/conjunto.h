// conjunto.h
#ifndef CONJUNTO_H
#define CONJUNTO_H

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Conjunto {
    Node* head;
    int size;
} Conjunto;

Conjunto* criarConjunto();
void adicionarElemento(Conjunto* conjunto, int elemento);
int pertenceConjunto(Conjunto* conjunto, int elemento);
void removerElemento(Conjunto* conjunto, int elemento);
void atualizarElemento(Conjunto* conjunto, int elementoAntigo, int elementoNovo);
void liberarConjunto(Conjunto* conjunto);

#endif
