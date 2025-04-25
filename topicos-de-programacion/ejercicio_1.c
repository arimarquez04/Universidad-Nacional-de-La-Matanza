//Desarrollar una función para calcular el factorial de un entero

#include <stdio.h>
int calcularFactorial(int n);
int main(void) {
    printf("Hello, World!\n");

    printf("Ingrese un numero natural para calcular su factorial\n>>");
    int num = 0;
    scanf("%d", &num);
    int resultado = calcularFactorial(num);
    printf("El resultado es: %d", resultado);
    return 0;
}
int calcularFactorial(int n) {
    if (n == 0) {
        return 1;
    }
    int resultado = 1;
    for (int i = n; i>0; i--) {
        resultado *= i;
    }
    return resultado;
}