#include <stdio.h>
#include "atores.h"
int main() {
  if ( !atores_carrega("atores.txt") ) return 0;
  printf("----------\n");
  atores_mostra();
  atores_ordena();
  printf("----------\n");
  atores_mostra();
  printf("----------\n");
  if ( !atores_salva("atores.txt.out") ) return 0;
  return 0;
}
