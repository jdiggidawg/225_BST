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

using namespace std;

class KlingonDictionary {
    
    
public:
    void populate(vector<Word>);
    string klingonFor(string englishWord);
};

#endif /* KlingonDictionary_hpp */
