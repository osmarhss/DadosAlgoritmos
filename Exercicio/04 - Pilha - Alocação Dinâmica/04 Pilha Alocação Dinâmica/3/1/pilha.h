typedef int elemento;

typedef struct nodo {
    elemento e;
    struct nodo *prox;
    struct nodo *ant;
} tnodo;

typedef tnodo *pilha;

void CriarPilha(pilha *topo) {
    *topo = NULL;
}

int PilhaVazia(pilha *topo) {
    return (*topo == NULL);
}

void Empilhar(pilha *topo, elemento x) {
    tnodo *novo = (tnodo *)malloc(sizeof(tnodo));
    novo->e = x;
    novo->prox = *topo;
    novo->ant = NULL;
    if (*topo != NULL) {
        (*topo)->ant = novo;
    }
    *topo = novo;
}

elemento Desempilhar(pilha *topo) {
    if (PilhaVazia(topo)) {
        fprintf(stderr, "Erro: Pilha vazia.\n");
        exit(EXIT_FAILURE);
    }
    elemento x;
    tnodo *temp = *topo;
    *topo = (*topo)->prox;
    if (*topo != NULL) {
        (*topo)->ant = NULL;
    }
    x = temp->e;
    free(temp);
    return x;
}

