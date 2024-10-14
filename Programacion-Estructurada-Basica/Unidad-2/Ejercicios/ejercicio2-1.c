#include <stdio.h>
#include <string.h>
#include <strings.h>

void LeerTexto (char texto[], int largo);
int pedirDni(int maximo, int minimo);
char pedirNombreAlumno(int maximoCaracteres);
int pedirNota(int minimo, int maximo);
int buscar(char vn[][],char buscado[], int cant);
int cargarDatos(int dnisAlumnos[], char nombresAlumnos[][], int notasAlumnos[], int cantMaxAlumnos);
int main(void) {
    printf("Hello, World!\n");
    int maximoAlumnos = 20;
    int maxCaracteresNombresAlumnos = 21;
    int dnisAlumnos[maximoAlumnos];
    int notasAlumnos[maximoAlumnos];
    char nombresAlumnos[maxCaracteresNombresAlumnos][maximoAlumnos];
    int cantAlumnosCargados = cargarDatos(dnisAlumnos, nombresAlumnos, notasAlumnos, maximoAlumnos);

    return 0;
}
int cargarDatos(int dnisAlumnos[], char nombresAlumnos[][], int notasAlumnos[], int cantMaxAlumnos) {
    int dni = 0;
    int dniMinimo = 0;
    int dniMaximo = 99999999;
    int cantMaxCaracteres = 21;
    int notaMinima = 1;
    int notaMaxima = 10;
    int cantidadAlumnosCargados = 0;
    do {
        dni = pedirDni(dniMaximo, dniMinimo);
        if(dni!=0) {
            char nombre = pedirNombreAlumno(cantMaxCaracteres);
            int nota = pedirNota(notaMinima, notaMaxima);
            dnisAlumnos[cantidadAlumnosCargados] = dni;
            nombresAlumnos[cantidadAlumnosCargados] = nombre;
            notasAlumnos[cantidadAlumnosCargados] = nota;
            cantidadAlumnosCargados++;
        }
    }while (dni!=0 || cantidadAlumnosCargados<cantMaxAlumnos);
}

void LeerTexto (char texto[], int largo)
{
    int i;
    fgets(texto, largo, stdin);
    i=0;
    while (texto[i]!='\0')
    {
        if (texto[i]=='\n')
            texto[i]='\0';
        else
            i++;
    }
}
int buscar(char vn[][11],char buscado[], int cant)
{
    int i=0, pos=-1;
    while (pos==-1 && i<cant)
    {
        if (strcmp(vn[i], buscado)==0)
            pos =i;
        else
            i++;
    }
    return pos;
}
char pedirNombreAlumno(int maximoCaracteres) {
    char nombre[maximoCaracteres];
    printf ("Ingrese un nombre: ");
    return fgets(nombre);
}
