/* Ejercicio 9: Suma de elementos de un vector
Desarrollar un programa en C que gestione la información de productos utilizando vectores paralelos.
El programa debe pedir la fecha para mostrar en el informa permitir cargar de forma segura hasta un máximo de 10 productos.
La carga finaliza con un codigoigual a 99
Se pide ingresar para cada producto su código (entero.  100 al 999), Tipo (entero 1, 2 y 3)  y el precio (float mayor a 0).
La carga de los vectores se realiza en una función.
Al final del programa se pide el siguiente informe:
    a)Informe del dia dd/mm/aaaa.
        Total Productos: XX
        Total Productos Tipo 1: XX
        Total Productos Tipo 2: XX
        Total Productos Tipo 3: XX
    b) Promedio de los precios del tipo 1.
    c) El mayor precio y a que codigopertenece del tipo 2.
    d) El menor precio y a que codigopertenece del tipo 3.*/
#include <stdio.h>
int esFechaValida(int dia, int mes, int año);
int cantidadDiasDelMes(int mes, int año);
int diasBisiesto(int año);
int pedirDatosDeProducto( int codigosProductos[10], int tipoProductos[10], float precioProductos[10]);
int pedirNumeroInt(char mensaje[],int minimaOpcion, int maximaOpcion);
float pedirNumeroFloat(char mensaje[],float minimaOpcion);
int pedirCodigoDeProducto(char mensaje[], int minimaOpcion, int maximaOpcion);
int main(void) {
    int codigosProductos[10];
    int tiposProductos[10];
    float preciosProductos[10];
    int totalProductos = 0;
    int totalProductosTipoUno = 0;
    int totalProductosTipoDos = 0;
    int totalProductosTipoTres = 0;
    int tipoProductoMayorPrecio =0;
    int codigoProductoMayorPrecio = 0;
    float precioProductoMayorPrecio = 0;
    int tipoProductoMenorPrecio =0;
    int codigoProductoMenorPrecio = 0;
    float precioProductoMenorPrecio = 1000000000000;
    float sumaDePreciosProductosTipoUno = 0;
    int fechaValida = 0;
    int año = 0;
    int dia = 0;
    int mes = 0;
    do {
        año = 0;
        dia = 0;
        mes = 0;
        printf("\nIngrese año \n >>");
        scanf("%d", &año);
        printf("Ingrese mes \n >>");
        scanf("%d", &mes);
        printf("Ingrese dia \n >>");
        scanf("%d", &dia);
        if (esFechaValida(dia, mes, año)==1) {
            printf("La fecha %d/%d/%d es valida.", dia, mes, año);
            fechaValida=1;
        }else {
            printf("La fecha %d/%d/%d no es valida.", dia, mes, año);
            fechaValida=0;
        }
    }while(fechaValida!=1);
    totalProductos = pedirDatosDeProducto(codigosProductos, tiposProductos, preciosProductos);
    for (int i = 0; i<totalProductos;i++){
        //Buscar el producto de mayor precio
        if (preciosProductos[i]>precioProductoMayorPrecio) {
            precioProductoMayorPrecio = preciosProductos[i];
            tipoProductoMayorPrecio = tiposProductos[i];
            codigoProductoMayorPrecio = codigosProductos[i];
        }
        //Buscar el producto de menor precio
        if (preciosProductos[i]<precioProductoMenorPrecio) {
            precioProductoMenorPrecio = preciosProductos[i];
            tipoProductoMenorPrecio = tiposProductos[i];
            codigoProductoMenorPrecio = codigosProductos[i];
        }
        //Verificar los tipos de productos y sumar los precios del tipo 1
        if (tiposProductos[i]==1) {
            totalProductosTipoUno++;
            sumaDePreciosProductosTipoUno += preciosProductos[i];
        }
        if (tiposProductos[i]==2) {
            totalProductosTipoDos++;
        }
        if (tiposProductos[i]==3) {
            totalProductosTipoTres++;
        }
    }
    //Comenzar informe
    printf("\n\nInforme del dia %d/%d/%d.", dia, mes, año);
    printf("\n\tTotal Productos: %d", totalProductos);
    printf("\n\tTotal Productos Tipo 1: %d", totalProductosTipoUno);
    printf("\n\tTotal Productos Tipo 2: %d", totalProductosTipoDos);
    printf("\n\tTotal Productos Tipo 3: %d", totalProductosTipoTres);
    printf("\n\tPromedio de los precios del tipo 1: $%.2f", (float)sumaDePreciosProductosTipoUno / (float)totalProductosTipoUno);
    printf("\n\tDatos del producto con mayor precio: \n\t\tCodigo: %d \n\t\tTipo: %d \n\t\tPrecio: $%.2f",
        codigoProductoMayorPrecio, tipoProductoMayorPrecio, precioProductoMayorPrecio);
    printf("\n\tDatos del producto con menor precio: \n\t\tCodigo: %d \n\t\tTipo: %d \n\t\tPrecio: $%.2f",
        codigoProductoMenorPrecio, tipoProductoMenorPrecio, precioProductoMenorPrecio);
    return 0;
}

