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
 * Um programa usa structs que possuem três campos: nome, idade, próx
 * (aponta para o próximo elemento).
 * Crie uma função que recebe como entrada um ponteiro para o primeiro elemento
 * de uma pilha. A função contar o número de elementos cujo campo idade é maior
 * do que 21. No exemplo abaixo retornaria o número 1.
 * Você conseguiria implementar essa função de forma recursiva?
 * Obs.: Uma chamada recursiva é chamar a própria função dentro dela mesma
 * assim, a função vai "percorrendo" a lista até chegar no final (NULL)
 * =============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// elemento usado (não modificar)
struct Pessoa_tipo {
  char nome[50];
  int idade;
  struct Pessoa_tipo *prox;
};
typedef struct Pessoa_tipo pessoa;

// função a ser desenvolvida:
int maiores(pessoa *p) {
  if (p == NULL) {
    return 0;
  }

  if (p->idade > 21) {
    return 1 +
           maiores(p->prox);  // Retorna 1 se for maior que 21
                              // e chama a função recursivamente para o próximo
  } else {
    return maiores(p->prox);
  }
  //
}

int main() {
  pessoa p[3] = {{"ana", 20, NULL}, {"ze", 22, NULL}, {"bia", 18, NULL}};
  p[0].prox = &p[1];  // Faz de maneira estática a ligação entre os elementos
  p[1].prox = &p[2];
  printf("%d", maiores(&p[0]));
}