//
//  LinkedList.hpp
//  LinkedListLecture
//
//  Created by Saransh Kalra on 9/28/18.
//  Copyright © 2018 Saransh Kalra. All rights reserved.
//

#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <stdio.h>
class Node {
    int datum;
    Node *next;
    
public:
    Node(int);
    // we do not need a descructor because it will delete every element except the first one.
    int get_datum();
    void set_datum(int);
    Node* get_next();
    void set_next(Node*);
};

class LinkedList {
    Node *head;
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


#endif /* LinkedList_hpp */
