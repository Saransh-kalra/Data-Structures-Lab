//
//  lab_05.cpp
//  CS_2413_lab_05
//
//  Created by Saransh Kalra on 10/14/18.
//  Copyright © 2018 Saransh Kalra. All rights reserved.
//

#include "lab_05.hpp"
#include <stdio.h>
#include <iostream>

using namespace std;

//Initialising the head and tail pointers to NULL
LinkedList::LinkedList(){
    this->head=this->tail=NULL;
}

//deconstructor to free the memory occupied by linked list
LinkedList::~LinkedList(){
    
    //while the head doesn't reach till node, traverse through the list and free the memory occupied by each node
    while(this->head!=NULL)
    {
        Node *ptr;
        ptr = this->head;
        this->head = this->head->next;
        delete ptr;
    }
}

//member function to insert a node at the head of the linked list
void LinkedList::insertAtHead(int value){
    //if head is NULL, means the list is empty, put the info in the first node and make the tail as head too as single node is both the head and tail
    if(this->head==NULL){
        //initialise a pointer to store the new info to be added
        Node *ptr = new Node();
        ptr->info=value;
        //the new pointer's next node is the old head
        ptr->next=this->head;
        //the updated head points to the new pointer now
        this->head=ptr;
        //making the tail to be the head
        this->tail=this->head;
    }
    
    else{
        //same as above just dont make the head the tail this time as this is not the first node
        Node *ptr = new Node();
        ptr->info=value;
        ptr->next=this->head;
        this->head=ptr;
    }
}

//member function to insert a node at the tail of the linked list
void LinkedList::insertAtTail(int value){
    
    //if tail is NULL, means the list is empty, put the info in the first node and make the head as tail too as single node is both the head and tail
    if(this->tail==NULL){
        //initialise a pointer to store the new info to be added
        Node *ptr = new Node();
        ptr->info=value;
        //the old tail's pointer to next node is the new pointer
        this->tail->next=ptr;
        //the updated tail points to the new pointer now
        this->tail=ptr;
        //making the head to be the tail
        this->head=this->tail;
    }
    
    else{
        //same as above just dont make the tail the head this time as this is not the first node
        Node *ptr = new Node();
        ptr->info=value;
        ptr->next=NULL;
        this->tail->next=ptr;
        this->tail=ptr;
    }
}

//Print the info value before deletion of the node and then deleting the node at the head of the linked list
void LinkedList::deleteAtHead(){
    //if the head points to NULL, means the list is empty, therefore error message printed
    if(this->head==NULL){
        cout<<"there is nothing to be deleted, the list is empty"<<endl;
    }
    //if the head's next points to NULL, means there is just one record so print deleted info and make both the head and tail to be NULL, making the list to be empty
    else if(this->head->next==NULL){
        cout<<"The value being deleted is: "<<this->head->info<<endl;
        Node *temp = this->head;
        this->head=this->tail=NULL;
        delete temp;
    }
    //else just make the head to be its next and print the old head info before that
    else{
        cout<<"The value being deleted is: "<<this->head->info<<endl;
        Node *temp = this->head;
        this->head=this->head->next;
        delete temp;
    }
    
}

//Print the info value before deletion of the node and then deleting the node at the tail of the linked list
void LinkedList::deleteAtTail(){
    //if the head points to NULL, means the list is empty, therefore error message printed
    if(this->head==NULL){
        cout<<"there is nothing to be deleted, the list is empty"<<endl;
    }
    //if the head's next points to NULL, means there is just one record so print deleted info and make both the head and tail to be NULL, making the list to be empty
    else if(this->head->next==NULL){
        cout<<"The value being deleted is: "<<this->tail->info<<endl;
        Node *temp = this->tail;
        this->head=this->tail=NULL;
        delete temp;
    }
    //else just make the tail's next to be NULL, and the old tail to be the previous record of tail
    else{
        cout<<"The value being deleted is: "<<this->tail->info<<endl;
        Node *ptr = this->head;
        //do that by traversing the list till the pointer whose next is NULL, to find the record who's next is tail and then make it the tail of the linked list
        while(ptr->next!=this->tail){
            ptr=ptr->next;
        }
        Node *temp = this->tail;
        this->tail=ptr;
        this->tail->next=NULL;
        delete temp;
    }
}

