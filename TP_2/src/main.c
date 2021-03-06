#include <stdio.h>
#include <stdlib.h>
#include "string.h"

#include "Flight.h"
#include "ArrayPassenger.h"
#include "options.h"

#define TAMFLI 6
#define TAMTYPE 3
#define TAMPASS 2001

// hardcodeo de structs Flight y TypePassenger
Flight flights[TAMFLI] =
{
		{"UA 818", "Demorado", 1},
		{"BA 4254", "Activo", 2},
		{"QR 6974", "Cancelado", 0},
		{"ET 507", "Activo", 2},
		{"AR 1370", "Demorado", 1},
		{"LA 478", "Activo", 2},
};

TypePassenger types[TAMTYPE]=
{
		{0 , "Turista"},
		{1, "Premium"},
		{2, "Ejecutiva"}
};
// fin de datos Hardcodeados


int main(void) {

	setbuf(stdout, NULL);

	int retornoBuffer;
	int flagIsNotEmpty = 0;
	int salir = 0;
	int id = 1;
	char name[51];
	char lastName[51];
	float price = 0;
	char flyCode[10];
	int typePassenger = 0;

	// variable para informe de precios y promedio
	float acumulador =0;
	int contador = 0;
	float promedio = 0;
	int pasajeros = 0;

	Passenger list[TAMPASS];
	initPassengers(list, TAMPASS);
	//hardcodePassengers(list, &id, 10, &flagIsNotEmpty);

	do
	{
		system("cls");
		switch(optionMenu())
		{
		case 1: //Alta
			retornoBuffer = addPassenger(list, TAMPASS, &id, name, lastName, price, typePassenger,
														flyCode, flights, TAMFLI, types, TAMTYPE);
			if(retornoBuffer == 0)
			{
				flagIsNotEmpty = 1;
				retornoBuffer = -1;
			}else{
				printf("Se ha producido un error, reintente nuevamente");
			}
			system("pause");
			break;

		case 2: //Modificar
			if(flagIsNotEmpty)
			{
				retornoBuffer = modifyPassenger(list, TAMPASS, flights, TAMFLI, types, TAMTYPE);
				if(retornoBuffer == 0)
				{
					retornoBuffer = -1; // seteo retornoBuffer en "error" para ser evaluado en otra funcion
					printf("\n -> Modificacion de pasajero realizada correctamente \n\n");
				}else{
					printf("Se ha producido un error, reintente nuevamente");
				}
			}
			else{
				printf("Opcion no disponible, no hay pasajeros registrados en el sistema\n");
			}
			system("pause");
			break;

		case 3: // Baja
			if(flagIsNotEmpty)
			{
				retornoBuffer = removePassenger(list, TAMPASS, id, types, TAMTYPE, flights, TAMFLI);
				if(retornoBuffer == 0)
				{
					retornoBuffer = -1; // seteo retornoBuffer en "error" para ser evaluado en otra funcion
					listIsNotEmpty(list, TAMPASS, &flagIsNotEmpty);
				}else{
					printf("Se ha producido un error, reintente nuevamente\n");
				}
			}
			else{
				printf("Opcion no disponible, no hay pasajeros registrados en el sistema\n");
			}
			system("pause");
			break;

		case 4: // informes
			if(flagIsNotEmpty)
			{
				switch(optionInformes())
				{
				case 1:
					retornoBuffer = optionInformesSubMenu2();
					if(retornoBuffer == 0 || retornoBuffer == 1)
					{
						sortPassengers(list, TAMPASS, retornoBuffer);
						printPassengers(list, TAMPASS, types, TAMTYPE, flights, TAMFLI);
						retornoBuffer = -1;
					}
					break;

				case 2:
					retornoBuffer = acumuladorPrecios(list, TAMPASS, &acumulador, &contador);
					if(retornoBuffer == 0)
					{
						retornoBuffer = promedioPrecios(&promedio, acumulador, contador);
						if(retornoBuffer == 0)
						{
							retornoBuffer = pasajerosSuperanProm(list, TAMPASS, &pasajeros, promedio);
							if(retornoBuffer == 0)
							{
								system("cls");
								printf("\nPrecio total de pasajes: $%.2f\n\n", acumulador);
								printf("Precio promedio: $%.2f\n\n", promedio);
								printf("Pasajeros que superan el promedio: %d\n\n", pasajeros);
							}
							else
							{
								printf("Se ha producido un error [003], reintente nuevamente\n");
							}
						}
						else
						{
							printf("Se ha producido un error [002], reintente nuevamente\n");
						}
					}
					else
					{
						printf("Se ha producido un error [001], reintente nuevamente\n");
					}
					break;

				case 3:
					retornoBuffer = optionInformesSubMenu3();
					if(retornoBuffer == 0 || retornoBuffer == 1)
					{
						sortPassengersByCode(list, TAMPASS, retornoBuffer);
						printPassengers(list, TAMPASS, types, TAMTYPE, flights, TAMFLI);
						retornoBuffer = -1;
					}
					break;
				}
			}
			else {
				printf("Opcion no disponible, no hay pasajeros registrados en el sistema\n");
			}
			system("pause");
			break;

		case 5:
			salir = 1;
			break;

		}

	}while(salir != 1);

	return EXIT_SUCCESS;
}
