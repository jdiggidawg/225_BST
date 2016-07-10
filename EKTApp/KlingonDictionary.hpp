//
//  KlingonDictionary.hpp
//  EKTApp
//
//  Created by June Kim on 2016-07-10.
//  Copyright © 2016 jdiggidawg. All rights reserved.
//

#ifndef KlingonDictionary_hpp
#define KlingonDictionary_hpp

#include <stdio.h>
#include "Word.hpp"
#include <vector>
#include "BST.hpp"

using namespace std;

class KlingonDictionary {

private:
    BST<Word> tree;
    
public:
    
    void populate(vector<Word>);
    string klingonFor(string englishWord);
};

#endif /* KlingonDictionary_hpp */
