// Exercicio001.c
// Autor: Carolina Ferreiraß
// Soma e multiplicação de frações
// Versão: 27/03/2025

#include <stdio.h>

typedef struct {
    int numerador;
    int denominador;
} fracao_t;

int mmc(int a, int b);
fracao_t soma(fracao_t a, fracao_t b);
fracao_t multiplica(fracao_t a, fracao_t b);

int mmc(int a, int b) {
    int resto, n1, n2;
    n1 = a;
    n2 = b;
    do {
        resto = n1 % n2;
        n1 = n2;
        n2 = resto;
    } while (resto != 0);
    return (a * b) / n1;
}

fracao_t soma(fracao_t a, fracao_t b) {
    fracao_t res;
    int m = mmc(a.denominador, b.denominador);
    res.numerador = (a.numerador * (m / a.denominador)) + (b.numerador * (m / b.denominador));
    res.denominador = m;
    return res;
}

fracao_t multiplica(fracao_t a, fracao_t b) {
    fracao_t res;
    res.numerador = a.numerador * b.numerador;
    res.denominador = a.denominador * b.denominador;
    return res;
}

int main() {
    fracao_t f1, f2, res;

    scanf("%d%d", &f1.numerador, &f1.denominador);
    scanf("%d%d", &f2.numerador, &f2.denominador);
    
    res = soma(f1, f2);
    printf("%d %d\n", res.numerador, res.denominador);
    
    res = multiplica(f1, f2);
    printf("%d %d\n", res.numerador, res.denominador);
    
    return 0;
}
