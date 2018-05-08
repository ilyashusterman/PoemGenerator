//
// Created by ilya on 06/05/18.
//

#ifndef POEMGENERATOR_POEMGENERATOR_H
#define POEMGENERATOR_POEMGENERATOR_H
#include <cstdlib>
#include <string>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>

using std::string;

class PoemGenerator {

public:
    int applyRow(){
        return 2;
    }

    string getLastWord(char *row) {
        using namespace std;
        string sentence = row;
        long index = sentence.find_last_of(' ');
        string lastWord = sentence.substr(++index);
        return lastWord;
    }

    bool isKeyWord(std::vector<std::string> keyWords, string word) {
        string wordString = word;
        return (std::find(keyWords.begin(), keyWords.end(), word) != keyWords.end());
    }

    bool isLastLettersSimilar(const  string first, const string second, int letters) {
        bool answer = long{second.length()}>long{letters};
        if(second.length() < letters || first.length() < letters){
            return false;
        }else{
            return first.substr(first.length()-letters,first.length())
                   == second.substr(second.length()-letters, second.length());
        }
    }

    int haveSimilarEnding(char* firstRow, char* secondRow, int numLetters){
        int isSimilarEnding = 0;
        string firstRowLastWord  = getLastWord(firstRow);
        string secondRowLastWord  = getLastWord(secondRow);
        if (firstRowLastWord == secondRowLastWord){
            return 1;
        }
        std::string keys[] = {"i", "ea", "ee", "ll"};
        std::vector<std::string> keyWords(keys, keys + 4);
        if(isKeyWord(keyWords, firstRowLastWord)
           && isKeyWord(keyWords, secondRowLastWord)){
            isSimilarEnding = 1;
        }
        keyWords.clear();
        keys->clear();
        if(isSimilarEnding ==0 &&
           isLastLettersSimilar(firstRowLastWord, secondRowLastWord, numLetters)){
            isSimilarEnding = 1;
        }
        return isSimilarEnding;
    }
};

#endif //POEMGENERATOR_POEMGENERATOR_H
