/*5. Escreva a biblioteca lista.h para uma lista duplamente encadeada circular e teste-a para o exercício 1.
Qual(is) a(s) vantagem(ens)/ desvantagem(ens) da utilização de uma lista duplamente encadeada
circular?*/

/*Lista.h:*/

#ifndef LISTA_H
#define LISTA_H

struct Aluno {
    int codigo;
    char nome[50];
    struct Aluno* proximo;
    struct Aluno* anterior;
};

void inserirAluno(struct Aluno** lista, int codigo, const char* nome);
void imprimirLista(struct Aluno* lista);

#endif
/*Alunos.c:*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

// Função para comparar nomes de alunos
int compararNomes(const char* nome1, const char* nome2) {
    return strcmp(nome1, nome2);
}

int main() {
    struct Aluno* listaAlunos = NULL;

    // Exemplo de procedimento para inserir alunos na lista
    inserirAluno(&listaAlunos, 1, "Alice");
    inserirAluno(&listaAlunos, 2, "Carlos");
    inserirAluno(&listaAlunos, 3, "Bob");
    inserirAluno(&listaAlunos, 4, "David");
    inserirAluno(&listaAlunos, 5, "Eva");

    // Exemplo de procedimento para imprimir a lista
    imprimirLista(listaAlunos);

    return 0;
}

// Procedimento para inserir um aluno na lista em ordem alfabética
void inserirAluno(struct Aluno** lista, int codigo, const char* nome) {
    struct Aluno* novoAluno = (struct Aluno*)malloc(sizeof(struct Aluno));
    novoAluno->codigo = codigo;
    strcpy(novoAluno->nome, nome);

    if (*lista == NULL) {
        novoAluno->proximo = novoAluno;
        novoAluno->anterior = novoAluno;
        *lista = novoAluno;
    } else {
        struct Aluno* anterior = *lista;
        struct Aluno* atual = (*lista)->proximo;

        // Encontre o local correto para inserir o aluno em ordem alfabética
        while (atual != *lista && compararNomes(atual->nome, nome) < 0) {
            anterior = atual;
            atual = atual->proximo;
        }

        // Insira o aluno na posição correta
        anterior->proximo = novoAluno;
        novoAluno->anterior = anterior;
        novoAluno->proximo = atual;
        atual->anterior = novoAluno;

        // Se o novo aluno for o primeiro da lista, atualize o ponteiro da lista
        if (anterior == *lista) {
            *lista = novoAluno;
        }
    }
}

// Procedimento para imprimir a lista de alunos cadastrados
void imprimirLista(struct Aluno* lista) {
    if (lista == NULL) {
        printf("A lista de alunos esta vazia.\n");
    } else {
        printf("Lista de Alunos:\n");
        struct Aluno* atual = lista;
        do {
            printf("Codigo: %d, Nome: %s\n", atual->codigo, atual->nome);
            atual = atual->proximo;
        } while (atual != lista);
    }
}

/*Explicação do cod>> Neste exemplo, a lista duplamente encadeada circular é usada para armazenar alunos em ordem alfabética de nomes. 
O código está organizado em dois arquivos: "lista.h" contém a definição da estrutura da lista e as funções, 
e "alunos.c" demonstra o uso das funções e procedimentos para inserir e imprimir alunos na lista. 
Importante Certifique-se de compilar ambos os arquivos ao criar o programa final.*/

// Vantagens >> inserção eficiente, exclusões eficiente, acesso aleatório limitado, economia de memória//

// Desvantagens >> Complexidade de código, acesso aleatório ineficiente, overhead de memória, Dificuldade de inversão//

/*A escolha entre uma lista duplamente encadeada circular e outras estruturas de dados depende dos requisitos específicos do seu programa e 
das operações que você pretende realizar. O encadeamento circular é uma escolha válida em muitos casos, especialmente quando as vantagens, 
como inserção eficiente e economia de memória, superam as desvantagens para um determinado problema.*/

