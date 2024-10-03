#include <unordered_map>
#include <vector>
#include <algorithm>
#include <numeric>

class Solution {
public:
    int minSubarray(std::vector<int>& nums, int p) {
        int totalSum = 0;

        totalSum = std::accumulate(nums.begin(), nums.end(), 0, 
            [p](int sum, int num) { 
                return (sum + num) % p; 
            }
        );

        if (totalSum % p == 0) return 0;


        std::unordered_map<int, int> prefixMod;
        prefixMod[0] = -1;
        
        int targetRemainder = totalSum % p;
        int currentPrefix = 0;
        int minLength = nums.size();
        
        for (int i = 0; i < nums.size(); ++i) {
            currentPrefix = (currentPrefix + nums[i]) % p;
            
            int neededRemainder = (currentPrefix - targetRemainder + p) % p;

            if (prefixMod.find(neededRemainder) != prefixMod.end()) {
                int subarrayLength = i - prefixMod[neededRemainder];
                minLength = std::min(minLength, subarrayLength);
            }

            prefixMod[currentPrefix] = i;
        }

        return (minLength == nums.size()) ? -1 : minLength;
    }
};