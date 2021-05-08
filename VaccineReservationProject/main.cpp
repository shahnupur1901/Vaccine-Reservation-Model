#include<iostream>
#include<string.h>
using namespace std;
#include "Citizen.h"
#include "Government.h"
#include "LinkedList.h"
#include "Queue.h"
#include "Hospital.h"

int main(){
	cout<<"Welcome to the COVID-19 Vaccination Portal!"<<endl;
	Government g;
	Citizen c;
	int ch = 0;
	do{
		cout<<"Enter your choice : "<<endl;
		cout<<"1 - Register for a Vaccination."<<endl;
		cout<<"2 - Delete your reservation."<<endl;
		cout<<"3 - Enter  "<<endl;
		cout<<"4 - Check the status of your vaccination."<<endl
		int option; cin>>option;
		switch(option){
		case 1 : g.reserveVaccine(); break;
		case 2 : g.deleteVaccine(); break;
		case 3 :{
			cout<<"Enter yes if you have received your vaccine, else enter no."<<endl;
			string s; cin>>s;
			if(s=="yes")
				g.modify();
		}
		}
	}
}
