#pragma once
#include <iostream>
#include "Queue.h"
#include "LinkedList.h"

using namespace std;
class Government {
	LinkedList l;
	Queue waitingList;
	int numVaccinatedOnce;
	int numVaccinatedTwice;
	int numVaccines;
	LinkedList confirmed[3];
	int allocatedSlotCount[3];
	int vaccinesPerSlot,numSlots;
	int numOfMinVaccines;
	string password;
public:
	Government();
	void reserveVaccine();
	void deleteVaccine();
	int available();
	void checkStatus();
	void modify();
	void modifyEndOfDay();
	void govtInterface();
};


