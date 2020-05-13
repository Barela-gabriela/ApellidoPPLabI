#ifndef BICI_H_INCLUDED
#define BICI_H_INCLUDED
typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;
typedef struct
{
    int id;
    char marca[20];///nombre
    float rodado;///sueldo
    eFecha fechaIngreso;
    int isEmpty;
    int idTipo;
    int idColor;
}eBicicleta;
typedef struct
{
   int id;
   char descripcion[20];
}eTipo;
typedef struct
{
   int id;
   char descripcion[20];
}eColor;
typedef struct
{
   int id;
   char descripcion[20];
   float precio;
}eServicio;
typedef struct
{
   int id;
   int idBicicleta;
   int idServicio;
   eFecha fecha;
}eTrabajo;
int askMenuOption();
void printBike(eBicicleta x, eTipo tipos[], int tamTip,eColor color[],int tamCol);
void printBikes(eBicicleta bicicletas[], int tam, eTipo tipos[], int tamTip,eColor color[],int tamCol);


void loadDescription(char descripcionTipo[],char descripcionColor[],int idTip,eTipo tipos[],int tam,int idCol,eColor color[],int tamCol);



void initBikes(eBicicleta bicicletas[],int tam);
int findFreespace(eBicicleta bicicletas[],int tam);
int findBikeById(int id, eBicicleta bicicletas[],int tam);

int addBikes(int id,eBicicleta bicicletas[],int tam,eTipo tipos[],int tamTip,eColor color[],int tamCol);

void removeBikes(eBicicleta bicicletas[], int tam,eTipo tipos[], int tamTipe,eColor color[],int tamCol);

void modifyBike(eBicicleta bicicletas[],int tam, eTipo tipos[], int tamTip,eColor color[],int tamCol);




#endif // BICI_H_INCLUDED
