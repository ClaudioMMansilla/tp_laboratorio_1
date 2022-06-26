#include <stdio.h>
#include <stdlib.h>
#include "string.h"

#include "Flight.h"
#include "TypePassenger.h"

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

typedef struct {
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flycode[10];
	int typePassenger;
	int statusFlight;
	int isEmpty;
}Passenger;

#endif /* ARRAYPASSENGER_H_ */


int hardcodePassengers(Passenger destiny[], int* pNextId, int lenDest, int* flag);


int initPassengers(Passenger* list, int len);


int addPassenger(Passenger* list, int len, int* id, char name[],char lastName[], float price,
		int typePassenger, char flycode[], Flight flights[], int lenFli, TypePassenger type[], int lenType );


int findIndexEmpty(Passenger list[], int len, int* pIndex);

void printPassenger(Passenger list, TypePassenger type[], int lenType, Flight flights[], int lenFli);

int printPassengers(Passenger list[], int len, TypePassenger type[], int lenType, Flight flights[], int lenFli);

int findPassengerById(Passenger* list, int len,int id);

int modifyPassenger(Passenger* list, int len, Flight flights[], int lenFli, TypePassenger type[], int lenType);

int removePassenger(Passenger* list, int len, int id, TypePassenger type[], int lenType, Flight flights[], int lenFli);

int setStatusFlight(Passenger* list, int index, char flyCode[], Flight flights[], int lenFli);

int listIsNotEmpty(Passenger* list, int len, int* flag);

int sortPassengers(Passenger* list, int len, int order);

int sortPassengersByCode(Passenger* list, int len, int order);

int acumuladorPrecios(Passenger* list, int len, float* acumulado, int* contador);

int promedioPrecios(float* promedio, float acumulado, int contador);

int pasajerosSuperanProm(Passenger* list, int len, int* pasajeros, float promedio);


