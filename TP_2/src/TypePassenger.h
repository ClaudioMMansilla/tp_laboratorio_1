
#ifndef TYPEPASSENGER_H_
#define TYPEPASSENGER_H_


typedef struct {
	int id;
	char description[15];
}TypePassenger;

#endif /* TYPEPASSENGER_H_ */


int searchTypePassenger(TypePassenger type[], int lenType, int id, int* pIndex);

int validateTypePassenger(TypePassenger type[], int lenType, int id);

int loadDescriptionTypePassenger(TypePassenger type[], int lenType, int id, char descrip[]);

void printTypePassenger(TypePassenger type);

int printAvailableTypes(TypePassenger type[], int lenType);

