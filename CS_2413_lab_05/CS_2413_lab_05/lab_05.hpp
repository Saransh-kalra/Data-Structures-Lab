//
//  lab_05.hpp
//  CS_2413_lab_05
//
//  Created by Saransh Kalra on 10/14/18.
//  Copyright © 2018 Saransh Kalra. All rights reserved.
//

#ifndef lab_05_hpp
#define lab_05_hpp

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
    //function for deleting the smallest info out  of the whole linked list
    void deleteSmallest();
    //function to remove the duplicates of the number in the linked list
    void removeDuplicates(int number);
    //search the given info found at which node of a linked list
    void search(int value);
    //member function to display the list
    void displayList();
};

#endif /* lab_05_hpp */
