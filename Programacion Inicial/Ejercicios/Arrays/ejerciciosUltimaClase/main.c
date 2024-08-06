/*7.1.7   Se ingresan DNI, código de sector (1 a 5) y sueldo de los empleados de una empresa. Se sabe que como
máximo la empresa tiene 100 empleados. Se desea:
a. Cargar los datos de los empleados mediante la función CargaEmpleados. La carga finaliza con un
empleado con DNI 99.
b. Generar un vector con la cantidad de empleados en cada sector mediante la función
CuentaPorSector y mostrarlo en forma de listado.
c. Determinar el importe total a pagar de sueldos mediante la función TotalAPagar.*/
#include <stdio.h>
int cargaEmpleados(int codigosSectorEmpleados[], int dniEmpleados[], float sueldosEmpleados[], int maximoEmpleados);
int pedirDniEmpleado(int numeroSalida);
float pedirSueldoEmpleado();
int pedirCodigoSectorEmpleado(int maximo, int minimo);
float totalAPagar(float sueldosEmpleados[], int empleadosCargados);
void cuentaPorSector(int codigoSectorEmpleados[], int totalEmpleadosPorSector[], int empleadosCargados);
int main(void) {
    printf("Hello, World!\n");
    int maximoEmpleados = 100;
    int codigosSectorEmpleados[maximoEmpleados];
    int dniEmpleados[maximoEmpleados];
    float sueldosEmpleados[maximoEmpleados];
    int empleadosCargados = cargaEmpleados(codigosSectorEmpleados, dniEmpleados, sueldosEmpleados, maximoEmpleados);
    int totalEmpleadosPorSector[5] = {0,0,0,0,0};
    cuentaPorSector(codigosSectorEmpleados, totalEmpleadosPorSector, empleadosCargados);
    float totalPagar = totalAPagar(sueldosEmpleados, empleadosCargados);
    printf("\nInforme:");
    for (int i = 0; i<5; i++) {
        printf("\n\tCantidad Empleados en el Sector %d : %d", i+1, totalEmpleadosPorSector[i]);
    }
    printf("\n\tTotal a pagar: $%.2f", totalPagar);
    return 0;
}
int cargaEmpleados(int codigosSectorEmpleados[], int dniEmpleados[], float sueldosEmpleados[], int maximoEmpleados) {
    int dniEmpleado = 0;
    int codigoSectorEmpleado = 0;
    float sueldoEmpleado = 0;
    int numeroDeSalida = 99;
    int maximoSector = 5;
    int minimoSector = 1;
    int empleadosCargados = 0;
    while (empleadosCargados<maximoEmpleados && dniEmpleado!=99){
        dniEmpleado = pedirDniEmpleado(numeroDeSalida);
        if(dniEmpleado!=99) {
            codigoSectorEmpleado = pedirCodigoSectorEmpleado(minimoSector, maximoSector);
            sueldoEmpleado = pedirSueldoEmpleado();
            dniEmpleados[empleadosCargados] = dniEmpleado;
            codigosSectorEmpleados[empleadosCargados] = codigoSectorEmpleado;
            sueldosEmpleados[empleadosCargados] = sueldoEmpleado;
            empleadosCargados++;
            printf("Datos del empleado cargados con exito!!");
        }
    }
}
int pedirDniEmpleado(int numeroSalida) {
    int dni= 0;
    do {
        printf("\n Ingrese Dni . Ingrese %d para terminar la carga. \n >>", numeroSalida);
        scanf("%d", &dni);
        if (dni<0) {
            printf("\nEl numero ingresado es erroneo.");
        }
    }while (dni<0);
    return dni;
}
int pedirCodigoSectorEmpleado(int minimo, int maximo) {
    int sector= 0;
    do {
        printf("\n Ingrese Sector. Entre %d y %d >>", minimo, maximo);
        scanf("%d", &sector);
        if (sector<minimo || sector>maximo) {
            printf("\nEl numero ingresado es erroneo.");
        }
    }while (sector<minimo || sector>maximo);
    return sector;
}
float pedirSueldoEmpleado() {
    float sueldo= 0;
    do {
        printf("\n Ingrese Sueldo. \n >>");
        scanf("%f", &sueldo);
        if (sueldo<0) {
            printf("\nEl numero ingresado es erroneo.");
        }
    }while (sueldo<0);
    return sueldo;
}
void cuentaPorSector(int codigoSectorEmpleados[], int totalEmpleadosPorSector[], int empleadosCargados) {
    if(empleadosCargados!=0) {
        for (int i = 0; i < empleadosCargados; i++) {
            if(codigoSectorEmpleados[i]==1) {
                totalEmpleadosPorSector[0] +=1;
            }
            if(codigoSectorEmpleados[i]==2) {
                totalEmpleadosPorSector[1] +=1;
            }
            if(codigoSectorEmpleados[i]==3) {
                totalEmpleadosPorSector[2] +=1;
            }
            if(codigoSectorEmpleados[i]==4) {
                totalEmpleadosPorSector[3] +=1;
            }
            if(codigoSectorEmpleados[i]==5) {
                totalEmpleadosPorSector[4] +=1;
            }
        }
    }
}
float totalAPagar(float sueldosEmpleados[], int empleadosCargados) {
    float totalAPagar = 0;
    if(empleadosCargados!=0) {
        for (int i = 0; i < empleadosCargados; i++) {
           totalAPagar += sueldosEmpleados[i];
        }
    }
    return totalAPagar;
}


