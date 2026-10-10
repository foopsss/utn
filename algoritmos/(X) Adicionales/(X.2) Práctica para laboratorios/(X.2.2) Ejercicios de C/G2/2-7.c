/* Crear una función que compare dos arreglos de 10 posiciones y verifique si
ambos son iguales. Al igual que en el caso anterior, la función debe devolver
1 (verdadero) si los arreglos son iguales y 0 (falso) en caso de que no lo
sean. */

#include <stdio.h>

#include "../functions.h"

int verificar_igualdad_arreglos(const int* prim_vec, const int* seg_vec,
                                const size_t shared_vec_size) {
    for (size_t i = 0; i < shared_vec_size; i++) {
        if (prim_vec[i] != seg_vec[i]) {
            return 0;
        }
    }
    return 1;
}

void evaluar_resultado(const int result) {
    if (result == 1) {
        printf("(los arreglos son iguales)\n");
    } else {
        printf("(los arreglos son distintos)\n");
    }
}

int main(void) {
    const size_t vec_size = 10;
    const int lim_inf = 0, lim_sup = 100;
    int prim_vec[vec_size], seg_vec[vec_size], result;

    // Es posible que en plataformas distintas de Windows y Linux
    // los arreglos cargados tengan exactamente los mismos valores,
    // debido a que generar números aleatorios cuando se usa el
    // tiempo como semilla no es el mejor método para dicho fin.
    cargar_vector_enteros_aleatorios(prim_vec, vec_size, lim_inf, lim_sup);
    cargar_vector_enteros_aleatorios(seg_vec, vec_size, lim_inf, lim_sup);

    printf("Primer arreglo generado por la computadora: \n");
    mostrar_vector_enteros(prim_vec, vec_size);
    printf("\nSegundo arreglo generado por la computadora: \n");
    mostrar_vector_enteros(seg_vec, vec_size);

    result = verificar_igualdad_arreglos(prim_vec, seg_vec, vec_size);
    printf("\nEl resultado de la comparación es: %d ", result);
    evaluar_resultado(result);

    for (size_t i = 0; i < vec_size; i++) {
        seg_vec[i] = prim_vec[i];
    }

    printf("\nRedefinición del segundo arreglo: \n");
    mostrar_vector_enteros(seg_vec, vec_size);

    result = verificar_igualdad_arreglos(prim_vec, seg_vec, vec_size);
    printf("\nEl resultado de la comparación es: %d ", result);
    evaluar_resultado(result);

    return 0;
}
