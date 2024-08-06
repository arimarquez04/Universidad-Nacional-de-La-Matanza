#include <stdio.h>

int main(void) {
    printf("Hello, World!\n");
    for (int numero =1; numero<10 ; numero++) {
        for (int multiplicador = 1; multiplicador<10; multiplicador++) {
            printf("%d", numero * multiplicador);
        }
        printf("\n");
    }
    return 0;
}
