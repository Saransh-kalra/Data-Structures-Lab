//
//  BST.cpp
//  BST_lecture
//
//  Created by Saransh Kalra on 10/10/18.
//  Copyright © 2018 Saransh Kalra. All rights reserved.
//

#include "BST.hpp"

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

BST::BST() {
    this->root = 0;
}

BST::~BST(){
    this->destr_helper(this->root);
}

void BST::destr_helper(Node* node){
    if(node){
        this->destr_helper(node->get_left());
        this->destr_helper(node->get_right());
        delete node;
    }
}

void BST::insert(int num){
    Node *newNode = new Node(num);
    
    if (!this->root) {
        this->root = newNode;
    }
    else{
        Node *temp = this->root;
        while (true) {
            if(num < temp->get_datum()){
                if (temp->get_left()) {
                    temp = temp->get_left();
                }
                else {
                    temp->set_left(newNode);
                    newNode->set_parent(temp);
                    break;
                }
            }
            else if (num > temp->get_datum()) {
                if (temp->get_right()) {
                    temp = temp->get_right();
                }
                else {
                    temp->set_right(newNode);
                    newNode->set_parent(temp);
                    break;
                }
            }
            else {
                throw "Duplicate not allowed";
            }
        }
    }
}

bool BST::search(int num) {
    return this->search_helper(this->root, num);
}

//int BST::search.......
Node* BST::search_helper(Node *node, int num) {
    if(!node) {
        return node; //return false;
    }
    else if (node->get_datum() == num) {
        return node; //return true;
    }
    else if (num < node->get_datum()) {
        return this->search_helper(node->get_left(), num);
    }
    else {
        return this->search_helper(node->get_right(), num);
    }
}

void BST::remove(int num) {
    Node *remNode = this->search_helper(this->root, num);
    
    if(!remNode) {
        throw "node does not exist";
    }
    
    if(!(remNode->get_right() || remNode->get_left())) {
        if(remNode->get_parent()) {
            if(remNode->get_datum() < remNode->get_parent()->get_datum()) {
                remNode->get_parent()->set_left(0);
            }
            else {
                remNode->get_parent()->set_right(0);
            }
        }
        else {
            this->root = 0;
        }
        delete remNode;
    }
    
    else if(remNode->get_right() && remNode->get_left()) {
        Node *temp = remNode->get_right();
        //for(; temp->get_left(); temp = temp->get->left());
        while(temp->get_left()) {
            temp = temp->get_left();
        }
        remNode->set_datum(temp->get_datum());
        if(temp->get_datum() > temp->get_parent()->get_datum()) {
            temp->get_parent()->set_right(temp->get_right());
            if(temp->get_right()) {
                temp->get_right()->set_parent(temp->get_parent());
            }
        }
        else {
            temp->get_parent()->set_left(temp->get_right());
            if(temp->get_right()) {
                temp->get_right()->set_parent(temp->get_parent());
            }
        }
        delete temp;
    }
    
    else {
        if(remNode->get_left()) {
            if(remNode->get_datum() < remNode->get_parent()->get_datum()) {
                remNode->get_parent()->set_left(remNode->get_left());
            }
            else {
                remNode->get_parent()->set_right(remNode->get_left());
            }
            remNode->get_left()->set_parent(remNode->get_parent());
        }
        else {
            if(remNode->get_datum() < remNode->get_parent()->get_datum()) {
                remNode->get_parent()->set_left(remNode->get_right());
            }
            else {
                remNode->get_parent()->set_right(remNode->get_right());
            }
            remNode->get_right()->set_parent(remNode->get_parent());
        }
        delete remNode;
    }
}
