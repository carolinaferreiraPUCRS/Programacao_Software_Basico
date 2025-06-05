#define TAM_NOME 60
#define MAX_ATORES 100

typedef struct {
 int dia, mes, ano;
} data_t;

typedef struct {
  int id;
  char nome[TAM_NOME+1]; //por conta do \0
  data_t data_nascimento;
  data_t data_falecimento;
} ator_t;

int atores_menor(ator_t *a1, ator_t *a2);
int atores_carrega(char *nome_arq);
int atores_num_atores();

ator_t *atores_obtem_ator_id(int id);
ator_t *atores_obter_ator_indice(int indice);

void atores_mostra_ator(ator_t *ator);
void atores_mostra();
void atores_ordena();
int atores_salva(char *nome_arq);

