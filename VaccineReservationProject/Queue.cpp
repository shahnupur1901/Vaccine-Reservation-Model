/*
 * Queue.cpp
 *
 *  Created on: 08-May-2021
 *      Author: nupur
 */

#include "Queue.h"
#include "Government.h"
#include "LinkedList.h"
#include "Queue.h"
#include "Node.h"
#include "Citizen.h"
#include "Government.h"
#include "LinkedList.h"
Queue::Queue() {
	// TODO Auto-generated constructor stub
	front = rear = NULL;
}
void Queue::enqueue(Citizen input)
{
	Node *temp=new Node();
	temp->c=input;
	if(rear==NULL)//i.e.the queue was empty
	{
		rear=temp;
		front=temp;//front will remain at this node till you deque
	}
	else
	{//code of inserting node at head in DLL
		rear->next=temp;
		temp->prev=rear;
		rear=temp;
	}
	cout<<"The Citizen is added to waiting list"<<endl;
}

void Queue::search(long key)
{
	Node *ptr;
	int flag=0;
	ptr=front;
	while(ptr!=NULL)
	{
		if(key==ptr->c.getAadhar()){
			flag=1;
			break;
		}
		ptr=ptr->next;
	}
	if(flag==0){cout<<"the Citizen has no slots in the waiting queue and confirmed list also"<<endl;}
	else{
		cout<<"Your entry is in the waiting queue"<<endl;
	}
	}
void Queue::deleteNode(long key)
{
	Node *ptr=front;
	int flag=0;
	if(isEmpty()){cout<<"The waiting list is empty."<<endl;}
	else
	{
		while(ptr!=NULL)
		{
			if(ptr->c.getAadhar()==key)
			{
				flag=1;//when key is found
				break;
			}
			ptr=ptr->next;//always remember or else loop will run for infinity
		}
		if(flag==0){cout<<"There are no bookings by this name "<<endl;}//when key not found flag remains 0
		else if(ptr->next==NULL)
		{
			ptr->prev->next=NULL;
			delete ptr;
		}
		else
		{
			ptr->prev->next=ptr->next;
			ptr->next->prev=ptr->prev;
			delete ptr;
			cout<<"The booking is cancelled from waiting list"<<endl;
		}
	}
}
bool Queue::isEmpty()
{
	if(rear==NULL)
		return true;
	else
		return false;

}
Citizen Queue::dequeue()
{
	Citizen temp;
	if(front==NULL) return temp;
	Node *ptr=front;
	temp=ptr->c;
	front=front->next;
	delete(ptr);
	return temp;
}


