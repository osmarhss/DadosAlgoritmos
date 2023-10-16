#include <stdio.h>
#include <stdio.h>

int calcularPotencia(int base, int expoente) {
    if (expoente == 0) {
        return 1;
    } else if (expoente < 0) {
        base = 1 / base;
        expoente = -expoente;
    }

    return base * calcularPotencia(base, expoente - 1);
}

int main() {
    int base, expoente, resultado;

    printf("Digite a base: ");
    scanf("%d", &base);

    printf("Digite o expoente: ");
    scanf("%d", &expoente);

    resultado = calcularPotencia(base, expoente);

    printf("%d elevado a %d é igual a %d\n", base, expoente, resultado);

    return 0;
}
