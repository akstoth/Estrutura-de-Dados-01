/**
 * @file Aula-04-exercicios-03.c
 * @author Aleksander Da Silva Toth
 * @brief Exercícios de manipulação de uma pilha dinâmica implementada com lista
 * encadeada.
 * @version 1.0.0
 * @date 2025-09-05
 *
 * @copyright Copyright (c) 2025
 *
 * =============================================================================
 * @details
 * Este arquivo contém a implementação de uma pilha LIFO (Last In, First Out)
 * para armazenar dados de alunos. Inclui operações fundamentais como push e
 * pop, além de funções auxiliares para liberar, imprimir, inserir em posições
 * arbitrárias e remover elementos por critério (idade).
 * =============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura que armazena os dados de um aluno
struct aluno {
  int idade;
  char nome[30];
};

// Estrutura do nó da lista encadeada, que representa um elemento da pilha
typedef struct no {
  struct aluno dado;
  struct no *prox;
} no;

/**
 * @brief Adiciona um aluno ao topo da pilha.
 *
 * @param topo Ponteiro duplo para o nó do topo da pilha.
 * @param al Struct de aluno com os dados a serem inseridos.
 * @return int Retorna 1 em caso de sucesso, 0 em caso de falha.
 */
int push(no **topo, struct aluno al) {
  if (topo == NULL) {
    return 0;
  }
  no *novo = (no *)malloc(sizeof(no));
  if (novo == NULL) {
    return 0;
  }
  novo->dado = al;
  novo->prox = *topo;
  *topo = novo;
  return 1;
}

/**
 * @brief Remove o aluno do topo da pilha.
 *
 * @param topo Ponteiro duplo para o nó do topo da pilha.
 * @param al Ponteiro para uma struct aluno onde os dados removidos serão
 * armazenados.
 * @return int Retorna 1 em caso de sucesso, 0 se a pilha estiver vazia.
 */
int pop(no **topo, struct aluno *al) {
  if (topo == NULL || *topo == NULL) {
    return 0;
  }
  no *temp = *topo;
  *al = temp->dado;
  *topo = temp->prox;
  free(temp);
  return 1;
}

/**
 * @brief Remove todos os elementos da pilha, liberando a memória.
 *
 * @param topo Ponteiro duplo para o nó do topo da pilha.
 */
void libera_pilha(no **topo) {
  if (topo == NULL) {
    return;
  }
  struct aluno x;
  while (pop(topo, &x)) {
    printf("removido %s %d\n", x.nome, x.idade);
  }
}

/**
 * @brief Imprime todos os elementos da pilha, do topo à base.
 *
 * @param topo Ponteiro duplo para o nó do topo da pilha.
 */
void imprime_pilha(no **topo) {
  if (topo == NULL) {
    return;
  }
  no *temp = *topo;
  while (temp != NULL) {
    printf("Nome: %s, Idade: %d\n", temp->dado.nome, temp->dado.idade);
    temp = temp->prox;
  }
}

/**
 * @brief Insere um aluno em uma posição específica da lista.
 * @details Esta função "quebra" a regra LIFO da pilha, mas serve como
 * um exercício de manipulação de listas encadeadas.
 *
 * @param topo Ponteiro duplo para o nó do topo.
 * @param al Struct de aluno com os dados a serem inseridos.
 * @param pos Posição de base 0 onde o novo aluno será inserido.
 * @return int Retorna 1 em caso de sucesso, 0 em caso de falha.
 */
int push_pos(no **topo, struct aluno al, int pos) {
  if (topo == NULL) {
    return 0;
  }
  no *novo = (no *)malloc(sizeof(no));
  if (novo == NULL) {
    return 0;
  }
  novo->dado = al;

  if (pos < 0) {
    free(novo);  // Libera o nó alocado se a posição for inválida
    return 0;
  }

  if (pos == 0) {
    novo->prox = *topo;
    *topo = novo;
  } else {
    no *temp = *topo;
    // Navega até o nó ANTERIOR à posição de inserção
    for (int i = 0; i < pos - 1; i++) {
      if (temp == NULL) {  // Posição fora do alcance
        free(novo);
        return 0;
      }
      temp = temp->prox;
    }
    // Verifica se a posição é válida após o loop
    if (temp == NULL) {
      free(novo);
      return 0;
    }
    novo->prox = temp->prox;
    temp->prox = novo;
  }
  return 1;
}

/**
 * @brief Remove o primeiro aluno encontrado com uma idade específica.
 *
 * @param topo Ponteiro duplo para o nó do topo da pilha.
 * @param rem_idade A idade do aluno a ser removido.
 * @return int Retorna 1 se removeu, 0 se não encontrou, -1 se a pilha estava
 * vazia.
 */
int pop_idade(no **topo, int rem_idade) {
  if (topo == NULL || *topo == NULL) {
    return -1;
  }

  no *temp = *topo;
  no *ant = NULL;

  // Percorre a lista até encontrar a idade ou chegar ao fim
  while (temp != NULL && temp->dado.idade != rem_idade) {
    ant = temp;
    temp = temp->prox;
  }

  // Se 'temp' é NULL, significa que não encontrou a idade na lista
  if (temp == NULL) {
    return 0;  // Não encontrou
  }

  // Se 'ant' é NULL, o nó a ser removido é o topo da pilha
  if (ant == NULL) {
    *topo = temp->prox;
  } else {
    // Se não, o nó a ser removido está no meio/fim da lista
    ant->prox = temp->prox;
  }

  free(temp);
  return 1;  // Sucesso
}

/**
 * @brief Função principal para testar as operações da pilha.
 */
int main() {
  no *topo = NULL;
  struct aluno a0;

  int idades[5] = {12, 15, 17, 19, 25};
  char nomes[5][15] = {"pedro", "caio", "ze", "ju", "bia"};

  // Adiciona 5 elementos
  for (int i = 0; i < 5; i++) {
    a0.idade = idades[i];
    strcpy(a0.nome, nomes[i]);
    push(&topo, a0);
  }

  a0.idade = 50;
  strcpy(a0.nome, "florisbela");
  push_pos(&topo, a0, 4);
  imprime_pilha(&topo);

  printf("\nDepois de remover a idade 17:\n");
  pop_idade(&topo, 17);
  imprime_pilha(&topo);

  // libera_pilha(&topo);
  return 0;
}