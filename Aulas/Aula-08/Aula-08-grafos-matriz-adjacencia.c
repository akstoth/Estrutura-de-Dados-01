/**
 * @file Aula-08-grafos-matriz-adjacencia.c
 * @author Aleksander Da Silva Toth
 * @brief Exercícios de filas - continuação
 * @version 1.0.0
 * @date 2025-09-19
 *
 * @copyright Copyright (c) 2025
 *
 * =============================================================================
 * @details
 * Implementação simples de grafos utilizando matriz de adjacência
 * =============================================================================
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX 4 // Quantidade máxima de vértices/arestas

void inicializarMatriz(int matriz[MAX][MAX], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            matriz[i][j] = -1;    
            
        }     
}

void adicionarAresta(int matriz[MAX][MAX], int u, int v){
    matriz[u][v] = 1;
    matriz[v][u] = 1; // Para grafos não direcionados
}

void imprimirMatriz(int matriz[MAX][MAX], int n) {
    printf("Matriz de Adjacencia:\n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            printf("%d ", matriz[i][j]);
        printf("\n");
    }
}

int adiciona_peso(int matriz[MAX][MAX], int de, int para, int peso) {
    matriz[de][para] = peso; 
    return 1; // Sucesso
}

int imprime_grau(int matriz[MAX][MAX]) {
    int grau = 0;
    printf("Imprimindo o Grau dos vertices:\n");
    for (int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            if (matriz[i][j] > 0) grau++;
        }
        printf("No: %d, grau: %d\n", i, grau);
        grau = 0;
    }
    return 1; // Sucesso
}

int imprime_vizinhos(int matriz[MAX][MAX], int vertice) {
    printf("\nVizinhos do no: %d\n", vertice);
    for (int i = 0; i < MAX; i++) {
        if (matriz[vertice][i] > 0) {
            printf(" %d ", i);
        }
    }
}

int main() {
    int grafo[MAX][MAX] = {{0, 0, 0, 0,},
                           {0, 0, 0, 0},
                           {0, 0, 0, 0},
                           {0, 0, 0, 0}};
    inicializarMatriz(grafo, MAX);

    adiciona_peso(grafo, 0, 0, 1);
    adiciona_peso(grafo, 0, 1, 2);
    adiciona_peso(grafo, 0, 3, 8);

    adiciona_peso(grafo, 1, 0, 3);
    adiciona_peso(grafo, 1, 2, 1);

    adiciona_peso(grafo, 2, 0, 5);
    adiciona_peso(grafo, 2, 1, 4);
    adiciona_peso(grafo, 2, 2, 6);
    adiciona_peso(grafo, 2, 3, 2);

    adiciona_peso(grafo, 3, 3, 7);


    imprimirMatriz(grafo, MAX);

    imprime_grau(grafo);

    imprime_vizinhos(grafo, 1);
    imprime_vizinhos(grafo, 2);

    return 0;
}

