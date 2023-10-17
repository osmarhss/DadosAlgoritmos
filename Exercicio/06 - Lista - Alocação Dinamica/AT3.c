/*3. Uma lista duplamente encadeada é um tipo abstrato de dados (TAD) lista em que cada nodo possui
um ponteiro para o nodo antecessor e outro para o nodo sucessor, como apresentado na figura
abaixo. Altere a biblioteca lista.h do exercício 5 para que se torne uma biblioteca para lista
duplamente encadeada. Teste a nova biblioteca para o exercício 1. Qual(is) a(s) vantagem(ens)/
desvantagem(ens) da utilização de uma lista duplamente encadeada?*/

//caminho imagem  >> at3image.png//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para representar um aluno
struct Aluno {
    int codigo;
    char nome[50];
    struct Aluno* proximo;
    struct Aluno* anterior;
};

// Função para criar um novo nó de aluno
struct Aluno* criarAluno(int codigo, const char* nome) {
    struct Aluno* novoAluno = (struct Aluno*)malloc(sizeof(struct Aluno));
    novoAluno->codigo = codigo;
    strcpy(novoAluno->nome, nome);
    novoAluno->proximo = NULL;
    novoAluno->anterior = NULL;
    return novoAluno;
}

// Função para inserir um aluno na lista em ordem alfabética
void inserirAlunoOrdenado(struct Aluno** lista, struct Aluno* novoAluno) {
    if (*lista == NULL || strcmp(novoAluno->nome, (*lista)->nome) < 0) {
        novoAluno->proximo = *lista;
        if (*lista != NULL) {
            (*lista)->anterior = novoAluno;
        }
        *lista = novoAluno;
    } else {
        struct Aluno* atual = *lista;
        while (atual->proximo != NULL && strcmp(novoAluno->nome, atual->proximo->nome) >= 0) {
            atual = atual->proximo;
        }
        novoAluno->proximo = atual->proximo;
        if (atual->proximo != NULL) {
            atual->proximo->anterior = novoAluno;
        }
        atual->proximo = novoAluno;
        novoAluno->anterior = atual;
    }
}

// Função para imprimir a lista de alunos em ordem alfabética
void imprimirLista(struct Aluno* lista) {
    while (lista != NULL) {
        printf("Código: %d, Nome: %s\n", lista->codigo, lista->nome);
        lista = lista->proximo;
    }
}

int main() {
    struct Aluno* lista = NULL;

    // Cadastre alguns alunos
    inserirAlunoOrdenado(&lista, criarAluno(101, "Alice"));
    inserirAlunoOrdenado(&lista, criarAluno(102, "Bob"));
    inserirAlunoOrdenado(&lista, criarAluno(103, "Eve"));
    inserirAlunoOrdenado(&lista, criarAluno(104, "Charlie"));

    // Imprima a lista de alunos em ordem alfabética
    printf("Lista de Alunos em Ordem Ascendente:\n");
    imprimirLista(lista);

    return 0;
}


/* CONSIDERAÇÕES FINAIS >> Listas encadeadas possuem duas desvantagens principais. 
Primeiro, precisamos de espaço adicional para armazenar os ponteiros. Segundo, se quisermos acessar um elemento em uma dada posição da lista, 
precisamos percorrer todos os elementos anteriores a ele na lista.*/