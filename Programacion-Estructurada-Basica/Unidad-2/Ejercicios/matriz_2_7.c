#include<stdio.h>
#define CANT_PRODUCTOS 3
#define MESES 12

int ValidarIngreso(int,int,int);
int Buscar(int [], int, int);
void CargaProductos(int [], float [], int);
int Trimestre(int);
void MostrarUnidadesVendidasXMes(int []
                                 ,int [][12]
                                 ,int
                                 ,int);
float MayorRecaudacion(float [],
                       int);
void MostrarProductoMayor(float [],
                          int [],
                          int,
                          float);

float MenorRecaudacion(float [],int);
void MostrarTriMenorRec(float [],int,float);

main()
{
    float mayor_rec,menor_rec;
    int cod_productos[CANT_PRODUCTOS];
    float precios_productos[CANT_PRODUCTOS];

    int cant_ventas[CANT_PRODUCTOS][MESES] = {{0.0}};
    float recaudacion_producto[CANT_PRODUCTOS] = {0.0};
    float recaudacion_trim[4] = {0.0};

    int prod, dia, mes, cant, pos, trim;

    CargaProductos(cod_productos,precios_productos,CANT_PRODUCTOS);

    //PROCESAMIENTO DE LAS VENTAS

    printf("Ingrese el codigo de producto:");
    prod = ValidarIngreso(100,999,0);
    while (prod!=0)
    {
        pos = Buscar(cod_productos, prod, CANT_PRODUCTOS);

        if(pos!=-1)
        {
            printf("Ingrese el mes:");
            mes = ValidarIngreso(1,12,12);
//            printf("Ingrese el dia:");
//            dia = ValidarIngreso(1,31,31);
            printf("Ingrese cant vendida:");
            scanf("%d",&cant);

            cant_ventas[pos][mes-1]+=cant;
            recaudacion_producto[pos]+=cant*precios_productos[pos];

            trim=Trimestre(mes);
            recaudacion_trim[trim-1]+=cant*precios_productos[pos];

        }
        else
            printf("El producto es invalido.\n");


        printf("Ingrese el codigo de producto:");
        prod = ValidarIngreso(100,999,0);
    }

    MostrarUnidadesVendidasXMes(cod_productos,cant_ventas
                                ,CANT_PRODUCTOS
                                ,MESES);

    mayor_rec = MayorRecaudacion(recaudacion_producto,
                                 CANT_PRODUCTOS);
    MostrarProductoMayor(recaudacion_producto,
                         cod_productos,
                         CANT_PRODUCTOS,
                         mayor_rec);
    menor_rec = MenorRecaudacion(recaudacion_trim, 4);
    MostrarTriMenorRec(recaudacion_trim, 4, menor_rec);
}

int ValidarIngreso(int li, int ls, int salida)
{
    int dato, bandera=0;

    do
    {
        if (bandera==1)
            printf("Ingreso erroneo. Vuelva a ingresar:");

        scanf("%d",&dato);

        bandera = 1;
    }while((dato<li || dato>ls) && dato!=salida);

    return dato;
}

int Buscar(int v[], int dato, int tam)
{
    int posi,i;
    i = 0;
    posi = -1;

    while(posi == -1 && i < tam)
    {
        if (v[i] == dato)
            posi = i;
        else
            i++;
    }
    return posi;
}

void CargaProductos(int prod[], float precios[], int n)
{
    int i, cod_producto, pos;
    float pu;

    for(i=0;i<n;i++)
    {
        printf("Ingrese producto:");

        do
        {
            cod_producto = ValidarIngreso(100,999,999);
            pos=Buscar(prod,cod_producto,i);
            if (pos!=-1)
                printf("Producto existente. Ingrese nuevamente.");
        }
        while(pos!=-1);

        prod[i]=cod_producto;
        printf("Ingrese precio unitario:");
        scanf("%f", &precios[i]);
    }
}
int Trimestre(int mes)
{
    int trimestre;
    if (mes<=3)
        trimestre=1;

    if (mes>3 && mes <=6)
        trimestre = 2;

    if (mes>6 && mes <=9)
        trimestre = 3;

    if (mes>9)
        trimestre = 4;
    return trimestre;
}

void MostrarUnidadesVendidasXMes(int v_cod_prods[]
                                 ,int m_cant_ventas[][12]
                                 ,int cant_prod
                                 ,int cant_meses)
{
   int i,j;
   printf("\nDetalle de Venta de Productos x Mes");

   printf("\nPRO\\MES");
   for(j=0;j<cant_meses;j++)
    printf("\t%d", j+1);

   for(i=0;i<cant_prod;i++)
   {
       printf("\n%d    ",v_cod_prods[i]);
       for(j=0;j<cant_meses;j++)
        printf("\t%d",m_cant_ventas[i][j]);
   }
}

float MayorRecaudacion(float v_recaudacion[],
                       int cant_prod)
{
    int i=0;
    float mayor = v_recaudacion[0];

    for(i=1;i<cant_prod;i++)
      if(v_recaudacion[i]>mayor)
        mayor=v_recaudacion[i];

    return mayor;
}

void MostrarProductoMayor(float recaudacion[],
                          int cod_prods[],
                          int cant_prod,
                          float mayor)
{

    int i;
    printf("\nLa recaudacion mayor fue %.2f en los siguientes productos",mayor);

    for(i=0;i<cant_prod;i++)
    {
        if(recaudacion[i]==mayor)
            printf("\n%d",cod_prods[i]);
    }
}

float MenorRecaudacion(float v_recaudacion[], int cant_tri)
{
    int i;
    float menor = v_recaudacion[0];

    for(i=1;i<cant_tri;i++)
      if(v_recaudacion[i]<menor)
        menor=v_recaudacion[i];

    return menor;
}

void MostrarTriMenorRec(float v_recaudacion[]
                        ,int cant_tri
                        ,float menor)
{
    int i;
    printf("\nLa recaudacion menor fue %.2f en los siguientes trimestres",menor);

    for(i=0;i<cant_tri;i++)
        if(v_recaudacion[i]==menor)
            printf("\n%d",i+1);


}
