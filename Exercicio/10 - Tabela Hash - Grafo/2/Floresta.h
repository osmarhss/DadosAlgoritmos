#ifndef FLORESTA_H
#define FLORESTA_H

typedef int TipoChave;

typedef struct {
    TipoChave Chave;
} Registro;

typedef struct Nodo_str *Apontador;

typedef struct Nodo_str {
    Registro Reg;
    Apontador Esq, Dir;
} Nodo;

typedef struct {
    Apontador Raiz;
} ArvoreCategoria;

typedef struct {
    ArvoreCategoria categorias[3]; // Três categorias diferentes de produtos
} Floresta;

void IniciaFloresta(Floresta *floresta);
void Insere(Registro *produto, Apontador *p);
void InsereProduto(Registro *produto, Floresta *floresta, int categoria);
void Pesquisa(Registro *produto, Apontador p);
void PesquisaProduto(TipoChave chave, Floresta *floresta, int categoria);
void Antecessor(Apontador q, Apontador *r);
void Retira(Registro *produto, Apontador *p);
void RemoveProduto(TipoChave chave, Floresta *floresta, int categoria);
void PreOrdem(Apontador raiz);
void Central(Apontador raiz);
void PosOrdem(Apontador raiz);

#endif
