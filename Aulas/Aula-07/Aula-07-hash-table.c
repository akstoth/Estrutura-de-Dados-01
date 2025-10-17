/**
 * @file Aula-07-hash-table
 * @author Aleksander Da Silva Toth
 * @brief Exercícios de filas - continuação
 * @version 1.0.0
 * @date 2025-10-17
 *
 * @copyright Copyright (c) 2025
 *
 * =============================================================================
 * @details
 * Hash tables
 * =============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10 // Tamanho máximo da tabela

// nota que o elemento agora nao tem ponteiro para o próximo
struct aluno_t {
    char nome[30];
    int idade;
};
typedef struct aluno_t aluno;

// Função hash
int hash(char *str, int tamanho) {
    // a = 97
    // n = 110
    // a = 97

    int soma = 0;
    for (int i = 0; str[i] != '\0'; i++)
        soma += str[i]; // Soma cada elemento, cada caractere
    return soma % tamanho;
}

void adiciona_elemento(aluno novo, aluno tabela[]) {
    int pos = hash(novo.nome, MAX);
    int max_atingido = 0;
    printf("\nNome: %s, idade: %d, posicao calculada: %d\n", novo.nome, novo.idade, pos);
    
    while(tabela[pos].nome[0] != '\0') {
        printf("A posicao %d esta ocupada por %s\n", pos, tabela[pos].nome);
        pos++;
        if (pos == MAX && !max_atingido) {
            pos = 0;
            max_atingido =  1;
        }
        else if(pos == MAX && max_atingido) {
            printf("Todas as posicoes estao preenchidas!");
            break;
        }
    }
    printf("Elemento adicionado na posicao: %d\n", pos);
    tabela[pos] = novo;
}

int main() {

    aluno tabela[MAX];
    memset(tabela, 0, sizeof(tabela)); // Todas as posições iguais a 0

    char nomes[10][20] = {"ana", "bia", "julia", "caio", "ze",
                          "ju", "otavio", "caca", "mario", "borre"};
    int idades[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // adiciona alunos à tabela
    aluno novo;
    for (int i = 0; i < MAX; i++) {
        strcpy(novo.nome, nomes[i]);
        novo.idade = idades[i];
        adiciona_elemento(novo, tabela);
        
    }
}