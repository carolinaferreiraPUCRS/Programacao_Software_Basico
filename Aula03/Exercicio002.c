// Exercicio002.c
// Autor: Carolina Ferreira
// Verifica se uma string é substring de outra
// Versão: 27/03/2025

#include <stdio.h>
#include <string.h>

#define TAM 100

int eh_substring(char s1[], char s2[]) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    if (len2 == 0 || len2 > len1) return -1;

    for (int i = 0; i <= len1 - len2; i++) {
        int j = 0;
        while (j < len2 && s1[i + j] == s2[j]) {
            j++;
        }
        if (j == len2) return i;
    }

    return -1;
}

int main() {
    int t;
    char str1[TAM+1], str2[TAM+2];

    fgets(str1, TAM+1, stdin);
    t = strlen(str1);
    if (str1[t-1] == '\n') str1[t-1] = '\0';

    fgets(str2, TAM+1, stdin);
    t = strlen(str2);
    if (str2[t-1] == '\n') str2[t-1] = '\0';

    printf("%d\n", eh_substring(str1, str2));
    return 0;
}
