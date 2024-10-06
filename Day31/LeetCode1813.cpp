#include <vector>
#include <string>
#include <sstream>

class Solution {
public:
    bool areSentencesSimilar(std::string sentence1, std::string sentence2) {
        std::vector<std::string> words1 = split(sentence1);
        std::vector<std::string> words2 = split(sentence2);
        
        if (words1.size() > words2.size()) {
            swap(words1, words2);
        }

        int i = 0, j = 0;
        int n = words1.size();
        int m = words2.size();
        
        while (i < n && words1[i] == words2[i]) {
            i++;
        }
        
        while (j < n && words1[n - 1 - j] == words2[m - 1 - j]) {
            j++;
        }
        
        return i + j >= n;
    }

private:
    std::vector<std::string> split(const std::string& sentence) {
        std::vector<std::string> result;
        std::stringstream ss(sentence);
        std::string word;
        while (ss >> word) {
            result.push_back(word);
        }
        return result;
    }   
};