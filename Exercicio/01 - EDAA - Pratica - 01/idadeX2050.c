//b. A idade que a pessoa terá em 2050.

#include <stdio.h>
#include <math.h>

int main() {

    int pes_ano, futuro;
    futuro = 2050;

    printf("Informe o ano que nasceu: ");
    scanf ("%d", &pes_ano);

    printf ("Sua idade em 2050 será: %d \n\n\n", (futuro - pes_ano));
    return 0 ;
    
}