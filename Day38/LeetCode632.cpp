/*
! Problem - 632. Smallest Range Covering Elements from K Lists

! Description 
    * You have k lists of sorted integers in non-decreasing order. Find the smallest range that includes at least one number from each of the k lists.
    * We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.

! Examples
    * Example 1:
    * Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
    * Output: [20,24]
    * Explanation: 
    * List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
    * List 2: [0, 9, 12, 20], 20 is in range [20,24].
    * List 3: [5, 18, 22, 30], 22 is in range [20,24].

    * Example 2:
    * Input: nums = [[1,2,3],[1,2,3],[1,2,3]]
    * Output: [1,1]
 
! Constraints 
    * nums.length == k
    * 1 <= k <= 3500
    * 1 <= nums[i].length <= 50
    * -100000 <= nums[i][j] <= 100000
    * nums[i] is sorted in non-decreasing order.

! Goal 
    * Find the smallest range that includes at least one number from each of the k lists

! Definitions & Predefined qualities 
    * We define the range [a, b] is smaller than range [c, d] 
        ? if (b - a < d - c)  
        ? or (a < c) if (b - a == d - c)
    * nums[i] is sorted in non-decreasing order. [-5,-4,-3,-2,-1,0,1,2,3,4,5...]
    * -100000 <= nums[i][j] <= 100000 which means we also deal with negative values
    * 3500 lists with up to 50 elements that gives us 175k elements that's a lot
    * range can be created ONLY from two existing values in two lists, value from third list don't have to be edge of range
    * List aren't the same size

! Topics
    * Array 
    * Hash Table 
    * Greedy 
    * Sliding Window 
    * Sorting 
    * Heap (Priority Queue)

! Thoughts
    * we can have a sliding window between lists and move would decide which one to incrementc and move through using priority queue
*/



#include <vector>
#include <queue>
#include <limits>
#include <iostream>

using tuple = tuple;

class Solution {
public:
    std::vector<int> smallestRange(std::vector<std::vector<int>>& nums) {

        std::priority_queue<tuple, std::vector<tuple>, std::greater<tuple>> minHeap;

        int maxVal = std::numeric_limits<int>::min();

        for (int i = 0; i < nums.size(); ++i) {
            minHeap.emplace(nums[i][0], i, 0);
            maxVal = std::max(maxVal, nums[i][0]);
        }

        int rangeStart = 0, rangeEnd = std::numeric_limits<int>::max();

        std::cout << "Initial Heap: ";
        printHeap(minHeap);
        std::cout << "Initial maxVal: " << maxVal << "\n";
        std::cout << "Initial range: [" << rangeStart << ", " << rangeEnd << "]\n\n";

        while (true) {
            auto [minVal, row, col] = minHeap.top();
            minHeap.pop();

            if (maxVal - minVal < rangeEnd - rangeStart) {
                rangeStart = minVal;
                rangeEnd = maxVal;
                std::cout << "Updated range: [" << rangeStart << ", " << rangeEnd << "]\n";
            }

            if (col + 1 < nums[row].size()) {
                int nextVal = nums[row][col + 1];
                minHeap.emplace(nextVal, row, col + 1);
                maxVal = std::max(maxVal, nextVal);

                std::cout << "Pushed next value: " << nextVal << " from list " << row << "\n";
                std::cout << "Current Heap: ";
                printHeap(minHeap);
                std::cout << "Updated maxVal: " << maxVal << "\n";
                std::cout << "Current range: [" << rangeStart << ", " << rangeEnd << "]\n\n";
            } else {
                break;
            }
        }

        return {rangeStart, rangeEnd};
    }
    private:
    void printHeap(const std::priority_queue<tuple, std::vector<tuple>, std::greater<tuple>>& minHeap) {
        std::priority_queue<tuple, std::vector<tuple>, std::greater<tuple>> tempHeap = minHeap;

        std::cout << "[ ";
        while (!tempHeap.empty()) {
            auto [value, row, col] = tempHeap.top();
            std::cout << "(" << value << ", " << row << ", " << col << ") ";
            tempHeap.pop();
        }
        std::cout << "]\n";
    }
};

int main() { 
    std::vector<std::vector<int>> lists = {
        {4, 10, 15, 24, 26},
        {0, 9, 12, 20},
        {5, 18, 22, 30},
    };

    Solution s;
    
    std::vector<int> result = s.smallestRange(lists);
    std::cout << "[" << result[0] << ", " << result[1] << "]\n";


    return 0;
}