
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "ctype.h"

#include "ArrayPassenger.h"
#include "Flight.h"
#include "validaciones.h"
#include "TypePassenger.h"
#include "options.h"


int initPassengers(Passenger* list, int len){

	int Return = -1;

	if((list != NULL) & (len > 0))
	{
		for(int i = 0; i < len; i++)
		{
			list[i].isEmpty = 1; // seteo todos los passengers en empty true
			list[i].id = -1;
			//fin swap
			Return = 0;
		}
	}
	return Return;
}




int addPassenger(Passenger* list, int len, int* id, char name[],char lastName[], float price,
		int typePassenger, char flycode[], Flight flights[], int lenFli, TypePassenger type[], int lenType ) {

    int Return = -1;
    int ReturnAuxiliar = -1;
    int index; // buscar indice libre en el vector contenedor
    char flycodeBuffer[10];
    int typePassengerBuffer;

    Passenger passengerBuffer; // para cargar datos (validados) y luego copiar en el list Passengers

    if( id != NULL && list != NULL  && len > 0 && flights != NULL  && lenFli > 0 && type != NULL  && lenType > 0)
    {
        system("cls");
        printf("    *** Ingreso de nuevo pasajero ***\n\n");
        findIndexEmpty(list, len, &index);
//        printf("index = %d\n", index);
        if(index == -1)
        {
            printf("No hay lugar en el sistema\n");
        }
        else
        {
        	printf("Ingrese nombre: \n");
        	fflush(stdin);
        	gets(name);
        	strlwr(name);
        	name[0] = toupper(name[0]);
        	while(strlen(name) >= 51) // Controlar desbordamiento de "gets" limitando longitud
        	{
        		printf("Error, exceso de caracteres - Ingrese nombre: \n");
        		fflush(stdin);
        		gets(name);
            	strlwr(name);
            	name[0] = toupper(name[0]);
        	}
        	strcpy(passengerBuffer.name, name);
        	printf("\n");


        	printf("Ingrese Apellido: \n");
        	fflush(stdin);
        	gets(lastName);
        	strlwr(lastName);
        	lastName[0] = toupper(lastName[0]);
        	while(strlen(lastName) >= 51) // Controlar desbordamiento de "gets" limitando longitud
        	{
        		printf("Error, exceso de caracteres - Ingrese Apellido: \n");
        		fflush(stdin);
        		gets(lastName);
            	strlwr(lastName);
            	lastName[0] = toupper(lastName[0]);
        	}
        	strcpy(passengerBuffer.lastName, lastName);
        	printf("\n");


            fflush(stdin);
            ReturnAuxiliar = entradaDatos_getNumeroFloat(&price, "Ingrese precio del vuelo: \n", "error", 1.0, 1000000.0);
            if(ReturnAuxiliar == 0)
            {
            	passengerBuffer.price = price;
            }

            printf("\n");
            printAvailableFlights(flights, lenFli);
            printf("\nSeleccione un vuelo (ingrese codigo) : \n");
            fflush(stdin);
            gets(flycodeBuffer);
            strupr(flycodeBuffer);
            while( (validateFlight(flights, len, flycodeBuffer)) !=0 )
            {
                printf("Codigo invalido. Reingrese nuevamente: \n");
                gets(flycodeBuffer);
                strupr(flycodeBuffer);
            }
            strcpy(passengerBuffer.flycode, flycodeBuffer);
            printf("\n");

            printAvailableTypes(type, lenType);
            printf("\nSeleccione tipo de servicio (ingrese codigo) \n");
            scanf("%d", &typePassengerBuffer);
            while( (validateTypePassenger(type, lenType, typePassengerBuffer)) !=0 )
            {
                printf("Codigo invalido. Reingrese nuevamente: \n");
                scanf("%d", &typePassengerBuffer);
            }
            passengerBuffer.typePassenger = typePassengerBuffer;

            // si todos los pasos anteriores estan ok
            passengerBuffer.isEmpty = 0;

            list[index] = passengerBuffer;
            list[index].id = *id;
            setStatusFlight(list, index, flycodeBuffer, flights, lenFli);
            (*id)++;
            Return = 0;

            printf("\n -> Alta de pasajero realizada correctamente \n\n");
//            system("pause");
        }
    }
    return Return;
}




int findIndexEmpty(Passenger list[], int len, int* pIndex){

    int Return = -1;
    if( list != NULL && pIndex != NULL && len > 0)
    {
        *pIndex = -1;
        for(int i=0; i < len; i++)
        {
            if(list[i].isEmpty) // busca en el array de estructuras algun indice libre
            {
                *pIndex = i;
                break;
            }
        }
        Return = 0;
    }
    return Return;
}


