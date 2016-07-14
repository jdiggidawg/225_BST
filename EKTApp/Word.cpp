//
//  Word.cpp
//  EKTApp
//
//  Created by June Kim on 2016-07-10.
//  Copyright © 2016 jdiggidawg. All rights reserved.
//

#include "Word.hpp"
#include <string>
#include <algorithm>

using namespace std;

string toLower(string inString){
    transform(inString.begin(), inString.end(), inString.begin(), ::tolower);
    return inString;
}

bool Word::operator <(const Word &w) const{
    return toLower(this->english).compare(toLower(w.english)) < 0;
}
bool Word::operator >(const Word &w) const{
    return toLower(this->english).compare(toLower(w.english)) > 0;
}
bool Word::operator ==(const Word &w) const{
    return toLower(this->english).compare(toLower(w.english)) == 0;
}

bool Word::operator !=(const Word &w) const{
    return toLower(this->english).compare(toLower(w.english)) != 0;
}
