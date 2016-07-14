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
#include "EKTApp.hpp"

using namespace std;

void testWord();

int main(int argc, const char * argv[]) {
    
    //Driver *driver = new Driver();
    //driver->test();
    
    EKTApp *app = new EKTApp();
    string sourceFileName = "dataFile.txt";
    
    if (argc == 1) {
    //    app->launchWith(sourceFileName);
    //} else if (argc == 2){ //display
        app->launchAndPrint(sourceFileName);
    }
    
    return 0;
}
