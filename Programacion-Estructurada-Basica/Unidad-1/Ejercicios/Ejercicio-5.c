#include <stdio.h>
/*
1.5 Se ingresan los códigos de 15 productos de una empresa (números de 3 dígitos). Luego del ingreso se debe
ordenar de forma ascendente la colección con dichos códigos para permitir realizar búsquedas binarias.
Luego se ingresan las ventas realizadas durante el día. Por cada venta se ingresa código de vendedor, código
de artículo y cantidad.
Los vendedores son 5 y están codificados en forma correlativa de 1001 a 1005. Se puede recibir más de una
venta de un mismo vendedor y artículo. El ingreso de datos finaliza con código de vendedor igual a 0. Se desea:
a. Mostrar un listado ordenado de mayor a menor por cantidad de unidades vendidas de cada producto.
CANT UNIDADES CÓDIGO
    XXX         XXX
    XXX         XXX

b. Indicar el/los vendedores que realizaron menor cantidad de ventas (no de unidades)
 */
int ingresarCodigosProductos(int codigosProductos[], int codigoMaximo, int codigoMinimo, int cantidadCodigos);
int verificarSiSeRepite(int codigosProductos[], int datoBuscar, int cantidadElementos);
int validarCodigoProducto(int codigoIngresado, int codigoMinimo, int codigoMaximo);
void ordenarArrayPorBurbujeo(int array[], int cantElementos);
int busquedaBinaria(int vector[], int numeroBuscar, int cantElementos);

int main(void) {
    printf("Hello, World!\n");
    int codigoMinimo = 100;
    int codigoMaximo = 999;
    int cantidadCodigos = 15;
    int codigosProductos[cantidadCodigos];
    ingresarCodigosProductos(codigosProductos, codigoMaximo, codigoMinimo, cantidadCodigos);
    printf("\nsin ordenar:");
    for (int i = 0; i<cantidadCodigos;i++) {
        printf("%d - ", codigosProductos[i]);
    }
    ordenarArrayPorBurbujeo(codigosProductos, cantidadCodigos);
    printf("\nordenado:");
    for (int i = 0; i<cantidadCodigos;i++) {
        printf("%d - ", codigosProductos[i]);
    }

    return 0;
}
int ingresarCodigosProductos(int codigosProductos[], int codigoMaximo, int codigoMinimo, int cantidadCodigos) {
    printf("\nComienza la carga de 15 elementos.");
    int codigosCargados = 0;
     do{
        printf("\nIngrese el codigo del producto N°%d. Maximo: %d. Minimo: %d \n>>", codigosCargados, codigoMaximo, codigoMinimo);
        int codigoIngresado = 0;
        scanf("%d", &codigoIngresado);
        if (validarCodigoProducto(codigoIngresado, codigoMinimo, codigoMaximo)!=1) {
            printf("\nError, ingrese un codigo valido.");
        }else {
            if (verificarSiSeRepite(codigosProductos, codigoIngresado, cantidadCodigos)!=1) {
                printf("Error, no se puede ingresar un codigo repetido.");
            }else {
                codigosProductos[codigosCargados] = codigoIngresado;
                codigosCargados++;
            }
        }
    }while (codigosCargados<cantidadCodigos);
    return codigosCargados;
}

int verificarSiSeRepite(int codigosProductos[], int datoBuscar, int cantidadElementos) {
    for(int i = 0; i<cantidadElementos; i++) {
        if(codigosProductos[i] == datoBuscar) {
            return -1;
        }
    }
    return 1;
}
int validarCodigoProducto(int codigoIngresado, int codigoMinimo, int codigoMaximo) {
    if (codigoIngresado<codigoMinimo) {
        return -1;
    }
    if (codigoIngresado>codigoMaximo) {
        return -1;
    }
    return 1;
}

void ordenarArrayPorBurbujeo(int array[], int cantElementos) {
    for (int i = 0; i<cantElementos-1; i++) {
        for(int j=0; j<cantElementos-i; j++) {
            if(array[j]>=array[j+1]) {
                int auxiliar = array[j];
                array[j] = array[j+1];
                array[j+1] = auxiliar;
            }
        }
    }
}
int busquedaBinaria(int vector[], int numeroBuscar, int cantElementos) {
    int posicion = -1;
    int li = 0;
    int ls = cantElementos-1;
    int med;
    while (posicion==-1 && li<=ls) {
        med = (li+ls)/2;
        if(vector[med]==numeroBuscar) {
            posicion=med;
        }
        if(vector[med]!=numeroBuscar) {
            if (numeroBuscar>vector[med]) {
                li = med+1;
            }else {
                ls = med-1;
            }
        }
    }
    return posicion;
}