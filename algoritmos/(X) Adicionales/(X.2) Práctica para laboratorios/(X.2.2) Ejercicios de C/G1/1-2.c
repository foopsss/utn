/* Escribir un programa en C que, dado dos números enteros, realice la suma,
resta, multiplicación, división entera y resto de los mismos. Los números
deben ser ingresados por el usuario. */

#include <stdio.h>

#include "../functions.h"

int main() {
    int x, y;

    printf("Ingrese un valor para X: ");
    x = obtener_entero_usuario();
    printf("Ingrese un valor para Y: ");
    y = obtener_entero_usuario();

    int suma = x + y;
    int resta = x - y;
    int mult = x * y;
    int div_ent = x / y;
    int resto = x % y;

    printf("\n");
    printf("Valor de X: %d\n", x);
    printf("Valor de Y: %d\n", y);

    printf("\n");
    printf("Resultado de la suma: %d\n", suma);
    printf("Resultado de la resta: %d\n", resta);
    printf("Resultado de la multiplicación: %d\n", mult);
    printf("Resultado de la división entera: %d\n", div_ent);
    printf("Resultado del resto: %d\n", resto);

    return 0;
}
