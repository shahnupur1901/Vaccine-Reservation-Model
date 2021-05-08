/*
 * Citizen.cpp
 *
 *  Created on: 08-May-2021
 *      Author: nupur
 */

#include "Citizen.h"
#include "Government.h"
#include "LinkedList.h"
#include "Queue.h"
#include "Hospital.h"

Citizen::Citizen() {
	// TODO Auto-generated constructor stub
	vaccineCompany="\0";
	numTimesVaccinated = 0;
	status = "Unconfirmed";
}
void accept(){
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
		cout<<"Enter the name of the vaccine received eariler : "<<endl;
		cin>>vaccineCompany;
	}
}
void display(){
	cout<<"Your name : "<<name<<endl;
	cout<<"Your age : "<<age<<endl;
	cout<<"Your Aadhar number : "<<aadhar<<endl;
	if(status=="Confirmed!")
		cout<<"Your slot : "<<slot<<endl;
	else{
		cout<<"You are in the waiting list. Number of people ahead of you: "<<_____<<endl;
	}
}

