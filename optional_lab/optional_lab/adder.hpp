//
//  adder.hpp
//  optional_lab
//
//  Created by Saransh Kalra on 9/14/18.
//  Copyright © 2018 Saransh Kalra. All rights reserved.
//

#ifndef ADDER
#define ADDER

#include <stdio.h>
#include <string>

using namespace std;

class adder {
    
private:
    int a;
    int b;
    
public:
    adder();
    adder(int, int);
    int add();
    int multiply();
    int subtract();
    float divide();
    void set(int,int);
    int get(int);
    
};
#endif /* adder_hpp */

