#define VERDADEIRO 1
#define FALSO 0

typedef struct livro {
    char titulo[100];
    char autor[100];
    int edicao;
} Livro;

typedef struct nodo *pilha;
typedef struct nodo *pt_nodo;

typedef struct nodo {
    Livro livro;
    pt_nodo prox;
} tnodo;

void CriarPilha(pilha *topo) {
    *topo = NULL;
}

int PilhaVazia(pilha topo) {
    return (topo == NULL);
}


void Empilhar(pilha *topo, Livro livro) {
    pt_nodo aux = (pt_nodo)malloc(sizeof(tnodo));
    aux->livro = livro;
    aux->prox = *topo;
    *topo = aux;
}

Livro Desempilhar(pilha *topo) {
    Livro livro;
    pt_nodo aux = *topo;
    *topo = (*topo)->prox;
    livro = aux->livro;
    free(aux);
    return livro;
}

void ImprimirPilha(pilha topo) {
    printf("\nLivros na pilha:\n");
    pilha temp = NULL;
    while (PilhaVazia(topo) == FALSO) {
        Livro livro = Desempilhar(&topo);
        printf("Título: %s, Autor: %s, Edição: %d\n", livro.titulo, livro.autor, livro.edicao);
        Empilhar(&temp, livro);
    }

    while (PilhaVazia(temp) == FALSO) {
        Livro livro = Desempilhar(&temp);
        Empilhar(&topo, livro);
    }
}


void ImprimirPilhaArquivo(pilha topo, const char *nome_arquivo) {
    FILE *arquivo = fopen(nome_arquivo, "wb");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    pilha temp = NULL;
    while (PilhaVazia(topo) == FALSO) {
        Livro livro = Desempilhar(&topo);
        fwrite(&livro, sizeof(Livro), 1, arquivo);
        Empilhar(&temp, livro);
    }

    while (PilhaVazia(temp) == FALSO) {
        Livro livro = Desempilhar(&temp);
        Empilhar(&topo, livro);
    }

    fclose(arquivo);
}

void LerPilhaArquivo(pilha *topo, const char *nome_arquivo) {
    FILE *arquivo = fopen(nome_arquivo, "rb");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    Livro livro;
    while (fread(&livro, sizeof(Livro), 1, arquivo)) {
        Empilhar(topo, livro);
    }

    fclose(arquivo);
}

int QuantidadeLivrosAteTitulo(pilha *topo, const char *titulo_desejado) {
    int cont = 0;
    pilha temp = NULL;
    while (PilhaVazia(*topo) == FALSO) {
        cont++;
        Livro livro = Desempilhar(topo);
        Empilhar(&temp, livro);
        if (strcmp(livro.titulo, titulo_desejado) == 0) {
            break;
        }
    }

    while (PilhaVazia(temp) == FALSO) {
        Livro livro = Desempilhar(&temp);
        Empilhar(topo, livro);
    }

    if (PilhaVazia(*topo)) {
        return -1;
    } else {
        return cont;
    }
}
