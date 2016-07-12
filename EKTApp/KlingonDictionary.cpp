//
//  KlingonDictionary.cpp
//  EKTApp
//
//  Created by June Kim on 2016-07-10.
//  Copyright © 2016 jdiggidawg. All rights reserved.
//

#include "KlingonDictionary.hpp"


void KlingonDictionary::populate(vector<Word> wordList) {
    //TODO: shuffle first.
    random_shuffle(wordList.begin(), wordList.end());
    for (int i = 0; i < wordList.size(); i++) {
        tree.insert(wordList[i]);
    }
}

string KlingonDictionary::klingonFor(string englishWord) {
    Word *query = new Word();
    query->english = englishWord;
    
    Word result = *tree.search(query);
    
    return result.klingon;
}

void KlingonDictionary::printAll() {
    
    for (Word eachWord : tree.flattenedTree()) {
        cout << eachWord.english << ": " << eachWord.klingon << endl;
    }
}