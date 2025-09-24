/**
 * @file Aula-05-filas.c
 * @author Aleksander Da Silva Toth
 * @brief Exercícios de filas
 * @version 1.0.0
 * @date 2025-09-05
 *
 * @copyright Copyright (c) 2025
 *
 * =============================================================================
 * @details
 * Este arquivo contém a implementação de uma fila
 * =============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5

// Estrutura que armazena os dados de um aluno
typedef struct
{
    int idade;
    char nome[30];
} Aluno;

typedef struct
{
    int inicio, final, qtd;
    Aluno dados[MAX];
} Fila;

// Cria de maneira dinâmica com o malloc
Fila *cria_Fila()
{
    Fila *fi;
    fi = (Fila *)malloc(sizeof(Fila));
    if (fi != NULL)
    {
        fi->inicio = 0;
        fi->final = 0;
        fi->qtd = 0;
    }
    return fi;
}

void libera_Fila(Fila *fi)
{
    free(fi);
}

int insere_fila(Fila *fi, Aluno *al) {
    if (fi == NULL || al == NULL || fi->qtd == MAX)  {
        return 0;
    }

    fi->dados[fi->final] = *al; // Será o final
    fi->qtd++;
    
    /* 
    // Maneira mais comum de incrementar o valor final e resetar no buffer circular
    fi->final++;
    
    if(fi->final == MAX)
    {
        fi->final = 0;
    }
    */

    //fi->final = (fi->final + 1) % MAX; // Segunda maneira, dessa forma temos 1%5 = 1, 2%5 = 2, 3%5 = 3, 4%5 = 4, 5%5 = 0
    return 1;
}

int remove_fila (Fila *fi, Aluno*al) {
    if (fi == NULL || fi->qtd > 0)  {
        return 0;
    }

    *al = fi->dados[fi->inicio];
    fi->qtd--;
    /* Maneira mais comum de incrementar o valor final e resetar no buffer circular
    fi->inicio++;
    
    if(fi->inicio == MAX)
    {
        fi->inicio = 0;
    }
    */
    
    fi->inicio = (fi->inicio + 1) % MAX;

    return 1;
}

void imprime_pilha(Fila *fi) {  // Basta enviar o ponteiro da pilha, onde é
                                // enviado apenas 4butes, ao invés de n bytes
  for (int i = 0; i < fi->qtd; i++) {
    printf("nome: %s, idade: %d\n", fi->dados[i].nome, fi->dados[i].idade);
  }
}

int conta_nomes_com_inicial(Fila *fi, char inicial) {
    if (fi == NULL || fi->qtd == 0)  {
        return 0;
    }
    int count = 0;
    int pos = fi->inicio; // inicio

    for (int i = 0; i < fi->qtd; i++) { // Repete quantidade
        if(fi->dados[pos].nome[0] == inicial)
        {
            count++;
        }
        pos = (pos + 1) % MAX;
    }
    return count;

}

int main() {
    // Criação da fila de maneira estática, ponto a ponto, inicialmente com valor igual a 0
    Fila fi;
    fi.inicio = 0;
    fi.final = 0;
    fi.qtd = 0;         // quantidade de elementos DENTRO da fila

    char nomes[10][20] = {"aa", "bb", "cc", "dd", "ee", 
                          "ff", "gg", "hh", "ii", "jj"};
    Aluno a;
    for (int i=0; i<3; i++){
        strcpy(a.nome, nomes[i]);
        insere_fila(&fi, &a);
    }
    printf("inicio: %d, final: %d, qtd:%d\n", fi.inicio, fi.final, fi.qtd); 
    //printf("Quantidade de nomes com a inicial b: %d", conta_nomes_com_inicial(&fi,'b'));
    
}