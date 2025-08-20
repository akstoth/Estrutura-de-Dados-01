/* ===============================================================================
 * Arquivo: Aula-02-structs.c
 * Autor: Aleksander Da Silva Toth
 * Disciplina: Algoritmos e Estruturas de Dados I
 * 
 * Data de criação: 15/08/2025
 * Data da última alteração: 20/08/2025	
 * - Adicionado comentários explicativos.
 * 
 * Descrição: 
 * Este programa demonstra o uso de structs em C, incluindo a definição de uma struct
 * para representar uma pessoa, a busca por idade de uma pessoa em um array de structs
 * ===============================================================================
 
 * compile: gcc 
 * build:   Ctrl + shift + B
 * run:     ./Aula-02-structs.c
 */

// Bibliotecas
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