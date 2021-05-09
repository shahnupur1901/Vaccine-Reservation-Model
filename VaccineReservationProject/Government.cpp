#include <iostream>
using namespace std;
#include "Government.h"
#include "Citizen.h"
#include "LinkedList.h"
#include "Queue.h"
#include "Node.h"

Government::Government() {
	// TODO Auto-generated constructor stub
	numSlots = 2;
	numOfMinVaccines = 2;
	for(int i=0;i<numSlots;i++){
		allocatedSlotCount[i] = 0;
	}
	vaccinesPerSlot = numVaccines/numSlots;
	numVaccinatedOnce = numVaccinatedTwice = 0;
	password = "ICU";
}
int Government::available(){
	bool available[numSlots] = {false};
	int slot, flag=0;
	for(int i=0;i<numSlots;i++){
		if(allocatedSlotCount[i] < vaccinesPerSlot){
			cout<<"Slot "<<i+1<<" : Available."<<endl;
			available[i] = true;
			flag = 1;
		}
	}
	if(flag==0) return 0;//waiting list
	int f = 0;
	do{
		f = 0;
		cout<<"Select a slot : "<<endl;
		cin>>slot;
		if(flag==1 && slot>numSlots) {
			f=1;//invalid slot, but slot is available
			cout<<"Invalid slot, enter again."<<endl;
		}
		else if(flag==1 && available[slot-1]==false){
			f=1;//invalid slot, but slot is available
			cout<<"Invalid slot, enter again."<<endl;
		}

	}while(f==1);
	return slot;//proper slot

}
void Government::reserveVaccine(){
	Citizen c;
	bool isEligible = c.accept();
	vaccinesPerSlot = numVaccines/numSlots;
	if(!isEligible) return;
	int s = available();
	if(s==0){
		cout<<"For future reference, enter your slot preference : "<<endl;
		cin>>c.slot;
		c.status = "Unconfirmed";
		waitingList.priorityEnqueue(c);
		waitingList.search(c.getAadhar())->c.citizenAhead = waitingList.citizenAhead(c.getAadhar());
		waitingList.search(c.getAadhar())->c.display();
	}
	else{
		arr[s-1].insert(c);
		allocatedSlotCount[s-1]++;
		Node* ptr = arr[s-1].search(c.getAadhar());
		ptr->c.slot = s;
		ptr->c.status = "Confirmed!";
		ptr->c.display();
	}
}
void Government::deleteVaccine(){
	cout<<"Enter your Aadhar number to delete your reservation."<<endl;
	long a; cin>>a;
	Node* ptr=NULL;
	int idx;
	for(int i=0;i<numSlots;i++){
		ptr = arr[i].search(a);
		if(ptr!=NULL){
			idx = i;
			break;
		}
	}
	if(ptr!=NULL){
		if(!waitingList.isEmpty()){
			ptr->c = waitingList.dequeue();
			ptr->c.slot = idx+1;
			ptr->c.status = "Confirmed!";
			cout<<"Your reservation has been successfully deleted from the confirmed slots."<<endl;

		}
		else{
			cout<<"hi!"<<endl;
			bool isDelete = arr[idx].deleteNode(a);
			allocatedSlotCount[idx]--;
			cout<<"Your reservation has been successfully deleted from the confirmed slots."<<endl;
		}
	}
	else{
		bool isDeleted = waitingList.deleteNodeWaitingList(a);
		if(isDeleted==true){
			cout<<"Your reservation has been successfully deleted from the waiting lists."<<endl;
		}
		else{
			cout<<"You are not registered in the vaccination portal."<<endl;
		}
	}

}
void Government::modify(){
	cout<<"Enter your Aadhar number to check your reservation."<<endl;
	long a; cin>>a;
	Node* ptr  = l.search(a);
	if(ptr==NULL){
		for(int i=0;i<numSlots;i++){
			Node* n = arr[i].search(a);
			if(n!=NULL){
				ptr = n;
				break;
			}
		}
		l.insert(ptr->c);
		numVaccinatedOnce++;
		if(ptr==NULL){
			cout<<"You are not registered in the vaccination portal."<<endl;
			return;
		}
	}
	else{
		ptr->c.numTimesVaccinated++;
		numVaccinatedOnce--;
		numVaccinatedTwice++;
	}
	cout<<"You have successfully modified the database. Thank you!"<<endl;
	bool isDelete = arr[ptr->c.slot - 1].deleteNode(a);
	allocatedSlotCount[ptr->c.slot - 1]--;
}
void Government::modifyEndOfDay(){
	cout<<"Welcome administrator! Enter your password : "<<endl;
		string s;
		cin>>s;
	if(s.compare(password)!=0){
			cout<<"Incorrect password."<<endl;
			return;
	}

	int minVaccinesperSlot = numOfMinVaccines/numSlots;
	Node* ptr = waitingList.front;
	while(ptr!=NULL){
		ptr->c.priority = 1;
		ptr = ptr->next;
	}
	ptr = waitingList.front;
	int i=0;
	while(i!=numOfMinVaccines){
		if(ptr==NULL)
			return;
		if(allocatedSlotCount[ptr->c.slot - 1] < minVaccinesperSlot){
				ptr->c.status = "Confirmed!";
				arr[ptr->c.slot - 1].insert(ptr->c);
				allocatedSlotCount[ptr->c.slot - 1]++;
				bool isDelete = waitingList.deleteNodeWaitingList(ptr->c.getAadhar());
				i++;
			}
		ptr = ptr ->next;
	}
}
void Government::checkStatus(){
		cout<<"Enter your Aadhar number to check your reservation."<<endl;
		long a; cin>>a;
		Node* ptr=NULL;
		int idx=0;
		for(int i=0;i<numSlots;i++){
			ptr = arr[i].search(a);
			if(ptr!=NULL){
				ptr->c.display();
				return;
			}
		}

			ptr = waitingList.search(a);
			if(ptr!=NULL){
				ptr->c.citizenAhead = waitingList.citizenAhead(a);
				ptr->c.display();
			}
			else{
				cout<<"You are not registered in the vaccination portal."<<endl;
			}
}
void Government::govtInterface(){
	cout<<"Welcome administrator! Enter your password : "<<endl;
	string s;
	cin>>s;
	if(s.compare(password)!=0){
		cout<<"Incorrect password."<<endl;
		return;
	}
	cout<<"Enter the number of vaccines available today"<<endl;
	cin>>numVaccines;
	vaccinesPerSlot = numVaccines/numSlots;
}
