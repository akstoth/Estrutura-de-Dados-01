/**
 * @file Aula-06-arvores-02.c
 * @author Aleksander Da Silva Toth
 * @brief Exercícios de filas - continuação
 * @version 1.0.0
 * @date 2025-09-19
 *
 * @copyright Copyright (c) 2025
 *
 * =============================================================================
 * @details
 * Este arquivo contém a implementação de uma árvore binária
 * =============================================================================
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct NO {
    int info;
    struct NO *esq;
    struct NO *dir;
} NO;

// A ideia da ordem de tratamento de Pré-Ordem é Raiz, Esquerda e Direita
void preOrder_ArvBin (NO *raiz) {
    if(raiz == NULL) return;

    if(raiz != NULL) {
        printf("%d\n", raiz->info);
        preOrder_ArvBin(raiz->esq);
        preOrder_ArvBin(raiz->dir);
    }
}

// A ideia da ordem de tratamento de Em-Ordem é Esquerda, Raiz e Direita
void inOrder_ArvBin (NO *raiz) {
    if(raiz == NULL) return;

    if(raiz != NULL) {
        inOrder_ArvBin(raiz->esq);
        printf("%d\n", raiz->info);
        inOrder_ArvBin(raiz->dir);
    }
}

// A ideia da ordem de tratamento de Pós-Ordem é Esquerda, Direita e Raiz
void posOrder_ArvBin (NO *raiz) {
    if(raiz == NULL) return;

    if(raiz != NULL) {
        posOrder_ArvBin(raiz->esq);
        posOrder_ArvBin(raiz->dir);
        printf("%d\n", raiz->info);
    }
}

int count_NO (NO *raiz) {
    if(raiz == NULL) {
        return 0;
    }
    else {
        int filhos_esq = count_NO(raiz->esq);
        int filhos_dir = count_NO(raiz->dir);

        printf("No %d, filhos: %d\n", raiz->info, filhos_esq + filhos_dir);

        return filhos_esq + filhos_dir + 1;
    }
}

int count_folhas (NO *raiz) {
    // Primeiro verificamos se a árvore está vazia
    if(raiz == NULL) {
        return 0; // Não há folhas em uma árvore vazia ou somente um ramo nulo
    }
    // Se não, entramos na árvore
    else {
        // Verificamos se o nó atual é uma folha, caso positivo retornamos 1 (aqui já começamos a contar, pois na lógica da árvore, uma folha é um nó sem filhos)
        if(raiz->esq == NULL && raiz->dir ==NULL) {
            return 1; // Encontramos uma folha
        }
        // Caso contrário, continuamos descendo na árvore
        else {
            return count_folhas(raiz->esq) + count_folhas(raiz->dir); // Somamos as folhas encontradas nas subárvores esquerda e direita de maneira recursiva
        }
    }
}

// Soma todos os valores menores que x
int soma_menores(NO *raiz, int x) {
    if(raiz == NULL) {
        return 0;
    }
    int ret = 0, total_esq  = 0, total_dir = 0;

    // Verificamos se o valor do nó atual é menor que x
    if(raiz->info < x) {
        ret = raiz->info; // Se for, adicionamos o valor do nó atual à soma
    }

    total_esq = soma_menores(raiz->esq, x); // Soma dos valores menores que x na subárvore esquerda
    total_dir = soma_menores(raiz->dir, x); // Soma dos valores menores que x na subárvore direita

    return ret + total_esq + total_dir; // Retorna a soma total
}

// Para cada nó, verificamos a altura da subárvore esquerda e direita, pegamos o maior valor entre os dois e somamos 1 (que representa o nó atual)
int altura_arvore(NO *raiz) {
    if(raiz == NULL) {
        return 0;
    }

    int altura_esq = altura_arvore(raiz->esq);
    int altura_dir = altura_arvore(raiz->dir);

    if(altura_esq > altura_dir) {
        return altura_esq + 1;
    }
    else {
        return altura_dir + 1;
    }

    return 0;
}

/* 
Exemplo de árvore
            15
           / \
          25 20
         / \   
        12 18
             \  
              27   
*/

int main(){
    // De maneira estática
    NO x[6] = {{15, NULL, NULL}, 
               {25, NULL, NULL}, 
               {20, NULL, NULL}, 
               {12, NULL, NULL}, 
               {18, NULL, NULL},
               {27, NULL, NULL}};
    x[0].esq = &x[1];
    x[0].dir = &x[2];
    x[1].esq = &x[3];
    x[1].dir = &x[4];
    x[2].dir = &x[5];  
    
    printf("Modo de tratamento Pre-Ordem:\n");
    preOrder_ArvBin(&x[0]);

    printf("Modo de tratamento Em-Ordem:\n");
    inOrder_ArvBin(&x[0]);

    printf("Modo de tratamento Pos-Ordem:\n");
    posOrder_ArvBin(&x[0]);

    // Teste no Python Tutor
    printf("Total de nos: %d\n", count_NO(&x[0]));

    printf("Total de folhas: %d\n", count_folhas(&x[0]));

    printf("Soma dos valores menores que 18: %d\n", soma_menores(&x[0], 18));

    printf("Altura da arvore: %d\n", altura_arvore(&x[0]));

}