#include <vector>
#include <algorithm>

class Solution {
public:
    int longestSubarray(std::vector<int>& nums) {
        auto max = *std::max_element(nums.begin(), nums.end());
        int count = 0;
        int sum = 0;
        bool works = false;
        for(int i = 0; i < nums.size(); i++) {
            if(max == nums[i]) {
                works = true;
                count++;
            } else {
                works = false;
                sum = sum >= count ? sum : count;
                count = 0; 
            }
        }
        sum = sum >= count ? sum : count;
        return sum;
    }
};