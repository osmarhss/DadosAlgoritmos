#define TAM 10

struct tipo_produto {
    char nome[50];
    float valor_unitario;
    int quantidade_estoque;
};

struct tipo_lista {
    struct tipo_produto vet[TAM];
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

void InserirProduto(lista *l, struct tipo_produto p) {
    if (ListaCheia(l)) {
        printf("ERRO: Lista cheia!\n");
    } else {
        l->vet[l->tamanho] = p;
        l->tamanho++;
    }
}

int PesquisarProduto(lista *l, char *nome) {
    for (int i = 0; i < l->tamanho; i++) {
        if (strcmp(l->vet[i].nome, nome) == 0) {
            return i;
        }
    }
    return -1;
}

void ExcluirProduto(lista *l, int pos) {
    if (pos >= 0) {
        for (int i = pos; i < l->tamanho - 1; i++) {
            l->vet[i] = l->vet[i + 1];
        }
        l->tamanho--;
        printf("Produto excluído com sucesso.\n");
    }
}

void ImprimirLista(lista *l) {
    if (ListaVazia(l)) {
        printf("A lista está vazia.\n");
    } else {
        printf("Produtos na lista: \n");
        for (int i = 0; i < l->tamanho; i++) {
            printf("Nome: %s, Valor unitário: %.2f, Quantidade em estoque: %d\n", l->vet[i].nome, l->vet[i].valor_unitario, l->vet[i].quantidade_estoque);
        }
        printf("\n");
    }
}

void GravarLista(lista *l, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para gravação.\n");
        return;
    }
    fwrite(l, sizeof(lista), 1, arquivo);
    fclose(arquivo);
}


void LerLista(lista *l, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }
    fread(l, sizeof(lista), 1, arquivo);
    fclose(arquivo);
}
