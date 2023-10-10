#include <stdio.h> 
#include <math.h>

int main(){

    float x,y,z;

    printf("\nInforme um numero para X: ");
    scanf ("%f", &x);

    printf("\nInforme um numero para Y: ");
    scanf ("%f", &y);

    printf("\nInforme um numero para Z: ");
    scanf ("%f", &z);

    printf("Valor Médio é %.1f \n\n\n", (x+y+z)/3);
    return 0;
    
}