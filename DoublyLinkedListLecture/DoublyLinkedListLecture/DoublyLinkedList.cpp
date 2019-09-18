//
//  DoublyLinkedList.cpp
//  DoublyLinkedListLecture
//
//  Created by Saransh Kalra on 9/28/18.
//  Copyright © 2018 Saransh Kalra. All rights reserved.
//

#include "DoublyLinkedList.hpp"
#include<iostream>
using namespace std;

Node::Node(int num) {
    this->datum = num;
    this->next = NULL;
    this->prev = NULL;
}

int Node::get_datum() {
    return this->datum;
}
void Node::set_datum(int num) {
    this->datum = num;
}

Node* Node::get_next() {
    return this->next;
}

void Node::set_next(Node *next) {
    this->next = next;
}
Node* Node::get_prev() {
    return this->prev;
}

void Node::set_prev(Node* prev) {
    this->prev = prev;
}

LinkedList::LinkedList() {
    this->size = 0;
    this->head = NULL;
    this->tail = NULL;
}

LinkedList::~LinkedList() {
    destr_helper(this->head);
}

void LinkedList::destr_helper(Node *node) {
    if (node) {
        destr_helper(node->get_next()); // delete node; is not before recursive because we don't want to lose reference to other nodes
        delete node;
    }
}

void LinkedList::insert(int index, int value) {
    if (index<0 || index>this->size) {
        throw "index out of bounds";
    }
    
    Node *newNode = new Node(value);
    
    if (index == 0) {
        // newNode->next = this->head is an error becasue
        // Node->next is private
        if (this->head) {
            this->head->set_prev(newNode);
        }
        newNode->set_next(this->head);
        this->head = newNode;
        if (!this->tail) {
            this->tail = this->head;
        }
    }
    else if (index == this->size) {
        this->tail->set_next(newNode);
        newNode->set_prev(this->tail);
        this->tail = newNode;
    }
    else
    {
        Node *temp = this->head;
        for (int i = 1; i < index; i++, temp = temp->get_next()); // temp is always behind i
        newNode->set_next(temp->get_next());//
        if (temp->get_next()) { // don't really need the if statement because we already took care of it in the
            temp->get_next()->set_prev(newNode);// else if statement
        }
        newNode->set_prev(temp);
        temp->set_next(newNode);
    }
    
    this->size++;
}

int LinkedList::remove(int index) {
    if (index<0 || index >= this->size) {
        throw "index out of bounds";
    }
    
    Node *temp;
    if (index == 0) {
        temp = this->head;
        this->head = temp->get_next();
        // we will delete after if else statement
        if (this->head) {
            this->head->set_prev(NULL);
        }
        else {
            this->tail = NULL;
        }
    }
    else if (index == (this->size - 1)) {
        temp = this->tail;
        this->tail = this->tail->get_prev();
        this->tail->set_next(NULL);
        
    }
    else {
        Node *temp2 = this->head;
        for (int i = 1; i < index; i++, temp2 = temp2->get_next());
        temp = temp2->get_next();
        temp2->set_next(temp->get_next());
        if (temp->get_next()) {
            temp->get_next()->set_prev(temp2); // the prev of the node after temp is changed to point to temp2
        }
    }
    int retVal = temp->get_datum();
    delete temp;
    this->size--;
    return retVal;
}

int LinkedList::get_size() {
    return this->size;
}
int LinkedList::get(int index) {
    if (index<0 || index >= this->size) {
        throw "index out of bounds";
    }
    Node* temp = this->head;
    for (int i = 0; i < index; i++, temp = temp->get_next());
    return temp->get_datum();
}
void LinkedList::set(int index, int value) {
    if (index<0 || index >= this->size) {
        throw "index out of bounds";
    }
    Node* temp = this->head;
    for (int i = 0; i < index; i++, temp = temp->get_next());
    temp->set_datum(value);
}
void LinkedList::print_list() {
    cout << "{";
    if (this->head) {
        cout << " " << this->head->get_datum();
        Node* temp;
        for (temp = this->head->get_next(); temp; temp = temp->get_next()) {
            cout << ", " << temp->get_datum();
            
        }
    }
    cout << " }" << endl;
}
