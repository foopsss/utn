/* Generar un algoritmo que diga si un número es primo. */

#include <stdbool.h>
#include <stdio.h>

int main(void) {
    int num_us;
    bool es_primo = true;

    printf("Introduzca un número: ");
    scanf("%d", &num_us);

    for (int i = 2; i <= (num_us - 1); i++) {
        if (num_us % i == 0) {
            es_primo = false;
            break;
        }
    }

    if (es_primo) {
        printf("El número es primo.\n");
    } else {
        printf("El número NO es primo.\n");
    }

    return 0;
}
