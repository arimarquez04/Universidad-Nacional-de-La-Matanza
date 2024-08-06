#include <stdio.h>

int main(void) {
    int edadDelAlumnoMasGrande =0;
    int cantidadDeAlumnos = 0;
    printf("Ingrese la cantidad de alumnos\n");
    printf(">>");
    scanf("%d", &cantidadDeAlumnos);
    for (int i =0; i<cantidadDeAlumnos; i++) {
        int edadActual = 0;
        printf("\nIngrese la edad del alumno actual \n");
        printf(">>");
        scanf("%d", &edadActual);
        if (edadActual>edadDelAlumnoMasGrande) {
            printf("Es mas grande\n");
        }
        else {
            printf("Es mas chico\n");
        }
    }
    return 0;
}
