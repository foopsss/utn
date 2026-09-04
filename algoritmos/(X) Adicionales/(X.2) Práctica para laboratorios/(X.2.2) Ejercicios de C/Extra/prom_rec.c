// Este algoritmo presenta una función recursiva que permite calcular un
// promedio para un arreglo de 26 elementos. A continuación, adjunto el
// seudocódigo que pensé para plantear la función recursiva:

/*
Función Promedio(
    arr: arreglo de [1..26] de entero,
    num_jug: entero,
    suma_edades: entero
): entero ES
    Si num_jug < 27 Entonces
      Promedio := Promedio(arr, num_jug + 1, suma_edades + arr[num_jug])
    Contrario
      Promedio := suma_edades DIV (num_jug - 1)
    Fin Si
Fin Función
*/

#include <stdio.h>

int promedio(int arr[26], int num_jug, int suma_edades) {
    if (num_jug < 26) {
        promedio(arr, num_jug + 1, suma_edades + arr[num_jug]);
    } else {
        printf("Valor de num_jug: %d\n", num_jug);
        printf("Valor de la variable suma_edades: %d\n", suma_edades);
        return suma_edades / (num_jug - 1);
    }
}

int main() {
    int edades[26];
    int i, prom, suma_val;

    suma_val = 0;

    for (i = 0; i < 26; i++) {
        edades[i] = 25;
        suma_val += edades[i];
    }

    prom = promedio(edades, 0, 0);
    printf("Valor de la variable suma_val: %d\n", suma_val);
    printf("Valor de la variable prom: %d", prom);
}
