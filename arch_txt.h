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

void crear_Archivo_Texto_longitud_variable(const char *archivo);
void crear_Archivo_Texto_longitud_fija(const char *archivo);
bool cargar_Archtxt_variable(const char *archivo,tEmpleado *emp);
void probar_Sprintf(void);
void probar_fprintf(void);
int abrir_Archivo(FILE **fp,const char *nombre_Archivo,const char *modo_apertura,int mostrar_Error);
void  trozar_Campos_longitud_variable(tEmpleado *d,char *s);
void leerArchivo_variable(const char *archivo_variable);
void trozar_Campo_longitud_Fija(tEmpleado *d, char *s);
void leerArchivo_fija(const char *archivo_fija);
void convertir_Archivotxt_Long_fija_A_Binario(const char *archivotxt, const char *archivobin);
void leer_Archivo_binario(const char *archivo);
void convertir_Archivotxt_Long_variable_A_Binario(const char *archivotxt, const char *archivobin);




#endif // ARCH_TXT_H_INCLUDED
