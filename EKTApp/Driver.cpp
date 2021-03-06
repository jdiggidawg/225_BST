//
//  Driver.cpp
//  EKTApp
//
//  Created by June Kim on 2016-07-10.
//  Copyright © 2016 jdiggidawg. All rights reserved.
//

#include "Driver.hpp"
#include <sstream>

using namespace std;

void testWordConstruction();

void Driver::test(){
    testWordConstruction();
    populateWordList();
    populateDictionary();
    testPrint();
    testSearchWords();
    testOperatorOverload();
}

void Driver::testOperatorOverload() {
    Word *word1 = new Word("a", "AAA");
    Word *word2 = new Word("a", "AAA");
    Word *word3 = new Word("a", "");
    Word *word4 = new Word("b", "BBB");
    
    assert(*word1 == *word2);
    assert(*word1 == *word3);
    assert(*word4 > *word1);
    assert(*word1 < *word4);
    assert(*word4 != *word1);
    
}

void Driver::testPrint(){
    dictionary.printAll();
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

void Driver::read() {
    string line;
    string english = "";
    while(getline(cin, line)) {
        char eachLine[128];
        strcpy(eachLine, line.c_str());
        string englishWord;
        string klingonWord;
        bool isEnglish = true;
        
        for (int c = 0; c < 100; c++) {
            if (eachLine[c] == '\0') break; //end of line
            if (eachLine[c] == ' ') continue; //ignore space
            if (eachLine[c] == ':') {
                isEnglish = false;
                continue;
            }
            stringstream ss;
            string s;
            if (isEnglish) {
                string englishLetter;
                ss << eachLine[c];
                ss >> englishLetter;
                englishWord += englishLetter;
            } else {
                string klingonLetter;
                ss << eachLine[c];
                ss >> klingonLetter;
                klingonWord += klingonLetter;
            }
        }
        Word newWord = Word(englishWord, klingonWord);
        wordList.push_back(newWord);
    }
}

void Driver::populateDictionary() {
    dictionary = *new KlingonDictionary();
    dictionary.populate(wordList);
}

void Driver::populateWordList(){
    Word *word1 = new Word("a", "AAA");
    Word *word2 = new Word("b", "BBB");
    Word *word3 = new Word("c", "CCC");
    Word *word4 = new Word("d", "DDD");
    Word *word5 = new Word("e", "EEE");
    Word *word6 = new Word("e", "EEE");
    Word *word7 = new Word("Eaa", "EEEaaa");
    Word *word8 = new Word("Ebb","EEEbbb");
    Word *word9 = new Word("eba","EEEbba");
    Word *word10 = new Word("Eba","EEEbba");
    
    wordList.push_back(*word1);
    wordList.push_back(*word2);
    wordList.push_back(*word3);
    wordList.push_back(*word4);
    wordList.push_back(*word5);
    wordList.push_back(*word6);
    wordList.push_back(*word7);
    wordList.push_back(*word8);
    wordList.push_back(*word9);
    wordList.push_back(*word10);
    
    return;
    
    //for (Word eachWord: wordList) {
    //    cout << eachWord.english << ": " << eachWord.klingon << endl;
    //}
    
}

void testWordConstruction() {
    string hello = "hello";
    string hnnnn = "HNNNN";
    Word *someWord = new Word(hello, hnnnn);
    
    assert(someWord->english == hello);
    assert(someWord->klingon == hnnnn);
    
}