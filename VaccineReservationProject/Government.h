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
#include "LinkedList.h"
#include "Queue.h"
#include "Node.h"
using namespace std;
#ifndef GOVERNMENT_H_
#define GOVERNMENT_H_
class Government {
	LinkedList l;
	Queue waitingList;
	int numVaccinatedOnce;
	int numVaccinatedTwice;
	int numVaccines;
	LinkedList arr[10];
	int allocatedSlotCount[10];
	int vaccinesPerSlot,numSlots;

public:
	Government();
	void reserveVaccine();
	void deleteVaccine();
	int available();
	void checkStatus();
	void modify();
};

#endif /* GOVERNMENT_H_ */
