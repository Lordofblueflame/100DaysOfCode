#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:

    std::string largestNumber(std::vector<int>& nums) {
        std::vector<std::string> numStrings;
        for (int num : nums) {
            numStrings.push_back(std::to_string(num));
        }

        std::sort(numStrings.begin(), numStrings.end(), [](const std::string &a, const std::string &b) -> bool {
            return a + b > b + a;
        });

        if (numStrings[0] == "0") {
            return "0";
        }

        std::string result;
        for (const std::string &num : numStrings) {
            result += num;
        }

        return result;
    }
};