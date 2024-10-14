#include <stdio.h>
int main()
{
    char nombre[21];
    printf ("Ingrese un nombre: ");
    gets(nombre);
    printf ("El nombre ingresado es: %s", nombre);
    return 0;
}