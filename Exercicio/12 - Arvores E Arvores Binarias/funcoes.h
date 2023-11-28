#include <stdbool.h>
#define alturaInicial 0

// Definindo a estrutura de um nó da árvore
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Função para criar um novo nó
struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Função para inserir nó na árvore
struct TreeNode* inserirNaArovre(struct TreeNode* arvore, int value) {
    if (arvore == NULL) {
        return createNode(value);
    }

    if (value < arvore->data) {
        arvore->left = inserirNaArovre(arvore->left, value);
    } else if (value > arvore->data) {
        arvore->right = inserirNaArovre(arvore->right, value);
    }

    return arvore;
}

// verificar árvore vazia
bool verificarArvoreVazia (struct TreeNode* arvore){
    if (arvore == NULL)
    {
        return true;
    }
    return false;    
}

// função para remover nó da arvore
struct TreeNode* removerNo(struct TreeNode* arvore, int value){
    if (arvore->data == value) {
        return arvore = NULL;
    }

    if (value < arvore->data) {
        arvore->left = removerNo(arvore->left, value);
    } else if (value > arvore->data) {
        arvore->right = removerNo(arvore->right, value);
    }

    return arvore;
}

// // função para pesquisar nó na arvore
// bool pesquisaElementoExiste(struct TreeNode* arvore, int value){
//     if (arvore->data == value) {
//         return true;
//     }

//     if (value < arvore->data) {
//         return arvore->left = pesquisaElementoExiste(arvore->left, value);
//     } else if (value > arvore->data) {
//         return arvore->right = pesquisaElementoExiste(arvore->right, value);
//     }
//     return false;
// }

// int alturaArvore(struct TreeNode* arvore){
//     int listaDeAlturas[100];
//     int valorInicialAltura = 0;
//     funcaoAlturaArvore(arvore, valorInicialAltura, listaDeAlturas);
// }

// // função para ver alturar da arvore
// struct TreeNode* funcaoAlturaArvore(struct TreeNode* arvore, int altura, int lista[1]){
//     if (arvore == NULL) {
//         return true;
//     }

//     if (value < arvore->data) {
//         return arvore->left = funcaoAlturaArvore(arvore->left, value);
//     } else if (value > arvore->data) {
//         return arvore->right = funcaoAlturaArvore(arvore->right, value);
//     }
//     return false;
// }

