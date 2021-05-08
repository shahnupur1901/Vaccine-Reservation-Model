/*
 * Hospital.h
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
#ifndef HOSPITAL_H_
#define HOSPITAL_H_

class Hospital {
public:
	int numVaccinesAvailable;
	int numSlots;
	int allocated[numSlots];
	Hospital();
};

#endif /* HOSPITAL_H_ */
