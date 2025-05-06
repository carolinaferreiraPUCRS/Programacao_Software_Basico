#include <stdio.h>
#include "bibfunc.h"

int main() {
   int v;
   printf("Digite um valor: ");
   scanf("%d", &v);
   printf("Fatorial: %lf\n", fatorial(v));
   printf("Somatorio: %lf\n", somatorio(v));
   return 0;
}

