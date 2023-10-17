/*6. Testar o algoritmo abaixo que alista letras maiúsculas geradas aleatoriamente. Caso necessário, altere
o algoritmo para que funcione corretamente.*/
/* Arquivo: lista.c
* Programa para alistar letras maiúsculas geradas aleatoriamente.
*/


/*Neste código revisado:

Usei as estruturas "Nodo" e "Lista" para representar os elementos da lista e a lista em si.

Renomeei as funções, Corrigi a função PesquisarLista para retornar um ponteiro "Nodo*"".

Usei free para liberar a memória */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Definir a estrutura do nodo
typedef struct Nodo {
    char elemento;
    struct Nodo* prox;
} Nodo;

// Definir a estrutura da lista
typedef struct Lista {
    Nodo* inicio;
} Lista;

// Função para criar uma lista vazia
void criarLista(Lista* lista) {
    lista->inicio = NULL;
}

// Função para inserir um elemento no final da lista
void alistar(Lista* lista, char c) {
    Nodo* novoNodo = (Nodo*)malloc(sizeof(Nodo));
    novoNodo->elemento = c;
    novoNodo->prox = NULL;

    if (lista->inicio == NULL) {
        lista->inicio = novoNodo;
    } else {
        Nodo* atual = lista->inicio;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novoNodo;
    }
}

// Função para imprimir a lista
void imprimirLista(Lista lista) {
    Nodo* atual = lista.inicio;
    printf("Lista = ");
    while (atual != NULL) {
        printf("%c -> ", atual->elemento);
        atual = atual->prox;
    }
    printf("NULL\n");
}

// Função para procurar e retornar um ponteiro para o nodo com o elemento especificado
Nodo* pesquisarLista(Lista* lista, char c) {
    Nodo* atual = lista->inicio;
    while (atual != NULL) {
        if (atual->elemento == c) {
            return atual;
        }
        atual = atual->prox;
    }
    return NULL;
}

// Função para remover um nodo da lista e liberar memória
void desalistar(Lista* lista, Nodo* predecessor) {
    if (predecessor == NULL) {
        Nodo* temp = lista->inicio;
        lista->inicio = lista->inicio->prox;
        free(temp);
    } else {
        Nodo* temp = predecessor->prox;
        if (temp != NULL) {
            predecessor->prox = temp->prox;
            free(temp);
        }
    }
}

int main() {
    char c, op = 's';
    Lista lista;
    criarLista(&lista);
    srand(time(NULL));

 

    return 0;
}
