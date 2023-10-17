#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main() {
    lista l;
    CriarLista(&l);

    
    for (int i = 0; i < 10; i++) {
        int num;
        printf("Insira um número inteiro: ");
        scanf("%d", &num);
        InserirInteiro(&l, num);
    }

    while (!ListaVazia(&l)) {
        printf("\n Imprimindo a lista de inteiros:\n");
        ImprimirLista(&l);

        int pos;
        printf("Digite a posição do elemento a ser retirado (0 a %d, ou -1 para encerrar): ", l.tamanho - 1);
        scanf("%d", &pos);

        if (pos < 0) {
            
            break;
        } else if (pos >= 0 && pos < l.tamanho) {
            int elemento = RetirarInteiro(&l, pos);
            printf("Elemento retirado: %d\n", elemento);
        } else {
            printf("Posição inválida! Tente novamente.\n");
        }
    }

    if (ListaVazia(&l)) {
        printf("A lista está vazia!\n");
    } else {
        printf("\n Imprimindo a lista de inteiros restante:\n");
        ImprimirLista(&l);
    }

    return 0;
}
