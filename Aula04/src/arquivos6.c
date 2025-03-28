#include <stdio.h>

#define MAX_DIAS 31

typedef struct { int dia, m, ano; } data_t;

int main() {
  data_t m[MAX_DIAS];
  int num_dias;
  FILE *f = fopen("abril.dat","rb");
  if (f == NULL) return 1;
  fread((void *)&num_dias, sizeof(int), 1, f);
  fread((void *)&m[0], sizeof(data_t), num_dias, f);
  fclose(f);
  for (int d=0; d<num_dias; ++d)
      printf("%d %d %d\n", m[d].dia, m[d].m, m[d].ano);
  return 0;
}
