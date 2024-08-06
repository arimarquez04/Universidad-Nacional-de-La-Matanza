#include <stdio.h>

int main(void) {
    printf("Hello, World!\n");
    int cantidadDeNumeros = 0;
    printf("Ingrese la cantidad de numeros a sumar \n >>");
    scanf("%d", &cantidadDeNumeros);
    int total = 0;
    for (int i = 0; i<=cantidadDeNumeros; i++ ) {
        total += i;
        printf( "%d ", total);
    }
    printf("La suma de los primeros %d numero naturales es %d" , cantidadDeNumeros, total);

    return 0;
}
