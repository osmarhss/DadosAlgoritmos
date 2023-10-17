#include <stdio.h>
#include <ctype.h>

void main() {
    funcao1();
//    funcao2();
//    funcao3();
//    funcao4();
//    funcao5();
}

// Verificar se o caractere informado é uma letra ou não

int funcao1() {
    char c;
    
    printf("digite um caracter: \n");
    scanf("%c", &c);
    
    if (isalpha(c)) {
        printf("%c é uma letra.\n", c);
    } else {
        printf("%c não é uma letra.\n", c);
    }
    
    return 0;
}

// Verificar se o caractere informado é um dígito ou não

int funcao2() {
    char c;
    
    printf("Insira um dígito: \n");
    scanf("%c", &c);
    
    if (isdigit(c)) {
        printf("%c é um dígito.\n", c);
    } else {
        printf("%c não é um dígito.\n", c);
    }
    
    return 0;
}

// Verificar se o caractere informado é uma letra maiúscula ou não

int funcao3() {
    char c;
    
    printf("Insira uma letra: \n");
    scanf("%c", &c);
    
    if (isupper(c)) {
        printf("%c é uma letra maiúscula.\n", c);
    } else {
        printf("%c não é uma letra maiúscula.\n", c);
    }

        return 0;
}

// Verificar se o caractere informado é uma letra minúscula ou não

int funcao4() {
    char c;
    
    printf("Insira uma letra: \n");
    scanf("%c", &c);
    
    if (islower(c)) {
        printf("%c é uma letra minúscula.\n", c);
    } else {
        printf("%c não é uma letra minúscula.\n", c);
    }
    
    return 0;
}

// Verificar se o caractere informado é uma letra ou um dígito ou se não é nenhum dos 2

int funcao5() {
    char c;
    
    printf("Insira uma letra ou dígito: \n");
    scanf("%c", &c);
    
    if (isalnum(c)) {
        printf("%c é uma letra ou um dígito.\n", c);
    } else {
        printf("%c não é uma letra ou um dígito.\n", c);
    }
    
    return 0;
}