#include <vector>
#include <iostream>

class Solution {
public:
    std::vector<int> lexicalOrder(int n) {
        std::vector<int> retVec;
        int l = 1;

        for (int i = 0; i < n; i++) {
            retVec.push_back(l);

            if (l * 10 <= n) {
                l *= 10;
            } 
            else {
                while (l % 10 == 9 || l + 1 > n) {
                    l /= 10;
                }
                l++;
            }
        }

        return retVec;
    }
};
