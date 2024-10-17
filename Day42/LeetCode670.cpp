#include <string>
#include <utility>

class Solution {
public:

    int maximumSwap(int num) {
        std::string numStr = std::to_string(num);
        int n = numStr.length();
        
        int maxIdx = n - 1;
        int leftIdx = -1, rightIdx = -1;

        for (int i = n - 2; i >= 0; --i) {

            if (numStr[i] < numStr[maxIdx]) {
                leftIdx = i;
                rightIdx = maxIdx;
            } else if (numStr[i] > numStr[maxIdx]) {
                maxIdx = i;
            }
        }

        if (leftIdx != -1) {
            std::swap(numStr[leftIdx], numStr[rightIdx]);
        }

        return std::stoi(numStr);
    }
};