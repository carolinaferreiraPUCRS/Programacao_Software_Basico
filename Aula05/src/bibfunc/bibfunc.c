#include "bibfunc.h"

double fatorial(int v) {
   int res = 1, i;
   for(i=1; i<=v; i++) res = res * i;
   return res;
}

double somatorio(int v) {
   double soma = 0, i;
   for(i=1; i<=v; i++) soma += i;
   return soma;
}
