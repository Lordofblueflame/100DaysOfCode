#include <queue>
#include <vector>

class Solution {
public:
    long long maxKelements(std::vector<int>& nums, int k) {
        long long score = 0;

        std::priority_queue<int> maxHeap(nums.begin(),nums.end());

        while(k > 0) {
            score += maxHeap.top();
            int temp = std::ceil(maxHeap.top() / 3);

            if(maxHeap.top() % 3 != 0) 
                temp++;
            
            maxHeap.pop();
            maxHeap.emplace(temp);
            
            k--;
        }

        return score;
    }
};