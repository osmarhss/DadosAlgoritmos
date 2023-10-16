/*
* Programa que lê um número inteiro a partir do teclado
* e o converte para o seu correspondente em binário.
*/
#include <stdio.h>
#include <stdlib.h>
#define TAM 5
typedef int elemento;
#include "pilha.h"
int main() {
int num, resto;
pilha p;
CriarPilha(&p);
printf("\nInforme um numero inteiro: ");
scanf("%d", &num);
num+=32;
int i = 0;
while(num != 0) {
    resto = num % 2;
    Empilhar(&p, resto);
    num/=2;
    i++;
    if(i == 5)
    {
        if (num != 0)
        {
            printf("o numero tem mais que 5 bits.\n");
            printf("os bits mais significativos nao serao processados.");
        }
        
        break;
    }
}
printf("\n\nCorrespondente em binario: ");
int multiplicador = 16;
int numero_binario = 0;
while(PilhaVazia(&p) == FALSO) {
    resto = Desempilhar(&p);
    printf("%d", resto);
    numero_binario = numero_binario + (resto * multiplicador);
    multiplicador/=2;
}
printf("\n\nA representacao binaria que foi possivel processar \ne o quanto ela equivale em decimal:\n %d", numero_binario);
printf("\n");
system("pause");
return 0;
}