/*
Crie uma struct chamada Retangulo com os campos:
● float largura
● float altura

Implemente as seguintes funções:
● float calcularArea(Retangulo *r): retorna a área do retângulo.
● float calcularPerimetro(Retangulo *r): retorna o perímetro.
No main(), leia os valores do usuário, chame as funções e exiba os resultados

*/

#include <stdio.h>
#include <string.h>


typedef struct  {
    float largura;
    float altura;
} Retangulo;

float calcularArea(Retangulo *p) {
    //return (*p).altura * (*p).largura;
    return p->altura * p->largura;
}

float calcularPerimetro(Retangulo *p) {
    return (2 * p->altura) + (2 * p->largura);
}

int main() {
    Retangulo r;
    printf("Digite a altura e a largura: ");
    //scanf("%f %f", r.altura, r.largura);
    scanf("%f %f", &r.altura, &r.largura);
    printf( "Largura: %.2f, Altura: %.2f\n" , r.largura, r.altura);
    float area = calcularArea(&r);
    float perimetro = calcularPerimetro(&r);

    printf("\n Area do retangulo: %.2f, perimetro: %.2f", area, perimetro);

 return 0;
}