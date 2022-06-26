#include <stdio.h>
#include <stdlib.h>
#include "string.h"

#include "Flight.h"
#include "arrayPassenger.h"


int hardcodeFlights(Flight fligths[], int tamFli){
               //   contenedorDestino, tamanio
	int Return = -1;

    //char vuelo[10]; int estado; char descripcion; char destino[20]; char compania[20]; int isEmpty;
	Flight arrayOrigen[6] = {
	    {"AR 1325", "Inactivo", 0},
	    {"AA 931", "Activo", 1},
	    {"LH 510", "Inactivo", 0},
	    {"AF 228", "Activo", 1},
	    {"IB 6841", "Activo", 1},
	    {"BA 247", "Activo", 0},
	};

	if((fligths != NULL) & (tamFli > 0)){
		for(int i = 0; i < tamFli; i++){
			fligths[i] = arrayOrigen[i]; // recorro y swapeo entre vectores contenedores de subvectores estructuras
			Return = 0;
			//fin swap
		}
	}
	return Return;
}


void printFlight(Flight flight){
// recibe 1 vector
	printf("|%-10s   |   %10s|\n",
			flight.flycode,
			flight.status);
}


int printAvailableFlights(Flight flights[], int lenFli){
	// recibe un vec de subvec, tamanio vec a recorrer

	int Return = -1;

	if((flights != NULL) && lenFli > 0)
	{
		printf(" ----  Estado de los vuelos  ---- \n");
		printf(" Codigo vuelo | Estado \n");
		printf("__________________________________________\n");

		for(int i = 0; i < lenFli; i++){
			printFlight(flights[i]);
		}
		Return = 0;
	}
	return Return;
}

int searchFlight(Flight flights[], int lenFli, char fly[], int* pIndex){

    int Return = -1;
    if( flights != NULL && pIndex != NULL && lenFli > 0 )
    {
        *pIndex = -1;
        for(int i=0; i < lenFli; i++)
        {
            if( (strcmp(flights[i].flycode, fly) == 0) )
            {
                *pIndex = i;
                break;
            }
        }
        Return = 0;
    }
    return Return;
}


int validateFlight(Flight flight[], int lenFli, char fly[]){
	int Return = -1;
	int index;

	if ( !searchFlight(flight, lenFli, fly, &index) ){
		if(index != -1){
			Return = 0;
		}
	}
	return Return;
}


int loadDescriptionStatusFlight(Flight flights[], int lenFli, int id, char status[]){

	int Return = -1;
    if(flights != NULL && lenFli > 0 && status != NULL){

         for(int i= 0; i < lenFli; i++){

            if( flights[i].statusFlight == id){
                strcpy( status, flights[i].status);
                Return = 0;
                break;
            }
         }
    }
    return Return;
}






