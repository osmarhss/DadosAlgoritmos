#include "ArvoreBinariaDePesquisa.h"
#include <stdio.h>
#include <stdlib.h>

void Inicia(TipoDicionario *Dicionario) {
    *Dicionario = NULL;
}

void Insere(Registro x, Apontador *p) {
    if (*p == NULL) {
        *p = (Apontador)malloc(sizeof(Nodo));
        if (*p == NULL) {
            printf("Erro: Falha na alocação de memória.\n");
            exit(EXIT_FAILURE);
        }
        (*p)->Reg = x;
        (*p)->Esq = NULL;
        (*p)->Dir = NULL;
        return;
    }
    if (x.Chave < (*p)->Reg.Chave) {
        Insere(x, &(*p)->Esq);
        return;
    }
    if (x.Chave > (*p)->Reg.Chave)
        Insere(x, &(*p)->Dir);
    else
        printf("Registro existente na árvore\n");
}

void Pesquisa(Registro *x, Apontador p) {
    if (p == NULL) {
        printf("Erro: Registro não está na árvore\n");
        return;
    }
    if (x->Chave < p->Reg.Chave) {
        Pesquisa(x, p->Esq);
        return;
    }
    if (x->Chave > p->Reg.Chave)
        Pesquisa(x, p->Dir);
    else
        *x = p->Reg;
}

void Central(Apontador p) {
    if (p != NULL) {
        Central(p->Esq);
        printf("%d\n", p->Reg.Chave);
        Central(p->Dir);
    }
}
