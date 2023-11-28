#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para um nó da árvore binária de pesquisa
struct Node {
    char chave[50];
    struct Node* esquerda;
    struct Node* direita;
};

// Estrutura para a tabela hash
struct TabelaHash {
    struct Node* tabela[10];
};

// Função para inicializar a tabela hash
void inicializarTabelaHash(struct TabelaHash* tabela) {
    for (int i = 0; i < 10; i++) {
        tabela->tabela[i] = NULL;
    }
}

// Função para calcular o índice da tabela hash
int calcularIndiceTabelaHash(char chave[]) {
    int soma = 0;
    for (int i = 0; chave[i] != '\0'; i++) {
        soma += chave[i];
    }
    return soma % 10;
}

// Função para inserir um elemento na árvore binária de pesquisa
struct Node* inserirElementoBST(struct Node* raiz, char chave[]) {
    if (raiz == NULL) {
        // Se a árvore estiver vazia, crie um novo nó
        struct Node* novoNode = (struct Node*)malloc(sizeof(struct Node));
        if (novoNode == NULL) {
            fprintf(stderr, "Erro ao alocar memória.\n");
            exit(EXIT_FAILURE);
        }

        strcpy(novoNode->chave, chave);
        novoNode->esquerda = novoNode->direita = NULL;
        return novoNode;
    }

    // Caso contrário, insira na subárvore apropriada
    if (strcmp(chave, raiz->chave) < 0) {
        raiz->esquerda = inserirElementoBST(raiz->esquerda, chave);
    } else if (strcmp(chave, raiz->chave) > 0) {
        raiz->direita = inserirElementoBST(raiz->direita, chave);
    }

    return raiz;
}

// Função para inserir um elemento na tabela hash
void inserirElemento(struct TabelaHash* tabela, char chave[]) {
    int indice = calcularIndiceTabelaHash(chave);

    // Inserir na árvore binária de pesquisa correspondente
    tabela->tabela[indice] = inserirElementoBST(tabela->tabela[indice], chave);

    printf("Elemento inserido com sucesso.\n");
}

// Função auxiliar para realizar a busca na árvore binária de pesquisa
int buscarElementoBST(struct Node* raiz, char chave[]) {
    if (raiz == NULL) {
        return 0; // Elemento não encontrado
    }

    // Comparar a chave com a chave do nó atual
    int comparacao = strcmp(chave, raiz->chave);

    if (comparacao < 0) {
        // Se a chave é menor, buscar na subárvore esquerda
        return buscarElementoBST(raiz->esquerda, chave);
    } else if (comparacao > 0) {
        // Se a chave é maior, buscar na subárvore direita
        return buscarElementoBST(raiz->direita, chave);
    } else {
        return 1; // Elemento encontrado
    }
}

// Função para buscar um elemento na tabela hash
void buscarElemento(struct TabelaHash* tabela, char chave[]) {
    int indice = calcularIndiceTabelaHash(chave);

    // Realizar a busca na árvore binária de pesquisa correspondente
    if (buscarElementoBST(tabela->tabela[indice], chave)) {
        printf("Elemento encontrado na tabela hash.\n");
    } else {
        printf("Elemento nao encontrado na tabela hash.\n");
    }
}

// Função para imprimir a árvore binária de pesquisa (em ordem)
void imprimirArvoreBST(struct Node* raiz) {
    if (raiz != NULL) {
        imprimirArvoreBST(raiz->esquerda);
        printf("%s ", raiz->chave);
        imprimirArvoreBST(raiz->direita);
    }
}

// Função para imprimir a tabela hash (apenas para depuração)
void imprimirTabelaHash(struct TabelaHash* tabela) {
    for (int i = 0; i < 10; i++) {
        printf("%d: ", i);
        imprimirArvoreBST(tabela->tabela[i]);
        printf("\n");
    }
}

// Função para liberar a memória alocada para a árvore binária de pesquisa
void liberarArvoreBST(struct Node* raiz) {
    if (raiz != NULL) {
        liberarArvoreBST(raiz->esquerda);
        liberarArvoreBST(raiz->direita);
        free(raiz);
    }
}

// Função para liberar a memória alocada para a tabela hash
void liberarTabelaHash(struct TabelaHash* tabela) {
    for (int i = 0; i < 10; i++) {
        liberarArvoreBST(tabela->tabela[i]);
    }
}

int main() {
    struct TabelaHash tabela;
    inicializarTabelaHash(&tabela);

    int opcao;
    char chave[50];

    do {
        printf("\nMenu:\n");
        printf("1. Inserir elemento\n");
        printf("2. Buscar elemento\n");
        printf("3. Imprimir tabela hash\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite a chave a ser inserida: ");
                scanf("%s", chave);
                inserirElemento(&tabela, chave);
                break;
            case 2:
                printf("Digite a chave a ser buscada: ");
                scanf("%s", chave);
                buscarElemento(&tabela, chave);
                break;
            case 3:
                printf("Tabela Hash:\n");
                imprimirTabelaHash(&tabela);
                break;
            case 4:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 4);

    // Liberar memória alocada
    liberarTabelaHash(&tabela);

    return 0;
}
