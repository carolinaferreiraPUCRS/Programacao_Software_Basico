#include <stdio.h>
#define DIAS 30
typedef struct { int dia, m, ano; } data_t;
int main() {
  int num_dias = DIAS;
  data_t m[DIAS];
  FILE *f = fopen("abril.dat","wb");
  if (f == NULL) return 1;
  for (int d=0; d<num_dias; ++d) { m[d].dia = d+1; m[d].m = 4; m[d].ano = 2023; }
  fwrite((void *)&num_dias, sizeof(int), 1, f);
  fwrite((void *)&m[0], sizeof(data_t), num_dias, f);
  fclose(f);
  return 0;
}
