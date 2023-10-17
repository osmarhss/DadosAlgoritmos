#include <stdio.h>


int soma(int n) {
    if (n == 1) {
        return 1; 
    } else {
        return n + soma(n - 1); 
    }
}

int main() {
    int n, resultado;

    printf("Digite um valor: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("insira um número  positivo.\n");
    } else {
        resultado = soma(n);
        printf("A soma do numero  %d e resultado: %d.\n", n, resultado);
    }

    return 0;
}