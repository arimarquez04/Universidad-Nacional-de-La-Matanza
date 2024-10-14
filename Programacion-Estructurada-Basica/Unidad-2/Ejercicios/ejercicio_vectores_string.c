#include <stdio.h>
#include <strings.h>
#include <string.h>
#define MAX_ALUMNOS 5

int Buscar(int [], int, int);
int CargarAlumnos(int [], int [], char [][21], int);
void MostrarNotas(int [], int [], char [][21], int);
void OrdenarBurbujeo(int [], int [], char [][21], int);
int MaximaNotas(int [], int);
void MostrarXNota(int [], int [], char [][21], int, int);

int main() {
    int dnis[MAX_ALUMNOS], notas[MAX_ALUMNOS];
    char nombres[MAX_ALUMNOS][21];
    int cant_alumnos, maxima_nota;

    cant_alumnos = CargarAlumnos(dnis, notas, nombres,MAX_ALUMNOS);

    OrdenarBurbujeo(dnis, notas, nombres, cant_alumnos);
    MostrarNotas(dnis, notas, nombres, cant_alumnos);
    maxima_nota = MaximaNotas(notas, cant_alumnos);
    printf("\nLa nota maxima fue %d", maxima_nota);
    printf("\nMejores Alumnos");

    MostrarXNota(dnis, notas, nombres, maxima_nota, cant_alumnos);
    return 0;
}

int Buscar(int v[], int dato, int tam) {
    int posi, i;
    i = 0;
    posi = -1;

    while (posi == -1 && i < tam) {
        if (v[i] == dato)
            posi = i;
        else
            i++;
    }
    return posi;
}

int CargarAlumnos(int v_dnis[]
                  , int v_notas[]
                  , char v_nombres[][21]
                  , int tam) {
    int dni, nota, pos, i = 0;


    printf("Ingrese DNI:");
    scanf("%d", &dni);

    while (dni > 0 && i < tam) {
        pos = Buscar(v_dnis, dni, i);

        if (pos == -1) {
            v_dnis[i] = dni;

            fflush(stdin);
            printf("Ingrese nombre y apellido:");
            char nombre[21];
            gets(nombre);
            v_nombres[i]= nombre;
            printf("Ingrese la nota:");
            scanf("%d", &v_notas[i]); //validar not

            i++;
        } else
            printf("Dni existente.");

        if (i != tam) {
            printf("Ingrese DNI:");
            scanf("%d", &dni);
        }
    }
    return i;
}

void MostrarNotas(int v_dnis[]
                  , int v_notas[]
                  , char v_nombres[][21]
                  , int tam) {
    int i;
    printf("\nDNI\t\tNOMBRE\t\t\tNOTA");
    for (i = 0; i < tam; i++)
        printf("\n%d\t\t%s\t\t\t%d", v_dnis[i], v_nombres[i], v_notas[i]);
}

void OrdenarBurbujeo(int v_dnis[]
                     , int v_notas[]
                     , char v_nombres[][21]
                     , int tam) {
    int aux, i, j;
    char aux_nombre[21];

    for (i = 0; i < tam - 1; i++)
        for (j = 0; j < tam - i - 1; j++)
            if (strcmp(v_nombres[j], v_nombres[j + 1]) > 0) {
                aux = v_notas[j + 1];
                v_notas[j + 1] = v_notas[j];
                v_notas[j] = aux;

                aux = v_dnis[j + 1];
                v_dnis[j + 1] = v_dnis[j];
                v_dnis[j] = aux;

                strcpy(aux_nombre, v_nombres[j + 1]);
                strcpy(v_nombres[j + 1], v_nombres[j]);
                strcpy(v_nombres[j], aux_nombre);
            }
}


int MaximaNotas(int v_notas[], int tam) {
    int i, max;
    max = v_notas[0];

    for (i = 0; i < tam; i++)
        if (v_notas[i] > max)
            max = v_notas[i];
    return max;
}

void MostrarXNota(int v_dnis[]
                  , int v_notas[]
                  , char v_nombres[][21]
                  , int nota
                  , int tam) {
    int i;
    printf("\nDNI\t\tNOMBRE\t\t\tNOTA");
    for (i = 0; i < tam; i++)
        if (v_notas[i] == nota)
            printf("\n%d\t\t%s\t\t\t%d", v_dnis[i], v_nombres[i], v_notas[i]);
}
