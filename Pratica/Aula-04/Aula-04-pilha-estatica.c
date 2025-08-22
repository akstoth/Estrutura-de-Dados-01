/* ===============================================================================
 * Arquivo: Aula-04-pilha-estatica.c
 * Autor: Aleksander Da Silva Toth
 * Disciplina: Estruturas de Dados I
 *
 * Data de criação: 22/08/2025
 * Data da última alteração: 22/08/2025
 *
 *
 * Descrição:
 *
 *
 * ===============================================================================
 * compile: gcc
 * build: Ctrl + shift + B
 * run: ./Aula-04-pilha-estatica.exe
 */

#include <stdio.h>
#include <string.h>

#define MAX 100

struct aluno {
    int idade;
    char nome[30];
};

struct pilha {
    int qtd;                // Começa com 0 até a chegada do primeiro elemento
    struct aluno dados[MAX]; // Array de dados do tipo aluno (array de structs)
};

typedef struct pilha Pilha;

// Insere um elemento no topo da pilha (PUSH)
int insere_Pilha(Pilha *pi, struct aluno al) {
    if (pi == NULL || pi->qtd == MAX) // Verifica se não é um elemnto nulo e se não está cheia
        return 0;

    pi->dados[pi->qtd] = al;
    pi->qtd++;

    return 1;
}

// Consulta topo (TOP)
int consulta_topo_Pilha(Pilha *pi, struct aluno *al) {
    if (pi == NULL || pi->qtd == 0)
        return 0;

    *al = pi->dados[pi->qtd - 1];
    return 1;
}

// Remove um elemento do topo da pilha (POP)
int remove_Pilha(Pilha *pi, struct aluno *al) {
    if (pi == NULL || pi->qtd == 0) // Verifica se não é um elemento nulo e se há dados. if (pi == NULL || pi->qtd == 0) difere de if (pi->qtd == 0 || pi == NULL), pois se pi for nulo, dará errado (crash)
        return -1;
    
    // Copiar elemento e remover
    // Não terá problema apenas retirar o "topo" da posição anterior, mesmo que o dado esteja na posição antes de ser retirada, o próximo dado a ser acrescentado será sobrescrito
    pi->qtd--;
    *al = pi->dados[pi->qtd]; // Copia os dados
}
