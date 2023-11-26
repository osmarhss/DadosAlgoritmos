#ifndef ARVORE_BINARIA_DE_PESQUISA_H
#define ARVORE_BINARIA_DE_PESQUISA_H

typedef int TipoChave;

typedef struct {
    TipoChave Chave;
} Registro;

typedef struct Nodo_str *Apontador;

typedef struct Nodo_str {
    Registro Reg;
    Apontador Esq, Dir;
} Nodo;

typedef Apontador TipoDicionário;

void Inicia(TipoDicionário *Dicionário);
void Insere(Registro x, Apontador *p);
void Pesquisa(Registro *x, Apontador p);
void Central(Apontador p);
void PreOrdem(Apontador p);
void PosOrdem(Apontador p);
void Retira(Registro x, Apontador *p);
void Antecessor(Apontador q, Apontador *r);

#endif /* ARVORE_BINARIA_DE_PESQUISA_H */