void printPassenger(Passenger list, TypePassenger type[], int lenType,
					Flight flights[], int lenFli){
// recibe 1 solo vector por cada llamado

	char descrip[15];
	char status[10];

	loadDescriptionTypePassenger(type, lenType, list.typePassenger, descrip);
	loadDescriptionStatusFlight(flights, lenFli, list.statusFlight, status);

	printf("|%02d  %-10s  %-10s  $%10.2f    %-10s  %-10s  %10s|\n",
			list.id,
			list.name,
			list.lastName,
			list.price,
			list.flycode,
			descrip,
			status
	);

}


int printPassengers(Passenger list[], int len, TypePassenger type[], int lenType,
						Flight flights[], int lenFli){

	int Return = -1;
    if( type != NULL && len > 0 )
    {
    	system("cls");
    	printf("                 ***** Listado de pasajeros registrados ***** \n");
    	printf("-------------------------------------------------------------------------------\n");
    	printf(" ID  Nombre      Apellido       Precio      Codigo      Pasaje         Estado\n");
    	printf("-------------------------------------------------------------------------------\n");

    	for(int i = 0; i < len; i++){
            if( !list[i].isEmpty)
            {
        		printPassenger(list[i], type, lenType, flights, lenFli);
            }
    	}
        printf("_______________________________________________________________________________\n\n");

        Return = 0;
//    	system("pause");
    }
    return Return;
}



int hardcodePassengers(Passenger destiny[], int* pNextId, int lenDest, int* flag){

	int Return = -1;

//	{"UA 818", "Demorado", 1},
//	{"BA 4254", "Activo", 2},
//	{"QR 6974", "Cancelado", 0},
//	{"ET 507", "Activo", 2},
//	{"AR 1370", "Demorado", 1},
//	{"LA 478", "Activo", 2},

	Passenger origin[10] = {
		{0, "Lucas", "Ramirez", 50000.90, "UA 818", 1, 1, 0},
		{0, "Miguel", "Molina", 142500.40, "BA 4254", 2, 2, 0},
		{0, "Juana", "Viale", 138900.90, "QR 6974", 0, 0, 0},
		{0, "Andrea", "Carrizo", 140100.90, "ET 507", 1, 2, 0},
		{0, "Juliana", "Coleman", 77899.40, "AR 1370", 2, 1, 0},
		{0, "Martin",  "Gonzalez", 234800.70, "LA 478", 1, 2, 0},
		{0, "Dardo", "Fusceneco", 67800.20, "QR 6974", 0, 0, 0},
		{0, "Alicia", "Molina", 117800.30, "UA 818", 0, 1, 0},
		{0, "Javier", "Ferrari", 194700.40, "LA 478", 0, 2, 0},
		{0, "Diego", "Molina", 38600.80, "BA 4254", 1, 2, 0}
	};

	if((destiny != NULL) & (pNextId != NULL) & (lenDest > 0)){
		for(int i = 0; i < lenDest; i++){
			destiny[i] = origin[i]; // recorro y swapeo entre vectores contenedores de subvectores estructuras
			destiny[i].id = *pNextId;
			(*pNextId)++;
			*flag = 1;
			Return = 0;
			//fin swap
		}
	}
	return Return;
}


//Busca un pasajero recibiendo como par?metro de b?squeda su Id.
/** \brief find a Passenger by Id en returns the index position in array.*
* \param list Passenger*
* \param len int
* \param id int
* \return Return passenger index position or (-1) if [Invalid length or NULL pointer received or passenger not found]
*
*/
int findPassengerById(Passenger* list, int len,int id) {

    int index = -1;
    if( list != NULL && len > 0 )
    {
        for(int i=0; i < len; i++)
        {
            if(list[i].id == id)
            {
            	index = i;
                break;
            }
        }
    }
    return index;
}


