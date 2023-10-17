/*
* Programa que lê números inteiros a partir
* do teclado e os armazena em uma pilha.
*/
#include <stdio.h>
#include <stdlib.h>
#define TAM 1
#include "pilha.h"
int main() {
pilha p;
pessoa pe;
CriarPilha(&p);
while(PilhaCheia(&p) == FALSO) {
printf("\nInforme um numero inteiro: ");
scanf("%s", pe.cpf);
scanf("%s", pe.nome);
scanf("%s", pe.endereco);
scanf("%s", pe.telefone);
scanf("%s", pe.celular);
scanf("%s", pe.data_de_nascimento);
scanf("%s", pe.data_de_admisao);
scanf("%s", pe.departamento);
scanf("%s", pe.cargo);
scanf("%f", &pe.salario);
Empilhar(&p, pe);
}
empilharArquivo(&p, "arquivoC.dat");
printf("testando o test");
desempilharArquivo(&p, "arquivoC.dat");
printf("\ndados informados: ");
while(PilhaVazia(&p) == FALSO) {
pe = Desempilhar(&p);
printf("\n%s", pe.cpf);
printf("\n%s", pe.nome);
printf("\n%s", pe.endereco);
printf("\n%s", pe.telefone);
printf("\n%s", pe.celular);
printf("\n%s", pe.data_de_nascimento);
printf("\n%s", pe.data_de_admisao);
printf("\n%s", pe.departamento);
printf("\n%s", pe.cargo);
printf("\n%f", pe.salario);
}
printf("\n");
system("pause");
return 0;
}