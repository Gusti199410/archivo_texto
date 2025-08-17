#include"arch_txt.h"
#include"memoria.h"
#define archi_bin "archivo.bin"


void crear_Archivo_Texto_longitud_variable(const char *archivo)
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
                                };

    size_t ce = sizeof(vectorEmpleado)/sizeof(tEmpleado);

    for(int i=0;i<ce;i++)
    {
        fprintf(fp,"%ld;%s;%c;%d/%d/%d;%.2f\n",

                vectorEmpleado[i].dni,
                vectorEmpleado[i].apyn,
                vectorEmpleado[i].categoria,
                vectorEmpleado[i].fecIngreso.dia,
                vectorEmpleado[i].fecIngreso.mes,
                vectorEmpleado[i].fecIngreso.anio,
                vectorEmpleado[i].sueldo);

    }

    fclose(fp);
}
void crear_Archivo_Texto_longitud_fija(const char *archivo)
{
    FILE *fp=fopen(archivo,"wt");
    if(!fp)
    {
        printf("Error al crear archivo de texto longitud fija");
        exit(-1);
    }
     tEmpleado vectorEmpleado[]={{4444444,"Persona Cuatro", 'A',{1,10,2022},44000.4F},
                                {2222222,"Persona Dos",    'B',{12,12,2021},22000.2F},
                                {3333333,"Persona Tres",   'B',{1,5,2023},33000.3F},
                                {5555555,"Persona Cinco",  'A',{1,5,2005},55000.5F},
                                {1111111,"Persona Cuatro", 'C',{1,1,2001},111000.F}
                                };
    size_t ce=sizeof(vectorEmpleado)/sizeof(vectorEmpleado[0]);
    for(size_t i=0;i<ce;i++)
    {
        fprintf(fp,"%08ld %-49s %c %02d/%02d/%04d %9.2f\n",
                vectorEmpleado[i].dni,
                sizeof(vectorEmpleado[i].apyn)-1,
                sizeof(vectorEmpleado[i].apyn)-1,
                vectorEmpleado[i].categoria,
                vectorEmpleado[i].fecIngreso.dia,
                vectorEmpleado[i].fecIngreso.mes,
                vectorEmpleado[i].fecIngreso.anio,
                vectorEmpleado[i].sueldo);
    }


    fclose(fp);
}

bool convertir_archtxt_a_archibin(const char *archivo_txt,const char *archivo_bin,tMemoria *vec)
{
    FILE *ft=fopen(archivo_txt,"rt");
    if(!ft)
    {
        printf("Error abrir el archivo texto");
        return false;
    }
    FILE * fb=fopen(archivo_bin,"wb");
    if(!fb)
    {
        printf("Error al abrir el archivo binario");
        fclose(ft);
        return false;
    }
    tEmpleado emp;
    fgets(&emp,sizeof(tEmpleado)-1,ft);


    return true;
}
