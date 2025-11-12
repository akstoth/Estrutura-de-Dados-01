#include <stdio.h>
#include <stdlib.h>

#define MAX 6  // número máximo de vértices

// ==============================
// Estruturas de dados
// ==============================

// Nó da lista de adjacência ("base")
typedef struct No {
    int vertice;
    struct No* prox;
} No;

// Grafo representado por lista de adjacência
typedef struct {
    int numVertices;
    No* lista[MAX];        // vetor de ponteiros para listas
    int visitado [MAX];    // vetor de vértices visitados
} Grafo;

// Estrutura de fila (implementação simples com vetor)
typedef struct {
    int itens[MAX];
    int frente;
    int tras;
} Fila;


// ==============================
// Funções da Fila
// ==============================

void inicializaFila(Fila *f) {
    f->frente = 0;
    f->tras = 0;
}

int filaVazia(Fila *f) {
    return f->frente == f->tras;
}

void enfileira(Fila *f, int valor) {
    if (f->tras < MAX)
        f->itens[f->tras++] = valor;
    else
        printf("Fila cheia!\n");
}

int desenfileira(Fila *f) {
    if (!filaVazia(f))
        return f->itens[f->frente++];
    else {
        printf("Fila vazia!\n");
        return -1;
    }
}


// ==============================
// Funções para o Grafo
// ==============================

No* criaNo(int v) {
    No* novoNo = (No*) malloc(sizeof(No));
    novoNo->vertice = v;
    novoNo->prox = NULL;
    return novoNo;
}

void adicionaAresta(Grafo* g, int origem, int destino) {
    // adiciona aresta origem -> destino
    No* novoNo = criaNo(destino);
    novoNo->prox = g->lista[origem];
    g->lista[origem] = novoNo;

    // adiciona aresta destino -> origem (grafo não direcionado)
    novoNo = criaNo(origem);
    novoNo->prox = g->lista[destino];
    g->lista[destino] = novoNo;
}


// ==============================
// Busca em Largura (BFS)
// ==============================

void BFS(Grafo* g, int inicio) {
    Fila f;
    inicializaFila(&f);

    g->visitado[inicio] = 1;
    enfileira(&f, inicio);

    printf("BFS a partir do vertice %d: ", inicio);

    // Vamos adicionar os vizinhos da aresta na lista
    int atual;
    while(filaVazia(&f) == 0) {
        atual = desenfileira(&f);
        g->visitado[atual] = 1;
        printf("%d ", atual);
        

        // atual recebe primeiro da fila
        // imprime atual
        No* temp = g->lista[atual];

        // Enquanto temp não for nulo, percorro todos os vizinho
        while (temp != NULL) {
            if(g->visitado[temp->vertice] == 0)
            enfileira(&f, temp->vertice);
            temp = temp -> prox;
        }

    }

    printf("\n");
}


// ==============================
// Programa principal (exemplo)
// ==============================

int main() {
    Grafo* g = 0;

    adicionaAresta(g, 0, 1);
    adicionaAresta(g, 0, 2);
    adicionaAresta(g, 1, 3);
    adicionaAresta(g, 1, 4);
    adicionaAresta(g, 2, 5);

    BFS(g, 0);

    return 0;
}
