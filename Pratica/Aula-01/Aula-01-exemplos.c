/* ===============================================================================
 * Arquivo: Aula-01-exemplos.c
 * Autor: Aleksander Da Silva Toth
 * Disciplina: Algoritmos e Estruturas de Dados I
 * 
 * Data de criação: 13/08/2025
 * Data da última alteração: 20/08/2025	
 * - Adicionado comentários explicativos.
 * 
 * Descrição: 
 * Este programa demonstra e compara o tempo de execução de dois algoritmos:
 * - findMax: Uma busca linear de complexidade O(n).
 * - bubble_sort: Um algoritmo de ordenação de complexidade O(n^2).
 * O objetivo é ilustrar o impacto da complexidade do algoritmo na performance.
 * Ambos os algoritmos operam sobre um vetor de inteiros de tamanho definido por SIZE.
 * O vetor é preenchido com números aleatórios, e o tempo de execução é medido usando a função clock().
 * ===============================================================================
 
 * compile: gcc 
 * build: Ctrl + shift + B
 * run: ./Aula-01-exemplos
 */

#include <stdio.h>   // Biblioteca para funções de entrada e saída padrão
#include <stdlib.h>  // Biblioteca para funções gerais, incluindo alocação de memória e números aleatórios
#include <time.h>    // Biblioteca para funções relacionadas a tempo

#define SIZE 10000

// Em quantas vezes o tempo aumentará?
// Com a busca pelo maior elemento se duplicarmos o SIZE, o tempo de 
//processamento é aproximadamente proporcional a entrada, logo O(n)
// Com o bubble sort, se duplicarmos o SIZE, o tempo de processamento é 
//proporcional ao quadrado da entrada, logo O(n²)

// Função findMax: Busca o maior elemento em um vetor de inteiros e retorna o valor encontrado.
int findMax(int arr[]) {
    int maior = 0;
    for (int i = 0; i < SIZE; i++) {
        if (arr[i] > maior) {
            maior = arr[i];
        }
    }
    return maior;
} // Fim da função findMax

// Bubble sort é um algoritmo de ordenação simples que percorre repetidamente o 
//vetor, comparando elementos adjacentes e trocando-os se estiverem na ordem 
//errada. O processo é repetido até que o vetor esteja ordenado.

// Função bubble_sort: Ordena um vetor de inteiros usando o algoritmo bubble sort.
void bubble_sort(int arr[]) {
    int temp;
    // Loop externo que percorre o array.
    for (int i = 0; i < SIZE-1; i++) {
        // Loop interno que "borbulha" o maior elemento para o final.
        for (int j = 0; j < SIZE-1; j++) {
            // Se o elemento atual for maior que o próximo, troca-os de lugar.
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}// Fim da função bubble_sort

// Função main
int main() {

    // Declaração do vetor de inteiros com tamanho SIZE
    int arr[SIZE];      

    // Inicializa o gerador de números aleatórios com o tempo atual 
    srand(time(NULL));  

    // Loop para preencher o vetor com números aleatórios
    for (int i = 0; i < SIZE; i++)
    arr[i] = rand() % SIZE*10;

    printf("Iniciando cronometragem...\n");

    // Captura o "tick" de clock inicial, antes da execução do algoritmo.
    clock_t start = clock();

    // Descomente a linha da função que você quer medir o tempo.    

    //int maxElement = findMax(arr);
    bubble_sort(arr);
    
    // Captura o "tick" de clock final, após a execução.
    clock_t end = clock();


    // (double) é usado para garantir que a divisão seja de ponto flutuante.
    // double tempo_execucao = ((double)(end - start)) / CLOCKS_PER_SEC;
    // printf("Tempo de execucao: %lf segundos\n", tempo_execucao);
    
    //printf("Maior elemento: %d, Tempo: %lf segundos\n", maxElement, ((double)(end - start)) / CLOCKS_PER_SEC);
    printf("Tempo: %lf segundos\n", ((double)(end - start)) / CLOCKS_PER_SEC);
    
}// Fim da função main

