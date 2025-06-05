#ifndef DIRETORES_H
#define DIRETORES_H
#define TAM_NOME 60
#define TAM_CIDADE 30
#define MAX_DIRETORES 100
#define TAM_ESTILO 20

typedef struct {
    int dia, mes, ano;
} data_t;

typedef struct {
    int id;
    char nome[TAM_NOME+1];
    char cidade_nascimento[TAM_CIDADE+1];
    data_t data_nascimento;
    char cidade_falecimento[TAM_CIDADE+1];
    data_t data_falecimento;
    // int registro;
    // char estilo[TAM_ESTILO+1];
} diretor_t;

int diretores_menor(diretor_t *a1, diretor_t *a2);
int diretores_carrega(char *nome_arq);
int diretores_num_diretores();
diretor_t *diretores_obtem_diretor_id(int id);
diretor_t *diretores_obter_diretor_indice(int indice);
void diretores_mostra_diretor(diretor_t *diretor);
void diretores_mostra();
void diretores_ordena();
int diretores_salva(char *nome_arq);

#endif