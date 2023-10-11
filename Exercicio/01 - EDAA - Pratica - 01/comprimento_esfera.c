// a. O comprimento de uma esfera: C = 2 * π * R.

#include <stdio.h>
#include <math.h>

int main () {

    float raio, circun,pi;

    pi = 3.14;

    printf("Informe o valor do raio: ");
    scanf("%f", &raio);

    circun = (2*pi*raio);

    printf("O valor do Comprimento da Esfera: %.1f\n", circun);
    return 0;

}