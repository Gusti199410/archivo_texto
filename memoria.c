#include"memoria.h"
bool crear_memoria(tMemoria *vec,size_t tam,size_t tam_Elem)
{
    vec->vec=malloc(tam*tam_Elem);
    if(!vec->vec)
    {
        printf("Error al asignar memoria");
        return false;
    }
    vec->tam=tam;
    vec->ce=0;
    vec->tam_elem=tam_Elem;
    return true;
}

bool asignar_memoria(tMemoria *vec,size_t tam_Elem)
{

    size_t nuevo_tamanio=vec->tam*2;
    void *aux=realloc(vec->vec,nuevo_tamanio*tam_Elem);
    if(!aux)
    {
        printf("Error al asignar memoria");
        return false;
    }
    vec->vec=aux;
    vec->tam=nuevo_tamanio;
    return true;
}

bool destruir_memoria(tMemoria *vec)
{
    free(vec->vec);
    vec->vec=NULL;
    vec->ce=0;
    vec->tam=0;
    vec->tam_elem=0;
    return true;
}
