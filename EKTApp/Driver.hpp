//
//  Driver.hpp
//  EKTApp
//
//  Created by June Kim on 2016-07-10.
//  Copyright © 2016 jdiggidawg. All rights reserved.
//

#ifndef Driver_hpp
#define Driver_hpp

#include <stdio.h>
#include "Word.hpp"
#include <iostream>
#include <assert.h>
#include <vector>
#include "KlingonDictionary.hpp"

class Driver {
    vector<Word> wordList;
    KlingonDictionary dictionary;
public:
    Driver(){};
    void test();
    void populateWordList();
    void populateDictionary();
    void testSearchWords();
    void read();
};



#endif /* Driver_hpp */
