#include <set>
#include <algorithm>
#include <string>
#include <vector>

class Solution {
public:
    int countConsistentStrings(std::string allowed, std::vector<std::string>& words) {
        std::set<char> wordSet;
        std::set<char> allowedSet(allowed.begin(), allowed.end());

        int counter = 0;
        
        for(const auto& word : words) {
            wordSet = std::set<char>(word.begin(), word.end());
            if( std::includes(allowedSet.begin(), allowedSet.end(), wordSet.begin(), wordSet.end())) {
                counter++;
            }
        }

        return counter;
    }
};