#include"arch_txt.h"
#include"memoria.h"



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
        fprintf(fp,"%ld;%s;%c;%02d/%02d/%04d;%.2f\n",

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
     tEmpleado vectorEmpleado[]={{44444444,"Persona Cuatro", 'A',{1,10,2022},44000.4F},
                                {22222222,"Persona Dos",    'B',{12,12,2021},22000.2F},
                                {3333333,"Persona Tres",   'B',{1,5,2023},33000.3F},
                                {5555555,"Persona Cinco",  'A',{1,5,2005},55000.5F},
                                {1111111,"Persona Uno", 'C',{1,1,2001},111000.F}
                                };
    size_t ce=sizeof(vectorEmpleado)/sizeof(vectorEmpleado[0]);
    for(size_t i=0;i<ce;i++)
    {
        fprintf(fp,"%08ld%-35s%c%02d%02d%04d%9.2f\n",
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

    return true;
}

bool cargar_Archtxt_variable(const char *archivo,tEmpleado *emp)
{

    FILE *fp=fopen(archivo,"rt");
    if(!fp)
    {
        printf("Error al leer archivo");
        return false;
    }
    char buffer[100];
    if(!fgets(buffer,sizeof(buffer),fp))
    {
        return false;
    }
    sscanf(buffer,"%8ld%30s%c%2d%2d%4d%9.2f",
           &emp->dni,
           emp->apyn,
           &emp->categoria,
           &emp->fecIngreso.dia,
           &emp->fecIngreso.mes,
           &emp->fecIngreso.anio,
           &emp->sueldo);

    emp->apyn[30]='\0';
    fclose(fp);
    return true;

}

void probar_Sprintf(void)
{
    char cadena[80];
    tEmpleado emp;
    emp.dni=38531120;
    strcpy(emp.apyn,"Neubauer Gustavo");
    emp.categoria='A';
    emp.fecIngreso.dia=12;
    emp.fecIngreso.mes=11;
    emp.fecIngreso.anio=1994;
    emp.sueldo=199531.12;

    sprintf(cadena,"%08ld %-15s %c %02d/%02d/%04d %9.2f\n",
            emp.dni,
            emp.apyn,
            emp.categoria,
            emp.fecIngreso.dia,
            emp.fecIngreso.mes,
            emp.fecIngreso.anio,
            emp.sueldo);

    printf("Cadena generada por sprintf: %s\n",cadena);
}
void probar_fprintf(void)
{
    FILE *fp=fopen("gustavo.txt","wt");
    if(!fp)
    {
        printf("error al crear archivo");
        exit(1);
    }

    tEmpleado emp;

    emp.dni=38531120;
    strcpy(emp.apyn,"Gustavo neubauer");
    emp.categoria='A';
    emp.fecIngreso.dia=12;
    emp.fecIngreso.mes=7;
    emp.fecIngreso.anio=2020;
    emp.sueldo=1500000.3;

    fprintf(fp,"%08ld;%s;%c;%02d/%02d/%04d;%9.2f\n",emp.dni,
                                                    emp.apyn,
                                                    emp.categoria,
                                                    emp.fecIngreso.dia,
                                                    emp.fecIngreso.mes,
                                                    emp.fecIngreso.anio,
                                                    emp.sueldo);
    fclose(fp);

}

int abrir_Archivo(FILE **fp,const char *nombre_Archivo,const char *modo_apertura,int mostrar_Error)
{
    *fp=fopen(nombre_Archivo,modo_apertura);
    if(!fp==NULL)
    {
        if(mostrar_Error==1){
            fprintf(stderr,"Error abriendo \%s en modo \%s.",nombre_Archivo,modo_apertura);

        }
        return 0;
    }
    return 1;

}

void  trozar_Campos_longitud_variable(tEmpleado *d,char *s)

{
    char *aux=strchr(s,'\n');///busco el salto de linea
    *aux='\0';                ///lo reemplazo por el caracter nulo

    /** SUELDO  */

    aux=strrchr(s,';');             /// busco el ultimo separador en archivo de texto se
                                    ///realiza la convercion de atras para adelante

    sscanf(aux+1,"%f",&d->sueldo);

    *aux='\0';                      /// reemplazo el contenido de la direccion de aux por el caracter nulo "\0"

    /** FECHA  */

    aux=strrchr(s,';');

    sscanf(aux+1,"%d/%d/%d",&d->fecIngreso.dia,
                            &d->fecIngreso.mes,
                            &d->fecIngreso.anio);

    *aux='\0';

    /** CATEGORIA  */

    aux=strrchr(s,';');

    sscanf(aux+1,"%c",&d->categoria);

    *aux='\0';

    /** APELLIDO Y NOMBRE **/

    aux=strrchr(s,';');

    strcpy(d->apyn,aux+1);

    *aux='\0';

    /** DNI  */

    sscanf(s,"%ld",&d->dni);

}
void leerArchivo_variable(const char *archivo_variable)
{
    FILE *fp = fopen(archivo_variable, "rt");
    if(!fp)
    {
        printf("Error al leer archivo\n");
        exit(1);
    }
    tEmpleado emp;
    char cad[200];
    while(fgets(cad, sizeof(cad), fp))
    {
        trozar_Campos_longitud_variable(&emp, cad);
        printf("DNI: %ld\n", emp.dni);
        printf("Nombre: %s\n", emp.apyn);
        printf("Categoria: %c\n", emp.categoria);
        printf("Fecha: %02d/%02d/%04d\n",
               emp.fecIngreso.dia,
               emp.fecIngreso.mes,
               emp.fecIngreso.anio);
        printf("Sueldo: %.2f\n", emp.sueldo);
        printf("\n-----------------------------------------------------------------\n");
    }

    fclose(fp);
}

void trozar_Campo_longitud_Fija(tEmpleado *d, char *s)
{
    char *aux=s+TAM_LINEA;///POSICIONAMOS AL FINAL DEL PUNTERO
    *aux='\0'; ///CARGAMOS CARACTER NULO

    /** SUELDO*/

    aux-=TAM_SUELDO;

    sscanf(aux,"%f",&d->sueldo);

    *aux='\0';

    /** FECHA */

    aux-=TAM_FECHA;

    sscanf(aux,"%2d%2d%4d",&d->fecIngreso.dia,
                           &d->fecIngreso.mes,
                           &d->fecIngreso.anio);

    *aux='\0';

    /** CATEGORIA */

    aux-=TAM_CATEGORIA;

    sscanf(aux,"%c",&d->categoria);

    *aux='\0';

    /** APELLIDO Y NOMBRE */

    aux-=TAM_APYN;

    strcpy(&d->apyn,aux);

    *aux='\0';

    /** DNI */

    aux-=TAM_DNI;

    sscanf(aux,"%ld",&d->dni);

    *aux='\0';

}
void leerArchivo_fija(const char *archivo_fija)
{
    FILE *fp= fopen(archivo_fija,"rt");
    if(!fp)
    {
        printf("Error al abrir archivo de lectura fija");
        exit(1);
    }
    tEmpleado emp;
    char cad[100];

    while(fgets(cad,sizeof(cad),fp))
    {
        trozar_Campo_longitud_Fija(&emp,cad);
         printf("DNI: %ld\n", emp.dni);
        printf("Nombre: %s\n", emp.apyn);
        printf("Categoria: %c\n", emp.categoria);
        printf("Fecha: %02d/%02d/%04d\n",
               emp.fecIngreso.dia,
               emp.fecIngreso.mes,
               emp.fecIngreso.anio);
        printf("Sueldo: %.2f\n", emp.sueldo);
        printf("\n----------------------------\n");
    }

}
/**                                   ARCHIVOS BINARIO                                    */

void convertir_Archivotxt_Long_fija_A_Binario(const char *archivotxt, const char *archivobin)
{
    FILE *ft=fopen(archivotxt,"rt");
    if(!ft)
    {
        printf("Error al abrir archivo de texto");
        exit(1);
    }

    FILE *fb=fopen(archivobin,"wb");
    if(!fb)
    {
        printf("Error al abrir archivo binario modo escritura");
        fclose(ft);
        exit(1);
    }

    tEmpleado emp;
    char cad[100];
    while(fgets(cad,sizeof(cad),ft))
    {
        trozar_Campo_longitud_Fija(&emp,cad);
        fwrite(&emp,sizeof(tEmpleado),1,fb);
    }
    fclose(fb);
    fclose(ft);
}

void leer_Archivo_binario(const char *archivo)
{
    FILE *fp=fopen(archivo,"rb");
    if(!fp)
    {
        printf("Error al abrir el archivo");
        exit(1);
    }
    tEmpleado emp;

    fread(&emp,sizeof(tEmpleado),1,fp);
    while(!feof(fp))
    {
      printf("DNI: %ld\n", emp.dni);
        printf("Nombre: %s\n", emp.apyn);
        printf("Categoria: %c\n", emp.categoria);
        printf("Fecha: %02d/%02d/%04d\n",
               emp.fecIngreso.dia,
               emp.fecIngreso.mes,
               emp.fecIngreso.anio);
        printf("Sueldo: %.2f\n", emp.sueldo);
        printf("\n----------------------------\n");
        fread(&emp,sizeof(tEmpleado),1,fp);
    }
    fclose(fp);

}
