/**
 * Exercício002
 * Carolina Ferreira
 * Converte segundos em horas, minutos e segundos
 * 20/03/2025
 */
#include <stdio.h>

void hms(int seg, int *h, int *m, int *s);

int main() {
  int seg, h, m, s;
  scanf("%u", &seg);
  hms(seg, &h, &m, &s);
  printf("%u %u %u\n", h, m, s);
  return 0;
}

void hms(int seg, int *h, int *m, int *s) {
  *h = seg / 3600;
  seg %= 3600;
  *m = seg / 60;
  *s = seg % 60;
}
