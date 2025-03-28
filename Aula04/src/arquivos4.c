#include <stdio.h>

#define MAX_DIAS 31

typedef struct { int dia, mes, ano; } data_t;

int main() {
  data_t mes[MAX_DIAS];
  int num_dias;
  FILE *f = fopen("abril.txt","r");
  if (f == NULL) return 1;
  fscanf(f,"%d", &num_dias);
  for (int d=0; d<num_dias; ++d)
      fscanf(f,"%d %d %d", &mes[d].dia, &mes[d].mes, &mes[d].ano);
  fclose(f);
  for (int d=0; d<num_dias; ++d)
      printf("%d %d %d\n", mes[d].dia, mes[d].mes, mes[d].ano);
  return 0;
}
