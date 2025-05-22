#include <stdio.h>
#include <stdlib.h>
#define TAM 2000000 // dois milhoes
int main() {
    double *vetor = malloc( TAM * sizeof(double) );
    printf("tamanho de memoria: %zu\n", TAM * sizeof(double));
    for (int i=0; i<TAM; i++)
        vetor[i] = i;
    free(vetor);
    return 0;
}
