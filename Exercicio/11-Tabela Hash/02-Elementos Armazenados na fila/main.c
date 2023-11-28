#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_TABELA_HASH 10

// ESTRUTURA DA TABELA EM FILA
struct Node {
    char chave[50];
    struct Node* proximo;
};

// Estrutura para a tabela hash
struct TabelaHash {
    struct Node* tabela[TAMANHO_TABELA_HASH];
};

// Função para inicializar a tabela hash
void inicializarTabelaHash(struct TabelaHash* tabela) {
    for (int i = 0; i < TAMANHO_TABELA_HASH; i++) {
        tabela->tabela[i] = NULL;
    }
}

// Função para calcular o índice da tabela hash
int calcularIndiceTabelaHash(char chave[]) {
    int soma = 0;
    for (int i = 0; chave[i] != '\0'; i++) {
        soma += chave[i];
    }
    return soma % TAMANHO_TABELA_HASH;
}

// Função para enfileirar um elemento na tabela hash
void enfileirarElemento(struct Node** inicio, struct Node** fim, char chave[]) {
    struct Node* novoNode = (struct Node*)malloc(sizeof(struct Node));
    if (novoNode == NULL) {
        fprintf(stderr, "Erro ao alocar memória.\n");
        exit(EXIT_FAILURE);
    }

    strcpy(novoNode->chave, chave);
    novoNode->proximo = NULL;

    if (*inicio == NULL) {
        // Se a fila estiver vazia, o novo elemento será tanto o início quanto o fim
        *inicio = *fim = novoNode;
    } else {
        // Se a fila já tiver elementos, enfileire o novo elemento no final
        (*fim)->proximo = novoNode;
        *fim = novoNode;
    }
}

// Função para inserir um elemento na tabela hash
void inserirElemento(struct TabelaHash* tabela, char chave[]) {
    int indice = calcularIndiceTabelaHash(chave);

    // Enfileirar o novo elemento na tabela hash
    enfileirarElemento(&tabela->tabela[indice], &tabela->tabela[indice], chave);

    printf("Elemento inserido com sucesso.\n");
}

// Função para desenfileirar um elemento da tabela hash
void desenfileirarElemento(struct Node** inicio, struct Node** fim) {
    if (*inicio == NULL) {
        // A fila está vazia
        return;
    }

    struct Node* temp = *inicio;

    if (*inicio == *fim) {
        // Se há apenas um elemento na fila, ajuste o início e o fim para NULL
        *inicio = *fim = NULL;
    } else {
        // Se há mais de um elemento na fila, mova o início para o próximo elemento
        *inicio = (*inicio)->proximo;
    }

    free(temp);
}

// Função para imprimir a tabela hash (apenas para depuração)
void imprimirTabelaHash(struct TabelaHash* tabela) {
    for (int i = 0; i < TAMANHO_TABELA_HASH; i++) {
        printf("%d: ", i);
        struct Node* atual = tabela->tabela[i];
        while (atual != NULL) {
            printf("%s -> ", atual->chave);
            atual = atual->proximo;
        }
        printf("NULL\n");
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
        printf("2. Imprimir tabela hash\n");
        printf("3. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite a chave a ser inserida: ");
                scanf("%s", chave);
                inserirElemento(&tabela, chave);
                break;
            case 2:
                printf("Tabela Hash:\n");
                imprimirTabelaHash(&tabela);
                break;
            case 3:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 3);

    // Desalocar memória da fila
    for (int i = 0; i < TAMANHO_TABELA_HASH; i++) {
        while (tabela.tabela[i] != NULL) {
            desenfileirarElemento(&tabela.tabela[i], &tabela.tabela[i]);
        }
    }

    return 0;
}

