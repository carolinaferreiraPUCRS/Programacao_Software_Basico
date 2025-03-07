//Escrevaumprogramaquerecebeumhora ́rio(comovaloresinteiroscorrespondendoahoras,minutosesegundos) e que calcule quantos segundos ainda faltam ate ́ o dia terminar.
#include <stdio.h>

int main() {
  int h, m, s;
  printf("Digite o horário (hh mm ss): ");
  scanf("%d %d %d", &h, &m, &s);
  int totalSeconds = h * 3600 + m * 60 + s;
  int remainingSeconds = 86400 - totalSeconds;
  printf("Faltam %d segundos para o dia terminar.\n", remainingSeconds);
  return 0;
}