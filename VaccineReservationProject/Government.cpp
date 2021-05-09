#include <iostream>
using namespace std;
#include "Government.h"
#include "Citizen.h"
#include "LinkedList.h"
#include "Queue.h"
#include "Node.h"

Government::Government() {
	// TODO Auto-generated constructor stub
	numSlots = 3;
	numOfMinVaccines = 3;
	for(int i=0;i<numSlots;i++){//initializing array with 0
		allocatedSlotCount[i] = 0;
	}
	vaccinesPerSlot = numVaccines/numSlots;
	numVaccinatedOnce = numVaccinatedTwice = 0;
	password = "ICU";//private to class
}
int Government::available(){//to check which slots are available so that the user can select appropriately.
	bool available[numSlots] = {false};
	int slot, flag=0;
	for(int i=0;i<numSlots;i++){
		if(allocatedSlotCount[i] < vaccinesPerSlot){
			cout<<"Slot "<<i+1<<" : Available."<<endl;
			available[i] = true;
			flag = 1;
		}
	}
	if(flag==0) return 0;//no space in confirmed array, thus will be enqueued in the waiting list
	int f = 0;
	do{
		f = 0;
		cout<<"Select a slot : "<<endl;
		cin>>slot;
		if(flag==1 && slot>numSlots) {
			f=1;//invalid slot, does not exist.
			cout<<"Invalid slot, enter again."<<endl;
		}
		else if(flag==1 && available[slot-1]==false){
			f=1;//invalid slot as it is full.
			cout<<"Invalid slot, enter again."<<endl;
		}

	}while(f==1);
	return slot;//proper slot

}
void Government::reserveVaccine(){
	Citizen c;
	bool isEligible = c.accept();
	vaccinesPerSlot = numVaccines/numSlots;
	if(!isEligible) return;//check for eligibility
	int s = available();
	if(s==0){//no space in confirmed array, thus will be enqueued in the waiting list
		cout<<"For future reference, enter your slot preference : "<<endl;
		cin>>c.slot;
		c.status = "Unconfirmed";
		waitingList.priorityEnqueue(c);
		waitingList.search(c.getAadhar())->c.citizenAhead = waitingList.citizenAhead(c.getAadhar());//to check number of people ahead in the waiting list
		waitingList.search(c.getAadhar())->c.display();//display information about user and his/her status.
	}
	else{
		confirmed[s-1].insert(c);//insertion in linked list in the array
		allocatedSlotCount[s-1]++;
		Node* ptr = confirmed[s-1].search(c.getAadhar());
		ptr->c.slot = s;//statu updation
		ptr->c.status = "Confirmed!";
		ptr->c.display();
	}
}
void Government::deleteVaccine(){
	cout<<"Enter your Aadhar number to delete your reservation."<<endl;
	long a; cin>>a;
	Node* ptr=NULL;
	int idx;
	for(int i=0;i<numSlots;i++){//searching in confirmed array
		ptr = confirmed[i].search(a);
		if(ptr!=NULL){//implies that Citizen is found in confirmed array
			idx = i;
			break;
		}
	}
	if(ptr!=NULL){
		if(!waitingList.isEmpty()){//implies that citizen in the waiting list has been promoted to the position of the deleted citizen in the confirmed array
			ptr->c = waitingList.dequeue();
			ptr->c.slot = idx+1;
			ptr->c.status = "Confirmed!";
			cout<<"Your reservation has been successfully deleted from the confirmed slots."<<endl;

		}
		else{//Waiting List is empty, thus deleting node in confirmed array.
			bool isDelete = confirmed[idx].deleteNode(a);
			allocatedSlotCount[idx]--;
			cout<<"Your reservation has been successfully deleted from the confirmed slots."<<endl;
		}
	}
	else{//checking if citizen is in Waiting List, and if so, the node is deleted.
		bool isDeleted = waitingList.deleteNodeWaitingList(a);
		if(isDeleted==true){
			cout<<"Your reservation has been successfully deleted from the waiting lists."<<endl;
		}
		else{//Citizen not found in confirmed array nor in waiting list.
			cout<<"You are not registered in the vaccination portal."<<endl;
		}
	}

}
void Government::modify(){
	cout<<"Enter your Aadhar number to check your reservation."<<endl;
	long a; cin>>a;
	Node* ptr  = l.search(a);//check in government record linked list.
	if(ptr==NULL){//if Null, implies the Citizen received the vaccination for the first time.
		for(int i=0;i<numSlots;i++){//check in confirmed array.
			Node* n = confirmed[i].search(a);
			if(n!=NULL){
				ptr = n;
				break;
			}
		}
		l.insert(ptr->c);//inserting the node in government record linked list.
		numVaccinatedOnce++;
		if(ptr==NULL){//Node cannot be found in confirmed array.
			cout<<"You are not registered in the vaccination portal."<<endl;
			return;
		}
	}
	else{//implies the Citizen received the vaccination for the second time.
		ptr->c.numTimesVaccinated++;//modify the node details.
		numVaccinatedOnce--;
		numVaccinatedTwice++;
	}
	cout<<"You have successfully modified the database. Thank you!"<<endl;
	bool isDelete = confirmed[ptr->c.slot - 1].deleteNode(a);//delete node from the confirmed array
	allocatedSlotCount[ptr->c.slot - 1]--;
}
void Government::modifyEndOfDay(){//should be accessible only to the government administrator
	cout<<"Welcome administrator! Enter your password : "<<endl;
		string s;
		cin>>s;
	if(s.compare(password)!=0){
			cout<<"Incorrect password."<<endl;
			return;
	}

	int minVaccinesperSlot = numOfMinVaccines/numSlots;//The minimum number of available vaccines per day is a fixed parameter. The number of vaccines per day must be greater than this threshold.
	Node* ptr = waitingList.front;
	/*
	 * NOTE: Working flow and goal :
	 * 1. At the end of the day, prioritize all citizens including the young to the highest priority, i.e 1
	 * 2. As the minimum number of vaccines is fixed, allocate that number of slots in the confirmed array to the citizens in the waiting list.
	 * 3. The next day, new citizens will get an opportunity to get a slot in the confirmed array if number of vaccines > number of minimum vaccines.
	 * 4. Thus, we also provide FCFS for a new day.
	 * 5. Now once the confirmed array is full, the citizens will enter in the waiting list.
	 * 	  But they will enter after the remaining citizens who booked a slot in the previous days(if there are any present)
	 * 	  Thus, the citizens who were in the waiting queue since before will have a higher priority.
	 */
	while(ptr!=NULL){//At the end of the day, prioritize all Citizens to the highest priority.
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
				confirmed[ptr->c.slot - 1].insert(ptr->c);
				allocatedSlotCount[ptr->c.slot - 1]++;
				bool isDelete = waitingList.deleteNodeWaitingList(ptr->c.getAadhar());
				i++;
			}
		ptr = ptr ->next;
	}
}
void Government::checkStatus(){//Displays the current status of the citizen's vaccination
		cout<<"Enter your Aadhar number to check your reservation."<<endl;
		long a; cin>>a;
		Node* ptr=NULL;
		int idx=0;
		for(int i=0;i<numSlots;i++){
			ptr = confirmed[i].search(a);
			if(ptr!=NULL){
				ptr->c.display();//in confirmed array
				return;
			}
		}

			ptr = waitingList.search(a);
			if(ptr!=NULL){//in waiting list
				ptr->c.citizenAhead = waitingList.citizenAhead(a);
				ptr->c.display();
			}
			else{//invalid entry
				cout<<"You are not registered in the vaccination portal."<<endl;
			}
}
void Government::govtInterface(){//only accessible to a government administrator
	cout<<"Welcome administrator! Enter your password : "<<endl;
	string s;
	cin>>s;
	if(s.compare(password)!=0){
		cout<<"Incorrect password."<<endl;
		return;
	}
	cout<<"Enter the number of vaccines available today"<<endl;//Critical information entry
	cin>>numVaccines;
	vaccinesPerSlot = numVaccines/numSlots;
}
