#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#define MAX_NOMBRE_ARCHIVO 100
int generarAleatorio(int minimo, int maximo);
bool crearArchivo(char nombreArchivo[], int cantidad);
int main(void){

    char nombreArchivo[] = "NombreArchivoEjemplo.dat";
    int cantidadGenerar = 1000;

    bool correcto = crearArchivo(nombreArchivo, cantidadGenerar);
    if (!correcto) {
      printf("Ocurrio un error al generar el archivo con numeros.");
    }

    return 0;
}

int generarAleatorio(int minimo, int maximo) {
    int rango = maximo - minimo + 1;
    return minimo + rand() % rango;
}
bool crearArchivo(char nombreArchivo[], int cantidad) {
    srand(time(NULL));
    int cantidadMinima = 567;
    int cantidadMaximo = 1234;

    if(cantidad <0) {
        printf("Error: la cantidad a generar debe ser mayor o igual a 0.");
        return 0;
    }
    if (strlen(nombreArchivo) > MAX_NOMBRE_ARCHIVO) {
        printf("El nombre del archivo no puede tener mas de %d caracteres." , MAX_NOMBRE_ARCHIVO);
        return false;
    }
    if(cantidadMinima> cantidad || cantidadMaximo< cantidad) {
        printf("Error: la cantidad a generar debe estar entre  %d y %d.", cantidadMinima, cantidadMaximo);
        return false;
    }

    FILE *archivo = fopen(nombreArchivo, "wb");
    if (archivo == NULL) {
      printf("Error: No se pudo abrir el archivo.\n");
      return false;
    }
    for (int i = 0; i < cantidad; i++) {
        int aleatorio = generarAleatorio(cantidadMinima, cantidadMaximo);
        printf("%d\n", aleatorio);
        fwrite(&aleatorio, sizeof(int), 1, archivo);
    }
    fclose(archivo);
    return true;
}
