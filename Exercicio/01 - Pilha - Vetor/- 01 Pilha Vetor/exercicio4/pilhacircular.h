/*
* Arquivo: pilha.h
* Biblicoteca de operações para pilha
* implementada com vetor.
*/
#define VERDADEIRO 1
#define FALSO 0

struct tipo_pilha {
elemento vet[TAM];
int topo, voltas;
};

typedef struct tipo_pilha pilha;

//Cria pilha.
void CriarPilha(pilha *p) {
    p->topo = 0;
    p->voltas = 0;
}

//Verifica se a pilha está vazia.
int PilhaVazia(pilha *p, int tamanhoVetor) {
    return(tamanhoVetor == 0);
}

//Verifica se a pilha está cheia.
int LimitePilha(pilha *p) {
    return(p->topo == TAM);
}

//Verifica se a pilha está realmente cheia e não vai mais poder acrecentar valores.
int PilhaCheia(pilha *p) {
    return(p->topo == limite_vetor && p->voltas == limite_voltas);
}

//Insere um elemento na pilha.
void Empilhar(pilha *p, elemento e) {
    p->vet[p->topo] = e;
    p->topo++;
    if (LimitePilha(p) == VERDADEIRO)
    {
        p->topo = 0;
        p->voltas++;
    }

}

//Retira um elemento na pilha.
elemento Desempilhar(pilha *p, int tamanhoVetor) {
    return p->vet[tamanhoVetor];
}