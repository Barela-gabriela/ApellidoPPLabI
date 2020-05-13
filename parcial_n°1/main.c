#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define TAMTIP 4
#define TAM 8
#define TAMCOL 5
#include "bici.h"
int main()
{
    char confirm;
    char seguir='s';
    eBicicleta bicicletas[TAM];
    eTipo tipos[TAMTIP]={{1,"rutera"},{2,"Carerra"},{3,"mountain"},{4,"BMX"}};
    eColor color[TAMCOL]={{100,"girs"},{101,"negro"},{102,"blaco"},{103,"azul"},{104,"rojo"}};
    int nextId=1000;
    initBikes(bicicletas,TAM);
    ///loadEmployees();
    nextId +=1;
    do
    {
        switch(askMenuOption())
            {
            case 1:
                printf("\t\tAlta");
               if(addBikes(nextId,bicicletas,TAM,tipos,TAMTIP,color,TAMCOL))
               {
                   nextId++;
               }
                break;
            case 2:
                modifyBike(bicicletas,TAM,tipos,TAMTIP,color,TAMCOL);
                break;
            case 3:
                removeBikes(bicicletas,TAM,tipos,TAMTIP,color,TAMCOL);
                break;
            case 4:
                printf("\nListar bicicletas\n");
                printBikes(bicicletas,TAM,tipos,TAMTIP,color,TAMCOL);
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
                printf("\nConfirma salida?(s/n)\t");
                fflush(stdin);
                scanf("%c",&confirm);
                if(confirm=='s')
                {
                    seguir='n';
                }
                break;
            }
    }
    while(seguir=='s');
    return 0;
}
