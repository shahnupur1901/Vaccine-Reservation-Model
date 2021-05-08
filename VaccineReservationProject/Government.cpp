/*
 * Government.cpp
 *
 *  Created on: 08-May-2021
 *      Author: nupur
 */

#include "Government.h"
#include "Citizen.h"
#include "Government.h"
#include "LinkedList.h"
#include "Queue.h"
#include "Hospital.h"
Government::Government() {
	// TODO Auto-generated constructor stub
	numVaccines = 10;
	numSlots = 5;
	allocatedSlotCount = {0,0,0,0,0};
	vaccinesPerSlot = numVaccines/numSlots

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
	if(s=0){
		//waiting list
	}
	else if(s==-1){
		cout<<"Try again."<<endl;
		reserveVaccine();
	}
	else{
		arr[slot-1].insert(c);
		allocatedSlotCount[slot-1]++;
		c.numTimesVaccinated++;
		c.slot = slot;
		c.status = "Confirmed!";
	}
	c.display();
}
void Government::deleteVaccine(){
	Citizen c;
	c.accept();
	cout<<"Enter the status of your reservation \n1- Confirmed\n2- Unconfirmed"<<endl;
	int choice;cin>>choice;
	switch(choice){
	case 1:{
		cout<<"Enter the slot you've been allocated : "<<endl;
		int s;cin>>s;
		if(!waitingList.isEmpty()){
				Citizen cwq = waitingList.dequeue();
				cwq.slot = slot;
				cwq.status = "Confirmed!"<<endl;
				l.replace(c.adhar,cwq);//replace(long adhar, Citizen cwq)

		}
		else{
			arr[slot-1].deleteNode(c.adhar);compare with them
			allocatedSlotCount[slot-1]--;
		}
	}
	case 2:
	}
}
void Government::modify(){
	Citizen c;
	c.accept();
	Node* ptr  = l.search(c.adhar);
	ptr->numTimesVaccinated++;
}
void Government::checkStatus(){
	Citizen c;
	c.accept();
	if(numTimesVaccinated==2)


}


