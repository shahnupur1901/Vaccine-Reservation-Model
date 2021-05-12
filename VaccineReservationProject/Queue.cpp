#include "Queue.h"
#include "Government.h"
#include "LinkedList.h"
#include "Queue.h"
#include "Node.h"
#include "Citizen.h"
#include "Government.h"
#include "LinkedList.h"
Queue::Queue() {
	front = rear = NULL;
}

void Queue::priorityEnqueue(Citizen input)
{
	Node *temp=new Node();
	temp->c=input;
	if(rear==NULL)//i.e.the queue was empty
	{
		rear=temp;
		front=temp;//front will remain at this node till you dequeue
	}
	else{
		Node* ptr = front;
		while(ptr->c.priority <= input.priority){//check where to enter the temp node
			if(ptr==rear){//at the end
				rear->next = temp;
				temp->prev = rear;
				rear = temp;
				return;
			}
			ptr = ptr->next;
		}
		if(ptr==front){//at the start
			front->prev = temp;
			temp->next = front;
			front = temp;
			return;
		}
		Node* previous = ptr->prev;//in the middle
		temp->prev = previous;
		temp->next = ptr;
		previous->next = temp;
		ptr->prev = temp;
	}
}
Node* Queue::search(long key)
{
	Node *ptr;
	int flag=0;
	ptr=front;
	while(ptr!=NULL)
	{
		if(ptr->c.aadhar==key)
		{
			flag=1;
			break;
		}
		ptr=ptr->next;
	}
	if(flag==0){return NULL;}
	else{return ptr;}
}
Citizen Queue::dequeue()
{
	Citizen temp;
	Node *ptr=front;
	temp=ptr->c;
	front=front->next;
	delete(ptr);
	return temp;
}
bool Queue::isEmpty()
{
	if(rear==NULL)
	{
		return true;}
	else
	{
	return false;
	}
}
bool Queue::deleteNodeWaitingList(long key)
{
	Node *ptr=front;
	int flag=0;

	while(ptr!=NULL)
	{
		if(ptr->c.aadhar==key)
		{
			flag=1;//when key is found
			break;
		}
		ptr=ptr->next;//always remember or else loop will run for infinity
	}
	if(flag==0){return false;}//when key not found flag remains 0
	else if(ptr==front)//if first node
	{
		front=front->next;
		front->prev = NULL;
		delete ptr;
		return true;
	}
	else if(ptr->next==NULL)//if last node
	{
		ptr->prev->next = NULL;
		delete ptr;
		return true;
	}
	else
	{
		ptr->prev->next=ptr->next;
		ptr->next->prev=ptr->prev;
		delete ptr;
		return true;
	}
}

int Queue::citizenAhead(long key){
	Node* ptr2 = search(key);
	Node* ptr1 = front;
	int count = 0;
	while(ptr1!=ptr2){
		ptr1 = ptr1->next;
		count++;
	}
	return count;
}
