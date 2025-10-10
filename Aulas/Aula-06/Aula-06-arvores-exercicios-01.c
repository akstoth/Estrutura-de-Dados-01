/**
 * @file AUla-06-arvores-exercicios-01
 * @author Aleksander Da Silva Toth
 * @brief Exercícios de filas - continuação
 * @version 1.0.0
 * @date 2025-10-10
 *
 * @copyright Copyright (c) 2025
 *
 * =============================================================================
 * @details
 * Cálcular o fator de balanceamento
 * =============================================================================
 */

#include <stdlib.h>
#include <stdio.h>

typedef struct NO{
   int info;
   char cod;
   struct NO *esq;
   struct NO *dir;
} NO;

// imprime em ordem
void imprime_arvore(NO *raiz){
    if (raiz == NULL){
        return;
    }
    imprime_arvore(raiz->dir);
    printf("%d - ", raiz->info);
    imprime_arvore(raiz->esq);
    return;
}

// retorna 1 se achou e zero se não achou o nó
int busca_no(NO *raiz, int info){
    NO *temp = raiz;
    while(temp != NULL && temp->info != info){
        if(info < temp->info){
            temp = temp->esq;
        }
        else{
            temp = temp->dir;
        }
    }
    if (temp==NULL){
        return 0;
    }
    else{
        return 1;
    }
}

int busca_no_rec(NO *raiz, int info){
    // não encontrou
    if (raiz == NULL){ 
        return 0;
    }
    // encontrou
    else if(info == raiz->info){
        return 1;
    }  
    // buscando numero maior
    else if(info > raiz->info){
        return busca_no_rec(raiz->dir, info);
    }
    // buscando numero menor
    return busca_no_rec(raiz->esq, info);

}
/*
            15
           /   \ 
          9     25
         / \    /  \ 
        5  12  19  27
*/

/* **************************************************** *
**                     EXERCÍCIOS                       *
** 1 - imprimir árvore
** 2 - inserir nó sem recursividade
** 3 - inserir nó com recursividade
** 4 - conta elementos pares
** 5 - remover nó (difícil)
*/

int adiciona_no_rec(NO *raiz, NO *novo){
    // se raiz nula ou dado já existente: não pode adicionar
    if (raiz==NULL || novo==NULL || novo->info==raiz->info){
        return 0;
    }

    // se chave a ser adicionada maior do que a chave da raiz
    if (novo->info > raiz->info){
        // se não tem filho na direita
        if (raiz->dir == NULL){
            raiz->dir = novo;
            return 1;
        }
        else{
            // se já tem filho, chama a função com o filho como raiz
            return adiciona_no_rec(raiz->dir, novo);
        }
    }
    // novo nó tem chave menor
    else{
        if (raiz->esq == NULL){
            raiz->esq = novo;
            return 1;
        }
        else{
            return adiciona_no_rec(raiz->esq, novo);
        }
    }
}

int conta_pares(NO *raiz){
    if (raiz == NULL){
        return 0;
    }

    int pares = conta_pares(raiz->esq) + conta_pares(raiz->dir);
    if (raiz->info % 2 == 0){
        pares = pares + 1;
    }
    return pares;
}

int altura(NO *raiz) {
    if (raiz == NULL) {
        return 0;
    }
    int hD = altura(raiz->dir);
    int hE = altura(raiz->esq);
    int h;

    // Contamos a altura verificando cada folha, somando um ao retornar após comparar entre o lado esquerdo e o direito
    if (hD > hE) {
        h = hD + 1;
    }
    else {
        h = hE + 1;
    }
    printf("chave: %d, altura: %d\n", raiz->info, h);
    return h;
}

int main(){
    NO x[7] = {{15, 'A', NULL, NULL},   //x[0]
               {9,  'B', NULL, NULL},   //x[1]
               {25, 'C', NULL, NULL},   //x[2]
               {5,  'D', NULL, NULL},   //x[3]
               {12, 'E',NULL, NULL},    //x[4]
               {19, 'F',NULL, NULL},    //x[5]
               {32, 'G',NULL, NULL}};   //x[6]

    x[0].esq = &x[1];
    x[0].dir = &x[2];
    x[1].esq = &x[3];
    x[1].dir = &x[4];
    x[2].esq = &x[5];
    x[2].dir = &x[6];

    //printf("busca 25: %d\n", busca_no(&x[0], 25));
    //printf("busca 11: %d\n", busca_no(&x[0], 11));
    //printf("busca 16: %d\n", busca_no(&x[0], 16));
    /*
    imprime_arvore(&x[0]);
    
    printf("\n pares: %d\n", conta_pares(&x[0]));
    NO n = {10, 'X', NULL, NULL};
    adiciona_no_rec(&x[0], &n);
    imprime_arvore(&x[0]);
    printf("\n pares: %d", conta_pares(&x[0]));
    */
    altura(&x[0]);
}