int modifyPassenger(Passenger* list, int len, Flight flights[], int lenFli, TypePassenger type[], int lenType) {

	int Return = -1;
	int ReturnAuxiliar = -1;
	int index; // buscar indice libre en el vector contenedor
	int idBuffer;
	char nameBuffer[51];
	char lastNameBuffer[51];
	float priceBuffer;
	char flycodeBuffer[10];
	int typePassengerBuffer;


	if(list != NULL  && len > 0 && flights != NULL  && lenFli > 0 && type != NULL  && lenType > 0)
	{
		printPassengers(list, len, type, lenType, flights, lenFli);
		printf("\n\n    *** Ingrese ID del pasajero a modificar ***\n\n");
		scanf("%d", &idBuffer);
		index = findPassengerById(list, len, idBuffer);

		if(index == -1)
		{
			printf("Error, se ha ingresado un ID invalido o inexistente\n");
		}
		else
		{
			system("cls");
			printPassenger(list[index], type, lenType, flights, lenFli);

			switch(optionModifyPassenger())
			{
			case 1:
				system("cls");
				printf("Ingrese nombre: \n");
				fflush(stdin);
				gets(nameBuffer);
				strlwr(nameBuffer);
				nameBuffer[0] = toupper(nameBuffer[0]);
				while(strlen(nameBuffer) >= 51) // Controlar desbordamiento de "gets" limitando longitud
				{
					printf("Error, exceso de caracteres - Ingrese nombre: \n");
					fflush(stdin);
					gets(nameBuffer);
					strlwr(nameBuffer);
					nameBuffer[0] = toupper(nameBuffer[0]);
				}
				strcpy(list[index].name, nameBuffer);
				break;

			case 2:
				system("cls");
				printf("Ingrese apellido: \n");
				fflush(stdin);
				gets(lastNameBuffer);
				strlwr(lastNameBuffer);
				lastNameBuffer[0] = toupper(lastNameBuffer[0]);
				while(strlen(lastNameBuffer) >= 51) // Controlar desbordamiento de "gets" limitando longitud
				{
					printf("Error, exceso de caracteres - Ingrese nombre: \n");
					fflush(stdin);
					gets(lastNameBuffer);
					strlwr(lastNameBuffer);
					lastNameBuffer[0] = toupper(lastNameBuffer[0]);
				}
				strcpy(list[index].lastName, lastNameBuffer);
				break;

			case 3:
				system("cls");
				fflush(stdin);
				ReturnAuxiliar = entradaDatos_getNumeroFloat(&priceBuffer, "Ingrese precio del vuelo: \n", "error", 1.0, 1000000.0);
				if(ReturnAuxiliar == 0)
				{
					list[index].price = priceBuffer;
				}
				break;

			case 4:
				system("cls");
				printAvailableFlights(flights, lenFli);
				printf("\nSeleccione un vuelo (ingrese codigo) : \n");
				fflush(stdin);
				gets(flycodeBuffer);
				strupr(flycodeBuffer);
				while( (validateFlight(flights, len, flycodeBuffer)) !=0 )
				{
					printf("Codigo invalido. Reingrese nuevamente: \n");
					gets(flycodeBuffer);
					strupr(flycodeBuffer);
				}
				strcpy(list[index].flycode, flycodeBuffer);
	            setStatusFlight(list, index, flycodeBuffer, flights, lenFli);
				break;

			case 5:
				system("cls");
				printAvailableTypes(type, lenType);
				printf("\nSeleccione tipo de servicio (ingrese codigo) \n");
				scanf("%d", &typePassengerBuffer);
				while( (validateTypePassenger(type, lenType, typePassengerBuffer)) !=0 )
				{
					printf("Codigo invalido. Reingrese nuevamente: \n");
					scanf("%d", &typePassengerBuffer);
				}
				list[index].typePassenger = typePassengerBuffer;
				break;
			}

			Return = 0;

			//            system("pause");
        }
    }
    return Return;
}


int removePassenger(Passenger* list, int len, int id, TypePassenger type[], int lenType, Flight flights[], int lenFli) {

	int Return = -1;
	int index;
	char confirm;

	if(list != NULL  && len > 0)
	{
		printPassengers(list, len, type, lenType, flights, lenFli);
		printf("\n    *** Ingrese ID del pasajero a dar de baja ***\n\n");
		scanf("%d", &id);
		index = findPassengerById(list, len, id);

		if(index == -1 || list[index].isEmpty == 1)
		{
			printf("Error, se ha ingresado un ID invalido o inexistente\n");
		}
		else
		{
			printf("\nConfirma baja? (no se puede deshacer):  S/N\n");
			fflush(stdin);
			scanf("%c", &confirm);

			if(confirm == 'S' || confirm == 's')
			{
				list[index].isEmpty = 1;
				printf("\n-> Baja de pasajero realizada correctamente\n\n");
			}
			else
			{
				printf("\n-> Baja cancelada\n");
			}
			Return = 0;
		}
	}
	return Return;
}


int setStatusFlight(Passenger* list, int index, char flyCode[], Flight flights[], int lenFli){

	int Return = -1;
    if(flights != NULL && lenFli > 0){

        for(int i= 0; i < lenFli; i++){

           if( strcmp(flights[i].flycode, flyCode) == 0){
               list[index].statusFlight = flights[i].statusFlight;
               Return = 0;
               break;
           }
        }
   }
   return Return;

}

