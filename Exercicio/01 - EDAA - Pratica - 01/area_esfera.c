//b. A área de uma esfera: A = π * R2

#include <stdio.h>
#include <math.h>

int main () {

    float A,pi,raio;

    pi = 3.14;

    printf("Informe o valor do raio: ");
    scanf("%f", &raio);

    A = (pi*raio*raio);

    printf("O valor da Área da Esfera: %.1f\n",A );
    return 0;

}