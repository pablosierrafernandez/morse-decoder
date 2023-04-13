#include <stdio.h>
#include <stdlib.h>
#define MAXMORSE 10
#define CARACTERES 36
#include <string.h>
#define MAXPALABRAS 15
#define DIMENSION 7
#define ALFABETO 36
#define TAMANIO 15
#include <stdbool.h>
#define DIM 6
#define TAM 5

#include "cabeceras.h"

int main()
{
    int error=0,op;
    struct dic_t dict[CARACTERES];
    char caracter='\n';
    struct Traduccion1 tradu[ALFABETO];
struct Traduccion traduccion[ALFABETO];


    dict[CARACTERES]=leerDiccionario(dict, &error,caracter);

    if(error==-1)
    {
        printf("FIN DEL PROGRAMA.\n\n");
        return 0;
    }

    menuInicio();

    menu();

    scanf("%i",&op);
    while(op!=4)
    {

        switch(op)
        {
        case 1:
            codificarPalabra(dict);
            break;
        case 2: error= codificar(tradu);salidaError(&error);  break;

        case 3: error=descodificar(traduccion);
                 salidaError(&error);               break;

            default :
            system("cls");
            printf("ERROR. La opcion introducida no es valida.\n\n");
        }
        if (error==0)
            {
        menu();
        scanf("%i",&op);}
        else{op=4;}
    }
    finDelPrograma();

    return 0;




}
