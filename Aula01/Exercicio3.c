#include <stdio.h>

int main() {
  int h, m, s;
  printf("Digite o horário (hh mm ss): ");
  scanf("%d %d %d", &h, &m, &s);
  int totalSeconds = h * 3600 + m * 60 + s;
  printf("Já se passaram %d segundos desde o início do dia.\n", totalSeconds);
  return 0;
}