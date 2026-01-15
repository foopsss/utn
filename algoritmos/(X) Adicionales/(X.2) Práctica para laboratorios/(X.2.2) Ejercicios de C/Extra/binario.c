// Este algoritmo presenta una función recursiva que, dado un número binario,
// permite calcular si se cumple el patrón de que el número esté compuesto por
// una serie de repeticiones del número 10, como 10101010.

#include <stdbool.h>
#include <stdio.h>

bool cumple_patron(long int entrada) {
    // Descomentar esto si se quiere ver
    // qué hace la función.
    // printf("%ld\n", entrada);

    if (entrada == 0) {
        return false;
    }

    // Mi código binario es 10 u 11.
    if (entrada % 100 == entrada) {
        if (entrada % 100 != 10) {
            return false;
        } else {
            return true;
        }
    }

    if (entrada % 100 != entrada) {
        if (entrada % 100 != 10) {
            return false;
        } else {
            cumple_patron(entrada / 100);
        }
    }
}

int main() {
    // Combinaciones que se pueden probar
    // para ver si la función falla:
    // (*) 1110101010.
    // (*) 1010111010.
    // (*) 1010101011.
    long int numero = 1010101011;
    long int numero2 = 1010101010;

    if (cumple_patron(numero)) {
        printf("El número %ld cumple con el patrón.\n", numero);
    } else {
        printf("El número %ld NO cumple con el patrón.\n", numero);
    }

    printf("--------------------------------------------------\n");

    if (cumple_patron(numero2)) {
        printf("El número %ld cumple con el patrón.\n", numero2);
    } else {
        printf("El número %ld NO cumple con el patrón.\n", numero2);
    }

    return 0;
}
