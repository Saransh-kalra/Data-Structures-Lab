//
//  main.cpp
//  LinkedListLecture
//
//  Created by Saransh Kalra on 9/28/18.
//  Copyright © 2018 Saransh Kalra. All rights reserved.
//

#include "LinkedList.hpp"
#include <iostream>

using namespace std;

int main() {
    
    LinkedList *ll = new LinkedList;
    ll->print_list();
    try {
        ll->insert(0, 1);
        ll->insert(1, 3);
        ll->insert(1, 2);
        ll->print_list();
        ll->remove(1);
        ll->print_list();
    }
    catch (const char *msg) {
        cout << msg << endl;
    }
    delete ll;
    return 0;
}
