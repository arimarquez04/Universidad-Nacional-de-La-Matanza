#include<stdio.h>
#include<stdlib.h>
#define FILAS 5
#define COLUMNAS 8

void Mostrar(int [][COLUMNAS], int, int);
void CargaAleatorioa(int [][COLUMNAS]
                     ,int,int,int,int);
int Maximo(int [][COLUMNAS], int, int);
void MostrarMaximo(int m[][COLUMNAS]
                   ,int,int,int);

main()
{
    int mat[FILAS][COLUMNAS];
    int max;
    CargaAleatorioa(mat,FILAS,COLUMNAS,10,99);
    Mostrar(mat,FILAS,COLUMNAS);
    max = Maximo(mat, FILAS, COLUMNAS);
    MostrarMaximo(mat, FILAS, COLUMNAS, max);
}

void CargaAleatorioa(int m[][COLUMNAS]
                     ,int f,int c,int min, int max)
{
    int i,j;

    srand(time(NULL));
    for(i=0;i<f;i++)
        for(j=0;j<c;j++)
        m[i][j] = min + rand()%(max - min + 1);
}

void Mostrar(int  m[][COLUMNAS], int f, int c)
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
int Maximo(int m[][COLUMNAS], int f, int c)
{
    int i, j, may;
    may=m[0][0];
    for(i=0;i<f;i++)
        for(j=0;j<c;j++)
            if(m[i][j]>may)
                may=m[i][j];

    return may;
}

void MostrarMaximo(int m[][COLUMNAS]
                   ,int f
                   ,int c
                   ,int max)
{
    int i,j;
    printf("\nEl valor maximo es %d y se encuentra en las siguientes posiciones", max);
    for(i=0;i<f;i++)
        for(j=0;j<c;j++)
            if(m[i][j]==max)
                printf("\nFila %d Columna %d",i+1,j+1);

}








