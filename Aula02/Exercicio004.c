/**
 * Exercício004
 * Carolina Ferreira
 * Converte um valor em reais para a menor quantidade de moedas possíveis
 * 20/03/2025
 */
#include <stdio.h>

void quantidadeDeMoedas(int r, int *m100, int *m50, int *m25, int *m10, int *m5, int *m1);

void quantidadeDeMoedas(int r, int *m100, int *m50, int *m25, int *m10, int *m5, int *m1) {
  *m100 = r / 100;
  r %= 100;
  *m50 = r / 50;
  r %= 50;
  *m25 = r / 25;
  r %= 25;
  *m10 = r / 10;
  r %= 10;
  *m5 = r / 5;
  r %= 5;
  *m1 = r;
}

int main() {
  int r, m100, m50, m25, m10, m5, m1;
  scanf("%u", &r);
  quantidadeDeMoedas(r, &m100, &m50, &m25, &m10, &m5, &m1);
  printf("%u %u %u %u %u %u\n", m100, m50, m25, m10, m5, m1);
  return 0;
}