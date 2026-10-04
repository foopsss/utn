/* Modificar la función de carga creada en el ejercicio anterior para cargar el
arreglo de forma aleatoria, con números que vayan del 1 al 100. */

#include "../functions.h"

int main(void) {
    const size_t arr_size = 10;
    const int low_lim = 1, upp_lim = 100;
    int arr_ent[arr_size];

    cargar_vector_enteros_aleatorios(arr_ent, arr_size, low_lim, upp_lim);
    mostrar_vector_enteros(arr_ent, arr_size);
    return 0;
}
