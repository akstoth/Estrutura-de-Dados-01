/**
 * @file Aula-05-filas_02.c
 * @author Aleksander Da Silva Toth
 * @brief Exercícios de filas - continuação
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

 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*Exercícios
    1: Função para imprimir todos os elementos da fila
    2: Função para contar alunos cujo nome começa com a letra 'a' ou 'A'
    3: Remover elemento em determinada posição
    4: Adicionar elemento em determinada posição
    5: Remover elementos com determinada inicial
*/
int modoRemovePos;

typedef struct aluno{
   int idade;
   char nome[30];
} aluno;

// número de elementos na fila
#define MAX 5

//Definição do tipo Fila
struct fila{
   int inicio, final, qtd;
   struct aluno dados[MAX];
};

typedef struct fila Fila;


int insere_Fila(Fila* fi, struct aluno al){
   if(fi == NULL)
       return 0;

   // Verifica se a fila está cheia
   if(fi->qtd >= MAX)
       return 0;

   // escreve dado na primeira posição livre
   fi->dados[fi->final] = al;

   // incrementa seta, se chegar no final volta p zero
   fi->final = (fi->final+1)%MAX;
   fi->qtd++;
   return 1;
}

// Remove um elemento do início da fila:
int remove_Fila(Fila* fi){
   if(fi == NULL || fi->qtd == 0)
       return 0;
   fi->inicio = (fi->inicio+1)%MAX;
   fi->qtd--;
   return 1;
}

// Exercício 1: imprime fila
int imprime_fila(Fila* fi){
    if (fi == NULL || fi->qtd == 0){ // Testamos se nosso fi é nulo ou se a quantidade é igual a zero (sem elementos na fila)
        return 0;
    }
    int pos = fi->inicio; // A posição inicial. Quando a fila está vazia, o inicio é igual ao final e quando está cheio, o final é igual o inicio
    for (int i = 0; i < fi->qtd; i++) {
        printf("Nome: %s, Idade: %d, Posicao: %d\n", fi->dados[pos].nome, fi->dados[pos].idade, pos); // Imprimos os dados com o índice posição, pois assim não estará em conflito
        pos = (pos + 1) % MAX; // Quando chegar a 5. voltará ao inicio
    }
    return 1;
}

// Exercício 2: função para contar alunos cujo nome começa com a letra 'a' ou 'A'
int conta_nomes(Fila* fi){
    char inicial = 'a';
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

// Exercício 3: Função para remover elemento em determinada posição
int remove_pos(Fila* fi, int pos){
   if(fi == NULL || fi->qtd <= pos - 1)
       return 0;

    printf("\nRemovendo posicao: %d\n", pos);
    
    switch (modoRemovePos)
    {
    case 0: // Primeira maneira de fazer modoRemovePos = 0, não funcionou. Caso o inicial e final forem de posições diferentes de 0 ele repete os últimos ítens
        
        for(int i = 0; i < fi->qtd; i++){
            if(i == pos){
                for(int j = i; j < fi->qtd - 1; j++){
                    fi->dados[j] = fi->dados[j + 1];
                }
                fi->qtd--;
                fi->final--;   
                if(fi->final < 0)
                {
                    fi->final = MAX - 1;
                }
            }
        }
        break;
    case 1: 

        int dest = (fi->inicio + pos) % MAX;
        int orig = (dest + 1) % MAX;

        for(int i = 0; i < fi->qtd - pos - 1; i++){
            fi->dados[dest] = fi->dados[orig];
            dest = (dest + 1) % MAX;
            orig = (orig + 1) % MAX;
        }
        fi->qtd--;
        //fi->final = (fi->final - 1) % MAX; // Decrementa o final, considerando o buffer circular. MOD(%) para números negativos não é bom
        fi->final--;   
        if(fi->final < 0)
        {
            fi->final = MAX - 1;
        }

        break;
    default:
        break;
    }

    imprime_fila(fi);
    return 1;
}

// Exercício 5: Remover elementos com determinada inicial
int remove_por_inicial(Fila* fi, char inicial) {
    if(fi == NULL || fi->qtd == 0)
       return 0;

    printf("\nRemovendo posicao com a inicial: %c\n", inicial);

    int dest = fi->inicio;
    int orig = fi->inicio; // Irá percorrer tudo
    int removidos = 0;

    for(int i = 0; i < fi->qtd; i++){
        if(fi->dados[orig].nome[0] != inicial){
            fi->dados[dest] = fi->dados[orig];
            dest = (dest + 1) % MAX;
        }
        else {
            removidos++;
        }
        orig = (orig + 1) % MAX;
    }

    fi->qtd =  fi->qtd - removidos;
    fi->final = fi->final - removidos;
    if(fi->final < 0)
    {
        fi->final = MAX - 1;
    }
    imprime_fila(fi);
}

int main(){

    Fila f;
    f.inicio = 2;
    f.final = 2;
    f.qtd = 0;

    modoRemovePos = 1;

    struct aluno a0;
    char nomes[5][20] = {"Ana", "Abigail", "adalba", "lucio", "muriel"};
    int idades[5] = {10, 20, 15, 25, 17};
 
    for (int i=0; i<5; i++){ // Necessário fazer um for para preencher os dados na fila
        strcpy(a0.nome, nomes[i]);
        a0.idade = idades[i];
        insere_Fila(&f, a0);
    }

    imprime_fila(&f);
    remove_por_inicial(&f, 'A');
    
    //printf("primeiro elemento: %s %d\n", f.dados[0].nome, f.dados[0].idade);
    //printf("segundo elemento: %s %d\n", f.dados[1].nome, f.dados[1].idade);
    remove_pos(&f, 3);

    return 0;
}

