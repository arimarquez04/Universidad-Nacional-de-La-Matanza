#include <stdio.h>
void modificarUnArray(int array[]);
int main(void) {
    printf("Hello, World!\n");
    int otrosNumeros[5] = {1+10,2,3,4,5};
    return 0;
}
void modificarUnArray(int array[]) {
    int longitudDelArray = sizeof(array);
    int nuevoArray[longitudDelArray];
    for (int i = longitudDelArray; i>0; i--) {
        nuevoArray[i]= array[i];
    }
    for (int i = 0; i <longitudDelArray; i--) {
        array[i] = nuevoArray
    }
}
