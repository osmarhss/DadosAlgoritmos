#include <stdio.h>
#include <stdlib.h>
#include "Floresta.h"

void IniciaFloresta(Floresta *floresta) {
    for (int i = 0; i < 3; i++) {
        floresta->categorias[i].Raiz = NULL;
    }
}

void Insere(Registro *produto, Apontador *p) {
    if (*p == NULL) {
        *p = (Apontador)malloc(sizeof(Nodo));
        (*p)->Reg = *produto;
        (*p)->Esq = (*p)->Dir = NULL;
    } else {
        if (produto->Chave < (*p)->Reg.Chave) {
            Insere(produto, &(*p)->Esq);
        } else if (produto->Chave > (*p)->Reg.Chave) {
            Insere(produto, &(*p)->Dir);
        } else {
            printf("Chave duplicada: %d\n", produto->Chave);
        }
    }
}

void InsereProduto(Registro *produto, Floresta *floresta, int categoria) {
    Insere(produto, &floresta->categorias[categoria].Raiz);
}

void Pesquisa(Registro *produto, Apontador p) {
    if (p == NULL) {
        printf("Produto não encontrado.\n");
        return;
    }
    if (produto->Chave < p->Reg.Chave) {
        Pesquisa(produto, p->Esq);
    } else if (produto->Chave > p->Reg.Chave) {
        Pesquisa(produto, p->Dir);
    } else {
        printf("Produto encontrado: Chave %d\n", produto->Chave);
    }
}

void PesquisaProduto(TipoChave chave, Floresta *floresta, int categoria) {
    Registro produto = {chave};
    Pesquisa(&produto, floresta->categorias[categoria].Raiz);
}

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

void Retira(Registro *produto, Apontador *p) {
    Apontador Aux;
    if (*p == NULL) {
        printf("Produto não encontrado.\n");
        return;
    }
    if (produto->Chave < (*p)->Reg.Chave) {
        Retira(produto, &(*p)->Esq);
        return;
    }
    if (produto->Chave > (*p)->Reg.Chave) {
        Retira(produto, &(*p)->Dir);
        return;
    }
    if ((*p)->Dir == NULL) {
        Aux = *p;
        *p = (*p)->Esq;
        free(Aux);
        return;
    }
    if ((*p)->Esq == NULL) {
        Aux = *p;
        *p = (*p)->Dir;
        free(Aux);
        return;
    }
    Antecessor(*p, &(*p)->Esq);
}

void RemoveProduto(TipoChave chave, Floresta *floresta, int categoria) {
    Registro produto = {chave};
    Retira(&produto, &floresta->categorias[categoria].Raiz);
}

void PreOrdem(Apontador raiz) {
    if (raiz != NULL) {
        printf("%d\n", raiz->Reg.Chave);
        PreOrdem(raiz->Esq);
        PreOrdem(raiz->Dir);
    }
}

void Central(Apontador raiz) {
    if (raiz != NULL) {
        Central(raiz->Esq);
        printf("%d\n", raiz->Reg.Chave);
        Central(raiz->Dir);
    }
}

void PosOrdem(Apontador raiz) {
    if (raiz != NULL) {
        PosOrdem(raiz->Esq);
        PosOrdem(raiz->Dir);
        printf("%d\n", raiz->Reg.Chave);
    }
}

int main() {
    Floresta floresta;
    IniciaFloresta(&floresta);

    int opcao, categoria, chave;
    Registro produto;

    do {
        printf("\n1. Inserir Produto\n");
        printf("2. Pesquisar Produto\n");
        printf("3. Remover Produto\n");
        printf("4. Realizar Caminhamento\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Insira a categoria (0 a 2): ");
                scanf("%d", &categoria);
                printf("Insira a chave do produto: ");
                scanf("%d", &chave);
                produto.Chave = chave;
                InsereProduto(&produto, &floresta, categoria);
                break;
            case 2:
                printf("Insira a categoria (0 a 2): ");
                scanf("%d", &categoria);
                printf("Insira a chave do produto a pesquisar: ");
                scanf("%d", &chave);
                PesquisaProduto(chave, &floresta, categoria);
                break;
            case 3:
                printf("Insira a categoria (0 a 2): ");
                scanf("%d", &categoria);
                printf("Insira a chave do produto a remover: ");
                scanf("%d", &chave);
                RemoveProduto(chave, &floresta, categoria);
                break;
            case 4:
                printf("Insira a categoria (0 a 2) para caminhamento: ");
                scanf("%d", &categoria);
                printf("Caminhamento Pré-ordem:\n");
                PreOrdem(floresta.categorias[categoria].Raiz);
                
                printf("\nCaminhamento em Ordem Central:\n");
                Central(floresta.categorias[categoria].Raiz);
                
                printf("\nCaminhamento Pós-ordem:\n");
                PosOrdem(floresta.categorias[categoria].Raiz);
                break;
            case 5:
                return 0;
            default:
                printf("Opcao invalida!\n");
                break;
        }
    } while (opcao != 5);

    return 0;
}



