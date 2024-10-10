#include <stack>
#include <vector>
#include <algorithm>

class Solution {
public:
    int maxWidthRamp(std::vector<int>& nums) {
        int n = nums.size();
        std::stack<int> stack;
        
        for (int i = 0; i < n; ++i) {
            if (stack.empty() || nums[stack.top()] > nums[i]) {
                stack.push(i);
            }
        }

        int maxWidth = 0;
        for (int j = n - 1; j >= 0; --j) {
            while (!stack.empty() && nums[stack.top()] <= nums[j]) {
                maxWidth = std::max(maxWidth, j - stack.top());
                stack.pop();
            }
        }

        return maxWidth;
    }
};