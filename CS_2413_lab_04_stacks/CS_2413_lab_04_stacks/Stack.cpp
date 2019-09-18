//
//  Stack.cpp
//  CS_2413_lab_04_stacks
//
//  Created by Saransh Kalra on 10/10/18.
//  Copyright © 2018 Saransh Kalra. All rights reserved.
//

#include "Stack.hpp"
#include <iostream>

using namespace std;

//constructor for node  class
Node::Node(int info){
    //set info to the info of the node
    this->info = info;
    //next of the node is set to null
    this->next = 0;
}

//no need of deconstructor as stack deconstructor handles these
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

//constructor for the stack class
Stack::Stack(){
    this->head=0;
}

//deconstructor for the stack class
Stack::~Stack(){
    Node *temp = this->head;
    while(temp!=NULL){
        temp = temp->get_next();
        delete temp;
    }
}

//push function for stack class
void Stack::stack_push(int info){
    //new node to be added with info as the argument
    Node *newNode = new Node(info);
    //we are pushing it on the head, so make the next of new node to be head
    newNode->set_next(this->head);
    //make the new node as the new head
    this->head = newNode;
}

//pop function for stack class
int Stack::stack_pop(){
    //error if the list is empty
    if (!this->head) {
        cout<<"Stack is empty! no of items avilable to pop: "<<endl;
        return 0;
    }
    else{
        //take a temporary node intialise to head
        Node *temp = this->head;
        //the head is now the next of the head
        this->head = temp->get_next();
        //take a variable to store the popped value
        int info = temp->get_info();
        //delete the deleted node
        delete temp;
        cout<<"Item popped: ";
        //return the value
        return info;
    }
}

//peek function for stack
int Stack::stack_peek(){
    //if head is not null, return the head as the top value on the stack
    if(this->head){
        cout<<"Last Item in stack: ";
        return this->head->get_info();
    }
    //else error message that stack is empty
    else {
        cout<<"Stack is empty! Items in Stack: ";
        return 0;
    }
}

//function for printing the stack
void Stack::stack_print(){
    //if head is NULL, error stack is empty
    if(!this->head){
        cout<<"stack is empty!"<<endl;
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
    }
}

//function to check if the stack is empty
void Stack::stack_isEmpty(){
    if(this->head){
        //if head is not null its not empty
        cout<<"no! stack isn't empty "<<endl;
    }
    else{
        cout<<"yes! the stack is empty "<<endl;
    }
}

