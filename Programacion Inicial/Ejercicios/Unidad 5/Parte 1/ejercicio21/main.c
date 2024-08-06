#include <stdio.h>

int main(void) {
    printf("Hello, World!\n");
    int cantidadDeFilas = 0;
    printf("Ingrese la cantidad de filas \n >>");
    scanf("%d", &cantidadDeFilas);
    int cantidadEspaciosEnBlanco = cantidadDeFilas-1;
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
    cantidadEspaciosEnBlanco+=2;
    cantidadAsteriscos = cantidadAsteriscos-4;
    for (int i = cantidadDeFilas-1; i>=1; i--) {
        for (int k = cantidadEspaciosEnBlanco; k>=1; k--) {
            printf(" ");
        }
        for (int h = cantidadAsteriscos; h>0; h--) {
            printf("*");
        }
        for (int k = cantidadEspaciosEnBlanco; k>=1; k--) {
            printf(" ");
        }
        cantidadEspaciosEnBlanco+=1;
        cantidadAsteriscos = cantidadAsteriscos-2;
        printf("\n");
    }

    return 0;

}