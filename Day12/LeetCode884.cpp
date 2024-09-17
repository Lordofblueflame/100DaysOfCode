#include <unordered_map>
#include <vector>
#include <string>
#include <sstream>

class Solution {
public:
    std::vector<std::string> uncommonFromSentences(std::string s1, std::string s2) {
        std::unordered_map<std::string,int> wordsCount; 

        std::istringstream iss(s1 + " " +  s2); 
        std::string word;
        while (iss >> word) {
            wordsCount[word]++; 
        }

        std::vector<std::string> retVec; 

        for(const auto& [word,number] : wordsCount) { 
            if(number > 1) { 
                continue;
            }
            retVec.emplace_back(word); 
        }

        return retVec; 
    }
};