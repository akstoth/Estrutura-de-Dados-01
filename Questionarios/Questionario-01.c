#include <stdio.h>
#include <string.h>

// estrutura da struct
typedef struct {
  char nome[50];
  int idade;
} pessoa;

int encontra_elemento(pessoa lst[], int n, char *nome) {
  int idade = -1;
  for (int i = 0; i < n; i++) {
    if (strcmp(lst[i].nome, nome) ==
        0) {  // Precisamos usar a função strcmp. Caso tenha dois nomes iguais,
              // irá retornar o último, pois irá percorrer toda a lista. Pode
              // usar um break
      idade = lst[i].idade;
    }
  }
  return idade;
}

void main() {
  pessoa p[2] = {{"joao", 5}, {"jose", 10}};
  printf("%d", encontra_elemento(p, 2, "joao"));
}