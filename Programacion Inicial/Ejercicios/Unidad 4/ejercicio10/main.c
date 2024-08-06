#include <stdio.h>

int main(void) {
    printf("Hello, World!\n");
    printf("Ingrese una opcion de conversion \n 1) Sexagecimal a Radianes \n 2) Radianes a Sexageximal \n");
    int opcion = 0;
    float valor = 0;
    float resultado = 0;
    scanf("%d", &opcion);
    if (opcion == 1) {
        printf("Ingrese el valor en Sexagecimal \n");
        scanf("%f", &valor);
        resultado = valor * 3.14159 / 180;
        printf("%f grados Sexagecimales corresponden aproximadamente a %f Radianes", valor, resultado);
    }
    if (opcion == 2) {
        printf("Ingrese el valor en Radianes \n");
        scanf("%f", &valor);
        resultado = valor * 180 /  3.14159;
        printf("%f grados Radianes corresponden aproximadamente a %f Sexageximales", valor, resultado);
    }
    return 0;
}
