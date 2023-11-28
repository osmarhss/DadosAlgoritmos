#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include "funcoes.h"


// Definindo a estrutura de um nó da árvore


int main() {
    struct TreeNode* arvore = NULL;

    
    arvore = inserirNaArovre(arvore, 10);
    arvore = inserirNaArovre(arvore, 5);
    arvore = inserirNaArovre(arvore, 15);
    arvore = inserirNaArovre(arvore, 16);
    arvore = inserirNaArovre(arvore, 17);
    arvore = inserirNaArovre(arvore, 18);
    arvore = inserirNaArovre(arvore, 19);

    printf("o no raiz tem o valor: %d \n", arvore->data);

    bool n = false;
    n = pesquisaElementoExiste(arvore, 15);
    if (n)
    {
        printf("tem!!\n");
    } else {
        printf("nao tem\n");
    }

    // int altura = calcularAlturaArvore(arvore);
    // printf("%d\n", altura);

    // int alturaNo = calcularAlturaNoNaArvore(arvore, 5);
    // printf("%d\n", alturaNo);

    // int profundidade = calcularProfundidadeArvore(arvore);
    // printf("%d\n", profundidade);

    // int profundidadeNo = calcularProfundidadeNoNaArvore(arvore, 5);
    // printf("%d\n", profundidadeNo);

    int nivelNo = calcularNivelNoNaArvore(arvore, 18);
    printf("%d\n", nivelNo);

    printf("%d", calcularGrauMaximo(arvore));

    // arvore = removerNo(arvore, 10);

    // // Verificar se a árvore está vazia
    // if (verificarArvoreVazia(arvore)) {
    //     printf("A árvore está vazia.\n");
    // } else {
    //     printf("A árvore não está vazia.\n");
    // }



    return 0;
}
