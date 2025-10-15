/**
 * @file AUla-06-arvores-exercicios-02
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
   int bf;
   struct NO *esq;
   struct NO *dir;
} NO;

void print_preOrdem(NO *raiz){
   if(raiz == NULL)
       return;
   if(raiz != NULL){
       printf("info: %d, bf: %d \n", raiz->info, raiz->bf);
       print_preOrdem(raiz->esq);
       print_preOrdem(raiz->dir);
   }
}

int altura(NO *raiz){
    if (raiz == NULL){
        return 0;
    }

    int hd = altura(raiz->dir);
    int he = altura(raiz->esq);
    raiz->bf = hd - he;
    int h;
    if (he > hd){
        h = he;
    }
    else {
        h = hd;
    }
    return h+1;
}
// Recebe um ponteiro pra raiz (no nosso caso o 2) e retorna o novo ponteiro (no nosso caso o 3)
NO *rot_esq(NO *raiz) {
    if(raiz == NULL) {
        return 0;
    }
    
    NO *p = raiz;           //p recebe a raiz (onde o bf é 2, nesse caso o nosso nó 2)
    NO *u = raiz->dir;      //u recebe o filho (onde o bf é 1, nesse caso o nosso nó 3)
    NO *beta = u->esq;      //beta é o neto do 2, filho do 1

    u->esq = p;
    p->dir = beta;
 
    return u;
}

/*
            1
             \ 
              2
               \ 
                3
                 \
                  4
*/

int main(){
    NO x[6] = {{1, 0, NULL, NULL},
               {2, 0, NULL, NULL},
               {3, 0, NULL, NULL},
               {4, 0, NULL, NULL}};

    x[0].dir = &x[1];
    x[1].dir = &x[2];
    x[2].dir = &x[3];

    print_preOrdem(&x[0]);
    printf("\nCalcula altura\n");
    altura(&x[0]);
    print_preOrdem(&x[0]);

    printf("\nRotacao simples a esquerda\n");
    x[0].dir = rot_esq(&x[1]);
    altura(&x[0]);
    print_preOrdem(&x[0]);  
}
