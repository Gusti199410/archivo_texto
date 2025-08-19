#include"arch_txt.h"
#define archi_texto_variable "archivo_variable.txt"
#define archi_texto_fija "archivo_fija.txt"
int main()
{
    crear_Archivo_Texto_longitud_variable(archi_texto_variable);
    crear_Archivo_Texto_longitud_fija(archi_texto_fija);
    probar_Sprintf();
    probar_fprintf();
    printf("\n------------------------------------------\n");
    leerArchivo();
    tEmpleado emp;
    char s[100]="38531120;Gustavo neubauer;A;12/07/2020;1500000.25\n";
    trozar_Campos_longitud_fija(&emp,s);


    return 0;
}
