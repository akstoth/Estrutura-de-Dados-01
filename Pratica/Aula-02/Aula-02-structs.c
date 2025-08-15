#include <stdio.h>
#include <string.h>

struct pessoa {
 char nome[50];
 int idade;
};
typedef struct pessoa Pessoa;

int busca_idade(Pessoa a[], char *nome, int tamanho){
    int idade = -1;
    for (int i=0; i<tamanho; i++){
        if (strcmp(a[i].nome, nome) == 0){
            idade = a[i].idade;
        }
    }
    return idade;
}

// Structs com ponteiros
void mostrarPessoa(Pessoa *p) {
 printf( "Nome: %s, Idade: %d\n" , p->nome, p->idade);
 printf( "Nome: %s, Idade: %d\n" , (*p).nome, (*p).idade);
}


int main() {
    Pessoa p1[3] = {{"Ana", 30}, {"caio", 22}, {"pedro", 20}};
    printf("idade do pedro: %d\n", busca_idade(p1, "pedro", 3));

    Pessoa p2 = { "Joao", 22};
    mostrarPessoa(&p2); // Passando a struct por referência
    return 0;
}