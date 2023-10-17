#include <stdio.h>
#include <stdlib.h>

#define TAM 10

typedef int elemento;

#include "lista.h"

int main() {
    float num; 
    int pos = 0;
    lista l;
    CriarLista(&l);

    while (ListaCheia(&l) == FALSO) {
        printf("Insira 10 números reais na lista:\n");
        scanf("%f", &num);
        Alistar(&l, num);
        pos++;
    }

    
    printf("\nGravando a lista em um arquivo...\n");
    DesalistePArquivo(&l, "arquivo.txt");
    printf("Lista gravada no arquivo com sucesso.\n");
    
    CriarLista(&l);
    
    printf("\nLendo a lista do arquivo e enfileirando novamente...\n");
    ArquivoPLista(&l, "arquivo.txt");
    printf("Lista carregada do arquivo com sucesso.\n");

    printf("\nImprimindo a lista:\n");
    ImprimirLista(&l);

    printf("\n");
    
    
    return 0;
}
