#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "funcoes.h"


// Definindo a estrutura de um nó da árvore


int main() {
    struct TreeNode* arvore = NULL;

    
    arvore = inserirNaArovre(arvore, 10);
    arvore = inserirNaArovre(arvore, 5);
    arvore = inserirNaArovre(arvore, 15);

    printf("o no raiz tem o valor: %d \n", arvore->data);

    arvore = removerNo(arvore, 10);

    // Verificar se a árvore está vazia
    if (verificarArvoreVazia(arvore)) {
        printf("A árvore está vazia.\n");
    } else {
        printf("A árvore não está vazia.\n");
    }



    return 0;
}
