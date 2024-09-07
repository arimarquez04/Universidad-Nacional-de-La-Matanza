#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
 *Guía Práctica – V2.0 2 / 2
1.1 Cargar de forma aleatoria un vector de 20 elementos con números de 3 cifras.
a. Mostrar el menor valor e indicar cuantas veces se repite
b. Mostrar el mayor valor e indicar en que posición/posiciones se encuentra
*/
void cargaAleatoria(int elementos[], int cantidadElementos, int maximoDigitos);
void mostrarMayorYMenor(int elementos[], int cantidadElementos);
int main(void) {
    printf("Hello, World!\n");
    int cantidadElementos = 20;
    int maximo = 300;
    int elementos[cantidadElementos];
    srand((time(NULL)));
    cargaAleatoria(elementos, cantidadElementos, maximo);
    mostrarMayorYMenor(elementos, cantidadElementos);

    return 0;
}
void cargaAleatoria(int elementos[], int cantidadElementos, int maximoDigitos) {
    for(int i = 0; i<cantidadElementos; i++) {
        elementos[i]=rand()%maximoDigitos;
        printf("\nEl numero %d es %d", i, elementos[i]);
    }
}
void mostrarMayorYMenor(int elementos[], int cantidadElementos) {
    int menor = elementos[0];
    int mayor = menor;
    int cantRepetidosMenor = 0;
    int posicionesMaximo[cantidadElementos];
    int cantidadRepetidoMaximos = 0;
    for (int i=0; i<cantidadElementos; i++) {
        if (elementos[i]<menor) {
            menor=elementos[i];
        }
        if(elementos[i]==menor) {
            cantRepetidosMenor++;
        }
        if (elementos[i]>mayor) {
            mayor=elementos[i];
        }
    }
    for (int i=0; i<cantidadElementos; i++) {
        if (elementos[i]==mayor) {
            cantidadRepetidoMaximos++;
            posicionesMaximo[i] = i;
        }
    }
    printf("\nEl numero %d es el mayor y se encuentra en la posiciones:", mayor);
    for (int i= 0; i<cantidadRepetidoMaximos; i++) {
        printf("\n\t -%d", posicionesMaximo[i]);
    }
    printf("\nEl numero %d es el menor y se repite %d veces", menor, cantRepetidosMenor);
}

