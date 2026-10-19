/* Realizar un algoritmo que identifique si un número es palíndromo. Un número
es palíndromo cuando es igual a su inverso. Ejemplo: 3223. */

#include <stdio.h>

#include "../functions.h"

int main(void) {
    int num_us, copia, inv = 0;

    printf("Introduzca un número: ");
    num_us = obtener_entero_usuario();
    copia = num_us;

    while (copia != 0) {
        inv = inv * 10;
        inv = inv + copia % 10;
        copia = copia / 10;
    }

    // Descomentar esto para ver los valores de las variables
    // al final del proceso.
    // printf("Valor de la variable 'num_us': %d\n", num_us);
    // printf("Valor de la variable 'copia': %d\n", copia);
    // printf("Valor de la variable 'inv': %d\n", inv);

    if (inv == num_us) {
        printf("El número es palíndromo.\n");
    } else {
        printf("El número NO es palíndromo.\n");
    }

    return 0;
}
