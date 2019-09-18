//
//  Stack.hpp
//  CS_2413_lab_04_stacks
//
//  Created by Saransh Kalra on 10/10/18.
//  Copyright © 2018 Saransh Kalra. All rights reserved.
//

#ifndef Stack_hpp
#define Stack_hpp

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

class Stack{
    //pointer to point of the head of the stack
    Node *head;
public:
    //constructor and deconstructor for the stack
    Stack();
    ~Stack();
    //function to push stuff on head of the stack
    void stack_push(int);
    //function to pop stuff from the head of the stack
    int stack_pop();
    //function to peek onto the top of the stack
    int stack_peek();
    //function to print the stack
    void stack_print();
    //function to check if the stack is empty
    void stack_isEmpty();
};

#endif /* Stack_hpp */
