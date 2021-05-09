
#pragma once
#include<iostream>
#include "Citizen.h"
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
