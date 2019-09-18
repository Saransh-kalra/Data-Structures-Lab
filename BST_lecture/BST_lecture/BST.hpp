//
//  BST.hpp
//  BST_lecture
//
//  Created by Saransh Kalra on 10/10/18.
//  Copyright © 2018 Saransh Kalra. All rights reserved.
//

#ifndef BST_hpp
#define BST_hpp

#include <stdio.h>

class Node{
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

class BST {
    Node *root;
public:
    BST();
    ~BST();
    void destr_helper(Node*);
    void insert(int);
    bool search(int);
    Node* search_helper(Node*, int);
    void remove(int);
    
};



#endif /* BST_hpp */
