/**
 * Exercício003
 * Carolina Ferreira
 * Conta quantos elementos repetidos existem em um vetor
 * 20/03/2025
 */
#include <stdio.h>

#define MAX 100

int conta_repetidos(int *vet, int tam);

int main() {
  int vet[MAX], tam;
  scanf("%d", &tam);
  if ( tam > MAX )
     return 1;
  for (int i=0; i < tam; ++i)
      scanf("%d", &vet[i]);
  printf("%d\n", conta_repetidos(vet, tam));
  return 0;
}

int conta_repetidos(int *vet, int tam) {
  int cont = 0;
  int repetidos[MAX] = {0};

  for (int i = 0; i < tam; ++i) {
    if (repetidos[i] == 0) {
      for (int j = i + 1; j < tam; ++j) {
        if (vet[i] == vet[j]) {
          cont++;
          repetidos[i] = 1; 
          for (int k = j; k < tam; ++k) {
            if (vet[i] == vet[k]) {
              repetidos[k] = 1; 
            }
          }
          break;
        }
      }
    }
  }
  return cont;
}