int pedirDatosDeProducto(int codigosProductos[10], int tipoProductos[10], float precioProductos[10]) {
    int codigoMinimo = 100;
    int codigoMaximo = 999;
    int tipoMinimo = 1;
    int tipoMaximo = 3;
    float precioMinimo = 0;
    int codigoProducto = 0;
    int tipoProducto = 0;
    float precioProducto = 0;
    int contadorDeProductosCargados = 0;
    do {
        codigoProducto = pedirCodigoDeProducto("Ingrese codigo de producto. Ingrese 99 para terminar la carga",codigoMinimo, codigoMaximo);
        if (codigoProducto!=99) {
            tipoProducto = pedirNumeroInt("Ingrese tipo de producto", tipoMinimo, tipoMaximo);
            precioProducto = pedirNumeroFloat("Ingrese precio de producto", precioMinimo);
            codigosProductos[contadorDeProductosCargados] = codigoProducto;
            tipoProductos[contadorDeProductosCargados] = tipoProducto;
            precioProductos[contadorDeProductosCargados] = precioProducto;
            contadorDeProductosCargados++;
            printf("Informacion de producto cargada!! Siguiente.\n");
        }
    }while (codigoProducto!=99 || contadorDeProductosCargados==10);
    return contadorDeProductosCargados;
}
int pedirCodigoDeProducto(char mensaje[], int minimaOpcion, int maximaOpcion) {
    int numero= 0;
    do {
        printf("\n %s . Minimo %d. Maximo: %d. \n >>", mensaje, minimaOpcion, maximaOpcion);
        scanf("%d", &numero);
        if (numero<minimaOpcion-1 || numero>maximaOpcion) {
            printf("El numero ingresado es erroneo.");
        }
    }while (numero<minimaOpcion-1 || numero>maximaOpcion);
    return numero;
}
int pedirNumeroInt(char mensaje[], int minimaOpcion, int maximaOpcion) {
    int numero= 0;
    do {
        printf("\n %s . Minimo %d. Maximo: %d \n >>", mensaje, minimaOpcion, maximaOpcion);
        scanf("%d", &numero);
        if (numero<minimaOpcion || numero>maximaOpcion) {
            printf("El numero ingresado es erroneo.");
        }
    }while (numero<minimaOpcion || numero>maximaOpcion);
    return numero;
}
float pedirNumeroFloat(char mensaje[], float minimaOpcion) {
    float numero= 0;
    do {
        printf("\n %s . Minimo %2.f \n >>", mensaje, minimaOpcion);
        scanf("%f", &numero);
        if (numero<minimaOpcion) {
            printf("El precio ingresado es erroneo.");
        }
    }while (numero<minimaOpcion);
    return numero;
}


int diasBisiesto(int año) {
    if(año%100!=0 && año%4 == 0) {
        return 1;
    }
    if (año%100 == 0 && año%400 == 0) {
        return 1;
    }
    return 0;
}
int cantidadDiasDelMes(int mes, int año) {
    if (mes==2) {
        return 28 + diasBisiesto(año);
    }
    if (mes ==4 || mes == 6 | mes == 9 || mes ==11) {
        return 30;
    }
    return 31;
}
int esFechaValida(int dia, int mes, int año) {
    if (año<1582) {
        printf("\nAño no valido, debe ser mayor o igual a 1582.");
        return 0;
    }
    if(mes<1 || mes>12) {
        printf("\nMes no valido, debe estar entre 1 y 12.");
        return 0;
    }
    if (dia<1 || dia >31) {
        printf("\nDia no valido, debe estar entre 1 y 31.");
    }
    int diasDelMes = cantidadDiasDelMes(mes, año);
    if (dia>diasDelMes) {
        printf("\nEl mes ingresado tiene menos dias");
        return 0;
    }
    return 1;
}