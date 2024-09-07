#include <vector>

class Solution {
public:

    std::vector<int> sumZero(int n) {
        std::vector<int> retVec;
        int size = n;

        if(n % 2 != 0) {
            retVec.push_back(0);
            size--;
        }

        for(int i = 0 ; i < size/2; i ++) {
            retVec.push_back(i+1);
            retVec.push_back((i+1)*-1);
        }
        
        return retVec;
    }
};