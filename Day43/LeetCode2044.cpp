#include <vector>

class Solution {
public:
    int countMaxOrSubsets(std::vector<int>& nums) {
        int maxOr = 0, count = 0;
        for (int num : nums) {
            maxOr |= num;
        }
        
        countMaxOrSubsetRecursive(nums, 0, 0, maxOr, count);
        return count;
    }

private:
    void countMaxOrSubsetRecursive(const std::vector<int>& nums, int index, int currentOr, int maxOr, int& count) {
        if (index == nums.size()) {
            if (currentOr == maxOr) {
                count++;
            }
            return;
        }
        
        countMaxOrSubsetRecursive(nums, index + 1, currentOr | nums[index], maxOr, count);
        
        countMaxOrSubsetRecursive(nums, index + 1, currentOr, maxOr, count);
    }
};