int listIsNotEmpty(Passenger* list, int len, int* flag){

    int Return = -1;
    *flag = 0;

    if( list != NULL && flag != NULL && len > 0)
    {
        for(int i=0; i < len; i++)
        {
            if(list[i].isEmpty == 0) // busca en el array de estructuras algun indice ocupado
            {
                *flag = 1;
                break;
            }
        }
        Return = 0;
    }
    return Return;
}


/** \brief Sort the elements in the array of passengers, the argument order indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok*
*/
int sortPassengers(Passenger* list, int len, int order){
	int retorno = -1;
	Passenger listAux;

	if(list != NULL && len > 0)
	{
		for(int i=0; i < len - 1; i++)
		{
			for(int j = i + 1; j <len; j++) // order: 1 = up  ;  0 = down
			{
				if( (order == 1 &&
					( (strcmp(list[i].lastName,list[j].lastName) ==0 && list[i].typePassenger < list[j].typePassenger)
							|| strcmp(list[i].lastName,list[j].lastName) >0) )
					 || // cambio de criterio
					(order == 0 &&
					(  (strcmp(list[i].lastName,list[j].lastName) ==0 && list[i].typePassenger > list[j].typePassenger)
							|| strcmp(list[i].lastName,list[j].lastName) <0  ))
				  )

				{
					listAux = list[i];
					list[i] = list[j];
					list[j] = listAux;
				}
			}
		}
		retorno = 1;
	}
	return retorno;
}


/** \brief Sort the elements in the array of passengers, the argument order indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok*
*/
int sortPassengersByCode(Passenger* list, int len, int order){

	int retorno = -1;
	Passenger listAux;

	if(list != NULL && len > 0)
	{
		for(int i=0; i < len - 1; i++)
		{
			for(int j = i + 1; j <len; j++) // order: 1 = up  ;  0 = down
			{
					if( (order == 1 &&
						( (list[i].statusFlight < list[j].statusFlight)
								|| ((list[i].statusFlight == list[j].statusFlight) && (strcmp(list[i].flycode,list[j].flycode) >=0)) ))
						 || // cambio de criterio
						(order == 0 &&
						( (list[i].statusFlight < list[j].statusFlight)
								|| ((list[i].statusFlight == list[j].statusFlight) && (strcmp(list[i].flycode,list[j].flycode) <=0)) ))
					  )

//				if( (order == 1 &&
//					( (strcmp(list[i].flycode,list[j].flycode) ==0 && list[i].statusFlight < list[j].statusFlight)
//							|| strcmp(list[i].flycode,list[j].flycode) >0) )
//					 || // cambio de criterio
//					(order == 0 &&
//					(  (strcmp(list[i].flycode,list[j].flycode) ==0 && list[i].statusFlight > list[j].statusFlight)
//							|| strcmp(list[i].flycode,list[j].flycode) <0  ))
//				  )
				{
					listAux = list[i];
					list[i] = list[j];
					list[j] = listAux;
				}
			}
		}
		retorno = 1;
	}
	return retorno;
}


//Total de los precios de los pasajes
int acumuladorPrecios(Passenger* list, int len, float* acumulado, int* contador){

	int retorno = -1;
	float acumBuffer = 0;
	int contBuffer = 0;

	if(list != NULL && len > 0 && acumulado != NULL && contador != NULL)
	{
		for(int i=0; i < len; i++)
		{
			acumBuffer += list[i].price;
			contBuffer++;
		}
		retorno = 0;
	}

	if(retorno == 0)
	{
		if(acumBuffer >0)
		{
			*acumulado = acumBuffer;
			*contador = contBuffer;
		}
		else
		{
			printf("\nNo hay datos para procesar\n");
		}
	}
	return retorno;
}



//y promedio de los precios de los pasajes,
int promedioPrecios(float* promedio, float acumulado, int contador){

	int retorno = -1;
	float promBuffer =0;

	if(promedio != NULL)
	{
		promBuffer = acumulado / contador;
		*promedio = promBuffer; // no realiza validacion >0 porque ya lo hace acumuladorPrecios()
		retorno = 0;
	}

	return retorno;
}


//y cu?ntos pasajeros superan el precio promedio.
int pasajerosSuperanProm(Passenger* list, int len, int* pasajeros, float promedio){

	int retorno = -1;
	int passBuffer = 0;

	if(list != NULL && len > 0 && pasajeros != NULL)
	{
		for(int i=0; i < len; i++)
		{
			if(list[i].price > promedio)
			{
				passBuffer++;
			}
			*pasajeros = passBuffer; // no realiza validacion >0 porque ya lo hace acumuladorPrecios()
		}
		retorno = 0;
	}
	return retorno;
}





