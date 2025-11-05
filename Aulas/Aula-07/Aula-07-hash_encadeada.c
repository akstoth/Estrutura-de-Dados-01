#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// número de ponteiros na tabela
#define MAX 6
struct aluno_t{
   char nome[30];
   int idade;
   struct aluno_t *prox;
};
typedef struct aluno_t aluno;

// função hash (espalhamento)
int hash(char *str, int tamanho) {
    int soma = 0;
    for (int i = 0; str[i] != '\0'; i++)
        soma += str[i];
    return soma % tamanho;
}

void adiciona_elemento(aluno *novo, aluno *tabela[]){
    int idx = hash(novo->nome, MAX);
    printf("nome: %s, idade: %d, idx: %d\n", novo->nome, novo->idade, idx);

    // testa se posição está vazia
    if(tabela[idx] == NULL){
        // se estiver vazia, só adiciona
        tabela[idx] = novo;
    }
    else{
        // caso contrário, adiciona antes do primeiro
        novo->prox = tabela[idx];
        tabela[idx] = novo;
    }
}

int busca_idade(char *nome, aluno *tabela[]){
    int idx = hash(nome, MAX);
    printf("idx %d - ", idx);
    aluno *temp = tabela[idx];
    int idade = -1;
    while(temp != NULL){
        if (strcmp(nome, temp->nome) == 0){
            idade = temp->idade;
            break;
        }
        temp = temp->prox;
    }
    return idade;
}

void imprime_mais_velho(aluno *tabela[]){
    
    aluno *mais_velho = NULL;
    aluno *temp;
    for(int i=0; i<MAX; i++){
        temp = tabela[i];
        while(temp != NULL){
            if (mais_velho == NULL || temp->idade > mais_velho->idade){
                mais_velho = temp;
                printf("(*)nome: %s, maior idade: %d\n", mais_velho->nome, mais_velho->idade);
            }
            temp = temp->prox;
        }
    }

    printf("nome: %s, maior idade: %d\n", mais_velho->nome, mais_velho->idade);
} 


void posicao_mais_elementos(aluno *tabela[]){

    int max_pos = -1;
    int max_el = -1;
    int cont = 0;
    aluno *temp;
    for(int i=0; i<MAX; i++){
        temp = tabela[i];
        cont = 0;
        while(temp != NULL){
            cont = cont + 1;
            temp = temp->prox;
        }

        if(cont > max_el){
            max_pos = i;
            max_el = cont;
        }
    }
    printf("posicao: %d\n", max_pos);
}


int main(){
    aluno *tabela[10] =  {NULL};
    char nomes[10][20] = {"ana", "bia", "julia", "caio", "ze", 
                        "ju", "otavio", "caca", "mario", "borre"};
    int idades[20] = {17, 22, 31, 25, 21, 23, 27, 28, 29, 19};

    for (int i=0; i<10; i++){
        aluno *novo = malloc(sizeof(aluno));
        strcpy(novo->nome, nomes[i]);
        novo->idade = idades[i];
        novo->prox = NULL;
        adiciona_elemento(novo, tabela);
    }

    printf("idade ze: %d\n", busca_idade("ze", tabela));
    printf("idade julia: %d\n", busca_idade("julia", tabela));
    printf("idade robesvaldo: %d\n", busca_idade("robesvaldo", tabela));

    imprime_mais_velho(tabela);
    posicao_mais_elementos(tabela);
}