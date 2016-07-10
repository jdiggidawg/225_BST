//
//  main.cpp
//  EKTApp
//
//  Created by Jessie Tran on 2016-07-10.
//  Copyright © 2016 jdiggidawg. All rights reserved.
//

#include <assert.h>
#include <iostream>
#include "Driver.hpp"

using namespace std;

void testWord();

int main(int argc, const char * argv[]) {
    
    Driver *driver = new Driver();
    driver->test();
    
    
    return 0;
}
