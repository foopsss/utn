/* Realizar un algoritmo que cargue un arreglo de 10 enteros y lo muestre por
pantalla. */

#include <stdio.h>

#include "../functions.h"

int main(void) {
    const size_t arr_size = 10;
    int arr_ent[arr_size];

    cargar_vector_enteros_usuario(arr_ent, arr_size);
    printf("\n");
    printf("Valores del arreglo: \n");
    mostrar_vector_enteros(arr_ent, arr_size);

    return 0;
}
