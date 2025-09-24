/**
 * @file Aula-05-exercicio-02.c
 * @author Aleksander Da Silva Toth
 * @brief Exercícios de filas duplas
 * @version 1.0.0
 * @date 2025-09-17
 *
 * @copyright Copyright (c) 2025
 *
 * =============================================================================
 * @details
 * Este arquivo contém a implementação de uma filas duplas
 * =============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno{ 
   int matricula;
   char nome[30];
   float n1,n2,n3;
} aluno;

typedef struct elemento{
   aluno dados;
   struct elemento *prox;
   struct elemento *ant;
} elemento;

typedef struct deque{
   elemento *inicio;
   elemento *final;
   int qtd;
} deque;

// insere novo elemento
int insere_inicio(deque* d, aluno al){

    // se deque nulo ou não consegue alocar
    if(d == NULL)
        return 0;
    elemento *no = (elemento*) malloc(sizeof(elemento));
    if(no == NULL)
        return 0;
    no->dados = al;
    no->prox = NULL;
    no->ant = NULL;

    // se deque vazio inicio e fim apontam pro novo
    if (d->qtd == 0){
        d->inicio = no;
        d->final = no;
    }
    // senão:
    else{
        no->prox = d->inicio;
        d->inicio->ant = no;
        d->inicio = no;
    }
   d->qtd++;
   return 1;
}

// remove elemento do final do deque
void remove_final(deque *d){
   if(d == NULL || d->qtd == 0)
       return;

    elemento *temp = d->final;
    printf("removendo: %s\n", temp->dados.nome);
    
    // destroi o único elemento e atuliza ponteiros
    if (d->qtd == 1){
        free(temp);
        d->inicio = NULL;
        d->final = NULL;
    }
    else{
        d->final = d->final->ant;
        d->final->prox = NULL;
        free(temp);
    }
    d->qtd--;
}

// Exercício - adiciona elemento na segunda posição, precisa de pelo menos um elemento

int adiciona_elemento(deque *d, aluno a) {
    if(d == NULL || d->qtd < 1) {
        return 0;
    }

    elemento *no = (elemento*) malloc(sizeof(elemento));
    if(no == NULL)
        return 0;

    no->dados = a;

    if (d->qtd == 1) {

        d->inicio->prox = no;
        no->prox = NULL; 
        no->ant = d->inicio;
        d->final = no;
    }
    else {

        elemento *prim = d->inicio;
        elemento *seg = d->inicio->prox;

        prim->prox = no;
        seg->ant = no;
        no->prox = seg;
        no->ant = prim;
    }

    d->qtd++;
    
}


int main(){
    char nomes[5][20] = {"ana", "bia", "caio", "ze", "ju"};
    aluno a;
    deque d;
    d.final = NULL;
    d.inicio = NULL;
    d.qtd = 0;

    for (int i=0; i<5; i++){
        strcpy(a.nome, nomes[i]);
        insere_inicio(&d, a); // Como insere no inicio da fila, os nomes ficam no final como: ju, ze, caio, bia e ana
    }

    strcpy(a.nome, "val");
    adiciona_elemento(&d, a);

    while(d.inicio != NULL){
        remove_final(&d);
    }
    
}