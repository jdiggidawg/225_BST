//
//  Word.hpp
//  EKTApp
//
//  Created by June Kim on 2016-07-10.
//  Copyright © 2016 jdiggidawg. All rights reserved.
//

#ifndef Word_hpp
#define Word_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

class Word {
    
    
public:
    string english;
    string klingon;
    
    Word(){};
    Word(const string newEng, const string newKling) : english(newEng), klingon(newKling) {}
    
    bool operator ==(const Word &w) const;
    bool operator <(const Word &w) const;
    bool operator >(const Word &w) const;
    bool operator !=(const Word &w) const;
    bool operator <=(const Word &w) const;
    bool operator >=(const Word &w) const;
    
    
};

#endif /* Word_hpp */
