#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100
#define NUMFLIGHTS 50
typedef struct
{
	char fullName[64];
	char gender; //M or F
	char address[128];
	int age;
} Passenger;

typedef struct
{
	char flightNo[4];
	Passenger psgr;
} Ticket;

typedef struct
{
	Ticket ticket[MAX];
	int lastTicket;
} TicketList;

typedef struct
{
	int day;
	int month;
	int year;
	int timeDeparture; //Only in hours. Possible values are from 5 - 22 meaning, 5 AM to 10 PM
	int arrival;
} Schedule;

typedef struct
{
	char flightNo[4];
	char src[4];
	char dest[4];
	Schedule sched;
	int status; // 0 = CANCELLED, 1 = ON TIME
} Flight;

typedef struct
{
	Flight flight[NUMFLIGHTS];
	int flightCount;
} FlightList;

TicketList initTL(void);
void initFL(FlightList *FL);
void displayTL(TicketList TL);
void displayFL(FlightList FL);
void addFlight(Flight F, FlightList *FL);
void populateFlightList(FlightList *FL);
void bookTicket(Passenger P, int currTime, char flightNo[4], FlightList FL, TicketList *TL);
void cancelFlight(char flightNo[4], FlightList *FL, TicketList *TL);

int main(void)
{
	Passenger P1 = {"Cristan Adams", 'M', "Cebu City", 24};
	Passenger P2 = {"Johann Cruz", 'M', "Metro Manila", 30};
	Passenger P3 = {"Maria Suson", 'F', "Davao City", 21};
	Passenger P4 = {"Pauline Barrera", 'F', "Bacolod City", 20};
	Passenger P5 = {"Jonell De Lima", 'M', "Metro Manila", 35};

	TicketList todaysTickets = initTL();
	FlightList todaysFlights;
	initFL(&todaysFlights);

	populateFlightList(&todaysFlights);
	displayFL(todaysFlights);

	bookTicket(P2, 1, "72X", todaysFlights, &todaysTickets);
	bookTicket(P1, 1, "8ZN", todaysFlights, &todaysTickets);
	bookTicket(P4, 1, "4JP", todaysFlights, &todaysTickets);
	bookTicket(P3, 1, "8ZN", todaysFlights, &todaysTickets);
	bookTicket(P5, 1, "72X", todaysFlights, &todaysTickets);
	displayTL(todaysTickets);

	cancelFlight("8ZN", &todaysFlights, &todaysTickets);
	displayTL(todaysTickets);
	displayFL(todaysFlights);

	return 0;
}

TicketList initTL(void)
{
	TicketList newTL;
	newTL.lastTicket = -1;
	return newTL;
}

void initFL(FlightList *FL)
{
	FL->flightCount = 0;
}

void displayTL(TicketList TL)
{
	int i;
	int count = TL.lastTicket + 1;

	puts("TICKET LIST:");
	if (count == 0)
	{
		puts("There are no tickets in the ticket list.");
	}
	else
	{
		for (i = 0; i < count; i++)
		{
			printf("[%s] - %s\n", TL.ticket[i].flightNo, TL.ticket[i].psgr.fullName);
		}
	}
}

void displayFL(FlightList FL)
{
	int i;
	puts("FLIGHT LIST:");
	for (i = 0; i < FL.flightCount; i++)
	{
		printf("[%s] || %s - %s : %d/%d/%d %d - %d Status: %s\n", FL.flight[i].flightNo, FL.flight[i].src, FL.flight[i].dest, FL.flight[i].sched.day, FL.flight[i].sched.month,
			   FL.flight[i].sched.year, FL.flight[i].sched.timeDeparture * 100, FL.flight[i].sched.arrival * 100,
			   FL.flight[i].status == 0 ? "CANCELLED" : "ON TIME");
	}
}

void addFlight(Flight F, FlightList *FL)
{
	if (FL->flightCount != NUMFLIGHTS)
	{
		FL->flight[FL->flightCount] = F;
		FL->flightCount++;
	}
}

void populateFlightList(FlightList *FL)
{
	Flight F[5] = {
		{"8ZN", "CEB", "MNL", {10, 22, 2021, 5, 6}, 1},
		{"72X", "MNL", "CEB", {10, 22, 2021, 12, 13}, 1},
		{"4JP", "CEB", "BCD", {10, 22, 2021, 7, 8}, 1},
		{"6LX", "CEB", "DVO", {10, 22, 2021, 9, 11}, 1},
		{"5RT", "DVO", "CEB", {10, 22, 2021, 12, 14}, 0},
	};
	int i;
	for (i = 0; i < 5; i++)
	{
		addFlight(F[i], FL);
	}
}

/*
  	Write the code for the function bookTicket.
  	The function will add a new ticket into the end of the TicketList if the passed flightNo is found in the FlightList, 
  	and if the scheduled time of departure for the flight is minimum 4 hours before the currentTime.
*/
void bookTicket(Passenger P, int currTime, char flightNo[4], FlightList FL, TicketList *TL)
{
	int i;
	for (i = 0; i < FL.flightCount; i++)
	{

		if (strcmp(flightNo, FL.flight[i].flightNo) == 0 && FL.flight[i].sched.timeDeparture <= currTime + 4)
		{
			TL->ticket[TL->lastTicket + 1].psgr = P;
			strcpy(TL->ticket[TL->lastTicket + 1].flightNo, flightNo);
			i = FL.flightCount + 1;
			TL->lastTicket++;
		}
	}
}
/*
	Write the code for the function cancelFlight.
	The function will go through the FlightList and check if the passed flightNo exists. 
	If it does, set the status of that flight to 0, and DELETE ALL tickets in the TicketList with the cancelled flightNo.
*/
void cancelFlight(char flightNo[4], FlightList *FL, TicketList *TL)
{
	int i;
	for (i = 0; i < FL->flightCount && strcmp(flightNo, FL->flight[i].flightNo) == 0; i++)
	{
	}
	i--;
	int ctr;
	if (i < FL->flightCount)
	{
		FL->flight[i].status = 0;
		for (i = 0; i < (TL->lastTicket + 1); i++)
		{
			// printf("\n\n%d\n\n", TL->lastTicket);
			if (strcmp(TL->ticket[i].flightNo, flightNo) == 0)
			{
				memmove(TL->ticket + i, TL->ticket + (i + 1), sizeof(Ticket) * TL->lastTicket - i);
				ctr++;
			}
		}
		TL->lastTicket -= ctr;
	}
}
