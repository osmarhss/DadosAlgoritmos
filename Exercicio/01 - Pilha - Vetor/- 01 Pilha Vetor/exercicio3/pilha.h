/*
* Arquivo: pilha.h
* Biblicoteca de operações para pilha
* implementada com vetor.
*/
#define VERDADEIRO 1
#define FALSO 0
struct Pessoa {
    char cpf[50];
    char nome[50];
    char endereco[50];
    char telefone[50];
    char celular[50];
    char data_de_nascimento[50];
    char data_de_admisao[50];
    char departamento[50];
    char cargo[50];
    float salario;
};
typedef struct Pessoa pessoa;
struct tipo_pilha {
pessoa vet[TAM];
int topo;
};
typedef struct tipo_pilha pilha;
//Cria pilha.
void CriarPilha(pilha *p) {
p->topo = 0;
}
//Verifica se a pilha está vazia.
int PilhaVazia(pilha *p) {
return(p->topo == 0);
}
//Verifica se a pilha está cheia.
int PilhaCheia(pilha *p) {
return(p->topo == TAM);
}
//Insere um pessoa na pilha.
void Empilhar(pilha *p, pessoa e) {
p->vet[p->topo] = e;
p->topo++;
}
//Retira um pessoa na pilha.
pessoa Desempilhar(pilha *p) {
p->topo--;
return p->vet[p->topo];
}

void empilharArquivo(pilha *p, char nome_arquivo[50]) {
    int quantidade;
    FILE *arq;

    if ((arq = fopen (nome_arquivo, "wb")) == NULL) {
        printf ("\n Erro ao abrir o arquivo arquivoC.dat.");
        system ("pause");
        exit (1);
    }

    quantidade = fwrite (&p, sizeof (pessoa), TAM, arq);
    printf ("Quantidade de itens gravados: %d.\n",
    quantidade);
    fclose (arq);
}

void desempilharArquivo(pilha *p, char nome_arquivo[50]) {
    int quantidade;
    FILE *arq;
    printf("wgwhiuhrieuhbiuebiueb");
    if ((arq = fopen (nome_arquivo, "rb")) == NULL) {
        printf ("\n Erro ao abrir o arquivo arquivoC.dat.");
        system ("pause");
        exit (1);
    }

    quantidade = fread (&p, sizeof (pessoa), TAM, arq);

    printf ("Quantidade de itens lidos: %d.\n", quantidade);
    fclose (arq);
}