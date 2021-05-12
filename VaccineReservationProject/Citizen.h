#pragma once
#include <iostream>
#include <string.h>


using namespace std;
class Citizen {
	string name;
	long aadhar;
	int age,vaccineSlot;
	friend class Node;
	friend class Government;
	friend class Queue;
	friend class LinkedList;
public:
	int priority;
	int numTimesVaccinated,slot;
	string vaccineCompany,status;
	Citizen();
	bool accept();
	void display();
	int citizenAhead;
	bool chkEligibility();
};


