/*
 * Queue.h
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
#ifndef QUEUE_H_
#define QUEUE_H_

class Queue {
	Citizen* front;
	Citizen* rear;
public:
	Queue();
	void enqueue(Citizen* c);
	Citizen* dequeue();
};

#endif /* QUEUE_H_ */
