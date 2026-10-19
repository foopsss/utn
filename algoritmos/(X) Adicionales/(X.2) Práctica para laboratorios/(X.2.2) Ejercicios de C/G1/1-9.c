/* Generar un programa que determine cuál es el factorial de un número N dado,
utilizando solo las operaciones de multiplicación, suma y resta. El factorial
se compone por la multiplicación de todos los números desde 1 hasta N. Por
ejemplo: el factorial de 5 es 5 * 4 * 3 * 2 * 1. */

#include <stdint.h>
#include <stdio.h>

#include "../functions.h"

int main(void) {
    int input_us;
    unsigned int num_us;
    uintmax_t fact = 1;

    printf("Introduzca un número: ");
    input_us = obtener_entero_usuario();

    while (input_us < 0) {
        printf("Introduzca un número positivo: ");
        input_us = obtener_entero_usuario();
    }

    num_us = (unsigned)input_us;

    for (uintmax_t i = 1; i <= num_us; i++) {
        fact *= i;
    }

    printf("Factorial de %u: %ju\n", num_us, fact);

    return 0;
}
