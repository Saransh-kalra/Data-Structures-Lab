//
//  BST.hpp
//  lab 7
//
//  Created by Saransh Kalra on 11/1/18.
//  Copyright © 2018 Saransh Kalra. All rights reserved.
//

#ifndef BST_hpp
#define BST_hpp

#include <stdio.h>

//Node class for making nodes in the binary search tree
class Node
{
    //variable for storing teh information in each node
    int info;
public:
    //constructor
    Node(int info);
    //accessor for the information stored in node
    int getInfo();
    //mutator for the information stored in node
    void setInfo(int);
    //left and right pointers to point to the left and right nodes in the BST
    Node *left, *right;
};

//Class for the binary search tree
class BST
{
    //root pointer to point to the root of the BST
    Node *root;
public:
    //constructor
    BST();
    //destructor
    ~BST();
    //destructor helper to make the destructor recursive
    void destr_helper(Node*);
    //insert function for inserting a new node into teh BST
    void insert(int);
    //search function for searching the value passed as argument in the BST
    void search(int);
    //recursive search helper function to make search easier
    Node* search_helper(Node*, int);
    //recursive inorder traversal function to make the print easier
    void inorderTraversal(Node*);
    //recursive preorder traversal function to make the print easier
    void preorderTraversal(Node*);
    //recursive postorder traversal function to make the print easier
    void postorderTraversal(Node*);
    //print function to print the BST according to inorder, preorder and postorder traversal
    void print();
    //function for counting the leaves in the BST
    void leavesCount();
    //recursive leaves count function helper to make leave counting function easier
    int leavesCountHelper(Node*);
    //parent finder recursive helper for remove function
    Node* parent_helper(Node*, int);
    //remove function to remove the argument passed from the BST
    void remove(int num);
};

#endif /* BST_hpp */

