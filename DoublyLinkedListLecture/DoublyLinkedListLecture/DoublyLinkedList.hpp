//
//  DoublyLinkedList.hpp
//  DoublyLinkedListLecture
//
//  Created by Saransh Kalra on 9/28/18.
//  Copyright © 2018 Saransh Kalra. All rights reserved.
//

#ifndef DoublyLinkedList_hpp
#define DoublyLinkedList_hpp

#include <stdio.h>
class Node {
    int datum;
    Node *next;
    Node *prev;
    
public:
    Node(int);
    // we do not need a descructor because it will delete every element except the first one.
    int get_datum();
    void set_datum(int);
    Node* get_next();
    void set_next(Node*);
    Node* get_prev();
    void set_prev(Node*);
};

class LinkedList {
    Node *head, *tail;
    int size;
public:
    LinkedList();
    ~LinkedList();
    void destr_helper(Node*);
    void insert(int, int);
    int remove(int); // this will ouput the number we are deleting, does not need to be int, can be void
    int get_size();
    int get(int);
    void set(int, int);
    void print_list();
    
};

#endif /* DoublyLinkedList_hpp */
