#include <stdio.h>
#include <stdlib.h>
#include <funcoes.h>


// Definindo a estrutura de um nó da árvore
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

int main() {
    struct TreeNode* arvore = NULL;
    inserirNaArovre(arvore, 26);
    printf("%d", arvore->data);
}
