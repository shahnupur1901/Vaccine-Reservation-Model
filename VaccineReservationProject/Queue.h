#pragma once
#include<iostream>
#include "Node.h"
#include "Citizen.h"
using namespace std;
#ifndef QUEUE_H_
#define QUEUE_H_

class Queue {
	Citizen c;
	friend class Citizen;
public:
	Node* front;
	Node* rear;
	Queue();
	void priorityEnqueue(Citizen c);
	Citizen dequeue();
	Node* search(long key);
	bool isEmpty();
	bool deleteNodeWaitingList(long key);
	int citizenAhead(long key);
};

#endif /* QUEUE_H_ */
