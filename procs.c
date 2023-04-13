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

void menuInicio()
{
    printf("\n\n\t\t*****BIENVENIDO AL TRADUCTOR DE MORSE*****\n\n");
}
void menu ()
{

    printf("\nElija alguna de las siguientes opciones\n\n");
    printf("\n\n\t(1).Codificar palabra.\n\t(2).Codificar Fichero.\n\t(3).Descodificar Fichero.\n\t(4).SALIR\n\n");
}

void codificarPalabra (struct dic_t dict[CARACTERES])
{
    system("cls");
    char palabra[15]="";
    printf("Escriba la palabra:  "); //  ***APORTE EXTRA*** ACEPTA MINUSCULAS


    scanf("%s",palabra);
    int numLetras=strlen(palabra);

    if(numLetras>MAXPALABRAS)
    {
        printf("\n\nERROR. La palabra supera los limites establecidos.\n\n");
    }
    else
    {

        printf("\n\nLa palabra %s, codificada es: ",palabra);
        for(int p=0; palabra[p]!='\0'; p++)
        {
            for(int q=0; q<=CARACTERES; q++)
            {
                if((palabra[p]==dict[q].letra)||(palabra[p]==dict[q].letraMin))
                {
                    for(int e=0; dict[q].codigo[e]!='\n'; e++)
                    {
                        printf("%c",dict[q].codigo[e]);

                    }
                    printf("   ");

                }
            }
            printf("  ");
        }

    }
    printf("\n\n");

}

struct dic_t leerDiccionario(struct dic_t dict[CARACTERES], int *error, char caracter)
{

    FILE*fichero;
    char c;
    int i=0,j=0;
    fichero = fopen ("morse.txt", "r");

    fscanf (fichero, "%c", &c);
    if ((fichero!=NULL)&& (!feof(fichero)))
    {
        while(!feof(fichero))
        {
            dict[i].letra=c;
            dict[i].letraMin=c+32;
            printf("%c ",dict[i].letra);
            fscanf (fichero, "%c", &c);
            fscanf (fichero, "%c", &c);
            while(c!='*')
            {

                dict[i].codigo[j]=c;
                printf("%c",dict[i].codigo[j]);
                fscanf (fichero, "%c", &c);
                j++;
            }
            dict[i].codigo[j]=caracter;
            i++;
            fscanf (fichero, "%c", &c);
            fscanf (fichero, "%c", &c);
            fscanf (fichero, "%c", &c);

            j=0;
        }

        *error=0;
    }
    else
    {
        printf("ERROR\n\n"); //NO ME FUNCIONA SI ESTA VACIO
        *error=-1;

    }
    fclose(fichero);
    return(dict[CARACTERES]);

}
void finDelPrograma()
{


    printf("Hasta Pronto!\n\n");

}
int codificar( struct Traduccion1 tradu[ALFABETO]){

 int i=0,e=0,j=0;
    char c;
    char palabra[TAMANIO];
    bool trobat=false,paraula=true;
    FILE* fitxer;
    FILE* sortida;
    memset(palabra,0,15);

    /* for(j=0;j<ALFABETO,j++)
     memset(tradu[j],0,5);
     La inicializacion peta, pero no es necesario del todo*/

    fitxer=fopen("morse.txt","r");
    /*Comprovem de que es pugui accedir al fitxer i de que aqeust no estigui buit*/
    if (fitxer == NULL){
        printf("Error!!! No s'ha pogut accedir al fitxer");
return -1;
    }else{
        fseek(fitxer, 0, SEEK_END);
        if (ftell(fitxer) == 0){
            printf("El fitxer esta buit");
            return -1;
        } fseek(fitxer, 0, SEEK_SET);
    }
    /*Rellenamos el vector tradu con el caracter en la parte char del struct
    y el codigo en el vetor morse*/
    fscanf(fitxer,"%c",&c);
    while (!feof(fitxer))
    {

        if (c!=' ')
        {
        tradu[i].letra=c;
        }
        else
        {
         e++;

        }
        if(e>0)
        {
         fgets(tradu[i].morse,sizeof(tradu[i].morse),fitxer);
         e=0;
         i++;
        }
    fscanf(fitxer,"%c",&c);
    }
    fclose(fitxer);
    i=0;
    e=0;


    fitxer=fopen("original.txt","r");
    sortida=fopen("codificat.txt","w");
    /*Comprovem de que es pugui accedir al fitxer i de que aqeust no estigui buit*/
    if (fitxer == NULL){
        printf("Error!!! No s'ha pogut accedir al fitxer");
        return -1;
    }else{
        fseek(fitxer, 0, SEEK_END);
        if (ftell(fitxer) == 0){
            printf("El fitxer esta buit");
            return -1;
        } fseek(fitxer, 0, SEEK_SET);
    }

    fscanf(fitxer,"%c",&c);
    while (!feof(fitxer))
    {   memset(palabra,0,15);
        while((paraula)&&(!feof(fitxer)))
        {
        palabra[i]=c;
        i++;
        fscanf(fitxer,"%c",&c);
        if(c==' ')
        paraula=false;
        }
        i=0;
        e=0;
        while(e<strlen(palabra))
        {
            while(!trobat)
            {
                if (palabra[e]==tradu[i].letra)
                { trobat=true;
                while(tradu[i].morse[j]!='*')
                    {
                    fprintf(sortida,"%c",tradu[i].morse[j]);
                    j++;
                    }
                }
                else
                i++;
            }
         e++;
         i=0;
         j=0;
         fprintf(sortida,"   ");
         trobat=false;

        }

    fprintf(sortida,"     ");
    fscanf(fitxer,"%c",&c);
    paraula=true;
    }

  fclose(fitxer);
  fclose(sortida);
return 0;
    }

