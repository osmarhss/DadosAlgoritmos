typedef int elemento;

typedef struct nodo {
    elemento e;
    struct nodo *prox;
} tnodo;

typedef tnodo *pilha;

void CriarPilha(pilha *topo) {
    *topo = NULL;
}

int PilhaVazia(pilha *topo) {
    return (*topo == NULL);
}

void Empilhar(pilha *topo, elemento x) {
    tnodo *aux = (tnodo *)malloc(sizeof(tnodo));
    aux->e = x;
    aux->prox = *topo;
    *topo = aux;
}

elemento Desempilhar(pilha *topo) {
    elemento x;
    tnodo *aux = *topo;
    *topo = (*topo)->prox;
    x = aux->e;
    free(aux);
    return x;
}
