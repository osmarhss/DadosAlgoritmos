#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_TABELA_HASH 10

// Estrutura para um nó da pilha
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

// Função para empilhar um elemento na tabela hash
void empilharElemento(struct Node** topo, char chave[]) {
    struct Node* novoNode = (struct Node*)malloc(sizeof(struct Node));
    if (novoNode == NULL) {
        fprintf(stderr, "Erro ao alocar memória.\n");
        exit(EXIT_FAILURE);
    }

    strcpy(novoNode->chave, chave);
    novoNode->proximo = *topo;
    *topo = novoNode;
}

// Função para inserir um elemento na tabela hash
void inserirElemento(struct TabelaHash* tabela, char chave[]) {
    int indice = calcularIndiceTabelaHash(chave);

    if (tabela->tabela[indice] == NULL) {
        // Se não houver colisão, insira diretamente na tabela hash
        empilharElemento(&tabela->tabela[indice], chave);
    } else {
        // Se houver colisão, empilhe o novo elemento
        printf("Colisao detectada para %s. Lidando com a colisao usando pilha.\n", chave);
        empilharElemento(&tabela->tabela[indice], chave);
    }

    printf("Elemento inserido com sucesso.\n");
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

    return 0;
}
