// 1337. The K Weakest Rows in a Matrix
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

class Solution {
public:
    std::vector<int> kWeakestRows(std::vector<std::vector<int>>& mat, int k) {
        auto compare = [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
            if (a.first == b.first) {
                return a.second > b.second;
            }
            return a.first > b.first;  
        };
        
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(compare)> pq(compare);

        for (int i = 0; i < mat.size(); ++i) {
            int soldierCount = std::count(mat[i].begin(), mat[i].end(), 1); 
            pq.push({soldierCount, i});
        }

        // Retrieve the k weakest rows
        std::vector<int> result;
        for (int i = 0; i < k; ++i) {
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }
};