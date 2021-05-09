#pragma once
#include <iostream>
#include <string.h>


using namespace std;
class Citizen {
	string name;
	long aadhar;
	int age,vaccineSlot;
public:
	int priority;
	int numTimesVaccinated,slot;
	string vaccineCompany,status;
	Citizen();
	bool accept();
	void display();
	long getAadhar();
	int citizenAhead;
	bool chkEligibility();
};


