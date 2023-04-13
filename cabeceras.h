#ifndef CABECERAS_H_INCLUDED
#define CABECERAS_H_INCLUDED



#endif // CABECERAS_H_INCLUDED
struct Traduccion{
    char letra;
    char morse[DIM];

    };
struct Traduccion1{
    char letra;
    char morse[DIMENSION];

    };

struct dic_t
{
    char letra;
    char letraMin;
    char codigo[MAXMORSE];
};
void menuInicio();
void menu ();
void codificarPalabra (struct dic_t dict[CARACTERES]);
struct dic_t leerDiccionario(struct dic_t dict[CARACTERES], int *error, char caracter);
void finDelPrograma();
int codificar( struct Traduccion1 tradu[ALFABETO]);
int descodificar (struct Traduccion traduccion[ALFABETO]);
void salidaError(int *error);
