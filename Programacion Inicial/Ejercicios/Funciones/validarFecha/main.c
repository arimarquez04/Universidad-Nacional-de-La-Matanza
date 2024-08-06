#include <stdio.h>
int esFechaValida(int dia, int mes, int año);
int cantidadDiasDelMes(int mes, int año);
int diasBisiesto(int año);
int main(void) {
    int año = 0;
    int dia = 0;
    int mes = 0;
    printf("Ingrese año \n >>");
    scanf("%d", &año);
    printf("Ingrese mes \n >>");
    scanf("%d", &mes);
    printf("Ingrese dia \n >>");
    scanf("%d", &dia);
    if (esFechaValida(dia, mes, año)==1) {
        printf("\nLa fecha %d/%d/%d es valida.", dia, mes, año);
    }else {
        printf("\nLa fecha %d/%d/%d no es valida.", dia, mes, año);
    }
    return 0;
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