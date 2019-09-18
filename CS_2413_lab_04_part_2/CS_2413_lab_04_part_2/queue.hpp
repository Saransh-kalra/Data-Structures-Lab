//
//  queue.hpp
//  CS_2413_lab_04_part_2
//
//  Created by Saransh Kalra on 10/10/18.
//  Copyright © 2018 Saransh Kalra. All rights reserved.
//

#ifndef queue_hpp
#define queue_hpp

#include <stdio.h>

//creating the node class for the node of the stack
class Node{
private:
    //variable info for storing node info
    int info;
    //pointer of class node, pointing to the next node of the stack
    Node *next;

public:
    //constructor and deconstructor for node
    Node(int);
    ~Node();
    //getters and setters for info
    int get_info();
    void set_info(int);
    //getters and setters for next
    Node* get_next();
    void set_next(Node*);
};

class Queue{
    //pointer to point of the head and tail of the queue
    Node *head, *tail;
public:
    //constructor and deconstructor for the queue
    Queue();
    ~Queue();
    //function to add on head of the queue
    void queue_enqueue(int);
    //function to remove from the tail of the queue
    int queue_dequeue();
    //function to peek onto the head of the queue
    int queue_peek();
    //function to print the queue
    void queue_print();
    //function to check if the queue is empty
    void queue_isEmpty();
    
};
#endif /* queue_hpp */
