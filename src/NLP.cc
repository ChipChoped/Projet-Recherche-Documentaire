#include "NLP.hh"
#include <iostream>
#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <iterator>
#include <bits/stdc++.h>
#include "../lib/rapidxml-1.13/rapidxml.hpp"
#include <utility>
#include <vector>
#include "../lib/porter/olestem/stemming/english_stem.h"
#include <cstdlib>

std::string NLP::deleteSpecialChar(std::string text) {
    char specialChar[] = ".,();!?{}\"\"$%€1234567890";
    int it = 0;

    for(char c : text){
        it++;
        if (isupper(c)){
            char lower = c + 32;
            std::replace(text.begin(), text.end(), c, lower);
        }
        for(char c2 : specialChar){
            if(c == c2){
                std::replace(text.begin(), text.end(), c, ' ');
            }
        }
    }

    return text;
} 

std::vector<std::string> NLP::tokenize(std::string text) {
    char delim = ' ';
    std::vector<std::string> tokens;
    std::string temp;
    int space = 0;

    for (char i : text) {
        if(i == delim){
            if(space==0)
                tokens.push_back(temp);
            temp = "";
            space++;
            
        }
        else {
            space = 0;
            if (i != ' ')
                temp += i;
        }       
    }

    tokens.push_back(temp);
    return tokens;
}


std::vector<std::string> NLP::getStopword(){
    std::vector<std::string> stopwords;
    std::ifstream file;
    file.open("../stopwords.txt", std::ios::in); // Opens a file to perform read operation using file object

    if (file.is_open()){ // Checking whether the file is open
        std::string tp;
        while (file >> tp) {
            stopwords.push_back(tp);
        }
    }

    file.close();
    return stopwords;
}

std::vector<std::string> NLP::deleteStopwords(std::vector<std::string> tokens, std::vector<std::string> stopwords){
    for(auto it = std::begin(tokens); it != std::end(tokens); ++it) {
        for(auto it2 = std::begin(stopwords); it2 != std::end(stopwords); ++it2) {
            if(*it == *it2){
                tokens.erase(it);
                it--;
            }
        }
    }
    return tokens;
}

std::vector<std::string> NLP::stem(std::vector<std::string> tokens){
    std::wstring word;
    stemming::english_stem<> StemEnglish;
    std::vector<std::string> newList;
    for (auto it = tokens.cbegin(); it != tokens.cend(); it++) {
        std::string token=*it;
        std::string ANSIWord(token);
        wchar_t* UnicodeTextBuffer = new wchar_t[(*it).length()+1];
        std::wmemset(UnicodeTextBuffer, 0, (*it).length()+1);
        std::mbstowcs(UnicodeTextBuffer, (*it).c_str(), (*it).length());
        word = UnicodeTextBuffer;
        StemEnglish(word);
        
        std::string str(word.length(), 0);
        std::transform(word.begin(), word.end(), str.begin(), [] (wchar_t c) {
            return (char)c;
        });
        newList.push_back(str);
    }
    return newList;
}