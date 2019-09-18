//
//  main.cpp
//  project
//
//  Created by Saransh Kalra on 12/3/18.
//  Copyright © 2018 Saransh Kalra. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "project.hpp"
#include <string>

using namespace std;
//global variables
BST bst;

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

//function to check if the file exists
bool is_file_exist(string file_name)
{
    ifstream infile(file_name.c_str());
    return infile.good();
}

//file reading and storing as a bst file function
void store_as_BST(string file_name) {
    fstream f;
    f.open(file_name.c_str(),ios::in|ios::out|ios::binary);
    
    Node node;
    Node* node1;
    
    while(f.read((char*)&node, sizeof(node)))
    {
        node1 = new Node (node.entry_num, node.name, node.version, node.quantity, node.price);
        bst.insert(node1,0);
    }
    cout<<"BST According to the file: "<<endl;
    bst.print();
    
    f.close();
}

//file writing from the bst function like basically the func required to rewrite the whole file if any change occurs
void file_insert(Node *node, string file_name) {
    ofstream outFile;
    outFile.open(file_name.c_str(), ios::out | ios::binary | ios::app);
    Node node1 (node->entry_num, node->name, node->version, node->quantity, node->price);
    outFile.write((char*)&node1, sizeof(node1));
    outFile.close();
}

//writing a file if it doesn't exist
void write_in_file(string file_name) {
    int num;
    cout<<"The file is empty you will need to add some software entries! "<<endl;
    cout<<"So, how many entries do you want to add? "<<endl;
    cin>>num;
    Node* node = NULL;
    for (int i = 0; i < num; i++) {
        node = User_insert_input();
        cout<<" ENTRY ADDED: "<<endl;
        node->display();
        file_insert(node, file_name);
    }
}

//change file from here
//updating the quantity in the file
void file_sold_or_more_copies(string name, string file_name) {
    fstream f;
    f.open(file_name.c_str(),ios::in|ios::out|ios::binary|ios::ate);
    f.seekg(0);
    Node node;
    Node* node5 = NULL;
    Node node2;
    while(f.read((char*)&node,sizeof(node)))
    {
        if((node.name).compare(name)==0)
        {
            node5 = bst.search_helper(bst.root, name);
            node2.entry_num =  node5->entry_num;
            node2.name = node5->name;
            node2.version = node5->version;
            node2.quantity = node5->quantity;
            node2.price = node5->price;
            f.seekp(-sizeof(node2),ios::cur);
            f.write((char*)&node2,sizeof(node2));
            //remove
            delete node5;
        }
    }
    f.close();
}

//clean up file function
void cleanup(string file_name) {
    Node node;
    
    ofstream outFile;
    outFile.open("temp.dat", ios::out | ios::binary);
    
    Node* node4;
    Node node2;
    
    for(int i = 1; i <= bst.size; i++) {
        node4 = bst.search_by_ent_num (bst.root, i);
        node2.entry_num =  node4->entry_num;
        node2.name = node4->name;
        node2.version = node4->version;
        node2.quantity = node4->quantity;
        node2.price = node4->price;
        if(node4) {
            outFile.write((char*)&node2,sizeof(node2));
        }
        else {
            node4 = bst.search_by_ent_num (bst.root, bst.size);
            node2.entry_num =  node4->entry_num;
            node2.name = node4->name;
            node2.version = node4->version;
            node2.quantity = node4->quantity;
            node2.price = node4->price;
            outFile.write((char*)&node2,sizeof(node2));
            bst.size--;
        }
        
    }    
    outFile.close();
    
    remove(file_name.c_str());
    rename("temp.dat",file_name.c_str());
    
}

int main() {
    int choice;
    int flag = 0;
    string file_name;
    //take input of file name for user
    // cout<<"Enter the name of the file you want to create or the file which already has the software inventory: "<<endl;
    //  cin.ignore();
    //  cin.getline(file_name,30);cout<<endl<<file_name;
    file_name="s1.dat";
    if(is_file_exist(file_name.c_str()))
        cout<<"yes";
    if(is_file_exist(file_name.c_str())) {
        store_as_BST(file_name);
    }
    
    else {
        write_in_file(file_name);
        store_as_BST(file_name);
    }
    
    //create the menu
    cout<<endl;
    cout<<"SOFTWARE MANAGEMENT SYSTEM"<<endl;
    cout<<"--------------------------"<<endl;
    cout<<"1. Make an entry for a software that came in "<<endl;
    cout<<"2. Make an entry for the copies sold "<<endl;
    cout<<"3. Check the status of a software in the system "<<endl;
    cout<<"4. Exit "<<endl;
    cout<<"Enter your choice: "<<endl;
    cin>>choice;
    cout<<endl;
    
    while(flag == 0) {
        if (choice == 1) {
            Node* node = User_insert_input();
            if (bst.search_helper (bst.root, node->name)) {
                bst.insert(node, node->quantity);
                file_sold_or_more_copies(node->name, file_name);
                cout<<" UPDATED ENTRY: "<<endl;
                bst.search_helper (bst.root, node->name)->display();
            }
            else {
                bst.insert(node,0);
                file_insert(node, file_name);
                cout<<" ENTRY ADDED: "<<endl;
                node->display();
            }
    
        }
        else if (choice == 2) {
            int quantity;
            string name;
            cout<<"Enter the name of the software whose copies were sold: "<<endl;
            cin.ignore();
            getline(cin, name);
            cout<<"Enter the number of copies that were sold: "<<endl;
            cin>>quantity;
            bst.sell_copy(name, quantity);
            file_sold_or_more_copies(name, file_name);
            cout<<"Updated Entry: "<<endl;
            if(bst.search_helper(bst.root, name)) {
                bst.search_helper(bst.root, name)->display();
            }
            if (bst.search_helper(bst.root, name)->quantity == 0) {
                bst.remove(name);
                cout<<"Entry deleted! Because stock ran out!"<<endl;
            }
        }
        else if (choice == 3) {
            string name;
            cout<<"Enter the name of the software whose status you want to check: "<<endl;
            cin.ignore();
            getline(cin, name);
            bst.search(name);
            if(bst.search_helper(bst.root, name)) {
                bst.search_helper(bst.root, name)->display();
            }
        }
        else if (choice == 4) {
            cleanup(file_name);
            cout<<"Final BST: "<<endl;
            bst.print();
            flag = 1;
        }
        else {
            cout<<"Invalid Choice! Try Again!"<<endl;
            cout<<"Enter your choice: "<<endl;
            cin>>choice;
        }
        if(choice != 4) {
            cout<<"Enter your choice: "<<endl;
            cin>>choice;
        }
    }
    return 0;
}

