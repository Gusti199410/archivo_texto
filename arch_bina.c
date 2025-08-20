#include"modi_bina.h"

bool modificar_Archivo_binario(const char * archivo)
{
    FILE *fp=fopen(archivo,"r+b");
    if(!fp)
    {
        printf("Error al abrir el archivo en modo r+b");
        return false;
    }
    tEmpleado emp;
    fread(&emp,sizeof(tEmpleado),1,fp);
    while(!feof(fp))
    {
        if(emp.categoria=='B')
        {
            emp.sueldo*=1.5;
            fseek(fp,-(long)sizeof(tEmpleado),SEEK_CUR);
            fwrite(&emp,sizeof(tEmpleado),1,fp);
            fflush(fp);
        }
        fread(&emp,sizeof(tEmpleado),1,fp);
    }
    fclose(fp);
    return true;
}
