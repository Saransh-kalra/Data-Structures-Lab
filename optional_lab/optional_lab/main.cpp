//
//  main.cpp
//  optional_lab
//
//  Created by Saransh Kalra on 9/14/18.
//  Copyright © 2018 Saransh Kalra. All rights reserved.
//

#include "adder.hpp"
#include <iostream>
using namespace std;

int main(){
    adder *myAdder= new adder(2,4);
    
    cout<<myAdder->get(1)<<endl<<myAdder->get(2)<<endl;
    cout<<myAdder->add()<<endl<<
        myAdder->subtract()<<endl<<
        myAdder->multiply()<<endl<<
        myAdder->divide()<<endl;
   
    cout<<endl;
    myAdder->set(2,8);
    cout<<myAdder->get(1)<<endl<<myAdder->get(2)<<endl;
    cout<<myAdder->add()<<endl<<
        myAdder->subtract()<<endl<<
        myAdder->multiply()<<endl<<
        myAdder->divide()<<endl;
    
    return 0;
    
}
