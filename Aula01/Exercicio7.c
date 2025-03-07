#include <stdio.h>

int main() {
  int R, n100, n50, n10, n5, n1;
  printf("Digite o valor a ser sacado: ");
  scanf("%d", &R);
  n100 = R / 100;
  R = R % 100;
  n50 = R / 50;
  R = R % 50;
  n10 = R / 10;
  R = R % 10;
  n5 = R / 5;
  R = R % 5;
  n1 = R;
  printf("Notas de 100: %d\n", n100);
  printf("Notas de 50: %d\n", n50);
  printf("Notas de 10: %d\n", n10);
  printf("Notas de 5: %d\n", n5);
  printf("Notas de 1: %d\n", n1);
  return 0;
}