#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#define MAX_NOMBRE_ARCHIVO 100

int generarAleatorio(int minimo, int maximo);
bool crearArchivo(char nombreArchivo[], int cantidad);
void procesarArchivo(char nombreArchivo[]);

int main(void){

    char nombreArchivo[] = "NombreArchivoEjemplo.dat";
    int cantidadGenerar = 1000;

    bool correcto = crearArchivo(nombreArchivo, cantidadGenerar);
    if (!correcto) {
        printf("Ocurrio un error al generar el archivo con numeros.");
        return 0;
    }
    procesarArchivo(nombreArchivo);
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
        printf("Error: No se pudo crear el archivo.\n");
        return false;
    }
    for (int i = 0; i < cantidad; i++) {
        int aleatorio = generarAleatorio(cantidadMinima, cantidadMaximo);
        fwrite(&aleatorio, sizeof(int), 1, archivo);
    }
    fclose(archivo);
    return true;
}
void procesarArchivo(char nombreArchivo[]) {
    int cantidad = 0;
    int suma = 0;
    int maximo = 0;
    int minimo = 0;
    int minimoPos = 0;
    int masRepetido = 0;
    int frecuenciaMax = 0;
    float promedio = 0.0;
    nombreArchivo = "NombreArchivoEjemplo.dat";
    FILE *archivo = fopen(nombreArchivo, "rb");
    if (archivo == NULL) {
    printf("Error: No se pudo abrir el archivo.\n");
    exit (1);
    }
    fseek(archivo, 0, SEEK_END);
    int tamanio = ftell(archivo);
    if (tamanio/sizeof(int) == 0) {
        printf("Error: el archivo no contiene ningun valor.\n");
        fclose(archivo);
        exit (1);
    }
    if (tamanio/sizeof(int) == 1) {
        printf("Error: el archivo contiene un solo valor.\n");
        fclose(archivo);
        exit (1);
    }
    fseek(archivo, 0, SEEK_SET);
    int primerNumero = 0;
    int seRepitenSiempre = 1;
    fread(&primerNumero, sizeof(int),1,archivo);
    int siguientePosicion = primerNumero;
    while (!feof(archivo)) {
        if (siguientePosicion != primerNumero) {
            seRepitenSiempre = 0;
        }
        siguientePosicion = fread(&primerNumero, sizeof(int),1,archivo);
    }
    if (seRepitenSiempre==1) {
        printf("Error: el archivo contiene un solo valor que se repite constantemente\n");
        fclose(archivo);
        exit (1);
    }

    fseek(archivo, 0, SEEK_SET);
  int numeroActual = 0;
  fread(&numeroActual, sizeof(int),1,archivo);
  maximo = numeroActual;
  minimo = numeroActual;
  minimoPos = cantidad;
    masRepetido = numeroActual;

  while (!feof(archivo)){
      if (numeroActual == 100) {
        printf("a\n");
      }
      cantidad+=1;
      suma+=numeroActual;
      if(numeroActual>maximo){
        maximo=numeroActual;
      }
      if(numeroActual<minimo){
        minimo=numeroActual;
        minimoPos=cantidad;
      }
      FILE *archRepetidos = fopen(nombreArchivo, "rb");
      if (archRepetidos == NULL) {
          printf("Error: No se pudo abrir el archivo.\n");
          exit (1);
      }
      int actualRepetido = 0;
      fread(&actualRepetido, sizeof(int),1,archRepetidos);
      int cantActualRepetido = 0;
      while (!feof(archRepetidos)){
          if(numeroActual==actualRepetido){
            cantActualRepetido+=1;
          }
          fread(&actualRepetido, sizeof(int),1,archRepetidos);
      }
      fclose(archRepetidos);
      if(cantActualRepetido>frecuenciaMax){
          masRepetido=actualRepetido;
          frecuenciaMax=cantActualRepetido;
      }
      fread(&numeroActual, sizeof(int),1,archivo);
  }
    fclose(archivo);
    promedio = (float)suma / cantidad;

    printf("Cantidad de numeros: %d\n", cantidad);
    printf("Suma de los numeros: %d\n", suma);
    printf("Promedio de los numeros: %.2f\n", promedio);
    printf("Valor maximo: %d\n", maximo);
    printf("Valor minimo: %d (posicion: %d)\n", minimo, minimoPos);
    printf("Numero mas repetido: %d (apariciones: %d)\n", masRepetido, frecuenciaMax);
}
