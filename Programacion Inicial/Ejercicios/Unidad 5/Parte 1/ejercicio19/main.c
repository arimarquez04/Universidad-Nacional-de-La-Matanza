#include <stdio.h>

int main(void) {
    printf("Hello, World!\n");
    int cantidad = 0;
    printf("Ingrese la cantidad de filas \n >>");
    scanf("%d", &cantidad);
    for (int i = 1; i<=cantidad; i++) {
        for(int j= 1; j<=i; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
