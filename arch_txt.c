#include"arch_txt.h"
#define archi_texto "archivo.txt"
#define archi_bin "archivo.bin"

void crear_Archivo_Texto(const char *archivo)
{
    FILE *fp=fopen(archivo,"wt");
    if(!fp)
    {
        printf("Error al crear archivo de texto");
        exit(1);
    }
    tEmpleado vectorEmpleado[]={{4444444,"Persona Cuatro", 'A',{1,10,2022},44000.4F},
                                {2222222,"Persona Dos",    'B',{12,12,2021},22000.2F},
                                {3333333,"Persona Tres",   'B',{1,5,2023},33000.3F},
                                {5555555,"Persona Cinco",  'A',{1,5,2005},55000.5F},
                                {1111111,"Persona Cuatro", 'C',{1,1,2001},111000.F}

    size_t ce=sizeof(vectorEmpleado)/sizeof(vectorEmpleado[0]);
    size_t tam_Elem=sizeof(tEmpleado);

    for(int i=0;i<ce;i++)
    {
        fprintf(fp,"%ld;%s;%c;%d/%d/%d;%.2f\n";

                vectorEmpleado[i].dni,
                vectorEmpleado[i].apyn,
                vectorEmpleado[i].categoria,
                vectorEmpleado[i].tFecha.dia,
                vectorEmpleado[i].tFecha.mes,
                vectorEmpleado[i].tFecha.año,
                vectorEmpleado[i].sueldo);

    }

    fclose(fp);
    return 0;
}

