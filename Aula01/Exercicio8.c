#include <stdio.h>

int main() {
    int n;
    double S = 1.0; // Começa com 1, pois o primeiro termo da soma já é dado

    // Leitura do valor de n
    scanf("%d", &n);

    // Cálculo da soma a partir de 2! (pois 1 já foi somado)
    for (int i = 2; i <= n; i++) {
        long long fat = 1; // Inicializa o fatorial

        // Calcula o fatorial de i
        for (int j = 2; j <= i; j++) {
            fat *= j;
        }

        // Soma o termo 1/fat ao resultado
        S += 1.0 / fat;
    }

    // Impressão do resultado com 10 casas decimais
    printf("%.10lf\n", S);

    return 0;
}