/**
 * @file Aula-05-exercicio-01.c
 * @author Aleksander Da Silva Toth
 * @brief Exercícios de filas
 * @version 1.0.0
 * @date 2025-09-17
 *
 * @copyright Copyright (c) 2025
 *
 * =============================================================================
 * @details
 * Este arquivo contém a implementação de uma fila encadeada
 * =============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
   int matricula;
   char nome[30];
   int idade;
} aluno;

typedef struct elemento {
   aluno dados;
   struct elemento *prox;
} elemento;

typedef struct fila {
   elemento *inicio;
   elemento *final;
   int qtd;
} fila;

// insere novo elemento na fila
int insere_Fila(fila* fi, aluno al) {

   // se fila nula ou não consegue alocar, termina
   if(fi == NULL)
       return 0;
   elemento *no = (elemento*) malloc(sizeof(elemento));
   if(no == NULL)
       return 0;
   no->dados = al;
   no->prox = NULL;

   // se fila vazia novo elemento vai ser o primeiro e último
   if (fi->qtd == 0){
      fi->inicio = no;
      fi->final = no;
      fi->qtd++;
   }
   else{
      // caso contrário, vai ser só o último
      fi->final->prox = no;
      fi->final = no;
      fi->qtd++;
   }
   return 1;
}

// remove todos os elementos e limpa a fila
void destroi_fila(fila* fi) {

   // se fila nula ou vazia, não faz nada
   if(fi == NULL || fi->qtd == 0)
       return;

   // percorre a fila e vai removendo um por um.
   elemento *temp = fi->inicio;
   while(temp != NULL){
        printf("Destruindo: %s %d\n", temp->dados.nome, temp->dados.idade);
        fi->inicio = fi->inicio->prox;
        free(temp);
        temp = fi->inicio;
   }

   fi->qtd = 0;
   fi->inicio = NULL;
   fi->final = NULL;
}

// Exercício 1 - média
float calcula_media(fila* fi) {
    if(fi == NULL || fi->qtd == 0) {
        return -1;
    }
    float count = 0;
    float acum = 0;
    elemento *temp = fi->inicio;

    while(temp != NULL) {
        if(temp->dados.idade > 15) {
            acum += temp->dados.idade;
            count++;
        }
        temp = temp->prox; // É o incremento do ponteiro, aponta para a próxima posição
    }
    return acum/count;

}


// Exercício 3 - remove elemento por posição
int remove_elemento (fila *fi) {
    if(fi == NULL || fi->qtd < 2 ) {
        return 0;
    }
    elemento *temp = fi->inicio;

    if (fi->qtd == 2) {
        fi->inicio = fi->inicio->prox;
        free(temp);
        temp = fi->inicio;
    }
    else {
        elemento *ant = fi->inicio;
        temp = ant->prox;

        //Enquanto não for o penúltimo
        // ant  temp
        // [A]->[B]->[C]-> NULL
        while(temp->prox->prox != NULL) {
            ant = ant->prox;
            temp = temp->prox;
        }
        
        ant->prox = temp->prox;
        free(temp);
    }
    fi->qtd--;
    printf("Removido o penúltimo elemento\n");
    return 1;
}

/* Exercícios sugeridos:
   1 - Percorre fila e calcula a média das idades dos alunos com mais de 15 anos
   2 - Remove ou adiciona elemento com idade específica.
   3 - Remove ou adiciona elemento em posição específica.
*/

int main() {
   // nomes para teste
   char nomes[5][20] = {"ana", "bia", "caio", "ze", "ju"};
   int idades[5] = {10, 12, 19, 13, 20};
   aluno a;

   // cria e inicializa fila
   fila f;
   f.final = NULL;
   f.inicio = NULL;
   f.qtd = 0;

   // insere alguns alunos na fila
   for (int i=0; i<5; i++){
      strcpy(a.nome, nomes[i]);
      a.idade = idades[i];
      insere_Fila(&f, a);
   }

   printf("A media das idades dos alunos com mais de 15 anos: %.1f\n", calcula_media(&f));
   remove_elemento(&f);
   // destroi fila
   destroi_fila(&f);
}