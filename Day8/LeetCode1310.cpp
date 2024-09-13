#include <vector>
#include <numeric>

class Solution {
public:
    std::vector<int> xorQueries(std::vector<int>& arr, std::vector<std::vector<int>>& queries) {
        std::vector<int> retXor;
        for (const auto& query : queries) {
            int begin = query.front(); //where to start
            int end = query.back(); //where to finish
            int value = std::accumulate(arr.begin() + begin, arr.begin() + end + 1, 0, [](int x,int y){
                return x^y;
            });
            retXor.emplace_back(value);
        }
        return retXor;
    }
};