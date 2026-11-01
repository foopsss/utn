/* Escribir un algoritmo que permita al usuario ingresar una cantidad indeter-
minada de números enteros (la condición de fin es que el número ingresado sea
0 o un número menor a 0) y, al finalizar, muestre por pantalla los 5 números
más grandes que ingresó el usuario. */

#include <stdio.h>
#include <stdlib.h>

#include "../functions.h"

typedef struct Nodo {
    int num;
    struct Nodo* prox;
} Nodo;

Nodo* crear_nodo(const int num) {
    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));

    if (nuevo == NULL) {
        fprintf(stderr, "No se pudo reservar memoria para un nodo.\n");
        exit(EXIT_FAILURE);
    }

    nuevo->num = num;
    nuevo->prox = NULL;
    return nuevo;
}

void limpiar_lista(Nodo* prim) {
    Nodo* aux = NULL;
    while (prim != NULL) {
        aux = prim;
        prim = prim->prox;
        free(aux);
    }
}

int main(void) {
    const char line_symbol = '=';
    Nodo* prim = NULL;
    Nodo* ventana = NULL;
    Nodo* aux = NULL;
    Nodo* nuevo = NULL;
    size_t long_list = 0, pos_lista = 0;

    printf("Introduzca un número por favor.\n");
    printf("Para salir, introduzca 0, o un número menor.\n");
    printf("\n");
    printf("Número: ");
    int num_us = obtener_entero_usuario();

    if (num_us <= 0) {
        printf(
            "La ejecución del programa ha sido abortada sin introducir "
            "números.");
        return 1;
    }

    while (num_us > 0) {
        nuevo = crear_nodo(num_us);
        ventana = prim;

        while (ventana != NULL && ventana->num < num_us) {
            aux = ventana;
            ventana = ventana->prox;
        }

        if (aux == NULL) {
            nuevo->prox = prim;
            prim = nuevo;
        } else {
            aux->prox = nuevo;
            nuevo->prox = ventana;
        }

        long_list++;
        aux = NULL;

        printf("Introduzca otro número: ");
        num_us = obtener_entero_usuario();
    }

    printf("\n");
    imprimir_string_subrayado(line_symbol, "5 valores más grandes");

    ventana = prim;
    while (ventana != NULL) {
        if (pos_lista >= (long_list - 5)) {
            printf("Valor: %d en posición %zu.\n", ventana->num, pos_lista);
        }
        ventana = ventana->prox;
        pos_lista++;
    }

    limpiar_lista(prim);

    return 0;
}
