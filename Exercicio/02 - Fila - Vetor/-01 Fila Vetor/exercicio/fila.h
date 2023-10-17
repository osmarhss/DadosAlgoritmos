/*
* Arquivo: fila.h
* Biblicoteca de operações para fila implementada
* com vetor.
*/
#define VERDADEIRO 1
#define FALSO 0

struct Pessoa {
    char cpf[50];
    char nome[50];
    char endereco[50];
    char telefone[50];
    char celular[50];
    char data_de_nascimento[50];
    char data_de_admisao[50];
    char departamento[50];
    char cargo[50];
    char salario[50];
};
typedef struct Pessoa pessoa;

struct tipo_fila {
pessoa vet[TAM];
int inicio, fim;
};
typedef struct tipo_fila fila;
//Cria fila.
void CriarFila(fila *f) {
f->inicio = 0;
f->fim = 0;
}
//Verifica se a fila está vazia.
int FilaVazia(fila *f) {
return(f->inicio == f->fim);
}
//Verifica se a fila está cheia.
int FilaCheia(fila *f) {
return(f->fim == TAM);
}
//Insere um pessoa na fila.
void Enfileirar(fila *f, pessoa e) {
f->vet[f->fim++] = e;
}
//Retira um pessoa na fila.
pessoa Desenfileirar(fila *f) {
return(f->vet[f->inicio++]);
}



void enfileirarArquivo(fila *f, char nome_arquivo[50]) {
    int quantidade;
    FILE *arq;

    if ((arq = fopen (nome_arquivo, "wb")) == NULL) {
        printf ("\n Erro ao abrir o arquivo arquivoC.dat.");
        system ("pause");
        exit (1);
    }

    quantidade = fwrite (&f, sizeof (pessoa), TAM, arq);
    printf ("Quantidade de itens gravados: %d.\n",
    quantidade);
    fclose (arq);
}

void desenfileirarArquivo(fila *f, char nome_arquivo[50]) {
    int quantidade;
    FILE *arq;
    if ((arq = fopen (nome_arquivo, "rb")) == NULL) {
        printf ("\n Erro ao abrir o arquivo arquivoC.dat.");
        system ("pause");
        exit (1);
    }

    quantidade = fread (&f, sizeof (pessoa), TAM, arq);

    printf ("Quantidade de itens lidos: %d.\n", quantidade);
    fclose (arq);
}

int formato_cpf_valido(const char *cpf) {
    
    if (strlen(cpf) != 14) {
        return FALSO;
    }


    for (int i = 0; cpf[i] != '\0'; i++) {
        if (i == 3 || i == 7) {
            if (cpf[i] != '.') {
                return FALSO;
            }
        } else if (i == 11) {
            if (cpf[i] != '-') {
                return FALSO;
            }
        } else if (!isdigit(cpf[i])) {
            return FALSO;
        }
    }

    return VERDADEIRO;
}

int is_valid_date(const char *date) {
    int day, month, year;
    if (sscanf(date, "%d/%d/%d", &day, &month, &year) == 3) {
        // Verificar se o dia, mês e ano estão dentro dos limites aceitáveis
        if (year >= 1000 && year <= 9999 &&
            month >= 1 && month <= 12 &&
            day >= 1 && day <= 31) {
            // Verificar se os meses com 30 dias não têm mais de 30 dias
            if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
                return FALSO;
            }
            // Verificar se fevereiro tem no máximo 29 dias em anos bissextos ou 28 em outros anos
            else if (month == 2) {
                if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
                    return day <= 29;
                } else {
                    return day <= 28;
                }
            }
            return VERDADEIRO;
        }
    }
    return FALSO;
}

void pesquisaCPF(fila *f) {
    char cpf[50];
    printf("\n\n\n\n\n\n\nVamos pesquisar um CPF, informe o cpf de alguma pessoa:\n");
    scanf("%s", cpf);
    for(int t = 0; t<TAM; t++) {
        if(strcmp(f->vet[t].cpf, cpf) == 0){
            printf("\n\nA pessoa %d tem esse CPF!!", t+1);
        }else{
            printf("\n\nNiguem tem esse CPF!!");
        }
    }
}