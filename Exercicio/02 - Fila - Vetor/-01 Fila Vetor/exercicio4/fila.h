/*
* Arquivo: fila.h
* Biblicoteca de operações para fila implementada
* com vetor.
*/
#define VERDADEIRO 1
#define FALSO 0
#define max_voltas 2
#define max_element 1
struct tipo_fila {
elemento vet[TAM];
int inicio, fim, voltas;
};
typedef struct tipo_fila fila;
//Cria fila.
void CriarFila(fila *f) {
f->inicio = -1;
f->fim = 0;
f->voltas = 0;
}
//Verifica se a fila está vazia.
int FilaVazia(fila *f) {
return(f->inicio == TAM-1);
}
//Verifica se a fila está cheia.
int FilaCheia(fila *f) {
    if (max_element > TAM-1)
    {
        return(f->fim == TAM-1 && f->voltas == max_voltas);
    }else{
        return(f->fim == max_element && f->voltas == max_voltas);
    }
    
}
//Insere um elemento na fila.
void Enfileirar(fila *f, elemento e) {
    if (f->fim == TAM -1)
    {
        f->fim=-1;
        f->voltas++;
    }
    
f->vet[f->fim++] = e;
}
//Retira um elemento na fila.
elemento Desenfileirar(fila *f) {
return(f->vet[f->inicio++]);
}