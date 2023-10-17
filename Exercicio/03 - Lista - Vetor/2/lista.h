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
void Alistar(lista *l, float e) {
    if (ListaCheia(l))
        printf("\n ERRO: lista cheia!");
    else {
        if (l->inicio == -1) {
            l->inicio = 0;
        }
        l->fim++;
        l->vet[l->fim] = e;
    }
}

//Retira um elemento da lista.
float Desalistar(lista *l) {
    float e;
    if (ListaVazia(l)) {
        printf("\n ERRO: lista vazia!");
        return 0.0; // ou algum valor de erro adequado
    } else {
        e = l->vet[l->inicio];
        if (l->inicio == l->fim) {
            l->inicio = -1;
            l->fim = -1;
        } else {
            for (int i = 0; i < l->fim; i++) {
                l->vet[i] = l->vet[i + 1];
            }
            l->fim--;
        }
        return e;
    }
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


// Desalista para arquivo.
void DesalistePArquivo(lista *l, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    while (!ListaVazia(l)) {
        float num = Desalistar(l);
        fprintf(arquivo, "%f\n", num);
    }

    fclose(arquivo);
}

//Lê do arquivo para a lista.
void ArquivoPLista(lista *l, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    float num;
    while (fscanf(arquivo, "%f", &num) != EOF) {
        Alistar(l, num);
    }

    fclose(arquivo);
}
