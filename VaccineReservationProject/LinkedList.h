/*
 * LinkedList.h
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
#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

class LinkedList {
	Citizen* head;
public:
	LinkedList();
	void insert(Citizen* c);//vaccinated for the first time
	void modify(Citizen* c);//vaccinated for the second time
	void deleteOnce(Citizen* c);//delete node
	void deleteTwice(Citizen* c);//reduce times vaccinated
};

#endif /* LINKEDLIST_H_ */
