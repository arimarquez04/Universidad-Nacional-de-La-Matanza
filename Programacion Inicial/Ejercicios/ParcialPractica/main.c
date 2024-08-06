 /*
  Ejercicio de practica:
  Se procesan las altas de ingresantes a Ingeniería. Por cada inscripto se ingresa:
- DNI (7 u 8 dígitos)
   - carrera (char: I informática, E electrónica, C civil, M mecánica)
   - edad (>15)
   - 3 notas correspondiente a las notas de evaluaciones obtenidas en el curso de ingreso (cada una entre 4 y 10)

   La carga de inscripciones finaliza con un DNI igual a 0. Todos los datos de ingreso deben estar validados

   a) Mostar la cantidad de inscriptos separados por rango etario:
   •  menores a 18
   • entre 18 y 25
   • entre 25 y 40
   • mayores a 40

   b) Indicar si alguna carrera no tuvo inscriptos LISTO
   c) Mostrar el mayor promedio obtenido Listo
   d) Mostrar el promedio de cada alumno No quiero hacerlo
*/
#include <stdio.h>
int main(void) {
    printf("Hello, World!\n");
    //variables de utilidades
    int salirDelCiclo = 1;
    int dniMinimo = 1000000;
    int dniMaximo = 99999999;
    int edadMinima = 15;
    int notasAPedir = 3;
    int notaMinima = 4;
    int notaMaxima = 10;
    int inscriptosElectromecanica = 0;
    int inscriptosInformatica = 0;
    int inscriptosCivil = 0;
    int inscriptosMecanica = 0;
    int edadesMenores18=0;
    int edadesEntre18y25=0;
    int edadesEntre25y40 = 0;
    int edadesMayores40 = 0;
    float mayorPromedio = 0;
    int dniMayorPromedio = 0;

    //ciclo principal del programa, este ciclo se repetira siempre que dniIngresado!=0
    while(salirDelCiclo!=0) {
        //dato a pedir por cada alumno
        int dniIngresado = 1;
        char carreraIngresada = 'I';
        int edadIngresada = 0;
        int notaIngresada = 0;
        int notasAcumuladas = 0;
        float promedio = 0;
        int datoValido = 1;

        //empezar a pedir datos
        printf("\n Ingrese el dni, entre 7 y 8 digitos, al ingresar 0 se terminara \n >>");
        scanf("%d", &dniIngresado);
        fflush(stdin);
        //si el dni ingresado==0 entonces "salirDelCiclo" se iguala a 0, por lo tanto np pedira dato alguno
        //y saldra del ciclo principal del programa y posteriormente se mostraran los datos de informe
        if (dniIngresado==0) {
            salirDelCiclo = 0;
        }
        if (dniIngresado>dniMinimo && dniIngresado<dniMaximo && salirDelCiclo!=0) {
            //Pedir datos individualmente y validarlos
            //Ciclo para pedir CARRERA
            do {
            printf("\nIngrese la carrera: I informática, E electrónica, C civil, M mecánica\n >>");
            fflush(stdin);
            scanf(" %c", &carreraIngresada);
                datoValido = 1;
                if (carreraIngresada=='I'||carreraIngresada=='E'||carreraIngresada=='M'||carreraIngresada=='C'
                    ||carreraIngresada=='i'||carreraIngresada=='e'||carreraIngresada=='m'||carreraIngresada=='c') {
                    switch (carreraIngresada) {
                        case 'i':
                            case 'I':
                                inscriptosInformatica +=1;
                        break;
                        case 'e':
                            case 'E':
                                inscriptosElectromecanica +=1;
                        break;
                        case 'm':
                            case 'M':
                                inscriptosMecanica +=1;
                        break;
                        case 'c':
                            case 'C':
                                inscriptosCivil +=1;
                        break;
                    }
                    datoValido = 1;
                }else {
                    printf("\n Error! carrera erronea. Ingrese una valida... \n");
                    datoValido=0;
                }
            }while (datoValido!=1);

            //Ciclo para pedir EDAD
            datoValido = 1;
            do {
                printf("\nIngrese la edad \n >>");
                fflush(stdin);
                scanf(" %d", &edadIngresada);
                if (edadIngresada>edadMinima) {
                    if (edadIngresada<18) {
                        edadesMenores18 +=1;
                    }
                    if (edadIngresada>=18 && edadIngresada<25) {
                        edadesEntre18y25 +=1;
                    }
                    if (edadIngresada>=25 && edadIngresada<=40) {
                        edadesEntre25y40 +=1;
                    }
                    if (edadIngresada>40) {
                        edadesMayores40 +=1;
                    }
                    datoValido = 1;
                }else {
                    printf("\nError! edad erronea. Ingrese una valida... \n");
                    datoValido=0;
                }
            }while (datoValido!=1);

            //Ciclo para pedir NOTAS, la variable "notasAPedir" es la cantidad maxima de notas que se pediran
            for (int i = 1; i<=notasAPedir;i++) {
                datoValido = 1;
                printf("Ahora debe ingresar las %d notas del alumno", notasAPedir);
                do {
                    printf("\nIngrese la %d nota entre 4 y 10 \n >>", i);
                    scanf("%d", &notaIngresada);
                    if (notaIngresada>=notaMinima && notaIngresada<=notaMaxima) {
                        notasAcumuladas += notaIngresada;
                        datoValido = 1;

                    }else {
                        printf("\nError! nota erronea. Ingrese una valida... \n");
                        datoValido = 0;
                    }
                }while (datoValido!=1);
            }
            promedio = notasAcumuladas/notasAPedir;
            if(promedio>mayorPromedio) {
                mayorPromedio = promedio;
                dniMayorPromedio = dniIngresado;
            }
        }
    }
    //el ciclo de pedir datos se termina

    //mostrar datos de informe
    printf("\nInscriptos menores a 18: %d", edadesMenores18);
    printf("\nInscriptos entre 18 y 25: %d", edadesEntre18y25);
    printf("\nInscriptos entre 25 y 40: %d", edadesEntre25y40);
    printf("\nInscriptos mayores a 40: %d", edadesMayores40);
    if (inscriptosCivil==0) {
        printf("\n No hay inscriptos a Ingenieria Civil");
    }
    if (inscriptosElectromecanica==0) {
        printf("\n No hay inscriptos a Ingenieria Electromecanica");
    }
    if (inscriptosInformatica==0) {
        printf("\n No hay inscriptos a Ingenieria Informatica");
    }
    if (inscriptosMecanica==0) {
        printf("\n No hay inscriptos a Ingenieria Mecanica");
    }
    printf("\n El mayor promedio es de: %f y corresponde al alumno con dni: %d", mayorPromedio, dniMayorPromedio);

    return 0;
}