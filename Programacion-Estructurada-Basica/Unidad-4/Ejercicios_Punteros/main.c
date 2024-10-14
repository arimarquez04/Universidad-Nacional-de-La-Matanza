#include <stdio.h>
typedef struct {
    int codigo;
    char descripcion[31];
    float precio;
} Producto;
int mockProductos(Producto productos[]);
Producto* buscarPosicionProducto(Producto productos[],int productosCargados, int codigoBuscar);
int main(void) {
    printf("Hello, World!\n");
    Producto productos[10];
    printf("Ingrese codigo a buscar \n>>");
    int codigoBuscar=-1;
    scanf("%d", &codigoBuscar);
    int productosCargados = mockProductos(productos);
    Producto* posicion = buscarPosicionProducto(productos, productosCargados,codigoBuscar);
    if(posicion!=NULL) {
        printf("La posicion del producto con codigo [%d] es: [%p].", codigoBuscar, posicion);
        printf("\nDatos: \n\t Codigo: [%d] \n\t Descripcion: [%s] \n\t Precio: [%.2f]",
            posicion->codigo, posicion->descripcion, posicion->precio);
    }
    if(posicion==NULL) {
        printf("La posicion del producto con codigo [%d] no se pudo encontrar.", codigoBuscar);
    }
    return 0;
}
Producto* buscarPosicionProducto(Producto productos[],int productosCargados, int codigoBuscar) {
    for(int i = 0; i<productosCargados; i++) {
        if (productos[i].codigo== codigoBuscar) {
            Producto* posicion= &productos[i];
            return posicion;
        }
    }
    Producto* posicion = NULL;
    return posicion;
}
int mockProductos(Producto productos[]) {
    // Cargamos los 10 productos
    productos[0] = (Producto){1001, "Producto A", 12.50};
    productos[1] = (Producto){1002, "Producto B", 8.99};
    productos[2] = (Producto){1003, "Producto C", 5.49};
    productos[3] = (Producto){1004, "Producto D", 20.00};
    productos[4] = (Producto){1005, "Producto E", 3.75};
    productos[5] = (Producto){1006, "Producto F", 15.30};
    productos[6] = (Producto){1007, "Producto G", 7.99};
    productos[7] = (Producto){1008, "Producto H", 9.49};
    productos[8] = (Producto){1009, "Producto I", 13.80};
    productos[9] = (Producto){1010, "Producto J", 25.99};
    return 10;
}