#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinariaDePesquisa.h"

void Inicia(TipoDicionário *Dicionário) {
    *Dicionário = NULL;
}

void Insere(Registro x, Apontador *p) {
    if (*p == NULL) {
        *p = (Apontador)malloc(sizeof(Nodo));
        (*p)->Reg = x;
        (*p)->Esq = NULL;
        (*p)->Dir = NULL;
        return;
    }
    if (x.Chave < (*p)->Reg.Chave) {
        Insere(x, &(*p)->Esq);
        return;
    }
    if (x.Chave > (*p)->Reg.Chave) {
        Insere(x, &(*p)->Dir);
        return;
    } else {
        printf("Registro existente na árvore\n");
    }
}

void Pesquisa(Registro *x, Apontador p) {
    if (p == NULL) {
        printf("Erro: Registro não está na árvore\n");
        return;
    }
    if (x->Chave < p->Reg.Chave) {
        Pesquisa(x, p->Esq);
    } else if (x->Chave > p->Reg.Chave) {
        Pesquisa(x, p->Dir);
    } else {
        *x = p->Reg; // Atribuir diretamente o registro encontrado para x
        return;
    }
}


void Central(Apontador p) {
    if (p != NULL) {
        Central(p->Esq);
        printf("%d\n", p->Reg.Chave);
        Central(p->Dir);
    }
}

void PreOrdem(Apontador p) {
    if (p != NULL) {
        printf("%d\n", p->Reg.Chave);
        PreOrdem(p->Esq);
        PreOrdem(p->Dir);
    }
}

void PosOrdem(Apontador p) {
    if (p != NULL) {
        PosOrdem(p->Esq);
        PosOrdem(p->Dir);
        printf("%d\n", p->Reg.Chave);
    }
}

void Retira(Registro x, Apontador *p) {
}

void Antecessor(Apontador q, Apontador *r) {
}

int main() {
    Registro x;''
    TipoDicionário Dicionário;
    Inicia(&Dicionário);

    printf("Informe a chave: ");
    scanf("%d", &x.Chave);

    while (x.Chave > 0) {
        Insere(x, &Dicionário);
        printf("Informe a chave: ");
        scanf("%d", &x.Chave);
    }

    // Teste da função de pesquisa
    printf("Pesquisar por chave: ");
    scanf("%d", &x.Chave);
    Registro resultadoPesquisa;
    Pesquisa(&resultadoPesquisa, Dicionário);
    printf("Resultado da pesquisa:%d\n", resultadoPesquisa.Chave);

    // Teste da função Central
    printf("Impressão em ordem central:\n");
    Central(Dicionário);

    // Teste da função PreOrdem
    printf("Impressão em pré-ordem:\n");
    PreOrdem(Dicionário);

    // Teste da função PosOrdem
    printf("Impressão em pós-ordem:\n");
    PosOrdem(Dicionário);

    // Teste da função Retira
    void Retira(Registro x, Apontador *p) {
    Apontador Aux;
    if (*p == NULL) {
        printf("Erro: Registro não está na árvore\n");
        return;
    }
    if (x.Chave < (*p)->Reg.Chave) {
        Retira(x, &(*p)->Esq);
        return;
    }
    if (x.Chave > (*p)->Reg.Chave) {
        Retira(x, &(*p)->Dir);
        return;
    }
    if ((*p)->Dir == NULL) { // Se não tiver filho à direita
        Aux = *p;
        *p = (*p)->Esq;
        free(Aux);
        return;
    }
    if ((*p)->Esq == NULL) { // Se não tiver filho à esquerda
        Aux = *p;
        *p = (*p)->Dir;
        free(Aux);
        return;
    }
    // Se tiver dois filhos
    Antecessor(*p, &(*p)->Esq);
}

    // Teste da função Antecessor
    
    void Antecessor(Apontador q, Apontador *r) {
    if ((*r)->Dir != NULL) {
        Antecessor(q, &(*r)->Dir);
        return;
    }
    q->Reg = (*r)->Reg;
    q = *r;
    *r = (*r)->Esq;
    free(q);
}

    return 0;
}