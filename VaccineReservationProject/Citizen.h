/*
 * Citizen.h
 *
 *  Created on: 08-May-2021
 *      Author: nupur
 */
#pragma once
#include <iostream>
#include <string.h>


using namespace std;
#ifndef CITIZEN_H_
#define CITIZEN_H_
class Citizen {
	string name;
	long aadhar;
	int age,vaccineSlot;
public:
	int numTimesVaccinated,slot;
	string vaccineCompany,status;
	Citizen();
	void accept();
	void display();
	long getAadhar();
};

#endif /* CITIZEN_H_ */
