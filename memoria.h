#ifndef MEMORIA_H_INCLUDED
#define MEMORIA_H_INCLUDED
#include"arch_txt.h"

typedef struct
{
    void*vec;
    size_t ce;
    size_t tam;
    size_t tam_elem;
}tMemoria;

bool crear_memoria(tMemoria *vec,size_t tam,size_t tam_Elem);
bool asignar_memoria(tMemoria *vec,size_t tam_Elem);
bool destruir_memoria(tMemoria *vec);

#endif // MEMORIA_H_INCLUDED
