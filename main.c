#include"arch_txt.h"
#define archi_texto_variable "archivo_variable.txt"
#define archi_texto_fija "archivo_fija.txt"
#define archivo_binario_fija "archi_bin"
#define archivo_binario_variable"archivo_binario"
int main()
{
    crear_Archivo_Texto_longitud_variable(archi_texto_variable);
    crear_Archivo_Texto_longitud_fija(archi_texto_fija);
    probar_Sprintf();
    probar_fprintf();
    printf("\n-------------------------------------------------------------\n");
    printf("\n/////////////////////////////////////////////////////////////\n");
    printf("\n***               ARCHIVO DE TEXTO VARIABLE              ****\n");
    printf("\n/////////////////////////////////////////////////////////////\n");
    leerArchivo_variable(archi_texto_variable);
    printf("\n*************************************************************\n");
    printf("\n/////////////////////////////////////////////////////////////\n");
    printf("\n***                    ARCHIVO DE TEXTO FIJA             ****\n");
    printf("\n/////////////////////////////////////////////////////////////\n");
    leerArchivo_fija(archi_texto_fija);
    printf("\n/////////////////////////////////////////////////////////////\n");
    printf("\n        *****TEXTO CONVERTIDO EN ARCHIVO BINARIO*****        \n");
    printf("\n/////////////////////////////////////////////////////////////\n");
    convertir_Archivotxt_Long_fija_A_Binario(archi_texto_fija,archivo_binario_fija);
    leer_Archivo_binario(archivo_binario_fija);
    printf("\n/////////////////////////////////////////////////////////////\n");
    printf("\n        *****TEXTO var CONVERTIDO EN ARCHIVO BINARIO*****        \n");
    printf("\n/////////////////////////////////////////////////////////////\n");
    convertir_Archivotxt_Long_variable_A_Binario(archi_texto_variable,archivo_binario_variable);
    leer_Archivo_binario(archivo_binario_variable);
    return 0;
}
