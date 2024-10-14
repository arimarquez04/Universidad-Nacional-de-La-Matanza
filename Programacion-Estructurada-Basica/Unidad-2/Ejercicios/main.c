#include <stdio.h>
typedef struct {
    int dni;
    int nota;
    char nombre[21];
} Alumno;
Alumno pedirDatosAlumno(int dni);
int cargarAlumnos(Alumno alumno[], int maximoAlumnos);
int pedirDni(int minimo, maximo);
Alumno buscarAlumnoPorDni(Alumno alumno[], int dniBuscar);
int main(){
    int maximoAlumnos = 20;
    Alumno alumnos[maximoAlumnos];
    return 0;
}
int cargarAlumnos(Alumno alumno[], int maximoAlumnos) {
    int dni = 0;
    
}

