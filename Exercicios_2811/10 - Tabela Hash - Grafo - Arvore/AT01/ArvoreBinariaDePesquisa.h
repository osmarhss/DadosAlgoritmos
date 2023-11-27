#ifndef ARVOREBINARIADEPESQUISA_H
#define ARVOREBINARIADEPESQUISA_H

typedef int TipoChave;

typedef struct {
    TipoChave Chave;
    /* outros componentes */
} Registro;

typedef struct Nodo {
    Registro Reg;
    struct Nodo *Esq, *Dir;
} Nodo;

typedef Nodo *Apontador;
typedef Apontador TipoDicionario;

void Inicia(TipoDicionario *Dicionario);
void Insere(Registro x, Apontador *p);
void Pesquisa(Registro *x, Apontador p);
void Central(Apontador p);

#endif /* ARVOREBINARIADEPESQUISA_H */
