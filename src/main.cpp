#include <iostream>
#include <bits/stdc++.h>
#include <list>
#include <string>



char * deleteSpecialChar(char *str){
    char specialChar[]=".,();!?{}\"\"$%€1234567890";
    std::string s=str;
    int it=0;
    for(char c : s){
        it++;
        if (isupper(c)){
            char lower = c + 32;
            std::replace( s.begin(), s.end(), c,lower);
        }
        for(char c2 : specialChar){
            if(c==c2){
                std::replace( s.begin(), s.end(), c,' ');
            }
        }
    }
    int n = s.length(); 
    char * cleanStr= new char[n+1];
    strcpy(cleanStr, s.c_str());
    return cleanStr;
} 


std::list<char*> tokenize(char str []){
    std::list<char*> mylist;
    char *token = strtok(str," ");
    while (token != NULL)
    {
        mylist.push_back(token);
        token = strtok(NULL," ");
    }
    return mylist;
} 

int main() {
    char str[] ="The inventor of an ultrasonic gun used to stun racehorses was sentenced Thursday to 14 years in jail for his involvement in a multimillion dollar cocaine ring. Southwark Crown Court Judge Gerald Butler also ordered assets of auto dealer James Laming worth $38,320 be confiscated or Laming,49, would face an additional 18 months in jail. A jury convicted Laming and two other men Nov. 14. Ring leader Rene Black, 35, was sentenced to 15 years for masterminding the $24.8 million cocaine operation, which included Europe's first cocaine factory.";
    char * cleanStr=deleteSpecialChar(str);    
    std::list<char*> mylist = tokenize(cleanStr);
 
    for (auto it = mylist.cbegin(); it != mylist.cend(); it++) {
        std::cout << *it << std::endl;
    }

    return 0;
}
