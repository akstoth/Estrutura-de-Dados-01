/* ===============================================================================
 * Arquivo: Aula-04-exercicios-02.c
 * Autor: Aleksander Da Silva Toth
 * Disciplina: Estruturas de Dados I
 *
 * Data de criação: 29/08/2025
 *
 *
 * Descrição: Exercícios diversos
 *
 * ===============================================================================
 * compile: gcc
 * build: Ctrl + shift + B
 * run: ./Aula-04-exercicios.exe
 */

#include <stdio.h>

#define MAX 100
struct aluno
{
    int idade;
    char nome[30];
};

typedef struct Pilha
{
    int qtd;
    struct aluno dados[MAX];
} Pilha;

// adiciona elemento à pilha
int push(Pilha *p, struct aluno al)
{
    // se não pode adicionar retorna zero
    if (p == NULL || p->qtd >= MAX)
    {
        return 0;
    }

    // copia o dado para o array e atualiza qtd
    p->dados[p->qtd] = al;
    p->qtd++;
    return 1;
}

// lê elemento do topo da pilha
int top(Pilha *p, struct aluno *al)
{
    // se não pode ler retorna zero
    if (p == NULL || p->qtd <= 0)
    {
        return 0;
    }

    // copia o dado para o array e atualiza qtd
    *al = p->dados[p->qtd - 1];
    return 1;
}

// lê e remove o elemento do topo da pilha
int pop(Pilha *p, struct aluno *al)
{
    // se não pode ler retorna zero
    if (p == NULL || p->qtd <= 0)
    {
        return 0;
    }

    // copia o dado para o array e atualiza qtd
    *al = p->dados[p->qtd - 1];
    p->qtd--;
    return 1;
}

// exercício 1: adiciona 5 pessoas e remove uma da pilha
void estado_inicial(Pilha *p)
{
    // cria uma struct do tipo aluno
    struct aluno a0;
    int idades[5] = {12, 15, 17, 19, 25};
    char nomes[5][15] = {"pedro", "caio", "ze", "ju", "bia"}; // Cuidado, se na criação nomes[5][5], se ficar com 5 ou mais, sobrepõe o nome seguinte

    // adiciona 5 elementos
    for (int i = 0; i < 5; i++)
    {
        a0.idade = idades[i];
        strcpy(a0.nome, nomes[i]); // (destino, origem)

        // comando push
        push(p, a0);
    }

    // remove um elemento:
    pop(p, &a0); // Pop recebe um ponteiro para aluno, logo enviamos o endereço com &. Retira o último
    // pop(p, &a0); // Retira o penúltimo
    top(p, &a0);                                      // Mostra quem está no topo
    //printf("nome: %s, idade: %d", a0.nome, a0.idade); // Com dois pop, retira-se e ainda salva o último retirado, mas quem está no topo é ze
}

// exercício 2: calcular a média das idades dos alunos menores de idade
float media_menores(Pilha *p)
{
    //printf("\nquantidade: %d", p->qtd);
    float media;
    float qtd = 0;
    int soma = 0;

    for (int i = 0; i < p->qtd; i++)
    {
        if (p->dados[i].idade < 18)
        { // Como temos um ponteiro p, com um array de structs dados, usamos o indice no dados e como já estamos usando o ->, usamos o .idade
            soma += p->dados[i].idade;
            qtd++;
        }
    }

    return media = soma / qtd;
}

// exercício 3 remover o primeiro elememento pelo campo idade
int remove_por_idade(Pilha *p, int idade)
{
    int encontrado = 0;

    // encontra posição do elemento a ser removido
    // remove elemento
    for (int i = 0; i < p->qtd; i++)
    {
        if (p->dados[i].idade == idade)
        {
            encontrado = 1;
            p->qtd--;
        }
        if (encontrado != 0)
        {
            p->dados[i] = p->dados[i + 1];
        }
    }
    return encontrado;
}

void imprime_pilha(Pilha *p) { // Basta enviar o ponteiro da pilha, onde é enviado apenas 4butes, ao invés de n bytes
    for(int i = 0; i < p->qtd; i++)
        printf("nome: %s, idade: %d\n", p->dados[i].nome, p->dados[i].idade);
    
}

int main()
{
    // cria uma pilha estática
    Pilha minha_pilha;
    minha_pilha.qtd = 0;

    // preenche a pilha
    estado_inicial(&minha_pilha);
    printf("Estado inicial: \n");
    imprime_pilha(&minha_pilha);

    // mostra media
    printf("\nmedia: %.2f\n", media_menores(&minha_pilha));

    // remove e mostra media
    remove_por_idade(&minha_pilha, 15);
    printf("\nmedia apos rem: %.2f\n", media_menores(&minha_pilha));

    printf("\nEstado final: \n");
    imprime_pilha(&minha_pilha);
}
