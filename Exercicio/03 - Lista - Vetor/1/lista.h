#define VERDADEIRO 1
#define FALSO 0

struct tipo_lista {
    int vet[TAM];
    int inicio, fim;
};

typedef struct tipo_lista lista;

//Cria lista.
void CriarLista(lista *l) {
    l->inicio = -1;
    l->fim = -1;
}

//Verifica se a lista está vazia
int ListaVazia(lista *l) {
    return (l->inicio == -1 && l->fim == -1);
}

//Verifica se a lista está cheia.
int ListaCheia(lista *l) {
    return (l->fim == TAM - 1);
}

//Insere um elemento na lista.
void Alistar(lista *l, double e, int pos) {
    int i;

    if (ListaCheia(l))
        printf("\n ERRO: lista cheia!");
    else if (pos < 0 || pos > l->fim + 1) {
        printf("\n ERRO: posição não existe!");
        printf("\n Posicoes validas: [0, %d].", l->fim);
    } else {
        for (i = l->fim; i >= pos; i--)
            l->vet[i + 1] = l->vet[i];
        l->vet[pos] = e;
        if (ListaVazia(l))
            l->inicio = 0;
        l->fim++;
    }
}
//Retira um elemento da lista.
int Desalistar(lista *l, int pos) {
    int i, e;

    if (ListaVazia(l))
        printf("\n ERRO: lista vazia!");
    else if (pos < 0 || pos > l->fim) {
        printf("\n ERRO: posição não existe!");
        printf("\n Posicoes validas: [0, %d].", l->fim - 1);
    } else {
        e = l->vet[pos];
        for (i = pos; i < l->fim; i++)
            l->vet[i] = l->vet[i + 1];
        l->fim--;
        if (l->fim == -1) // se a lista estiver vazia
            l->inicio = -1;
    }
    return e;
}
//Imprime a lista.
void ImprimirLista(lista *l) {
    if (ListaVazia(l)) {
        printf("A lista está vazia.\n");
    } else {
        printf("Elementos na lista: ");
        for (int i = l->inicio; i <= l->fim; i++) {
            printf("%d ", l->vet[i]);
        }
        printf("\n");
    }
}
