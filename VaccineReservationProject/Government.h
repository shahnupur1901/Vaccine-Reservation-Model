/*
 * Government.h
 *
 *  Created on: 08-May-2021
 *      Author: nupur
 */
#pragma once
#include<iostream>
#include<string.h>
#include "Citizen.h"
#include "Government.h"
#include "LinkedList.h"
#include "Queue.h"
#include "Hospital.h"
using namespace std;
#ifndef GOVERNMENT_H_
#define GOVERNMENT_H_

class Government {
	LinkedList l;
	Queue waitingList;
	count numVaccinatedOnce;
	count numVaccinatedTwice;
	int numSlots,numVaccines;
	LinkedList arr[numSlots];
	int allocatedSlotCount[numSlots];
	int vaccinesPerSlot;

public:
	Government();
	void reserveVaccine();
	void deleteVaccine();
	bool available();
	void checkStatus();
	void modify();
};

#endif /* GOVERNMENT_H_ */
