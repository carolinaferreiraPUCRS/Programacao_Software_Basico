#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "ERRO: Nenhum nome de arquivo fornecido...\n");
        return 1;
    }

    FILE *f = fopen(argv[1], "r");
    if (f == NULL) {
        fprintf(stderr, "ERRO: Nao foi possivel abrir o arquivo \"%s\"...\n", argv[1]);
        return 2;
    }

    int quantidade;
    long long int numero, soma = 0;
    
    // Lê a quantidade de números (primeira linha)
    fscanf(f, "%d", &quantidade);
    printf("Quantidade de números: %d\n", quantidade);
    
    // Lê e soma cada número
    for(int i = 0; i < quantidade; i++) {
        fscanf(f, "%lld", &numero);
        printf("%lld ", numero);
        soma += numero;
    }
    
    printf("\nSoma dos números: %lld\n", soma);
    fclose(f);
    return 0;
}