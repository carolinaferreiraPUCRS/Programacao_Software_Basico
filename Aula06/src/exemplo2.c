#include <stdio.h>
#define TAM 2000000 // dois milhoes
int main() {
    double vetor[TAM];
    printf("tamanho de memoria: %zu\n", sizeof(vetor)); // sizeof(double)*TAM
    for (int i=0; i<TAM; i++)
        vetor[i] = i;
    return 0;
}
