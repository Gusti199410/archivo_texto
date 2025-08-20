#include"arch_txt.h"
#include"modi_bina.h"
#define archi_texto_variable "archivo_variable.txt"
#define archi_texto_fija "archivo_fija.txt"
#define archivo_binario_fija "archi_bin"
#define archivo_binario_variable "archivo_binario"
int main()
{
    crear_Archivo_Texto_longitud_variable(archi_texto_variable);
    crear_Archivo_Texto_longitud_fija(archi_texto_fija);
    convertir_Archivotxt_Long_fija_A_Binario(archi_texto_fija,archivo_binario_fija);
    printf("\n*****************************************************************\n");
    leer_Archivo_binario(archivo_binario_fija);
     printf("\n*****************************************************************\n");
    modificar_Archivo_binario(archivo_binario_fija);
    leer_Archivo_binario(archivo_binario_fija);
    return 0;
}
