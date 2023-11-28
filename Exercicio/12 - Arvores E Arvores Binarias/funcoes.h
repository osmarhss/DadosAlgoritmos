#include <stdbool.h>
#include <stddef.h>

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

// função para pesquisar nó na arvore
bool pesquisaElementoExiste(struct TreeNode* arvore, int value){
    if (arvore->data == value) {
        return true;
    }

    if (value < arvore->data) {
        if (!arvore->left == NULL)
        {
        return pesquisaElementoExiste(arvore->left, value);
        }
        
    } else if (value > arvore->data) {
        if (!arvore->right == NULL)
        {
        return pesquisaElementoExiste(arvore->right, value);
        }
        
    }
    return false;
}

// Função para calcular a altura de uma árvore binária
int calcularAlturaArvore(struct TreeNode* arvore) {
    if (arvore == NULL) {
        return 0;
    } else {
        int alturaEsquerda = calcularAlturaArvore(arvore->left);
        int alturaDireita = calcularAlturaArvore(arvore->right);

        // A altura da árvore é a altura do caminho mais longo mais 1
        return 1 + (alturaEsquerda > alturaDireita ? alturaEsquerda : alturaDireita);
    }
}

// Função para calcular a altura de um nó específico na árvore
int calcularAlturaNoNaArvore(struct TreeNode* arvore, int valorNo) {
    if (arvore == NULL) {
        return 0; // Se a árvore estiver vazia, a altura é 0
    }

    if (valorNo < arvore->data) {
        return calcularAlturaNoNaArvore(arvore->left, valorNo) + 1;
    } else if (valorNo > arvore->data) {
        return calcularAlturaNoNaArvore(arvore->right, valorNo) + 1;
    } else {
        // Encontrou o nó desejado, a altura é 1
        return 1;
    }
}

// Função para calcular a altura de uma árvore binária
int calcularProfundidadeArvore(struct TreeNode* arvore) {
    if (arvore == NULL) {
        return 0;
    } else {
        int alturaEsquerda = calcularAlturaArvore(arvore->left);
        int alturaDireita = calcularAlturaArvore(arvore->right);

        // A altura da árvore é a altura do caminho mais longo mais 1
        return 1 + (alturaEsquerda > alturaDireita ? alturaEsquerda : alturaDireita);
    }
}

// Função para calcular a altura de um nó específico na árvore
int calcularProfundidadeNoNaArvore(struct TreeNode* arvore, int valorNo) {
    if (arvore == NULL) {
        return 0; // Se a árvore estiver vazia, a altura é 0
    }

    if (valorNo < arvore->data) {
        return calcularAlturaNoNaArvore(arvore->left, valorNo) + 1;
    } else if (valorNo > arvore->data) {
        return calcularAlturaNoNaArvore(arvore->right, valorNo) + 1;
    } else {
        // Encontrou o nó desejado, a altura é 1
        return 1;
    }
}

// Função para calcular o nível de um nó em relação à raiz da árvore
int calcularNivelNoNaArvore(struct TreeNode* arvore, int valorNo) {
    if (arvore == NULL) {
        return 0; // Se a árvore estiver vazia, o nível é 0
    }

    if (valorNo < arvore->data) {
        return 1 + calcularNivelNoNaArvore(arvore->left, valorNo);
    } else if (valorNo > arvore->data) {
        return 1 + calcularNivelNoNaArvore(arvore->right, valorNo);
    } else {
        // Encontrou o nó desejado, o nível é 1
        return 1;
    }
}

// Função para calcular o grau máximo de uma árvore binária
int calcularGrauMaximo(struct TreeNode* arvore) {
    if (arvore == NULL) {
        return 0; // Se a árvore estiver vazia, o grau máximo é 0
    }

    int grauEsquerda = calcularGrauMaximo(arvore->left);
    int grauDireita = calcularGrauMaximo(arvore->right);

    // O grau máximo da árvore é o maior grau entre a subárvore esquerda e direita
    return grauEsquerda > grauDireita ? grauEsquerda : grauDireita;
}
