#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"


int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int bufferInt;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s", mensaje);
			scanf("%d", &bufferInt);
			if(bufferInt >= minimo && bufferInt <= maximo)
			{
				*pResultado = bufferInt;
				retorno = 0; // salio todo ok
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}
	return retorno;
}



int utn_getNumeroFloat(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
	int retorno = -1;
	float bufferFloat;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s", mensaje);
			scanf("%f", &bufferFloat);
			if(bufferFloat >= minimo && bufferFloat <= maximo)
			{
				*pResultado = bufferFloat;
				retorno = 0; // salio todo ok
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}
	return retorno;
}



int utn_getCaracter(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos)
{
	int retorno = -1;
	char bufferChar;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s", mensaje);
			fflush(stdin);
			scanf("%c", &bufferChar);
			if(bufferChar >= minimo && bufferChar <= maximo)
			{
				*pResultado = bufferChar;
				retorno = 0; // salio todo ok
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}
	return retorno;
}



int entradaDatos_getNumeroInt(int* pNumero, char* mensaje, char* mensajeError, int minimo, int maximo)
{
	int retorno = -1;
	int bufferInt;
	int ingreso;

	if(pNumero != NULL && mensaje != NULL && mensajeError && minimo <= maximo)
	{
		do
		{
			printf("%s", mensaje);
			fflush(stdin);
			ingreso = scanf("%d", &bufferInt);
			if(ingreso == 1)
			{
				if(bufferInt >= minimo && bufferInt <= maximo)
				{
					*pNumero = bufferInt;
					retorno = 0; // salio todo ok
					break;
				}
				else
				{
					printf("%s", mensajeError); // informa al usuario que el valor ingresado está fuera de rango
				}

			}
			else
			{
				printf("Error: el valor ingresado NO es un número. Reintente nuevamente\n");
			}
		}while(retorno != 0);
	}
	return retorno;
}



int entradaDatos_getNumeroFloat(float* pNumero, char* mensaje, char* mensajeError, float minimo, float maximo)
{
	int retorno = -1;
	float bufferFloat;
	int ingreso;

	if(pNumero != NULL && mensaje != NULL && mensajeError && minimo <= maximo)
	{
		do
		{
			printf("%s", mensaje);
			fflush(stdin);
			ingreso = scanf("%f", &bufferFloat);
			if(ingreso == 1)
			{
				if(bufferFloat >= minimo && bufferFloat <= maximo)
				{
					*pNumero = bufferFloat;
					retorno = 0; // salio todo ok
					break;
				}
				else
				{
					printf("%s", mensajeError); // informa al usuario que el valor ingresado está fuera de rango
				}

			}
			else
			{
				printf("Error: el valor ingresado NO es un número. Reintente nuevamente\n");
			}
		}while(retorno != 0);
	}
	return retorno;
}

