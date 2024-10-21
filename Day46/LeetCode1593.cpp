#include <unordered_set>
#include <string>

class Solution {
public:
    int maxUniqueSplit(std::string s) {
        std::unordered_set<std::string> substrings;
        return backtrack(s, 0, substrings);
    }

private:
    int backtrack(const std::string& s, int start, std::unordered_set<std::string>& substrings) {
        if (start == s.length()) {
            return 0;
        }

        int maxSplits = 0;

        for (int end = start; end < s.length(); ++end) {
            std::string substr = s.substr(start, end - start + 1);
            if (substrings.find(substr) == substrings.end()) {
                substrings.insert(substr);
                int splits = 1 + backtrack(s, end + 1, substrings);
                maxSplits = std::max(maxSplits, splits);
                substrings.erase(substr);
            }
        }

        return maxSplits;
    }
};
