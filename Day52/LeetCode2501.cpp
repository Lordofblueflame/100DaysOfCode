#include <unordered_set>
#include <vector>
#include <algorithm>

class Solution {
public:
    int longestSquareStreak(std::vector<int>& nums) {
        std::unordered_set<int> elems(nums.begin(), nums.end());
        int maxCount = 0;

        for (const auto& n : elems) {
            int count = squareStreak(n, elems);
            maxCount = std::max(maxCount, count);
        }

        return maxCount > 1 ? maxCount : -1;
    }

private:
    int squareStreak(int n, const std::unordered_set<int>& elems) {
        long long square = static_cast<long long>(n) * n; 
        if (square <= INT_MAX && elems.find(static_cast<int>(square)) != elems.end()) {
            return 1 + squareStreak(static_cast<int>(square), elems);
        }
        return 1;
    }
};
