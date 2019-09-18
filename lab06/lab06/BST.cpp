//
//  BST.cpp
//  lab06
//
//  Created by Saransh Kalra on 10/28/18.
//  Copyright © 2018 Saransh Kalra. All rights reserved.
//

#include "BST.hpp"
#include <iostream>

using namespace std;

//Node class constructor definition
Node::Node(int info){
    //assigning the argument value to the info of the node
    this->info = info;
    //intialising its left to 0
    this->left  = 0;
    //initialising its right to zero
    this->right = 0;
}

//accessor for the information stored in node
int Node::getInfo(){
    //return the information stored in the node
    return this->info;
}

//mutator for the information stored in node
void Node::setInfo(int info){
    //sets the argument value to the info of the node
    this->info = info;
}

//constructor for the BST class
BST::BST() {
    //initialises the root to 0
    this->root = 0;
}

//destructor for the BST class
BST::~BST(){
    //caling the destructor helper with root as the argument
    this->destr_helper(this->root);
}

//recursive destructor helper function for making destructor easier
void BST::destr_helper(Node* node){
    //if node exists
    if(node){
        //do postorder traversal for the whole BST and delete all the nodes
        this->destr_helper(node->left);
        this->destr_helper(node->right);
        delete node;
    }
}

//insert function for inserting a new node to the BST
void BST::insert(int info) {
    //if root doesn't exist
    if(!this->root) {
        //make a new node with the argument as the constructor argument
        Node *p = new Node(info);
        //assign that node to the root
        this->root = p;
    }
    //else add according to its info if its bigger smaller or equal to
    else {
        //variable flag to exit out of the loop
        int flag = 0;
        //make a new node with the argument as the constructor argument
        Node *add = new Node(info);
        //make a traversal node initialized to root
        Node *p1 = this->root;
        //while flag is 0, be in the loop i.e. we can exit the loop whenever we want to making flag 1
        while(flag==0) {
            //if the value to be added is greater that the traversal node it will be stored in the right side
            if(info > p1->getInfo()) {
                //if a right exists then update the traversal node to be its right
                if(p1->right) {
                    p1 = p1->right;
                }
                //if a right doesnt exist then add the new node at the right and make flag 1 to exit out of the loop
                else {
                    p1->right = add;
                    flag = 1;
                }
            }
            //if the value to be added is less than the current traversal node then it would be stored in the left side
            else if (info < p1->getInfo()) {
                //if a left exists then update the traversal node to be its left
                if(p1->left) {
                    p1 = p1->left;
                }
                //if a left doesnt exist then add the new node at the left and make flag 1 to exit out of the loop
                else {
                    p1->left = add;
                    flag = 1;
                }
            }
            //else it means its equal to the node info already in ther tree which means we should give an error that duplicates are not allowed and exit the loop by making flag 1
            else {
                cout<<"Duplicate not allowed! this value already exists in the BST!"<<endl;
                flag = 1;
            }
        }
    }
}

//search function for searching the value passed as argument in the BST
void BST::search(int info) {
    //if there is no root give error that the BST is empty
    if(!this->root) {
        cout<<"Nothing to search for! The Binary Search Tree is empty"<<endl;
    }
    //else search for the node
    else {
        //if the search hepler function returns true then display that this value exists in the  BST
        if(this->search_helper(this->root, info)) {
            cout<<"Yes, "<<info<<" exists in the Binary Search Tree."<<endl;
        }
        //else display that it doesn't exist in the BST
        else {
            cout<<"The value "<<info<<" was not found in the Binary Search Tree."<<endl;
        }
    }
}

//recursive search helper function to make search easier
Node* BST::search_helper(Node *node, int info) {
    //if a node doesn't exist return the node i.e. NULL
    if(!node) {
        //return false
        return node;
    }
    //if the value is found at this node return the node
    else if (node->getInfo() == info) {
        //return true
        return node;
    }
    //if its less than the node passed as argument then pass the left of the node as an argument and call the search helper again because if it is in BST will be found to the left
    else if (info < node->getInfo()) {
        return this->search_helper(node->left, info);
    }
    //if its more than the node passed as argument then pass the right of the node as an argument and call the search helper again because if it is in BST will be found to the right
    else {
        return this->search_helper(node->right, info);
    }
}

//recursive inorder traversal function to make the print easier
void BST::inorderTraversal(Node *temp) {
    //if temp exists follow LVR that means go to left then print that node and then go to right
    if(temp) {
        inorderTraversal(temp->left);
        cout<<temp->getInfo()<<" ";
        inorderTraversal(temp->right);
    }
}

//print function to print the BST according to inorder traversal
void BST::print() {
    //if the root doesn't exist, give an error that the BST is empty
    if(!this->root) {
        cout<<"Nothing to display! The Binary Search Tree is empty"<<endl;
    }
    // else just call teh inorder traversal helper with root as the argument and print the BST inorder with that
    else {
        cout<<"{ ";
        inorderTraversal(this->root);
        cout<<"}"<<endl;
    }
}
//function for counting the leaves in the BST
void BST::leavesCount() {
    //if the root doesn't exist, give an error that the BST is empty
    if(!this->root) {
        cout<<"Nothing to count leaves for! The Binary Search Tree is empty"<<endl;
    }
    //else give the nodes in the BST
    else {
        //pass the root as an argument to the leaves count helper function ehich returns the numer of leaves in the BST and print it
        Node *p = this->root;
        cout<<"No of leaves in the BST: "<<this->leavesCountHelper(p)<<endl;
    }
}
    

//recursive leaves count function helper to make leave counting function easier
int BST::leavesCountHelper(Node *temp) {
    //if the node exists
    if(temp) {
        //store the leaves count in the left side of the current node in a
        int a = this->leavesCountHelper(temp->left);
        
        //store the leaves count in the right side of the current node in b
        int b = this->leavesCountHelper(temp->right);
        
        //initialise c to zero which is used for storing the total leaves till this node
        int c = 0;
        
        //if there is no left or right children then its a leaf so add one to the leaves it has to the left and right and then return the total
        if(!(temp->left) && !(temp->right)) {
            c = 1 + a + b ;
        }
        //else its a not a leaf so add zero to the leaves it has to the left and right and then return the total
        else {
            c = 0 + a + b ;
        }
        //returning the total
        return c;
    }
    //if the node is null return 0
    else {
        return 0;
    }
   
}
