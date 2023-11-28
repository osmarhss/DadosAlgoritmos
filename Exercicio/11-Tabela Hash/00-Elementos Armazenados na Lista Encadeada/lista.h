/* Arquivo: lista.h
 * Biblicoteca de operações para lista implementada com alocação dinâmica de
 * memória.
 */

#define VERDADEIRO 1
#define FALSO      0

typedef struct TipoNodo *lista;
typedef struct TipoNodo *pt_nodo;

typedef struct TipoNodo {
  elemento e;
  pt_nodo prox;
} nodo;

/*
 * Cria uma lista vazia.
 */
void CriarLista (lista *l) {
  *l = NULL;
}

/*
 * Verifica se a lista está vazia.
 */
int ListaVazia (lista *l) {
  return (*l == NULL);
}

/*
 * Insere um novo elemento após o nodo apontado por "pred".
 */
void Alistar (pt_nodo *pred, elemento *x) {
  pt_nodo p;
  p = (pt_nodo) malloc (sizeof (nodo));
  p->e = *x;

  if (*pred != NULL)
	 p->prox = *pred;
  else
	 p->prox = NULL;

  *pred = p;
}

/*
 * Retira o elemento que está após o nodo apontado por "pred". A lista não pode
 * estar vazia.
 */
elemento Desalistar (pt_nodo *pred) {
  elemento x;
  pt_nodo p;

  p = *pred;
  *pred = (*pred)->prox;

  x = p->e;
  free (p);
  return x;
}

/*
 * Procura um elemento na lista.
 * Retorna a posição anterior ao elemento procurado.
 * Se o elemento procurado estiver na lista, retorna VERDADEIRO.
 * Se o elemento procurado n�o estiver na lista, retorna FALSO.
 */
pt_nodo* PesquisarLista (pt_nodo *pred, char *x) {
  pt_nodo *p;

  p = NULL;

  while (*pred != NULL)
	 if (strcmp ((*pred)->e.palavra, x) == 0) {
		p = pred;
		break;
	 }
	 else
		pred = &((*pred)->prox);

  return p;
}

