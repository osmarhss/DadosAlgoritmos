/*2. Compare a biblioteca abaixo com a apresentada nesta prática. Quais as diferenças entre essas
bibliotecas*/


/*---------------------------------------------------------------------------------------------------------*/

/* Arquivo: lista.h
* Biblicoteca de operações para lista implementada com ponteiro.
>> R:Não é usado as bibliotecas stdio.h, stdlib.h e lista.h é usado o metodo typedef struct
*/
#define VERDADEIRO 1
#define FALSO 0

typedef struct nodo *lista;
typedef struct nodo *pt_nodo;
typedef struct nodo { elemento e;
        pt_nodo prox;
        } tnodo;
/*
* Cria uma lista vazia. 
>> R: é criada uma lista vazia , nos exemplos é apresentado uma lista  a ser preenchida.
*/
void CriarLista (lista *l) {
*l = NULL;
}
/*
* Verifica se a lista está vazia.
>> R: Aqui é feito uma verificaçãos e a mesma esta vazia, sendo que no código de exemplo é feito uma listagem
enfileiração dos elementos, 
*/
int ListaVazia (lista *l) {
return (*l == NULL);
}

/*
* Insere um novo elemento após o nodo apontado por "pred".
*/
void Alistar (lista *l, elemento x, pt_nodo pred) {
pt_nodo p;
p = (pt_nodo) malloc (sizeof (tnodo));
p->e = x;
    if (pred == NULL) {
        p->prox = *l;
            *l = p;
        }
    else {
            p->prox = pred->prox;
            pred->prox = p;
}
}
/*
* Retira o elemento que está após o nodo apontado por "pred".
>> R: Aqui é usado o pt_nodo , codigo exemplo não é usado 
*/
elemento Desalistar (lista *l, pt_nodo pred) {
elemento x;
pt_nodo p;
if (pred == NULL) {
p = *l;
*l = p->prox;
}
else {
p = pred->prox;
pred->prox = p->prox;
}
x = p->e;
free (p);
return x;
}

/*
* Procura um elemento na lista.
* Retorna a posição anterior ao elemento procurado.
* Se o elemento procurado estiver na lista, retorna VERDADEIRO.
* Se o elemento procurado não estiver na lista, retorna FALSO.
*/
int PesquisarLista (lista *l, elemento x, pt_nodo *pred) {
int achou = FALSO;
pt_nodo p = *l;
while (p != NULL)
if (p->e == x) {
achou = VERDADEIRO;
break;
}
else {
*pred = p;
p = p->prox;
}
return achou;
}