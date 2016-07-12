//
//  Word.cpp
//  EKTApp
//
//  Created by June Kim on 2016-07-10.
//  Copyright © 2016 jdiggidawg. All rights reserved.
//

#include "Word.hpp"
#include <string>


bool compareEnglishString(string lhs, string rhs){
    //TODO: verify.
    return lhs.compare(rhs);
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