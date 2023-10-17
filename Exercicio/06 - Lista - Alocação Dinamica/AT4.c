/*4. Uma lista encadeada circular é um tipo abstrato de dados (TAD) lista em que o último nodo alistado
sempre aponta para o primeiro nodo alistado. A figura 2 apresenta uma lista encadeada circular.
Escreva a biblioteca lista.h para uma lista encadeada circular e teste-a para o exercício 1. Qual(is) a(s)
vantagem(ens)/ desvantagem(ens) da utilização de uma lista encadeada circular?

caminho da image >> at4image.png*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para representar um aluno
struct Aluno {
    int codigo;
    char nome[50];
    struct Aluno* proximo;
};

// Inicializa a lista vazia
struct Aluno* listaAlunos = NULL;

// Função para comparar nomes de alunos
int compararNomes(const char* nome1, const char* nome2) {
    return strcmp(nome1, nome2);
}

// Procedimento para cadastrar um aluno na lista
void cadastrarAluno(int codigo, const char* nome) {
    struct Aluno* novoAluno = (struct Aluno*)malloc(sizeof(struct Aluno));
    novoAluno->codigo = codigo;
    strcpy(novoAluno->nome, nome);

    if (listaAlunos == NULL) {
        listaAlunos = novoAluno;
        novoAluno->proximo = novoAluno;
    } else {
        struct Aluno* anterior = listaAlunos;
        struct Aluno* atual = listaAlunos->proximo;

        // Encontre o local correto para inserir o aluno em ordem alfabética
        while (atual != listaAlunos && compararNomes(atual->nome, nome) < 0) {
            anterior = atual;
            atual = atual->proximo;
        }

        // Insira o aluno na posição correta
        anterior->proximo = novoAluno;
        novoAluno->proximo = atual;

        // Se o novo aluno for o primeiro da lista, atualize o ponteiro da lista
        if (anterior == listaAlunos) {
            listaAlunos = novoAluno;
        }
    }
}

// Procedimento para imprimir a lista de alunos cadastrados
void imprimirLista() {
    if (listaAlunos == NULL) {
        printf("A lista de alunos esta vazia.\n");
    } else {
        struct Aluno* atual = listaAlunos;
        printf("Lista de Alunos:\n");
        do {
            printf("Codigo: %d, Nome: %s\n", atual->codigo, atual->nome);
            atual = atual->proximo;
        } while (atual != listaAlunos);
    }
}

int main() {
    // Exemplo de uso
    cadastrarAluno(1, "Alice");
    cadastrarAluno(2, "Carlos");
    cadastrarAluno(3, "Bob");
    cadastrarAluno(4, "David");
    cadastrarAluno(5, "Eva");

    imprimirLista();

    return 0;
}

/*Conclusão Final >> As desvantagens são enumeras , alem da complexidade do código, consumo de memória, overhead de ponteiros.
A escolha entre o encadeamento circular e outras estruturas de dados depende dos requisitos específicos do seu programa 
e do tipo de operações que você pretende realizar. O encadeamento circular é uma escolha válida em muitos casos, especialmente quando as vantagens,
 como inserções eficientes, superam as desvantagens para um determinado problema.*/
