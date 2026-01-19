/* Modificar la función de carga creada en el ejercicio anterior para cargar el
arreglo de forma aleatoria, con números que vayan del 1 al 100. */

// NOTA: la función de carga modificada es cargar_arreglo_enteros() y se
// encuentra definida en la librería "functions.h" para que pueda ser utilizada
// por otras funciones también.

#include "../functions.h"

int main(void) {
    const size_t arr_size = 10;
    const int low_lim = 1;
    const int upp_lim = 100;

    int arr_ent[arr_size];
    cargar_arreglo_enteros(arr_ent, arr_size, low_lim, upp_lim);
    mostrar_arreglo_enteros(arr_ent, arr_size);
    return 0;
}
