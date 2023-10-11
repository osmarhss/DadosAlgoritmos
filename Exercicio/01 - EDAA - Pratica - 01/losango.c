//5) Calcule e apresente a área de um losango. As diagonais maior e menor do losango
//devem ser informadas pelo usuário. OBS: ÁREA = (DIAGONAL MAIOR * DIAGONAL
//MENOR) / 2.

#include <stdio.h>
#include <math.h>

int main () {

    float diagMai, diagMen;

    printf ("Informe a diagonal maior: ");
    scanf("%f",&diagMai);

    printf ("Informe a diagonal menor: ");
    scanf("%f",&diagMen);

    printf("O valor da Área do Losango é: %.1f \n\n\n", (diagMai * diagMen/2));
    return 0;
    
}