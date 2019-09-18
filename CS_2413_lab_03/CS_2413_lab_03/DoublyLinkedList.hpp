//
//  DoublyLinkedList.hpp
//  CS_2413_lab_03
//
//  Created by Saransh Kalra on 9/29/18.
//  Copyright © 2018 Saransh Kalra. All rights reserved.
//

#ifndef DoublyLinkedList_hpp
#define DoublyLinkedList_hpp

#include <stdio.h>
//creating the node class for the node of the linked list
class Node
{
private:
    //variable info for storing node info
    int info;
    
public:
    //pointer of class node, pointing to the next node of the linked list
    Node* next;
    //pointer of class node, pointing to the prev node of the linked list
    Node* prev;
    //accessor for the info stored in node
    int getInfo();
    //mutator for the info stored in node
    void setInfo(int value);
};

//class for linked list
class DoublyLinkedList
{
private:
    //pointers to point of the head and tail of the list
    Node *head, *tail;
    //to keep the track of the size of the DoublyLinkedList
    int size;
    
public:
    DoublyLinkedList();   //constructor to initialize head and tail to 0 or NULL
    ~DoublyLinkedList();  //deconstructor to free the memory borrowed from heap
    
    //member functions to insert a node at the head, the tail and at a particular position of the linked list
    void insertAtHead(int value);
    void insertAtTail(int value);
    void insertAtPos(int pos, int value);
    
    //Print the info value before deletion of the node and then deleting the node from the head, the tail and at a particular position of the linked list
    void deleteAtHead();
    void deleteAtTail();
    void deleteAtPos(int pos);
    
    //search the given info found at which node of a linked list
    void search(int value);
    //member function to display the list
    void displayList();
};

#endif /* DoublyLinkedList_hpp */
