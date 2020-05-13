#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#include "bici.h"
int askMenuOption()
{
    int option;
    printf("\t ******MENU DE OPERACIONES******\n\t");
    printf("\n1.Alta");
    printf("\n2.Modificar");
    printf("\n3.Baja bicicleta");
    printf("\n4.Listar bicicletas");
    printf("\n5.Listar tipos");
    printf("\n6.Listar colores");
    printf("\n7.Listar servicios");
    printf("\n8.Alta trabajo");
    printf("\n9.Listar trabajos");
    printf("\n10.Salir\n\n");
    scanf("%d", &option);

    return option;
}
void printBike(eBicicleta x, eTipo tipos[], int tamTip,eColor color[],int tamCol)
{
    char descriptionTipo[20];
    char descriptionColor[20];
    loadDescription(descriptionTipo,descriptionColor,x.idTipo,tipos,tamTip,x.idColor,color,tamCol);
    printf("%d   %s    %6.2f   %10s  %10s\n",x.id,x.marca,x.rodado,descriptionTipo,descriptionColor);

}
void printBikes(eBicicleta bicicletas[], int tam, eTipo tipos[], int tamTip,eColor color[],int tamCol)
{
    int i;
    int flag=0;
    printf("\tLista de bicicletas\n\n");
    printf("ID    MARCA     RODADOS     TIPO      COLOR\n");
    for(i=0;i<tam;i++)
    {
        if(bicicletas[i].isEmpty==0)
        {
            printBike(bicicletas[i],tipos,tamTip,color,tamCol);
            flag=1;
        }
    }
    if(flag==0)
    {
        printf("\nNo hay Bicicletas que mostrar");
    }
}
void loadDescription(char descripcionTipo[],char descripcionColor[],int idTip,eTipo tipos[],int tam,int idCol,eColor color[],int tamCol)
{
    int i;

    for(i=0;i<tam;i++)///recorro secotres
    {
        if(tipos[i].id==idTip && color[i].id==idCol)///busco el id de sectores
        {
            strcpy(descripcionTipo,tipos[i].descripcion);///copio la descripcion a l parametro
            strcpy(descripcionColor,color[i].descripcion);
        }
    }
}
void initBikes(eBicicleta bicicletas[],int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        bicicletas[i].isEmpty=1;///si esta vacio 1=verdadero 0=flaso
    }
}
int findFreespace(eBicicleta bicicletas[],int tam)
{
    int index=-1;///asi empieza desde 0
    int i;
    for(i=0;i<tam;i++)
    {
        if(bicicletas[i].isEmpty==1)///si esta abierto detecta el lugar vacio
        {
            index=i;
            break;
        }
    }
    return index;
}
int findBikeById(int id, eBicicleta bicicletas[],int tam)
{
    int index=-1;
    int i;
    for(i=0;i<tam;i++)
    {
        if(bicicletas[i].id==id && bicicletas[i].isEmpty==0)///detecta si existe el alumno por id
        {
            index=i;
            break;
        }
    }
    return index;

}
int addBikes(int id,eBicicleta bicicletas[],int tam,eTipo tipos[],int tamTip,eColor color[],int tamCol)
{
    eBicicleta auxBicicletas;
    int retorno=-1;
    float numero;
    int index=findFreespace(bicicletas,tam);///devuelve el indice -1
    int exist;///aca guardo el id

    system("cls");
    printf("\nAlta empleados");
    if(index==-1)///hay lugar?
    {
        printf("\nSistema Completao\n");
    }
    else
    {
        exist = findBikeById(id,bicicletas,tam);

        if(exist !=-1)///el id ya esta?, es decis los compara los ID
        {
            printf("\nYa existe un empleado con ese id");
        }
        else
        {
            auxBicicletas.id=id;

            printf("\nIngrese Marca: ");
            fflush(stdin);
            gets(auxBicicletas.marca);

            printf("\nSelecciona el color: ");
            for(int i=0; i<1;i++)
            {
                printf("\n100.Gris");
                printf("\n101.Negro");
                printf("\n102.Blanco");
                printf("\n103.Azul");
                printf("\n104.Rojo");
            }

            printf("\ningrese id del color");
            scanf("%d",&auxBicicletas.idColor);


            printf("\nSelecciona el tipo: ");
            for(int i=0; i<1;i++)
            {
                printf("\n1.Rutera");
                printf("\n2.Carrera");
                printf("\n3.Mountain");
                printf("\n4.BMX");
            }

            printf("\ningrese id del tipo");
            scanf("%d",&auxBicicletas.idTipo);

            printf("\n1. 20\n2. 26\n3. 27.5\n4. 29\n");
            printf("\nIngrese rodado: ");
            scanf("%f",&numero);
            if(numero==20|| numero==26||numero==27.5||numero==29)
            {
                auxBicicletas.rodado=numero;
                 auxBicicletas.isEmpty=0;
                bicicletas[index]=auxBicicletas;
                retorno=0;
            }
            else
            {
                printf("\nRodado invalido\n");
            }
           ///copio vector con empleado nuevo
        }
    }
    return retorno;
}
void removeBikes(eBicicleta bicicletas[], int tam,eTipo tipos[], int tamTip,eColor color[],int tamCol)
{
    int index;
    int id;
    char confirm;
    system("cls");

    printf("Baja bicicletas");
    printf("\nIngrese ID");

    scanf("%d",&id);

    index=findBikeById(id,bicicletas,tam);

    if(index==-1)
    {
        printf("\nNo hay registro de una bicicleta con el id: %d",id);
    }
    else
    {
        printBike(bicicletas[index],tipos,tamTip,color,tamCol);
        printf("\nConfirma Baja?(s/n)");
        fflush(stdin);
        scanf("%c",&confirm);

        if(confirm== 's')
        {
            bicicletas[index].isEmpty=1;
            printf("\nSe a realizado la baja con exito");
        }
        else
        {
            printf("\nSe ha cancelado la operacion");
        }
    }
}
void modifyBike(eBicicleta bicicletas[],int tam, eTipo tipos[], int tamTip,eColor color[],int tamCol)
{
    int options;
    int id;
    int index;
    char confirm;
    float newrodado;
    int newtipo;
    printf("Modificar empleados");
    printf("\nIngrese Id:");
    scanf("%d",&id);

    index =findBikeById(id,bicicletas,tam);

    if(index==-1)
    {
        printf("\nNo hay registro de un bicicleta con el id: %d",id);
    }
    else
    {
        printBike(bicicletas[index],tipos,tamTip,color,tamCol);

        printf("\nModificar bicicleta?(s/n)");
        fflush(stdin);
        scanf("%c",&confirm);

        if(confirm== 's')
        {
            printf("\nQue desa modificar?");
            printf("\n1.rodado");
            printf("\n2.tipo");
            scanf("%d",&options);
            switch(options)
            {

            case 1:
                printf("\n1. 20\n2. 26\n3. 27.5\n4. 29\n");
                printf("\nIngrese nuevo rodado: ");
                scanf("%f",&newrodado);
                if(newrodado==20|| newrodado==26||newrodado==27.5||newrodado==29)
            {
                bicicletas[index].rodado=newrodado;
            }
            else
            {
                printf("\nRodado invalido\n");
            }
                break;
            case 2:
                printf("\nSeleccione nuevo tipo");
            printf("\nSelecciona el tipo: ");
                for(int i=0; i<1;i++)
                {
                    printf("\n1.Rutera");
                    printf("\n2.Carrera");
                    printf("\n3.Mountain");
                    printf("\n4.BMX");
                }

                    scanf("%d",&newtipo);
                    bicicletas[index].idTipo=newtipo;
                    break;
                }

            printf("\nSe a realizado la modificacion con exito");
        }
        else
        {
            printf("\nSe ha cancelado la operacion");
        }
    }
}
