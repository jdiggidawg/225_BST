//
//  EKTApp.hpp
//  EKTApp
//
//  Created by Jessie Tran on 2016-07-13.
//  Copyright © 2016 jdiggidawg. All rights reserved.
//

#ifndef EKTApp_hpp
#define EKTApp_hpp

#include <stdio.h>
#include "KlingonDictionary.hpp"
//launch with options

class EKTApp {
    KlingonDictionary *dictionary;
    
public:
    EKTApp();
    void launchWith(string sourceFileName); //./EKTApp, cin
    void launchAndPrint(string sourceFileName); // ./EKTApp display
};

#endif /* EKTApp_hpp */
