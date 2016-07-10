//
//  Driver.cpp
//  EKTApp
//
//  Created by June Kim on 2016-07-10.
//  Copyright © 2016 jdiggidawg. All rights reserved.
//

#include "Driver.hpp"


using namespace std;

void testWordConstruction();

void Driver::test(){
    testWordConstruction();
    populateWordList();
    populateDictionary();
    testSearchWords();
}

void Driver::testSearchWords() {
    string a = "a";
    string b = "b";
    string c = "c";
    
    string klingA = dictionary.klingonFor(a);
    string klingB = dictionary.klingonFor(b);
    string klingC = dictionary.klingonFor(c);
    
    assert(klingA == "AAA");
    
}

void Driver::populateDictionary(){
    dictionary = *new KlingonDictionary;
    dictionary.populate(wordList);
}

void Driver::populateWordList(){
    Word *word1 = new Word("a", "AAA");
    Word *word2 = new Word("b", "BBB");
    Word *word3 = new Word("c", "CCC");
    Word *word4 = new Word("d", "DDD");
    Word *word5 = new Word("e", "EEE");
    wordList.push_back(*word1);
    wordList.push_back(*word2);
    wordList.push_back(*word3);
    wordList.push_back(*word4);
    wordList.push_back(*word5);
    
    return;
    
    for (Word eachWord: wordList) {
        cout << eachWord.english << ": " << eachWord.klingon << endl;
    }
    
}

void testWordConstruction() {
    string hello = "hello";
    string hnnnn = "HNNNN";
    Word *someWord = new Word(hello, hnnnn);
    
    assert(someWord->english == hello);
    assert(someWord->klingon == hnnnn);
    
}