#include <stdio.h>
int main() {
  char c;       int total = 0, letras = 0, digitos = 0;
  FILE *f = fopen("arquivo.txt","r");
  if (f == NULL) return 1;
  while ( (c=fgetc(f)) != EOF ) {
        ++total;
        if ( (c >='A' && c <='Z') || (c >= 'a' && c <= 'z') ) ++letras;
        if ( c >='0' && c <='9' ) ++digitos;
  }
  fclose(f);
  printf("total=%d\nletras=%d\ndigitos=%d\n", total, letras, digitos);
  return 0;
}
