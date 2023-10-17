#define TAM 10

struct tipo_lista {
    int vet[TAM];
    int tamanho;
};

typedef struct tipo_lista lista;

void CriarLista(lista *l) {
    l->tamanho = 0;
}

int ListaVazia(lista *l) {
    return (l->tamanho == 0);
}

int ListaCheia(lista *l) {
    return (l->tamanho == TAM);
}

void InserirInteiro(lista *l, int num) {
    if (ListaCheia(l)) {
        printf("ERRO: Lista cheia!\n");
    } else {
        l->vet[l->tamanho] = num;
        l->tamanho++;
    }
}

int RetirarInteiro(lista *l, int pos) {
    if (pos < 0 || pos >= l->tamanho) {
        return -1;
    }

    int elemento = l->vet[pos];
    for (int i = pos; i < l->tamanho - 1; i++) {
        l->vet[i] = l->vet[i + 1];
    }
    l->tamanho--;

    return elemento;
}

void ImprimirLista(lista *l) {
    if (ListaVazia(l)) {
        printf("A lista está vazia.\n");
    } else {
        printf("Elementos na lista: ");
        for (int i = 0; i < l->tamanho; i++) {
            printf("%d ", l->vet[i]);
        }
        printf("\n");
    }
}
