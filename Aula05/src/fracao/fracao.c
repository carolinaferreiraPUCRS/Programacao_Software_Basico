#include <stdio.h>	
#include "fracao.h"

int mdc(int a, int b) {
   while (b != 0) {
          int r = a % b;
          a = b;
          b = r;
   }
   return a;
}

int mmc(int a, int b) {
    return a * (b / mdc(a, b));
}

fracao_t soma(fracao_t a, fracao_t b) {
   fracao_t res;
   if (a.denominador == b.denominador) {
      res.numerador = a.numerador + b.numerador;
      res.denominador = a.denominador;
   }
   else {
      res.denominador = mmc(a.denominador,b.denominador);
      res.numerador = (res.denominador/a.denominador)*a.numerador + (res.denominador/b.denominador)*b.numerador;
   }
   return simplifica(res);
}

fracao_t subtrai(fracao_t a, fracao_t b) {
   fracao_t res;
   if (a.denominador == b.denominador) {
      res.numerador = a.numerador - b.numerador;
      res.denominador = a.denominador;
   }
   else {
      res.denominador = mmc(a.denominador,b.denominador);
      res.numerador = (res.denominador/a.denominador)*a.numerador - (res.denominador/b.denominador)*b.numerador;
   }
   return simplifica(res);
}

fracao_t multiplica(fracao_t a, fracao_t b) {
   fracao_t res;
   res.numerador = a.numerador * b.numerador;
   res.denominador = a.denominador * b.denominador;	
   return simplifica(res);
}

fracao_t divide(fracao_t a, fracao_t b) {
   fracao_t res;
   res.numerador = a.numerador * b.denominador;
   res.denominador = a.denominador * b.numerador;	
   return simplifica(res);
}

fracao_t simplifica(fracao_t f) {
   fracao_t res;
   if (f.numerador < 0 && f.denominador < 0) {
      f.numerador = -f.numerador;
      f.denominador = -f.denominador;
   }
   int div  = mdc(f.numerador, f.denominador);
   res.numerador = f.numerador / div;
   res.denominador = f.denominador / div;
   return res;
}

size_t fracao2str(char *s, fracao_t f) {
   sprintf(s,"%d/%d",f.numerador, f.denominador);
   return strlen(s);
}
