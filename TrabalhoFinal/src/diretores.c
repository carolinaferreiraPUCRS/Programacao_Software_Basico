#include "diretores.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Vetor de diretores
static diretor_t diretores[MAX_DIRETORES];
// Número de diretores carregados
static int num_diretores = 0;

// Função auxiliar para comparar dois diretores pelo nome
int diretores_menor(diretor_t *a1, diretor_t *a2)
{
    if (strcmp(a1->nome, a2->nome) < 0)
    {
        return -1;
    }
    if (strcmp(a1->nome, a2->nome) > 0)
    {
        return 1;
    }
    return 0;
}

// Carrega os diretores de um arquivo
int diretores_carrega(char *nome_arq)
{
    FILE *f = fopen(nome_arq, "r");
    if (f == NULL)
        return 0;
    char linha[TAM_NOME + 1];
    while (1)
    {
        if (num_diretores >= MAX_DIRETORES)
            break;

        // id
        if (fgets(linha, TAM_NOME + 1, f) == NULL)
            break;
        diretores[num_diretores].id = atoi(linha);

        // nome
        if (fgets(diretores[num_diretores].nome, TAM_NOME + 1, f) == NULL)
            break;
        int t = strlen(diretores[num_diretores].nome);
        if (diretores[num_diretores].nome[t - 1] == '\n')
        {
            diretores[num_diretores].nome[t - 1] = '\0';
        }

        // cidade_nascimento
        if (fgets(diretores[num_diretores].cidade_nascimento, TAM_CIDADE + 1, f) == NULL)
            break;
        t = strlen(diretores[num_diretores].cidade_nascimento);
        if (diretores[num_diretores].cidade_nascimento[t - 1] == '\n')
        {
            diretores[num_diretores].cidade_nascimento[t - 1] = '\0';
        }

        // data_nascimento
        if (fgets(linha, TAM_NOME + 1, f) == NULL)
            break;
        diretores[num_diretores].data_nascimento.dia = atoi(linha);
        if (fgets(linha, TAM_NOME + 1, f) == NULL)
            break;
        diretores[num_diretores].data_nascimento.mes = atoi(linha);
        if (fgets(linha, TAM_NOME + 1, f) == NULL)
            break;
        diretores[num_diretores].data_nascimento.ano = atoi(linha);

        // cidade_falecimento
        if (fgets(diretores[num_diretores].cidade_falecimento, TAM_CIDADE + 1, f) == NULL)
            break;
        t = strlen(diretores[num_diretores].cidade_falecimento);
        if (diretores[num_diretores].cidade_falecimento[t - 1] == '\n')
        {
            diretores[num_diretores].cidade_falecimento[t - 1] = '\0';
        }

        // data_falecimento
        if (fgets(linha, TAM_NOME + 1, f) == NULL)
            break;
        diretores[num_diretores].data_falecimento.dia = atoi(linha);
        if (fgets(linha, TAM_NOME + 1, f) == NULL)
            break;
        diretores[num_diretores].data_falecimento.mes = atoi(linha);
        if (fgets(linha, TAM_NOME + 1, f) == NULL)
            break;
        diretores[num_diretores].data_falecimento.ano = atoi(linha);

        // // registro
        // if (fgets(linha, TAM_NOME+1, f) == NULL) break;
        // diretores[num_diretores].registro = atoi(linha);

        // // estilo
        // if (fgets(diretores[num_diretores].estilo, TAM_ESTILO+1, f) == NULL) break;
        // t = strlen(diretores[num_diretores].estilo);
        // if (diretores[num_diretores].estilo[t-1] == '\n') {
        //     diretores[num_diretores].estilo[t-1] = '\0';
        // }

        ++num_diretores;
    }
    fclose(f);
    return 1;
}

// Mostra os detalhes de um diretor
// Exibe o ID, nome, cidade de nascimento, data de nascimento e, se aplicável, cidade e data de falecimento
void diretores_mostra_diretor(diretor_t *diretor)
{
    printf("[%d] %s (* ", diretor->id, diretor->nome);
    printf("%s, %02d/%02d/%4d", diretor->cidade_nascimento, diretor->data_nascimento.dia, diretor->data_nascimento.mes, diretor->data_nascimento.ano);
    if (diretor->data_falecimento.dia != -1)
    {
        printf(";+ %s, %02d/%02d/%4d", diretor->cidade_falecimento, diretor->data_falecimento.dia, diretor->data_falecimento.mes, diretor->data_falecimento.ano);
    }
    printf(")\n");
}

// Mostra todos os diretores carregados
void diretores_mostra()
{
    for (int i = 0; i < num_diretores; ++i)
    {
        diretores_mostra_diretor(&diretores[i]);
    }
}

// Retorna o número de diretores carregados
int diretores_num_diretores()
{
    return num_diretores;
}

// Obtém um diretor pelo ID
diretor_t *diretores_obtem_diretor_id(int id)
{
    for (int i = 0; i < num_diretores; i++)
    {
        if (diretores[i].id == id)
            return &diretores[i];
    }
    return NULL;
}

// Obtém um diretor pelo índice
diretor_t *diretores_obtem_diretor_indice(int indice)
{
    if (indice < 0 || indice >= num_diretores)
        return NULL;
    return &diretores[indice];
}

// Ordena os diretores pelo nome usando o algoritmo de seleção
void diretores_ordena()
{
    for (int i = 0; i < num_diretores; i++)
    {
        int menor = i;
        for (int j = i + 1; j < num_diretores; j++)
        {
            if (diretores_menor(&diretores[j], &diretores[menor]) < 0)
            {
                menor = j;
            }
        }
        if (menor != i)
        {
            diretor_t aux = diretores[menor];
            diretores[menor] = diretores[i];
            diretores[i] = aux;
        }
    }
}

// Salva os diretores em um arquivo
int diretores_salva(char *nome_arq)
{
    FILE *f = fopen(nome_arq, "w");
    if (f == NULL)
    {
        return 0;
    }
    for (int i = 0; i < num_diretores; i++)
    {
        fprintf(f, "%d\n", diretores[i].id);
        fprintf(f, "%s\n", diretores[i].nome);
        fprintf(f, "%s\n", diretores[i].cidade_nascimento);
        fprintf(f, "%d\n", diretores[i].data_nascimento.dia);
        fprintf(f, "%d\n", diretores[i].data_nascimento.mes);
        fprintf(f, "%d\n", diretores[i].data_nascimento.ano);
        fprintf(f, "-\n");
        fprintf(f, "%d\n", diretores[i].data_falecimento.dia);
        fprintf(f, "%d\n", diretores[i].data_falecimento.mes);
        fprintf(f, "%d\n", diretores[i].data_falecimento.ano);
    }
    fclose(f);
    return 1;
}
