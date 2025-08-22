/* ===============================================================================
 * Arquivo: Aula-03-lista.c
 * Autor: Aleksander Da Silva Toth
 * Disciplina: Algoritmos e Estruturas de Dados I
 * 
 * Data de criação: 20/08/2025
 * Data da última alteração: 20/08/2025	
 * 
 * 
 * Descrição: 
 * 
 * compile: gcc 
 * build: Ctrl + shift + B
 * run: ./Aula-03-lista.c
 */

//https://codefile.io/f/hQrbgIR5sv
#include <stdio.h>
#include <string.h>

typedef struct aluno{
    char nome[25];
    int idade;
    struct aluno *prox;
} aluno;


// Função para imprimir todos os elementos da lista. A função recebe um ponteiro para o primeiro elemento da lista encadeada, ou seja, o primeiro aluno
void imprime_lista(aluno *prim){
    // Ponteiro auxiliar começa no primeiro elemento
    aluno *aux = prim;
    // Enquanto o ponteiro auxiliar não for nulo, imprime o nome e a idade do aluno
    while(aux != NULL){
        // Imprime o nome e a idade do aluno atual, o aux aponta para o nome e para a idade, ele recebe todos os dados da struct aluno
        printf("Nome: %s, Idade: %d\n", aux->nome, aux->idade);
        aux = aux->prox;
    }
}

// inverte o segundo e terceiro elementos da lista:
// terceiro vira segundo e segundo vira terceiro
// Função que recebe a struct aluno
void inverte_seg_ter(aluno *prim){
    // Ponteiros auxiliares para percorrer a lista
    aluno *seg = prim->prox; // segundo elemento
    aluno *ter = seg->prox; // Ou prim->prox->prox; // terceiro elemento
    
    // Ana aponta para Jo
    seg->prox = ter->prox;
    
    // Zeca aponta para Ana
    ter->prox = seg; // Ou prim->prox

    // Jose aponta para Zeca
    prim->prox = ter;
}

// Função para adicionar um novo aluno no inicio do elemento. Passa-se um ponteiro duplo.
void adiciona_inicio(aluno **p_prim, aluno *novo){
    // Atualiza o proximo do novo
    novo->prox = *p_prim; // Deve-se usar um ponteiro, pois p_prim é um ponteiro duplo

    // Atualiza o primeiro elemento
    *p_prim = novo; // Aqui não é necessárioo, pois já é um ponteiro simples

}

int main()
{
    
    // Cria 5 alunos de maneira estática, cada um em cada memória, sem array
    // Cada aluno tem nome, idade e ponteiro para o próximo aluno, sendo que o último aluno irá apontar para NULL. 
    aluno a0 = {"Jose", 15, NULL}; 
    aluno a1 = {"Zeca", 22, NULL};
    aluno a2 = {"Caio", 15, NULL};
    aluno a3 = {"Ana", 18, NULL};
    aluno a4 = {"Jo", 21, NULL};
    aluno a5 = {"Bob", 21, NULL};

    // Cria as ligações da lista encadeada, ou seja, altera o ponteiro prox de cada aluno para apontar para o próximo aluno.
    // Essa lista encadeada interliga cada aluno.
    aluno *primeiro = &a0;  // ponteiro para o primeiro elemento, a0. * Indica que é um ponteiro e & indica o endereço de a0
    a0.prox = &a3;          // jose aponta p ana, usando prox e o endereço de a3
    a3.prox = &a1;          // ana aponta p zeca
    a1.prox = &a4;          // zeca aponta p jo
    a4.prox = &a2;          // jo aponta  p caio (e caio aponta para nulo)
    imprime_lista(primeiro);

    // Como a função associa a ponteiros, altera-se a estrutura como um todo, diferente de arrays, onde se copia o valor
    // Inverte o segundo e terceiro elementos da lista
    printf("\nLista antes da mudanca:\n");
    imprime_lista(primeiro);
    inverte_seg_ter(primeiro);
    printf("\nLista apos mudanca:\n");
    imprime_lista(primeiro);

    // Esse é um exemplo de lista encadeada, onde cada elemento aponta para o próximo, permitindo a inserção e remoção de elementos de maneira eficiente.
    // Em structs maiores com listas, o uso de ponteiros é essencial para manipular os dados sem precisar copiar toda a estrutura, economizando memória e tempo de processamento.   
   
    adiciona_inicio(&primeiro, &a5);
    printf("\nApos novo aluno:\n");
    imprime_lista(primeiro);
    return 0;
}
