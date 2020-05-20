#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "informes.h"
#include "utn.h"
#include "trabajo.h"
#include "bici.h"

void menuInformes(eBicicleta bicicletas[],int tamBici,eTrabajo trabajo[],int tamTra,eServicio servicio[],int tamSer,eColor color[],int tamCol,eTipo tipos[],int tamTip,eCliente client[],int tamCli)
{
    int option;
    do
    {

    printf("\t ******MENU DE INFORMES******\n\t");
    printf("\n1.Bicicletas por color");
    printf("\n2.Bicicletas por tipo");
    printf("\n3.Bicicletas menor rodado");
    printf("\n4.Mostrar listado de bicicletas por tipo");
    printf("\n5.Contador de Color y tipo");
    printf("\n6. Contador mayor color");
    printf("\n7. ");
    printf("\n8.");
    printf("\n9.");
    printf("\n10.");
    printf("\n11.");
    printf("\n12.");
    printf("\n13.Salir\n\n");
    scanf("%d", &option);

    switch(option)

        {
        case 1:
            printBikeColor(bicicletas,tamBici,color,tamCol,tipos,tamTip,client,tamCli);
            break;
        case 2:
            printBikeTipo(bicicletas,tamBici,color,tamCol,tipos,tamTip,client,tamCli);

            break;
        case 3:
            printBikeRodado(bicicletas,tamBici,color,tamCol,tipos,tamTip,client,tamCli);
            break;
        case 4:
            sortbikeTipo(bicicletas,tamBici,color,tamCol,tipos,tamTip,client,tamCli);

            break;
        case 5:
            contadorBike(bicicletas,tamBici,tipos,tamTip,color,tamCol);

            break;
        case 6:
            printMayorColor(bicicletas,tamBici,color,tamCol,tipos,tamTip,client,tamCli);
            break;
        case 7:



            break;
        case 8:


            break;
        case 9:


            break;
        case 10:


            break;
        case 11:
            break;
        case 12:
            break;
        case 13:
            printf("\nREGRESANDO AL MENU PRINCIPAL\n");
            break;
        default:
            printf("\nERROR! Por favor ingrese una opcion valida <1-13>\n");
            break;
        }

        fflush(stdin);
        system("pause");
        system("cls");
    }while(option!=13);
}
void printBikeColor(eBicicleta bici[],int tamBici,eColor color[],int tamCol, eTipo tipo[],int tamTipo,eCliente client[],int tamCli)
{
    system("cls");
    int i;
    int auxColor;
            printf("\n100.Gris");
            printf("\n101.Negro");
            printf("\n102.Blanco");
            printf("\n103.Azul");
            printf("\n104.Rojo");
    getValidInt("\nIngrese numero: ","\nError dato no valido",100,104,&auxColor);
    printf("ID      MARCA     RODADO     TIPO     COLOR\n");
    for(i=0;i<tamBici;i++)
    {
        if(bici[i].idColor==auxColor)
        {
            printBike(bici[i],tipo,tamTipo,color,tamCol,client,tamCli);
        }
    }
}
void printBikeTipo(eBicicleta bici[],int tamBici,eColor color[],int tamCol,eTipo tipo[],int tamTip,eCliente cliente[],int tamCli)
{
        system("cls");
    int i;
    int auxTipo;
                printf("\n10.Rutera");
                    printf("\n11.Carrera");
                    printf("\n12.Mountain");
                    printf("\n13.BMX");
    getValidInt("\nIngrese numero: ","\nError dato no valido",10,13,&auxTipo);
    printf("ID      MARCA     RODADO     TIPO     COLOR\n");
    for(i=0;i<tamBici;i++)
    {
        if(bici[i].idTipo==auxTipo)
        {
            printBike(bici[i],tipo,tamTip,color,tamCol,cliente,tamCli);
        }
    }
}
void printBikeRodado(eBicicleta bici[],int tamBici,eColor color[],int tamCol, eTipo tipo[],int tamTipo,eCliente client[],int tamCli)
{

    for(int i=0;i<tamBici;i++)
    {
        if(bici[i].rodado==20)
        {
            printBike(bici[i],tipo,tamTipo,color,tamCol,client,tamCli);
        }
    }

}
void sortbikeTipo(eBicicleta bici[],int tamBici,eColor color[],int tamCol, eTipo tipo[],int tamTipo,eCliente client[],int tamCli)
{
    eBicicleta auxBicicleta;
    int i;
    for(i=0; i<tamBici-1; i++)
    {
        for(int j=i+1; j<tamBici; j++)
        {
            if(bici[i].isEmpty==0)
            {

                if(bici[i].idTipo>bici[j].idTipo)
                {
                    auxBicicleta=bici[i];
                    bici[i]=bici[j];
                    bici[j]=auxBicicleta;
                }
            }
        }
    }
    printBikes(bici,tamBici,tipo,tamTipo,color,tamCol,client,tamCli);
}

void contadorBike(eBicicleta bici[],int tamBici,eTipo tipo[],int tamTip,eColor color[],int tamCol)

{
    system("cls");
    char descriptionTipo[20];
    char descriptionColor[20];
    int contadorColor=0;
    int contadorTipo=0;
    int i;
    int auxTipo;
                    printf("\n10.Rutera");
                    printf("\n11.Carrera");
                    printf("\n12.Mountain");
                    printf("\n13.BMX");
    getValidInt("\nIngrese numero: ","\nError dato no valido",10,13,&auxTipo);

    for(i=0;i<tamBici;i++)
    {
        if(bici[i].idTipo==auxTipo)
        {
            contadorTipo++;
        }
    }
    int auxColor;
            printf("\n100.Gris");
            printf("\n101.Negro");
            printf("\n102.Blanco");
            printf("\n103.Azul");
            printf("\n104.Rojo");
    getValidInt("\nIngrese numero: ","\nError dato no valido",100,104,&auxColor);

    for(i=0;i<tamBici;i++)
    {
        if(bici[i].idColor==auxColor)
        {
            contadorColor ++;
        }
    }

    loadDescriptionTipo(descriptionTipo,auxTipo,tipo,tamTip);
    loadDescriptionColor(descriptionColor,auxColor,color,tamCol);


    printf("\nCantidad de bicis del color: %s  %d",descriptionColor,contadorColor);
    printf("\nCantidad de bicis del Tipo: %s   %d\n",descriptionTipo,contadorTipo);

}
void printMayorColor(eBicicleta bici[],int tamBici,eColor color[],int tamCol, eTipo tipo[],int tamTipo,eCliente client[],int tamCli)
{
    char descripcionColor[20];
    int contadorColorMayor=0;
    int contadorColor;
    int auxColor[tamBici];
    int flag=0;
    int i;
    for(int i=0;i<tamBici;i++)
    {
        auxColor[i]=bici[i].idColor;

    }
    for(i=0;i<tamCol;i++)
    {
        if(auxColor[i]==color[i].id)
        {
            contadorColor++;
        }
        if(contadorColor>contadorColorMayor ||flag==0)
        {
            contadorColorMayor=contadorColor;
            flag=1;
        }
    }
     for(i=0;i<tamCol;i++)
    {
        if(auxColor[i]==color[i].id)
        {
            contadorColor++;
        }

    }
    if(contadorColor==contadorColorMayor)
        {
        loadDescriptionColor(descripcionColor,auxColor[i],color,tamCol);
        printf("\nEl color mas pedido es: %s",descripcionColor);
        }

}
