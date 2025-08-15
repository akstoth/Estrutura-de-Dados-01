/* 
Busca do maior elemento.
Algoritmo bubble sort.
Busca um elemento em árvore binária de busca.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10000

// Em quantas vezes o tempo aumentará?
// Com a busca pelo maior elemento se duplicarmos o SIZE, o tempo de processamento é aproximadamente proporcional a entrada, logo O(n)
// Com o bubble sort, se duplicarmos o SIZE, o tempo de processamento é proporcional ao quadrado da entrada, logo O(n²)

int findMax(int arr[]) {
    int maior = 0;
    for (int i = 0; i < SIZE; i++) {
        if (arr[i] > maior) {
            maior = arr[i];
        }
    }
    return maior;
}

void bubble_sort(int arr[]) {
    int temp;
    for (int i = 0; i < SIZE-1; i++) {
        for (int j = 0; j < SIZE-1; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {

    int arr[SIZE];
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++)
    arr[i] = rand() % SIZE*10;

    // Medindo tempo da busca do maior elemento
    clock_t start = clock();

    //int maxElement = findMax(arr);
    bubble_sort(arr);
    
    clock_t end = clock();

    //printf("Maior elemento: %d, Tempo: %lf segundos\n", maxElement, ((double)(end - start)) / CLOCKS_PER_SEC);
    printf("Tempo: %lf segundos\n", ((double)(end - start)) / CLOCKS_PER_SEC);
    
}

