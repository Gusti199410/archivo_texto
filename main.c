#include"arch_txt.h"
#define archi_texto_variable "archivo_variable.txt"
#define archi_texto_fija "archivo_fija.txt"
int main()
{
    crear_Archivo_Texto_longitud_variable(archi_texto_variable);
    crear_Archivo_Texto_longitud_fija(archi_texto_fija);
    probar_Sprintf();
    probar_fprintf();
    printf("\n-----------------------------------------------\n");
    printf("\n***     ARCHIVO DE TEXTO VARIABLE      ****\n");
    leerArchivo_variable(archi_texto_variable);
    printf("\n***********************************************\n");
    printf("\n***     ARCHIVO DE TEXTO FIJA      ****\n");
    leerArchivo_fija(archi_texto_fija);

    return 0;
}
