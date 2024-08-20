#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
1.7 Dado un vector de 10 enteros, ingresar un entero por teclado, buscarlo y, si se lo encuentra, generar un nuevo
vector con los índices correspondientes a las ubicaciones en el primer vector del entero ingresado.
*/
void cargaAleatoria(int elementos[], int cantidadElementos, int maximoDigitos);
int main(void) {
    printf("Hello, World!\n");
    int cantidadElementos = 10;
    int maximo = 5;
    int elementos[cantidadElementos];
    srand((time(NULL)));
    cargaAleatoria(elementos, cantidadElementos, maximo);
    int numeroBuscar = 0;
    printf("\nIngrese el numero a buscar:");
    scanf("%d", &numeroBuscar);
    int cantidadApariciones = 0;
    int indices[cantidadElementos];
    for (int i =0; i<cantidadElementos;i++) {
        if (elementos[i]==numeroBuscar) {
            indices[cantidadApariciones] = i;
            cantidadApariciones++;
        }
    }
    if(cantidadApariciones==0) {
        printf("El numero %d no se encontro", numeroBuscar);
    }
    if(cantidadApariciones>0) {
        printf("El numero %d se encuentra en las posiciones:", numeroBuscar);
        for (int i=0; i<cantidadApariciones;i++) {
            printf("\n\t- %d",indices[i]);
        }
    }

    return 0;
}
void cargaAleatoria(int elementos[], int cantidadElementos, int maximoDigitos) {
    elementos[cantidadElementos];
    for(int i = 0; i<cantidadElementos; i++) {
        elementos[i]=rand()%maximoDigitos;
        printf("\nEl numero en el indice %d es %d", i, elementos[i]);
    }
}
