/**
 * @file Questionario-02.c
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
 * Neste questionário, faça Um programa usa structs que representam retângulos
 * que possuem três campos: largura, altura, área e perímetro.
 * Crie uma função que recebe como entrada um ponteiro para uma struct como
 * mencionada acima, e preencha os campos perímetro e área usando os campos
 * altura e largura.
 * =============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// struct representando o retângulo
typedef struct {
  float largura;
  float altura;
  float perimetro;
  float area;
} retangulo;

// função a ser preenchida
void preenche_retangulo(retangulo *r) {
  // Como não há return, podemos fazer simplesmente o preenchimento dos campos
  // usando ->

  if (r == NULL) {
    return;
  }
  // Calculo do perímetro
  r->perimetro = 2 * (r->altura + r->largura);

  // Calculo da área
  r->area = r->altura * r->largura;
}

int main() {
  // Cria um retângulo com largura 1 e altura 2
  retangulo r = {1, 2, 0, 0};

  // Chama a função e envia o endereço de r
  preenche_retangulo(&r);

  // Após a função finalizar o preenchimento, retorna ao main e imprime
  printf(
      "O perimetro e a area do retangulo de largura %.1f e altura %.1f: %.1f "
      "e %.1f",
      r.largura, r.altura, r.perimetro, r.area);
}