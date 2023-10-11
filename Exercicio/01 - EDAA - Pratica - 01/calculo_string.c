#include <stdio.h> //printf().
#include <string.h> //strlen().
#include <locale.h> //setlocale() - caracteres especiais.

int main() {
int i, comprimento;
char minhaString[] = "Olá, Mundo!";
/* setlocale(LC_CTYPE, ""): caracteres especiais
de acordo com a configuração das variáveis
de ambiente.
setlocale(LC_CTYPE, "UTF-8"); caracteres especiais
de acordo com a tabela UTF-8.
*/

setlocale(LC_CTYPE, "");
// Calcula o comprimento da string usando a função strlen:
    comprimento = strlen(minhaString);
// Exibe o comprimento da string na tela:
    printf("\a A string \"%s\" possui %d caracteres.\n", minhaString,
            comprimento);
// Imprime os caractees da string na tela:
    for(i = 0; i < comprimento; i++)
        printf("\n %2d - %c", i, minhaString[i]);
        printf("\n");
return 0;
}