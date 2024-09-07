#include <stdio.h>
/*1.2 Una empresa debe registrar los pedidos recibidos de cada uno sus 10 productos a lo largo del día. Cada
producto está identificado por un código de 4 cifras. Los códigos deben ingresarse al inicio del programa
mediante la función IngresaCódigos y no pueden repetirse.
Por cada pedido se recibe:
• Código de producto
• Cantidad de unidades solicitadas
Se puede recibir más de un pedido por producto.
La carga de pedidos finaliza cuando se ingresa un producto igual a 0
Al finalizar se debe:
a) Emitir un listado con código y cantidad de unidades solicitadas de cada producto.
b) El / los productos del cual se solicitaron mayor cantidad de unidades.
c) El / los productos del cual se solicitaron menos cantidad de unidades.
*/
int busquedBinaria(int vector[], int numeroBuscar, int cantElementos);
void ordenarArrayPorBurbujeo(int array[], int cantElementos);
int main(void) {
    printf("Hello, World!\n");
    return 0;
}
void ordenarArrayPorBurbujeo(int array[], int cantElementos) {
    for (int i = 0; i<cantElementos-1; i++) {
        for(int j=0; j<cantElementos-i; j++) {
            if(array[j]>=array[+1]) {
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
