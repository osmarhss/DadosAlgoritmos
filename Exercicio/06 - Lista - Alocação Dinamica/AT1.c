//1. Escreva um algoritmo que aliste os alunos matriculados em um curso na ordem ascendente dos
nomes. Crie um procedimento para comparar os elementos na função PesquisarLista(), um
procedimento para cadastrar os alunos e outro para imprimir a lista de alunos cadastrados. A
estrutura aluno deve possuir o código e nome dos alunos.//


#include <stdio.h>
#include <string.h>

// Estrutura para representar um aluno
struct Aluno {
    int codigo;
    char nome[100];
};

// Função de comparação para ordenar alunos por nome
int CompararNomes(const void *a, const void *b) {
    struct Aluno *aluno1 = (struct Aluno *)a;
    struct Aluno *aluno2 = (struct Aluno *)b;
    return strcmp(aluno1->nome, aluno2->nome);
}

// Procedimento para cadastrar um aluno
void CadastrarAluno(struct Aluno lista[], int *numAlunos, int codigo, const char *nome) {
    struct Aluno aluno;
    aluno.codigo = codigo;
    strcpy(aluno.nome, nome);
    lista[(*numAlunos)++] = aluno;
}

// Procedimento para imprimir a lista de alunos
void ImprimirLista(struct Aluno lista[], int numAlunos) {
    for (int i = 0; i < numAlunos; i++) {
        printf("Código: %d, Nome: %s\n", lista[i].codigo, lista[i].nome);
    }
}

int main() {
    struct Aluno ListaDeAlunos[100];  // Suponhamos um máximo de 100 alunos na lista
    int numAlunos = 0;

    // Cadastro de alunos
    CadastrarAluno(ListaDeAlunos, &numAlunos, 1, "Maria");
    CadastrarAluno(ListaDeAlunos, &numAlunos, 2, "João");
    CadastrarAluno(ListaDeAlunos, &numAlunos, 3, "Ana");
    CadastrarAluno(ListaDeAlunos, &numAlunos, 4, "Pedro");

    // Ordenar a lista de alunos por nome
    qsort(ListaDeAlunos, numAlunos, sizeof(struct Aluno), CompararNomes);

    // Imprimir a lista de alunos
    ImprimirLista(ListaDeAlunos, numAlunos);

    return 0;
}
