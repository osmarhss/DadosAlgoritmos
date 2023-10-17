#include <stdio.h>
#include <stdlib.h>

#define TAM 10

typedef int elemento;

#include "lista.h"

int main() {
    double num; 
    int pos = 0;
    lista l;
    CriarLista(&l);

    while (ListaCheia(&l) == FALSO) {
        printf("\nInforme um numero inteiro: ");
        scanf("%d", &num);
        Alistar(&l, num, pos);
        pos++;
    }

    printf("\nNumeros informados: ");
    pos = 0;
    while (ListaVazia(&l) == FALSO) {
        num = Desalistar(&l, pos);
        printf("\n%d", num);
    }
    printf("\n");
    system("pause");
    return 0;
}
