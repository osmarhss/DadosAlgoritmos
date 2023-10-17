/*
* Programa que lê números inteiros a partir
* do teclado e os armazena em uma pilha.
*/
#include <stdio.h>
#include <stdlib.h>
#define TAM 3
#define limite_voltas 1
#define limite_vetor 2
typedef int elemento;
#include "pilhacircular.h"

int main() {

int num;
pilha p;

CriarPilha(&p);

while(PilhaCheia(&p) == FALSO) {
    printf("\nInforme um numero inteiro: ");
    scanf("%d", &num);
    Empilhar(&p, num);
}

printf("\nNumeros informados: ");
int tamanhoVetor = TAM;
while(PilhaVazia(&p, tamanhoVetor) == FALSO) {
    tamanhoVetor--;
    num = Desempilhar(&p, tamanhoVetor);
    printf("\n%d", num);
}

printf("\n");
system("pause");
return 0;
}
