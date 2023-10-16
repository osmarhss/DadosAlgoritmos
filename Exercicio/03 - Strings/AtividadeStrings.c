#include <stdio.h>
#include <ctype.h>

//Função isalpha - Verifica se um caractere é uma letra:

int main() {
    char c = 'A';

    if (isalpha(c)) {
        printf("%c é uma letra.\n", c);
    } else {
        printf("%c não é uma letra.\n", c);
    }

    return 0;
}

//Função isdigit - Verifica se um caractere é um dígito

int main() {
    char c = '9';

    if (isdigit(c)) {
        printf("%c é um dígito.\n", c);
    } else {
        printf("%c não é um dígito.\n", c);
    }

    return 0;
}
//Função isupper - Verifica se um caractere é uma letra maiúscula:

int main() {
    char c = 'B';

    if (isupper(c)) {
        printf("%c é uma letra maiúscula.\n", c);
    } else {
        printf("%c não é uma letra maiúscula.\n", c);
    }

    return 0;
}

//Função islower - Verifica se um caractere é uma letra minúscula:

int main() {
    char c = 'j';

    if (islower(c)) {
        printf("%c é uma letra minúscula.\n", c);
    } else {
        printf("%c não é uma letra minúscula.\n", c);
    }

    return 0;
}
//Função isalnum - Verifica se um caractere é uma letra ou um dígito:
int main() {
    char c = '7';

    if (isalnum(c)) {
        printf("%c é uma letra ou um dígito.\n", c);
    } else {
        printf("%c não é uma letra ou um dígito.\n", c);
    }

    return 0;
}
