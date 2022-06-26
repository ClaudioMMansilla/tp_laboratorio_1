#ifndef ARRAYSTATUS_H_
#define ARRAYSTATUS_H_

typedef struct {
	char flycode[10];
	char status[10];
	int statusFlight;
}Flight;

#endif /* ARRAYSTATUS_H_ */


int searchFlight(Flight list[], int len, char fly[], int* pIndex);

void printFlight(Flight flight);

int printAvailableFlights(Flight flights[], int lenFli);

int validateFlight(Flight flight[], int lenFli, char fly[]);

int loadDescriptionStatusFlight(Flight flights[], int lenFli, int id, char status[]);