//function for deleting the smallest info out  of the whole linked list
void LinkedList::deleteSmallest(){
    //if the head points to NULL, means the list is empty, therefore error message printed
    if(this->head==NULL){
        cout<<"there is nothing to be deleted, the list is empty"<<endl;
    }
    //if head equals tail, there is only one element in the list, so delete that
    else if(this->head==this->tail) {
        Node *temp = this->head;
        cout<<"The smallest value being deleted is: "<<temp->info<<endl;
        this->head = this->tail = NULL;
        delete temp;
    }
    //else just find the minimum and delete that
    else {
        //a pointer to traverse the list starting from the next of the head
        Node *ptr = this->head->next;
        //a pointer to keep record of the previous pointer starting at the head
        Node *prev = this->head;
        //initial minimum set to the head, giving the reason being the transversal pointer is initialised to next of head
        Node *minimum = this->head;
        //initial previous of minimum set to be NULL
        Node *minimum_prev = NULL;
        //traversing the list till the pointer comes to tail to find minimum
        while(ptr!=NULL){
            //if the traversing pointer has info less than minimum set minimum to that record and the previous to the minimum to the new previous pointer
            if(ptr->info < minimum->info) {
                minimum = ptr;
                minimum_prev = prev;
            }
            //move traversal pointer and previous pointer to the next
            prev = prev->next;
            ptr = ptr->next;
        }
        //mode pointer made to store the node that has to deleted
        Node *temp = minimum;
        //if minimum is head then just make the head point to the next of head
        if(minimum==this->head){
            this->head=this->head->next;
        }
        //if minimum is the tail then make the new tail to be previous of the minimum and the next to be NULL
        else if(minimum==this->tail) {
            this->tail=minimum_prev;
            minimum_prev->next = NULL;
        }
        //else just set the next of the previous of minimum to be the next of the minimum
        else {
            minimum_prev->next = minimum->next;
        }
        //print what's being deleted and delete the record
        cout<<"The smallest value being deleted is: "<<temp->info<<endl;
        delete temp;
        
    }
}

//function to remove the duplicates of the number in the linked list
void LinkedList::removeDuplicates(int number){
    //flag variable to indicate whether value was found or not
    int flag=0;
    //if head points to NULL, means the list is empty
    if(this->head==NULL)
        cout<<"The whole list is empty, so the record was not found"<<endl;
    //else traverse the whole linked list to find if some node's info matches with the given info
    else{
        //pointers to point to previous and the pointer for traversal
        Node *ptr = this->head;
        Node *prev = this->head;
        //loop to traverse through the list
        while(ptr!=NULL){
            //if we find the number in the linked list in the traversal
            if(ptr->info==number){
                //store the pointer to be deleted and previous pointer to it
                Node* del = ptr;
                Node* del_prev = prev;
                //if the head is being deleted, update the head
                if(del==this->head) {
                    this->head=this->head->next;
                    //keep the previous at the new head
                    prev = this->head;
                }
                //else if the tail is being deleted, update the tail
                else if(del==this->tail) {
                    this->tail = del_prev;
                    this->tail->next = NULL;
                }
                //else just connect the previous's next to the delted's next
                else {
                    del_prev->next = del->next;
                }
                //update the flag to 1 to indicate that the record was found
                flag=1;
                //update the previous pointer only when the head is not the number to be deleted
                if(del!=this->head) {
                    ptr=ptr->next;
                }
                //print the deleted node's info and delete that node
                cout<<"The value being deleted is: "<<del->info<<endl;
                delete del;

            }
            //else just update the prev and traversal pointer
            else {
                if(ptr!=this->head) {
                    prev=prev->next;
                }
                ptr=ptr->next;
            }
            
        }
        //error message if info was not found
        if(flag==0){
            cout<<"The given value "<<number<<" was not found in the list!"<<endl;
        }
    }
}

//member function to search the given info found at which node of a linked list
void LinkedList::search(int value){
    //counter variable to count at which position given info was found
    int count=0;
    //flag variable to indicate whether value was found or not
    int flag=0;
    //if head points to NULL, means the list is empty
    if(this->head==NULL)
        cout<<"The whole list is empty, so the record was not found"<<endl;
    //else traverse the whole linked list to find if some node's info matches with the given info
    else{
        Node *ptr = this->head;
        while(ptr->info!=value && ptr!=this->tail){
            ptr=ptr->next;
            count++;
            if(ptr->info==value){
                flag=1;
            }
        }
        //error message if info was not found
        if(flag==0){
            cout<<"The given value "<<value<<" was not found in the list!"<<endl;
        }
        else{
            cout<<"The value "<<value<<" was found and its the no. "<<count+1<<" record."<<endl;
        }
    }
}

//member function to display the linked list
void LinkedList::displayList(){
    //if head points to NULL, the list is empty
    if(this->head==NULL){
        cout<<"The whole list is empty, nothing to display."<<endl;
    }
    //else traverse through the list displaying each node's info followed by an arrow
    else{
        Node *ptr;
        ptr = this->head;
        while(ptr!=NULL){
            cout<<ptr->info<<"->";
            ptr = ptr->next;
        }
        cout<<endl;
    }
}
