#include <vector>
#include <algorithm>

class Solution {
public:

    std::vector<int> arrayRankTransform(std::vector<int>& arr) {
        int n = arr.size();
        
        if( n == 0 ) {
            return std::vector<int>();
        }

        std::vector<int> indices(n);

        for (int i = 0; i < n; ++i) {
            indices[i] = i;
        }

        std::sort(indices.begin(), indices.end(), [&arr](int a, int b) {
            return arr[a] < arr[b];
        });

        std::vector<int> rank(n, 0);
        int currentRank = 1;

        rank[indices[0]] = currentRank;
        for (int i = 1; i < n; ++i) {
            if (arr[indices[i]] != arr[indices[i - 1]]) {
                currentRank++;
            }
            rank[indices[i]] = currentRank;
        }

        return rank;
    }
};