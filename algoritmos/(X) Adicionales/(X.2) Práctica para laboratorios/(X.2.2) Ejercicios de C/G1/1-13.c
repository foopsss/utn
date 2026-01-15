/* Generar un algoritmo que tome 3 números enteros distintos y devuelva cuál es
el más grande, cuál es el más pequeño y cuál se encuentra entre estos dos. */

#include <stdio.h>

int main(void) {
    int num_a, num_b, num_c, mas_gr, mas_peq, med;

    printf("Introduzca un número A: ");
    scanf("%d", &num_a);

    printf("Introduzca un número B: ");
    scanf("%d", &num_b);

    printf("Introduzca un número C: ");
    scanf("%d", &num_c);

    if (num_a == num_b && num_b == num_c) {
        printf("¡Los tres números coinciden!\n");
    } else {
        if (num_a >= num_b && num_a >= num_c) {
            mas_gr = num_a;

            if (num_b > num_c) {
                mas_peq = num_c;
                med = num_b;
            } else if (num_c > num_b) {
                mas_peq = num_b;
                med = num_c;
            } else {
                mas_peq = num_b;
                med = mas_peq;
            }
        } else if (num_b >= num_a && num_b >= num_c) {
            mas_gr = num_b;

            if (num_a > num_c) {
                mas_peq = num_c;
                med = num_a;
            } else if (num_c > num_a) {
                mas_peq = num_a;
                med = num_c;
            } else {
                mas_peq = num_a;
                med = mas_peq;
            }
        } else if (num_c >= num_a && num_c >= num_b) {
            mas_gr = num_c;

            if (num_a > num_b) {
                mas_peq = num_b;
                med = num_a;
            } else if (num_b > num_a) {
                mas_peq = num_a;
                med = num_b;
            } else {
                mas_peq = num_a;
                med = mas_peq;
            }
        }

        printf("\n");
        if (mas_gr != med && med != mas_peq) {
            printf("El número más grande es: %d\n", mas_gr);
            printf("El número más pequeño es: %d\n", mas_peq);
            printf("Entre ellos se encuentra el número: %d\n", med);
        } else if (mas_gr == med && med != mas_peq) {
            printf("¡El número más grande y el mediano coinciden! Valor: %d\n",
                   mas_gr);
            printf("El número más pequeño es: %d\n", mas_peq);
        } else if (mas_gr != med && med == mas_peq) {
            printf(
                "¡El número más pequeño y el mediano coinciden! Valor: %d\n",
                med);
            printf("El número más grande es: %d\n", mas_gr);
        }
    }

    return 0;
}
