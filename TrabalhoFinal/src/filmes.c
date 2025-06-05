#include "filmes.h"
#include "diretores.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static filme_t filmes[MAX_FILMES];
static int num_filmes = 0;

// Função auxiliar para comparar dois filmes pelo título
int filmes_menor(filme_t *f1, filme_t *f2)
{
    if (strcmp(f1->titulo, f2->titulo) < 0)
        return -1;
    if (strcmp(f1->titulo, f2->titulo) > 0)
        return 1;
    return 0;
}

// Carrega os filmes de um arquivo
int filmes_carrega(char *nome_arq)
{
    FILE *f = fopen(nome_arq, "r");
    if (f == NULL)
        return 0;
    char linha[TAM_NOME + 1];
    while (1)
    {
        if (num_filmes >= MAX_FILMES)
            break;

        if (fgets(linha, TAM_NOME + 1, f) == NULL)
            break;
        filmes[num_filmes].id = atoi(linha);

        if (fgets(filmes[num_filmes].titulo, TAM_NOME + 1, f) == NULL)
            break;
        int t = strlen(filmes[num_filmes].titulo);
        if (filmes[num_filmes].titulo[t - 1] == '\n')
        {
            filmes[num_filmes].titulo[t - 1] = '\0';
        }

        if (fgets(linha, TAM_NOME + 1, f) == NULL)
            break;
        filmes[num_filmes].ano_lancamento = atoi(linha);

        if (fgets(linha, TAM_NOME + 1, f) == NULL)
            break;
        int diretor_id = atoi(linha);
        filmes[num_filmes].diretor = diretores_obtem_diretor_id(diretor_id);

        ++num_filmes;
    }
    fclose(f);
    return 1;
}

// Obtém o número de filmes carregados
int filmes_num_filmes()
{
    return num_filmes;
}

// Obtém um filme pelo ID
filme_t *filmes_obtem_filme_id(int id)
{
    for (int i = 0; i < num_filmes; i++)
    {
        if (filmes[i].id == id)
            return &filmes[i];
    }
    return NULL;
}

// Obtém um filme pelo índice
filme_t *filmes_obtem_filme_indice(int indice)
{
    if (indice < 0 || indice >= num_filmes)
    {
        return NULL;
    }
    return &filmes[indice];
}

// Mostra os detalhes de um filme
// Exibe o ID, título, ano de lançamento e nome do diretor
void filmes_mostra_filme(filme_t *filme)
{
    printf("[%d] %s (%d) - %s\n", filme->id, filme->titulo, filme->ano_lancamento, filme->diretor->nome);
}

// Mostra todos os filmes carregados
void filmes_mostra()
{
    for (int i = 0; i < num_filmes; i++)
    {
        filmes_mostra_filme(&filmes[i]);
    }
}

// Ordena os filmes pelo título usando o algoritmo de seleção
void filmes_ordena()
{
    for (int i = 0; i < num_filmes; i++)
    {
        int menor = i;
        for (int j = i + 1; j < num_filmes; j++)
        {
            if (filmes_menor(&filmes[j], &filmes[menor]) < 0)
                menor = j;
        }
        if (menor != i)
        {
            filme_t aux = filmes[menor];
            filmes[menor] = filmes[i];
            filmes[i] = aux;
        }
    }
}

// Salva os filmes em um arquivo
int filmes_salva(char *nome_arq)
{
    FILE *f = fopen(nome_arq, "w");
    if (f == NULL)
        return 0;
    for (int i = 0; i < num_filmes; ++i)
    {
        fprintf(f, "%d\n", filmes[i].id);
        fprintf(f, "%s\n", filmes[i].titulo);
        fprintf(f, "%d\n", filmes[i].ano_lancamento);
        fprintf(f, "%d\n", filmes[i].diretor->id);
    }
    fclose(f);
    return 1;
}