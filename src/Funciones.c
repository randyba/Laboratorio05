/*
funciones.c
IE-0117 Laboratorio 05

los camibios y manejo de la logica de las funciones se manejan en este archivo.
*/
#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"

//funcion para crear un arreglo con memoria dinamica
int* crearArreglo(int tamano) {
    int* arreglo = (int*)malloc(tamano * sizeof(int));
    if (arreglo == NULL) {
        printf("Error al asignar memoria.\n");
        exit(1);
    }
    return arreglo;

    //liberar memoria
    free(arreglo);
}

//funcion para agregar un elemento al arreglo
void agregarElemento(int* arreglo, int tamano, int elemento) {
    for (int i = 0; i < tamano; i++) {
        if (*arreglo == 0) { // logica con punteros 
            *arreglo = elemento;
            return;
        }
    }
    printf("No hay espacio disponible para agregar el elemento.\n");
}

//funcion para eliminar un elemento del arreglo
void eliminarElemento(int* arreglo, int tamano, int elemento) {
    for (int i = 0; i < tamano; i++) {
        if (*(arreglo + i) == elemento) { // logica con punteros 
            *(arreglo + i) = 0; // se elimina el elemento estableciendo su valor a 0
            return;
        }
    }
    printf("El elemento no se encuentra en el arreglo.\n");
}

//funcion para obtener elemento por indice 
int obtenerElemento(int* arreglo, int tamano, int indice) {
    if (indice < 0 || indice >= tamano) {
        printf("Indice fuera de rango.\n");
        exit(1);
    }
    return *(arreglo + indice); // logica con punteros 
}

//funcion para imprimir el arreglo
void imprimirArreglo(int* arreglo, int tamano) {
    printf("Arreglo: ");
    for (int i = 0; i < tamano; i++) {
        printf("%d ", *(arreglo + i)); // logica con punteros 
    }
    printf("\n");
}
