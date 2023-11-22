typedef struct {

TipoChave Chave;
/* outros componentes */

} Registro;

typedef struct Nodo_str *Apontador;

typedef struct Nodo_str {
Registro Reg;
Apontador Esq, Dir;

} Nodo;

typedef Apontador TipoDicionário;


void Inicia ( TipoDicionário *Dicionário )
{
*Dicionário = NULL;
}

typedef int TipoChave;

void main()
{
Registro x;
TipoDicionário Dicionário;
Inicia (&Dicionário);

printf("Informe a chave:");
scanf("%d”, &x.Chave);

while (x.Chave > 0) {
Insere (x, &Dicionário);
printf("Informe a chave:");
scanf ("%d”, &x.Chave);
}
}

void Insere ( Registro x, Apontador *p )
{
if ( *p == NULL ) {
*p = (Apontador) malloc ( sizeof ( Nodo ) );
(*p)->Reg = x;
(*p)->Esq = NULL;
(*p)->Dir = NULL;
return;
}
if ( x.Chave < (*p)->Reg.Chave ) {
Insere (x, &(*p)->Esq);
return;
}
if ( x.Chave > (*p)->Reg.Chave )
Insere ( x, &(*p)->Dir );
else
printf(" Registro existente na árvore \n”);
}

void Pesquisa ( Registro *x, Apontador p ){
    if (p == NULL) {
        printf ("Erro: Registro não está na árvore\n");
    return;
}
    if (x->Chave < p->Reg.Chave) {
        Pesquisa ( x, p->Esq );
    return;
}
    if ( x->Chave > p->Reg.Chave )
        Pesquisa ( x, p->Dir );
    else
        *x = p->Reg;
}


void Central ( Apontador p )
{
    if ( p != NULL ) {
        Central ( p->Esq );
            printf ( "%d\n", p->Reg.Chave );
        Central ( p->Dir );
    }
}