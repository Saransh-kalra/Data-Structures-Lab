//
//  main.cpp
//  CS_2413_lab_02
//
//  Created by Saransh Kalra on 9/21/18.
//  Copyright © 2018 Saransh Kalra. All rights reserved.
//

#include <iostream>
#include "LinkedList.hpp"

using namespace std;

int main() {
    //initialising instance variable of linked list
    LinkedList LinkedList1;
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
    
    return 0;
}
