//
//  StackQueue.cpp
//  stacks_queues_lecture
//
//  Created by Saransh Kalra on 10/1/18.
//  Copyright © 2018 Saransh Kalra. All rights reserved.
//

#include "StackQueue.hpp"

Node::Node(int datum) {
    this->datum = datum;
    this->next = 0;
    this->prev = 0;
}

Node::~Node(){
    
}

int Node::get_datum(){
    return this->datum;
}

void Node::set_datum(int datum){
    this->datum = datum;
}

Node* Node::get_next(){
    return this->next;
}

void Node::set_next(Node* next){
    this->next = next;
}

Node* Node::get_prev(){
    return this->prev;
}

void Node::set_prev(Node* prev){
    this->prev = prev;
}

StackQueue::StackQueue(){
    this->head=0;
    this->tail=0;
}

StackQueue::~StackQueue(){
    destr_helper(this->head);
}

void StackQueue::destr_helper(Node* node){
    if (node) {
        destr_helper(node->get_next());
        delete node;
    }
}

void StackQueue::push(int num){
    Node *newNode = new Node(num);
    
    newNode->set_next(this->head);
    if(this->head) {
        this->head->set_prev(newNode);
    }
    else{
        this->tail = newNode;
    }
    this->head = newNode;
}

int StackQueue::stack_pop() {
    if (!this->head) {
        throw "Stack is empty";
    }
    
    Node *temp = this->head;
    this->head = temp->get_next();
    if (this->head){
        this->head->set_prev(0);
    }
    int datum = temp->get_datum();
    delete temp;
    return datum;
}

int StackQueue::stack_peek() {
    if(this->head){
        return this->head->get_datum();
    }
    else {
        throw "Stack is empty";
    }
}

int StackQueue::queue_pop() {
    if(!this->tail) {
        throw "the queue is empty";
    }
    Node *temp = this->tail;
    this->tail = temp->get_prev();
    if(this->tail) {
        this->tail->set_next(0);
    }
    
    else {
        this->head = 0;
    }
    int datum = temp->get_datum();
    delete temp;
    return datum;
}

int StackQueue::queue_peek() {
    if(this->tail){
        return this->tail->get_datum();
    }
    else {
        throw "the queue is empty";
    }
}
