#ifndef ARCH_TXT_H_INCLUDED
#define ARCH_TXT_H_INCLUDED
#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

typedef struct
{
    int dia,mes,año;

}tFecha;

typedef struct
{
    long dni;
    char apyn[36];
    char categoria;
    tFecha fecIngreso;
    float sueldo;

}tEmpleado

void crear_Archivo_Texto(const char *archivo);



#endif // ARCH_TXT_H_INCLUDED
