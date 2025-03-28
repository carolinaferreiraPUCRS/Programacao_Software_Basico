#include <stdio.h>
#define DIAS 30
int main() {
  FILE *f = fopen("abril.txt","w");
  if (f == NULL) return 1;
  fprintf(f,"%d\n", DIAS);
  for (int d=0; d<DIAS; ++d)
      fprintf(f,"%d %d %d\n", d+1, 4, 2023);
  fclose(f);
  return 0;
}
