//
//  project.hpp
//  project
//
//  Created by Saransh Kalra on 12/3/18.
//  Copyright © 2018 Saransh Kalra. All rights reserved.
//

#ifndef project_hpp
#define project_hpp

#include <stdio.h>
#include <string>

using namespace std;

//node class for BST
class Node {
public:
    //variable info for storing name of the software
    string name;
    //variable for storing the version of the software
    string version;
    //variable for storing the quantity of software available
    int quantity;
    //variable for storing price of the software
    int price;
    //variable to store entry number in the system
    int entry_num;
    //constructor
    Node(string, string, int, int);
    Node(int, string, string, int, int);
    Node();
    ~Node();
    //left pointer to point to the left node in the BST
    Node *left;
    //right pointer to point to the right node in the BST
    Node *right;
    void display();
};

class BST {
public:
    //root pointer to point to the root of the BST
    Node *root;
    //variable to store the number of elements in the the BST
    int size;
    //constructor
    BST();
    //destructor
    ~BST();
    //destructor helper to make the destructor recursive
    void destr_helper(Node*);
    //insert function for inserting a new node into teh BST
    void insert(Node* node, int quantity);
    //search function for searching the value passed as argument in the BST
    void search(string);
    //recursive search helper function to make search easier
    Node* search_helper(Node*, string);
    //recursive inorder traversal function to make the print easier
    void inorderTraversal(Node*);
    //recursive preorder traversal function to make the print easier
    void preorderTraversal(Node*);
    //recursive postorder traversal function to make the print easier
    void postorderTraversal(Node*);
    //print function to print the BST according to inorder traversal
    void print();
    //parent finder recursive helper for remove function
    Node* parent_helper(Node*, string);
    //remove function to remove the argument passed from the BST
    void remove(string);
    void sell_copy(string, int quantity);
    //we will use a loop to get all entry num records and each time it returns a node we write it down using write data
    Node* search_by_ent_num (Node* node, int num);
    
};


#endif /* project_hpp */

