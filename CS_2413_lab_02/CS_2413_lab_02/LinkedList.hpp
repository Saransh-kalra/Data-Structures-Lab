//
//  LinkedList.hpp
//  CS_2413_lab_02
//
//  Created by Saransh Kalra on 9/21/18.
//  Copyright © 2018 Saransh Kalra. All rights reserved.
//

#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <stdio.h>
//creating the node class for the node of the linked list
class Node
{
public:
    //variable info for storing node info
    int info;
    //pointer of class node, pointing to the next node of the linked list
    Node* next;
};

//class for linked list
class LinkedList
{
public:
    //pointers to point of the head and tail of the list
    Node *head, *tail;
    
    LinkedList();   //constructor to initialize head and tail to 0 or NULL
    ~LinkedList();  //deconstructor to free the memory borrowed from heap
    
    //member functions to insert a node at the head and the tail of the linked list
    void insertAtHead(int value);
    void insertAtTail(int value);
    
    //Print the info value before deletion of the node and then deleting the node from the head and tail
    //of the linked list
    void deleteAtHead();
    void deleteAtTail();
    
    //search the given info found at which node of a linked list
    void search(int value);
    //member function to display the list
    void displayList();
};
#endif /* LinkedList_hpp */
