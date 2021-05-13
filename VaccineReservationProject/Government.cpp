/******** Government Class ***********/ 
#include <iostream>
using namespace std;
#include "Government.h"
#include "Citizen.h"
#include "LinkedList.h"
#include "Queue.h"
#include "Node.h"

Government::Government()
{
	// TODO Auto-generated constructor stub
	numVaccines=0;
    numSlots = 2;
	for(int i=0;i<numSlots;i++){//initializing array with 0
		allocatedSlotCount[i] = 0;
	}
	extraVaccines = 0;
	vaccinesPerSlot = numVaccines/numSlots;
	numVaccinatedOnlyOnce = numVaccinatedTwice = 0;
	password = "ICU";//private to class
}
int Government::available()
{//to check which slots are available so that the user can select appropriately.
	bool available[2] = {false};
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
void Government::urgentReservation()
{
	if(extraVaccines==0){
		cout<<"Vaccines Unavailable. Please check in the regular vaccine portal."<<endl;
		return;
	}
	cout<<"Please carry the required proof to validate your emergency. State your emergency from the options below :"<<endl;
	cout<<"1 - Military personnel\n2 - Medical Emergency\n3 - Travelling abroad\n4 - Other"<<endl;
	int em;cin>>em;
	Citizen c;
	bool isValid = c.accept();
	if(!isValid) return;
	c.status = "Confirmed!";
	c.slot = 1;
	c.display();
	confirmed[0].insert(c);
	extraVaccines--;
}
void Government::reserveVaccine()
{
	cout<<"Do you have an emergency?\n1. Yes\n2. No"<<endl;
	int choice;cin>>choice;
	int s1;
	if(choice==1) {urgentReservation();return;}
	Citizen c;
	bool isEligible = c.accept();
	vaccinesPerSlot = numVaccines/numSlots;
	if(!isEligible) return;//check for eligibility
	int s = available();
	if(s==0){//no space in confirmed array, thus will be enqueued in the waiting list
		do{
		cout<<"For future reference, enter your slot preference : "<<endl;
		cin>>c.slot;
		}while(c.slot>numSlots ||c.slot<=0);
		c.status = "Unconfirmed";
		waitingList.priorityEnqueue(c);
		waitingList.search(c.aadhar)->c.citizenAhead = waitingList.citizenAhead(c.aadhar);//to check number of people ahead in the waiting list
		waitingList.search(c.aadhar)->c.display();//display information about user and his/her status.
	}
	else{
		confirmed[s-1].insert(c);//insertion in linked list in the array
		allocatedSlotCount[s-1]++;
		Node* ptr = confirmed[s-1].search(c.aadhar);
		ptr->c.slot = s;//status updation
		ptr->c.status = "Confirmed!";
		ptr->c.display();
	}
}
void Government::cancelReservation()
{
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
		if(!waitingList.isEmpty())
		{   //implies that citizen in the waiting list has been promoted to the position of the deleted citizen in the confirmed array
			Citizen temp;
			temp= waitingList.dequeue();
			ptr->c.aadhar=temp.aadhar;
			ptr->c.name=temp.name;
			ptr->c.age=temp.age;
			ptr->c.slot = idx+1;
			ptr->c.status = "Confirmed!";
			ptr->c.display();
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
void Government::modify()
{
	cout<<"Enter your Aadhar number to update your vaccination status."<<endl;
	long a; cin>>a;
	Node* ptr  = l.search(a);//check in government record linked list.
	if(ptr==NULL)
	{//if Null, implies the Citizen received the vaccination for the first time.
		for(int i=0;i<numSlots;i++)
		{//check in confirmed array.
			Node* n = confirmed[i].search(a);
			if(n!=NULL){
				ptr = n;
				break;
			}
		}
		l.insert(ptr->c);//inserting the node in government record linked list.
		numVaccinatedOnlyOnce++;
		if(ptr==NULL)
		{//Node cannot be found in confirmed array.
			cout<<"You are not registered in the vaccination portal."<<endl;
			return;
		}
	}
	else{//implies the Citizen received the vaccination for the second time.
		ptr->c.numTimesVaccinated++;//modify the node details.
		numVaccinatedOnlyOnce--;
		numVaccinatedTwice++;
	}
	cout<<"You have successfully modified the database. Thank you!"<<endl;
	bool isDelete = confirmed[ptr->c.slot - 1].deleteNode(a);//delete node from the confirmed array
	allocatedSlotCount[ptr->c.slot - 1]--;
}
void Government::modifyEndOfDay()
{//should be accessible only to the government administrator
	cout<<"Welcome administrator! Enter your password : "<<endl;
		string s;
		cin>>s;
	if(s.compare(password)!=0){
			cout<<"Incorrect password."<<endl;
			return;
	}
	Node* ptr = waitingList.front;
	/*
	 * NOTE: Working flow and goal :
	 * 1. At the end of the day, prioritize all citizens including the young to the highest priority, i.e 1.
	 * 2. Then depending on the number of vaccines available tomorrow, those many people will be dequeued(depending on the preference of slot and availability) and filled in the confirmed array.
	 * 3. If the confirmed array is not empty, then the citizens who reserve vaccine tomorrow, will get the slot.
	 */
	while(ptr!=NULL){//At the end of the day, prioritize all Citizens to the highest priority.
		ptr->c.priority = 1;
		ptr = ptr->next;
	}
	cout<<"The number of people vaccinated only once : "<<numVaccinatedOnlyOnce<<endl;
	cout<<"The number of people vaccinated twice : "<<numVaccinatedTwice<<endl;
	allocatedSlotCount[0]=allocatedSlotCount[1]=0;
	confirmed[0].head=confirmed[1].head=NULL;
}
void Government::checkStatus()
{//Displays the current status of the citizen's vaccination
		cout<<"Enter your Aadhar number to check your reservation."<<endl;
		long a; cin>>a;
		Node* ptr=NULL;
		//int idx=0;
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
void Government::govtInterface()
{//only accessible to a government administrator
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
	extraVaccines = (numVaccines%numSlots) + extraVaccines;
	if(!waitingList.isEmpty()){
	Node* ptr = waitingList.front;

	int i=0;
	while(i!=numVaccines){

		if(ptr==NULL)
			return;
		else if(allocatedSlotCount[ptr->c.slot - 1]<vaccinesPerSlot)
		{//it should be less or else extra 1 person will enter
				ptr->c.status = "Confirmed!";

				confirmed[ptr->c.slot - 1].insert(ptr->c);

				allocatedSlotCount[ptr->c.slot - 1]++;

				bool isDelete = waitingList.deleteNodeWaitingList(ptr->c.aadhar);

				i++;
			}
		ptr = ptr ->next;
	}

	}
}
