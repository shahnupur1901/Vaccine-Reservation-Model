/*
 * Government.h
 *
 *  Created on: 08-May-2021
 *      Author: nupur
 */
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
	LinkedList company1;
	LinkedList company2;
	Queue waitingList;
	count numVaccinatedOnce;
	count numVaccinatedTwice;

public:
	Government();
};

#endif /* GOVERNMENT_H_ */
