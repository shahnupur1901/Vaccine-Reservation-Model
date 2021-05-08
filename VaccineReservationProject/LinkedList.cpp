/*
 * LinkedList.cpp
 *
 *  Created on: 08-May-2021
 *      Author: nupur
 */

#include "LinkedList.h"
#include "Citizen.h"
#include "Government.h"
#include "LinkedList.h"
#include "Queue.h"
#include "Node.h"
LinkedList::LinkedList() {
	// TODO Auto-generated constructor stub
	head = NULL;
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

void LinkedList::insert (Citizen c1)
{
Node *temp= new Node();
temp->c=c1;
if(head==NULL){
head=temp;
}
else{
Node *ptr=head;
while(ptr->next!=NULL){
ptr=ptr->next;
}
ptr->next=temp;
temp->prev=ptr;
}




}
void LinkedList::deleteNode(long aadhar_search)
{


int flag=0;
if(head==NULL)
{
   cout<<"The list is empty "<<endl;
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
head->prev=NULL;
delete ptr;

}
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
}

}
else
{
cout<<"There is no such entry "<<endl;
}
}

}

Node* LinkedList::search(long to_search){
Node *ptr=head;
int flag=0;
if(head==NULL)
{
   cout<<"The list is empty "<<endl;
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
    cout<<"You have an entry "<<endl;
    return ptr;
    }
    else
    {
    cout<<"You don't have an entry "<<endl;
    return NULL;
    }
}
}



