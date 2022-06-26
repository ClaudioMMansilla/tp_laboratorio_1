#include <stdio.h>
#include <stdlib.h>
#include "string.h"

#include "TypePassenger.h"


int searchTypePassenger(TypePassenger type[], int lenType, int id, int* pIndex){

    int Return = -1;
    if( type != NULL && pIndex != NULL && lenType > 0 )
    {
        *pIndex = -1;
        for(int i=0; i < lenType; i++)
        {
            if(type[i].id == id)
            {
                *pIndex = i;
                break;
            }
        }
        Return = 0;
    }
    return Return;
}


int validateTypePassenger(TypePassenger type[], int lenType, int id){
	int Return = -1;
	int index;

	if (!searchTypePassenger(type, lenType, id, &index) ){
		if(index != -1){
			Return = 0;
		}
	}
	return Return;
}



int loadDescriptionTypePassenger(TypePassenger type[], int lenType, int id, char descrip[]){

	int Return = -1;
    if(type != NULL && lenType > 0 && descrip != NULL){

         for(int i= 0; i < lenType; i++){

            if( type[i].id == id){
                strcpy( descrip, type[i].description);
                Return = 0;
                break;
            }
         }
    }
    return Return;
}


void printTypePassenger(TypePassenger type){
// recibe 1 solo vector por cada llamado
	printf("|%d            %15s| \n",
			type.id,
			type.description);
}


int printAvailableTypes(TypePassenger type[], int lenType){

	int Return = -1;
    if( type != NULL && lenType > 0 )
    {
    	system("cls");
    	printf(" ** Listado de clases disponibles ** \n");
    	printf("--------------------------------------\n");
    	printf("   Codigo       Descripcion     \n");
    	printf("--------------------------------------\n");

    	for(int i = 0; i < lenType; i++){
    		printTypePassenger(type[i]);
    	}
        printf("______________________________________\n\n");

        Return = 0;
//    	system("pause");
    }
    return Return;
}
