#include "LinkedList.h"
#include "Citizen.h"
#include "Government.h"
#include "Queue.h"
#include "Node.h"
LinkedList::LinkedList() {
	// TODO Auto-generated constructor stub
	head = NULL;
}
void LinkedList::insert (Citizen c)
{
	Node *temp= new Node();
	temp->c=c;
	if(head==NULL)
	{
		head=temp;
	}
	else
	{
		Node *ptr=head;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=temp;
		temp->prev=ptr;
	}

}
bool LinkedList::deleteNode(long aadhar_search)
{
	int flag=0;
	if(head->c.aadhar==aadhar_search)
	{
		head=head->next;
		delete ptr;
		return true;
	}
	if(head==NULL)
	{
	   return false;
	}
	else
	{
		Node *ptr= head;
		while(ptr!=NULL)
		{
			if(ptr->c.aadhar==aadhar_search)
			{
				flag=1;
				break;
			}
			ptr=ptr->next;
		}
		if(flag==1)
		{
			if(ptr==head)
			{
				head=head->next;
				delete ptr;
				return true;
			}
			else if(ptr->next==NULL)
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
		else
		{
			return false;
		}
	}
}
Node* LinkedList::search(long to_search){
	Node *ptr=head;
	int flag=0;
	if(head==NULL)
	{
	    return NULL;
	}
	else
	{
    	while(ptr!=NULL)
    	{
    		if(ptr->c.aadhar==to_search)
    		{
    			flag=1;
    			break;
    		}
    		ptr=ptr->next;
    	}
    	if(flag==1)
    	{
    		return ptr;
    	}
    	else
    	{
    		//cout<<"You don't have an entry "<<endl;
    		return NULL;
    	}
	}
}
bool LinkedList::is_empty()
{
	if(head==NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}
