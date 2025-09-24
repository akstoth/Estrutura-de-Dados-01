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
    struct elemento *ant
} elemento;

typedef struct
{
    elemento *inicio;
    elemento *final;
    int qtd;
} deque;

int insere_inicio(deque *d, aluno al)
{
    if (d == NULL)
        return 0;

    elemento *no = (elemento *)malloc(sizeof(elemento));

    if (no == NULL)
        return 0;

    no->dados = al;
    no->prox = NULL;
    no->ant = NULL;

    if (d->qtd == 0)
    {
        // Inicio e fim apontam para o no
        d->inicio = no;
        d->final = no;  
    }
    else
    {
        no->prox = d->inicio;
        d->inicio->ant = no;
        d->inicio = no;
    }

    d->qtd++;

    return 1;
}

void remove_final(deque *d) {
    if (d == NULL || d->qtd == 0)
        return;

    elemento *temp = d->final;
    printf("Removendo: %s\n", temp->dados.nome);

    if(d->qtd == 1){
        // destroi o único elemento e atualiza elemento
        free(temp);
        d->inicio = NULL;
        d->final = NULL;
    }
    else
    {
        d->final = d->final->ant;
        d->final->prox = NULL;
        free(temp);
    }
    d->qtd--;

}

void destroi_fila(deque *d)
{
    if (d == NULL || d->qtd == 0)
        return;

    elemento *temp = d->inicio; // cria-se um novo struct temporário do tipo elemento

    while (temp != NULL)
    {
        printf("Destruindo: %s\n", temp->dados.nome);
        // primeiro "pula"
        d->inicio = d->inicio->prox; // fi vai apontar para outro

        // destroi
        free(temp); // limpa temp, que recebeu anteriormente a fi->inicio

        // temp "pula"
        temp = d->inicio; // Atualiza com a nova fi-> inicio
    }
    return;
}

int main()
{
    char nomes[5][20] = {"ana", "bia", "caio", "ze", "ju"};
    aluno a;
    deque d;
    d.final = NULL;
    d.inicio = NULL;
    d.qtd = 0;

    for (int i=0; i<5; i++){
        strcpy(a.nome, nomes[i]);
        insere_inicio(&d, a);
    }
    while(d.inicio != NULL) {
        remove_final(&d);
    }
    
}