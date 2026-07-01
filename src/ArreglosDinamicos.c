/*
ArreglosDinamicos.c
IE-0117 Laboratorio 05

Los cambios y manejo de la logica de las funciones se manejan en este archivo.
*/

#include <stdio.h>
#include <stdlib.h>
#include "ArreglosDinamicos.h"

// Funcion para crear un arreglo con memoria dinamica
int* crearArreglo(int tamano) {
    int* arreglo = calloc(tamano, sizeof(int));

    if (arreglo == NULL) {
        printf("Error al asignar memoria.\n");
        exit(1);
    }

    return arreglo;
}


//funcion para agregar un elemento al arreglo
void agregarElemento(int* arreglo, int tamano, int elemento) {
    for (int i = 0; i < tamano; i++) {
        if (*(arreglo + i) == 0) { // logica con punteros 
            *(arreglo + i) = elemento;
            return;
        }
    }
}

// Funcion para eliminar un elemento del arreglo
void eliminarElemento(int* arreglo, int tamano, int elemento) {
    for (int i = 0; i < tamano; i++) {
        if (arreglo[i] == elemento) {
            arreglo[i] = 0;
            return;
        }
    }

    printf("El elemento no se encuentra en el arreglo.\n");
}

// Funcion para obtener elemento por indice
int obtenerElemento(int* arreglo, int tamano, int indice) {
    if (indice < 0 || indice >= tamano) {
        printf("Indice fuera de rango.\n");
        exit(1);
    }

    return arreglo[indice];
}

// Funcion para imprimir el arreglo
void imprimirArreglo(int* arreglo, int tamano) {
    printf("Arreglo: ");

    for (int i = 0; i < tamano; i++) {
        printf("%d ", *(arreglo + i)); // imprime el elemento en la posicion del arrrglo.
    }

    printf("\n");
}
