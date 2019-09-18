//
//  lab5_part_2.cpp
//  CS_2403_lab_05_part_2
//
//  Created by Saransh Kalra on 10/15/18.
//  Copyright © 2018 Saransh Kalra. All rights reserved.
//

#include "lab5_part_2.hpp"

#include <iostream>

using namespace std;

//constructor for node  class
Node::Node(int info){
    //set info to the info of the node
    this->info = info;//next of the node is set to null
    this->next = 0;
}

//no need of deconstructor as queue deconstructor handles these
Node::~Node(){
    
}

//getter for the info of the class node
int Node::get_info(){
    return this->info;
}

//setter for the info of the class node
void Node::set_info(int info){
    this->info = info;
}

//getter for the next of the node class
Node* Node::get_next(){
    return this->next;
}

//setter for the next of the node class
void Node::set_next(Node *next){
    this->next = next;
}

//constructor for the queue class
Queue::Queue(){
    this->head=0;
    this->tail=0;
    this->size=0;
}

//deconstructor for the queue class
Queue::~Queue(){
    Node *temp = this->head;
    while(temp!=NULL){
        temp = temp->get_next();
        delete temp;
    }
}

//enqueue function for the queue class
void Queue::queue_enqueue(int info){
    //new node to be added with info as the argument
    Node *newNode = new Node(info);
    //we are pushing it on the head, so make the next of new node to be head
    newNode->set_next(this->head);
    //if head is null and new node is the first node then the new node is also the tail
    if(!this->head) {
        this->tail = newNode;
    }
    //the new head is the new node
    this->head = newNode;
    this->size++;
}

int Queue::queue_dequeue(){
    //if tail is null, queue is empty give error
    if(!this->tail) {
        cout<<"Queue is empty! no. of items avilable to dequeue: "<<endl;
        return 0;
    }
    else{
        this->size--;
        //if the next of head is null, there is only one element which will be deleted
        if(this->head->get_next()==NULL){
            //temp for storing the value that is being dequeued
            int temp = this->tail->get_info();
            //deleting the node at tail
            delete this->tail;
            cout<<"The value being popped is: "<<endl;
            //as this was the last element make the head and tail point to null making teh list empty
            this->head=this->tail=NULL;
            return temp;
        }
        else{
            cout<<"The value being popped is: "<<endl;
            //else make a tranversal pointer with starts as head
            Node *ptr = this->head;
            //traverse till it doesn't reach the node previous to tail
            while(ptr->get_next()!=this->tail){
                ptr=ptr->get_next();
            }
            //temp for storing the value that is being dequeued
            int temp = this->tail->get_info();
            //delete the node at tail
            delete this->tail;
            //setting the traversed pointer as teh new tail
            this->tail=ptr;
            //setting its next to be null as its the end of teh queue
            this->tail->set_next(NULL);
            //returning the removed value
            return temp;
        }
    }
    
}

//peek function for queue
int Queue::queue_peek(){
    //if tail is not null, return the tail as the last value on the queue
    if(this->tail){
        cout<<"Last Item in queue: ";
        return this->head->get_info();
    }
    //else error message that stack is empty
    else {
        cout<<"queue is empty! Items in Queue: ";
        return 0;
    }
}

//function to move the nth record to the front
void Queue::moveNthFront(int n){
    //if index is out of bounds check
    if(n<=0 || n>this->size) {
        //empty queue check
        if(!this->tail){
            cout<<"Queue is empty nothing to move! "<<endl;
        }
        else {
            cout<<"index out of bounds!"<<endl;
        }
    }
    else {
        //counter for keeping record number
        int count = 0;
        //pointer from traversal initialised to next of head and prev initialised from head
        Node *ptr = this->head->get_next();
        Node *prev = this->head;
        //if n is 1 means move the item at first of queue, so no need just give an error saying the value is already at front
        if(n==1) {
            cout<<"the value is already at the front"<<endl;
        }
        //else if its the last on the list move the head to its next and set the tail i.e. front of the queue to the old head
        else if(n==this->size) {
            Node* temp = this->head;
            this->head = this->head->get_next();
            this->tail->set_next(temp);
            this->tail = temp;
            this->tail->set_next(NULL);
        }
        //else just start from head traverse till size-n as it takes entries from head and takes off from head so the entry number the user wants is from counted from the tail
        else {
            while(ptr) {
                count++;
                if(count == (this->size-n)) {
                    prev->set_next(ptr->get_next());
                    this->tail->set_next(ptr);
                    this->tail = ptr;
                    this->tail->set_next(NULL);
                }
                ptr = ptr->get_next();
                prev = prev->get_next();
            }
        }
    }
}

//function for printing the queue
void Queue::queue_print(){
    //if head is NULL, error queue is empty
    if(!this->head){
        cout<<"queue is empty!"<<endl;
    }
    else{
        //create a temp node for traversing starting for head
        Node *temp = this->head;
        cout<<"{ ";
        //while temp is not null
        while(temp){
            cout<<temp->get_info()<<"->";
            temp = temp->get_next();
        }
        cout<<" }"<<endl;
        cout<<"size: "<<this->size<<endl;
    }
}

//function to check if the queue is empty
void Queue::queue_isEmpty(){
    //if head is not null its not empty
    if(this->head){
        cout<<"no! queue isn't empty. "<<endl;
    }
    else{
        cout<<"yes! the queue is empty. "<<endl;
    }
}
