/**
 * @file Aula-06-arvores.c
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

// A estrutura dos nós recebem uma informação, e um ponteiro para esquerda e/ou direita, onde estarão os filhos
typedef struct NO {
    char info;
    struct NO *esq;
    struct NO *dir;
} NO;

// A ideia da ordem de tratamento de Pré-Ordem é Raiz, Esquerda e Direita
void preOrder_ArvBin (NO *raiz) {
    if(raiz == NULL) return;

    if(raiz != NULL) {
        printf("%c\n", raiz->info);
        preOrder_ArvBin(raiz->esq);
        preOrder_ArvBin(raiz->dir);
    }
}

// A ideia da ordem de tratamento de Em-Ordem é Raiz, Esquerda e Direita
void inOrder_ArvBin (NO *raiz) {
    if(raiz == NULL) return;

    if(raiz != NULL) {
        inOrder_ArvBin(raiz->esq);
        printf("%c\n", raiz->info);
        inOrder_ArvBin(raiz->dir);
    }
}

// A ideia da ordem de tratamento de Pós-Ordem é Raiz, Esquerda e Direita
void posOrder_ArvBin (NO *raiz) {
    if(raiz == NULL) return;

    if(raiz != NULL) {
        posOrder_ArvBin(raiz->esq);
        posOrder_ArvBin(raiz->dir);
        printf("%c\n", raiz->info);
    }
}

int count_NO (NO *raiz) {
    if(raiz == NULL) {
        return 0;
    }
    else {
        int filhos_esq = 0;
        int filhos_dir = 0;

        if(raiz != NULL) {
            filhos_esq = count_NO(raiz->esq);
            filhos_dir = count_NO(raiz->dir);
            printf("No %c, filhos: %d\n", raiz->info, filhos_esq + filhos_dir);
            return filhos_esq + filhos_dir + 1;
        }
    }
    
}
/* 
Exemplo de árvore do slide:
            A
           / \
          B   C
         / \
        D   E

Exemplo de árvore do quadro:
            A
           / \
          B   E
               \
                F   
               / \
              G   C
*/

int main(){
    // De maneira estática
    NO A = {'A', NULL, NULL};
    NO B = {'B', NULL, NULL};
    NO C = {'C', NULL, NULL};
    NO D = {'D', NULL, NULL};
    NO E = {'E', NULL, NULL};
    NO F = {'F', NULL, NULL};
    NO G = {'G', NULL, NULL};

    // Exemplo do slide
    A.esq = &B;
    A.dir = &C;
    B.esq = &D;
    B.dir = &E;

  /*  
    // Exemplo do quadro
    A.esq = &B;
    A.dir = &E;
    E.dir = &F;
    F.esq = &G;
    F.dir = &C;
    */

    printf("Modo de tratamento Pre-Ordem:\n");
    preOrder_ArvBin(&A);

    printf("Modo de tratamento Em-Ordem:\n");
    inOrder_ArvBin(&A);

    printf("Modo de tratamento Pos-Ordem:\n");
    posOrder_ArvBin(&A);

    // Teste no Python Tutor
    printf("Total de nos: %d", count_NO(&A));

}