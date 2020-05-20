#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED
#include "bici.h"
#include "utn.h"
#include "trabajo.h"
void printBikeBlack(eBicicleta bici[],int tamBici,eColor color[],int tamCol, eTipo tipo[],int tamTipo,eCliente client[],tamCli);
void menuInformes(eBicicleta bicicletas[],int tamBici,eTrabajo trabajo[],int tamTra,eServicio servicio[],int tamSer,eColor color[],int tamCol,eTipo tipos[],int tamTip,eCliente clent[],tamCli);
#endif // INFORMES_H_INCLUDED
