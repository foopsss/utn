/* Generar un programa que determine cuál es el factorial de un número N dado,
utilizando solo las operaciones de multiplicación, suma y resta. El factorial
se compone por la multiplicación de todos los números desde 1 hasta N. Por
ejemplo: el factorial de 5 es 5 * 4 * 3 * 2 * 1. */

#include <stdio.h>

int main(void) {
    int num_us, fact = 1;

    printf("Introduzca un número: ");
    scanf("%d", &num_us);

    for (int i = 1; i <= num_us; i++) {
        fact *= i;
    }

    printf("Factorial de %d: %d\n", num_us, fact);
    return 0;
}
