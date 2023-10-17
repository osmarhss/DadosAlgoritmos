/*
* Programa que lê números inteiros a partir
* do teclado e os armazena em uma pilha.
*/
#include <stdio.h>
#include <stdlib.h>
#define TAM 10
typedef char elemento;
#include "pilha.h"
int main() {
char num[50];
pilha p;
char dados[TAM][50] = {
        "CPF",
        "Nome",
        "Endereço",
        "Telefone",
        "Celular",
        "Data de Nascimento",
        "Data de Admissão",
        "Departamento",
        "Cargo",
        "Salário"
    };
CriarPilha(&p);
int dado = 0;
while(PilhaCheia(&p) == FALSO) {
        printf("\nInforme o %s: ", dados[dado]);
        dado++;
        scanf("%s", num);
        Empilhar(&p, &num);
        printf("%d", dado);
    }
    SalvarPilhaEmArquivo("pilha.bin", &p);
    LerPilhaDeArquivo("pilha.bin", &p);
    // desempilhaArquivo(p);
// printf("\nNumeros informados: ");
// while(PilhaVazia(&p) == FALSO) {
// num = Desempilhar(&p);
// printf("\n%d", num);
// }
printf("\n");
system("pause");
return 0;
}