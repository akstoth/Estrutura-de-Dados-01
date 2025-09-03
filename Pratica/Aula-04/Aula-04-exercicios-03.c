/* ===============================================================================
 * Arquivo: Aula-04-exercicios-03.c
 * Autor: Aleksander Da Silva Toth
 * Disciplina: Estruturas de Dados I
 *
 * Data de criação: 29/08/2025
 *
 *
 * Descrição: Exercícios diversos - pilha dinâmica (lista encadeada)
 *
 * ===============================================================================
 * compile: gcc
 * build: Ctrl + shift + B
 * run: ./Aula-04-exercicios.exe
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// aluno (dado)
struct aluno
{
    int idade;
    char nome[30];
};

// nó: dado + ponteiro para o próximo
typedef struct no
{
    struct aluno dado;
    struct no *prox;
} no;

// adiciona ao topo da pilha
int push(no **topo, struct aluno al)
{
    if (topo == NULL)
    {
        return 0;
    }
    // cria um novo elemento
    no *novo = (no *)malloc(sizeof(no));
    if (novo == NULL)
    {
        return 0;
    }

    // copia dados para o novo nó
    novo->dado = al;

    novo->prox = *topo;
    *topo = novo;
    return 1;
}

// remove do topo da pilha
int pop(no **topo, struct aluno *al)
{
    if (topo == NULL || *topo == NULL)
    {
        return 0;
    }

    // temporário aponta para o primeiro elemento
    no *temp = *topo;

    // copia conteúdo
    *al = temp->dado;

    // topo aponta para o segundo elemento
    *topo = temp->prox;

    // destroi primeiro
    free(temp);
    return 1;
}

/* ***************************************************
** EXERCÍCIOS
** ***************************************************/

// exercício 1 libera pilha (remove todos os elementos)
void libera_pilha(no **topo)
{
    if (topo == NULL)
    {
        return;
    }

    struct aluno x;
    struct aluno *p_x;
    p_x = &x;

    while (pop(topo, &x))
    {
        printf("removido %s %d\n\n", x.nome, x.idade);
        // printf("removido %s %d", p_x->nome, p_x->idade);
        // printf("removido %s %d", (*p_x).nome, p_x->idade);
    }
}

// exercício 2 imprime pilha
void imprime_pilha(no **topo)
{
    if (topo == NULL)
    {
        return;
    }
    no *temp = *topo; // Como é um ponteiro duplo, usamos um para apontar ao primeiro elemento
                      // Temp é um ponteiro temporário que percorre a pilha, logo, parará quando chegar ao final, sendo NULL
    while (temp != NULL)
    {
        printf("Nome: %s, Idade: %d\n", temp->dado.nome, temp->dado.idade); // temp->dado.nome: temp é um ponteiro de dado, nome é um elemento do struct dado
        temp = temp->prox;                                                  // Usa-se temp que aponta para o prox.
    }
}

// exercício 3 insere em posição arbitrária
int push_pos(no **topo, struct aluno al, int pos) { // Receber a posição como parâmetro
    if (topo == NULL) { // Se o nó for nulo
        return 0;
    }


    // cria um novo elemento
    no *novo = (no *)malloc(sizeof(no));
    if (novo == NULL) {
        return 0;
    }

    // copia dados para o novo nó
    novo->dado = al;

    if (pos < 0)  { // Se pos for menor que 0
        return 0;
    }

    if (pos == 0) { // Se pos for o topo
        novo->prox = *topo;
        *topo = novo;
        //return push(topo, al); // Reaproveita a função push
    }
    else {
        
        no *temp = *topo; // temp começa no topo
        for(int i = 0; i < pos-1; i++){ // Se pos é igual a 4, deve parar na posição anterior (0 a 3)
            temp = temp->prox;
            
            if (temp == NULL) {
                return 0;
            }
        }

        novo->prox = temp->prox; // O próximo do novo é o próximo do temp (novo deve ser o primeiro a ser referenciado)
        temp->prox = novo; 

    }

    return 1;
}

// exercício 4: remove struct com idade específica
int pop_idade(no **topo, int rem_idade)
{
    if(topo == NULL || *topo == NULL) { // Se o topo for nulo ou a pilha estiver vazia
        return -1;
    }

    
    if ((*topo)->dado.idade == rem_idade) { // Se pos for o topo
        no *temp = *topo;           // Cria-se um nó temporário para liberar a memória
        *topo = (*topo)->prox;      // Atualiza o topo para o próximo com o ponteiro
        free(temp);                 // Libera a memória do nó temporário
    }
    else {
        no *temp = *topo;           // temp começa no topo
        no *ant = *topo;            // ant é o nó anterior, começa no topo também
        while(temp->dado.idade != rem_idade) {
            ant = temp;             // O anterior aponta para temp
            temp = temp->prox;      // Temp aponta para o proximo

            if(temp == NULL) {
                return 0; // Não encontrou a idade
            }
        } 

        // Remove o elemento
        ant->prox = temp->prox;     // O proximo do anterior aponta para o próximo do temp
        free(temp);                 // Libera a memória do temp
    }

    return 1;
}

// outros exercícios:
// remove o último ou o penúltimo elemento
// conta elementos com idade maior que x
// insere elemento na base da pilha
// remove o segundo elemento da pilha

int main()
{
    no *topo = NULL;
    struct aluno a0;

    int idades[5] = {12, 15, 17, 19, 25};
    char nomes[5][15] = {"pedro", "caio", "ze", "ju", "bia"};

    // adiciona 5 elementos
    for (int i = 0; i < 5; i++)
    {
        a0.idade = idades[i];
        strcpy(a0.nome, nomes[i]);
        push(&topo, a0);
    }

    a0.idade = 50;
    strcpy(a0.nome, "florisbela");
    push_pos(&topo, a0, 4);
    imprime_pilha(&topo);
    //libera_pilha(&topo);

    pop_idade(&topo, 17);
    printf("Depois de remover a idade 17:\n");
    imprime_pilha(&topo);
}