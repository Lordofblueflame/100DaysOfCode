#include <unordered_set>
#include <vector>
#include <string>

class Solution {
public:
    int longestCommonPrefix(std::vector<int>& arr1, std::vector<int>& arr2) {
        std::unordered_set<std::string> prefixes;
        for (const auto& num : arr1) {
            std::string s = std::to_string(num);
            for (size_t i = 1; i <= s.length(); ++i) {
                prefixes.insert(s.substr(0, i));
            }
        }
        std::vector<std::string> values;
            for (int num : arr2) {
            values.emplace_back(std::to_string(num));
        }
        int maxLength = 0;

        for(const auto& str : values) {
            for(int i = 0; i < str.length(); i++) {

                std::string substr = str.substr(0, i + 1);
                if (prefixes.find(substr) != prefixes.end()) {
                    maxLength = maxLength > substr.length() ? maxLength : substr.length();
                }
            }

        }
        return maxLength;
    }
};