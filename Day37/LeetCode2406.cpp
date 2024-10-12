#include <algorithm>
#include <queue>
#include <vector>

class Solution {
public:
    int minGroups(std::vector<std::vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end());
        
        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
        
        for (const auto& interval : intervals) {
            int start = interval[0];
            int end = interval[1];

            if (!minHeap.empty() && minHeap.top() < start) {
                minHeap.pop();
            }
            
            minHeap.push(end);
        }
        
        return minHeap.size();
    }
};