#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "informes.h"
#include "utn.h"
#include "trabajo.h"
#include "bici.h"

void menuInformes(eBicicleta bicicletas[],int tamBici,eTrabajo trabajo[],int tamTra,eServicio servicio[],int tamSer,eColor color[],int tamCol,eTipo tipos[],int tamTip,eCliente cleint[],int tamCli)
{
    int option;
    do
    {

    printf("\t ******MENU DE INFORMES******\n\t");
    printf("\n1.Bicicletas por color");
    printf("\n2.");
    printf("\n3.");
    printf("\n4.");
    printf("\n5. ");
    printf("\n6. ");
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
            printBikeBlack(bicicletas,tamBici,color,tamCol,tipos,tamTip,client,tamCli);
            break;
        case 2:

            break;
        case 3:
            break;
        case 4:


            break;
        case 5:


            break;
        case 6:

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
void printBikeBlack(eBicicleta bici[],int tamBici,eColor color[],int tamCol, eTipo tipo[],int tamTipo,eCliente client[],int tamCli)
{
    system("cls");
    int i;
    int auxColor;
    //getValidInt("\nIngrese numero: ","\nError dato no valido",100,104,&auxColor);
    //auxBicicletas.idColor=auxColor;
    printf("ID      MARCA     RODADO     TIPO     COLOR\n");
    for(i=0;i<tamBici;i++)
    {
        if(bici[i].idColor==101 || 100 || 102 ||103)
        {
            printBike(bici[i],tipo,tamTipo,color,tamCol,client,tamCli);
        }
    }
}
/*void printBikeMarca(eBicicleta bici[],int tamBici,eColor color[],int tamCol,eTipo tipo[],int tamTip)
{
    system("cls");
    int i;
    int j;
    getValidString("\nIngrese Marca: ","\nError ingrese solo caracteres","\nError se exedio del limite de caracteres\n",auxMarca,1,19);
    printf("ID      MARCA     RODADO     TIPO     COLOR\n");
    for(i=0;i<tamBici;i++)
    {
        for(j+1; j<tamBici,j++)
        {
            if(strcmp(bici[i].marca,bici[j].marca)==0)
            {
                printBike(bici[i],tipo,tamTipo,color,tamCol);
            }
        }

    }
}*/
