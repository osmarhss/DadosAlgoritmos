/* Arquivo: pilha.c
* Programa que lê números inteiros a partir do teclado e os armazena em uma pilha.
*/

#include <stdio.h>
#include <stdlib.h>

typedef int elemento;

#include "pilha.h"

int main() {
 int num, opcao;
 pilha p;

 CriarPilha(&p);

 do {
 printf("\nInforme um numero inteiro: ");
 scanf("%d", &num);

 Empilhar(&p, num);

 printf("\nDeseja empilhar outro numero? (nao = 0 / sim = 1)\n");
 scanf("%d", &opcao);
 } while(opcao == 1);

 printf("\nNumeros informados: ");
 while(PilhaVazia(&p) == FALSO) {
 num = Desempilhar(&p);
 printf("\n%d", num);
 }
 printf("\n");
 system("pause");
 return 0;
}