#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generarAleatorio(int minimo, int maximo);

int main(void) {
    int minimo = 0;
    int maximo = 10;

    if (minimo > maximo) {
        printf("Error: el minimo es mayor que el maximo.");
        return 0;
    }

    srand(time(NULL));


    int aleatorio = generarAleatorio(minimo, maximo);

    printf("Numero aleatorio entre %d y %d: %d\n", minimo, maximo, aleatorio);

    return 0;
}

int generarAleatorio(int minimo, int maximo) {
    int rango = maximo - minimo + 1;
    return minimo + rand() % rango;
}
