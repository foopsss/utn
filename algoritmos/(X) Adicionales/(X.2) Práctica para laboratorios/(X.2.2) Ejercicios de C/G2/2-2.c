/* A partir del ejercicio anterior, realizar una función para cargar el arreglo
y otra para mostrarlo por pantalla. */

#include <stdio.h>

#include "../functions.h"

int main(void) {
    const size_t arr_size = 10;
    int arr_ent[arr_size];

    cargar_vector_enteros_usuario(arr_ent, arr_size);
    mostrar_vector_enteros(arr_ent, arr_size);
    return 0;
}
