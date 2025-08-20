/* ===============================================================================
 * Arquivo: Aula-03-arrays.c
 * Autor: Aleksander Da Silva Toth
 * Disciplina: Algoritmos e Estruturas de Dados I
 * 
 * Data de criação: 20/08/2025
 * Data da última alteração: 20/08/2025	
 * 
 * 
 * Descrição: 
 * Este programa demonstra o uso de arrays em C.
 * Assim como a leitura de dados de um arquivo texto e o armazenamento desses dados em um array de structs.
 * ===============================================================================
 
 * compile: gcc 
 * build: Ctrl + shift + B
 * run: ./Aula-03-arrays.c
 */

 /* Exemplo de acesso a um array em tempo constante O(1) 
#include <stdio.h>

int main() {
 int arr[5] = {10, 20, 30, 40, 50}; // Array de tamanho fixo
 // Acesso direto ao terceiro elemento
 printf("Elemento na posição 2: %d\n", arr[2]); // O(1)
 return 0;
 
}
*/
//https://codefile.io/f/hQrbgIR5sv
#include <stdio.h>
#include <string.h>

// Define a struct aluno, onde aluno_s é o nome "real" da struct, sendo aluno o apelido
/*
struct aluno_s{
    char nome[25];
    int idade;
} ;
typedef struct aluno_s aluno; // Apelido para struct aluno_s
*/
// Outra forma de definir struct e apelido. Desta maneira, não é necessário colocar o nome "real" da struct, além de que será mais intuitivo usar ponteiros para struct aluno
typedef struct aluno{
    char nome[25];
    int idade;
}aluno;

// Função conta_menores, que percorre array e conta menores de idade. Essa função tem complexidade O(n), onde n é a quantidade de elementos no array
// Ela recebe a strct aluno por completo, ou seja, o array a[], e a quantidade de elementos no array, qtd
int conta_menores(aluno a[], int qtd){
    int menores = 0;
    for(int i = 0; i < qtd; i++){
        if(a[i].idade < 18){
            menores++;
        }
    }
    return menores;
} // Fim da função conta_menores

// Função principal
int main()
{
    // Variáveis para armazenar dados lidos do arquivo
    char nome[50];
    int idade;

    // Cria um array com 10 alunos
    aluno a[10];

    // Abre o arquivo para leitura (lembre de criar o arquivo alunos.txt)
    FILE *input = fopen("../alunos.txt", "r"); // Caminho relativo, necessário acrescentar ../ para voltar uma pasta, pois é criado uma pasta output, com o executável
    if (input == NULL){
        printf("erro abrindo arquivo\n");
        return 0;
    }

    // Lê e imprime cada linha do arquivo
    int i = 0;

    // A função fscanf retorna o número de itens lidos com sucesso ou EOF se o final do arquivo for alcançado
    while (fscanf(input, "%s %i", nome, &idade) != EOF){
        printf("Nome: %s, Idade: %d\n", nome, idade);
        
        a[i].idade = idade;
        strcpy(a[i].nome, nome); // Cópia de string em C com a função strcpy, função essa que copia o conteúdo da string de origem (nome) para a string de destino (a[i].nome)
        i++;
    }
    
    // Menores de idade, conforme a função conta_menores, ela recebe o array a por completo e a quantidade de elementos lidos conforme i.
    int n_menores = conta_menores(a, i);
    printf("numero de menores: %d\n", n_menores);
    fclose(input);
    return 0;
}