/* Realizar un algoritmo que verifique si un número es par o impar. Utilizar el
operador "?" en el algoritmo. */

// Material para este ejercicio:
// https://www.geeksforgeeks.org/conditional-or-ternary-operator-in-c/

#include <stdio.h>

int main(void) {
    int num_us;

    printf("Introduzca un número: ");
    scanf("%d", &num_us);

    // También se podría acomodar la expresión de la siguiente forma:
    // (num_us % 2 == 0) ? printf("El número es par.\n") : printf("El número NO
    // es par.\n");
    (num_us % 2 == 0) ? printf("El número es par.\n")
                      : printf("El número NO es par.\n");

    return 0;
}
