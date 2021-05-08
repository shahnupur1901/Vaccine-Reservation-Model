/*
 * Queue.h
 *
 *  Created on: 08-May-2021
 *      Author: nupur
 */
#pragma once
#include<iostream>
#include<string.h>
#include "Citizen.h"
#include "LinkedList.h"
#include "Node.h"
using namespace std;
#ifndef QUEUE_H_
#define QUEUE_H_

class Queue {
	Citizen c;
	friend class Citizen;
	Node* front;
	Node* rear;
public:
	Queue();
	void enqueue(Citizen c);
	Citizen dequeue();
	void search(long key);
	void deleteNode(long key);
	bool isEmpty();
};

#endif /* QUEUE_H_ */
