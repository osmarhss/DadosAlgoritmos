#include <stdio.h>
#include "Floresta.h"

int main() {
    Floresta floresta;
    inicializarFloresta(&floresta, 3); // Inicializa a floresta com capacidade para 3 árvores

    inserirArvore(&floresta); // Insere uma nova árvore na floresta

    // Realiza operações como inserção, pesquisa, exclusão e caminhamentos na floresta

    return 0;
}
