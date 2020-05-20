#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED
#include "bici.h"
#include "utn.h"
#include "trabajo.h"
void printBikeColor(eBicicleta bici[],int tamBici,eColor color[],int tamCol, eTipo tipo[],int tamTipo,eCliente client[],int tamCli);
void menuInformes(eBicicleta bicicletas[],int tamBici,eTrabajo trabajo[],int tamTra,eServicio servicio[],int tamSer,eColor color[],int tamCol,eTipo tipos[],int tamTip,eCliente client[],int tamCli);
void printBikeTipo(eBicicleta bici[],int tamBici,eColor color[],int tamCol,eTipo tipo[],int tamTip,eCliente cliente[],int tamCli);
void printBikeRodado(eBicicleta bici[],int tamBici,eColor color[],int tamCol, eTipo tipo[],int tamTipo,eCliente client[],int tamCli);
void sortbikeTipo(eBicicleta bici[],int tamBici,eColor color[],int tamCol, eTipo tipo[],int tamTipo,eCliente client[],int tamCli);
void contadorBike(eBicicleta bici[],int tamBici,eTipo tipo[],int tamTip,eColor color[],int tamCol);

void printMayorColor(eBicicleta bici[],int tamBici,eColor color[],int tamCol, eTipo tipo[],int tamTipo,eCliente client[],int tamCli);
#endif // INFORMES_H_INCLUDED
