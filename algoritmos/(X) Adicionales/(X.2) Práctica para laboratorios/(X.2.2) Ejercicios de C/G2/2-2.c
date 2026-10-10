/* A partir del ejercicio anterior, realizar una función para cargar el arreglo
y otra para mostrarlo por pantalla. */

#include "../functions.h"

int main(void) {
    const size_t vec_size = 10;
    int vec[vec_size];

    cargar_vector_enteros_usuario(vec, vec_size);
    mostrar_vector_enteros(vec, vec_size);

    return 0;
}
