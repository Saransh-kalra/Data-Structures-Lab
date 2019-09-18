//
//  StackQueue.hpp
//  stacks_queues_lecture
//
//  Created by Saransh Kalra on 10/1/18.
//  Copyright © 2018 Saransh Kalra. All rights reserved.
//

#ifndef StackQueue_hpp
#define StackQueue_hpp

#include <stdio.h>

class Node{
private:
    int datum;
    Node *next, *prev;
public:
    Node(int);
    ~Node();
    int get_datum();
    void set_datum(int);
    Node* get_next();
    void set_next(Node*);
    Node* get_prev();
    void set_prev(Node*);
};

class StackQueue{
    Node *head, *tail;
public:
    StackQueue();
    ~StackQueue();
    void destr_helper(Node*);
    void push(int);
    int stack_pop();
    int stack_peek();
    int queue_pop();
    int queue_peek();
};

#endif /* StackQueue_hpp */
