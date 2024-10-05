#include <string>
#include <vector>

class Solution {
public:
    std::vector<int> getLetterFrequencies(const std::string& s1) {
        std::vector<int> freqBaseStr(26, 0); 

        for (char c : s1) {
            freqBaseStr[c - 'a']++;
        }

        return freqBaseStr;
    }

    bool checkInclusion(std::string s1, std::string s2) {
        if (s1.length() > s2.length()) return false;

        std::vector<int> freqBaseStr = getLetterFrequencies(s1);
        
        std::vector<int> windowFreq(26, 0);
        
        for (int i = 0; i < s1.length(); ++i) {
            windowFreq[s2[i] - 'a']++;
        }

        if (windowFreq == freqBaseStr) return true;

        for (int i = s1.length(); i < s2.length(); ++i) {
            windowFreq[s2[i] - 'a']++;

            windowFreq[s2[i - s1.length()] - 'a']--;

            if (windowFreq == freqBaseStr) return true;
        }

        return false;
    }
};