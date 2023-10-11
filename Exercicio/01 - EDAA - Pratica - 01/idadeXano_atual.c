//2) Receba o ano de nascimento de uma pessoa, o ano atual e imprima:

//a. A idade da pessoa no ano atual.

#include <stdio.h> 
#include <math.h>

int main () {

    int pes_ano, id_atual;
    id_atual = 2023;

    printf ("Informe o ano que nasceu: ");
    scanf ("%d", &pes_ano);

    printf("Sua idade é: %d \n\n\n", (id_atual - pes_ano));
    return 0;
    
}
