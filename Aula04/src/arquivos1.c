#include <stdio.h>

int main(int argc,char *argv[]) {
  if (argc != 2) {
     fprintf(stderr,"%s [ERRO]: NENHUM nome de arquivo fornecido...\n", argv[0]);
     return 1;
  }
  FILE *f = fopen(argv[1],"r");
  if (f == NULL) {
     fprintf(stderr,"%s [ERRO]: arquivo \"%s\" NAO existe...\n", argv[0], argv[1]);
     return 2;
  }
  printf("Arquivo \"%s\" aberto com sucesso...\n", argv[1]);
  fclose(f);
  return 0;
}
