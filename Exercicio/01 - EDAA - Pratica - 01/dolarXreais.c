//3) Receba a cotação do dólar em reais e um valor que o usuário possui em dólares.
//Imprima este valor em reais.

#include <stdio.h>
#include <math.h>

int main (){

    float dolar,possui;

    printf ("Informe a cotação do dolar $: ");
    scanf ("%f", &dolar);

    printf ("Qual valor que você possui em dolar $?:");
    scanf("%f", &possui);

    printf("O valor que você possui em reais é R$: %.2f \n\n\n" , (dolar * possui));
    return 0;
    
}