#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinariaDePesquisa.h"

void Inicia(TipoDicionario *Dicionario) {
    *Dicionario = NULL;
}

void Insere(Registro x, Apontador *p) {
    if (x.Chave == 0) {
        printf("Insercao finalizada.\n");
        return;
    }

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
    }

    printf("Registro existente na árvore.\n");
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

    if (x->Chave > p->Reg.Chave) {
        Pesquisa(x, p->Dir);
        return;
    }

    *x = p->Reg;
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

    if ((*p)->Dir != NULL && (*p)->Esq != NULL) {
        Antecessor(*p, &(*p)->Esq);
        return;
    }

    Aux = *p;
    if ((*p)->Dir == NULL) {
        *p = (*p)->Esq;
    } else {
        *p = (*p)->Dir;
    }
    free(Aux);
}


void Antecessor(Apontador q, Apontador *r) {
    if ((*r)->Dir != NULL) {
        Antecessor(q, &(*r)->Dir);
        return;
    }

    q->Reg = (*r)->Reg;
    Antecessor(*r, &(*r)->Esq);
}

int main() {
    Registro x;
    TipoDicionario Dicionario;
    Inicia(&Dicionario);

    printf("Informe a chave: ");
    scanf("%d", &x.Chave);

    while (x.Chave > 0) {
        Insere(x, &Dicionario);
        printf("Informe a chave: ");
        scanf("%d", &x.Chave);
    }

    printf("Realizando Pesquisa:\n");
    printf("Informe a chave para pesquisa: ");
    scanf("%d", &x.Chave);
    Pesquisa(&x, Dicionario);

    printf("Realizando Caminhamentos:\n");
    printf("Caminhamento Central:\n");
    Central(Dicionario);

    printf("Caminhamento Pre-Ordem:\n");
    PreOrdem(Dicionario);

    printf("Caminhamento Pos-Ordem:\n");
    PosOrdem(Dicionario);

    printf("Removendo elementos:\n");
    printf("Informe a chave para remoção: ");
    scanf("%d", &x.Chave);
    Retira(x, &Dicionario);
    
    printf("Realizando novamente a Pesquisa:\n");
    printf("Informe a chave para pesquisa: ");
    scanf("%d", &x.Chave);
    Pesquisa(&x, Dicionario);
    
    Registro elementoRemover;
    printf("Removendo elementos:\n");
    while (1) {
        printf("Informe a chave para remoção (digite 0 para encerrar): ");
        scanf("%d", &elementoRemover.Chave);
        
        if (elementoRemover.Chave == 0) {
            printf("Remoção finalizada.\n");
            break;
        }
        Retira(elementoRemover, &Dicionario);
        // Para verificar se o elemento foi removido corretamente
        printf("Caminhamento Central após remoção:\n");
        Central(Dicionario);
        printf("\n");
    }

    
    return 0;
}
