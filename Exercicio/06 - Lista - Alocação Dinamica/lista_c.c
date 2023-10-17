/* Arquivo: lista.c
* Programa que lê números inteiros a partir do teclado e os armazena em uma lista.
*/
#include <stdio.h>
#include <stdlib.h>
typedef int elemento;
#include "lista.h"
int main() {
int num, opcao, pos = 0;
pt_nodo *p;
lista l;
CriarLista(&l);
do {
printf("\nInforme um numero inteiro: ");
scanf("%d", &num);
Alistar(&l, &num);
printf("\nDeseja enfileirar outro numero? (nao = 0 / sim = 1)\n");
scanf("%d", &opcao);
} while(opcao == 1);
do {
printf("\nInforme um numero inteiro a ser pesquisado na lista: ");
scanf("%d", &num);
p = PesquisarLista (&l, &num);
if(p != NULL) {
num = Desalistar(p);
printf("\nNumero removido da lista: %d", num);
}
else
printf("\nNumero nao encontrado na lista: %d", num);
printf("\nDeseja pesquisar outro numero? (nao = 0 / sim = 1)\n");
scanf("%d", &opcao);
} while(opcao == 1);
printf("\nNumeros removidos: ");
while(ListaVazia(&l) == FALSO) {
num = Desalistar(&l);
printf("\n%d", num);
}
printf("\n");
system("pause");
return 0;
}