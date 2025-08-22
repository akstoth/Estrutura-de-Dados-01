/* ===============================================================================
 * Arquivo: Aula-04-exercicios.c
 * Autor: Aleksander Da Silva Toth
 * Disciplina: Estruturas de Dados I
 *
 * Data de criação: 22/08/2025
 * Data da última alteração: 22/08/2025
 *
 *
 * Descrição:
 *      Um programa usa structs que possuem dois campos: nome (string) e idade (int).
 * Crie uma função que recebe como entrada uma lista de structs como citado acima,
 * o número de elementos na lista e um nome. A função deve retornar a idade do elemento
 * cujo nome foi passado ou o valor -1 caso o nome não seja encontrado.
 *
 * ===============================================================================
 * compile: gcc
 * build: Ctrl + shift + B
 * run: ./Aula-04-exercicios.exe
 */

#include <stdio.h>
#include <string.h>

// Estrutura
typedef struct
{
    char nome[50];
    int idade;
} pessoa;

int encontra_elemento(pessoa lst[], int n, char *nome) {
    int idade = -1;
    for (int i = 0; i < n; i++)
    {
        // Precisamos usar a função strcmp. Caso tenha dois nomes iguais, irá retornar o último, pois irá percorrer toda a lista. Pode usar um break por exemplo.
        if (strcmp(lst[i].nome, nome) == 0) { 
            idade = lst[i].idade;
        }
    }
    return idade;
}

int main()
{
    pessoa p[2] = {{"joao", 5}, {"jose", 10}};
    printf("%d", encontra_elemento(p, 2, "jose"));
}