// Este algoritmo presenta una función recursiva que, dado un código binario,
// permite calcular si se cumple el patrón de que el número esté compuesto por
// una cantidad impar de 1.

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

long int obtener_entero_largo_usuario() {
    long int output;
    int ret_val = scanf("%ld", &output);

    if (ret_val != 1) {
        fprintf(stderr,
                "Se produjo un error al recibir el entero solicitado al "
                "usuario.\n");
        exit(EXIT_FAILURE);
    }

    return output;
}

bool cumple_patron(long int entrada, int cant_uno) {
    // Descomentar esto si se quiere ver
    // qué hace la función.
    // printf("Entrada: %ld\n", entrada);
    // printf("cant_uno: %d\n", cant_uno);

    if (entrada % 10 == entrada) {
        if (entrada == 1) {
            cant_uno += 1;
        }

        if (cant_uno % 2 == 0) {
            return false;
        } else {
            return true;
        }
    } else {
        if (entrada % 10 == 1) {
            return cumple_patron(entrada / 10, cant_uno + 1);
        } else {
            return cumple_patron(entrada / 10, cant_uno);
        }
    }
}

int main() {
    long int binario;

    printf("Introduzca un código binario: ");
    binario = obtener_entero_largo_usuario();

    while (binario < 0) {
        printf("Introduzca un código binario sin números negativos.");
        printf("Código binario: ");
        binario = obtener_entero_largo_usuario();
    }

    if (cumple_patron(binario, 0)) {
        printf("El número cumple con el patrón.\n");
    } else {
        printf("El número NO cumple con el patrón.\n");
    }

    return 0;
}
