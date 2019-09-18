//
//  heap.cpp
//  Heap_lecture
//
//  Created by Saransh Kalra on 10/24/18.
//  Copyright © 2018 Saransh Kalra. All rights reserved.
//

#include "heap.hpp"

Node::Node(int datum){
    this->datum = datum;
    this->left  = 0;
    this->right = 0;
    this->parent = 0;
}

int Node::get_datum(){
    return this->datum;
}

void Node::set_datum(int datum){
    this->datum = datum;
}

Node* Node::get_left(){
    return this->left;
}

void Node::set_left(Node *left){
    this->left = left;
}

Node* Node::get_right(){
    return this->right;
}

void Node::set_right(Node *right){
    this->right = right;
}

Node* Node::get_parent(){
    return this->parent;
}

void Node::set_parent(Node *parent){
    this->parent = parent;
}

Heap::Heap() {
    this->root = 0;
    this->tail = 0;
}

Heap::~Heap() {
    this->destr_helper(this->root);
}

//like post order traversal of the tree
void Heap::destr_helper(Node* node){
    if(node){
        this->destr_helper(node->get_left());
        this->destr_helper(node->get_right());
        delete node;
    }
}

void Heap::insert(int num) {
    this->place_node(num);
    this->upheap();
}

int Heap::remove() {
    if(!this->root) {
        throw "Heap is empty!";
    }
    int retval = this->root->get_datum();
    this->root->set_datum(this->tail->get_datum());
    this->reset_tail();
    this->downheap();
    return retval;
}

void Heap::place_node(int num) {
    Node *newNode = new Node(num);
    
    if(!this->root) {
        this->root = newNode;
        this->tail = newNode;
    }
    else {
        Node *temp = this->tail;
        //go up as long as there is a parent and we are not a left node
        while (temp->get_parent() && temp == temp->get_parent()->get_right()) {
            temp = temp->get_parent();
        }
        //if there is a parent go up one more
        if (temp->get_parent()) {
            temp = temp->get_parent();
        }
        if (!temp->get_right()) {
            temp->set_right(newNode);
        }
        else {
            temp = temp->get_right();
            while (temp->get_left()) {
                temp = temp->get_left();
            }
            temp->set_left(newNode);
        }
        newNode->set_parent(temp);
        this->tail = newNode;
    }
}

void Heap::upheap() {
    //min heap
    Node *temp = this->tail;
    while (temp->get_parent() && temp->get_datum() < temp->get_parent()->get_datum()) {
        int tempInt = temp->get_datum();
        temp->set_datum(temp->get_parent()->get_datum());
        temp->get_parent()->set_datum(tempInt);
        temp = temp->get_parent();
    }
}

void Heap::reset_tail() {
    if(!this->root) {
        throw "heap is empty";
    }
    Node *temp = this->tail;
    Node *remNode = this->tail;
    
    while (temp->get_parent() && temp == temp->get_parent()->get_left()) {
        temp = temp->get_parent();
    }
    if (temp->get_parent()) {
        temp = temp->get_parent();
    }
    if (temp->get_left()) {
        temp =temp->get_left();
    }
    if (temp->get_parent()) {
        while (temp->get_right()) {
            temp = temp->get_right();
        }
        this->tail = temp;
        if (remNode->get_parent()->get_left() == remNode) {
            remNode->get_parent()->set_left(0);
        }
        else {
            remNode->get_parent()->set_right(0);
        }
    }
    else {
        this->root = 0;
        this->tail = 0;
    }
    delete remNode;
}

void Heap::downheap() {
    Node* temp = this->root;
    while (temp->get_left() || temp->get_right()) {
        if (temp->get_left() && !temp->get_right()) {
            if (temp->get_datum() > temp->get_left()->get_datum()) {
                int temp_num = temp->get_datum();
                temp->set_datum(temp->get_left()->get_datum());
                temp = temp->get_left();
                temp->set_datum(temp_num);
            }
            else
                break;
        }
        else if (!temp->get_left() && temp->get_right()) {
            if (temp->get_datum() > temp->get_right()->get_datum()) {
                int temp_num = temp->get_datum();
                temp->set_datum(temp->get_right()->get_datum());
                temp = temp->get_right();
                temp->set_datum(temp_num);
            }
            else
                break;
        }
        else {
            if (temp->get_left()->get_datum() < temp->get_right()->get_datum()) {
                if (temp->get_datum() > temp->get_left()->get_datum()) {
                    int temp_num = temp->get_datum();
                    temp->set_datum(temp->get_left()->get_datum());
                    temp = temp->get_left();
                    temp->set_datum(temp_num);
                }
                else
                    break;
            }
            else {
                if (temp->get_datum() > temp->get_right()->get_datum()) {
                    int temp_num = temp->get_datum();
                    temp->set_datum(temp->get_right()->get_datum());
                    temp = temp->get_right();
                    temp->set_datum(temp_num);
                }
                else
                    break;
            }
        }
        
    }
}
