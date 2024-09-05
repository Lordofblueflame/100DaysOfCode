#include <unordered_map>
#include <vector>

class Solution {
public:
    int findLHS(std::vector<int>& nums) {
        std::unordered_map<int, int> occu_map;
        int lhs = 0;

        for (int n : nums) {
            occu_map[n]++;
            
            if (occu_map.find(n + 1) != occu_map.end()) {
                lhs = std::max(lhs, occu_map[n] + occu_map[n + 1]);
            }
            
            if (occu_map.find(n - 1) != occu_map.end()) {
                lhs = std::max(lhs, occu_map[n] + occu_map[n - 1]);
            }
        }

        return lhs;
    }
};