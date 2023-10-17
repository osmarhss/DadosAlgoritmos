/*1. O TAD Deque pode ser implementado em um vetor (alocação sequencial). Modifique a
biblioteca lista.h (ou fila.h, ou lista.h) com implementação em vetor, para implementar as
operações comuns em um TAD Deque listadas acima. Crie também uma operação que
permita atualizar um elemento no Deque.*/

#include "deque.h01.c"

void criarDeque(Deque* deque) {
    deque->front = -1;
    deque->rear = -1;
}

int estaVazio(Deque* deque) {
    return (deque->front == -1);
}

int estaCheio(Deque* deque) {
    return ((deque->front == 0 && deque->rear == MAX_SIZE - 1) || (deque->front == deque->rear + 1));
}

void inserirInicio(Deque* deque, int elemento) {
    if (estaCheio(deque)) {
        printf("O deque está cheio. Não é possível inserir.\n");
    } else {
        if (deque->front == -1) {
            deque->front = 0;
            deque->rear = 0;
        } else if (deque->front == 0) {
            deque->front = MAX_SIZE - 1;
        } else {
            deque->front = deque->front - 1;
        }
        deque->elementos[deque->front] = elemento;
    }
}

void inserirFinal(Deque* deque, int elemento) {
    if (estaCheio(deque)) {
        printf("O deque está cheio. Não é possível inserir.\n");
    } else {
        if (deque->front == -1) {
            deque->front = 0;
            deque->rear = 0;
        } else if (deque->rear == MAX_SIZE - 1) {
            deque->rear = 0;
        } else {
            deque->rear = deque->rear + 1;
        }
        deque->elementos[deque->rear] = elemento;
    }
}

int removerInicio(Deque* deque) {
    int elementoRemovido;
    if (estaVazio(deque)) {
        printf("O deque está vazio. Não é possível remover.\n");
        return -1; // Valor de erro
    } else {
        elementoRemovido = deque->elementos[deque->front];
        if (deque->front == deque->rear) {
            deque->front = -1;
            deque->rear = -1;
        } else if (deque->front == MAX_SIZE - 1) {
            deque->front = 0;
        } else {
            deque->front = deque->front + 1;
        }
        return elementoRemovido;
    }
}

int removerFinal(Deque* deque) {
    int elementoRemovido;
    if (estaVazio(deque)) {
        printf("O deque está vazio. Não é possível remover.\n");
        return -1; // Valor de erro
    } else {
        elementoRemovido = deque->elementos[deque->rear];
        if (deque->front == deque->rear) {
            deque->front = -1;
            deque->rear = -1;
        } else if (deque->rear == 0) {
            deque->rear = MAX_SIZE - 1;
        } else {
            deque->rear = deque->rear - 1;
        }
        return elementoRemovido;
    }
}

void atualizarElemento(Deque* deque, int posicao, int novoElemento) {
    if (posicao < 0 || posicao > MAX_SIZE - 1) {
        printf("Posição fora dos limites.\n");
    } else if (posicao < deque->front || posicao > deque->rear) {
        printf("Posição vazia no deque.\n");
    } else {
        deque->elementos[posicao] = novoElemento;
    }
}
