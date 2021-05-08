/*
 * Node.h
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
using namespace std;
#ifndef NODE_H_
#define NODE_H_


class Node {
public:
	Citizen c;
	Node *next;
	Node *prev;
	Node();
	//long getAadhar();
};

#endif /* NODE_H_ */
