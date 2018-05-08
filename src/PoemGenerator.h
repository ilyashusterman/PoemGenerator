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
//        char* word  = const_cast<char *>(lastWord.c_str());
//        printf ("%s\n", word);
//        return  const_cast<char *>(lastWord.c_str());
    }

    bool isKeyWord(std::vector<std::string> keyWords, string word) {
        string wordString = word;
        return (std::find(keyWords.begin(), keyWords.end(), word) != keyWords.end());
    }

    bool isLastLettersSimilar(string first, string second, int letters) {
        std::cout << "\n Follow this sub1: " << first.substr(first.length()-letters,first.length());
        std::cout << "\n Follow this sub2: " << second.substr(second.length()-letters, second.length());
        std::cout << "\n Follow this second: " << second.length();
        std::cout << "\nFollow this first: " << first.length();
        std::cout << "\nFollow this letters: " << letters;
        bool answer = long{second.length()}<long{letters};
        std::cout << "\nFollow this answer: " << answer;
        if(long{first.length()} < long{letters} || long{second.length()}<long{letters}){
            return false;
        }else{
            return first.substr(first.length()-letters,first.length())
                   == second.substr(second.length()-letters, second.length());
        }
    }

    int haveSimilarEnding(char* firstRow, char* secondRow, int numLetters){
        int isSimilarEnding = 0;
//        printf ("%s\n", firstRow);
        string firstRowLastWord  = getLastWord(firstRow);
        string secondRowLastWord  = getLastWord(secondRow);
        if (firstRowLastWord == secondRowLastWord){
            return 1;
        }
        std::string keys[] = {"i", "ea", "ee", "ll"};
        std::vector<std::string> keyWords(keys, keys + 4);
        if(isKeyWord(keyWords, firstRowLastWord)
           && isKeyWord(keyWords, secondRowLastWord)){
            printf("\n here22");
            isSimilarEnding = 1;
        }
        keyWords.clear();
        keys->clear();
        if(isSimilarEnding ==0 &&
           isLastLettersSimilar(firstRowLastWord, secondRowLastWord, numLetters)){
            isSimilarEnding = 1;
        }
//        delete secondRowLastWord, firstRowLastWord;
//        size_t lengthFirstRow = strlen(firstRow);
//        size_t lengthSecondRow = strlen(firstRow);
//        isSimilarEnding = 1;

        return isSimilarEnding;
    }
};

#endif //POEMGENERATOR_POEMGENERATOR_H
