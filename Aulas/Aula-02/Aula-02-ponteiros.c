#include <stdio.h>
#include <string.h>


int main() {
 int a = 10;
 int *ptr = &a; // Ponteiro apontando para 'a'

 printf( "Valor de a: %d\n" , a);
 printf( "Endereço de a: %p\n" , &a);
 printf( "Valor apontado por ptr: %d\n" , *ptr);

 return 0;
}
