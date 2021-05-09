#pragma once
#include <iostream>
#include "Citizen.h"
#include "Node.h"

using namespace std;


class LinkedList {
	Citizen c;
public:
	 Node* head;
	 LinkedList();
	 void insert(Citizen c);
	 bool deleteNode(long);
	 Node* search(long);
	 bool is_empty();
};


