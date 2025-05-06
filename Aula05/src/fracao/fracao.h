#include <string.h>

typedef struct {
   int numerador;
   int denominador;
} fracao_t;

int mdc(int a, int b);
int mmc(int a, int b);
fracao_t soma(fracao_t a, fracao_t b);
fracao_t subtrai(fracao_t a, fracao_t b);
fracao_t multiplica(fracao_t a, fracao_t b);
fracao_t divide(fracao_t a, fracao_t b);
fracao_t simplifica(fracao_t f);
size_t fracao2str(char *s, fracao_t f);
