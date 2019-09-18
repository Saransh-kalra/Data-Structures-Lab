//
//  main.cpp
//  CS_2413_lab_04_stacks
//
//  Created by Saransh Kalra on 10/10/18.
//  Copyright © 2018 Saransh Kalra. All rights reserved.
//

#include <iostream>
#include "Stack.hpp"

using namespace std;

int main() {
    //stack for testing
    Stack s1;
    //initialising a choice variable
    char choice = '1';
    //while the choice is not the exit choice display the menu again and again
    while(choice!='6'){
        cout<<"STACK MENU"<<endl;
        cout<<"----------"<<endl;
        cout<<"1. Push a number on top of stack"<<endl;
        cout<<"2. Pop a number from the top of the stack"<<endl;
        cout<<"3. Check if the stack is empty"<<endl;
        cout<<"4. Take a peek in the stack"<<endl;
        cout<<"5. Print the stack"<<endl;
        cout<<"6. Exit"<<endl;
        cout<<"Enter your choice: "<<endl;
        cin>>choice;
        
        //switch case for menu
        switch (choice) {
                //menu option 1 for pushing into stack
            case '1':
                int info;
                //user input for the number they want to put in
                cout<<"enter the number you want to push: "<<endl;
                cin>>info;
                s1.stack_push(info);
                break;
                //menu option 2 for popping from the stack
            case '2':
                cout<<s1.stack_pop()<<endl;
                break;
                //menu option 3 to check if the stack is empty
            case '3':
                s1.stack_isEmpty();
                break;
                //menu option 4 to peek at the top of the stack
            case '4':
                cout<<s1.stack_peek()<<endl;
                break;
                //menu option 5 to print the stack
            case '5':
                s1.stack_print();
                break;
                //menu option 6 to exit
            case '6':
                break;
                //default being an invalid choice
            default:
                cout<<"invalid choice"<<endl;
                break;
        }
    
    }
    return 0;
}
