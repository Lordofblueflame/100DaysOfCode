#include <unordered_map>
#include <vector>

class Solution {
public:
    bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
        std::unordered_map<int,int> numMap;

        auto checkNearbyDuplicate = [&](int num, int index) -> bool {
            if (numMap.find(num) != numMap.end()) {
                if (index - numMap[num] <= k) {
                    return true;
                }
            }
            numMap[num] = index;
            return false;
        };

        for (int i = 0; i < nums.size(); ++i) {
            if (checkNearbyDuplicate(nums[i], i)) {
                return true;
            }
        }
        
        return false;
    }
};