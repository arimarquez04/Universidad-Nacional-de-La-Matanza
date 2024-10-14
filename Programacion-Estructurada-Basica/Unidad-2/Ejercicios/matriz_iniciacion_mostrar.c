#include<stdio.h>
#define FILAS 5
#define COLUMNAS 6

void mostrar(int [][COLUMNAS], int, int);
main()
{
 int mat[FILAS][COLUMNAS]={{0}};

 mostrar(mat, FILAS, COLUMNAS);
}

void mostrar(int  m[][COLUMNAS], int f, int c)
{
    int i,j;

    for(i=0;i<f;i++)
    {
        printf("\n%d ",i+1);
        for(j=0;j<c;j++)
        {
            printf(" %d",m[i][j]);
        }
    }
}
