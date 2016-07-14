//
//  EKTApp.cpp
//  EKTApp
//
//  Created by Jessie Tran on 2016-07-13.
//  Copyright © 2016 jdiggidawg. All rights reserved.
//

#include "EKTApp.hpp"
#include "Word.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cctype>

vector<Word> vectorizeTextFile(string sourceFileName);
void toLower(basic_string<wchar_t>& s);

EKTApp::EKTApp() {
    dictionary = new KlingonDictionary();
}

void EKTApp::launchWith(string sourceFileName){

    dictionary->populate(vectorizeTextFile(sourceFileName));
    //TODO: ask user for english word input
    //then print the klingon word for the input...
    
    vector<Word> wordsToBeTranslated;
    
}

void EKTApp::launchAndPrint(string sourceFileName){
    dictionary->populate(vectorizeTextFile(sourceFileName));
    //cout << "\nFinish populating. Start printing."<<endl;
    dictionary->printAll();
}

vector<Word> vectorizeTextFile(string sourceFileName){
    vector<Word> wordVector;
    //string wordToBeTranslated;
    //TODO:
    //refer to void Driver::read()
    
    string line;
    string english = "";
    
    ifstream file;
    file.open(sourceFileName);
    
    if(file.fail()) {
        cerr << "Error opening file"<<endl;
        exit(1);
    }
    while (!file.eof()) {
            getline(file, line); {
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
            wordVector.push_back(newWord);
        }
    }
    return wordVector;
}
