/**
 * @file Questionario-03.c
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
 * Você está construindo uma pilha estática que guarda caracteres como na struct
 * abaixo. Crie uma função que recebe como entrada um ponteiro para a pilha e um
 * caractere e adicione o caractere à pilha.
 * =============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// elemento usado (não modificar)
struct pilha_t {
  char dados[50];  // array de dados
  int qtd;         // número de elemenotos na pilha
};
typedef struct pilha_t pilha;

// função a ser desenvolvida (não use printf):
void adiciona_caractere(pilha *p, char c) {
  // coloque sua resposta aqui

  // Primeiro, verificar se a pilha não é nula
  if (p == NULL) {
    return;
  }
  if (p->qtd < 50) {
    // Adiciona o caractere desejado na posição correspondente à quantidade
    p->dados[p->qtd] = c;
    p->qtd++;  // incrementa a quantidade após ter inserido um caractere
  } else {
    // Pilha cheia, não é possível adicionar mais caracteres
    printf("Pilha cheia, não é possível adicionar mais caracteres.\n");
    return;
  }
}

int main() {
  pilha p;
  p.qtd = 0;
  char c;
  printf("Digite o caractere que deseja adicionar na pilha: ");
  scanf(" %c", &c);
  adiciona_caractere(&p, c);
  printf("A pilha recebeu o caractere: %c\n", p.dados[0]);
  return 0;
}