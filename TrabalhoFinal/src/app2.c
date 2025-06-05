#include <stdio.h>
#include "diretores.h"

int main() {
  if ( !diretores_carrega("diretores.txt") ) return 0;  
  printf("----------\n");  
  diretores_mostra();  
  diretores_ordena();  
  printf("----------\n");  
  diretores_mostra();  
  printf("----------\n");  
  if ( !diretores_salva("diretores.txt.out") ) return 0;  return 0;
}
