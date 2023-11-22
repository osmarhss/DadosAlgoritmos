#ifndef FLORESTA_H
#define FLORESTA_H

// Estrutura de um nó de árvore binária de pesquisa
typedef struct NoArvore {
    int valor; // valor do nó
    struct NoArvore *esquerda;
    struct NoArvore *direita;
} NoArvore;

// Estrutura de uma árvore binária de pesquisa
typedef struct {
    NoArvore *raiz;
} ArvoreBinaria;

// Estrutura da floresta de árvores binárias de pesquisa
typedef struct {
    ArvoreBinaria *arvores; // Array de árvores
    int numArvores;         // Número atual de árvores na floresta
    int capacidade;          // Capacidade máxima da floresta
} Floresta;

// Funções para manipulação da floresta de árvores binárias de pesquisa
void inicializarFloresta(Floresta *floresta, int capacidade);
void inserirArvore(Floresta *floresta);
void inserirNaArvore(ArvoreBinaria *arvore, int valor);
void pesquisarNaFloresta(Floresta *floresta, int valor);
void excluirNaFloresta(Floresta *floresta, int valor);
void percursoPreOrdem(Floresta *floresta);
void percursoEmOrdem(Floresta *floresta);
void percursoPosOrdem(Floresta *floresta);

#endif /* FLORESTA_H */
