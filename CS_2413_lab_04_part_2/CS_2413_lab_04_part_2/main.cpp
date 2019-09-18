//
//  main.cpp
//  CS_2413_lab_04_part_2
//
//  Created by Saransh Kalra on 10/10/18.
//  Copyright © 2018 Saransh Kalra. All rights reserved.
//

#include <iostream>
#include "queue.hpp"

using namespace std;

int main() {
    //queue for testing
    Queue q1;
    //initialising a choice variable
    char choice = '1';
    //while the choice is not the exit choice display the menu again and again
    while(choice!='6'){
        cout<<"QUEUE MENU"<<endl;
        cout<<"----------"<<endl;
        cout<<"1. Push a number on end of queue"<<endl;
        cout<<"2. Pop a number from the start of the queue"<<endl;
        cout<<"3. Check if the queue is empty"<<endl;
        cout<<"4. Take a peek in the queue"<<endl;
        cout<<"5. Print the queue"<<endl;
        cout<<"6. Exit"<<endl;
        cout<<"Enter your choice: "<<endl;
        cin>>choice;
        
        //switch case for menu
        switch (choice) {
                //menu option 1 for enqueue into queue
            case '1':
                int info;
                //user input for the number they want to put in
                cout<<"enter the number you want to push: "<<endl;
                cin>>info;
                q1.queue_enqueue(info);
                break;
                //menu option 2 for dequeue from the queue
            case '2':
                cout<<q1.queue_dequeue()<<endl;
                break;
                //menu option 3 to check if the queue is empty
            case '3':
                q1.queue_isEmpty();
                break;
                //menu option 4 to peek at the tail of the queue
            case '4':
                cout<<q1.queue_peek()<<endl;
                break;
                //menu option 5 to print the queue
            case '5':
                q1.queue_print();
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
