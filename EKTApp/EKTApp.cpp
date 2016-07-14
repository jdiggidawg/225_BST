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

using namespace std;

vector<Word> vectorizeTextFile(string sourceFileName);


EKTApp::EKTApp() {
    dictionary = new KlingonDictionary();
}

void EKTApp::launchWith(string sourceFileName){

    dictionary->populate(vectorizeTextFile(sourceFileName));
    //TODO: ask user for english word input
    //then print the klingon word for the input...
    
    vector<string> wordsToBeTranslated;
    string line;

    /*while (cin >> line) {
        wordsToBeTranslated.push_back(line);
    }*/
    
    
    while (getline(cin,line)) {
        bool checkWhiteSpace = false;
        char eachLine[128];
        strcpy(eachLine, line.c_str());
        string temp;
        int c = 0;
        
        while (eachLine[c] != '\n') {
            if (eachLine[c] != ' ') {
                checkWhiteSpace = true;
                break;
            }
            c++;
        }
        
        if (!line.empty() && checkWhiteSpace) {
            istringstream ss(line);
            
            string token;
            string word;
            while(getline(ss, token,' ')) {
                word+=token;
            }
            wordsToBeTranslated.push_back(word);
        }
    }
    cout<<endl<<"Testing"<<endl;
    for (string eachWord: wordsToBeTranslated) {
        cout << eachWord<<endl;
    }
    
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
