#include <stdio.h>
#include <stdlib.h>
#include "string.h"

#define CANT_NOTE 5

/*1. Crear una función llamada aplicarDescuento que reciba como parámetro el precio de un producto
 devuelva el valor del producto con un descuento del 5%. Realizar la llamada desde el main. **/

/*Crear una función que se llame contarCaracteres que reciba una cadena de caracteres como primer parámetro
y un carácter como segundo y devuelva la cantidad de veces que ese carácter aparece en la cadena */

/*Dada la estructura Notebook(id, procesador, marca, precio) generar una función que permita ordenar un array
de dicha estructura por marca. Ante igualdad de marca deberá ordenarse por precio. Hardcodear datos y mostrarlos
desde el main. */


typedef struct
{
    int id;
    char procesador[20];
    char marca[20];
    float precio;
} eNotebook;

float aplicarDescuento(float precio);
int contarCaracteres(char cadena[], char caracter);
int ordenarNotebooks(eNotebook notebooks[], int tamNote);

int mostrarNotebooks(eNotebook notebooks[], int tamNote);

int main()
{
    float precio = 1000;
    float precioConDescuento;
    char cadena[20] = "aa bbb dddd eeeee";
    char caracter;
    int cantCaracter;
    eNotebook notebooks[CANT_NOTE] =
    {
        {1,"Intel","Lenovo",1400},
        {2,"AMD","Lenovo",1000},
        {3,"AMD","BGH",2000},
        {4,"Intel","HP",2200},
        {5,"Intel","Asus",1800}
    };


    printf("Precio: %.2f\n", precio);
    precioConDescuento = aplicarDescuento(precio);
    printf("Precio con descuento: %.2f\n\n",precioConDescuento);


    caracter = 'd';
    cantCaracter = contarCaracteres(cadena, caracter);
    printf("Cadena: '%s'\n", cadena);
    printf("Caracter: '%c'\n", caracter);
    printf("Cantidad del caracter '%c': %d\n\n", caracter, cantCaracter);


    printf("Notebooks sin ordenar: \n");
    mostrarNotebooks(notebooks,CANT_NOTE);
    ordenarNotebooks(notebooks,CANT_NOTE);
    printf("Notebooks Ordenadas: \n");
    mostrarNotebooks(notebooks,CANT_NOTE);

    return 0;
}

float aplicarDescuento(float precio)
{
    float precioConDescuento;
    float descuento;
    int porcentaje;

    porcentaje = 5;
    descuento = precio * porcentaje / 100;
    precioConDescuento = precio - descuento;

    return precioConDescuento;
}

int contarCaracteres(char cadena[], char caracter)
{
    int cantCaracter = 0;
    int len;
    if(cadena != NULL)
    {
        len = strlen(cadena);
        for(int i = 0; i < len; i++)
        {
            if(cadena[i] == caracter)
            {
                cantCaracter++;
            }
        }
    }
    return cantCaracter;
}

int ordenarNotebooks(eNotebook notebooks[], int tamNote)
{
    int retorno = 0;
    eNotebook auxNote;
    if(notebooks != NULL && tamNote > 0)
    {
        for(int i = 0; i < tamNote-1; i++)
        {
            for(int j = i+1; j < tamNote; j++)
            {
                if(strcmp(notebooks[i].marca, notebooks[j].marca) > 0 ||
                        (strcmp(notebooks[i].marca, notebooks[j].marca) == 0 &&
                         notebooks[i].precio > notebooks[j].precio))
                {
                    auxNote = notebooks[i];
                    notebooks[i] = notebooks[j];
                    notebooks[j] = auxNote;
                }
            }
        }
        retorno = 1;
    }
    return retorno;
}

int mostrarNotebooks(eNotebook notebooks[], int tamNote)
{
    int retorno = 0;
    if(notebooks != NULL && tamNote > 0)
    {
        printf("ID    PROCESADOR     MARCA          PRECIO\n");
        for(int i = 0; i < tamNote; i++)
        {
            printf("%d     %-10s     %-10s     %.2f\n",
                   notebooks[i].id,
                   notebooks[i].procesador,
                   notebooks[i].marca,
                   notebooks[i].precio);
        }
        printf("\n\n");
        retorno = 1;
    }
    return retorno;
}
