#include<iostream>
#include<string.h>
using namespace std;
#include "Citizen.h"
#include "Government.h"
#include "LinkedList.h"
#include "Queue.h"


int main(){
	cout<<"Welcome to the COVID-19 Vaccination Portal!"<<endl;
	Citizen c;
	Government govt;
	int option = 0;
	do{
		cout<<"1 - Government Interface."<<endl;
		cout<<"2 - Register for a vaccination."<<endl;
		cout<<"3 - Delete your reservation."<<endl;
		cout<<"4 - If you've received the vaccination, then update the status."<<endl;
		cout<<"5 - Check the status of your vaccination."<<endl;
		cout<<"6 - Exit."<<endl;
		cout<<"Enter your choice : "<<endl;
		int option; cin>>option;
		switch(option){
		case 1 : {
			int c = 0;
			cout<<"1. Update the number of vaccines to be provided.\n2. Display the vaccinated count.\n3. Exit "<<endl;
			cout<<"Enter your choice : "<<endl;
			cin>>c;
			switch(c){
			case 1: govt.govtInterface();break;
			case 2: govt.modifyEndOfDay();break;
			default:break;
			}
		}
		break;
		case 2 : govt.reserveVaccine(); break;
		case 3 : govt.cancelReservation(); break;
		case 4 :{
			cout<<"Select your status: \n1. Vaccination received.\n2. Vaccination not received.\n3. Exit. "<<endl;
						int ch; cin>>ch;
						switch(ch){
						case 1: govt.modify();break;
						default : break;
						}
						}
		case 5 : govt.checkStatus();break;
		case 6 : break;
		default :cout<<"Invalid choice. Kindly enter your choice again."<<endl; break;
		}
	}while(option!=6);
	cout<<"Have a nice day!"<<endl;
}
