/*
* Programa que lê números inteiros a partir
* do teclado e os armazena em uma fila.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM 3
typedef int elemento;
#include "fila.h"
int main() {
fila f;
pessoa pe;
CriarFila(&f);
int numero_pessoa = 1;

while(FilaCheia(&f) == FALSO) {
printf("\nInforme os dados da %dº pessoa: \n", numero_pessoa);
printf("informe o CPF(no formato do cpf mesmo):");
while (formato_cpf_valido(pe.cpf) == FALSO)
{
    printf("\nCPF invalido!!\n");
    scanf("%s", pe.cpf);
}
printf("\ninforme o nome:");
scanf("%s", pe.nome);
printf("\ninforme o endereco:");
scanf("%s", pe.endereco);
printf("\ninforme o telefone:");
scanf("%s", pe.telefone);
printf("\ninforme o celular:");
scanf("%s", pe.celular);
printf("\ninforme o data de nascimento:");
scanf("%s", pe.data_de_nascimento);
while (is_valid_date(pe.data_de_nascimento) == FALSO)
{
    printf("\nData invalida!!");
    scanf("%s", pe.data_de_nascimento);
}

printf("\ninforme o date de admissao:");
scanf("%s", pe.data_de_admisao);
while (is_valid_date(pe.data_de_admisao) == FALSO)
{
    printf("\nData invalida!!");
    scanf("%s", pe.data_de_nascimento);
}
printf("\ninforme o departamento:");
scanf("%s", pe.departamento);
printf("\ninforme o cargo:");
scanf("%s", pe.cargo);
printf("\ninforme o salario:");
scanf("%s\n", pe.salario);
Enfileirar(&f, pe);
numero_pessoa++;
}
enfileirarArquivo(&f, "arquivoC.dat");
desenfileirarArquivo(&f, "arquivoC.dat");
pesquisaCPF(&f);

printf("\n\n\ndados informados: ");
numero_pessoa--;
while(FilaVazia(&f) == FALSO) {
    
printf("\nPessoa %d:", numero_pessoa);
pe = Desenfileirar(&f);
printf("\n\nCPF:");
printf("\n%s", pe.cpf);
printf("\n\nnome:");
printf("\n%s", pe.nome);
printf("\n\nendereco:");
printf("\n%s", pe.endereco);
printf("\n\ntelefone:");
printf("\n%s", pe.telefone);
printf("\n\ncelular:");
printf("\n%s", pe.celular);
printf("\n\ndata de nascimento:");
printf("\n%s", pe.data_de_nascimento);
printf("\n\ndata de admissao:");
printf("\n%s", pe.data_de_admisao);
printf("\n\ndepartamento:");
printf("\n%s", pe.departamento);
printf("\n\ncargo:");
printf("\n%s", pe.cargo);
printf("\n\nsalario:");
printf("\n%s", pe.salario);
numero_pessoa--;
}
printf("\n");
system("pause");
return 0;
}