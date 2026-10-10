/* Generar un algoritmo que calcule el resultado de la división entera y el
resto de la función A/B (siendo A y B números enteros), ocupando únicamente la
operación resta. */

#include <stdio.h>

int main(void) {
    int num_a, num_b, div_ent = 0;

    printf("Introduzca un número A: ");
    scanf("%d", &num_a);

    printf("Introduzca un número B: ");
    scanf("%d", &num_b);

    while (num_a != 0 && num_a >= num_b) {
        div_ent += 1;
        num_a -= num_b;
    }

    printf("Resultado de la división entera: %d\n", div_ent);
    printf("Resto de la operación: %d\n", num_a);
    
    return 0;
}
