#include <iostream>
using namespace std;
#include "Citizen.h"
#include "Government.h"
#include "LinkedList.h"
#include "Queue.h"

Citizen::Citizen() {
	// TODO Auto-generated constructor stub
	vaccineCompany="\0";
	numTimesVaccinated = 0;
	status = "Unconfirmed";
	citizenAhead = 0;
	priority = 0;
}
bool Citizen::chkEligibility(){//checks to see if you are eligible to receive a vaccine
	cout<<"How many days have passed since you've been tested positive?"<<endl;
	int days;cin>>days;
	if(days > 28) return true;
	else{
		cout<<"Please come back after "<<28-days<<" days."<<endl;return false;
	}
}
bool Citizen::accept(){//accept the citizen's details
	cout<<"Have you been infected with COVID-19? 1 - Yes 2 - No"<<endl;
	int ch;cin>>ch;
	if(ch==1 && !chkEligibility()){
		return false;
	}
	cout<<"Enter your name : "<<endl;
	string s;
	getline(cin,s);
	getline(cin,name);
	cout<<"Enter your age : "<<endl;
	cin>>age;
	if(age>60) priority = 1;
	else priority = 2;
	cout<<"Enter your aadhar number : "<<endl;
	cin>>aadhar;
	cout<<"Enter the number of times you've been vaccinated : "<<endl;
	cin>>numTimesVaccinated;
	if(numTimesVaccinated >= 2){
		cout<<"According to government guidelines, you are protected from COVID-19."<<endl;
		return false;
	}
	return true;
}
void Citizen::display(){//Display the citizen information
	cout<<"Your name : "<<name<<endl;
	cout<<"Your age : "<<age<<endl;
	cout<<"Your Aadhar number : "<<aadhar<<endl;
	cout<<"Your status :"<<status<<endl;
	if(status=="Confirmed!")
		cout<<"Your slot : "<<slot<<endl;
	else{
		cout<<"You are in the waiting list. Number of people ahead of you: "<<citizenAhead<<endl;
	}
}
long Citizen::getAadhar(){//as citizen's Aadhar details are private, constructing function to return the value.
	return aadhar;
}

