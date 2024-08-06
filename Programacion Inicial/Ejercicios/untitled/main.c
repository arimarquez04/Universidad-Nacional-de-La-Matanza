#include <stdio.h>

int main(void) {
    printf("Hello, World!\n");
/*
 *  b) Una agencia de viajes organiza tours a diferentes destinos internacionales,
 *  identificados por un código de país: (1-Europa, 2-Asia y 3-América).
 *  Antes de cargar los pedidos se debe ingresar la capacidad disponible para cada tour.
 *  Se sabe que los precios de cada tour son: 1-Europa = 1500.00; 2-Asia= 2500.00  y 3-América= 1000.00).
 *  La agencia necesita un programa para registrar sus actividades y generar informes.
 *  Para ello, cuenta con la siguiente información que se ingresa por teclado:
 *  Código de tour (entero de 3 dígitos) Destino (entero (1 a 3) Cantidad de pasajeros (entero mayor a 0 y menor a 50)
 *  Todos los datos deben ser validados.   Si la cantidad pedida es mayor o igual a la cantidad ingresada, para ese tour,
 *  se debe descontar ese valor. En caso en que la capacidad no alcance, se usará la necesaria y se enviará un mensaje
 *  por pantalla con la cantidad de pasajes no usados.   La carga de los datos finaliza con un código de tour igual a 0.
 *  Se requiere, al finalizar, informar: a) El Código de destino con mayor cantidad de tours vendidos.
 *  b) El promedio del precio por pasajero en los distintos tours.
 *  c) Generar el siguiente informe:
 * Informe de Tours Vendidos Destino Cantidad   Importe
 * xxxxxx   xxxxx    xxxxx.xx   xxxxxx   xxxxx    xxxxx.xx
 */
    //variables utiles
    int precioTourEuropa=1500;
    int precioTourAsia=2500;
    int precioTourAmerica=1000;
    int minimoCantidadDePasajeros =0;
    int maximoCapacidadDePasajeros =50;
    int codigoMaximo = 999;
    int codigoMinimo=1;
    int capacidadTourEuropa =0;
    int capacidadTourAsia=0;
    int capacidadTourAmerica=0;
    int cantidadVendidaEuropa =0;
    int cantidadVendidaAsia =0;
    int cantidadVendidaAmerica=0;
    int datoValido =0;
    //1ra forma de validar un dato
    do {
        printf("Ingrese la capaidad disponible para el tour de America \n >>");
        scanf("%d", &capacidadTourAmerica);
        if (capacidadTourAmerica<0) {
            printf("Error, ingrese una cantidad valida...\n");
            datoValido =0;
        }else {
            datoValido=1;
        }
    }while (datoValido!=1);
    do {
        datoValido =0;
        printf("Ingrese la capaidad disponible para el tour de Asia \n >>");
        scanf("%d", &capacidadTourAsia);
        if (capacidadTourAsia<0) {
            printf("Error, ingrese una cantidad valida...\n");
            datoValido =0;
        }else {
            datoValido=1;
        }
    }while (datoValido!=1);
    do {
         datoValido =0;
        printf("Ingrese la capaidad disponible para el tour de Europa \n >>");
        scanf("%d", &capacidadTourEuropa);
        if (capacidadTourEuropa<0) {
            printf("Error, ingrese una cantidad valida...\n");
            datoValido =0;
        }else {
            datoValido=1;
        }
    }while (datoValido!=1);

    int codigoTour = 0;
    do {
        printf("Ingrese un codigo de tour entre 1 y 999, ingrese 0 para salir\n >>");
        scanf("%d", &codigoTour);
        if (codigoTour<codigoMinimo || codigoTour>codigoMaximo) {
            printf("Error, ingrese un valor valido... \n");
        }else {
            int destino= 0;
            do {
                printf("Ingrese un destino 1-Europa, 2-Asia y 3-América \n >>");
                scanf("%d", &destino);
                if (destino<1 || destino>3) {
                    if (destino==1) {
                    }
                }else {
                    printf("Error, ingrese un destino valido \n");
                }
            }while (destino<1 && destino >3);
            int cantidadDePasajes = 0;
            do {
                printf("Ingrese la cantidad de pasajes\n>>");
                scanf("%d", &cantidadDePasajes);
                if(cantidadDePasajes<0) {
                    printf("Error, ingrese un destino valido \n");
                }
            }while (cantidadDePasajes<0);
                switch (destino){
                    case 1:
                        if (cantidadDePasajes<=capacidadTourEuropa) {
                            cantidadVendidaEuropa += cantidadDePasajes;
                            capacidadTourEuropa-=cantidadDePasajes;
                            printf("vendido \n");
                        }
                        if (cantidadDePasajes>capacidadTourEuropa) {
                            int capacidadParaVender = capacidadTourEuropa-cantidadDePasajes;
                            cantidadVendidaEuropa *= capacidadParaVender;
                            capacidadTourEuropa -=capacidadParaVender;
                            printf("La cantidad eligida excede el mamximo de capacidad, se vendio %d pasajes", capacidadParaVender);
                        }
                        break;
                    case 2:
                        if (cantidadDePasajes<=capacidadTourAsia) {
                            cantidadVendidaAsia += cantidadDePasajes;
                            capacidadTourAsia-=cantidadDePasajes;
                            printf("vendido \n");

                        }
                        if (cantidadDePasajes>capacidadTourAsia) {
                            int capacidadParaVender = capacidadTourAsia-cantidadDePasajes;
                            cantidadVendidaAsia *= capacidadParaVender;
                            capacidadTourAsia -=capacidadParaVender;
                            printf("La cantidad eligida excede el mamximo de capacidad, se vendio %d pasajes", capacidadParaVender);

                        }
                    break;
                    case 3:
                        if (cantidadDePasajes<=capacidadTourAmerica) {
                            cantidadVendidaAmerica += cantidadDePasajes;
                            capacidadTourAmerica-=cantidadDePasajes;
                            printf("vendido \n");

                        }
                        if (cantidadDePasajes>capacidadTourAmerica) {
                            int capacidadParaVender = capacidadTourAmerica-cantidadDePasajes;
                            cantidadVendidaAmerica *= capacidadParaVender;
                            capacidadTourAmerica -=capacidadParaVender;
                            printf("La cantidad eligida excede el mamximo de capacidad, se vendio %d pasajes", capacidadParaVender);
                        }
                    break;
            }
        }
    }while (codigoTour!=0 || (codigoTour>=codigoMinimo && codigoTour<=codigoMaximo));

    /*a) El Código de destino con mayor cantidad de tours vendidos.
     *  b) El promedio del precio por pasajero en los distintos tours.
     *  c) Generar el siguiente informe:
     * Informe de Tours Vendidos Destino Cantidad   Importe
     * xxxxxx   xxxxx    xxxxx.xx   xxxxxx   xxxxx    xxxxx.xx
     */
    if(cantidadVendidaEuropa== cantidadVendidaAmerica && cantidadVendidaEuropa==cantidadVendidaAsia) {
        printf("Los tres destnos vendieron la misma cantidad \n");
    }
    if (cantidadVendidaEuropa>cantidadVendidaAmerica && cantidadVendidaEuropa>cantidadVendidaAsia) {
        printf("Europa fue el destino mas vendido. Cantidad: %d \n", cantidadVendidaEuropa);
    }
    if (cantidadVendidaAmerica>cantidadVendidaEuropa && cantidadVendidaAmerica>cantidadVendidaAsia) {
        printf("America fue el destino mas vendido. Cantidad: %d \n", cantidadVendidaAmerica);
    }
    if (cantidadVendidaAsia>cantidadVendidaEuropa && cantidadVendidaAsia>cantidadVendidaAmerica) {
        printf("America fue el destino mas vendido. Cantidad: %d \n", cantidadVendidaAmerica);
    }
    
    printf("%d \n",capacidadTourAmerica);
    printf("%d \n",capacidadTourAsia);
    printf("%d \n",capacidadTourEuropa);
    return 0;
}
