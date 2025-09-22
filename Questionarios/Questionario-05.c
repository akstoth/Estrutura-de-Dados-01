/**
 * @file Questionario-04.c
 * @author Aleksander Da Silva Toth
 * @brief Exercícios de manipulação de uma pilha dinâmica implementada com lista
 * encadeada.
 * @version 1.0.0
 * @date 2025-09-15
 *
 * @copyright Copyright (c) 2025
 *
 * =============================================================================
 * @details
 * Você está criando uma fila estaticamente alocada, composta por uma estrutura
 * que contém um array de inteiros, um índice que indica o primeiro elemento da
 * fila (chamado ini), um índice que indica a próxima posição livre
 * (chamado fim) e um inteiro que indica a quantidade de elementos na fila
 * (chamado qnt). A figura abaixo mostra como deve ser o estado da fila após a
 * inserção dos inteiros 2, 5, 0 e 6 e da remoção de um elemento da fila.
 * Você precisa fazer uma função que adiciona um elemento na penúltima posição
 * da fila.
 * Crie a função “int adiciona_penultimo(fila_estatica *p, int x)” que recebe
 * um ponteiro para uma fila estática e um inteiro e adiciona este inteiro na
 * penúltima posição da fila. A função retorna 1 em caso de sucesso e 0 caso
 * contrário.
 * =============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5

// fila estática (não modificar)
typedef struct {
  int ini;         // primeiro elemento
  int fim;         // último el
  int qtd;         // número de elementos
  int array[MAX];  // array de inteiros
} fila_estatica;

// adiciona penúltimo
int adiciona_penultimo(fila_estatica *p, int x) {
  if (p == NULL || p->qtd == MAX || p->qtd == 0) {
    return 0;
  }
  // Move o último elemento para a última posição
  p->array[(p->fim)] = p->array[p->fim - 1];

  // Adiciona o novo elemento
  p->array[p->fim - 1] = x;
  p->fim++;
  p->qtd++;

  return 1;
}

int main() {
  fila_estatica pd = {0, 0, 0, {1, 2, 3, 4, 5}};
  printf("%d", adiciona_penultimo(&pd, 8));
  return 0;
}