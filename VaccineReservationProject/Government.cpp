/*
 * Government.cpp
 *
 *  Created on: 08-May-2021
 *      Author: nupur
 */
#include <iostream>
using namespace std;
#include "Government.h"
#include "Citizen.h"
#include "Government.h"
#include "LinkedList.h"
#include "Queue.h"
#include "Node.h"
Government::Government() {
	// TODO Auto-generated constructor stub
	numVaccines = 10;
	numSlots = 5;
	for(int i=0;i<numSlots;i++){
		allocatedSlotCount[i] = 0;
	}
	vaccinesPerSlot = numVaccines/numSlots;
	numVaccinatedOnce = numVaccinatedTwice = 0;

}
int Government::available(){
	bool available[5] = {false};
	int slot, flag=0;
	for(int i=0;i<numSlots;i++){
		if(allocatedSlotCount[i] < vaccinesPerSlot){
			cout<<"Slot "<<i+1<<" : Available."<<endl;
			available[i] = true;
			flag = 1;
		}
	}
	if(flag==0) return 0;//waiting list
	cout<<"Select a slot : "<<endl;
	cin>>slot;
	if(flag==1 && available[slot-1]==false)return -1;//invalid slot, but slot is available
	return slot;//proper slot

}
void Government::reserveVaccine(){
	Citizen c;
	c.accept();
	int s = available();
	if(s==0){
		//waiting list
		c.status = "Unconfirmed";
		waitingList.enqueue(c);
	}
	else if(s==-1){
		cout<<"Try again."<<endl;
		reserveVaccine();
	}
	else{
		arr[s-1].insert(c);
		allocatedSlotCount[s-1]++;
		c.numTimesVaccinated++;
		c.slot = s;
		c.status = "Confirmed!";
	}
	c.display();
}
void Government::deleteVaccine(){
	Citizen c;
	c.accept();
	cout<<"Enter the status of your reservation: \n1- Confirmed\n2- Unconfirmed"<<endl;
	int choice;cin>>choice;
	switch(choice){
	case 1:{
		cout<<"Enter the slot you've been allocated : "<<endl;
		int s;cin>>s;
		if(!waitingList.isEmpty()){
				Citizen cwq = waitingList.dequeue();
				cwq.slot = s;
				cwq.status = "Confirmed!";
				l.replace(c.aadhar,cwq);//replace(long adhar, Citizen cwq)

		}
		else{
			arr[s-1].deleteNode(c.getAadhar());//compare with them
			allocatedSlotCount[s-1]--;
		}
		break;
	}
	case 2:{
		waitingList.deleteNode(c.getAadhar());
	}

	}
}
void Government::modify(){
	Citizen c;
	c.accept();
	Node* ptr  = l.search(c.getAadhar());
	ptr->c.numTimesVaccinated++;
	if(ptr->c.numTimesVaccinated==1){
		numVaccinatedOnce++;
	}
	else{
		numVaccinatedOnce--;
		numVaccinatedTwice++;
	}
}
void Government::checkStatus(){
	Citizen c;
	c.accept();
	if(c.numTimesVaccinated==2){
		cout<<"You've been vaccinated twice!"<<endl;
	}
	else if(c.numTimesVaccinated==1 || c.numTimesVaccinated==0){
		int flag=0;
		for(int i=0;i<5;i++){
			Node* ptr = arr[i].head;//check!!
			while(ptr!=NULL){
				if(ptr->c.getAadhar() == c.getAadhar()){
					ptr->c.display();
					flag=1;
					break;
				}
				ptr = ptr->next;
			}
		}
		if(flag==0){

		}
		if(flag==0){
			cout<<"Not registered in the database."<<endl;
		}
	}



}


