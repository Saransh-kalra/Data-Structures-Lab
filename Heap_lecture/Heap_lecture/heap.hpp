//
//  heap.hpp
//  Heap_lecture
//
//  Created by Saransh Kalra on 10/24/18.
//  Copyright © 2018 Saransh Kalra. All rights reserved.
//

#ifndef heap_hpp
#define heap_hpp

#include <stdio.h>

class Node {
    int datum;
    Node *left, *right, *parent;
public:
    Node(int);
    int get_datum();
    void set_datum(int);
    Node* get_left();
    void set_left(Node*);
    Node* get_right();
    void set_right(Node*);
    Node* get_parent();
    void set_parent(Node*);
};

class Heap {
    Node *root, *tail;
    void upheap();
    void downheap();
    void place_node(int);
    void reset_tail();
public:
    Heap();
    ~Heap();
    void destr_helper(Node*);
    void insert(int);
    int remove();
};

#endif /* heap_hpp */
