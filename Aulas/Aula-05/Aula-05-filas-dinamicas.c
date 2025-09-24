/**
 * @file Aula-05-filas-encadeadas.c
 * @author Aleksander Da Silva Toth
 * @brief Exercícios de filas - continuação
 * @version 1.0.0
 * @date 2025-09-05
 *
 * @copyright Copyright (c) 2025
 *
 * =============================================================================
 * @details
 * Este arquivo contém a implementação de uma fila encadeada
 * =============================================================================
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    int matricula;
    char nome[30];
    float n1, n2, n3;
} aluno;

typedef struct elemento
{
    aluno dados;
    struct elemento *prox;
} elemento;

typedef struct
{
    elemento *inicio;
    elemento *final;
    int qtd;
} fila;

int insere_Fila(fila *fi, aluno al)
{
    if (fi == NULL)
        return 0;

    elemento *no = (elemento *)malloc(sizeof(elemento));

    if (no == NULL)
        return 0;

    no->dados = al;
    no->prox = NULL;

    if (fi->qtd > 0)
    {
        fi->final->prox = no;
    }
    else
    {
        fi->inicio = no;
    }

    fi->final = no;
    fi->qtd++;

    return 1;
}

void destroi_fila(fila *fi)
{
    if (fi == NULL || fi->qtd == 0)
        return;

    elemento *temp = fi->inicio; // cria-se um novo struct temporário do tipo elemento

    while (temp != NULL)
    {
        printf("Destruindo: %s\n", temp->dados.nome);
        // primeiro "pula"
        fi->inicio = fi->inicio->prox; // fi vai apontar para outro

        // destroi
        free(temp); // limpa temp, que recebeu anteriormente a fi->inicio

        // temp "pula"
        temp = fi->inicio; // Atualiza com a nova fi-> inicio
    }
    return;
}

int main()
{
    char nomes[5][20] = {"ana", "bia", "caio", "ze", "ju"};
    aluno a;
    fila f;
    f.final = NULL;
    f.inicio = NULL;
    f.qtd = 0;

    for (int i=0; i<5; i++){
        strcpy(a.nome, nomes[i]);
        insere_Fila(&f, a);
    }
    destroi_fila(&f);
}