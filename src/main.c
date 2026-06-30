#include <stdio.h>
#include <stdlib.h>
#include "ArreglosDinamicos.h"

//funcion principal
int main() {
    int tamano;
    printf("Ingrese el tamano del arreglo: ");
    scanf("%d", &tamano);

    //crear arreglo con memoria dinamica
    int* arreglo = crearArreglo(tamano);

    //agregar elementos al arreglo
    for (int i = 0; i < tamano; i++) {
        int elemento;
        printf("Ingrese el elemento %d: ", i + 1);
        scanf("%d", &elemento);
        agregarElemento(arreglo, tamano, elemento);
    }

    //imprimir el arreglo
    imprimirArreglo(arreglo, tamano);

    //eliminar un elemento del arreglo
    int elementoEliminar;
    printf("Ingrese el elemento a eliminar: ");
    scanf("%d", &elementoEliminar);
    eliminarElemento(arreglo, tamano, elementoEliminar);

    //imprimir el arreglo despues de eliminar el elemento
    imprimirArreglo(arreglo, tamano);

    //obtener un elemento por indice
    int indice;
    printf("Ingrese el indice del elemento a obtener: ");
    scanf("%d", &indice);
    int elementoObtenido = obtenerElemento(arreglo, tamano, indice);
    printf("Elemento en el indice %d: %d\n", indice, elementoObtenido);

   
    free(arreglo); // liberar memoria del arreglo
    return 0;
}