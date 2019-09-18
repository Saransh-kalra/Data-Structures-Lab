//
//  main.cpp
//  CS_2413_project
//
//  Created by Saransh Kalra on 11/26/18.
//  Copyright © 2018 Saransh Kalra. All rights reserved.
//

#include <iostream>
#include "project.hpp"
#include <string>

using namespace std;

Node* User_insert_input() {
    cin.ignore();
    string name,version;
    int quantity, price;
    cout<<"Enter the name of the software: "<<endl;
    getline(cin,name);
    cout<<"Enter the version of the software: "<<endl;
    getline(cin,version);
    cout<<"Enter the quantity of the software: "<<endl;
    cin>>quantity;
    cout<<"Enter the price of the software: "<<endl;
    cin>>price;
    
    Node* node = new Node(name, version, quantity, price);
    return node;
}

//file reading and storing as a bstnand file function

//file writing from the bst function like basically the func required to rewrite the whole file if any change occurs

//clean up file function

//create the menu also
int main() {
    Node *node2 = User_insert_input();
    Node *node1 = User_insert_input();
    Node *node3 = User_insert_input();
    BST bst;
    bst.insert(node2);
    bst.insert(node1);
    bst.insert(node3);
    for(int i =1; i<= bst.size; i++) {
        Node* node5 = bst.search_by_ent_num(bst.root, i);
        cout<<node5->entry_num<<endl;
    }
    bst.print();
    bst.search("Microsoft office");
    bst.search("Microsoft office2");
    bst.search("lol");
    bst.remove("Microsoft office2");
    bst.print();
    bst.sell_copy("Microsoft office", 2);
    bst.print();
    bst.sell_copy("Microsoft office", 2);
    
    return 0;
}
