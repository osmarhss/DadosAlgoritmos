#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definindo a estrutura do funcionário
struct Funcionario {
    char nome[50];
    char dataAdmissao[11]; // formato dd/mm/aaaa
    float salario;
    struct Funcionario* proximo; // para tratamento de colisões
};

// Definindo a estrutura da tabela hash
#define TAMANHO_TABELA 10
struct TabelaHash {
    struct Funcionario* elementos[TAMANHO_TABELA];
};

// Função para calcular o hash de uma string (nome do funcionário)
unsigned int calcularHash(const char* nome) {
    unsigned int hash = 0;
    for (int i = 0; nome[i] != '\0'; i++) {
        hash = 31 * hash + nome[i];
    }
    return hash % TAMANHO_TABELA;
}

// Função para inserir um funcionário na tabela hash
void inserirFuncionario(struct TabelaHash* tabela, const char* nome, const char* dataAdmissao, float salario) {
    // Criando um novo funcionário
    struct Funcionario* novoFuncionario = (struct Funcionario*)malloc(sizeof(struct Funcionario));
    strcpy(novoFuncionario->nome, nome);
    strcpy(novoFuncionario->dataAdmissao, dataAdmissao);
    novoFuncionario->salario = salario;
    novoFuncionario->proximo = NULL;

    // Calculando o índice da tabela hash usando o nome do funcionário
    unsigned int indice = calcularHash(nome);

    // Inserindo o funcionário na tabela hash (tratando colisões por encadeamento)
    if (tabela->elementos[indice] == NULL) {
        tabela->elementos[indice] = novoFuncionario;
    } else {
        // Se houver colisão, adicionamos no início da lista
        novoFuncionario->proximo = tabela->elementos[indice];
        tabela->elementos[indice] = novoFuncionario;
    }
}

// Função para buscar um funcionário na tabela hash
struct Funcionario* buscarFuncionario(struct TabelaHash* tabela, const char* nome) {
    // Calculando o índice da tabela hash usando o nome do funcionário
    unsigned int indice = calcularHash(nome);

    // Procurando o funcionário na lista (tratando colisões por encadeamento)
    struct Funcionario* atual = tabela->elementos[indice];
    while (atual != NULL) {
        if (strcmp(atual->nome, nome) == 0) {
            return atual; // Funcionário encontrado
        }
        atual = atual->proximo;
    }

    return NULL; // Funcionário não encontrado
}

int main() {
    // Inicializando a tabela hash
    struct TabelaHash tabela;
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        tabela.elementos[i] = NULL;
    }

    // Inserindo alguns funcionários de exemplo
    inserirFuncionario(&tabela, "Jataiza", "01/01/2022", 3000.0);
    inserirFuncionario(&tabela, "Matheus", "20/03/2022", 4000.0);
    inserirFuncionario(&tabela, "Gisele", "20/03/2022", 4000.0);
    inserirFuncionario(&tabela, "Larrisa", "20/03/2022", 4000.0);

    // Buscando um funcionário pelo nome
    char nomeBusca[50];
    printf("Digite o nome do funcionario para buscar: ");
    scanf("%s", nomeBusca);

    struct Funcionario* resultado = buscarFuncionario(&tabela, nomeBusca);
    if (resultado != NULL) {
        printf("Funcionario encontrado:\n");
        printf("Nome: %s\n", resultado->nome);
        printf("Data de Admissao: %s\n", resultado->dataAdmissao);
        printf("Salario: %.2f\n", resultado->salario);
    } else {
        printf("Funcionario nao encontrado.\n");
    }

    return 0;
}
