#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX 10
// nota que o elemento agora nao tem ponteiro para o próximo
struct aluno_t{
   char nome[30];
   int idade;
};
typedef struct aluno_t aluno;

int hash(char *str, int tamanho) {
    int soma = 0;
    for (int i = 0; str[i] != '\0'; i++)
        soma += str[i];
    return soma % tamanho;
}


void adiciona_elemento(aluno novo, aluno tabela[]){
    // função hash calcula a posição na tabela
    int idx = hash(novo.nome, MAX);
    printf("nome: %s hash: %d\n", novo.nome, idx);

    // enquanto posição ocupada, pula para a próxima
    while(tabela[idx].nome[0] != '\0'){
        idx = (idx + 1) % MAX;
    }
    // copia dados para a tabela
    tabela[idx] = novo;
}

int busca_idade(char *nome, aluno tabela[]){

    // calcula a posição na tabela
    int idx = hash(nome, MAX);
    int first_idx = idx;

    // percorre tabela
    while(tabela[idx].nome[0] != '\0' &&                // posição na tabela ocupada
                strcmp(nome, tabela[idx].nome) != 0){   // e nome diferente do buscado

        idx = (idx + 1) % MAX;

        // tabela cheia e item ausente
        if(idx == first_idx){
            break;
        }
    }

    // testa se nome foi encontrado
    int ret;
    if(strcmp(nome, tabela[idx].nome) != 0){
        ret = -1;
    }
    else{
        ret = tabela[idx].idade;
    }
    return ret;
}


int main(){

    aluno tabela[10];
    memset(tabela, 0, sizeof(tabela));

    char nomes[10][20] = {"ana", "bia", "julia", "caio", "ze", 
                        "ju", "otavio", "caca", "mario", "borre"};
    int idades[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // adiciona alunos à tabela
    aluno novo;
    for (int i=0; i<10; i++){
        strcpy(novo.nome, nomes[i]);
        novo.idade = idades[i];
        adiciona_elemento(novo, tabela);
    }

    printf("ana: %d\n", busca_idade("ana", tabela));
    printf("julia: %d\n", busca_idade("julia", tabela));
    printf("ze: %d\n", busca_idade("ze", tabela));
    printf("ju: %d\n", busca_idade("ju", tabela));

}