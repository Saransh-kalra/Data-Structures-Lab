//
//  adder.cpp
//  optional_lab
//
//  Created by Saransh Kalra on 9/14/18.
//  Copyright © 2018 Saransh Kalra. All rights reserved.
//

#include "adder.hpp"

adder::adder(){
    a=2;
    b=2;
}

adder::adder(int x,int y){
    this->a=x;
    this->b=y;
}

int adder::add(){
    return this->a + this->b;
}

int adder::subtract(){
    return this->a - this->b;
}

int adder::multiply(){
    return this->a * this->b;
}

float adder::divide(){
    return float(this->a)/float(this->b);
}

void adder::set(int q, int w){
    if(q==1){
        this->a=w;
    }
    else if(q==2){
        this->b=w;
    }
    else
        this->a=w;
}

int adder::get(int r){
    if(r==1){
        return this->a;
    }
    else if(r==2){
        return this->b;
    }
    else
        return this->a;
}

