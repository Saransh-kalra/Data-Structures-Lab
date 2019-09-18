//
//  main.cpp
//  lab 7
//
//  Created by Saransh Kalra on 11/1/18.
//  Copyright © 2018 Saransh Kalra. All rights reserved.
//

#include <iostream>
#include "BST.hpp"

using namespace std;

int main() {
    //instance variable for the BST class
    BST example;
    //initialising the count variable to 0 for counting numbers entered
    int count = 0;
    //initialising the ch storing yes/no for the menu to y
    char ch = 'y';
    //initialising num to zero for storing the number entered by the user
    int num = 0;
    //call the search function to search for number 5 when the BST is empty
    example.search(5);
    //call the print function to print the BST according to inorder traversal algorithm if BST is empty
    example.print();
    //call the leaves count function to count the number of leaves in the BST if BST is empty
    example.leavesCount();
    //ask the user for atleast 5 numbers
    cout<<"Enter minimum 5 numbers to make a binary search tree"<<endl;
    //while ch is y means the user wants to continue the loop runs
    while(ch == 'y') {
        //ask for a number from the user
        cout<<"Enter a number to insert into the BST: ";
        cin>>num;
        //increase the count of the numbers entered by 1
        count++;
        //insert the number entered by the user to the BST
        example.insert(int(num));
        //ask the user if he wants to continue entering more numbers once he has entered 5 numbers atleast
        if(count>=5) {
            cout<<"Do you want to continue? ";
            cin>>ch;
        }
    }
    //call the search function to search for number 5
    example.search(5);
    //call the search function to search for number 7
    example.search(7);
    //call the print function to print the BST according to inorder traversal algorithm
    example.print();
    //call the leaves count function to count the number of leaves in the BST
    example.leavesCount();
    //variable to store the number the user enters to be deleted from the BST initialised to 0
    int num1 = 0;
    //asking teh user for the number he wants to delete
    cout<<"Enter the number you want to delete: ";
    cin>>num1;
    //remove that value by calling the remove function
    example.remove(num1);
    //calling the print function to show the BST after the delete
    example.print();
    return 0;
}
