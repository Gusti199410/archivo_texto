#ifndef ARCH_TXT_H_INCLUDED
#define ARCH_TXT_H_INCLUDED
#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define TAM_LINEA 61
#define TAM_SUELDO 9
#define TAM_FECHA 8
#define TAM_CATEGORIA 1
#define TAM_APYN 35
#define TAM_DNI 8


typedef struct
{

    int dia;
    int mes;
    int anio;

}tFecha;

typedef struct
{
    long dni;
    char apyn[36];
    char categoria;
    tFecha fecIngreso;
    float sueldo;

}tEmpleado;

void crear_Archivo_Texto(const char *archivo);

void  trozar_Campos_longitud_fija(tEmpleado *d,char *s);

#endif // ARCH_TXT_H_INCLUDED
