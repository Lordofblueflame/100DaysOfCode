#include <string>
#include <unordered_map>


class Solution {
public:
    std::string longestDiverseString(int a, int b, int c) {
        std::string result;
        std::unordered_map<char, int> abc {
            {'a', a},
            {'b', b},
            {'c', c}
        };

        while (true) {
            if (abc['a'] == 0 && abc['b'] == 0 && abc['c'] == 0) {
                break;
            }

            char currChar = getHighestValueChar(abc);
            if (currChar == '\0') {
                break;
            }

            if (result.size() >= 2 && result[result.size() - 1] == currChar && result[result.size() - 2] == currChar) {
                char nextChar = getHighestValueChar(abc, currChar);
                if (nextChar == '\0') {
                    break; 
                }
                result += nextChar;
                abc[nextChar]--;
                continue; 
            }

            int countToAdd = (result.size() >= 2 && result[result.size() - 1] == currChar) ? 1 : 2;

            for (int i = 0; i < countToAdd; ++i) {
                if (abc[currChar] > 0) {
                    result += currChar;
                    abc[currChar]--;
                }
            }
        }

        return result;
    }
private:
    char getHighestValueChar(const std::unordered_map<char, int>& abc, char excludeChar = '\0') {
        char maxChar = '\0';
        int maxValue = -1;

        for (const auto& pair : abc) {
            if (pair.first != excludeChar && pair.second > maxValue && pair.second > 0) {
                maxValue = pair.second;
                maxChar = pair.first;
            }
        }

        return maxChar;
    }
};
