/* Genere un algoritmo que calcule el producto de dos números enteros A y B
utilizando únicamente la operación suma. */

#include <stdio.h>

#include "../functions.h"

int main(void) {
    int num_a, num_b, prod = 0;

    printf("Introduzca un número A: ");
    num_a = obtener_entero_usuario();

    printf("Introduzca un número B: ");
    num_b = obtener_entero_usuario();

    for (int i = 0; i < num_b; i++) {
        prod += num_a;
    }

    printf("Resultado del producto: %d\n", prod);

    return 0;
}
