#pragma once
#include <iostream>
#include "Queue.h"
#include "LinkedList.h"

using namespace std;
#define numSlots 2;//#define is used so that the value becomes global and remains static
class Government {
	LinkedList l;
	Queue waitingList;
	int numVaccinatedOnlyOnce;
	int numVaccinatedTwice;
	int numVaccines;
	LinkedList confirmed[numSlots];
	int allocatedSlotCount[numSlots];
	int vaccinesPerSlot;
	string password;
	int extraVaccines;
public:
	Government();
	void reserveVaccine();
	void cancelReservation();
	int available();
	void checkStatus();
	void modify();
	void modifyEndOfDay();
	void govtInterface();
	void urgentReservation();
};


