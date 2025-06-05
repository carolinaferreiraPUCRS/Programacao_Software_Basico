#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "atores.h"

// Vetor de atores
static ator_t atores[MAX_ATORES];
// Número de atores carregados
static int num_atores = 0;

// Função auxiliar para comparar dois atores pelo nome
int atores_menor(ator_t *a1, ator_t *a2)
{
  if (strcmp(a1->nome, a2->nome) < 0)
    return -1;
  if (strcmp(a1->nome, a2->nome) > 0)
    return 1;
  return 0;
}

// Função para carregar atores de um arquivo
int atores_carrega(char *nome_arq)
{
  FILE *f = fopen(nome_arq, "r");
  if (f == NULL)
    return 0;
  char linha[TAM_NOME + 1];
  while (1)
  {
    if (num_atores >= MAX_ATORES)
      break;

    if (fgets(linha, TAM_NOME + 1, f) == NULL)
      break;
    atores[num_atores].id = atoi(linha);

    if (fgets(atores[num_atores].nome, TAM_NOME + 1, f) == NULL)
      break;
    int t = strlen(atores[num_atores].nome);
    if (atores[num_atores].nome[t - 1] == '\n')
      atores[num_atores].nome[t - 1] = '\0';

    if (fgets(linha, TAM_NOME + 1, f) == NULL)
      break;
    atores[num_atores].data_nascimento.dia = atoi(linha);
    if (fgets(linha, TAM_NOME + 1, f) == NULL)
      break;
    atores[num_atores].data_nascimento.mes = atoi(linha);
    if (fgets(linha, TAM_NOME + 1, f) == NULL)
      break;
    atores[num_atores].data_nascimento.ano = atoi(linha);

    if (fgets(linha, TAM_NOME + 1, f) == NULL)
      break;
    atores[num_atores].data_falecimento.dia = atoi(linha);
    if (fgets(linha, TAM_NOME + 1, f) == NULL)
      break;
    atores[num_atores].data_falecimento.mes = atoi(linha);
    if (fgets(linha, TAM_NOME + 1, f) == NULL)
      break;
    atores[num_atores].data_falecimento.ano = atoi(linha);

    ++num_atores;
  }
  fclose(f);
  return 1;
}

// Retorna o número de atores carregados
int atores_num_atores()
{
  return num_atores;
}

// Função para obter atores por ID
ator_t *atores_obtem_ator_id(int id)
{
  for (int i = 0; i < num_atores; ++i)
    if (atores[i].id == id)
      return &atores[i];
  return NULL;
}

// Função para obter atores por índice
ator_t *atores_obtem_ator_indice(int indice)
{
  if (indice < 0 || indice >= num_atores)
    return NULL;
  return &atores[indice];
}

// Função para mostrar um ator
// Exibe o ID, nome e datas de nascimento e falecimento do ator
void atores_mostra_ator(ator_t *ator)
{
  printf("[%d] %s (* ", ator->id, ator->nome);
  printf("%02d/%02d/%4d", ator->data_nascimento.dia, ator->data_nascimento.mes, ator->data_nascimento.ano);
  if (ator->data_falecimento.dia != -1)
    printf(";+ %02d/%02d/%4d", ator->data_falecimento.dia, ator->data_falecimento.mes, ator->data_falecimento.ano);
  printf(")\n");
}

// Função para mostrar todos os atores
// Itera sobre o vetor de atores e chama a função de mostrar ator para cada um
void atores_mostra()
{
  for (int i = 0; i < num_atores; ++i)
    atores_mostra_ator(&atores[i]);
}

// Função para ordenar os atores pelo nome
void atores_ordena()
{
  for (int i = 0; i < num_atores - 1; ++i)
  {
    int menor = i;
    for (int j = i + 1; j < num_atores; ++j)
      if (atores_menor(&atores[j], &atores[menor]) < 0)
        menor = j;
    if (menor != i)
    {
      ator_t aux = atores[menor];
      atores[menor] = atores[i];
      atores[i] = aux;
    }
  }
}

// Função para salvar os atores em um arquivo
int atores_salva(char *nome_arq)
{
  FILE *f = fopen(nome_arq, "w");
  if (f == NULL)
    return 0;
  for (int i = 0; i < num_atores; ++i)
  {
    fprintf(f, "%d\n", atores[i].id);
    fprintf(f, "%s\n", atores[i].nome);
    fprintf(f, "%d\n%d\n%d\n", atores[i].data_nascimento.dia, atores[i].data_nascimento.mes, atores[i].data_nascimento.ano);
    fprintf(f, "%d\n%d\n%d\n", atores[i].data_falecimento.dia, atores[i].data_falecimento.mes, atores[i].data_falecimento.ano);
  }
  fclose(f);
  return 1;
}