int descodificar (struct Traduccion traduccion[ALFABETO]){

int i=0,e=0,j=1,x=0,y=0,coincidencia=0;
    char c;
    char letras[TAM];
    bool trobat=false,letra=true;
    FILE* fitxer;
    FILE* sortida;
    memset(letras,0,15);
    memset(traduccion[0].morse,0,DIM);
    memset(traduccion[1].morse,0,DIM);
    memset(traduccion[2].morse,0,DIM);
    memset(traduccion[3].morse,0,DIM);
    memset(traduccion[4].morse,0,DIM);
    memset(traduccion[5].morse,0,DIM);
    memset(traduccion[6].morse,0,DIM);
    memset(traduccion[7].morse,0,DIM);
    memset(traduccion[8].morse,0,DIM);
    memset(traduccion[9].morse,0,DIM);
    memset(traduccion[10].morse,0,DIM);
    memset(traduccion[11].morse,0,DIM);
    memset(traduccion[12].morse,0,DIM);
    memset(traduccion[13].morse,0,DIM);
    memset(traduccion[14].morse,0,DIM);
    memset(traduccion[15].morse,0,DIM);
    memset(traduccion[16].morse,0,DIM);
    memset(traduccion[17].morse,0,DIM);
    memset(traduccion[18].morse,0,DIM);
    memset(traduccion[19].morse,0,DIM);
    memset(traduccion[20].morse,0,DIM);
    memset(traduccion[21].morse,0,DIM);
    memset(traduccion[22].morse,0,DIM);
    memset(traduccion[23].morse,0,DIM);
    memset(traduccion[24].morse,0,DIM);
    memset(traduccion[25].morse,0,DIM);
    memset(traduccion[26].morse,0,DIM);
    memset(traduccion[27].morse,0,DIM);
    memset(traduccion[28].morse,0,DIM);
    memset(traduccion[29].morse,0,DIM);
    memset(traduccion[30].morse,0,DIM);
    memset(traduccion[31].morse,0,DIM);
    memset(traduccion[32].morse,0,DIM);
    memset(traduccion[33].morse,0,DIM);
    memset(traduccion[34].morse,0,DIM);
    memset(traduccion[35].morse,0,DIM);
    memset(traduccion[36].morse,0,DIM);

     /* for(j=0;j<ALFABETO,j++)
     memset(traduccion[j],0,5);
     La inicializacion peta, pero no es necesario del todo*/

    fitxer=fopen("morse.txt","r");
    /*Comprovem de que es pugui accedir al fitxer i de que aqeust no estigui buit*/
    if (fitxer == NULL){
        printf("Error!!! No s'ha pogut accedir al fitxer");
       return -1;
    }else{
        fseek(fitxer, 0, SEEK_END);
        if (ftell(fitxer) == 0){
            printf("El fitxer esta buit");
         return -1;
        } fseek(fitxer, 0, SEEK_SET);
    }
    /*Rellenamos el vector traduccion con el caracter en la parte char del struct
    y el codigo en el vetor morse*/
    fscanf(fitxer,"%c",&c);
    while (!feof(fitxer))
    {

        if (c!=' ')
        {
        traduccion[i].letra=c;
        }
        else
        {
         e++;
        }
        if(e>0)
        {
            while(c!='*')
            {
             traduccion[i].morse[y]=c;
             y++;
             e=0;
             fscanf(fitxer,"%c",&c);
            }
        y=0;
        i++;
        }
    fscanf(fitxer,"%c",&c);
    }
    fclose(fitxer);
    i=0;
    e=0;
/*---------------------------------------------------------------------------------------------*/

    fitxer=fopen("codificat.txt","r");
    sortida=fopen("descodificat.txt","w");
    /*Comprovem de que es pugui accedir al fitxer i de que aqeust no estigui buit*/
    if (fitxer == NULL){
        printf("Error!!! No s'ha pogut accedir al fitxer");
        return -1;
    }else{
        fseek(fitxer, 0, SEEK_END);
        if (ftell(fitxer) == 0){
            printf("El fitxer esta buit");
            return -1;
        } fseek(fitxer, 0, SEEK_SET);
    }

    fscanf(fitxer,"%c",&c);
    while (!feof(fitxer))
    {
        while((letra)&&(!feof(fitxer)))
        {
        letras[i]=c;
        i++;
        fscanf(fitxer,"%c",&c);
        if(c==' ')
        {
        fscanf(fitxer,"%c",&c);
        fscanf(fitxer,"%c",&c);
        letra=false;
        }

        }
        i=0;
        j=0;
        x=1;
        trobat=false;
    while(!trobat)
        {

            if(letras[j] == traduccion[i].morse[x])
                {
                 j++;
                 x++;
                 coincidencia++;
                }
            else
                {
                 i++;
                 j=0;
                 x=1;
                 coincidencia=0;
                }
            if (coincidencia==strlen(traduccion[i].morse))
            {
              trobat=true;
              coincidencia=0;
            }

        }
    fprintf(sortida,"%c",traduccion[i].letra);
    i=0;
    memset(letras,0,5);
    fscanf(fitxer,"%c",&c);
    if(c==' ')
    {
    fscanf(fitxer,"%c",&c);
    fscanf(fitxer,"%c",&c);
    fprintf(sortida," ");
    letra=true;
    }
    else
    letra=true;
}
fclose(fitxer);
fclose(sortida);
return 0;
}

void salidaError(int *error){

    if(*error==-1)
    {

        printf("\nFIN DEL PROGRAMA POR ERROR.\n\n");
         *error= -1;
    }
    else{
       *error= 0;
    }

}
