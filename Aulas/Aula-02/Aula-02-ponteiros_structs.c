#include <stdio.h>
#include <string.h>
/*
struct pessoa {
    char nome[50];
    int idade;
    struct pessoa *prox;
};
typedef struct pessoa Pessoa;
*/

typedef struct Pessoa {
    char nome[50];
    int idade;
    struct Pessoa *prox;
} Pessoa;


int main() {
    Pessoa p1 = {"Ana", 30};
    //printf("Idade da Ana: %d\n", busca_idade(p1, "pedro", 3));
    printf("Idade da Ana: %d\n", p1.idade);
}
