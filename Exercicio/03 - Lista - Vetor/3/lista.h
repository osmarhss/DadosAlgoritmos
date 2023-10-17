#define VERDADEIRO 1
#define FALSO 0
#define TAM 10

struct tipo_funcionario {
    long CPF;
    char nome[50];
    char endereco[100];
    long telefone;
    long celular;
    char data_nascimento[11];
    char data_admissao[11];
    char departamento[50];
    char cargo[50];
    float salario;
};

struct tipo_lista {
    struct tipo_funcionario vet[TAM];
    int inicio, fim;
};

typedef struct tipo_lista lista;

//Cria lista.
void CriarLista(lista *l){
    l->inicio = -1;
    l->fim = -1;
}


//Verifica se a lista está vazia
int ListaVazia(lista *l){
    return (l->inicio == -1 && l->fim == -1);
}

//Verifica se a lista está cheia.
int ListaCheia(lista *l){
    return (l->fim == TAM - 1);
}

//Insere um funcionário na lista.
void Alistar(lista *l, struct tipo_funcionario f){
    if (ListaCheia(l))
        printf("\n ERRO: lista cheia!");
    else {
        if (l->inicio == -1) {
            l->inicio = 0;
        }
        l->fim++;
        l->vet[l->fim] = f;
    }
}

//Retira um funcionário da lista.
struct tipo_funcionario Desalistar(lista *l){
    struct tipo_funcionario f;
    if (ListaVazia(l)) {
        printf("\n ERRO: lista vazia!");
        return f;
    } else {
        f = l->vet[l->inicio];
        if (l->inicio == l->fim) {
            l->inicio = -1;
            l->fim = -1;
        } else {
            for (int i = 0; i < l->fim; i++) {
                l->vet[i] = l->vet[i + 1];
            }
            l->fim--;
        }
        return f;
    }
}


//Imprime a lista.
void ImprimirLista(lista *l) {
    if (ListaVazia(l)) {
        printf("A lista está vazia.\n");
    } else {
        printf("Funcionários na lista: \n");
        for (int i = l->inicio; i <= l->fim; i++) {
            printf("CPF: %lld, Nome: %s, Endereço: %s, Telefone: %lld, Celular: %lld, Data de Nascimento: %s, Data de Admissão: %s, Departamento: %s, Cargo: %s, Salário: %.2f\n",
                l->vet[i].CPF, l->vet[i].nome, l->vet[i].endereco, l->vet[i].telefone, l->vet[i].celular, l->vet[i].data_nascimento, l->vet[i].data_admissao, l->vet[i].departamento, l->vet[i].cargo, l->vet[i].salario);
        }
        printf("\n");
    }
}


//Desalista para arquivo.
void DesalistePArquivo(lista *l, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    while (!ListaVazia(l)) {
        struct tipo_funcionario f = Desalistar(l);
        fprintf(arquivo, "%lld;%s;%s;%lld;%lld;%s;%s;%s;%s;%.2f\n",
            f.CPF, f.nome, f.endereco, f.telefone, f.celular, f.data_nascimento, f.data_admissao, f.departamento, f.cargo, f.salario);
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

    while (!ListaCheia(l)) {
        struct tipo_funcionario f;
        fscanf(arquivo, "%lld;%[^;];%[^;];%lld;%lld;%[^;];%[^;];%[^;];%[^;];%f\n",
            &f.CPF, f.nome, f.endereco, &f.telefone, &f.celular, f.data_nascimento, f.data_admissao, f.departamento, f.cargo, &f.salario);
        Alistar(l, f);
    }

    fclose(arquivo);
}


//Pesquisa um funcionário por CPF.
void PesquisarPorCPF(lista *l) {
long CPF;
    printf("Digite o CPF a ser pesquisado: ");
    scanf("%lld", &CPF);
    int encontrado = 0;
    for (int i = l->inicio; i <= l->fim; i++) {
        if (l->vet[i].CPF == CPF) {
            printf("Funcionário encontrado:\n");
            printf("CPF: %lld, Nome: %s, Endereço: %s, Telefone: %lld, Celular: %lld, Data de Nascimento: %s, Data de Admissão: %s, Departamento: %s, Cargo: %s, Salário: %.2f\n",
                l->vet[i].CPF, l->vet[i].nome, l->vet[i].endereco, l->vet[i].telefone, l->vet[i].celular, l->vet[i].data_nascimento, l->vet[i].data_admissao, l->vet[i].departamento, l->vet[i].cargo, l->vet[i].salario);
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("Funcionário não encontrado.\n");
    }
}