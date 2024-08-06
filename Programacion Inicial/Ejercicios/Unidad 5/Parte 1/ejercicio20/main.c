#include <stdio.h>

int main(void) {
    printf("Hello, World!\n");
    int cantidadDeFilas = 0;
    printf("Ingrese la cantidad de filas \n >>");
    scanf("%d", &cantidadDeFilas);
    int cantidadEspaciosEnBlanco = cantidadDeFilas;
    int cantidadAsteriscos = 1;
    for (int i = 1; i<=cantidadDeFilas; i++) {
            for (int k = 1; k<=cantidadEspaciosEnBlanco; k++) {
                printf(" ");
            }
            for (int h = 1; h<=cantidadAsteriscos; h++) {
            printf("*");
            }
            for (int k = 1; k<=cantidadEspaciosEnBlanco; k++) {
                printf(" ");
            }
        cantidadEspaciosEnBlanco-=1;
        cantidadAsteriscos = cantidadAsteriscos+2;
        printf("\n");
    }
    return 0;
}
/*
    i
   iii
  iiiii
 iiiiiii
iiiiiiiii
*/