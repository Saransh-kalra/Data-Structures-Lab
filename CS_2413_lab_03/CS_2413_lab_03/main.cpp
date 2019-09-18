//
//  main.cpp
//  CS_2413_lab_03
//
//  Created by Saransh Kalra on 9/29/18.
//  Copyright © 2018 Saransh Kalra. All rights reserved.
//

#include <iostream>
#include "DoublyLinkedList.hpp"
using namespace std;

int main() {
    //initialising instance variable of linked list
    DoublyLinkedList LinkedList1;
    //call to member function to delete at tail
    LinkedList1.deleteAtTail();
    //call to member function to delete at head
    LinkedList1.deleteAtHead();
    //call to insert 1 at head
    LinkedList1.insertAtHead(1);
    //display the list function called
    LinkedList1.displayList();
    //call to insert 2 at tail
    LinkedList1.insertAtTail(2);
    //display the list function called
    LinkedList1.displayList();
    //call to insert 3 at tail
    LinkedList1.insertAtTail(3);
    //display the list function called
    LinkedList1.displayList();
    //call to insert 4 at tail
    LinkedList1.insertAtTail(4);
    //display the list function called
    LinkedList1.displayList();
    //search 2 in the linked list
    LinkedList1.search(2);
    //search 4 in the linked list
    LinkedList1.search(4);
    //delete the value at tail
    LinkedList1.deleteAtTail();
    //search 4 in the linked list
    LinkedList1.search(4);
    //delete the value at head
    LinkedList1.deleteAtHead();
    //display the list
    LinkedList1.displayList();
    //testing the insert function
    LinkedList1.insertAtPos(1, 6);
    //display the list
    LinkedList1.displayList();
    //testing the insert function
    LinkedList1.insertAtPos(3, 5);
    //display the list
    LinkedList1.displayList();
    //testing the delete function
    LinkedList1.deleteAtPos(2);
    //display the list
    LinkedList1.displayList();
    //testing the delete function
    LinkedList1.deleteAtPos(3);
    //display the list
    LinkedList1.displayList();
    
    
    return 0;
}
