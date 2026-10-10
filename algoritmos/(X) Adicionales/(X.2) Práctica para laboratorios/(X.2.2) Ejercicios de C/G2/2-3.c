/* Modificar la función de carga creada en el ejercicio anterior para cargar el
arreglo de forma aleatoria, con números que vayan del 1 al 100. */

#include "../functions.h"

int main(void) {
    const size_t vec_size = 10;
    const int lim_inf = 1, lim_sup = 100;
    int vec[vec_size];

    cargar_vector_enteros_aleatorios(vec, vec_size, lim_inf, lim_sup);
    mostrar_vector_enteros(vec, vec_size);

    return 0;
}
