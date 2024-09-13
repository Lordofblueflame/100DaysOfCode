class Solution {
public:
    int countSetBits(int value) {
        int count = 0;
        while (value > 0) {
            count += (value & 1);
            value >>= 1;           
        }
        return count;
    }
    int minBitFlips(int start, int goal) {
        
        int xorValue = start ^ goal;

        return countSetBits(xorValue);    
    }
};