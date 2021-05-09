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
		cout<<"Enter your choice : "<<endl;
		cout<<"1 - Select if you are a government administrator for information updation.."<<endl;
		cout<<"2 - Register for a vaccination."<<endl;
		cout<<"3 - Delete your reservation."<<endl;
		cout<<"4 - If you've received the vaccination, then update the status."<<endl;
		cout<<"5 - Check the status of your vaccination."<<endl;
		cout<<"6 - Select if you are a government administrator for slot modification."<<endl;
		cout<<"7 - Exit."<<endl;
		int option; cin>>option;
		switch(option){
		case 1 : govt.govtInterface();break;
		case 2 : govt.reserveVaccine(); break;
		case 3 : govt.deleteVaccine(); break;
		case 4 :{
			cout<<"Enter yes if you have received your vaccine, else enter no."<<endl;
			string s; cin>>s;
			if(s=="yes")
				govt.modify();
			break;
			}
		case 5 : govt.checkStatus();break;
		case 6 : govt.modifyEndOfDay();break;
		case 7 : break;
		default :cout<<"Invalid choice. Kindly enter your choice again."<<endl; break;
		}
	}while(option!=7);
	cout<<"Have a nice day!"<<endl;
}
