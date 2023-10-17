// conjunto.c
#include <stdio.h>
#include <stdlib.h>
#include "conjunto.h"

Conjunto* criarConjunto() {
    Conjunto* conjunto = (Conjunto*)malloc(sizeof(Conjunto));
    conjunto->head = NULL;
    conjunto->size = 0;
    return conjunto;
}

void adicionarElemento(Conjunto* conjunto, int elemento) {
    if (!pertenceConjunto(conjunto, elemento)) {
        Node* novoNo = (Node*)malloc(sizeof(Node));
        novoNo->data = elemento;
        novoNo->next = conjunto->head;
        conjunto->head = novoNo;
        conjunto->size++;
    }
}

int pertenceConjunto(Conjunto* conjunto, int elemento) {
    Node* current = conjunto->head;
    while (current != NULL) {
        if (current->data == elemento) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

void removerElemento(Conjunto* conjunto, int elemento) {
    if (conjunto->head == NULL) return;

    Node* current = conjunto->head;
    Node* previous = NULL;

    while (current != NULL) {
        if (current->data == elemento) {
            if (previous == NULL) {
                conjunto->head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            conjunto->size--;
            return;
        }
        previous = current;
        current = current->next;
    }
}

void atualizarElemento(Conjunto* conjunto, int elementoAntigo, int elementoNovo) {
    if (pertenceConjunto(conjunto, elementoAntigo) && !pertenceConjunto(conjunto, elementoNovo)) {
        removerElemento(conjunto, elementoAntigo);
        adicionarElemento(conjunto, elementoNovo);
    }
}

void liberarConjunto(Conjunto* conjunto) {
    Node* current = conjunto->head;
    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }
    free(conjunto);
}

#include <stdio.h>
#include "conjunto.h"

int main() {
    Conjunto* conjunto = criarConjunto();
    
    adicionarElemento(conjunto, 1);
    adicionarElemento(conjunto, 2);
    adicionarElemento(conjunto, 3);
    
    atualizarElemento(conjunto, 2, 4); // Atualiza o elemento 2 para 4

    printf("Tamanho do conjunto: %d\n", conjunto->size);

    liberarConjunto(conjunto);
    return 0;
}
