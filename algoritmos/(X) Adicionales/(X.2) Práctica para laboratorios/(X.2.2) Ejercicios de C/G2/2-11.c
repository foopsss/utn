/* Escribir un algoritmo que cargue un arreglo de 100 elementos aleatoriamente,
lo ordene de menor a mayor y muestre por pantalla el arreglo ordenado. */

/* NOTA: esta resolución no utiliza la función dispoible en functions.h para
ordenar arreglos con la finalida de no hacer "trampa". */

#include <stdio.h>

#include "../functions.h"

void ordenar_arreglo_insercion(int* arr, size_t arr_size) {
    /* Esto ordena de menor a mayor, como pide la consigna. */
    /* Se utiliza el método de inserción directa, aunque no exactamente
       como se lo enseña en AED, ya que en esta resolución la primera parte
       de la condición en el "while" es "ind_menor >= 0", mientras que
       apegarse al algoritmo mostrando en la materia implicaría que se
       escriba "ind_menor > 0", pero así nunca se va a procesar el
       primer elemento del arreglo. */
    int resg_arr, ind_menor;

    for (size_t i = 0; i < arr_size; i++) {
        resg_arr = arr[i];
        ind_menor = i - 1;

        while (ind_menor >= 0 && resg_arr < arr[ind_menor]) {
            arr[ind_menor + 1] = arr[ind_menor];
            ind_menor = ind_menor - 1;
        }

        arr[ind_menor + 1] = resg_arr;
    }
}

int main(void) {
    const size_t arr_size = 100;
    const int low_lim = -100, upp_lim = 100;
    int arr[arr_size];

    cargar_arreglo_enteros(arr, arr_size, low_lim, upp_lim);
    printf("Valores del arreglo: \n");
    mostrar_arreglo_enteros(arr, arr_size);
    printf("\n");

    ordenar_arreglo_insercion(arr, arr_size);
    printf("Valores del arreglo ordenado: \n");
    mostrar_arreglo_enteros(arr, arr_size);
    printf("\n");

    return 0;
}
