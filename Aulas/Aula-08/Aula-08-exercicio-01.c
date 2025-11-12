#include <stdio.h>
#include <stdlib.h>

#define MAX 4

// Cria uma estrutura de nó com ponteiro para o próximo elemento
typedef struct No {
    int vertice;
    struct No* prox;
} No;

int criar_aresta(No* g[MAX], int origem, int destino) {
    // cria e preenche a nova aresta de maneira dinâmica
    No *novo = (No *)malloc(sizeof(No));
    novo->vertice = destino;

    // adiciona a aresta ao grafo
    novo->prox = g[origem]; // nova caixa aponta para onde o grafo apontava
    g[origem] = novo;       // grafo aponta para nova caixa

    return 0;
}

// retorna 1 se existe conexao ou zero caso contrário
int existe_conexao(No* g[MAX], int origem, int destino) {
    No *temp = g[origem];
    while(temp != NULL){
        if(temp->vertice == destino){
            return 1;
        }
        temp = temp->prox;
    }
    return 0;
}

void imprime_vizinhos(No* g[MAX]){
    printf("\nvizinhos\n");
    for(int origem = 0; origem < MAX; origem++){
        printf("No %d:", origem);

        No* temp = g[origem];
        while(temp != NULL){
            printf(" %d", temp->vertice);
            temp = temp->prox;
        }
        printf("\n");
    }
}

void vertice_com_mais_vizinhos(No* g[MAX]){
    
    // Devemos guardar as informações: número MAX e número máximo de vizinhos
    int no_mais_viz = 0;
    int max_vizi = 0;
    int cont;

    // Criamos um laço que conta enquanto o próximo não for nulo
    for (int k = 0; k<MAX; k++) {
        
        No *temp = g[k];
        cont = 0;
        while(temp != NULL) {
            cont++;
            temp = temp->prox;
        }

        if (cont > max_vizi) {
            max_vizi = cont;
            no_mais_viz = k;
        }
    }
    printf("no: %d - viz: %d\n", no_mais_viz, max_vizi);
}

int main(){
    // cria grafo
    No* grafo[MAX] = {0};

    // cria arestas, a cada nova aresta no próximo o anterior é "empurrado"
    // [0] -> [1] -> N
    // [1] -> [3] -> [0] -> N
    // [2] -> [3] -> [2] -> [1] -> N
    // [3] -> [2] -> N
    //
    //
    criar_aresta(grafo, 0, 1); // Cria aresta do 0 para 1
    criar_aresta(grafo, 1, 0); // Cria aresta do 1 para 0
    criar_aresta(grafo, 1, 3); //
    criar_aresta(grafo, 2, 1);
    criar_aresta(grafo, 2, 2);
    criar_aresta(grafo, 2, 3);
    criar_aresta(grafo, 3, 2);
    
    printf("con 2->1: %d\n", existe_conexao(grafo, 2, 1));
    printf("con 2->0: %d\n", existe_conexao(grafo, 2, 0));
 
    imprime_vizinhos(grafo);

    vertice_com_mais_vizinhos(grafo);
}