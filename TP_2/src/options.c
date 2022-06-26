#include <stdio.h>
#include <stdlib.h>
#include "options.h"

int optionMenu() {

    int opcion;

    printf("     *** Administracion de Pasajeros ***\n\n");
    printf("1. Alta\n");
    printf("2. Modificar\n");
    printf("3. Baja\n");
    printf("4. Informes\n");
    printf("\n5. Salir\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

int optionModifyPassenger() {

    int opcion;

    printf("\n\n     *** Campo a modificar ***\n\n");
    printf("1. Nombre\n");
    printf("2. Apellido\n");
    printf("3. Precio\n");
    printf("4. Codigo de Vuelo\n");
    printf("5. Tipo de Pasajero\n");
    printf("6. Volver al menu anterior\n");
    printf("\nIngrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}


int optionInformes() {

    int opcion;
    system("cls");
    printf("     *** Informes varios ***\n\n");
    printf("1. Pasajeros ordenados por Apellido y Tipo de pasajero\n");
    printf("2. Total y promedio de los precios de los pasajes\n");
    printf("3. Listado de los pasajeros por Codigo de vuelo y estados de vuelos\n");
    printf("\n4. Volver al menu anterior\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

int optionInformesSubMenu2() {

    int opcion;
    system("cls");
    printf(" *** Listado de los pasajeros ordenados por Apellido y Tipo de pasajero ***\n\n");
    printf("0. Listar en orden descendente\n");
    printf("1. Listar en orden ascendente\n");
    printf("\n2. Volver al menu anterior\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

int optionInformesSubMenu3() {

    int opcion;
    system("cls");
    printf(" *** Listado de los pasajeros por Código de vuelo y estados de vuelos ***\n\n");
    printf("0. Listar en orden descendente\n");
    printf("1. Listar en orden ascendente\n");
    printf("\n2. Volver al menu anterior\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}
