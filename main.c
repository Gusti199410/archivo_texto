#include"arch_txt.h"
#define archi_texto_variable "archivo_variable.txt"
#define archi_texto_fija "archivo_fija.txt"
int main()
{
    crear_Archivo_Texto_longitud_variable(archi_texto_variable);
    crear_Archivo_Texto_longitud_fija(archi_texto_fija);
    tEmpleado emp;
    while(leer_Archtxt_variable(archi_texto_fija,&emp))
    {
        printf("DNI: %ld\n",emp.dni);
        printf("NOMBRE: %s\n",emp.apyn);
        printf("CATEGORIA: %c\n",emp.categoria);
        printf("DIA: %d\n",emp.fecIngreso.dia);
        printf("MES: %d\n",emp.fecIngreso.mes);
        printf("ANIO: %d\n",emp.fecIngreso.anio);
        printf("SUELDO: %.2f\n",emp.sueldo);
        printf("\n-------------------------------------\n");
    }
    return 0;
}
