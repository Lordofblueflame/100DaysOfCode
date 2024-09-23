#include <unordered_set>
#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int minExtraChar(std::string s, std::vector<std::string>& dictionary) {
        int n = s.size();
        std::vector<int> dp(n + 1, n);

        dp[0] = 0;

        std::unordered_set<std::string> dict(dictionary.begin(), dictionary.end()); 

        for (int i = 0; i < n; ++i) {
            for (int len = 1; len <= n - i; ++len) {
                std::string sub = s.substr(i, len);

                if (dict.find(sub) != dict.end()) {
                    dp[i + len] = std::min(dp[i + len], dp[i]);
                }
            }

            dp[i + 1] = std::min(dp[i + 1], dp[i] + 1);
        }

        return dp[n];
    }
};