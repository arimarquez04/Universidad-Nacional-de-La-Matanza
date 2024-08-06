#include <stdio.h>
int pedirUnNumero();
int pedirOpcion(int minimaOpcion, int maximaOpcion);
int menu();
int main() {
    int opcion = 0;
    int numeroUno=0;
    int numeroDos = 0;
    while (opcion!=6) {
        opcion = menu(numeroUno, numeroDos);
        switch (opcion) {
            case 1:
                printf("Suma: %d", numeroUno+numeroDos);
            break;
            case 2:
                printf("Resta: %d", numeroUno-numeroDos);
            break;
            case 3:
                printf("Multiplicacion: %d", numeroUno*numeroDos);
            break;
            case 4:
                if (numeroDos!=0) {
                    float division = numeroUno/(float)numeroDos;
                    printf("Division: %2.f", division);
                }
                if (numeroDos==0) {
                    printf("No se puede realizar la division de %d entre %d, %d debe ser distinto de 0",
                        numeroUno, numeroDos, numeroDos);
                }
            break;
            case 5:
                numeroUno = pedirUnNumero();
                numeroDos = pedirUnNumero();
            break;
            case  6:
                printf("Saludos!!!!");
            break;
            default:
                printf("Saludos!!!!");
                opcion = 6;
            break;
        }
    }

}
int menu(int numeroUno, int numeroDos) {
    printf("\nMenu de opciones");
    printf("\nNumero 1: %d  Numero 2: %d", numeroUno, numeroDos);
    printf("\n1) Sumar \n2) Restar \n3) Multiplicar \n4) Dividir \n5) Ingresar nuevos numeros \n6) Salir");
    return pedirOpcion(1, 6);
}
int pedirOpcion(int minimaOpcion, int maximaOpcion) {
    int opcion= 0;
    do {
        printf("\nIngrese una opcion. Minimo %d. Maximo: %d \n >>", minimaOpcion, maximaOpcion);
        scanf("%d", &opcion);
    }while (opcion<minimaOpcion || opcion>maximaOpcion);
    return opcion;
}
int pedirUnNumero() {
    int numero = 0;
    printf("Ingrese una numero \n >>");
    scanf("%d", &numero);
    return numero;
}