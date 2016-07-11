//
//  Word.cpp
//  EKTApp
//
//  Created by June Kim on 2016-07-10.
//  Copyright © 2016 jdiggidawg. All rights reserved.
//

#include "Word.hpp"

bool compareEnglishString(string lhs, string rhs){
    //TODO:
    return true;
}

bool Word::operator <(const Word &w) const{
    return compareEnglishString(this->english, w.english);
}
bool Word::operator >(const Word &w) const{
    return compareEnglishString(this->english, w.english);
}
bool Word::operator ==(const Word &w) const{
    return compareEnglishString(this->english, w.english);
}
bool Word::operator !=(const Word &w) const{
    return compareEnglishString(this->english, w.english);
}
bool Word::operator <=(const Word &w) const{
    return compareEnglishString(this->english, w.english);
}
bool Word::operator >=(const Word &w) const{
    return compareEnglishString(this->english, w.english);
}