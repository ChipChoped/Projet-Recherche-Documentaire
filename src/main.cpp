#include <iostream>
#include "Document.hh"
#include "Documents.hh"

int main() {
    Documents documents;
    documents.parse("../AP/AP891216");
    //documents.print();
    char str[] ="The inventor of an about ultrasonic gun used to stun racehorses was sentenced Thursday to 14 years in jail for his involvement in a multimillion dollar cocaine ring. Southwark Crown Court Judge Gerald Butler also ordered assets of auto dealer James Laming worth $38,320 be confiscated or Laming,49, would face an additional 18 months in jail. A jury convicted Laming and two other men Nov. 14. Ring leader Rene Black, 35, was sentenced to 15 years for masterminding the $24.8 million cocaine operation, which included Europe's first cocaine factory.";
    std::string cleanStr=documents.deleteSpecialChar(str);    
    std::vector<std::string> mylist = documents.tokenize(cleanStr);
    std::vector<std::string> stopwords = documents.getStopword();
    mylist=documents.deleteStopwords(mylist,stopwords);
    std::cout<<mylist.size();
    
    for (auto it = mylist.cbegin(); it != mylist.cend(); it++) {
        std::cout << *it << std::endl;
    }
       return 0;
}
