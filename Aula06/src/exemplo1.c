#include <stdio.h>
#define TAM 1000000 // um milhao
int main() {
    double vetor[TAM];
    printf("tamanho de memoria: %zu\n", sizeof(vetor)); // sizeof(double)*TAM
    for (int i=0; i<TAM; i++)
        vetor[i] = i;
    return 0;
}
