/*
 * Citizen.cpp
 *
 *  Created on: 08-May-2021
 *      Author: nupur
 */
#include <iostream>
using namespace std;
#include "Citizen.h"
#include "Government.h"
#include "LinkedList.h"
#include "Queue.h"
#include "Node.h"
Citizen::Citizen() {
	// TODO Auto-generated constructor stub
	vaccineCompany="\0";
	numTimesVaccinated = 0;
	status = "Unconfirmed";
	vaccineSlot = aadhar = age = 0;
	slot = -1;
}
void Citizen::accept(){
	cout<<"Enter your name : "<<endl;
	cin>>name;
	cout<<"Enter your age : "<<endl;
	cin>>age;
	cout<<"Enter your aadhar number : "<<endl;
	cin>>aadhar;
	cout<<"Enter the number of times you've been vaccinated : "<<endl;
	cin>>numTimesVaccinated;
	if(numTimesVaccinated >= 2){
		cout<<"According to government guidelines, you are protected from COVID-19"<<endl;
	}
	if(numTimesVaccinated ==1){
		cout<<"Enter the name of the vaccine received earlier : "<<endl;
		cin>>vaccineCompany;
	}
}
void Citizen::display(){
	cout<<"Your name : "<<name<<endl;
	cout<<"Your age : "<<age<<endl;
	cout<<"Your Aadhar number : "<<aadhar<<endl;
	if(status=="Confirmed!")
		cout<<"Your slot : "<<slot<<endl;
	else{
		cout<<"You are in the waiting list. Number of people ahead of you: "<<endl;
	}
}
long Citizen::getAadhar(){
	return aadhar;
}
