/* ===============================================================================
 * Arquivo: Aula-04-pilha-dinamica.c
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
 * run: ./Aula-04-pilha-dinamica.exe
 */

#include <stdio.h>
#include <string.h>

// definição de aluno
struct aluno {
    int matricula;
    char nome[30];
    float n1, n2, n3;
};

// Definição do tipo Pilha
struct elemento {
    struct aluno dados;
    struct elemento *prox;
};

// Definição dos tipos
typedef struct elemento Elem;
typedef struct elemento *Pilha; // É um ponteiro para elemento

// Remove todos os elementos da pilha:
void libera_Pilha(Pilha *pi) {
    if (pi != NULL) {
        Elem *no;

        while ((*pi) != NULL) {
            no = *pi;
            *pi = (*pi)->prox;
            free(no);
        }
    }
}

// int insere_Pilha(Pilha *pi, struct aluno al) { // Nesse caso, pi é um ponteiro para um ponteiro para elemento (poderia ser um ponteiro duplo)
int insere_Pilha(Elem **pi, struct aluno al) {
    if (pi == NULL)
        return 0;
    Elem *no;
    no = (Elem *) malloc(sizeof(Elem));

    if (no == NULL)
        return 0;

    no->dados = al;
    no->prox = (*pi);
    *pi = no;

    return 1;
}

//int remove_Pilha(Pilha *pi, struct aluno *al)
int remove_Pilha(Elem **pi, struct aluno *al) {
    if (pi == NULL) // Essa primeira condicional aponta como um erro, dado inválido
        return -1;

    if ((*pi) == NULL) // Essa condicional aponta para pilha vazia, a pilha é valida, só não tem elemento
        return -1;

    // Copia os dados e remove o elemento (a struc elemento)
    Elem *aux = *pi;    // Cria um ponteiro auxiliar para referência
    *al = (*pi)->dados; // Copia os dados para o ponteiro passado, atualiza diretamente na struct    
    *pi = (*pi)->prox;  // Aponta para o próximo elemento
    free(aux);          // É necessário usar a função free, pois com malloc, caso somente apontarmos para um novo elemento somente, por ser dinâmico, ficaria um lugar na memória sendo usado.

    return 1;
}